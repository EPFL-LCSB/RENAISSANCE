# --------------------------------------------------------------------------
# File: _procedural.py
# ---------------------------------------------------------------------------
# Licensed Materials - Property of IBM
# 5725-A06 5725-A29 5724-Y48 5724-Y49 5724-Y54 5724-Y55 5655-Y21
# Copyright IBM Corporation 2008, 2017. All Rights Reserved.
#
# US Government Users Restricted Rights - Use, duplication or
# disclosure restricted by GSA ADP Schedule Contract with
# IBM Corp.
# ------------------------------------------------------------------------

from __future__ import print_function

from contextlib import contextmanager
from random import randrange
import signal

from . import _list_array_utils as LAU
from . import _pycplex as CR

from ._constants import *
from ..exceptions import CplexSolverError, CplexError, ErrorChannelMessage

from .. import six
from ..six.moves import map, zip

default_encoding = "UTF-8"
cpx_default_encoding = "UTF-8"


def cpx_decode(my_str, enc):
    if my_str is None:
        return my_str
    elif isinstance(my_str, six.binary_type):
        if enc == cpx_default_encoding:
            return my_str
        else:
            return six.text_type(my_str, enc).encode(cpx_default_encoding)
    else:
        assert isinstance(my_str, six.text_type)
        return my_str.encode(cpx_default_encoding)


def cpx_decode_noop3(my_str, enc):
    if six.PY2:
        return cpx_decode(my_str, enc)
    else:
        return my_str


def _cpx_encode_py2(my_str, enc):
    assert six.PY2
    if enc == cpx_default_encoding:
        return my_str
    else:
        return six.text_type(my_str, cpx_default_encoding).encode(enc)


def _cpx_encode_py3(my_str, enc):
    assert not six.PY2
    if isinstance(my_str, six.binary_type):
        return my_str.decode(enc)
    else:
        assert isinstance(my_str, six.text_type)
        if enc == cpx_default_encoding:
            return my_str
        else:
            return my_str.encode(cpx_default_encoding).decode(enc)


def cpx_encode_noop3(my_str, enc):
    if six.PY2:
        return cpx_encode(my_str, enc)
    else:
        return my_str


def cpx_encode(my_str, enc):
    if six.PY2:
        return _cpx_encode_py2(my_str, enc)
    else:
        return _cpx_encode_py3(my_str, enc)


def cpx_transcode(name, enc):
    if isinstance(name, six.text_type):
        return name.encode("utf-8")
    else:
        return six.text_type(name, enc).encode("utf-8")


def _safeDoubleArray(arraylen):
    # Make sure that we never request a zero-length array.  This results in
    # a malloc(0) call in the SWIG layer.  On AIX this returns NULL which
    # causes problems.  By ensuring that the array is at least size 1, we
    # avoid these problems and the overhead should be negligable.
    if arraylen <= 0:
        arraylen = 1
    return CR.doubleArray(arraylen)


def _safeIntArray(arraylen):
    # See comment for _safeDoubleArray above.
    if arraylen <= 0:
        arraylen = 1
    return CR.intArray(arraylen)


def _safeLongArray(arraylen):
    # See comment for _safeDoubleArray above.
    if arraylen <= 0:
        arraylen = 1
    return CR.longArray(arraylen)


def _rangelen(begin, end):
    """Returns length of the range specified by begin and end.

    As this is typically used to calculate the length of a buffer, it
    always returns a result >= 0.

    See functions like `_safeDoubleArray` and `safeLongArray`.
    """
    # We allow arguments like begin=0, end=-1 on purpose.  This
    # represents an empty set.  In most cases, the callable library will
    # just do nothing when called with an empty set.  Unfortunately, this
    # isn't consistent across the entire API.  See RTC-31484 for more.
    result = end - begin + 1
    if result < 0:
        return 0
    return result


def getstatstring(env, statind, enc=default_encoding):
    output = []
    CR.CPXXgetstatstring(env, statind, output)
    return cpx_encode(output[0], enc)


def geterrorstring(env, errcode):
    output = []
    CR.CPXXgeterrorstring(env, errcode, output)
    return output[0]


def cb_geterrorstring(env, status):
    return CR.cb_geterrorstring(env, status)


def setpyterminate(env):
    CR.setpyterminate(env)


def unset_py_terminator():
    CR.unset_py_terminator()


def set_py_terminator():
    CR.set_py_terminator()


def new_native_int():
    return CR.new_native_int()


def delete_native_int(p):
    CR.delete_native_int(p)


def set_native_int(p, v):
    CR.set_native_int(p, v)


def get_native_int(p):
    return CR.get_native_int(p)


def setterminate(env, env_lp_ptr, p):
    status = CR.setterminate(env_lp_ptr, p)
    check_status(env, status)


class SigIntHandler(object):
    """Handle Ctrl-C events during long running processes.

    :undocumented
    """

    def __init__(self):
        self.orig_handler = signal.getsignal(signal.SIGINT)
        self.was_triggered = False

        def sigint_handler(signum, frame):
            set_py_terminator()
            self.was_triggered = True
        # Make sure that we always start out with an "unset" terminator.
        unset_py_terminator()
        try:
            signal.signal(signal.SIGINT, sigint_handler)
        except ValueError:
            pass  # If not main thread then just continue

    def __enter__(self):
        return self

    def __exit__(self, exc_type, exc_value, traceback):
        try:
            signal.signal(signal.SIGINT, self.orig_handler)
        except ValueError:
            pass  # If not main thread then just continue
        if self.was_triggered:
            print("\nKeyboardInterrupt")


def pack_env_lp_ptr(env, lp):
    return CR.pack_env_lp_ptr(env, lp)


@contextmanager
def chbmatrix(lolmat, env_lp, r_c, enc):
    """See matrix_conversion.c:Pylolmat_to_CHBmat()."""
    mat = Pylolmat_to_CHBmat(lolmat, env_lp, r_c, enc)
    try:
        # yields ([matbeg, matind, matval], nnz)
        yield mat[:-1], mat[-1]
    finally:
        free_CHBmat(mat)


def Pylolmat_to_CHBmat(lolmat, get_indices, r_c, enc):
    return CR.Pylolmat_to_CHBmat(lolmat, get_indices, r_c, cpx_transcode, enc)


def free_CHBmat(lolmat):
    CR.free_CHBmat(lolmat)


class StatusChecker(object):
    """A callable object used for checking status codes.

    :undocumented
    """

    def __init__(self):
        class NoOp(object):
            pass
        self._pyenv = NoOp()
        self._pyenv._callback_exception = None

    def _handle_cb_error(self, env, cberror):
        """Handle the callback exception.

        These can be triggered either in the SWIG Python C API layer
        (e.g., SWIG_callback.c) or in _ostream.py.
        """
        if isinstance(cberror, Exception):
            # If cberror is already an exception, then just throw it as is.
            # We can only get here from: _ostream.py:_write_wrap.
            raise cberror
        if isinstance(cberror[1], Exception):
            # In this case the first item is the type of exception and
            # the second item is the exception.  This is raised from the
            # SWIG C layer (e.g., SWIG_callback.c:).
            cberror = cberror[1]
        elif isinstance(cberror[1], tuple):
            # The second item is a tuple containing the error string and
            # the error number.  We can get this from, for example:
            # SWIG_callback.c:fast_getcallbackinfo.
            assert len(cberror[1]) == 2
            cberror = cberror[0](cberror[1][0], env, cberror[1][1])
        else:
            # The second item is the error string or perhaps None.
            # See code in SWIG_callback.c where the _callback_exception
            # attribute is set.
            cberror = cberror[0](cberror[1])
        raise cberror

    def __call__(self, env, status, from_cb=False):
        error_string = None
        try:
            if self._pyenv._callback_exception is not None:
                callback_exception = self._pyenv._callback_exception
                self._pyenv._callback_exception = None
                if isinstance(callback_exception, ErrorChannelMessage):
                    # We can only get here from _ostream.py:_write_wrap.
                    # If we encounter an error, we use the last message
                    # from the error channel for the message (i.e., rather
                    # than calling CPXXgeterrorstring).
                    error_string = callback_exception.args[0]
                else:
                    self._handle_cb_error(env, callback_exception)
        except ReferenceError:
            pass
        if status == CR.CPXERR_NO_ENVIRONMENT:
            raise ValueError('illegal method invocation after Cplex.end()')
        elif status != 0:
            if error_string is None:
                if from_cb:
                    error_string = cb_geterrorstring(env, status)
                else:
                    error_string = geterrorstring(env, status)
            raise CplexSolverError(error_string, env, status)


check_status = StatusChecker()


def set_status_checker():
    CR.set_status_checker(check_status)

# Environment


def version(env):
    return CR.CPXXversion(env)


def versionnumber(env):
    ver = CR.intPtr()
    status = CR.CPXXversionnumber(env, ver)
    return ver.value()


def openCPLEX():
    status = CR.intPtr()
    env = CR.CPXXopenCPLEX(status)
    check_status(env, status.value())
    return env


def closeCPLEX(env):
    envp = CR.CPXENVptrPtr()
    envp.assign(env)
    status = CR.CPXXcloseCPLEX(envp)
    check_status(env, status)


def getchannels(env):
    results = CR.CPXCHANNELptrPtr()
    warning = CR.CPXCHANNELptrPtr()
    error = CR.CPXCHANNELptrPtr()
    log = CR.CPXCHANNELptrPtr()
    status = CR.CPXXgetchannels(env, results, warning, error, log)
    check_status(env, status)
    return (results.value(), warning.value(), error.value(), log.value())


def addfuncdest(env, channel, fileobj):
    status = CR.CPXXaddfuncdest(env, channel, fileobj)
    check_status(env, status)


def delfuncdest(env, channel, fileobj):
    status = CR.CPXXdelfuncdest(env, channel, fileobj)
    check_status(env, status)


def setlpcallbackfunc(env, cbhandle):
    status = CR.CPXXsetlpcallbackfunc(env, cbhandle)
    check_status(env, status)


def setnetcallbackfunc(env, cbhandle):
    status = CR.CPXXsetnetcallbackfunc(env, cbhandle)
    check_status(env, status)


def settuningcallbackfunc(env, cbhandle):
    status = CR.CPXXsettuningcallbackfunc(env, cbhandle)
    check_status(env, status)


def setheuristiccallbackfunc(env, cbhandle):
    status = CR.CPXXsetheuristiccallbackfunc(env, cbhandle)
    check_status(env, status)


def setlazyconstraintcallbackfunc(env, cbhandle):
    status = CR.CPXXsetlazyconstraintcallbackfunc(env, cbhandle)
    check_status(env, status)


def setusercutcallbackfunc(env, cbhandle):
    status = CR.CPXXsetusercutcallbackfunc(env, cbhandle)
    check_status(env, status)


def setincumbentcallbackfunc(env, cbhandle):
    status = CR.CPXXsetincumbentcallbackfunc(env, cbhandle)
    check_status(env, status)


def setnodecallbackfunc(env, cbhandle):
    status = CR.CPXXsetnodecallbackfunc(env, cbhandle)
    check_status(env, status)


def setbranchcallbackfunc(env, cbhandle):
    status = CR.CPXXsetbranchcallbackfunc(env, cbhandle)
    check_status(env, status)


def setbranchnosolncallbackfunc(env, cbhandle):
    status = CR.CPXXsetbranchnosolncallbackfunc(env, cbhandle)
    check_status(env, status)


def setsolvecallbackfunc(env, cbhandle):
    status = CR.CPXXsetsolvecallbackfunc(env, cbhandle)
    check_status(env, status)


def setinfocallbackfunc(env, cbhandle):
    status = CR.CPXXsetinfocallbackfunc(env, cbhandle)
    check_status(env, status)


def setmipcallbackfunc(env, cbhandle):
    status = CR.CPXXsetmipcallbackfunc(env, cbhandle)
    check_status(env, status)

# Parameters


def setintparam(env, whichparam, newvalue):
    status = CR.CPXXsetintparam(env, whichparam, newvalue)
    check_status(env, status)


def setlongparam(env, whichparam, newvalue):
    status = CR.CPXXsetlongparam(env, whichparam, newvalue)
    check_status(env, status)


def setdblparam(env, whichparam, newvalue):
    status = CR.CPXXsetdblparam(env, whichparam, newvalue)
    check_status(env, status)


def setstrparam(env, whichparam, newvalue):
    status = CR.CPXXsetstrparam(env, whichparam, newvalue)
    check_status(env, status)


def getintparam(env, whichparam):
    curval = CR.intPtr()
    status = CR.CPXXgetintparam(env, whichparam, curval)
    check_status(env, status)
    return curval.value()


def getlongparam(env, whichparam):
    curval = CR.cpxlongPtr()
    status = CR.CPXXgetlongparam(env, whichparam, curval)
    check_status(env, status)
    return curval.value()


def getdblparam(env, whichparam):
    curval = CR.doublePtr()
    status = CR.CPXXgetdblparam(env, whichparam, curval)
    check_status(env, status)
    return curval.value()


def getstrparam(env, whichparam):
    output = []
    status = CR.CPXXgetstrparam(env, whichparam, output)
    check_status(env, status)
    return output[0]


def infointparam(env, whichparam):
    default = CR.intPtr()
    minimum = CR.intPtr()
    maximum = CR.intPtr()
    status = CR.CPXXinfointparam(env, whichparam, default, minimum, maximum)
    check_status(env, status)
    return (default.value(), minimum.value(), maximum.value())


def infolongparam(env, whichparam):
    default = CR.cpxlongPtr()
    minimum = CR.cpxlongPtr()
    maximum = CR.cpxlongPtr()
    status = CR.CPXXinfolongparam(env, whichparam, default, minimum, maximum)
    check_status(env, status)
    return (default.value(), minimum.value(), maximum.value())


def infodblparam(env, whichparam):
    default = CR.doublePtr()
    minimum = CR.doublePtr()
    maximum = CR.doublePtr()
    status = CR.CPXXinfodblparam(env, whichparam, default, minimum, maximum)
    check_status(env, status)
    return (default.value(), minimum.value(), maximum.value())


def infostrparam(env, whichparam):
    output = []
    status = CR.CPXXinfostrparam(env, whichparam, output)
    check_status(env, status)
    return output[0]


def getparamtype(env, param_name):
    output = CR.intPtr()
    status = CR.CPXXgetparamtype(env, param_name, output)
    check_status(env, status)
    return output.value()


def readcopyparam(env, filename, enc=default_encoding):
    status = CR.CPXXreadcopyparam(env, cpx_decode_noop3(filename, enc))
    check_status(env, status)


def writeparam(env, filename, enc=default_encoding):
    status = CR.CPXXwriteparam(env, cpx_decode_noop3(filename, enc))
    check_status(env, status)


def tuneparam(env, lp, int_param_values, dbl_param_values, str_param_values):
    tuning_status = CR.intPtr()
    intcnt = len(int_param_values)
    dblcnt = len(dbl_param_values)
    strcnt = len(str_param_values)
    intnum = [int_param_values[i][0] for i in range(intcnt)]
    intval = [int_param_values[i][1] for i in range(intcnt)]
    dblnum = [dbl_param_values[i][0] for i in range(dblcnt)]
    dblval = [dbl_param_values[i][1] for i in range(dblcnt)]
    strnum = [str_param_values[i][0] for i in range(strcnt)]
    strval = [str_param_values[i][1] for i in range(strcnt)]
    with SigIntHandler():
        status = CR.CPXXtuneparam(
            env, lp, intcnt,
            LAU.int_list_to_array(intnum),
            LAU.int_list_to_array_trunc_int32(intval),
            dblcnt,
            LAU.int_list_to_array(dblnum),
            LAU.double_list_to_array(dblval),
            strcnt,
            LAU.int_list_to_array(strnum),
            [cpx_decode(x, default_encoding) for x in strval],
            tuning_status)
    check_status(env, status)
    return tuning_status.value()


def tuneparamprobset(env, filenames, filetypes, int_param_values,
                     dbl_param_values, str_param_values):
    tuning_status = CR.intPtr()
    intcnt = len(int_param_values)
    dblcnt = len(dbl_param_values)
    strcnt = len(str_param_values)
    intnum = [int_param_values[i][0] for i in range(intcnt)]
    intval = [int_param_values[i][1] for i in range(intcnt)]
    dblnum = [dbl_param_values[i][0] for i in range(dblcnt)]
    dblval = [dbl_param_values[i][1] for i in range(dblcnt)]
    strnum = [str_param_values[i][0] for i in range(strcnt)]
    strval = [str_param_values[i][1] for i in range(strcnt)]
    with SigIntHandler():
        status = CR.CPXXtuneparamprobset(
            env, len(filenames),
            [cpx_decode(x, default_encoding) for x in filenames],
            [cpx_decode(x, default_encoding) for x in filetypes],
            intcnt, LAU.int_list_to_array(intnum),
            LAU.int_list_to_array_trunc_int32(intval),
            dblcnt, LAU.int_list_to_array(dblnum),
            LAU.double_list_to_array(dblval),
            strcnt, LAU.int_list_to_array(strnum),
            [cpx_decode(x, default_encoding) for x in strval],
            tuning_status)
    check_status(env, status)
    return tuning_status.value()


def fixparam(env, paramnum):
    status = CR.CPXXEfixparam(env, paramnum)
    check_status(env, status)

# Runseeds

def runseeds(env, lp, cnt):
    with SigIntHandler():
        status = CR.CPXErunseeds(env, lp, cnt)
    check_status(env, status)

# Cplex


def createprob(env, probname, enc=default_encoding):
    status = CR.intPtr()
    lp = CR.CPXXcreateprob(env, status, cpx_decode_noop3(probname, enc))
    check_status(env, status.value())
    return lp


def readcopyprob(env, lp, filename, filetype="", enc=default_encoding):
    if filetype == "":
        status = CR.CPXXreadcopyprob(env, lp,
                                     cpx_decode_noop3(filename, enc))
    else:
        status = CR.CPXXreadcopyprob(env, lp,
                                     cpx_decode_noop3(filename, enc),
                                     cpx_decode_noop3(filetype, enc))
    check_status(env, status)


def cloneprob(env, lp):
    status = CR.intPtr()
    lp = CR.CPXXcloneprob(env, lp, status)
    check_status(env, status.value())
    return lp


def freeprob(env, lp):
    lpp = CR.CPXLPptrPtr()
    lpp.assign(lp)
    status = CR.CPXXfreeprob(env, lpp)
    check_status(env, status)


def mipopt(env, lp):
    with SigIntHandler():
        status = CR.CPXXmipopt(env, lp)
    check_status(env, status)


def distmipopt(env, lp):
    with SigIntHandler():
        status = CR.CPXXdistmipopt(env, lp)
    check_status(env, status)


def copyvmconfig(env, xmlstring):
    status = CR.CPXXcopyvmconfig(env, xmlstring)
    check_status(env, status)


def readcopyvmconfig(env, filename, enc=default_encoding):
    status = CR.CPXXreadcopyvmconfig(env, cpx_decode_noop3(filename, enc))
    check_status(env, status)


def delvmconfig(env):
    status = CR.CPXXdelvmconfig(env)
    check_status(env, status)


def hasvmconfig(env):
    hasvmconfig_p = CR.intPtr()
    status = CR.CPXEhasvmconfig(env, hasvmconfig_p)
    check_status(env, status)
    return hasvmconfig_p.value() != 0


def qpopt(env, lp):
    with SigIntHandler():
        status = CR.CPXXqpopt(env, lp)
    check_status(env, status)


def baropt(env, lp):
    with SigIntHandler():
        status = CR.CPXXbaropt(env, lp)
    check_status(env, status)


def hybbaropt(env, lp, method):
    with SigIntHandler():
        status = CR.CPXXhybbaropt(env, lp, method)
    check_status(env, status)


def hybnetopt(env, lp, method):
    with SigIntHandler():
        status = CR.CPXXhybnetopt(env, lp, method)
    check_status(env, status)


def lpopt(env, lp):
    with SigIntHandler():
        status = CR.CPXXlpopt(env, lp)
    check_status(env, status)


def primopt(env, lp):
    status = CR.CPXXprimopt(env, lp)
    check_status(env, status)


def dualopt(env, lp):
    status = CR.CPXXdualopt(env, lp)
    check_status(env, status)


def siftopt(env, lp):
    status = CR.CPXXsiftopt(env, lp)
    check_status(env, status)


def feasoptext(env, lp, grppref, grpbeg, grpind, grptype):
    grpcnt = len(grppref)
    concnt = len(grpind)
    with SigIntHandler(), \
            LAU.double_c_array(grppref) as c_grppref, \
            LAU.int_c_array(grpbeg) as c_grpbeg, \
            LAU.int_c_array(grpind) as c_grpind:
        status = CR.CPXXfeasoptext(env, lp, grpcnt, concnt,
                                   c_grppref, c_grpbeg,
                                   c_grpind, grptype)
    check_status(env, status)


def delnames(env, lp):
    status = CR.CPXXdelnames(env, lp)
    check_status(env, status)


def writeprob(env, lp, filename, filetype="", enc=default_encoding):
    if filetype == "":
        status = CR.CPXXwriteprob(env, lp,
                                  cpx_decode_noop3(filename, enc))
    else:
        status = CR.CPXXwriteprob(env, lp,
                                  cpx_decode_noop3(filename, enc),
                                  cpx_decode_noop3(filetype, enc))
    check_status(env, status)


def embwrite(env, lp, filename, enc=default_encoding):
    status = CR.CPXXembwrite(env, lp, cpx_decode_noop3(filename, enc))
    check_status(env, status)


def dperwrite(env, lp, filename, epsilon, enc=default_encoding):
    status = CR.CPXXdperwrite(env, lp, cpx_decode_noop3(filename, enc),
                              epsilon)
    check_status(env, status)


def pperwrite(env, lp, filename, epsilon, enc=default_encoding):
    status = CR.CPXXpperwrite(env, lp, cpx_decode_noop3(filename, enc),
                              epsilon)
    check_status(env, status)


def preslvwrite(env, lp, filename, enc=default_encoding):
    objoff = CR.doublePtr()
    status = CR.CPXXpreslvwrite(env, lp, cpx_decode_noop3(filename, enc),
                                objoff)
    check_status(env, status)
    return objoff.value()


def dualwrite(env, lp, filename, enc=default_encoding):
    objshift = CR.doublePtr()
    status = CR.CPXXdualwrite(env, lp, cpx_decode_noop3(filename, enc),
                              objshift)
    check_status(env, status)
    return objshift.value()


def chgprobtype(env, lp, probtype):
    status = CR.CPXXchgprobtype(env, lp, probtype)
    check_status(env, status)


def chgprobtypesolnpool(env, lp, probtype, soln):
    status = CR.CPXXchgprobtypesolnpool(env, lp, probtype, soln)
    check_status(env, status)


def getprobtype(env, lp):
    return CR.CPXXgetprobtype(env, lp)


def chgprobname(env, lp, probname, enc=default_encoding):
    status = CR.CPXXchgprobname(env, lp, cpx_decode_noop3(probname, enc))
    check_status(env, status)


def getprobname(env, lp, enc=default_encoding):
    namefn = CR.CPXXgetprobname
    return _getnamesingle(env, lp, enc, namefn)


def getnumcols(env, lp):
    return CR.CPXXgetnumcols(env, lp)


def getnumint(env, lp):
    return CR.CPXXgetnumint(env, lp)


def getnumbin(env, lp):
    return CR.CPXXgetnumbin(env, lp)


def getnumsemicont(env, lp):
    return CR.CPXXgetnumsemicont(env, lp)


def getnumsemiint(env, lp):
    return CR.CPXXgetnumsemiint(env, lp)


def getnumrows(env, lp):
    return CR.CPXXgetnumrows(env, lp)


def populate(env, lp):
    with SigIntHandler():
        status = CR.CPXXpopulate(env, lp)
    check_status(env, status)


def _getnumusercuts(env, lp):
    return CR.CPXXgetnumusercuts(env, lp)


def _getnumlazyconstraints(env, lp):
    return CR.CPXXgetnumlazyconstraints(env, lp)


def _hasgeneralconstraints(env, lp):
    for which in range(CPX_CON_SOS + 1, CPX_CON_LAST_CONTYPE):
        if CR.CPXEgetnumgconstrs(env, lp, which) > 0:
            return True
    return False


def getnumqconstrs(env, lp):
    return CR.CPXXgetnumqconstrs(env, lp)


def getnumindconstrs(env, lp):
    return CR.CPXXgetnumindconstrs(env, lp)


def getnumsos(env, lp):
    return CR.CPXXgetnumsos(env, lp)


def cleanup(env, lp, eps):
    status = CR.CPXXcleanup(env, lp, eps)
    check_status(env, status)


def basicpresolve(env, lp):
    numcols = CR.CPXXgetnumcols(env, lp)
    numrows = CR.CPXXgetnumcols(env, lp)
    redlb = _safeDoubleArray(numcols)
    redub = _safeDoubleArray(numcols)
    rstat = _safeIntArray(numrows)
    status = CR.CPXXbasicpresolve(env, lp, redlb, redub, rstat)
    check_status(env, status)
    return (LAU.array_to_list(redlb, numcols),
            LAU.array_to_list(redub, numcols),
            LAU.array_to_list(rstat, numrows))


def pivotin(env, lp, rlist):
    status = CR.CPXXpivotin(env, lp,
                            LAU.int_list_to_array(rlist),
                            len(rlist))
    check_status(env, status)


def pivotout(env, lp, clist):
    status = CR.CPXXpivotout(env, lp,
                             LAU.int_list_to_array(clist),
                             len(clist))
    check_status(env, status)


def pivot(env, lp, jenter, jleave, leavestat):
    status = CR.CPXXpivot(env, lp, jenter, jleave, leavestat)
    check_status(env, status)


def strongbranch(env, lp, goodlist, itlim):
    goodlen = len(goodlist)
    downpen = _safeDoubleArray(goodlen)
    uppen = _safeDoubleArray(goodlen)
    with SigIntHandler():
        status = CR.CPXXstrongbranch(env, lp, goodlen, goodlist,
                                     downpen, uppen, itlim)
    check_status(env, status)
    return (LAU.array_to_list(downpen, goodlen),
            LAU.array_to_list(uppen, goodlen))


def completelp(env, lp):
    status = CR.CPXXcompletelp(env, lp)
    check_status(env, status)

# Variables


def newcols(env, lp, obj, lb, ub, xctype, colname, enc=default_encoding):
    ccnt = max(len(obj), len(lb), len(ub), len(xctype), len(colname))
    with LAU.double_c_array(obj) as c_obj, \
            LAU.double_c_array(lb) as c_lb, \
            LAU.double_c_array(ub) as c_ub:
        status = CR.CPXXnewcols(
            env, lp, ccnt, c_obj, c_lb, c_ub,
            cpx_decode(xctype, enc),
            [cpx_decode(x, enc) for x in colname])
    check_status(env, status)


def addcols(env, lp, ccnt, nzcnt, obj, cmat, lb, ub, colname,
            enc=default_encoding):
    with LAU.double_c_array(obj) as c_obj, \
            LAU.double_c_array(lb) as c_lb, \
            LAU.double_c_array(ub) as c_ub:
        status = CR.CPXXaddcols(
            env, lp, ccnt, nzcnt,
            c_obj, cmat, c_lb, c_ub,
            [cpx_decode(x, enc) for x in colname])
    check_status(env, status)


def delcols(env, lp, begin, end):
    delfn = CR.CPXXdelcols
    _delbyrange(delfn, env, lp, begin, end)


def chgbds(env, lp, indices, lu, bd):
    with LAU.int_c_array(indices) as c_ind, \
            LAU.double_c_array(bd) as c_bd:
        status = CR.CPXXchgbds(env, lp, len(indices),
                               c_ind, lu, c_bd)
    check_status(env, status)


def chgcolname(env, lp, indices, newnames, enc=default_encoding):
    with LAU.int_c_array(indices) as c_indices:
        status = CR.CPXXchgcolname(env, lp, len(indices),
                                   c_indices,
                                   [cpx_decode(x, enc) for x in newnames])
    check_status(env, status)


def chgctype(env, lp, indices, xctype):
    with LAU.int_c_array(indices) as c_indices:
        status = CR.CPXXchgctype(env, lp, len(indices),
                                 c_indices,
                                 cpx_decode(xctype, default_encoding))
    check_status(env, status)


def getcolindex(env, lp, colname, enc=default_encoding):
    index = CR.intPtr()
    status = CR.CPXXgetcolindex(env, lp, cpx_decode_noop3(colname, enc),
                                index)
    check_status(env, status)
    return index.value()


def getcolname(env, lp, begin, end, enc=default_encoding):
    namefn = CR.CPXXgetcolname
    return _getnamebyrange(env, lp, begin, end, enc, namefn)


def getctype(env, lp, begin, end):
    inout_list = [begin, end]
    status = CR.CPXXgetctype(env, lp, inout_list)
    check_status(env, status)
    # We expect to get [sense]
    assert len(inout_list) == 1
    return cpx_encode(inout_list[0], default_encoding)


def getlb(env, lp, begin, end):
    lblen = _rangelen(begin, end)
    lb = _safeDoubleArray(lblen)
    status = CR.CPXXgetlb(env, lp, lb, begin, end)
    check_status(env, status)
    return LAU.array_to_list(lb, lblen)


def getub(env, lp, begin, end):
    ublen = _rangelen(begin, end)
    ub = _safeDoubleArray(ublen)
    status = CR.CPXXgetub(env, lp, ub, begin, end)
    check_status(env, status)
    return LAU.array_to_list(ub, ublen)


def getcols(env, lp, begin, end):
    inout_list = [0, begin, end]
    status = CR.CPXXgetcols(env, lp, inout_list)
    if status != CR.CPXERR_NEGATIVE_SURPLUS:
        check_status(env, status)
    if inout_list == [0]:
        return ([0] * _rangelen(begin, end), [], [])
    inout_list.extend([begin, end])
    status = CR.CPXXgetcols(env, lp, inout_list)
    check_status(env, status)
    return tuple(inout_list)


def copyprotected(env, lp, indices):
    status = CR.CPXXcopyprotected(env, lp, len(indices),
                                  LAU.int_list_to_array(indices))
    check_status(env, status)


def getprotected(env, lp):
    count = CR.intPtr()
    surplus = CR.intPtr()
    indices = LAU.int_list_to_array([])
    pspace = 0
    status = CR.CPXXgetprotected(env, lp, count, indices, pspace, surplus)
    if status != CR.CPXERR_NEGATIVE_SURPLUS:
        check_status(env, status)
    if surplus.value() == 0:
        return []
    pspace = -surplus.value()
    indices = _safeIntArray(pspace)
    status = CR.CPXXgetprotected(env, lp, count, indices, pspace, surplus)
    check_status(env, status)
    return LAU.array_to_list(indices, pspace)


def tightenbds(env, lp, indices, lu, bd):
    status = CR.CPXXtightenbds(env, lp, len(indices),
                               LAU.int_list_to_array(indices),
                               lu, LAU.double_list_to_array(bd))
    check_status(env, status)

# Linear Constraints


def newrows(env, lp, rhs, sense, rngval, rowname, enc=default_encoding):
    rcnt = max(len(rhs), len(sense), len(rngval), len(rowname))
    with LAU.double_c_array(rhs) as c_rhs, \
            LAU.double_c_array(rngval) as c_rng:
        status = CR.CPXXnewrows(
            env, lp, rcnt, c_rhs,
            cpx_decode(sense, enc),
            c_rng,
            [cpx_decode(x, enc) for x in rowname])
    check_status(env, status)


def addrows(env, lp, ccnt, rcnt, nzcnt, rhs, sense, rmat, colname, rowname,
            enc=default_encoding):
    with LAU.double_c_array(rhs) as c_rhs:
        status = CR.CPXXaddrows(
            env, lp, ccnt, rcnt, nzcnt, c_rhs,
            cpx_decode(sense, enc), rmat, colname,
            [cpx_decode(x, enc) for x in rowname])
    check_status(env, status)


def delrows(env, lp, begin, end):
    delfn = CR.CPXXdelrows
    _delbyrange(delfn, env, lp, begin, end)


def chgrowname(env, lp, indices, newnames, enc=default_encoding):
    with LAU.int_c_array(indices) as c_indices:
        status = CR.CPXXchgrowname(env, lp, len(indices), c_indices,
                                   [cpx_decode(x, enc) for x in newnames])
    check_status(env, status)


def chgcoeflist(env, lp, rowlist, collist, vallist):
    with LAU.int_c_array(rowlist) as c_rowlist, \
            LAU.int_c_array(collist) as c_collist, \
            LAU.double_c_array(vallist) as c_vallist:
        status = CR.CPXXchgcoeflist(env, lp, len(rowlist),
                                    c_rowlist, c_collist, c_vallist)
    check_status(env, status)


def chgrhs(env, lp, indices, values):
    with LAU.int_c_array(indices) as c_ind, \
            LAU.double_c_array(values) as c_val:
        status = CR.CPXXchgrhs(env, lp, len(indices), c_ind, c_val)
    check_status(env, status)


def chgrngval(env, lp, indices, values):
    with LAU.int_c_array(indices) as c_ind, \
            LAU.double_c_array(values) as c_val:
        status = CR.CPXXchgrngval(env, lp, len(indices), c_ind, c_val)
    check_status(env, status)


def chgsense(env, lp, indices, senses):
    with LAU.int_c_array(indices) as c_indices:
        status = CR.CPXXchgsense(env, lp, len(indices), c_indices,
                                 cpx_decode(senses, default_encoding))
    check_status(env, status)


def getrhs(env, lp, begin, end):
    rhslen = _rangelen(begin, end)
    rhs = _safeDoubleArray(rhslen)
    status = CR.CPXXgetrhs(env, lp, rhs, begin, end)
    check_status(env, status)
    return LAU.array_to_list(rhs, rhslen)


def getsense(env, lp, begin, end):
    inout_list = [begin, end]
    status = CR.CPXXgetsense(env, lp, inout_list)
    check_status(env, status)
    # We expect to get [sense]
    assert len(inout_list) == 1
    return cpx_encode(inout_list[0], default_encoding)


def getrngval(env, lp, begin, end):
    rngvallen = _rangelen(begin, end)
    rngval = _safeDoubleArray(rngvallen)
    status = CR.CPXXgetrngval(env, lp, rngval, begin, end)
    check_status(env, status)
    return LAU.array_to_list(rngval, rngvallen)


def getrowname(env, lp, begin, end, enc=default_encoding):
    namefn = CR.CPXXgetrowname
    return _getnamebyrange(env, lp, begin, end, enc, namefn)


def getcoef(env, lp, i, j):
    coef = CR.doublePtr()
    status = CR.CPXXgetcoef(env, lp, i, j, coef)
    check_status(env, status)
    return coef.value()


def getrowindex(env, lp, rowname, enc=default_encoding):
    index = CR.intPtr()
    status = CR.CPXXgetrowindex(env, lp, cpx_decode_noop3(rowname, enc), index)
    check_status(env, status)
    return index.value()


def getrows(env, lp, begin, end):
    inout_list = [0, begin, end]
    status = CR.CPXXgetrows(env, lp, inout_list)
    if status != CR.CPXERR_NEGATIVE_SURPLUS:
        check_status(env, status)
    if inout_list == [0]:
        return ([0] * _rangelen(begin, end), [], [])
    inout_list.extend([begin, end])
    status = CR.CPXXgetrows(env, lp, inout_list)
    check_status(env, status)
    return tuple(inout_list)


def getnumnz(env, lp):
    return CR.CPXXgetnumnz(env, lp)


def addlazyconstraints(env, lp, rhs, sense, lin_expr, names,
                       enc=default_encoding):
    env_lp_ptr = pack_env_lp_ptr(env, lp)
    with chbmatrix(lin_expr, env_lp_ptr, 0, enc) as (rmat, nnz), \
            LAU.double_c_array(rhs) as c_rhs:
        rmatbeg, rmatind, rmatval = rmat
        status = CR.CPXXaddlazyconstraints(
            env, lp, len(rhs), nnz,
            c_rhs, cpx_decode(sense, enc),
            rmatbeg, rmatind, rmatval,
            [cpx_decode(x, enc) for x in names])
    check_status(env, status)


def addusercuts(env, lp, rhs, sense, lin_expr, names,
                enc=default_encoding):
    env_lp_ptr = pack_env_lp_ptr(env, lp)
    with chbmatrix(lin_expr, env_lp_ptr, 0, enc) as (rmat, nnz), \
            LAU.double_c_array(rhs) as c_rhs:
        rmatbeg, rmatind, rmatval = rmat
        status = CR.CPXXaddusercuts(
            env, lp, len(rhs), nnz,
            c_rhs, cpx_decode(sense, enc),
            rmatbeg, rmatind, rmatval,
            [cpx_decode(x, enc) for x in names])
    check_status(env, status)


def freelazyconstraints(env, lp):
    status = CR.CPXXfreelazyconstraints(env, lp)
    check_status(env, status)


def freeusercuts(env, lp):
    status = CR.CPXXfreeusercuts(env, lp)
    check_status(env, status)

########################################################################
# SOS API
########################################################################


def addsos(env, lp, sostype, sosbeg, sosind, soswt, sosnames,
           enc=default_encoding):
    with LAU.int_c_array(sosbeg) as c_sosbeg, \
            LAU.int_c_array(sosind) as c_sosind, \
            LAU.double_c_array(soswt) as c_soswt:
        status = CR.CPXXaddsos(env, lp, len(sosbeg), len(sosind), sostype,
                               c_sosbeg, c_sosind, c_soswt,
                               [cpx_decode(x, enc) for x in sosnames])
    check_status(env, status)


def delsos(env, lp, begin, end):
    delfn = CR.CPXXdelsos
    _delbyrange(delfn, env, lp, begin, end)


def getsos_info(env, lp, begin, end):
    inout_list = [0, begin, end]
    status = CR.CPXXgetsos(env, lp, inout_list)
    if status != CR.CPXERR_NEGATIVE_SURPLUS:
        check_status(env, status)
    # We expect to get [sostype, surplus]
    assert len(inout_list) == 2
    inout_list[0] = cpx_encode(inout_list[0], default_encoding)
    return tuple(inout_list)


def getsos(env, lp, begin, end):
    numsos = _rangelen(begin, end)
    _, surplus = getsos_info(env, lp, begin, end)
    if surplus == 0:
        return ([0] * numsos, [], [])
    inout_list = [surplus, begin, end]
    status = CR.CPXXgetsos(env, lp, inout_list)
    check_status(env, status)
    # We expect to get [sosbeg, sosind, soswt]
    assert len(inout_list) == 3
    return tuple(inout_list)


def getsosindex(env, lp, name, enc=default_encoding):
    indexfn = CR.CPXXgetsosindex
    return _getindex(env, lp, name, enc, indexfn)


def getsosname(env, lp, begin, end, enc=default_encoding):
    namefn = CR.CPXXgetsosname
    return _getnamebyrange(env, lp, begin, end, enc, namefn)

########################################################################
# Indicator Constraint API
########################################################################


def addindconstr(env, lp, indcnt, indvar, complemented, rhs, sense, linmat,
                 indtype, name, nzcnt, enc=default_encoding):
    with LAU.int_c_array(indtype) as c_indtype, \
            LAU.int_c_array(indvar) as c_indvar, \
            LAU.int_c_array(complemented) as c_complemented, \
            LAU.double_c_array(rhs) as c_rhs:
        status = CR.CPXXaddindconstraints(
            env, lp, indcnt, c_indtype, c_indvar,
            c_complemented, nzcnt, c_rhs,
            cpx_decode(sense, enc), linmat,
            [cpx_decode(x, enc) for x in name])
    check_status(env, status)


def getindconstr(env, lp, begin, end):
    _, _, _, _, _, surplus = getindconstr_constant(env, lp, begin, end)
    if surplus == 0:
        return ([0] * _rangelen(begin, end), [], [])
    # inout_list contains the linspace, begin, and end args to
    # CPXXgetindconstraints.
    inout_list = [surplus, begin, end]
    status = CR.CPXXgetindconstraints(env, lp, inout_list)
    check_status(env, status)
    # We expect to get [linbeg, linind, linval]
    assert len(inout_list) == 3
    return tuple(inout_list)


def getindconstr_constant(env, lp, begin, end):
    # FIXME: See RTC-31484.
    if end < begin:
        return ([], [], [], [], "", 0)
    # inout_list contains the linspace, begin, and end args to
    # CPXXgetindconstraints.
    inout_list = [0, begin, end]
    status = CR.CPXXgetindconstraints(env, lp, inout_list)
    if status != CR.CPXERR_NEGATIVE_SURPLUS:
        check_status(env, status)
    # We expect to get:
    # [type, indvar, complemented, rhs, sense, surplus]
    assert len(inout_list) == 6
    inout_list[4] = cpx_encode(inout_list[4], default_encoding)
    return tuple(inout_list)


def getindconstrindex(env, lp, name, enc=default_encoding):
    indexfn = CR.CPXXgetindconstrindex
    return _getindex(env, lp, name, enc, indexfn)


def delindconstrs(env, lp, begin, end):
    delfn = CR.CPXXdelindconstrs
    _delbyrange(delfn, env, lp, begin, end)


def getindconstrslack(env, lp, begin, end):
    slacklen = _rangelen(begin, end)
    slacks = _safeDoubleArray(slacklen)
    status = CR.CPXXgetindconstrslack(env, lp, slacks, begin, end)
    check_status(env, status)
    return LAU.array_to_list(slacks, slacklen)


def getindconstrname(env, lp, which, enc=default_encoding):
    namefn = CR.CPXXgetindconstrname
    return _getname(env, lp, which, enc, namefn, index_first=False)

########################################################################
# Quadratic Constraints
########################################################################


def addqconstr(env, lp, rhs, sense, linind, linval, quadrow, quadcol,
               quadval, name, enc=default_encoding):
    with LAU.int_c_array(linind) as c_linind, \
            LAU.double_c_array(linval) as c_linval, \
            LAU.int_c_array(quadrow) as c_quadrow, \
            LAU.int_c_array(quadcol) as c_quadcol, \
            LAU.double_c_array(quadval) as c_quadval:
        status = CR.CPXXaddqconstr(env, lp, len(linind), len(quadrow),
                                   rhs, cpx_decode(sense, enc),
                                   c_linind, c_linval,
                                   c_quadrow, c_quadcol, c_quadval,
                                   cpx_decode_noop3(name, enc))
    check_status(env, status)


def getqconstr_info(env, lp, which):
    inout_list = [0, 0, which]
    status = CR.CPXXgetqconstr(env, lp, inout_list)
    if status != CR.CPXERR_NEGATIVE_SURPLUS:
        check_status(env, status)
    # We expect to get [rhs, sense, linsurplus, quadsurplus]
    assert len(inout_list) == 4
    assert len(inout_list[1]) == 1  # sense string should be one char
    inout_list[1] = cpx_encode(inout_list[1], default_encoding)
    return tuple(inout_list)


def getqconstr_lin(env, lp, which):
    _, _, linsurplus, _ = getqconstr_info(env, lp, which)
    if linsurplus == 0:
        return ([], [])
    inout_list = [linsurplus, 0, which]
    status = CR.CPXXgetqconstr(env, lp, inout_list)
    if status != CR.CPXERR_NEGATIVE_SURPLUS:
        check_status(env, status)
    # We expect to get [linind, linval, quadrow, quadcol, quadval]
    assert len(inout_list) == 5
    return tuple(inout_list[:2])  # slice off the quad info


def getqconstr_quad(env, lp, which):
    _, _, _, quadsurplus = getqconstr_info(env, lp, which)
    if quadsurplus == 0:
        return ([], [], [])
    inout_list = [0, quadsurplus, which]
    status = CR.CPXXgetqconstr(env, lp, inout_list)
    if status != CR.CPXERR_NEGATIVE_SURPLUS:
        check_status(env, status)
    # We expect to get [linind, linval, quadrow, quadcol, quadval]
    assert len(inout_list) == 5
    return tuple(inout_list[2:])  # slice off the lin info


def delqconstrs(env, lp, begin, end):
    delfn = CR.CPXXdelqconstrs
    _delbyrange(delfn, env, lp, begin, end)


def getqconstrindex(env, lp, name, enc=default_encoding):
    indexfn = CR.CPXXgetqconstrindex
    return _getindex(env, lp, name, enc, indexfn)


def getqconstrslack(env, lp, begin, end):
    slacklen = _rangelen(begin, end)
    slacks = _safeDoubleArray(slacklen)
    status = CR.CPXXgetqconstrslack(env, lp, slacks, begin, end)
    check_status(env, status)
    return LAU.array_to_list(slacks, slacklen)


def getqconstrname(env, lp, which, enc=default_encoding):
    namefn = CR.CPXXgetqconstrname
    return _getname(env, lp, which, enc, namefn, index_first=False)

########################################################################
# Generic helper methods
########################################################################


def _delbyrange(delfn, env, lp, begin, end=None):
    if end is None:
        end = begin
    status = delfn(env, lp, begin, end)
    check_status(env, status)


def _getindex(env, lp, name, enc, indexfn):
    idx = CR.intPtr()
    status = indexfn(env, lp, cpx_decode_noop3(name, enc), idx)
    check_status(env, status)
    return idx.value()


def _getname(env, lp, idx, enc, namefn, index_first=True):
    # Some name functions have the index argument first and some have it
    # last.  Thus, we do this little dance, so things are called in the
    # right way depending on index_first.
    def _namefn(env, lp, idx, inoutlist):
        if index_first:
            return namefn(env, lp, idx, inoutlist)
        else:
            return namefn(env, lp, inoutlist, idx)
    inoutlist = [0]
    # NB: inoutlist will be modified as a side effect
    status = _namefn(env, lp, idx, inoutlist)
    if status != CR.CPXERR_NEGATIVE_SURPLUS:
        check_status(env, status)
    if inoutlist == [0]:
        return None
    status = _namefn(env, lp, idx, inoutlist)
    check_status(env, status)
    return cpx_encode_noop3(inoutlist[0], enc)


def _getnamebyrange(env, lp, begin, end, enc, namefn):
    # FIXME: See RTC-31484.
    if end < begin:
        return []
    inout_list = [0, begin, end]
    status = namefn(env, lp, inout_list)
    if status != CR.CPXERR_NEGATIVE_SURPLUS:
        check_status(env, status)
    if inout_list == [0]:
        return [None] * _rangelen(begin, end)
    inout_list.extend([begin, end])
    status = namefn(env, lp, inout_list)
    check_status(env, status)
    return [cpx_encode_noop3(x, enc) for x in inout_list]


def _getnamesingle(env, lp, enc, namefn):
    inoutlist = [0]
    status = namefn(env, lp, inoutlist)
    if status != CR.CPXERR_NEGATIVE_SURPLUS:
        check_status(env, status)
    if inoutlist == [0]:
        return None
    status = namefn(env, lp, inoutlist)
    check_status(env, status)
    return cpx_encode_noop3(inoutlist[0], enc)

########################################################################
# Annotation API
########################################################################


def _newanno(env, lp, name, defval, newfn):
    status = newfn(env, lp, name, defval)
    check_status(env, status)


def newlonganno(env, lp, name, defval, enc=default_encoding):
    newfn = CR.CPXXnewlongannotation
    _newanno(env, lp, cpx_decode_noop3(name, enc), defval, newfn)


def newdblanno(env, lp, name, defval, enc=default_encoding):
    newfn = CR.CPXXnewdblannotation
    _newanno(env, lp, cpx_decode_noop3(name, enc), defval, newfn)


def dellonganno(env, lp, begin, end):
    delfn = CR.CPXXdellongannotations
    _delbyrange(delfn, env, lp, begin, end)


def deldblanno(env, lp, begin, end):
    delfn = CR.CPXXdeldblannotations
    _delbyrange(delfn, env, lp, begin, end)


def getlongannoindex(env, lp, name, enc=default_encoding):
    indexfn = CR.CPXXgetlongannotationindex
    return _getindex(env, lp, name, enc, indexfn)


def getdblannoindex(env, lp, name, enc=default_encoding):
    indexfn = CR.CPXXgetdblannotationindex
    return _getindex(env, lp, name, enc, indexfn)


def getlongannoname(env, lp, idx, enc=default_encoding):
    namefn = CR.CPXXgetlongannotationname
    return _getname(env, lp, idx, enc, namefn)


def getdblannoname(env, lp, idx, enc=default_encoding):
    namefn = CR.CPXXgetdblannotationname
    return _getname(env, lp, idx, enc, namefn)


def getnumlonganno(env, lp):
    return CR.CPXXgetnumlongannotations(env, lp)


def getnumdblanno(env, lp):
    return CR.CPXXgetnumdblannotations(env, lp)


def getlongannodefval(env, lp, idx):
    defval = CR.cpxlongPtr()
    status = CR.CPXXgetlongannotationdefval(env, lp, idx, defval)
    check_status(env, status)
    return int(defval.value())


def getdblannodefval(env, lp, idx):
    defval = CR.doublePtr()
    status = CR.CPXXgetdblannotationdefval(env, lp, idx, defval)
    check_status(env, status)
    return defval.value()


def setlonganno(env, lp, idx, objtype, ind, val):
    assert len(ind) == len(val)
    cnt = len(ind)
    status = CR.CPXXsetlongannotations(env, lp, idx, objtype, cnt,
                                       LAU.int_list_to_array(ind),
                                       LAU.long_list_to_array(val))
    check_status(env, status)


def setdblanno(env, lp, idx, objtype, ind, val):
    assert len(ind) == len(val)
    cnt = len(ind)
    status = CR.CPXXsetdblannotations(env, lp, idx, objtype, cnt,
                                      LAU.int_list_to_array(ind),
                                      LAU.double_list_to_array(val))
    check_status(env, status)


def getlonganno(env, lp, idx, objtype, begin, end):
    annolen = _rangelen(begin, end)
    val = _safeLongArray(annolen)
    status = CR.CPXXgetlongannotations(env, lp, idx, objtype, val,
                                       begin, end)
    check_status(env, status)
    return [int(i) for i in LAU.array_to_list(val, annolen)]


def getdblanno(env, lp, idx, objtype, begin, end):
    annolen = _rangelen(begin, end)
    val = _safeDoubleArray(annolen)
    status = CR.CPXXgetdblannotations(env, lp, idx, objtype, val,
                                      begin, end)
    check_status(env, status)
    return LAU.array_to_list(val, annolen)


def readcopyanno(env, lp, filename, enc=default_encoding):
    status = CR.CPXXreadcopyannotations(env, lp,
                                        cpx_decode_noop3(filename, enc))
    check_status(env, status)


def writeanno(env, lp, filename, enc=default_encoding):
    status = CR.CPXXwriteannotations(env, lp,
                                     cpx_decode_noop3(filename, enc))
    check_status(env, status)


def writebendersanno(env, lp, filename, enc=default_encoding):
    status = CR.CPXXwritebendersannotation(env, lp,
                                           cpx_decode_noop3(filename, enc))
    check_status(env, status)

########################################################################
# PWL API
########################################################################


def addpwl(env, lp, vary, varx, preslope, postslope, nbreaks,
           breakx, breaky, name, enc=default_encoding):
    assert len(breakx) == nbreaks
    assert len(breaky) == nbreaks
    with LAU.double_c_array(breakx) as c_breakx, \
            LAU.double_c_array(breaky) as c_breaky:
        status = CR.CPXXaddpwl(env, lp, vary, varx, preslope, postslope,
                               nbreaks, c_breakx, c_breaky,
                               cpx_decode_noop3(name, enc))
    check_status(env, status)


def delpwl(env, lp, begin, end):
    delfn = CR.CPXXdelpwl
    _delbyrange(delfn, env, lp, begin, end)


def getnumpwl(env, lp):
    return CR.CPXXgetnumpwl(env, lp)


def getpwl(env, lp, idx):
    # Initially, the inout_list contains the pwlindex and breakspace args
    # to CPXXgetpwl.  We use zero (0) for breakspace to query the
    # surplus.
    inout_list = [idx, 0]
    status = CR.CPXXgetpwl(env, lp, inout_list)
    if status != CR.CPXERR_NEGATIVE_SURPLUS:
        check_status(env, status)
    # We expect to get [vary, varx, preslope, postslope, surplus]
    assert len(inout_list) == 5
    vary, varx, preslope, postslope, surplus = inout_list
    # FIXME: Should we assert surplus is > 0?
    inout_list = [idx, surplus]
    status = CR.CPXXgetpwl(env, lp, inout_list)
    check_status(env, status)
    # We expect to get [breakx, breaky]
    assert len(inout_list) == 2
    breakx, breaky = inout_list
    return [vary, varx, preslope, postslope, breakx, breaky]


def getpwlindex(env, lp, name, enc=default_encoding):
    indexfn = CR.CPXXgetpwlindex
    return _getindex(env, lp, name, enc, indexfn)


def getpwlname(env, lp, idx, enc=default_encoding):
    namefn = CR.CPXXgetpwlname
    return _getname(env, lp, idx, enc, namefn, index_first=False)

########################################################################
# Objective API
########################################################################


def copyobjname(env, lp, objname, enc=default_encoding):
    status = CR.CPXXcopyobjname(env, lp, objname)
    check_status(env, status)


def chgobj(env, lp, indices, values):
    with LAU.int_c_array(indices) as c_ind, \
            LAU.double_c_array(values) as c_val:
        status = CR.CPXXchgobj(env, lp, len(indices), c_ind, c_val)
    check_status(env, status)


def chgobjsen(env, lp, maxormin):
    status = CR.CPXXchgobjsen(env, lp, maxormin)
    check_status(env, status)


def getobjsen(env, lp):
    return CR.CPXXgetobjsen(env, lp)


def getobjoffset(env, lp):
    objoffset = CR.doublePtr()
    status = CR.CPXXgetobjoffset(env, lp, objoffset)
    check_status(env, status)
    return objoffset.value()


def chgobjoffset(env, lp, offset):
    status = CR.CPXXchgobjoffset(env, lp, offset)
    check_status(env, status)


def getobj(env, lp, begin, end):
    objlen = _rangelen(begin, end)
    obj = _safeDoubleArray(objlen)
    status = CR.CPXXgetobj(env, lp, obj, begin, end)
    check_status(env, status)
    return LAU.array_to_list(obj, objlen)


def getobjname(env, lp, enc=default_encoding):
    namefn = CR.CPXXgetobjname
    return _getnamesingle(env, lp, enc, namefn)


def copyquad(env, lp, qmatbeg, qmatind, qmatval):
    if len(qmatbeg) > 0:
        qmatcnt = [qmatbeg[i + 1] - qmatbeg[i]
                   for i in range(len(qmatbeg) - 1)]
        qmatcnt.append(len(qmatind) - qmatbeg[-1])
    else:
        qmatcnt = []
    with LAU.int_c_array(qmatbeg) as c_qmatbeg, \
            LAU.int_c_array(qmatcnt) as c_qmatcnt, \
            LAU.int_c_array(qmatind) as c_qmatind, \
            LAU.double_c_array(qmatval) as c_qmatval:
        status = CR.CPXXcopyquad(env, lp, c_qmatbeg, c_qmatcnt,
                                 c_qmatind, c_qmatval)
    check_status(env, status)


def copyqpsep(env, lp, qsepvec):
    with LAU.double_c_array(qsepvec) as c_qsepvec:
        status = CR.CPXXcopyqpsep(env, lp, c_qsepvec)
    check_status(env, status)


def chgqpcoef(env, lp, row, col, value):
    status = CR.CPXXchgqpcoef(env, lp, row, col, value)
    check_status(env, status)


def getquad(env, lp, begin, end):
    nzcnt = CR.intPtr()
    ncols = _rangelen(begin, end)
    qmatbeg = _safeIntArray(ncols)
    qmatind = LAU.int_list_to_array([])
    qmatval = LAU.double_list_to_array([])
    space = 0
    surplus = CR.intPtr()
    status = CR.CPXXgetquad(env, lp, nzcnt, qmatbeg, qmatind, qmatval,
                            space, surplus, begin, end)
    if status != CR.CPXERR_NEGATIVE_SURPLUS:
        check_status(env, status)
    if surplus.value() == 0:
        return ([], [], [])
    space = -surplus.value()
    qmatind = _safeIntArray(space)
    qmatval = _safeDoubleArray(space)
    status = CR.CPXXgetquad(env, lp, nzcnt, qmatbeg, qmatind, qmatval,
                            space, surplus, begin, end)
    check_status(env, status)
    return (LAU.array_to_list(qmatbeg, ncols),
            LAU.array_to_list(qmatind, space),
            LAU.array_to_list(qmatval, space))


def getqpcoef(env, lp, row, col):
    val = CR.doublePtr()
    status = CR.CPXXgetqpcoef(env, lp, row, col, val)
    check_status(env, status)
    return val.value()


def getnumquad(env, lp):
    return CR.CPXXgetnumquad(env, lp)


def getnumqpnz(env, lp):
    return CR.CPXXgetnumqpnz(env, lp)


# Optimizing Problems

# Accessing LP results

def solninfo(env, lp):
    lpstat = CR.intPtr()
    stype = CR.intPtr()
    pfeas = CR.intPtr()
    dfeas = CR.intPtr()
    status = CR.CPXXsolninfo(env, lp, lpstat, stype, pfeas, dfeas)
    check_status(env, status)
    return (lpstat.value(), stype.value(), pfeas.value(), dfeas.value())


def getstat(env, lp):
    return CR.CPXXgetstat(env, lp)


def getmethod(env, lp):
    return CR.CPXXgetmethod(env, lp)


def getobjval(env, lp):
    objval = CR.doublePtr()
    status = CR.CPXXgetobjval(env, lp, objval)
    check_status(env, status)
    return objval.value()


def getx(env, lp, begin, end):
    xlen = _rangelen(begin, end)
    x = _safeDoubleArray(xlen)
    status = CR.CPXXgetx(env, lp, x, begin, end)
    check_status(env, status)
    return LAU.array_to_list(x, xlen)


def getnumcores(env):
    numcores = CR.intPtr()
    status = CR.CPXXgetnumcores(env, numcores)
    check_status(env, status)
    return numcores.value()


def getax(env, lp, begin, end):
    axlen = _rangelen(begin, end)
    ax = _safeDoubleArray(axlen)
    status = CR.CPXXgetax(env, lp, ax, begin, end)
    check_status(env, status)
    return LAU.array_to_list(ax, axlen)


def getxqxax(env, lp, begin, end):
    qaxlen = _rangelen(begin, end)
    qax = _safeDoubleArray(qaxlen)
    status = CR.CPXXgetxqxax(env, lp, qax, begin, end)
    check_status(env, status)
    return LAU.array_to_list(qax, qaxlen)


def getpi(env, lp, begin, end):
    pilen = _rangelen(begin, end)
    pi = _safeDoubleArray(pilen)
    status = CR.CPXXgetpi(env, lp, pi, begin, end)
    check_status(env, status)
    return LAU.array_to_list(pi, pilen)


def getslack(env, lp, begin, end):
    slacklen = _rangelen(begin, end)
    slack = _safeDoubleArray(slacklen)
    status = CR.CPXXgetslack(env, lp, slack, begin, end)
    check_status(env, status)
    return LAU.array_to_list(slack, slacklen)


def getdj(env, lp, begin, end):
    djlen = _rangelen(begin, end)
    dj = _safeDoubleArray(djlen)
    status = CR.CPXXgetdj(env, lp, dj, begin, end)
    check_status(env, status)
    return LAU.array_to_list(dj, djlen)


def getqconstrdslack(env, lp, qind):
    inout_list = [0, qind]
    status = CR.CPXXgetqconstrdslack(env, lp, inout_list)
    if status != CR.CPXERR_NEGATIVE_SURPLUS:
        check_status(env, status)
    if inout_list == [0]:
        return ([], [])
    inout_list.extend([qind])
    status = CR.CPXXgetqconstrdslack(env, lp, inout_list)
    check_status(env, status)
    return tuple(inout_list)


# Infeasibility

def getrowinfeas(env, lp, x, begin, end):
    infeasoutlen = _rangelen(begin, end)
    infeasout = _safeDoubleArray(infeasoutlen)
    status = CR.CPXXgetrowinfeas(env, lp, LAU.double_list_to_array(x),
                                 infeasout, begin, end)
    check_status(env, status)
    return LAU.array_to_list(infeasout, infeasoutlen)


def getcolinfeas(env, lp, x, begin, end):
    infeasoutlen = _rangelen(begin, end)
    infeasout = _safeDoubleArray(infeasoutlen)
    status = CR.CPXXgetcolinfeas(env, lp, LAU.double_list_to_array(x),
                                 infeasout, begin, end)
    check_status(env, status)
    return LAU.array_to_list(infeasout, infeasoutlen)


def getqconstrinfeas(env, lp, x, begin, end):
    infeasoutlen = _rangelen(begin, end)
    infeasout = _safeDoubleArray(infeasoutlen)
    status = CR.CPXXgetqconstrinfeas(env, lp, LAU.double_list_to_array(x),
                                     infeasout, begin, end)
    check_status(env, status)
    return LAU.array_to_list(infeasout, infeasoutlen)


def getindconstrinfeas(env, lp, x, begin, end):
    infeasoutlen = _rangelen(begin, end)
    infeasout = _safeDoubleArray(infeasoutlen)
    status = CR.CPXXgetindconstrinfeas(env, lp, LAU.double_list_to_array(x),
                                       infeasout, begin, end)
    check_status(env, status)
    return LAU.array_to_list(infeasout, infeasoutlen)


def getsosinfeas(env, lp, x, begin, end):
    infeasoutlen = _rangelen(begin, end)
    infeasout = _safeDoubleArray(infeasoutlen)
    status = CR.CPXXgetsosinfeas(env, lp, LAU.double_list_to_array(x),
                                 infeasout, begin, end)
    check_status(env, status)
    return LAU.array_to_list(infeasout, infeasoutlen)

# Basis


def getbase(env, lp):
    numcols = CR.CPXXgetnumcols(env, lp)
    numrows = CR.CPXXgetnumrows(env, lp)
    cstat = _safeIntArray(numcols)
    rstat = _safeIntArray(numrows)
    status = CR.CPXXgetbase(env, lp, cstat, rstat)
    check_status(env, status)
    return (LAU.array_to_list(cstat, numcols),
            LAU.array_to_list(rstat, numrows))


def getbhead(env, lp):
    headlen = CR.CPXXgetnumrows(env, lp)
    head = _safeIntArray(headlen)
    x = _safeDoubleArray(headlen)
    status = CR.CPXXgetbhead(env, lp, head, x)
    check_status(env, status)
    return (LAU.array_to_list(head, headlen),
            LAU.array_to_list(x, headlen))


def mbasewrite(env, lp, filename, enc=default_encoding):
    status = CR.CPXXmbasewrite(env, lp, cpx_decode_noop3(filename, enc))
    check_status(env, status)


def getijrow(env, lp, i, row_or_column):
    row = CR.intPtr()
    if row_or_column == 'r' or row_or_column == 'R':
        status = CR.CPXXgetijrow(env, lp, i, -1, row)
    elif row_or_column == 'c' or row_or_column == 'C':
        status = CR.CPXXgetijrow(env, lp, -1, i, row)
    if status == CR.CPXERR_INDEX_NOT_BASIC:
        return -1
    else:
        check_status(env, status)
    return row.value()


def getpnorms(env, lp):
    numcols = CR.CPXXgetnumcols(env, lp)
    numrows = CR.CPXXgetnumrows(env, lp)
    cnorm = _safeDoubleArray(numcols)
    rnorm = _safeDoubleArray(numrows)
    length = CR.intPtr()
    status = CR.CPXXgetpnorms(env, lp, cnorm, rnorm, length)
    check_status(env, status)
    return (LAU.array_to_list(cnorm, length.value()),
            LAU.array_to_list(rnorm, numrows))


def getdnorms(env, lp):
    numrows = CR.CPXXgetnumrows(env, lp)
    norm = _safeDoubleArray(numrows)
    head = _safeIntArray(numrows)
    length = CR.intPtr()
    status = CR.CPXXgetdnorms(env, lp, norm, head, length)
    check_status(env, status)
    return (LAU.array_to_list(norm, length.value()),
            LAU.array_to_list(head, length.value()))


def getbasednorms(env, lp):
    numcols = CR.CPXXgetnumcols(env, lp)
    numrows = CR.CPXXgetnumrows(env, lp)
    cstat = _safeIntArray(numcols)
    rstat = _safeIntArray(numrows)
    dnorm = _safeDoubleArray(numrows)
    status = CR.CPXXgetbasednorms(env, lp, cstat, rstat, dnorm)
    check_status(env, status)
    return (LAU.array_to_list(cstat, numcols),
            LAU.array_to_list(rstat, numrows),
            LAU.array_to_list(dnorm, numrows))


def getpsbcnt(env, lp):
    return CR.CPXXgetpsbcnt(env, lp)


def getdsbcnt(env, lp):
    return CR.CPXXgetdsbcnt(env, lp)


def getdblquality(env, lp, what):
    quality = CR.doublePtr()
    status = CR.CPXXgetdblquality(env, lp, quality, what)
    check_status(env, status)
    return quality.value()


def getintquality(env, lp, what):
    quality = CR.intPtr()
    status = CR.CPXXgetintquality(env, lp, quality, what)
    check_status(env, status)
    return quality.value()


# Sensitivity Analysis Results

def boundsa_lower(env, lp, begin, end):
    listlen = _rangelen(begin, end)
    lblower = _safeDoubleArray(listlen)
    lbupper = _safeDoubleArray(listlen)
    ublower = LAU.double_list_to_array([])
    ubupper = LAU.double_list_to_array([])
    status = CR.CPXXboundsa(env, lp, begin, end, lblower, lbupper,
                            ublower, ubupper)
    check_status(env, status)
    return (LAU.array_to_list(lblower, listlen),
            LAU.array_to_list(lbupper, listlen))


def boundsa_upper(env, lp, begin, end):
    listlen = _rangelen(begin, end)
    lblower = LAU.double_list_to_array([])
    lbupper = LAU.double_list_to_array([])
    ublower = _safeDoubleArray(listlen)
    ubupper = _safeDoubleArray(listlen)
    status = CR.CPXXboundsa(env, lp, begin, end, lblower, lbupper,
                            ublower, ubupper)
    check_status(env, status)
    return (LAU.array_to_list(ublower, listlen),
            LAU.array_to_list(ubupper, listlen))


def boundsa(env, lp, begin, end):
    listlen = _rangelen(begin, end)
    lblower = _safeDoubleArray(listlen)
    lbupper = _safeDoubleArray(listlen)
    ublower = _safeDoubleArray(listlen)
    ubupper = _safeDoubleArray(listlen)
    status = CR.CPXXboundsa(env, lp, begin, end, lblower, lbupper,
                            ublower, ubupper)
    check_status(env, status)
    return (LAU.array_to_list(lblower, listlen),
            LAU.array_to_list(lbupper, listlen),
            LAU.array_to_list(ublower, listlen),
            LAU.array_to_list(ubupper, listlen))


def objsa(env, lp, begin, end):
    listlen = _rangelen(begin, end)
    lower = _safeDoubleArray(listlen)
    upper = _safeDoubleArray(listlen)
    status = CR.CPXXobjsa(env, lp, begin, end, lower, upper)
    check_status(env, status)
    return (LAU.array_to_list(lower, listlen),
            LAU.array_to_list(upper, listlen))


def rhssa(env, lp, begin, end):
    listlen = _rangelen(begin, end)
    lower = _safeDoubleArray(listlen)
    upper = _safeDoubleArray(listlen)
    status = CR.CPXXrhssa(env, lp, begin, end, lower, upper)
    check_status(env, status)
    return (LAU.array_to_list(lower, listlen),
            LAU.array_to_list(upper, listlen))


# Conflicts

def refinemipstartconflictext(env, lp, mipstartindex, grppref, grpbeg,
                              grpind, grptype):
    grpcnt = len(grppref)
    concnt = len(grpind)
    with SigIntHandler(), \
            LAU.double_c_array(grppref) as c_grppref, \
            LAU.int_c_array(grpbeg) as c_grpbeg, \
            LAU.int_c_array(grpind) as c_grpind:
        status = CR.CPXXrefinemipstartconflictext(
            env, lp, mipstartindex, grpcnt, concnt,
            c_grppref, c_grpbeg, c_grpind, grptype)
    check_status(env, status)


def refineconflictext(env, lp, grppref, grpbeg, grpind, grptype):
    grpcnt = len(grppref)
    concnt = len(grpind)
    with SigIntHandler(), \
            LAU.double_c_array(grppref) as c_grppref, \
            LAU.int_c_array(grpbeg) as c_grpbeg, \
            LAU.int_c_array(grpind) as c_grpind:
        status = CR.CPXXrefineconflictext(
            env, lp, grpcnt, concnt,
            c_grppref, c_grpbeg, c_grpind, grptype)
    check_status(env, status)


def getconflictext(env, lp, begin, end):
    grpstatlen = _rangelen(begin, end)
    grpstat = _safeIntArray(grpstatlen)
    status = CR.CPXXgetconflictext(env, lp, grpstat, begin, end)
    check_status(env, status)
    return LAU.array_to_list(grpstat, grpstatlen)


def clpwrite(env, lp, filename, enc=default_encoding):
    status = CR.CPXXclpwrite(env, lp, cpx_decode_noop3(filename, enc))
    check_status(env, status)

# Problem Modification Routines

# File Reading Routines

# File Writing Routines


def solwrite(env, lp, filename, enc=default_encoding):
    status = CR.CPXXsolwrite(env, lp, cpx_decode_noop3(filename, enc))
    check_status(env, status)

# Message Handling Routines

# Advanced LP Routines


def binvcol(env, lp, j):
    xlen = CR.CPXXgetnumrows(env, lp)
    x = _safeDoubleArray(xlen)
    status = CR.CPXXbinvcol(env, lp, j, x)
    check_status(env, status)
    return LAU.array_to_list(x, xlen)


def binvrow(env, lp, i):
    ylen = CR.CPXXgetnumrows(env, lp)
    y = _safeDoubleArray(ylen)
    status = CR.CPXXbinvrow(env, lp, i, y)
    check_status(env, status)
    return LAU.array_to_list(y, ylen)


def binvacol(env, lp, j):
    xlen = CR.CPXXgetnumrows(env, lp)
    x = _safeDoubleArray(xlen)
    status = CR.CPXXbinvacol(env, lp, j, x)
    check_status(env, status)
    return LAU.array_to_list(x, xlen)


def binvarow(env, lp, i):
    zlen = CR.CPXXgetnumcols(env, lp)
    z = _safeDoubleArray(zlen)
    status = CR.CPXXbinvarow(env, lp, i, z)
    check_status(env, status)
    return LAU.array_to_list(z, zlen)


def ftran(env, lp, x):
    x_array = LAU.double_list_to_array(x)
    status = CR.CPXXftran(env, lp, x_array)
    check_status(env, status)
    return LAU.array_to_list(x_array, len(x))


def btran(env, lp, y):
    y_array = LAU.double_list_to_array(y)
    status = CR.CPXXbtran(env, lp, y_array)
    check_status(env, status)
    return LAU.array_to_list(y_array, len(y))


# Advanced Solution functions

def getgrad(env, lp, j):
    numrows = CR.CPXXgetnumrows(env, lp)
    head = _safeIntArray(numrows)
    y = _safeDoubleArray(numrows)
    status = CR.CPXXgetgrad(env, lp, j, head, y)
    check_status(env, status)
    return (LAU.array_to_list(head, numrows),
            LAU.array_to_list(y, numrows))


def slackfromx(env, lp, x):
    numrows = CR.CPXXgetnumrows(env, lp)
    slack = _safeDoubleArray(numrows)
    status = CR.CPXXslackfromx(env, lp, LAU.double_list_to_array(x), slack)
    check_status(env, status)
    return (LAU.array_to_list(slack, numrows))


def qconstrslackfromx(env, lp, x):
    numqcon = CR.CPXXgetnumqconstrs(env, lp)
    slack = _safeDoubleArray(numqcon)
    status = CR.CPXXqconstrslackfromx(env, lp,
                                      LAU.double_list_to_array(x), slack)
    check_status(env, status)
    return (LAU.array_to_list(slack, numqcon))


def djfrompi(env, lp, pi):
    numcols = CR.CPXXgetnumcols(env, lp)
    dj = _safeDoubleArray(numcols)
    status = CR.CPXXdjfrompi(env, lp, LAU.double_list_to_array(pi), dj)
    check_status(env, status)
    return (LAU.array_to_list(dj, numcols))


def qpdjfrompi(env, lp, pi, x):
    numcols = CR.CPXXgetnumcols(env, lp)
    dj = _safeDoubleArray(numcols)
    status = CR.CPXXqpdjfrompi(env, lp, LAU.double_list_to_array(pi),
                               LAU.double_list_to_array(x), dj)
    check_status(env, status)
    return (LAU.array_to_list(dj, numcols))


def mdleave(env, lp, goodlist):
    goodlen = len(goodlist)
    downratio = _safeDoubleArray(goodlen)
    upratio = _safeDoubleArray(goodlen)
    status = CR.CPXXmdleave(env, lp, LAU.int_list_to_array(goodlist),
                            goodlen, downratio, upratio)
    check_status(env, status)
    return (LAU.array_to_list(downratio, goodlen),
            LAU.array_to_list(upratio, goodlen))


def qpindefcertificate(env, lp):
    certlen = CR.CPXXgetnumquad(env, lp)
    cert = _safeDoubleArray(certlen)
    status = CR.CPXXqpindefcertificate(env, lp, cert)
    check_status(env, status)
    return LAU.array_to_list(cert, certlen)


def dualfarkas(env, lp):
    ylen = CR.CPXXgetnumrows(env, lp)
    y = _safeDoubleArray(ylen)
    proof = CR.doublePtr()
    status = CR.CPXXdualfarkas(env, lp, y, proof)
    check_status(env, status)
    return (LAU.array_to_list(y, ylen), proof.value())


def getijdiv(env, lp):
    idiv = CR.intPtr()
    jdiv = CR.intPtr()
    status = CR.CPXXgetijdiv(env, lp, idiv, jdiv)
    check_status(env, status)
    if idiv.value() != -1:
        return idiv.value() + getnumcols(env, lp)
    elif jdiv.value() != -1:
        return jdiv.value()
    else:  # problem is not diverging
        return -1


def getray(env, lp):
    zlen = CR.CPXXgetnumcols(env, lp)
    z = _safeDoubleArray(zlen)
    status = CR.CPXXgetray(env, lp, z)
    check_status(env, status)
    return LAU.array_to_list(z, zlen)


# Advanced Presolve Routines

def presolve(env, lp, method):
    status = CR.CPXXpresolve(env, lp, method)
    check_status(env, status)


def freepresolve(env, lp):
    status = CR.CPXXfreepresolve(env, lp)
    check_status(env, status)


def crushx(env, lp, x):
    redlp = CR.CPXLPptrPtr()
    status = CR.CPXXgetredlp(env, lp, redlp)
    check_status(env, status)
    if redlp.value() is None:
        raise CplexError("No presolved problem found")
    numcols = CR.CPXXgetnumcols(env, redlp.value())
    prex = _safeDoubleArray(numcols)
    status = CR.CPXXcrushx(env, lp, LAU.double_list_to_array(x), prex)
    check_status(env, status)
    return LAU.array_to_list(prex, numcols)


def uncrushx(env, lp, prex):
    numcols = CR.CPXXgetnumcols(env, lp)
    x = _safeDoubleArray(numcols)
    status = CR.CPXXuncrushx(env, lp, x, LAU.double_list_to_array(prex))
    check_status(env, status)
    return LAU.array_to_list(x, numcols)


def crushpi(env, lp, pi):
    redlp = CR.CPXLPptrPtr()
    status = CR.CPXXgetredlp(env, lp, redlp)
    check_status(env, status)
    if redlp.value() is None:
        raise CplexError("No presolved problem found")
    numrows = CR.CPXXgetnumrows(env, redlp.value())
    prepi = _safeDoubleArray(numrows)
    status = CR.CPXXcrushpi(env, lp, LAU.double_list_to_array(pi), prepi)
    check_status(env, status)
    return LAU.array_to_list(prepi, numrows)


def uncrushpi(env, lp, prepi):
    numrows = CR.CPXXgetnumrows(env, lp)
    pi = _safeDoubleArray(numrows)
    status = CR.CPXXuncrushpi(env, lp, pi, LAU.double_list_to_array(prepi))
    check_status(env, status)
    return LAU.array_to_list(pi, numrows)


def crushform(env, lp, ind, val):
    plen = CR.intPtr()
    poffset = CR.doublePtr()
    redlp = CR.CPXLPptrPtr()
    status = CR.CPXXgetredlp(env, lp, redlp)
    check_status(env, status)
    if redlp.value() is None:
        raise CplexError("No presolved problem found")
    numcols = CR.CPXXgetnumcols(env, redlp.value())
    pind = _safeIntArray(numcols)
    pval = _safeDoubleArray(numcols)
    status = CR.CPXXcrushform(env, lp, len(ind),
                              LAU.int_list_to_array(ind),
                              LAU.double_list_to_array(val),
                              plen, poffset, pind, pval)
    check_status(env, status)
    return (poffset.value(), LAU.array_to_list(pind, plen.value()),
            LAU.array_to_list(pval, plen.value()))


def uncrushform(env, lp, pind, pval):
    length = CR.intPtr()
    offset = CR.doublePtr()
    maxlen = CR.CPXXgetnumcols(env, lp) + CR.CPXXgetnumrows(env, lp)
    ind = _safeIntArray(maxlen)
    val = _safeDoubleArray(maxlen)
    status = CR.CPXXuncrushform(env, lp, len(pind),
                                LAU.int_list_to_array(pind),
                                LAU.double_list_to_array(pval),
                                length, offset, ind, val)
    check_status(env, status)
    return (offset.value(), LAU.array_to_list(ind, length.value()),
            LAU.array_to_list(val, length.value()))


def getprestat_status(env, lp):
    redlp = CR.CPXLPptrPtr()
    status = CR.CPXXgetredlp(env, lp, redlp)
    check_status(env, status)
    if redlp.value() is None:
        raise CplexError("No presolved problem found")
    prestat = CR.intPtr()
    pcstat = LAU.int_list_to_array([])
    prstat = LAU.int_list_to_array([])
    ocstat = LAU.int_list_to_array([])
    orstat = LAU.int_list_to_array([])
    status = CR.CPXXgetprestat(env, lp, prestat, pcstat, prstat,
                               ocstat, orstat)
    check_status(env, status)
    return prestat.value()


def getprestat_r(env, lp):
    redlp = CR.CPXLPptrPtr()
    status = CR.CPXXgetredlp(env, lp, redlp)
    check_status(env, status)
    if redlp.value() is None:
        raise CplexError("No presolved problem found")
    nrows = CR.CPXXgetnumrows(env, lp)
    prestat = CR.intPtr()
    pcstat = LAU.int_list_to_array([])
    prstat = _safeIntArray(nrows)
    ocstat = LAU.int_list_to_array([])
    orstat = LAU.int_list_to_array([])
    status = CR.CPXXgetprestat(env, lp, prestat, pcstat, prstat,
                               ocstat, orstat)
    check_status(env, status)
    return LAU.array_to_list(prstat, nrows)


def getprestat_c(env, lp):
    redlp = CR.CPXLPptrPtr()
    status = CR.CPXXgetredlp(env, lp, redlp)
    check_status(env, status)
    if redlp.value() is None:
        raise CplexError("No presolved problem found")
    ncols = CR.CPXXgetnumcols(env, lp)
    prestat = CR.intPtr()
    pcstat = _safeIntArray(ncols)
    prstat = LAU.int_list_to_array([])
    ocstat = LAU.int_list_to_array([])
    orstat = LAU.int_list_to_array([])
    status = CR.CPXXgetprestat(env, lp, prestat, pcstat, prstat,
                               ocstat, orstat)
    check_status(env, status)
    return LAU.array_to_list(pcstat, ncols)


def getprestat_or(env, lp):
    redlp = CR.CPXLPptrPtr()
    status = CR.CPXXgetredlp(env, lp, redlp)
    check_status(env, status)
    if redlp.value() is None:
        raise CplexError("No presolved problem found")
    nprows = CR.CPXXgetnumrows(env, redlp.value())
    prestat = CR.intPtr()
    pcstat = LAU.int_list_to_array([])
    prstat = LAU.int_list_to_array([])
    ocstat = LAU.int_list_to_array([])
    orstat = _safeIntArray(nprows)
    status = CR.CPXXgetprestat(env, lp, prestat, pcstat, prstat,
                               ocstat, orstat)
    check_status(env, status)
    return LAU.array_to_list(orstat, nprows)


def getprestat_oc(env, lp):
    redlp = CR.CPXLPptrPtr()
    status = CR.CPXXgetredlp(env, lp, redlp)
    check_status(env, status)
    if redlp.value() is None:
        raise CplexError("No presolved problem found")
    npcols = CR.CPXXgetnumcols(env, redlp.value())
    prestat = CR.intPtr()
    pcstat = LAU.int_list_to_array([])
    prstat = LAU.int_list_to_array([])
    ocstat = _safeIntArray(npcols)
    orstat = LAU.int_list_to_array([])
    status = CR.CPXXgetprestat(env, lp, prestat, pcstat, prstat,
                               ocstat, orstat)
    check_status(env, status)
    return LAU.array_to_list(ocstat, npcols)


def prechgobj(env, lp, ind, val):
    status = CR.CPXXprechgobj(env, lp, len(ind),
                              LAU.int_list_to_array(ind),
                              LAU.double_list_to_array(val))
    check_status(env, status)


def preaddrows(env, lp, rhs, sense, rmatbeg, rmatind, rmatval, names,
               enc=default_encoding):
    status = CR.CPXXpreaddrows(env, lp, len(rmatbeg), len(rmatind),
                               LAU.double_list_to_array(rhs),
                               cpx_decode(sense, enc),
                               LAU.int_list_to_array(rmatbeg),
                               LAU.int_list_to_array(rmatind),
                               LAU.double_list_to_array(rmatval),
                               [cpx_decode(x, enc) for x in names])
    check_status(env, status)

########################################################################
# MIP Starts API
########################################################################


def getnummipstarts(env, lp):
    return CR.CPXXgetnummipstarts(env, lp)


def chgmipstarts(env, lp, mipstartindices, beg, varindices, values,
                 effortlevel):
    with LAU.int_c_array(mipstartindices) as c_mipstartindices, \
            LAU.int_c_array(beg) as c_beg, \
            LAU.int_c_array(varindices) as c_varindices, \
            LAU.double_c_array(values) as c_values, \
            LAU.int_c_array(effortlevel) as c_effortlevel:
        status = CR.CPXXchgmipstarts(env, lp,
                                     len(mipstartindices),
                                     c_mipstartindices,
                                     len(varindices),
                                     c_beg,
                                     c_varindices,
                                     c_values,
                                     c_effortlevel)
    check_status(env, status)


def addmipstarts(env, lp, beg, varindices, values, effortlevel,
                 mipstartname, enc=default_encoding):
    with LAU.int_c_array(beg) as c_beg, \
            LAU.int_c_array(varindices) as c_varindices, \
            LAU.double_c_array(values) as c_values, \
            LAU.int_c_array(effortlevel) as c_effortlevel:
        status = CR.CPXXaddmipstarts(
            env, lp, len(beg), len(varindices),
            c_beg, c_varindices, c_values, c_effortlevel,
            [cpx_decode(x, enc) for x in mipstartname])
    check_status(env, status)


def delmipstarts(env, lp, begin, end):
    delfn = CR.CPXXdelmipstarts
    _delbyrange(delfn, env, lp, begin, end)


def getmipstarts_size(env, lp, begin, end):
    beglen = _rangelen(begin, end)
    beg = LAU.int_list_to_array([])
    effortlevel = _safeIntArray(beglen)
    nzcnt = CR.intPtr()
    surplus = CR.intPtr()
    varindices = LAU.int_list_to_array([])
    values = LAU.double_list_to_array([])
    startspace = 0
    status = CR.CPXXgetmipstarts(env, lp, nzcnt, beg, varindices, values,
                                 effortlevel, startspace, surplus, begin,
                                 end)
    if status != CR.CPXERR_NEGATIVE_SURPLUS:
        check_status(env, status)
    return -surplus.value()


def getmipstarts_effort(env, lp, begin, end):
    beglen = _rangelen(begin, end)
    beg = LAU.int_list_to_array([])
    effortlevel = _safeIntArray(beglen)
    nzcnt = CR.intPtr()
    surplus = CR.intPtr()
    varindices = LAU.int_list_to_array([])
    values = LAU.double_list_to_array([])
    startspace = 0
    status = CR.CPXXgetmipstarts(env, lp, nzcnt, beg, varindices, values,
                                 effortlevel, startspace, surplus, begin,
                                 end)
    if status != CR.CPXERR_NEGATIVE_SURPLUS:
        check_status(env, status)
    if surplus.value() == 0:
        return ([0] * _rangelen(begin, end), [], [],
                [0] * _rangelen(begin, end))
    startspace = -surplus.value()
    beg = _safeIntArray(beglen)
    varindices = _safeIntArray(startspace)
    values = _safeDoubleArray(startspace)
    status = CR.CPXXgetmipstarts(env, lp, nzcnt, beg, varindices, values,
                                 effortlevel, startspace, surplus, begin,
                                 end)
    check_status(env, status)
    return LAU.array_to_list(effortlevel, beglen)


def getmipstarts(env, lp, begin, end):
    beglen = _rangelen(begin, end)
    beg = LAU.int_list_to_array([])
    effortlevel = _safeIntArray(beglen)
    nzcnt = CR.intPtr()
    surplus = CR.intPtr()
    varindices = LAU.int_list_to_array([])
    values = LAU.double_list_to_array([])
    startspace = 0
    status = CR.CPXXgetmipstarts(env, lp, nzcnt, beg, varindices, values,
                                 effortlevel, startspace, surplus, begin,
                                 end)
    if status != CR.CPXERR_NEGATIVE_SURPLUS:
        check_status(env, status)
    if surplus.value() == 0:
        return ([0] * _rangelen(begin, end), [], [],
                [0] * _rangelen(begin, end))
    beg = _safeIntArray(beglen)
    startspace = -surplus.value()
    varindices = _safeIntArray(startspace)
    values = _safeDoubleArray(startspace)
    status = CR.CPXXgetmipstarts(env, lp, nzcnt, beg, varindices, values,
                                 effortlevel, startspace, surplus, begin,
                                 end)
    check_status(env, status)
    return (LAU.array_to_list(beg, beglen),
            LAU.array_to_list(varindices, startspace),
            LAU.array_to_list(values, startspace),
            LAU.array_to_list(effortlevel, beglen))


def getmipstartname(env, lp, begin, end, enc=default_encoding):
    namefn = CR.CPXXgetmipstartname
    return _getnamebyrange(env, lp, begin, end, enc, namefn)


def getmipstartindex(env, lp, mipstartname, enc=default_encoding):
    index = CR.intPtr()
    status = CR.CPXXgetmipstartindex(env, lp,
                                     cpx_decode_noop3(mipstartname, enc),
                                     index)
    check_status(env, status)
    return index.value()


def readcopymipstarts(env, lp, filename, enc=default_encoding):
    status = CR.CPXXreadcopymipstarts(env, lp,
                                      cpx_decode_noop3(filename, enc))
    check_status(env, status)


def writemipstarts(env, lp, filename, begin, end, enc=default_encoding):
    status = CR.CPXXwritemipstarts(env, lp,
                                   cpx_decode_noop3(filename, enc),
                                   begin, end)
    check_status(env, status)

# Optimizing Problems

# Progress


def getitcnt(env, lp):
    return CR.CPXXgetitcnt(env, lp)


def getphase1cnt(env, lp):
    return CR.CPXXgetphase1cnt(env, lp)


def getsiftitcnt(env, lp):
    return CR.CPXXgetsiftitcnt(env, lp)


def getsiftphase1cnt(env, lp):
    return CR.CPXXgetsiftphase1cnt(env, lp)


def getbaritcnt(env, lp):
    return CR.CPXXgetbaritcnt(env, lp)


def getcrossppushcnt(env, lp):
    return CR.CPXXgetcrossppushcnt(env, lp)


def getcrosspexchcnt(env, lp):
    return CR.CPXXgetcrosspexchcnt(env, lp)


def getcrossdpushcnt(env, lp):
    return CR.CPXXgetcrossdpushcnt(env, lp)


def getcrossdexchcnt(env, lp):
    return CR.CPXXgetcrossdexchcnt(env, lp)


def getmipitcnt(env, lp):
    return CR.CPXXgetmipitcnt(env, lp)


def getnodecnt(env, lp):
    return CR.CPXXgetnodecnt(env, lp)


def getnodeleftcnt(env, lp):
    return CR.CPXXgetnodeleftcnt(env, lp)


# MIP Only solution interface

def getbestobjval(env, lp):
    objval = CR.doublePtr()
    status = CR.CPXXgetbestobjval(env, lp, objval)
    check_status(env, status)
    return objval.value()


def getcutoff(env, lp):
    cutoff = CR.doublePtr()
    status = CR.CPXXgetcutoff(env, lp, cutoff)
    check_status(env, status)
    return cutoff.value()


def getmiprelgap(env, lp):
    relgap = CR.doublePtr()
    status = CR.CPXXgetmiprelgap(env, lp, relgap)
    check_status(env, status)
    return relgap.value()


def getnumcuts(env, lp, cuttype):
    num = CR.intPtr()
    status = CR.CPXXgetnumcuts(env, lp, cuttype, num)
    check_status(env, status)
    return num.value()


def getnodeint(env, lp):
    return CR.CPXXgetnodeint(env, lp)


def getsubstat(env, lp):
    return CR.CPXXgetsubstat(env, lp)

# for callback query methods


def get_wherefrom(cbstruct):
    return CR.get_wherefrom(cbstruct)


cpxlong_callback_node_info = [
    CPX_CALLBACK_INFO_NODE_SEQNUM_LONG,
    CPX_CALLBACK_INFO_NODE_NODENUM_LONG,
    CPX_CALLBACK_INFO_NODE_DEPTH_LONG,
]

int_callback_node_info = [
    CPX_CALLBACK_INFO_NODE_NIINF,
    CPX_CALLBACK_INFO_NODE_VAR,
    CPX_CALLBACK_INFO_NODE_SOS,
    CPX_CALLBACK_INFO_LAZY_SOURCE,
]

double_callback_node_info = [
    CPX_CALLBACK_INFO_NODE_SIINF,
    CPX_CALLBACK_INFO_NODE_ESTIMATE,
    CPX_CALLBACK_INFO_NODE_OBJVAL,
]

# NB: CPX_CALLBACK_INFO_NODE_TYPE not used in the Python API.

user_handle_callback_node_info = [
    CPX_CALLBACK_INFO_NODE_USERHANDLE
]


def gettime(env):
    time = CR.doublePtr()
    status = CR.CPXXgettime(env, time)
    check_status(env, status)
    return time.value()


def getdettime(env):
    time = CR.doublePtr()
    status = CR.CPXXgetdettime(env, time)
    check_status(env, status)
    return time.value()


def getcallbackincumbent(cbstruct, begin, end):
    xlen = _rangelen(begin, end)
    x = _safeDoubleArray(xlen)
    status = CR.CPXXgetcallbackincumbent(cbstruct, x, begin, end)
    check_status(None, status)
    return LAU.array_to_list(x, xlen)


def getcallbackpseudocosts(cbstruct, begin, end):
    pclen = _rangelen(begin, end)
    uppc = _safeDoubleArray(pclen)
    dnpc = _safeDoubleArray(pclen)
    status = CR.CPXXgetcallbackpseudocosts(cbstruct, uppc, dnpc, begin, end)
    check_status(None, status)
    return (LAU.array_to_list(uppc, pclen),
            LAU.array_to_list(dnpc, pclen))


def getcallbacknodeintfeas(cbstruct, begin, end):
    feaslen = _rangelen(begin, end)
    feas = _safeIntArray(feaslen)
    status = CR.CPXXgetcallbacknodeintfeas(cbstruct, feas, begin, end)
    check_status(None, status)
    return LAU.array_to_list(feas, feaslen)


def getcallbacknodelb(cbstruct, begin, end):
    lblen = _rangelen(begin, end)
    lb = _safeDoubleArray(lblen)
    status = CR.CPXXgetcallbacknodelb(cbstruct, lb, begin, end)
    check_status(None, status)
    return LAU.array_to_list(lb, lblen)


def getcallbacknodeub(cbstruct, begin, end):
    ublen = _rangelen(begin, end)
    ub = _safeDoubleArray(ublen)
    status = CR.CPXXgetcallbacknodeub(cbstruct, ub, begin, end)
    check_status(None, status)
    return LAU.array_to_list(ub, ublen)


def getcallbacknodeobjval(cbstruct):
    x = CR.doublePtr()
    status = CR.CPXXgetcallbacknodeobjval(cbstruct, x)
    check_status(None, status)
    return x.value()


def getcallbacknodex(cbstruct, begin, end):
    xlen = _rangelen(begin, end)
    x = _safeDoubleArray(xlen)
    status = CR.CPXXgetcallbacknodex(cbstruct, x, begin, end)
    check_status(None, status)
    return LAU.array_to_list(x, xlen)


def getcallbacknodeinfo(cbstruct, node, which):
    if which in int_callback_node_info:
        data = CR.intPtr()
    elif which in cpxlong_callback_node_info:
        data = CR.cpxlongPtr()
    elif which in double_callback_node_info:
        data = CR.doublePtr()
    elif which in user_handle_callback_node_info:
        data = []
    else:
        raise CplexError(
            "invalid value for which in _internal._procedural.getcallbacknodeinfo")
    status = CR.CPXXgetcallbacknodeinfo(cbstruct, [node, which, data])
    check_status(None, status)
    if which in int_callback_node_info or which in double_callback_node_info or which in cpxlong_callback_node_info:
        return data.value()
    elif which in user_handle_callback_node_info:
        return data[0]


def callbacksetuserhandle(cbstruct, userhandle):
    data = []
    status = CR.CPXXcallbacksetuserhandle(cbstruct, [userhandle, data])
    check_status(None, status)
    return data[0]


def callbacksetnodeuserhandle(cbstruct, nodeindex, userhandle):
    data = []
    status = CR.CPXXcallbacksetnodeuserhandle(
        cbstruct, [nodeindex, userhandle, data])
    check_status(None, status)
    return data[0]


def getcallbackseqinfo(cbstruct, node, which):
    if which in int_callback_node_info:
        data = CR.intPtr()
    elif which in cpxlong_callback_node_info:
        data = CR.cpxlongPtr()
    elif which in double_callback_node_info:
        data = CR.doublePtr()
    elif which in user_handle_callback_node_info:
        data = []
    else:
        raise CplexError(
            "invalid value for which in _internal._procedural.getcallbackseqinfo")
    status = CR.CPXXgetcallbackseqinfo(cbstruct, [node, which, data])
    check_status(None, status)
    if which in int_callback_node_info or which in double_callback_node_info or which in cpxlong_callback_node_info:
        return data.value()
    elif which in user_handle_callback_node_info:
        return data[0]


int_sos_info = [
    CPX_CALLBACK_INFO_SOS_NUM,
    CPX_CALLBACK_INFO_SOS_SIZE,
    CPX_CALLBACK_INFO_SOS_IS_FEASIBLE,
    CPX_CALLBACK_INFO_SOS_MEMBER_INDEX,
]

double_sos_info = [
    CPX_CALLBACK_INFO_SOS_MEMBER_REFVAL,
]

# NB: CPX_CALLBACK_INFO_SOS_TYPE not used in the Python API.


def getcallbacksosinfo(cbstruct, sosindex, member, which):
    if which in int_sos_info:
        data = CR.intPtr()
    elif which in double_sos_info:
        data = CR.doublePtr()
    else:
        raise CplexError(
            "invalid value for which in _internal._procedural.getcallbacksosinfo")
    status = CR.CPXXgetcallbacksosinfo(cbstruct, sosindex, member, which, data)
    check_status(None, status)
    return data.value()


def cutcallbackadd(cbstruct, rhs, sense, ind, val, purgeable):
    status = CR.CPXXcutcallbackadd(cbstruct, len(ind), rhs,
                                   cpx_decode(sense, default_encoding),
                                   LAU.int_list_to_array(ind),
                                   LAU.double_list_to_array(val),
                                   purgeable)
    check_status(None, status)


def cutcallbackaddlocal(cbstruct, rhs, sense, ind, val):
    status = CR.CPXXcutcallbackaddlocal(cbstruct, len(ind), rhs,
                                        cpx_decode(sense, default_encoding),
                                        LAU.int_list_to_array(ind),
                                        LAU.double_list_to_array(val))
    check_status(None, status)


def branchcallbackbranchgeneral(cbstruct, ind, lu, bd, rhs, sense, matbeg,
                                matind, matval, nodeest, userhandle):
    seqnum = CR.cpxlongPtr()
    status = CR.CPXXbranchcallbackbranchgeneral(
        cbstruct, len(ind),
        LAU.int_list_to_array(ind),
        lu,
        LAU.double_list_to_array(bd),
        len(matbeg), len(matind),
        LAU.double_list_to_array(rhs),
        cpx_decode(sense, default_encoding),
        LAU.int_list_to_array(matbeg),
        LAU.int_list_to_array(matind),
        LAU.double_list_to_array(matval),
        nodeest, userhandle, seqnum)
    check_status(None, status)
    return seqnum.value()


def branchcallbackbranchasCPLEX(cbstruct, n, userhandle):
    seqnum = CR.cpxlongPtr()
    status = CR.CPXXbranchcallbackbranchasCPLEX(
        cbstruct, n, userhandle, seqnum)
    check_status(None, status)
    return seqnum.value()


def setpydel(env):
    status = CR.setpydel(env)
    check_status(env, status)


def delpydel(env):
    status = CR.delpydel(env)
    check_status(env, status)

# Solution pool


def addsolnpooldivfilter(env, lp, lb, ub, ind, wts, ref, name,
                         enc=default_encoding):
    status = CR.CPXXaddsolnpooldivfilter(env, lp, lb, ub, len(ind),
                                         LAU.int_list_to_array(ind),
                                         LAU.double_list_to_array(wts),
                                         LAU.double_list_to_array(ref),
                                         cpx_decode_noop3(name, enc))
    check_status(env, status)


def addsolnpoolrngfilter(env, lp, lb, ub, ind, val, name,
                         enc=default_encoding):
    status = CR.CPXXaddsolnpoolrngfilter(env, lp, lb, ub, len(ind),
                                         LAU.int_list_to_array(ind),
                                         LAU.double_list_to_array(val),
                                         cpx_decode_noop3(name, enc))
    check_status(env, status)


def getsolnpooldivfilter_constant(env, lp, which):
    lb = CR.doublePtr()
    ub = CR.doublePtr()
    nzcnt = CR.intPtr()
    space = 0
    surplus = CR.intPtr()
    ind = LAU.int_list_to_array([])
    wts = LAU.double_list_to_array([])
    ref = LAU.double_list_to_array([])
    status = CR.CPXXgetsolnpooldivfilter(env, lp, lb, ub, nzcnt, ind,
                                         wts, ref, space, surplus, which)
    if status != CR.CPXERR_NEGATIVE_SURPLUS:
        check_status(env, status)
    return (lb.value(), ub.value(), -surplus.value())


def getsolnpooldivfilter(env, lp, which):
    lb = CR.doublePtr()
    ub = CR.doublePtr()
    nzcnt = CR.intPtr()
    space = 0
    surplus = CR.intPtr()
    ind = LAU.int_list_to_array([])
    wts = LAU.double_list_to_array([])
    ref = LAU.double_list_to_array([])
    status = CR.CPXXgetsolnpooldivfilter(env, lp, lb, ub, nzcnt, ind,
                                         wts, ref, space, surplus, which)
    if status != CR.CPXERR_NEGATIVE_SURPLUS:
        check_status(env, status)
    space = -surplus.value()
    ind = _safeIntArray(space)
    wts = _safeDoubleArray(space)
    ref = _safeDoubleArray(space)
    status = CR.CPXXgetsolnpooldivfilter(env, lp, lb, ub, nzcnt, ind,
                                         wts, ref, space, surplus, which)
    check_status(env, status)
    return (lb.value(),
            ub.value(),
            LAU.array_to_list(ind, space),
            LAU.array_to_list(wts, space),
            LAU.array_to_list(ref, space))


def getsolnpoolrngfilter_constant(env, lp, which):
    lb = CR.doublePtr()
    ub = CR.doublePtr()
    nzcnt = CR.intPtr()
    space = 0
    surplus = CR.intPtr()
    ind = LAU.int_list_to_array([])
    val = LAU.double_list_to_array([])
    status = CR.CPXXgetsolnpoolrngfilter(env, lp, lb, ub, nzcnt, ind, val,
                                         space, surplus, which)
    if status != CR.CPXERR_NEGATIVE_SURPLUS:
        check_status(env, status)
    return (lb.value(), ub.value(), -surplus.value())


def getsolnpoolrngfilter(env, lp, which):
    lb = CR.doublePtr()
    ub = CR.doublePtr()
    nzcnt = CR.intPtr()
    space = 0
    surplus = CR.intPtr()
    ind = LAU.int_list_to_array([])
    val = LAU.double_list_to_array([])
    status = CR.CPXXgetsolnpoolrngfilter(env, lp, lb, ub, nzcnt, ind, val,
                                         space, surplus, which)
    if status != CR.CPXERR_NEGATIVE_SURPLUS:
        check_status(env, status)
    space = -surplus.value()
    ind = _safeIntArray(space)
    val = _safeDoubleArray(space)
    status = CR.CPXXgetsolnpoolrngfilter(env, lp, lb, ub, nzcnt, ind, val,
                                         space, surplus, which)
    check_status(env, status)
    return (lb.value(), ub.value(), LAU.array_to_list(ind, space),
            LAU.array_to_list(val, space))


def delsolnpoolfilters(env, lp, begin, end):
    delfn = CR.CPXXdelsolnpoolfilters
    _delbyrange(delfn, env, lp, begin, end)


def getsolnpoolfiltername(env, lp, which, enc=default_encoding):
    namefn = CR.CPXXgetsolnpoolfiltername
    return _getname(env, lp, which, enc, namefn, index_first=False)


def getsolnpoolnumfilters(env, lp):
    return CR.CPXXgetsolnpoolnumfilters(env, lp)


def fltwrite(env, lp, filename, enc=default_encoding):
    status = CR.CPXXfltwrite(env, lp, cpx_decode_noop3(filename, enc))
    check_status(env, status)


def readcopysolnpoolfilters(env, lp, filename, enc=default_encoding):
    status = CR.CPXXreadcopysolnpoolfilters(env, lp,
                                            cpx_decode_noop3(filename, enc))
    check_status(env, status)


def getsolnpoolfilterindex(env, lp, colname, enc=default_encoding):
    index = CR.intPtr()
    status = CR.CPXXgetsolnpoolfilterindex(env, lp,
                                           cpx_decode_noop3(colname, enc),
                                           index)
    check_status(env, status)
    return index.value()


def getsolnpoolfiltertype(env, lp, index):
    type_ = CR.intPtr()
    status = CR.CPXXgetsolnpoolfiltertype(env, lp, type_, index)
    check_status(env, status)
    return type_.value()


def delsolnpoolsolns(env, lp, begin, end):
    delfn = CR.CPXXdelsolnpoolsolns
    _delbyrange(delfn, env, lp, begin, end)


def getsolnpoolnumsolns(env, lp):
    return CR.CPXXgetsolnpoolnumsolns(env, lp)


def getsolnpoolnumreplaced(env, lp):
    return CR.CPXXgetsolnpoolnumreplaced(env, lp)


def getsolnpoolsolnindex(env, lp, colname, enc=default_encoding):
    index = CR.intPtr()
    status = CR.CPXXgetsolnpoolsolnindex(env, lp,
                                         cpx_decode_noop3(colname, enc),
                                         index)
    check_status(env, status)
    return index.value()


def getsolnpoolmeanobjval(env, lp):
    objval = CR.doublePtr()
    status = CR.CPXXgetsolnpoolmeanobjval(env, lp, objval)
    check_status(env, status)
    return objval.value()


def getsolnpoolsolnname(env, lp, which, enc=default_encoding):
    namefn = CR.CPXXgetsolnpoolsolnname
    return _getname(env, lp, which, enc, namefn, index_first=False)


def solwritesolnpool(env, lp, soln, filename, enc=default_encoding):
    status = CR.CPXXsolwritesolnpool(env, lp, soln,
                                     cpx_decode_noop3(filename, enc))
    check_status(env, status)


def solwritesolnpoolall(env, lp, filename, enc=default_encoding):
    status = CR.CPXXsolwritesolnpoolall(env, lp,
                                        cpx_decode_noop3(filename, enc))
    check_status(env, status)


def getsolnpoolobjval(env, lp, soln):
    obj = CR.doublePtr()
    status = CR.CPXXgetsolnpoolobjval(env, lp, soln, obj)
    check_status(env, status)
    return obj.value()


def getsolnpoolx(env, lp, soln, begin, end):
    xlen = _rangelen(begin, end)
    x = _safeDoubleArray(xlen)
    status = CR.CPXXgetsolnpoolx(env, lp, soln, x, begin, end)
    check_status(env, status)
    return LAU.array_to_list(x, xlen)


def getsolnpoolslack(env, lp, soln, begin, end):
    slacklen = _rangelen(begin, end)
    slack = _safeDoubleArray(slacklen)
    status = CR.CPXXgetsolnpoolslack(env, lp, soln, slack, begin, end)
    check_status(env, status)
    return LAU.array_to_list(slack, slacklen)


def getsolnpoolqconstrslack(env, lp, soln, begin, end):
    qlen = _rangelen(begin, end)
    q = _safeDoubleArray(qlen)
    status = CR.CPXXgetsolnpoolqconstrslack(env, lp, soln, q, begin, end)
    check_status(env, status)
    return LAU.array_to_list(q, qlen)


def getsolnpoolintquality(env, lp, soln, what):
    quality = CR.intPtr()
    status = CR.CPXXgetsolnpoolintquality(env, lp, soln, quality, what)
    check_status(env, status)
    return quality.value()


def getsolnpooldblquality(env, lp, soln, what):
    quality = CR.doublePtr()
    status = CR.CPXXgetsolnpooldblquality(env, lp, soln, quality, what)
    check_status(env, status)
    return quality.value()


# Initial data


def copystart(env, lp, cstat, rstat, cprim, rprim, cdual, rdual):
    status = CR.CPXXcopystart(env, lp,
                              LAU.int_list_to_array(cstat),
                              LAU.int_list_to_array(rstat),
                              LAU.double_list_to_array(cprim),
                              LAU.double_list_to_array(rprim),
                              LAU.double_list_to_array(cdual),
                              LAU.double_list_to_array(rdual))
    check_status(env, status)


def readcopybase(env, lp, filename, enc=default_encoding):
    status = CR.CPXXreadcopybase(env, lp, cpx_decode_noop3(filename, enc))
    check_status(env, status)


def getorder(env, lp):
    count = CR.intPtr()
    surplus = CR.intPtr()
    space = 0
    ind = LAU.int_list_to_array([])
    pri = LAU.int_list_to_array([])
    dir_ = LAU.int_list_to_array([])
    status = CR.CPXXgetorder(env, lp, count, ind, pri, dir_, space, surplus)
    if status != CR.CPXERR_NEGATIVE_SURPLUS:
        check_status(env, status)
    space = -surplus.value()
    ind = _safeIntArray(space)
    pri = _safeIntArray(space)
    dir_ = _safeIntArray(space)
    status = CR.CPXXgetorder(env, lp, count, ind, pri, dir_, space, surplus)
    check_status(env, status)
    return (LAU.array_to_list(ind, space), LAU.array_to_list(pri, space),
            LAU.array_to_list(dir_, space))


def copyorder(env, lp, indices, priority, direction):
    status = CR.CPXXcopyorder(env, lp, len(indices),
                              LAU.int_list_to_array(indices),
                              LAU.int_list_to_array(priority),
                              LAU.int_list_to_array(direction))
    check_status(env, status)


def readcopyorder(env, lp, filename, enc=default_encoding):
    status = CR.CPXXreadcopyorder(env, lp,
                                  cpx_decode_noop3(filename, enc))
    check_status(env, status)


def ordwrite(env, lp, filename, enc=default_encoding):
    status = CR.CPXXordwrite(env, lp, cpx_decode_noop3(filename, enc))
    check_status(env, status)


def readcopysol(env, lp, filename, enc=default_encoding):
    status = CR.CPXXreadcopysol(env, lp, cpx_decode_noop3(filename, enc))
    check_status(env, status)

# handle the lock for parallel callbacks


def initlock():
    return CR.init_callback_lock()


def finitlock(lock):
    CR.finit_callback_lock(lock)


# get problem statistics

def getprobstats(env, lp):
    rows_p = CR.intPtr()
    cols_p = CR.intPtr()
    objcnt_p = CR.intPtr()
    rhscnt_p = CR.intPtr()
    nzcnt_p = CR.intPtr()
    ecnt_p = CR.intPtr()
    gcnt_p = CR.intPtr()
    lcnt_p = CR.intPtr()
    rngcnt_p = CR.intPtr()
    ncnt_p = CR.intPtr()
    fcnt_p = CR.intPtr()
    xcnt_p = CR.intPtr()
    bcnt_p = CR.intPtr()
    ocnt_p = CR.intPtr()
    bicnt_p = CR.intPtr()
    icnt_p = CR.intPtr()
    scnt_p = CR.intPtr()
    sicnt_p = CR.intPtr()
    qpcnt_p = CR.intPtr()
    qpnzcnt_p = CR.intPtr()
    nqconstr_p = CR.intPtr()
    qrhscnt_p = CR.intPtr()
    qlcnt_p = CR.intPtr()
    qgcnt_p = CR.intPtr()
    quadnzcnt_p = CR.intPtr()
    linnzcnt_p = CR.intPtr()
    nindconstr_p = CR.intPtr()
    indrhscnt_p = CR.intPtr()
    indnzcnt_p = CR.intPtr()
    indcompcnt_p = CR.intPtr()
    indlcnt_p = CR.intPtr()
    indecnt_p = CR.intPtr()
    indgcnt_p = CR.intPtr()
    maxcoef_p = CR.doublePtr()
    mincoef_p = CR.doublePtr()
    minrhs_p = CR.doublePtr()
    maxrhs_p = CR.doublePtr()
    minrng_p = CR.doublePtr()
    maxrng_p = CR.doublePtr()
    minobj_p = CR.doublePtr()
    maxobj_p = CR.doublePtr()
    minlb_p = CR.doublePtr()
    maxub_p = CR.doublePtr()
    minqcoef_p = CR.doublePtr()
    maxqcoef_p = CR.doublePtr()
    minqcq_p = CR.doublePtr()
    maxqcq_p = CR.doublePtr()
    minqcl_p = CR.doublePtr()
    maxqcl_p = CR.doublePtr()
    minqcr_p = CR.doublePtr()
    maxqcr_p = CR.doublePtr()
    minind_p = CR.doublePtr()
    maxind_p = CR.doublePtr()
    minindrhs_p = CR.doublePtr()
    maxindrhs_p = CR.doublePtr()
    minlazy_p = CR.doublePtr()
    maxlazy_p = CR.doublePtr()
    minlazyrhs_p = CR.doublePtr()
    maxlazyrhs_p = CR.doublePtr()
    minucut_p = CR.doublePtr()
    maxucut_p = CR.doublePtr()
    minucutrhs_p = CR.doublePtr()
    maxucutrhs_p = CR.doublePtr()
    nsos_p = CR.intPtr()
    nsos1_p = CR.intPtr()
    sos1nmem_p = CR.intPtr()
    sos1type_p = CR.intPtr()
    nsos2_p = CR.intPtr()
    sos2nmem_p = CR.intPtr()
    sos2type_p = CR.intPtr()
    lazyrhscnt_p = CR.intPtr()
    lazygcnt_p = CR.intPtr()
    lazylcnt_p = CR.intPtr()
    lazyecnt_p = CR.intPtr()
    lazycnt_p = CR.intPtr()
    lazynzcnt_p = CR.intPtr()
    ucutrhscnt_p = CR.intPtr()
    ucutgcnt_p = CR.intPtr()
    ucutlcnt_p = CR.intPtr()
    ucutecnt_p = CR.intPtr()
    ucutcnt_p = CR.intPtr()
    ucutnzcnt_p = CR.intPtr()
    npwl_p = CR.intPtr()
    npwlbreaks_p = CR.intPtr()
    status = CR.CPXEgetprobstats(env, lp,
                                 rows_p,
                                 cols_p,
                                 objcnt_p,
                                 rhscnt_p,
                                 nzcnt_p,
                                 ecnt_p,
                                 gcnt_p,
                                 lcnt_p,
                                 rngcnt_p,
                                 ncnt_p,
                                 fcnt_p,
                                 xcnt_p,
                                 bcnt_p,
                                 ocnt_p,
                                 bicnt_p,
                                 icnt_p,
                                 scnt_p,
                                 sicnt_p,
                                 qpcnt_p,
                                 qpnzcnt_p,
                                 nqconstr_p,
                                 qrhscnt_p,
                                 qlcnt_p,
                                 qgcnt_p,
                                 quadnzcnt_p,
                                 linnzcnt_p,
                                 nindconstr_p,
                                 indrhscnt_p,
                                 indnzcnt_p,
                                 indcompcnt_p,
                                 indlcnt_p,
                                 indecnt_p,
                                 indgcnt_p,
                                 maxcoef_p,
                                 mincoef_p,
                                 minrhs_p,
                                 maxrhs_p,
                                 minrng_p,
                                 maxrng_p,
                                 minobj_p,
                                 maxobj_p,
                                 minlb_p,
                                 maxub_p,
                                 minqcoef_p,
                                 maxqcoef_p,
                                 minqcq_p,
                                 maxqcq_p,
                                 minqcl_p,
                                 maxqcl_p,
                                 minqcr_p,
                                 maxqcr_p,
                                 minind_p,
                                 maxind_p,
                                 minindrhs_p,
                                 maxindrhs_p,
                                 minlazy_p,
                                 maxlazy_p,
                                 minlazyrhs_p,
                                 maxlazyrhs_p,
                                 minucut_p,
                                 maxucut_p,
                                 minucutrhs_p,
                                 maxucutrhs_p,
                                 nsos_p,
                                 nsos1_p,
                                 sos1nmem_p,
                                 sos1type_p,
                                 nsos2_p,
                                 sos2nmem_p,
                                 sos2type_p,
                                 lazyrhscnt_p,
                                 lazygcnt_p,
                                 lazylcnt_p,
                                 lazyecnt_p,
                                 lazycnt_p,
                                 lazynzcnt_p,
                                 ucutrhscnt_p,
                                 ucutgcnt_p,
                                 ucutlcnt_p,
                                 ucutecnt_p,
                                 ucutcnt_p,
                                 ucutnzcnt_p,
                                 npwl_p,
                                 npwlbreaks_p)
    check_status(env, status)
    return [rows_p.value(),  # 0
            cols_p.value(),  # 1
            objcnt_p.value(),  # 2
            rhscnt_p.value(),  # 3
            nzcnt_p.value(),  # 4
            ecnt_p.value(),  # 5
            gcnt_p.value(),  # 6
            lcnt_p.value(),  # 7
            rngcnt_p.value(),  # 8
            ncnt_p.value(),  # 9
            fcnt_p.value(),  # 10
            xcnt_p.value(),  # 11
            bcnt_p.value(),  # 12
            ocnt_p.value(),  # 13
            bicnt_p.value(),  # 14
            icnt_p.value(),  # 15
            scnt_p.value(),  # 16
            sicnt_p.value(),  # 17
            qpcnt_p.value(),  # 18
            qpnzcnt_p.value(),  # 19
            nqconstr_p.value(),  # 20
            qrhscnt_p.value(),  # 21
            qlcnt_p.value(),  # 22
            qgcnt_p.value(),  # 23
            quadnzcnt_p.value(),  # 24
            linnzcnt_p.value(),  # 25
            nindconstr_p.value(),  # 26
            indrhscnt_p.value(),  # 27
            indnzcnt_p.value(),  # 28
            indcompcnt_p.value(),  # 29
            indlcnt_p.value(),  # 30
            indecnt_p.value(),  # 31
            indgcnt_p.value(),  # 32
            maxcoef_p.value(),  # 33
            mincoef_p.value(),  # 34
            minrhs_p.value(),  # 35
            maxrhs_p.value(),  # 36
            minrng_p.value(),  # 37
            maxrng_p.value(),  # 38
            minobj_p.value(),  # 39
            maxobj_p.value(),  # 40
            minlb_p.value(),  # 41
            maxub_p.value(),  # 42
            minqcoef_p.value(),  # 43
            maxqcoef_p.value(),  # 44
            minqcq_p.value(),  # 45
            maxqcq_p.value(),  # 46
            minqcl_p.value(),  # 47
            maxqcl_p.value(),  # 48
            minqcr_p.value(),  # 49
            maxqcr_p.value(),  # 50
            minind_p.value(),  # 51
            maxind_p.value(),  # 52
            minindrhs_p.value(),  # 53
            maxindrhs_p.value(),  # 54
            minlazy_p.value(),  # 55
            maxlazy_p.value(),  # 56
            minlazyrhs_p.value(),  # 57
            maxlazyrhs_p.value(),  # 58
            minucut_p.value(),  # 59
            maxucut_p.value(),  # 60
            minucutrhs_p.value(),  # 61
            maxucutrhs_p.value(),  # 62
            nsos_p.value(),  # 63
            nsos1_p.value(),  # 64
            sos1nmem_p.value(),  # 65
            sos1type_p.value(),  # 66
            nsos2_p.value(),  # 67
            sos2nmem_p.value(),  # 68
            sos2type_p.value(),  # 69
            lazyrhscnt_p.value(),  # 70
            lazygcnt_p.value(),  # 71
            lazylcnt_p.value(),  # 72
            lazyecnt_p.value(),  # 73
            lazycnt_p.value(),  # 74
            lazynzcnt_p.value(),  # 75
            ucutrhscnt_p.value(),  # 76
            ucutgcnt_p.value(),  # 77
            ucutlcnt_p.value(),  # 78
            ucutecnt_p.value(),  # 79
            ucutcnt_p.value(),  # 80
            ucutnzcnt_p.value(),  # 81
            npwl_p.value(),  # 82
            npwlbreaks_p.value(), ]  # 83

# get histogram of non-zero row/column counts


def gethist(env, lp, key):
    if key == 'r':
        space = CR.CPXXgetnumcols(env, lp) + 1
    else:
        key = 'c'
        space = CR.CPXXgetnumrows(env, lp) + 1
    hist = _safeIntArray(space)
    status = CR.CPXEgethist(env, lp, cpx_decode(key, default_encoding), hist)
    check_status(env, status)
    return LAU.array_to_list(hist, space)

# get solution quality metrics


def getqualitymetrics(env, lp, soln):
    space = 26
    data = _safeDoubleArray(space)
    ispace = 10
    idata = _safeIntArray(ispace)
    status = CR.CPXEgetqualitymetrics(env, lp, soln, data, idata)
    check_status(env, status)
    return [LAU.array_to_list(idata, ispace),
            LAU.array_to_list(data, space)]

def showquality(env, lp, soln):
    status = CR.CPXEshowquality(env, lp, soln)
    check_status(env, status)

# ########## Expert Callback BEGIN ########################################


def setgenericcallbackfunc(env, lp, contextmask, cbhandle):
    # NOTE: The cbhandle that is passed in here, is the Cplex instance that
    #       installs the callback. We do not increment the reference count
    #       for this on purpose: First of all, it is not necessary since the
    #       lifetime of env/lp is controled by the lifetime of this instance.
    #       Hence any reference the callable library stores is valid as long
    #       as it may be used.
    #       Second, in the destructor of the Cplex class we attempt to set
    #       the callback to (0, None). This may fail with
    #       CPXERR_NOT_ONE_PROBLEM. If we had incremented the reference count
    #       we would have to figure out whether the attempt to unset got as
    #       far as decrementing the reference count or failed earlier.
    status = CR.CPXXcallbacksetfunc(env, lp, contextmask, cbhandle)
    check_status(env, status)


def callbackgetinfoint(contextptr, which):
    data = CR.intPtr()
    status = CR.CPXXcallbackgetinfoint(contextptr, [which, data])
    check_status(None, status)
    return data.value()


def callbackgetinfolong(contextptr, which):
    data = CR.cpxlongPtr()
    status = CR.CPXXcallbackgetinfolong(contextptr, [which, data])
    check_status(None, status)
    return data.value()


def callbackgetinfodbl(contextptr, which):
    data = CR.doublePtr()
    status = CR.CPXXcallbackgetinfodbl(contextptr, [which, data])
    check_status(None, status)
    return data.value()


def callbackabort(contextptr):
    CR.CPXXcallbackabort(contextptr)

def callbackcandidateispoint(contextptr):
    bounded = CR.intPtr()
    status = CR.CPXXcallbackcandidateispoint(contextptr, bounded)
    check_status(None, status)
    return bounded.value() != 0

def callbackgetcandidatepoint(contextptr, begin, end):
    xlen = _rangelen(begin, end)
    x = _safeDoubleArray(xlen)
    status = CR.CPXXcallbackgetcandidatepoint(contextptr, x, begin, end, None)
    check_status(None, status)
    return LAU.array_to_list(x, xlen)

def callbackcandidateisray(contextptr):
    ray = CR.intPtr()
    status = CR.CPXXcallbackcandidateisray(contextptr, ray)
    check_status(None, status)
    return ray.value() != 0

def callbackgetcandidateray(contextptr, begin, end):
    raylen = _rangelen(begin, end)
    ray = _safeDoubleArray(raylen)
    status = CR.CPXXcallbackgetcandidateray(contextptr, ray, begin, end)
    check_status(None, status)
    return LAU.array_to_list(ray, raylen)

def callbackgetcandidateobj(contextptr):
    obj_p = CR.doublePtr()
    status = CR.CPXXcallbackgetcandidatepoint(contextptr, None, 0, -1, obj_p)
    check_status(None, status)
    return obj_p.value()


def callbackgetrelaxationpoint(contextptr, begin, end):
    xlen = _rangelen(begin, end)
    x = _safeDoubleArray(xlen)
    status = CR.CPXXcallbackgetrelaxationpoint(contextptr, x, begin, end, None)
    check_status(None, status)
    return LAU.array_to_list(x, xlen)


def callbackgetrelaxationpointobj(contextptr):
    obj_p = CR.doublePtr()
    status = CR.CPXXcallbackgetrelaxationpoint(contextptr, None, 0, -1, obj_p)
    check_status(None, status)
    return obj_p.value()


def callbackgetincumbent(contextptr, begin, end):
    xlen = _rangelen(begin, end)
    x = _safeDoubleArray(xlen)
    status = CR.CPXXcallbackgetincumbent(contextptr, x, begin, end, None)
    check_status(None, status)
    return LAU.array_to_list(x, xlen)


def callbackgetincumbentobj(contextptr):
    obj_p = CR.doublePtr()
    status = CR.CPXXcallbackgetincumbent(contextptr, None, 0, -1, obj_p)
    check_status(None, status)
    return obj_p.value()


def callbackgetlocallb(contextptr, begin, end):
    xlen = _rangelen(begin, end)
    x = _safeDoubleArray(xlen)
    status = CR.CPXXcallbackgetlocallb(contextptr, x, begin, end)
    check_status(None, status)
    return LAU.array_to_list(x, xlen)


def callbackgetlocalub(contextptr, begin, end):
    xlen = _rangelen(begin, end)
    x = _safeDoubleArray(xlen)
    status = CR.CPXXcallbackgetlocalub(contextptr, x, begin, end)
    check_status(None, status)
    return LAU.array_to_list(x, xlen)

def callbackgetgloballb(contextptr, begin, end):
    xlen = _rangelen(begin, end)
    x = _safeDoubleArray(xlen)
    status = CR.CPXXcallbackgetgloballb(contextptr, x, begin, end)
    check_status(None, status)
    return LAU.array_to_list(x, xlen)


def callbackgetglobalub(contextptr, begin, end):
    xlen = _rangelen(begin, end)
    x = _safeDoubleArray(xlen)
    status = CR.CPXXcallbackgetglobalub(contextptr, x, begin, end)
    check_status(None, status)
    return LAU.array_to_list(x, xlen)

def callbackpostheursoln(contextptr, cnt, ind, val, obj, strategy):
    status = CR.CPXXcallbackpostheursoln(contextptr, cnt,
                                         LAU.int_list_to_array(ind),
                                         LAU.double_list_to_array(val),
                                         obj, strategy)
    check_status(None, status)


def callbackaddusercuts(contextptr, rcnt, nzcnt, rhs, sense, rmat, cutmanagement, local,
                        enc=default_encoding):
    with LAU.double_c_array(rhs) as c_rhs, \
            LAU.int_c_array(cutmanagement) as c_cutmanagement, \
            LAU.int_c_array(local) as c_local:
        status = CR.CPXXcallbackaddusercuts(contextptr, rcnt, nzcnt, c_rhs,
                                            cpx_decode(sense, enc), rmat,
                                            c_cutmanagement, c_local)
    check_status(None, status)


def callbackrejectcandidate(contextptr, rcnt, nzcnt, rhs, sense, rmat,
                            enc=default_encoding):
    with LAU.double_c_array(rhs) as c_rhs:
        status = CR.CPXXcallbackrejectcandidate(contextptr, rcnt, nzcnt, c_rhs,
                                                cpx_decode(sense, enc), rmat)
    check_status(None, status)

# ########## Expert Callback END ##########################################
