/***** CLAIRE Compilation of file e:\claire\v3.5\src\meta\file.cl 
         [version 3.5.0 / safety 5] Sun May 28 08:25:57 2017 *****/

#include <claire.h>
#include <Kernel.h>
#include <Core.h>
#include <Language.h>
#include <Reader.h>

//+-------------------------------------------------------------+
//| CLAIRE                                                      |
//| file.cl                                                     |
//| Copyright (C) 1994 - 2013 Yves Caseau. All Rights Reserved  |
//| cf. copyright info in file object.cl: about()               |
//+-------------------------------------------------------------+
// --------------------------------------------------------------------
// this file contains all that is related to files + top-level
// --------------------------------------------------------------------
// **********************************************************************
// * Contents:                                                          *
// *  Part 1: Utilities                                                 *
// *  Part 2: Loading                                                   *
// *  Part 3: Reading in a file/string & top-level                      *
// *  Part 4: The show & kill methods + macro-methods                   *
// **********************************************************************
// **********************************************************************
// *   Part 1: Utilities                                                *
// **********************************************************************
// useful gadgets
//
/* The c++ function for: self_eval(self:delimiter) [SAFE_RESULT] */
OID  self_eval_delimiter(delimiter *self)
{ next_meta_reader(Reader.reader);
  { OID Result = 0;
    { OID  V_CL0081;close_exception(((general_error *) (*Core._general_error)(_string_(CSTRING("[117] loose delimiter ~S in program [line ~A ?]")),
        _oid_(list::alloc(2,_oid_(self),Reader.reader->nb_line)))));
      
      Result=_void_(V_CL0081);} 
    return (Result);} 
  } 


// a small useful function
// PORTABILITY WARNING: the following assumes newline is ^J (ASCII 10 dec)
// PORTABILITY WARNING: what about ^M (ASCII 13 dec)
//
// a small usefull function
/* The c++ function for: useless_c(r:integer) [0] */
ClaireBoolean * useless_c_integer(Cint r)
{ if ((r == 10) || 
      (r == 13))
   (Reader.reader->nb_line = (Reader.reader->nb_line+1));
  return (((r == Reader.reader->space) ? CTRUE : ((r == 10) ? CTRUE : ((r == 13) ? CTRUE : ((r == 32) ? CTRUE : ((r == Reader.reader->tab) ? CTRUE : CFALSE))))));} 


// take care of PC format (10 + 13)
/* The c++ function for: skipc(self:meta_reader) [0] */
OID  skipc_meta_reader(meta_reader *self)
{ { while ((useless_c_integer(firstc_meta_reader(self)) == CTRUE))
    { { ClaireBoolean * b = ((firstc_meta_reader(self) == 10) ? CTRUE : CFALSE);
        next_meta_reader(self);
        if ((b == CTRUE) && 
            (firstc_meta_reader(self) == 13))
         next_meta_reader(self);
        } 
      } 
    } 
  return (firstc_meta_reader(self));} 


// look for a meaningful termination char such as ) or ]
/* The c++ function for: skipc!(r:meta_reader) [SLOT_UPDATE] */
OID  skipc_I_meta_reader(meta_reader *r)
{ { OID Result = 0;
    { OID  c = skipc_meta_reader(r);
      if (c == 59)
       { { while (((firstc_meta_reader(r) != r->eof) && 
              (firstc_meta_reader(r) != 10)))
          { next_meta_reader(r);
            } 
          } 
        if (firstc_meta_reader(r) == r->eof)
         Result = Language._eof->value;
        else { (r->nb_line = (r->nb_line+1));
            Result = skipc_I_meta_reader(r);
            } 
          } 
      else if (c == 47)
       { OID  x = read_ident_port(r->fromp);
        if (Kernel._string == OWNER(x))
         Result = skipc_I_meta_reader(r);
        else Result = 47;
          } 
      else Result = c;
        } 
    return (Result);} 
  } 


/* The c++ function for: cnext(self:meta_reader) [SAFE_RESULT] */
meta_reader * cnext_meta_reader(meta_reader *self)
{ next_meta_reader(self);
  return (self);} 


/* The c++ function for: findeol(self:meta_reader) [0] */
ClaireBoolean * findeol_meta_reader(meta_reader *self)
{ { ClaireBoolean *Result ;
    { ClaireBoolean *v_or;
      { { OID V_C;{ V_C= _oid_(CFALSE);
            while ((useless_c_integer(firstc_meta_reader(self)) == CTRUE))
            { if (firstc_meta_reader(self) == 10)
               { V_C = Kernel.ctrue;
                break;} 
              next_meta_reader(self);
              } 
            } 
          
          v_or=OBJECT(ClaireBoolean,V_C);} 
        if (v_or == CTRUE) Result =CTRUE; 
        else { v_or = ((firstc_meta_reader(self) == self->eof) ? CTRUE : CFALSE);
          if (v_or == CTRUE) Result =CTRUE; 
          else Result = CFALSE;} 
        } 
      } 
    return (Result);} 
  } 


// safety checking
//
/* The c++ function for: checkno(r:meta_reader,n:integer,y:any) [NEW_ALLOC] */
OID  checkno_meta_reader(meta_reader *r,Cint n,OID y)
{ { OID Result = 0;
    if (firstc_meta_reader(r) != n)
     Result = _oid_(r);
    else Serror_string(CSTRING("[118] read wrong char ~S after ~S"),list::alloc(2,_oid_(char_I_integer(n)),y));
      return (Result);} 
  } 


// reads a keyword inside a control structure
//
/* The c++ function for: verify(t:any,x:any,y:any) [NEW_ALLOC] */
OID  verify_any(OID t,OID x,OID y)
{ { OID Result = 0;
    if (belong_to(x,t) == CTRUE)
     Result = x;
    else Serror_string(CSTRING("[119] read ~S instead of a ~S in a ~S"),list::alloc(3,x,
        t,
        y));
      return (Result);} 
  } 


// prints a syntax error
//
/* The c++ function for: Serror(s:string,la:list) [0] */
void  Serror_string(char *s,list *la)
{ princ_string(CSTRING("---- Syntax Error[line: "));
  princ_integer(Reader.reader->nb_line);
  princ_string(CSTRING("]:\n"));
  flush_port(Reader.reader->fromp);
  close_exception(((general_error *) (*Core._general_error)(_string_(s),
    _oid_(la))));
  } 


// the reader-------------------------------------------------------------
//
// variable handling -------------------------------------------------
// reads a variable
//
/* The c++ function for: extract_variable(self:any) [NEW_ALLOC+BAG_UPDATE+SLOT_UPDATE] */
Variable * extract_variable_any(OID self)
{ GC_BIND;
  { Variable *Result ;
    if ((INHERIT(OWNER(self),Language._Variable)) && (equal(get_symbol(OBJECT(Variable,self)->pname),self) != CTRUE))
     { (OBJECT(Variable,self)->range = extract_type_any(GC_OID((*Kernel.range)(self))));
      Result = OBJECT(Variable,self);
      } 
    else { Variable * v;
        { { Variable * _CL_obj = ((Variable *) GC_OBJECT(Variable,new_object_class(Language._Variable)));
            (_CL_obj->pname = extract_symbol_any(self));
            add_I_property(Kernel.instances,Language._Variable,11,_oid_(_CL_obj));
            v = _CL_obj;
            } 
          GC_OBJECT(Variable,v);} 
        (Reader.reader->last_form = _oid_(v));
        Result = v;
        } 
      GC_UNBIND; return (Result);} 
  } 


// create a variable and add it to the lexical environment
/* The c++ function for: bind!(self:meta_reader,%v:Variable) [NEW_ALLOC] */
list * bind_I_meta_reader(meta_reader *self,Variable *_Zv)
{ GC_BIND;
  (_Zv->index = self->index);
  { list *Result ;
    { OID  value = GC_OID(get_symbol(_Zv->pname));
      (self->index = (self->index+1));
      if (self->index > self->maxstack)
       (self->maxstack = self->index);
      put_symbol(_Zv->pname,_oid_(_Zv));
      Result = list::alloc(2,_oid_(_Zv),value);
      } 
    GC_UNBIND; return (Result);} 
  } 


// remove a variable from the lexical environment
//
/* The c++ function for: unbind!(self:meta_reader,%first:list) [0] */
OID  unbind_I_meta_reader(meta_reader *self,list *_Zfirst)
{ { OID Result = 0;
    { OID  var = (*(_Zfirst))[1];
      (self->index = (self->index-1));
      Result = put_symbol(OBJECT(Variable,var)->pname,(*(_Zfirst))[2]);
      } 
    return (Result);} 
  } 


// declaration of the CLAIRE standard ports ----------------------------
// the internal standard ports are transmitted via two strings in the
// symbol table.
//
/* The c++ function for: /(s:string,s2:string) [NEW_ALLOC] */
char * _7_string(char *s,char *s2)
{ GC_BIND;
  { char *Result ;
    Result = append_string(GC_STRING(append_string(s,GC_STRING(string_v(Reader._starfs_star->value)))),s2);
    GC_UNBIND; return (Result);} 
  } 


// basic methods defined in creader.c -----------------------------------
// TODO move!
// flush(self:port) : any -> function!(flush_port)
// this function is called by the main and restores the reader in a good shape. Also
// closes the input port to free the associated file ! <yc>
/* The c++ function for: mClaire/restore_state(self:meta_reader) [SLOT_UPDATE] */
void  restore_state_meta_reader(meta_reader *self)
{ if (equal(ClAlloc->import(Kernel._port,(int *) self->fromp),Reader.STDIN->value) != CTRUE)
   fclose_port(self->fromp);
  (self->fromp = EXPORT((ClairePort *),Reader.STDIN->value));
  (self->index = 1);
  pushback_port(EXPORT((ClairePort *),Reader.STDIN->value),32);
  restore_state_void();
  } 


// *********************************************************************
// *   Part 2: Loading                                                 *
// *********************************************************************
// sload is the interactive version.
//
/* The c++ function for: load_file(self:string,b:boolean) [NEW_ALLOC] */
OID  load_file_string(char *self,ClaireBoolean *b)
{ GC_RESERVE(1);  // HOHO v3.0.55 optim !
  (Reader.reader->index = 0);
  (Reader.reader->maxstack = 0);
  (Reader.reader->nb_line = 1);
  (Reader.reader->external = self);
  tformat_string(CSTRING("---- [load CLAIRE file: ~A]\n"),2,list::alloc(1,_string_(self)));
  { char * s2 = GC_STRING(append_string(self,CSTRING(".cl")));
    ClairePort * p1;
    { { ClaireHandler c_handle = ClaireHandler();
        if ERROR_IN 
        { p1 = fopen_string(s2,CSTRING("r"));
          ClEnv->cHandle--;} 
        else if (belong_to(_oid_(ClEnv->exception_I),_oid_(Kernel._any)) == CTRUE)
        { c_handle.catchIt();{ ClaireHandler c_handle = ClaireHandler();
            if ERROR_IN 
            { p1 = fopen_string(self,CSTRING("r"));
              ClEnv->cHandle--;} 
            else if (belong_to(_oid_(ClEnv->exception_I),_oid_(Kernel._any)) == CTRUE)
            { c_handle.catchIt();close_exception(((general_error *) (*Core._general_error)(_string_(CSTRING("[120] the file ~A cannot be opened")),
                _oid_(list::alloc(1,_string_(self))))));
              } 
            else PREVIOUS_HANDLER;} 
          } 
        else PREVIOUS_HANDLER;} 
      (p1);} 
    Cint  start = ClEnv->base;
    Cint  top = ClEnv->index;
    ClairePort * p2 = (Reader.reader->fromp);
    ClaireBoolean * b2 = Reader.reader->toplevel;
    OID  _staritem_star = CNULL;
    (ClEnv->base= top);
    (Reader.reader->fromp = p1);
    (Reader.reader->toplevel = CFALSE);
    _staritem_star= GC_OID(readblock_port(p1));
    { OID gc_local;
      while ((equal(_staritem_star,_oid_(Reader.eof)) != CTRUE))
      { GC_LOOP;
        if (b == CTRUE)
         { princ_integer(Reader.reader->nb_line);
          princ_string(CSTRING(":"));
          print_any(_staritem_star);
          princ_string(CSTRING("\n"));
          } 
        (ClEnv->index= (top+(Reader.reader->maxstack+1)));
        if (Kernel._string == OWNER(_staritem_star))
         { if ((OBJECT(ClaireBoolean,Language.NeedComment->value)) == CTRUE)
           { if (Language.LastComment->value != CNULL)
             (Language.LastComment->value= (*Kernel._7_plus)(GC_OID(Language.LastComment->value),
              GC_OID(_string_(append_string(CSTRING("\n-- "),string_v(_staritem_star))))));
            else (Language.LastComment->value= _string_(append_string(GC_STRING(append_string(GC_STRING(append_string(GC_STRING(append_string(GC_STRING(append_string(CSTRING("["),GC_STRING(Reader.reader->external))),CSTRING("("))),GC_STRING(string_I_integer (Reader.reader->nb_line)))),CSTRING(")]\n-- "))),string_v(_staritem_star))));
              } 
          } 
        else { GC__OID(_staritem_star = OPT_EVAL(_staritem_star), 1);
            (Language.LastComment->value= CNULL);
            } 
          if (b == CTRUE)
         { princ_string(CSTRING("=> "));
          print_any(_staritem_star);
          princ_string(CSTRING(" \n\n"));
          } 
        GC__OID(_staritem_star = readblock_port(p1), 1);
        GC_UNLOOP;} 
      } 
    (ClEnv->base= start);
    (ClEnv->index= top);
    (Reader.reader->toplevel = b2);
    (Reader.reader->fromp = p2);
    (Reader.reader->external = CSTRING("toplevel"));
    fclose_port(p1);
    } 
  { OID Result = 0;
    Result = Kernel.ctrue;
    GC_UNBIND; return (Result);} 
  } 


// the simple load
//
/* The c++ function for: load(self:string) [NEW_ALLOC] */
OID  load_string(char *self)
{ return (load_file_string(self,CFALSE));} 


/* The c++ function for: sload(self:string) [NEW_ALLOC] */
OID  sload_string(char *self)
{ return (load_file_string(self,CTRUE));} 


// loading a module into the system.
// The correct package is open and each file is loaded.
/* The c++ function for: load_file(self:module,b:boolean) [NEW_ALLOC+SLOT_UPDATE] */
void  load_file_module(module *self,ClaireBoolean *b)
{ GC_BIND;
  if (self->status == 2)
   { fcall1(self->evaluate,Kernel._any,_oid_(Kernel._any),Kernel._any);
    (self->status = 3);
    } 
  else if ((self->status == 0) && 
      (((self->source == (NULL)) ? CTRUE : CFALSE) != CTRUE))
   { begin_module(self);
    { char * s = GC_STRING(append_string(GC_STRING(self->source),GC_STRING(string_v(Reader._starfs_star->value))));
      { OID gc_local;
        ITERATE(x);
        bag *x_support;
        x_support = GC_OBJECT(list,self->made_of);
        for (START(x_support); NEXT(x);)
        { GC_LOOP;
          load_file_string(GC_STRING(append_string(GC_STRING(append_string(s,string_v(x))),CSTRING(".cl"))),b);
          GC_UNLOOP;} 
        } 
      } 
    (self->status = 1);
    } 
  end_module(self);
  GC_UNBIND;} 


// the simple load
//
/* The c++ function for: load(self:module) [NEW_ALLOC+BAG_UPDATE] */
OID  load_module(module *self)
{ GC_BIND;
  { OID Result = 0;
    { OID gc_local;
      ITERATE(x);
      Result= Kernel.cfalse;
      bag *x_support;
      x_support = GC_OBJECT(list,add_modules_list(list::alloc(1,_oid_(self))));
      for (START(x_support); NEXT(x);)
      (*Reader.load_file)(x,
        Kernel.cfalse);
      } 
    GC_UNBIND; return (Result);} 
  } 


/* The c++ function for: sload(self:module) [NEW_ALLOC+BAG_UPDATE] */
OID  sload_module(module *self)
{ GC_BIND;
  { OID Result = 0;
    { OID gc_local;
      ITERATE(x);
      Result= Kernel.cfalse;
      bag *x_support;
      x_support = GC_OBJECT(list,add_modules_list(list::alloc(1,_oid_(self))));
      for (START(x_support); NEXT(x);)
      (*Reader.load_file)(x,
        Kernel.ctrue);
      } 
    GC_UNBIND; return (Result);} 
  } 


// This is a very important method which adds the right order the
// modules that must be loaded to load oself. the list l represents the
// list of modules that we know will be in the result. result represent
// the current list of ordered modules
//
/* The c++ function for: add_modules(self:module,l:set,result:list) [NEW_ALLOC+BAG_UPDATE] */
list * add_modules_module(module *self,set *l,list *result)
{ if (result->memq(_oid_(self)) == CTRUE) 
  { { list *Result ;
      Result = result;
      return (Result);} 
     } 
  else{ if (contain_ask_set(l,_oid_(self)) == CTRUE) 
    { { list *Result ;
        Result = result->addFast(_oid_(self));
        return (Result);} 
       } 
    else{ GC_RESERVE(1);  // HOHO v3.0.55 optim !
      l= GC_OBJECT(set,l->addFast(_oid_(self)));
      { OID gc_local;
        ITERATE(x);
        for (START(self->uses); NEXT(x);)
        { GC_LOOP;
          if (INHERIT(OWNER(x),Kernel._module))
           GC__ANY(result = add_modules_module(OBJECT(module,x),l,result), 1);
          GC_UNLOOP;} 
        } 
      if (result->memq(_oid_(self)) != CTRUE)
       result= result->addFast(_oid_(self));
      { OID gc_local;
        ITERATE(x);
        for (START(self->parts); NEXT(x);)
        { GC_LOOP;
          GC__ANY(result = add_modules_module(OBJECT(module,x),l,result), 1);
          GC_UNLOOP;} 
        } 
      { list *Result ;
        Result = result;
        GC_UNBIND; return (Result);} 
      } 
    } 
  } 


// this methods takes a list of modules that must be loaded and returns
// a list of modules that are necessary for the definition
//
/* The c++ function for: add_modules(self:list) [NEW_ALLOC+BAG_UPDATE] */
list * add_modules_list(list *self)
{ GC_RESERVE(1);  // HOHO v3.0.55 optim !
  { list *Result ;
    { list * l = list::empty(Kernel._module);
      { OID gc_local;
        ITERATE(x);
        for (START(self); NEXT(x);)
        { GC_LOOP;
          GC__ANY(l = add_modules_module(OBJECT(module,x),GC_OBJECT(set,set_I_bag(l)),l), 1);
          GC_UNLOOP;} 
        } 
      Result = l;
      } 
    GC_UNBIND; return (Result);} 
  } 


// load a file of expressions (quite useful)
/* The c++ function for: eload(self:string) [NEW_ALLOC] */
OID  eload_string(char *self)
{ GC_RESERVE(1);  // HOHO v3.0.55 optim !
  (Reader.reader->index = 0);
  (Reader.reader->maxstack = 0);
  (Reader.reader->nb_line = 1);
  (Reader.reader->external = self);
  tformat_string(CSTRING("---- [eload CLAIRE file: ~A]\n"),2,list::alloc(1,_string_(self)));
  { char * s2 = GC_STRING(append_string(self,CSTRING(".cl")));
    ClairePort * p0 = (Reader.reader->fromp);
    ClairePort * p1;
    { { ClaireHandler c_handle = ClaireHandler();
        if ERROR_IN 
        { p1 = fopen_string(s2,CSTRING("r"));
          ClEnv->cHandle--;} 
        else if (belong_to(_oid_(ClEnv->exception_I),_oid_(Kernel._any)) == CTRUE)
        { c_handle.catchIt();{ ClaireHandler c_handle = ClaireHandler();
            if ERROR_IN 
            { p1 = fopen_string(self,CSTRING("r"));
              ClEnv->cHandle--;} 
            else if (belong_to(_oid_(ClEnv->exception_I),_oid_(Kernel._any)) == CTRUE)
            { c_handle.catchIt();close_exception(((general_error *) (*Core._general_error)(_string_(CSTRING("[120] the file ~A cannot be opened")),
                _oid_(list::alloc(1,_string_(self))))));
              } 
            else PREVIOUS_HANDLER;} 
          } 
        else PREVIOUS_HANDLER;} 
      (p1);} 
    Cint  start = ClEnv->base;
    Cint  top = ClEnv->index;
    ClaireBoolean * b2 = Reader.reader->toplevel;
    OID  _staritem_star = CNULL;
    (ClEnv->base= top);
    (Reader.reader->toplevel = CFALSE);
    (Reader.reader->fromp = p1);
    _staritem_star= GC_OID(read_port(p1));
    { OID gc_local;
      while ((equal(_staritem_star,_oid_(Reader.eof)) != CTRUE))
      { GC_LOOP;
        (ClEnv->index= (top+(Reader.reader->maxstack+1)));
        GC__OID(_staritem_star = OPT_EVAL(_staritem_star), 1);
        GC__OID(_staritem_star = read_port(p1), 1);
        GC_UNLOOP;} 
      } 
    (ClEnv->base= start);
    (ClEnv->index= top);
    (Reader.reader->fromp = p0);
    (Reader.reader->toplevel = b2);
    (Reader.reader->external = CSTRING("toplevel"));
    fclose_port(p1);
    } 
  { OID Result = 0;
    Result = Kernel.ctrue;
    GC_UNBIND; return (Result);} 
  } 


// *********************************************************************
// *   Part 3: Read & Top-level                                        *
// *********************************************************************
// The standard read function.
// This method reads from a CLAIRE port (self).
// We first check if self is the current reading port.
// the last character read (and not used) is in last(reader)
/* The c++ function for: readblock(p:port) [NEW_ALLOC] */
OID  readblock_port(ClairePort *p)
{ if (equal(ClAlloc->import(Kernel._port,(int *) Reader.reader->fromp),ClAlloc->import(Kernel._port,(int *) p)) == CTRUE) 
  { { OID Result = 0;
      Result = nextunit_meta_reader(Reader.reader);
      return (Result);} 
     } 
  else{ GC_BIND;
    { OID Result = 0;
      { ClairePort * p2 = (Reader.reader->fromp);
        (Reader.reader->fromp = p);
        { OID  val = GC_OID(nextunit_meta_reader(Reader.reader));
          (Reader.reader->fromp = p2);
          if ((equal(val,Reader.reader->paren) == CTRUE) || 
              ((equal(val,Reader.reader->curly) == CTRUE) || 
                ((equal(val,Reader.reader->comma) == CTRUE) || 
                  (equal(val,Reader.reader->bracket) == CTRUE))))
           Serror_string(CSTRING("[117] Loose ~S in file"),list::alloc(1,val));
          Result = val;
          } 
        } 
      GC_UNBIND; return (Result);} 
    } 
  } 


// read reads a closed expression
/* The c++ function for: read(p:port) [NEW_ALLOC] */
OID  read_port(ClairePort *p)
{ GC_BIND;
  { OID Result = 0;
    { ClairePort * p2 = (Reader.reader->fromp);
      if (equal(ClAlloc->import(Kernel._port,(int *) p),ClAlloc->import(Kernel._port,(int *) p2)) != CTRUE)
       (Reader.reader->fromp = p);
      { OID  val;
        { if (skipc_meta_reader(Reader.reader) == Reader.reader->eof)
           val = _oid_(Reader.eof);
          else val = nexte_meta_reader(Reader.reader);
            GC_OID(val);} 
        if (equal(ClAlloc->import(Kernel._port,(int *) p),ClAlloc->import(Kernel._port,(int *) p2)) != CTRUE)
         (Reader.reader->fromp = p2);
        if ((equal(val,Reader.reader->paren) == CTRUE) || 
            ((equal(val,Reader.reader->curly) == CTRUE) || 
              ((equal(val,Reader.reader->comma) == CTRUE) || 
                (equal(val,Reader.reader->bracket) == CTRUE))))
         Serror_string(CSTRING("[117] Loose ~S in file"),list::alloc(1,val));
        Result = val;
        } 
      } 
    GC_UNBIND; return (Result);} 
  } 


// read into a string
/* The c++ function for: read(self:string) [NEW_ALLOC] */
OID  read_string(char *self)
{ GC_BIND;
  { OID Result = 0;
    { ClaireBoolean * b = Reader.reader->toplevel;
      ClairePort * p = (Reader.reader->fromp);
      OID  x = CNULL;
      (Reader.reader->toplevel = CTRUE);
      (Reader.reader->fromp = port_I_string(self));
      { ClaireHandler c_handle = ClaireHandler();
        if ERROR_IN 
        { { x= GC_OID(nextunit_meta_reader(Reader.reader));
            (Reader.reader->fromp = p);
            } 
          ClEnv->cHandle--;} 
        else if (belong_to(_oid_(ClEnv->exception_I),_oid_(Kernel._any)) == CTRUE)
        { c_handle.catchIt();{ (Reader.reader->fromp = p);
            close_exception(ClEnv->exception_I);
            } 
          } 
        else PREVIOUS_HANDLER;} 
      (Reader.reader->toplevel = b);
      Result = x;
      } 
    GC_UNBIND; return (Result);} 
  } 


// used by the top level
// calls the debugger
/* The c++ function for: debug_if_possible(_CL_obj:void) [NEW_ALLOC+BAG_UPDATE+SLOT_UPDATE] */
OID  debug_if_possible_void()
{ { OID Result = 0;
    if (0 <= ClEnv->debug_I)
     Result = fcall1(OBJECT(method,(*(Reader.call_debug->restrictions))[1])->functional,Kernel._any,_oid_(ClEnv),Kernel._any);
    else Result = print_exception_void();
      return (Result);} 
  } 


// a method for calling the printer without issuing a message (that would
// modify the stack and make debugging impossible).
// here we assume that self_print is always defined and is always a compiled
// function
/* The c++ function for: print_exception(_CL_obj:void) [NEW_ALLOC+BAG_UPDATE+SLOT_UPDATE] */
OID  print_exception_void()
{ GC_BIND;
  { OID Result = 0;
    { ClairePort * p = (use_as_output_port(EXPORT((ClairePort *),Reader.STDOUT->value)));
      ClaireException * _Zerr = GC_OBJECT(ClaireException,ClEnv->exception_I);
      method * _Zprop = ((method *) _at_property1(Kernel.self_print,OWNER(_oid_(_Zerr))));
      { ClaireHandler c_handle = ClaireHandler();
        if ERROR_IN 
        { if (((_Zprop->functional == (NULL)) ? CTRUE : CFALSE) != CTRUE)
           fcall1(_Zprop->functional,Kernel._object,_oid_(_Zerr),Kernel._any);
          else funcall_method1(_Zprop,_oid_(_Zerr));
            ClEnv->cHandle--;} 
        else if (belong_to(_oid_(ClEnv->exception_I),_oid_(Kernel._any)) == CTRUE)
        { c_handle.catchIt();princ_string(CSTRING("****** ERROR[121]: unprintable error has occurred.\n"));
          } 
        else PREVIOUS_HANDLER;} 
      Result = ClAlloc->import(Kernel._port,(int *) use_as_output_port(p));
      } 
    GC_UNBIND; return (Result);} 
  } 


// **********************************************************************
// *  Part 4: The show & kill methods + macro-methods                   *
// **********************************************************************
//----------------- printing an object -------------------------
// %show is an open restriction which allow to show the value of a
// binary relation
//
// this method is the basic method called for show(..)
//
/* The c++ function for: show(self:any) [NEW_ALLOC] */
OID  show_any(OID self)
{ GC_BIND;
  if (_Z_any1(self,Kernel._object) == CTRUE)
   { OID gc_local;
    ITERATE(rel);
    bag *rel_support;
    rel_support = OWNER(self)->slots;
    for (START(rel_support); NEXT(rel);)
    { GC_LOOP;
      { print_any(_oid_(OBJECT(restriction,rel)->selector));
        princ_string(CSTRING(": "));
        print_any(GC_OID(get_slot(OBJECT(slot,rel),OBJECT(ClaireObject,self))));
        princ_string(CSTRING("\n"));
        } 
      GC_UNLOOP;} 
    } 
  else { print_any(self);
      princ_string(CSTRING(" is a "));
      print_any(_oid_(OWNER(self)));
      princ_string(CSTRING("\n"));
      } 
    { OID Result = 0;
    Result = Kernel.ctrue;
    GC_UNBIND; return (Result);} 
  } 


// This is the good version of kill, the nasty one is dangerous ....
// these restrictions of kill explain the dependencies among objects
//
/* The c++ function for: kill(self:object) [SLOT_UPDATE] */
OID  kill_object(ClaireObject *self)
{ if (INHERIT(self->isa,Kernel._thing))
   put_symbol(CLREAD(thing,self,name),CNULL);
  (self->isa->instances = ((list *) delete_bag(self->isa->instances,_oid_(self))));
  return (_oid_(Kernel.emptySet));} 


/* The c++ function for: kill(self:class) [NEW_ALLOC+BAG_UPDATE+SLOT_UPDATE] */
OID  kill_class(ClaireClass *self)
{ { while ((self->instances->length != 0))
    { (*Reader.kill)((*(self->instances))[1]);
      } 
    } 
  { ITERATE(x);
    for (START(self->descendents); NEXT(x);)
    if (OBJECT(ClaireClass,x)->superclass == self)
     kill_class(OBJECT(ClaireClass,x));
    } 
  return (kill_object(self));} 


// our two very special inline methods
/* The c++ function for: min(x:integer,y:integer) [SAFE_RESULT] */
Cint  min_integer(Cint x,Cint y)
{ { Cint Result = 0;
    Result = ((x <= y) ?
      x :
      y );
    return (Result);} 
  } 


/* The c++ function for: max(x:integer,y:integer) [SAFE_RESULT] */
Cint  max_integer(Cint x,Cint y)
{ { Cint Result = 0;
    Result = ((x <= y) ?
      y :
      x );
    return (Result);} 
  } 


/* The c++ function for: min(g0082:any,g0083:any) [RETURN_ARG] */
OID  min_float_(OID g0082,OID g0083)
{ return _float_(min_float(float_v(g0082),float_v(g0083)));} 


/* The c++ function for: min(x:float,y:float) [RETURN_ARG] */
double  min_float(double x,double y)
{ { double Result =0.0;
    Result = ((x <= y) ?
      x :
      y );
    return (Result);} 
  } 


/* The c++ function for: max(g0084:any,g0085:any) [RETURN_ARG] */
OID  max_float_(OID g0084,OID g0085)
{ return _float_(max_float(float_v(g0084),float_v(g0085)));} 


/* The c++ function for: max(x:float,y:float) [RETURN_ARG] */
double  max_float(double x,double y)
{ { double Result =0.0;
    Result = ((x <= y) ?
      y :
      x );
    return (Result);} 
  } 


/* The c++ function for: min(x:any,y:any) [NEW_ALLOC+RETURN_ARG] */
OID  min_any(OID x,OID y)
{ { OID Result = 0;
    if ((OBJECT(ClaireBoolean,(*Kernel._inf_equal)(x,
      y))) == CTRUE)
     Result = x;
    else Result = y;
      return (Result);} 
  } 


/* The c++ function for: max(x:any,y:any) [NEW_ALLOC+RETURN_ARG] */
OID  max_any(OID x,OID y)
{ { OID Result = 0;
    if ((OBJECT(ClaireBoolean,(*Kernel._inf_equal)(x,
      y))) == CTRUE)
     Result = y;
    else Result = x;
      return (Result);} 
  } 


// this is a useful macro for hashing
/* The c++ function for: mClaire/hashgrow(l:list,hi:property) [0] */
list * hashgrow_list(list *l,property *hi)
{ GC_BIND;
  { list *Result ;
    { list * l1 = l;
      list * l2 = GC_OBJECT(list,make_list_integer((*Kernel._star)(GC_OID((*(l1))[0]),
        2),CNULL));
      { ITERATE(x);
        for (START(l1); NEXT(x);)
        if (x != CNULL)
         (*Core.call)(_oid_(hi),
          _oid_(l2),
          x);
        } 
      Result = l2;
      } 
    GC_UNBIND; return (Result);} 
  } 


// check if the value if known?
/* The c++ function for: known?(a:table,x:any) [0] */
ClaireBoolean * known_ask_table(table *a,OID x)
{ return (_I_equal_any(get_table(a,x),CNULL));} 


/* The c++ function for: unknown?(a:table,x:any) [0] */
ClaireBoolean * unknown_ask_table(table *a,OID x)
{ return (equal(get_table(a,x),CNULL));} 


/* The c++ function for: float!(g0086:string) [NEW_ALLOC] */
OID  float_I_string_(char *g0086)
{ return _float_(float_I_string(g0086));} 


/* The c++ function for: float!(self:string) [NEW_ALLOC] */
double  float_I_string(char *self)
{ GC_BIND;
  { double Result =0.0;
    { OID  x = GC_OID(read_string(self));
      if (Kernel._float == OWNER(x))
       Result = float_v(x);
      else if (INHERIT(OWNER(x),Kernel._integer))
       Result = to_float(x);
      else close_exception(((general_error *) (*Core._general_error)(_string_(CSTRING("[??] ~A is not a float")),
          _oid_(list::alloc(1,_string_(self))))));
        } 
    GC_UNBIND; return (Result);} 
  } 


// v3.00.46 a new macro
/* The c++ function for: >=(self:any,x:any) [NEW_ALLOC] */
ClaireBoolean * _sup_equal_any(OID self,OID x)
{ return (OBJECT(ClaireBoolean,(*Kernel._inf_equal)(x,
    self)));} 


// v3.3: a recursive macro
// v3.3.42 add macros to use float & integers easily
/* The c++ function for: +(g0087:integer,g0088:any) [0] */
OID  _plus_integer2_(Cint g0087,OID g0088)
{ return _float_(_plus_integer2(g0087,float_v(g0088)));} 


/* The c++ function for: +(x:integer,y:float) [0] */
double  _plus_integer2(Cint x,double y)
{ return ((to_float(x)+y));} 


/* The c++ function for: *(g0089:integer,g0090:any) [0] */
OID  _star_integer2_(Cint g0089,OID g0090)
{ return _float_(_star_integer2(g0089,float_v(g0090)));} 


/* The c++ function for: *(x:integer,y:float) [0] */
double  _star_integer2(Cint x,double y)
{ return ((to_float(x)*y));} 


/* The c++ function for: /(g0091:integer,g0092:any) [0] */
OID  _7_integer2_(Cint g0091,OID g0092)
{ return _float_(_7_integer2(g0091,float_v(g0092)));} 


/* The c++ function for: /(x:integer,y:float) [0] */
double  _7_integer2(Cint x,double y)
{ return ((to_float(x)/y));} 


/* The c++ function for: -(g0093:integer,g0094:any) [0] */
OID  _dash_integer3_(Cint g0093,OID g0094)
{ return _float_(_dash_integer3(g0093,float_v(g0094)));} 


/* The c++ function for: -(x:integer,y:float) [0] */
double  _dash_integer3(Cint x,double y)
{ return ((to_float(x)-y));} 


/* The c++ function for: +(g0095:any,g0096:integer) [0] */
OID  _plus_float2_(OID g0095,Cint g0096)
{ return _float_(_plus_float2(float_v(g0095),g0096));} 


/* The c++ function for: +(x:float,y:integer) [0] */
double  _plus_float2(double x,Cint y)
{ return ((x+to_float(y)));} 


/* The c++ function for: *(g0097:any,g0098:integer) [0] */
OID  _star_float2_(OID g0097,Cint g0098)
{ return _float_(_star_float2(float_v(g0097),g0098));} 


/* The c++ function for: *(x:float,y:integer) [0] */
double  _star_float2(double x,Cint y)
{ return ((x*to_float(y)));} 


/* The c++ function for: /(g0099:any,g0100:integer) [0] */
OID  _7_float2_(OID g0099,Cint g0100)
{ return _float_(_7_float2(float_v(g0099),g0100));} 


/* The c++ function for: /(x:float,y:integer) [0] */
double  _7_float2(double x,Cint y)
{ return ((x/to_float(y)));} 


/* The c++ function for: -(g0101:any,g0102:integer) [0] */
OID  _dash_float3_(OID g0101,Cint g0102)
{ return _float_(_dash_float3(float_v(g0101),g0102));} 


/* The c++ function for: -(x:float,y:integer) [0] */
double  _dash_float3(double x,Cint y)
{ return ((x-to_float(y)));} 


// v3.4 a useful macro
/* The c++ function for: sqr(x:integer) [0] */
Cint  sqr_integer(Cint x)
{ return ((x*x));} 


/* The c++ function for: sqr(g0103:any) [0] */
OID  sqr_float_(OID g0103)
{ return _float_(sqr_float(float_v(g0103)));} 


/* The c++ function for: sqr(x:float) [0] */
double  sqr_float(double x)
{ return ((x*x));} 

