# --------------------------------------------------------------------------
# File: _ostream.py
# ---------------------------------------------------------------------------
# Licensed Materials - Property of IBM
# 5725-A06 5725-A29 5724-Y48 5724-Y49 5724-Y54 5724-Y55 5655-Y21
# Copyright IBM Corporation 2008, 2017. All Rights Reserved.
#
# US Government Users Restricted Rights - Use, duplication or
# disclosure restricted by GSA ADP Schedule Contract with
# IBM Corp.
# ------------------------------------------------------------------------
"""
"""

import weakref

from ._procedural import check_status
from ..exceptions import CplexError, ErrorChannelMessage
from .. import six


class OutputStream(object):
    """Class to parse and write strings to a file object.

    Methods:
    __init__(self, outputfile, fn = None)
    __del__(self)
    write(self)
    flush(self)
    """

    def __init__(self, outputfile, env, fn=None, initerrorstr=False):
        """OutputStream constructor.

        outputfile must provide methods write(self, str) and
        flush(self).

        If fn is specified, it must be a fuction with signature
        fn(str) -> str.
        """
        self._env = weakref.proxy(env)
        self._fn = fn
        self._is_valid = False
        self._was_opened = False
        self._disposed = False
        # We only create this attribute for the error channel.
        if initerrorstr:
            self._error_string = None
        if isinstance(outputfile, six.string_types):
            self._file = open(outputfile, "w")
            self._was_opened = True
        else:
            self._file = outputfile
        if self._file is not None:
            try:
                tst = callable(self._file.write)
            except AttributeError:
                tst = False
            if not tst:
                raise CplexError("Output object must have write method")
            try:
                tst = callable(self._file.flush)
            except AttributeError:
                tst = False
            if not tst:
                raise CplexError("Output object must have flush method")
        self._is_valid = True

    def _end(self):
        """Flush and free any open file.

        If the user passes in a filename string, we open it.  In that case,
        we need to clean it up.
        """
        if self._disposed:
            return
        self._disposed = True
        # File-like objects should implement this attribute.  If we come
        # across one that doesn't, don't assume anything.
        try:
            isclosed = self._file.closed
        except AttributeError:
            isclosed = False
        # If something bad happened in the constructor, then don't flush.
        if self._is_valid and not isclosed:
            self.flush()
            # If we opened the file, then we need to close it.
            if self._was_opened:
                self._file.close()

    def __del__(self):
        """OutputStream destructor."""
        self._end()

    def _write_wrap(self, str_):
        """Used when anything is written to the message channels.

        The _error_string attribute should only be present on the error
        channel.  If we detect that something was printed on the error
        channel, then we raise an ErrorChannelMessage along with this
        message.  The message can contain more information than what
        we'd get by calling CPXgeterrorstring.  For example, we may see
        format string specifiers rather having them filled in.

        See SWIG_callback.c:messagewrap.
        """
        try:
            self.write(str_)
            self.flush()
            # Check to see if something was written to the error
            # channel.
            try:
                # Remove trailing newlines.
                msg = self._error_string.strip()
            except AttributeError:
                msg = None
            if msg is not None:
                # Errors raised from callbacks are handled in
                # SWIG_callback.c:cpx_handle_pyerr.  If we do not have a
                # callback error (CPXERR_CALLBACK = 1006), then raise a
                # ErrorChannelMessage containing the last error string.
                # This gets special treatment in
                # _procedural.py:StatusChecker.
                if not msg.startswith("CPLEX Error  1006"):
                    self._error_string = None
                    # NB: This will be caught immediately below and stored
                    #     in self._env._callback_exception.
                    raise ErrorChannelMessage(msg)
        except Exception as exc:
            self._env._callback_exception = exc
            check_status._pyenv = self._env

    def write(self, msg):
        """Parses and writes a string.

        If self._fn is not None, self._fn(msg) is passed to
        self._file.write.  Otherwise, msg is passed to self._file.write.
        """
        if self._file is None:
            return
        if msg is None:
            msg = ""
        if self._fn is None:
            self._file.write(msg)
        else:
            self._file.write(self._fn(msg))

    def flush(self):
        """Flushes the buffer."""
        if self._file is not None:
            self._file.flush()
