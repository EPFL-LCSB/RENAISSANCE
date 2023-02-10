// -------------------------------------------------------------- -*- C++ -*-
// File: iloextrmgr.h
// Version 12.7.1
// --------------------------------------------------------------------------
// Licensed Materials - Property of IBM
// 5725-A06 5725-A29 5724-Y48 5724-Y49 5724-Y54 5724-Y55 5655-Y21
// Copyright IBM Corporation 2000, 2017. All Rights Reserved.
//
// US Government Users Restricted Rights - Use, duplication or
// disclosure restricted by GSA ADP Schedule Contract with
// IBM Corp.
// --------------------------------------------------------------------------


#ifndef _ILOLPEXTRMGR_H
#define _ILOLPEXTRMGR_H

#ifdef _WIN32
#pragma pack(push, 8)
#endif

#define BUFLEN 256

#include <ilconcert/ilomodel.h>
#include <ilconcert/iloalgi.h>
#include <ilcplex/ilocplexi.h>

class IloCpxExtractor;
class IloLPExtractor;
class IloExprExtractor;

// --------------------------------------------------------------------------
//
// IloLPExtractorManager
//
// This class manages the list of extractors for IloCplex.
//
// It keeps two lists of extractors, one for constraints (starting with _first)
// and one for variables (starting with _firstExpr).  Extraction of constraint
// is triggered by calling the extract() method.  Extraction of variables
// (including constraint used as variables, or more complicated expressions
// such as PWL) are triggered by calling method makeIndex().  This method
// returns the IloCplex::Index of the column that has been created for the
// variable (which may be tied to a more complex linearization if needed; see
// below).
//
// When the extractor is asked to extract an extractable to its IloCplex object
// it will use Concert RTTI to figure out which extractor has registered an
// extraction method for the particular type of object.
//
// If an extractor has been identified, the extraction method is called.  If
// successful, this extraction records some data that maintains the mapping
// between the extractable and whatever has been extracted to IloCplex.  Such
// data is stored in an extension of IloCplexI::Data objects which contain the
// IloCplex::Index of the row/column/gc/sos/what_have_you the extractable has
// been extracted to.  Symmetrically, in the Index managers for the
// rows/columns/etc we register the extractable that caused the creation of
// each row/column/etc.
//
// For natively supported objects (linear/quadratic constraints variables,
// sos's), this is all that is needed.  For more complex objects that require
// linearization more information is appended in the data objects.  In
// particular, an extraction method may create new extractables to model the
// linearization.  When doing so the IloCpxExtractor::add() method must be
// called in the extraction method, to instruct the manager to associate these
// new extractables with the extractable being linearized, and store them in
// the extended Data object.
//
// These additional extractables recorded in the Data object are deleted by the
// manager, when the extractable for which they were created is removed from
// IloCplex.
//
// For both constraint and variable extraction, we maintain an array _which and
// _whichExpr, respectively, where the artifacts of an extraction are stored.
// If an extractable with id id has been extracted as a variables, say,
// _whichExpr[id] contains the required information about that extraction as an
// ExList object
//
// When an extraction fails, we don't terminate immediately and leave an
// inconsistent state.  Instead, we append the failed extractable in the
// _failed array, create a dummy row or column and keep going.  At the
// end of an extraction with failed extractions, we clear the model
// and add the object that could not be extracted to the exception.
// Users can identify these objects from the object ID.    
//
// On changing the model, the Concert model is changed and change objects
// are created to communicate the change to any algorithms that have been
// extracted to, e.g., IloCplex.  IloCplex calls the extractor manager which
// passes the change objects onto any of the extractors that have extracted
// that type of object, e.g., IloDefaultLPExtractor.  The extractor looks to
// see if it has an apply method registered for that type of change object
// and if so, calls it.

class IloLabelCallbackI;
class IloLPExtractorManager : public IloPlugIn {
  ILORTTIDECL

  char _namebuf[BUFLEN];

  typedef IloCplexI::Data Data;

  IloCplexI*                _alg;
  IloLabelCallbackI*        _labelCB;
  IloCarray<IloExtractable> _added;    // added during extraction
  IloCarray<IloExtractable> _failed;   // extractables for which extraction failed

  struct ExList {
     IloCpxExtractor* _extr;    // extractor responsible for extraction
     Data*            _data;    // Data object describing extraction
     IloInt           _usecnt;  // # of times object has been extracted.  If a
                                // variable, say, is extracted many times we
                                // don't create a column each time, but instead
                                // count how many times the same column is
                                // reused.  This also applies to constraints.
     ExList(IloCpxExtractor*e=0) : _extr(e), _data(0), _usecnt(0) {}
     void clear() {
        _extr   = 0;
        _data   = 0;
        _usecnt = 0;
     }
  };

  IloLPExtractor*  _first;      // first extractor 
  IloCarray<ExList> _which;

  IloExprExtractor*  _firstExpr;
  IloCarray<ExList>  _whichExpr;

  IloBool _recordExtraction;

  void setMaxID (IloInt maxId);
  void checkLabelCB();

  /* Create an extended Data object containing the specified extractables that
   * have been implicitly created.  When such implicitly created extractables
   * are IloCpxExtractor::add()ed, they are only appended to the _added array.
   * makeData includes elements firstadded..lastadded to the Data object it
   * creates.
   */
  Data* makeData (void* data, IloInt firstadded, IloInt lastadded);

  /* Frees a data object.  If remove==IloTrue, the added extractables are also
   * removed from IloCplex.
   */
  void  freeData (void* data, IloBool remove=IloTrue);

  /* These methods are used for some tricky business when it comes to
   * extracting aggregate constraints, such as IloForall.  The deal here is that
   * Concert executes the looping over the all instances of the forall (or
   * other aggregate constraint, but I'll stick to for all here).  For each
   * iteration, it instantiates a template constraint to the current iteration
   * and asks cplex to extract it.  Once it is extracted, we create a dummy
   * extractable to be used as a place holder for the instantiated extractable
   * for that iteration.  We then need to the Data associated to the
   * instantiated template extractable to the newly created dummy object.
   */
  void popConData (IloInt id, IloExtractableArray added);
  void pushConData (IloInt id, IloExtractableArray added, void *data = 0);
  void pushConData (IloInt id, IloInt firstadded, IloInt lastadded, void *data =0);
  void moveConData (const IloExtractableI* from, const IloExtractableI* to);

  /* return the list of extractables in cons that have been implicitly created
   * during extraction of e.
   */
  void getSubExtractables(IloExtractable e, IloExtractableArray cons) const;

  IloCplexI::Index doMakeIndex  (const IloNumExprI* expr);
  IloBool          doRemoveIndex(const IloNumExprI* expr);

  IloBool doExtract(const IloExtractableI* obj);
  IloBool doRemove (const IloExtractableI* obj);

public:
  IloLPExtractorManager(IloCplexI* alg);
  ~IloLPExtractorManager();

  IloCplexI* getCplex() const   { return (_alg); }
  IloEnvI*   getEnv() const     { return (_alg->getEnv()); }

  const char *makeName(const char* name, const char *extension) const;

  IloBool isAccounting() const  { return _recordExtraction; }
  void startAccounting()        { _recordExtraction = IloTrue; }
  void stopAccounting ()        { _recordExtraction = IloFalse; }

  void clear();
  void setMaxId(IloInt maxid);

  IloExtractable add(IloExtractable e);
  IloExtractableArray add(IloExtractableArray e);
  void endAdded();

  IloInt getConNadded(IloInt id) const;
  IloInt getConNadded(const IloExtractableI *obj) const {
     return getConNadded(obj->getId());
  }
  IloInt getConNadded(IloExtractable obj) const {
     return getConNadded(obj.getImpl());
  }
  IloExtractable getConAdded(IloInt id, IloInt n) const;
  IloExtractable getConAdded(const IloExtractableI* obj, IloInt n) const {
     return (getConAdded(obj->getId(), n));
  }
  IloExtractable getConAdded(IloExtractable obj, IloInt n) const {
     return (getConAdded(obj.getImpl(), n));
  }
  void setConAdded(const IloExtractableI* obj, IloInt n, IloExtractable set);
  void setConAdded(IloExtractable obj, IloInt n, IloExtractable set) {
     setConAdded(obj.getImpl(), n, set);
  }
  IloExtractable getConLastAdded(IloExtractable obj);

  void removeAndDestroyAdded();

  IloCplexI::Index getConIndex (IloInt id) const {
     if (id >= _which.getSize())
        return 0;
     Data *data = _which[id]._data;
     return (data ? data->index : 0);
  }
  IloCplexI::Index getConIndex (const IloExtractableI* extr) const {
     return (getConIndex (extr->getId()));
  }
  IloCplexI::Index getConIndex (const IloExtractable extr) const {
     return (getConIndex (extr.getId()));
  }
  void setConIndex (const IloExtractableI* extr, IloCplexI::Index index) const {
     _which[extr->getId()]._data->index = index;
  }

  IloInt getVarNadded(IloInt id) const;
  IloInt getVarNadded(const IloExtractableI* obj) const {
     return (getVarNadded(obj->getId()));
  }
  IloInt getVarNadded(const IloExtractable obj) const {
     return (getVarNadded(obj.getImpl()));
  }

  IloExtractable getVarAdded(IloInt id, IloInt n) const;
  IloExtractable getVarAdded(const IloExtractableI* obj, IloInt n) const {
     return (getVarAdded(obj->getId(), n));
  }
  IloExtractable getVarAdded(IloExtractable obj, IloInt n) const {
     return (getVarAdded(obj.getImpl(), n));
  }
  void setVarAdded(const IloExtractableI* obj, IloInt n, IloExtractable set);
  void setVarAdded(IloExtractable obj, IloInt n, IloExtractable set) {
     setVarAdded(obj.getImpl(), n, set);
  }
  IloExtractable getVarLastAdded(IloExtractable obj) const;

  IloCplexI::Index getVarIndex(IloInt id) const {
     if (id >= _whichExpr.getSize())
        return 0;
     Data *data = _whichExpr[id]._data;
     return (data ? data->index : 0);
  }
  IloCplexI::Index getVarIndex(const IloNumExprI* expr) const {
     return getVarIndex(expr->getId());
  }
  IloCplexI::Index getVarIndex(const IloNumExpr expr) const {
     return getVarIndex(expr.getId());
  }

  IloCplexI::Index makeIndex(const IloNumExprI* expr) {
     IloInt id = expr->getId();
     return ((id < _whichExpr.getSize()  &&
              _whichExpr[id]._data != 0  &&
              ++_whichExpr[id]._usecnt     ) ? _whichExpr[id]._data->index
                                             : doMakeIndex (expr));
  }
  IloCplexI::Index makeIndex(const IloNumExpr expr) {
     return makeIndex (expr.getImpl());
  }

  IloBool removeIndex (const IloNumExprI* expr) {
     return (--_whichExpr[expr->getId()]._usecnt < 1) ? doRemoveIndex (expr)
                                                      : IloTrue;
  }
  IloBool removeIndex (const IloNumExpr expr) {
     return removeIndex (expr.getImpl());
  }

  void addExtractor   (IloExprExtractor* e);
  void removeExtractor(IloExprExtractor* e);

  void addExtractor   (IloLPExtractor* e);
  void removeExtractor(IloLPExtractor* e);

  IloBool extract(const IloExtractableI* obj) {
     return ((++_which[obj->getId()]._usecnt > 1) ? IloTrue : doExtract(obj));
  }
  // Return the array of extractable for which extraction failed
  const IloExtractableArray getFailedExtractables() const;

  IloBool remove (const IloExtractableI* obj) {
     return ((--_which[obj->getId()]._usecnt > 0) ? IloTrue : doRemove(obj));
  }

  void apply (const IloChange& chg, const IloExtractableI* obj);
  void apply (const IloChange& chg);

  IloBool isExtracted (const IloExtractableI* obj) const;
  IloBool isExprExtracted (const IloNumExprI* obj) const;

  IloBool hasExtracted (IloInt id, IloLPExtractor* extr) const {
     return (id >= 0  &&  _which[id]._extr == (IloCpxExtractor*)extr);
  }
  IloBool hasExtracted (IloInt id, IloExprExtractor* extr) const {
     return (id >= 0  &&  _whichExpr[id]._extr == (IloCpxExtractor*)extr);
  }
  void unuse     (IloInt id);
  void unuseExpr (IloInt id);

  IloBool change (const IloChange* chg);
  IloBool change (IloInt id, const IloChange* chg);

  IloBool isConsistent() const;
  IloBool isConsistent(IloLPExtractorManager* copy) const;
};

#ifdef _WIN32
#pragma pack(pop)
#endif

#endif
