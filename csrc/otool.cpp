/***** CLAIRE Compilation of file e:\claire\v3.5\src\compile\otool.cl 
         [version 3.5.0 / safety 5] Sun May 28 08:25:58 2017 *****/

#include <claire.h>
#include <Kernel.h>
#include <Core.h>
#include <Language.h>
#include <Reader.h>
#include <Optimize.h>
void  self_print_to_protect(Compile_to_protect *v15440)
{ GC_BIND;
  princ_string(CSTRING("[to_protect "));
  print_any(GC_OID(v15440->arg));
  princ_string(CSTRING("]"));
  GC_UNBIND;} 

OID  self_eval_to_protect(Compile_to_protect *v15440)
{ GC_BIND;
  { OID Result = 0;
    Result = OPT_EVAL(v15440->arg);
    GC_UNBIND; return (Result);} 
  } 

void  self_print_to_CL(Compile_to_CL *v9332)
{ GC_BIND;
  princ_string(CSTRING("CL{"));
  print_any(GC_OID(v9332->arg));
  princ_string(CSTRING("}:"));
  print_any(_oid_(v9332->set_arg));
  princ_string(CSTRING(""));
  GC_UNBIND;} 

ClaireType * c_type_to_CL_Optimize(Compile_to_CL *v9332)
{ GC_BIND;
  { ClaireType *Result ;
    Result = sort_abstract_I_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(v9332->arg))));
    GC_UNBIND; return (Result);} 
  } 

ClaireBoolean * c_gc_ask_to_CL(Compile_to_CL *v9332)
{ GC_BIND;
  { ClaireBoolean *Result ;
    Result = (((gcsafe_ask_class(v9332->set_arg) != CTRUE) && 
        ((v9332->set_arg == Kernel._float) || 
            (_inf_equalt_class(v9332->set_arg,Kernel._cl_import) == CTRUE))) ? CTRUE : (((OBJECT(ClaireBoolean,(*Optimize.c_gc_ask)(GC_OID(v9332->arg)))) == CTRUE) ? CTRUE : CFALSE));
    GC_UNBIND; return (Result);} 
  } 

void  self_print_to_C(Compile_to_C *v9332)
{ GC_BIND;
  princ_string(CSTRING("C{"));
  print_any(GC_OID(v9332->arg));
  princ_string(CSTRING("}:"));
  print_any(_oid_(v9332->set_arg));
  princ_string(CSTRING(""));
  GC_UNBIND;} 

ClaireBoolean * c_gc_ask_to_C(Compile_to_C *v9332)
{ GC_BIND;
  { ClaireBoolean *Result ;
    Result = ((gcsafe_ask_class(v9332->set_arg) != CTRUE) ? (((OBJECT(ClaireBoolean,(*Optimize.c_gc_ask)(GC_OID(v9332->arg)))) == CTRUE) ? (((_inf_equalt_class(v9332->set_arg,Kernel._object) == CTRUE) || 
        (v9332->set_arg == Kernel._string)) ? CTRUE: CFALSE): CFALSE): CFALSE);
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_to_C_Optimize(Compile_to_C *v9332)
{ GC_BIND;
  { ClaireType *Result ;
    Result = glb_class(v9332->set_arg,GC_OBJECT(ClaireType,ptype_type(OBJECT(ClaireType,(*Optimize.c_type)(GC_OID(v9332->arg))))));
    GC_UNBIND; return (Result);} 
  } 

void  self_print_C_cast(Compile_C_cast *v9332)
{ GC_BIND;
  princ_string(CSTRING("<"));
  print_any(GC_OID(v9332->arg));
  princ_string(CSTRING(":"));
  print_any(_oid_(v9332->set_arg));
  princ_string(CSTRING(">"));
  GC_UNBIND;} 

ClaireBoolean * c_gc_ask_C_cast(Compile_C_cast *v9332)
{ GC_BIND;
  { ClaireBoolean *Result ;
    Result = OBJECT(ClaireBoolean,(*Optimize.c_gc_ask)(v9332->arg));
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_C_cast_Optimize(Compile_C_cast *v9332)
{ return (v9332->set_arg);} 

OID  c_code_C_cast_Optimize(Compile_C_cast *v9332,ClaireClass *v15435)
{ GC_BIND;
  { OID Result = 0;
    if (INHERIT(v15435,Kernel._object))
     { Compile_C_cast * v10264 = ((Compile_C_cast *) GC_OBJECT(Compile_C_cast,new_object_class(Optimize._C_cast)));
      (v10264->arg = (*Optimize.c_code)(GC_OID(v9332->arg),
        _oid_(v15435)));
      (v10264->set_arg = v9332->set_arg);
      add_I_property(Kernel.instances,Optimize._C_cast,11,_oid_(v10264));
      Result = _oid_(v10264);
      } 
    else Result = (*Optimize.c_code)(GC_OID(v9332->arg),
        _oid_(v15435));
      GC_UNBIND; return (Result);} 
  } 

void  self_print_Pattern(Optimize_ClairePattern *v9332)
{ GC_BIND;
  print_any(_oid_(v9332->selector));
  princ_string(CSTRING("[tuple("));
  princ_bag(GC_OBJECT(list,v9332->arg));
  princ_string(CSTRING(")]"));
  GC_UNBIND;} 

ClaireBoolean * _Z_any3(OID v15440,Optimize_ClairePattern *v15441)
{ GC_BIND;
  { ClaireBoolean *Result ;
    if (INHERIT(OWNER(v15440),Language._Call))
     { ClaireBoolean *v_and;
      { v_and = ((OBJECT(Call,v15440)->selector == v15441->selector) ? CTRUE : CFALSE);
        if (v_and == CFALSE) Result =CFALSE; 
        else { { list * v13630;
            { { bag *v_list; OID v_val;
                OID v15442,CLcount;
                v_list = GC_OBJECT(list,OBJECT(Call,v15440)->args);
                 v13630 = v_list->clone();
                for (CLcount= 1; CLcount <= v_list->length; CLcount++)
                { v15442 = (*(v_list))[CLcount];
                  v_val = (*Optimize.c_type)(v15442);
                  
                  (*((list *) v13630))[CLcount] = v_val;} 
                } 
              GC_OBJECT(list,v13630);} 
            v_and = tmatch_ask_list(v13630,GC_OBJECT(list,v15441->arg));
            } 
          if (v_and == CFALSE) Result =CFALSE; 
          else Result = CTRUE;} 
        } 
      } 
    else Result = CFALSE;
      GC_UNBIND; return (Result);} 
  } 

ClaireType * glb_Pattern(Optimize_ClairePattern *v15440,ClaireType *v15441)
{ return (Kernel.emptySet);} 

ClaireBoolean * less_ask_Pattern(Optimize_ClairePattern *v15440,OID v15441)
{ GC_BIND;
  { ClaireBoolean *Result ;
    if (INHERIT(OWNER(v15441),Optimize._Pattern))
     { ClaireBoolean *v_and;
      { v_and = ((v15440->selector == OBJECT(Optimize_ClairePattern,v15441)->selector) ? CTRUE : CFALSE);
        if (v_and == CFALSE) Result =CFALSE; 
        else { v_and = ((v15440->arg->length == OBJECT(Optimize_ClairePattern,v15441)->arg->length) ? CTRUE : CFALSE);
          if (v_and == CFALSE) Result =CFALSE; 
          else { { OID  v15552;
              { Cint  v15425 = 1;
                Cint  v14879 = v15440->arg->length;
                { OID gc_local;
                  v15552= _oid_(CFALSE);
                  while ((v15425 <= v14879))
                  { GC_LOOP;
                    if (_equaltype_ask_any(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*(v15440->arg))[v15425])),GC_OBJECT(ClaireType,OBJECT(ClaireType,(*(OBJECT(Optimize_ClairePattern,v15441)->arg))[v15425]))) != CTRUE)
                     { v15552 = Kernel.ctrue;
                      break;} 
                    ++v15425;
                    GC_UNLOOP;} 
                  } 
                } 
              v_and = not_any(v15552);
              } 
            if (v_and == CFALSE) Result =CFALSE; 
            else Result = CTRUE;} 
          } 
        } 
      } 
    else Result = OBJECT(ClaireBoolean,(*Core._inf_equalt)(_oid_(Language._Call),
        v15441));
      GC_UNBIND; return (Result);} 
  } 

ClaireBoolean * less_ask_any(OID v15440,Optimize_ClairePattern *v15441)
{ GC_BIND;
  { ClaireBoolean *Result ;
    if (INHERIT(OWNER(v15440),Optimize._Pattern))
     { ClaireBoolean *v_and;
      { v_and = ((OBJECT(Optimize_ClairePattern,v15440)->selector == v15441->selector) ? CTRUE : CFALSE);
        if (v_and == CFALSE) Result =CFALSE; 
        else { v_and = ((OBJECT(Optimize_ClairePattern,v15440)->arg->length == v15441->arg->length) ? CTRUE : CFALSE);
          if (v_and == CFALSE) Result =CFALSE; 
          else { { OID  v1090;
              { Cint  v15425 = 1;
                Cint  v14881 = OBJECT(Optimize_ClairePattern,v15440)->arg->length;
                { OID gc_local;
                  v1090= _oid_(CFALSE);
                  while ((v15425 <= v14881))
                  { GC_LOOP;
                    if (_equaltype_ask_any(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*(OBJECT(Optimize_ClairePattern,v15440)->arg))[v15425])),GC_OBJECT(ClaireType,OBJECT(ClaireType,(*(v15441->arg))[v15425]))) != CTRUE)
                     { v1090 = Kernel.ctrue;
                      break;} 
                    ++v15425;
                    GC_UNLOOP;} 
                  } 
                } 
              v_and = not_any(v1090);
              } 
            if (v_and == CFALSE) Result =CFALSE; 
            else Result = CTRUE;} 
          } 
        } 
      } 
    else Result = CFALSE;
      GC_UNBIND; return (Result);} 
  } 

Optimize_ClairePattern * nth_property(property *v15432,tuple *v15440)
{ GC_BIND;
  { Optimize_ClairePattern *Result ;
    { Optimize_ClairePattern * v10264 = ((Optimize_ClairePattern *) GC_OBJECT(Optimize_ClairePattern,new_object_class(Optimize._Pattern)));
      (v10264->selector = v15432);
      (v10264->arg = list_I_tuple(v15440));
      add_I_property(Kernel.instances,Optimize._Pattern,11,_oid_(v10264));
      Result = v10264;
      } 
    GC_UNBIND; return (Result);} 
  } 

void  warn_void()
{ GC_BIND;
  if (Optimize.OPT->in_method != CNULL)
   tformat_string(CSTRING("---- WARNING[in ~S]: "),2,list::alloc(1,GC_OID(Optimize.OPT->in_method)));
  else tformat_string(CSTRING("---- WARNING: "),2,list::empty());
    GC_UNBIND;} 

void  Cerror_string(char *v15435,listargs *v15428)
{ GC_BIND;
  princ_string(CSTRING("---- Compiler Error[in "));
  print_any(GC_OID(Optimize.OPT->in_method));
  princ_string(CSTRING("]:\n"));
  princ_string(CSTRING("---- file read up to line "));
  princ_integer(Reader.reader->nb_line);
  princ_string(CSTRING("\n"));
  close_exception(((general_error *) (*Core._general_error)(_string_(v15435),
    _oid_(v15428))));
  GC_UNBIND;} 

void  notice_void()
{ if (Optimize.OPT->in_method != CNULL)
   ;} 

OID  c_warn_Call(Call *v9332,OID v1207)
{ GC_BIND;
  { OID Result = 0;
    { property * v15435 = v9332->selector;
      if (v1207 == _oid_(Kernel._void))
       (*Optimize.Cerror)(_string_(CSTRING("[205] message ~S sent to void object")),
        _oid_(v9332));
      else if ((boolean_I_any(_oid_(v15435->restrictions)) != CTRUE) && 
          (contain_ask_set(Optimize.OPT->ignore,_oid_(v15435)) != CTRUE))
       { warn_void();
        tformat_string(CSTRING("the property ~S is undefined [255]\n"),2,list::alloc(1,_oid_(v15435)));
        } 
      else if ((contain_ask_set(Optimize.OPT->ignore,_oid_(v15435)) != CTRUE) && 
          (((v15435->open <= 1) || 
              (v15435->open == 4)) && 
            ((INHERIT(OWNER(v1207),Kernel._list)) && (class_I_type(OBJECT(ClaireType,(*(OBJECT(bag,v1207)))[1]))->open != 3))))
       { warn_void();
        tformat_string(CSTRING("wrongly typed message ~S (~S) [256]\n"),2,list::alloc(2,_oid_(v9332),v1207));
        } 
      else if (Optimize.compiler->optimize_ask == CTRUE)
       { notice_void();
        ;} 
      Result = _oid_(open_message_property(v9332->selector,GC_OBJECT(list,v9332->args)));
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_warn_Super(Super *v9332,OID v1207)
{ GC_BIND;
  { OID Result = 0;
    { property * v15435 = v9332->selector;
      if (v1207 == _oid_(Kernel._void))
       (*Optimize.Cerror)(_string_(CSTRING("[205] message ~S sent to void object")),
        _oid_(v9332));
      else if (boolean_I_any(_oid_(v15435->restrictions)) != CTRUE)
       { warn_void();
        tformat_string(CSTRING("the property ~S is undefined [255]\n"),2,list::alloc(1,_oid_(v15435)));
        } 
      else if ((contain_ask_set(Optimize.OPT->ignore,_oid_(v15435)) != CTRUE) && 
          (v15435->open <= 1))
       ;{ Call * v15429 = GC_OBJECT(Call,open_message_property(v9332->selector,GC_OBJECT(list,v9332->args)));
        Super * v10264 = ((Super *) GC_OBJECT(Super,new_object_class(Language._Super)));
        (v10264->selector = v15429->selector);
        (v10264->cast_to = v9332->cast_to);
        (v10264->args = v15429->args);
        add_I_property(Kernel.instances,Language._Super,11,_oid_(v10264));
        Result = _oid_(v10264);
        } 
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_warn_property(property *v9332,list *v15428,list *v1207)
{ if ((v9332->open <= 1) && 
      ((contain_ask_set(Optimize.OPT->ignore,_oid_(v9332)) != CTRUE) && 
        (Optimize.compiler->safety > 1)))
   ;return (_oid_(open_message_property(v9332,v15428)));} 

OID  c_warn_Variable(Variable *v9332,OID v15440,ClaireType *v15441)
{ GC_BIND;
  if (boolean_I_any((*Kernel._exp)(_oid_(v15441),
    GC_OID(_oid_(v9332->range)))) != CTRUE)
   { if (Optimize.compiler->safety > 4)
     { warn_void();
      tformat_string(CSTRING("~S of type ~S is put in the variable ~S:~S [257]\n"),2,list::alloc(4,v15440,
        _oid_(v15441),
        _oid_(v9332),
        GC_OID(_oid_(v9332->range))));
      } 
    else (*Optimize.Cerror)(_string_(CSTRING("[212] the value ~S of type ~S cannot be placed in the variable ~S:~S")),
        v15440,
        _oid_(v15441),
        _oid_(v9332),
        GC_OID(_oid_(v9332->range)));
      } 
  else if ((Optimize.compiler->safety <= 1) || 
      (boolean_I_any(sort_equal_class(osort_any(_oid_(v9332->range)),osort_any(_oid_(v15441)))) != CTRUE))
   { warn_void();
    tformat_string(CSTRING("~S of type ~S is put in the variable ~S:~S [257]\n"),2,list::alloc(4,v15440,
      _oid_(v15441),
      _oid_(v9332),
      GC_OID(_oid_(v9332->range))));
    } 
  { OID Result = 0;
    if ((Optimize.compiler->safety <= 1) && 
        (_inf_equal_type(v15441,GC_OBJECT(ClaireType,v9332->range)) != CTRUE))
     Result = c_check_any(GC_OID((*Optimize.c_code)(v15440,
      _oid_(Kernel._any))),GC_OID((*Optimize.c_code)(GC_OID(_oid_(v9332->range)),
      _oid_(Kernel._type))));
    else Result = v15440;
      GC_UNBIND; return (Result);} 
  } 

OID  sort_equal_class(ClaireClass *v15419,ClaireClass *v2903)
{ { OID Result = 0;
    if (INHERIT(v15419,Kernel._object))
     Result = _oid_(inherit_ask_class(v2903,Kernel._object));
    else Result = _oid_(((v15419 == v2903) ? CTRUE : ((((Optimize.compiler->overflow_ask != CTRUE) && 
            ((v15419 == Kernel._any) && 
                (v2903 == Kernel._integer))) || 
          ((v15419 == Kernel._integer) && 
              (v2903 == Kernel._any))) ? CTRUE : CFALSE)));
      return (Result);} 
  } 

ClaireClass * psort_any(OID v15440)
{ { ClaireClass *Result ;
    { ClaireClass * v15419 = class_I_type(OBJECT(ClaireType,v15440));
      Result = ((INHERIT(v15419,Kernel._object)) ?
        v15419 :
        ((v15419 == Kernel._float) ?
          v15419 :
          sort_I_class(v15419) ) );
      } 
    return (Result);} 
  } 

ClaireClass * osort_any(OID v15440)
{ { ClaireClass *Result ;
    { ClaireClass * v15419 = class_I_type(OBJECT(ClaireType,v15440));
      Result = ((v15419 == Kernel._float) ?
        v15419 :
        sort_I_class(v15419) );
      } 
    return (Result);} 
  } 

ClaireClass * sort_Variable(Variable *v15440)
{ { ClaireClass *Result ;
    { ClaireType * v15434 = v15440->range;
      Result = (((INHERIT(v15434->isa,Core._Union)) && (equal(_oid_(CLREAD(Union,v15434,t1)),_oid_(Kernel.emptySet)) == CTRUE)) ?
        psort_any(_oid_(CLREAD(Union,CLREAD(Union,v15434,t2),t2))) :
        psort_any(_oid_(v15434)) );
      } 
    return (Result);} 
  } 

ClaireClass * stupid_t_any1(OID v9332)
{ GC_BIND;
  { ClaireClass *Result ;
    if (INHERIT(OWNER(v9332),Language._Variable))
     { ClaireType * v15434 = GC_OBJECT(ClaireType,OBJECT(Variable,v9332)->range);
      Result = ((sort_abstract_ask_type(v15434) == CTRUE) ?
        Kernel._any :
        (((INHERIT(v15434->isa,Core._Union)) && (equal(_oid_(CLREAD(Union,v15434,t1)),_oid_(Kernel.emptySet)) == CTRUE)) ?
          OBJECT(ClaireClass,(*Core.t1)(GC_OID(_oid_(CLREAD(Union,v15434,t2))))) :
          class_I_type(v15434) ) );
      } 
    else if (INHERIT(OWNER(v9332),Core._global_variable))
     { ClaireType * v15434 = OBJECT(global_variable,v9332)->range;
      Result = ((boolean_I_any(_oid_(v15434)) == CTRUE) ?
        class_I_type(v15434) :
        OWNER(OBJECT(global_variable,v9332)->value) );
      } 
    else if (INHERIT(OWNER(v9332),Language._And))
     Result = Kernel._boolean;
    else if (INHERIT(OWNER(v9332),Kernel._bag))
     Result = OWNER(v9332);
    else if (INHERIT(OWNER(v9332),Kernel._environment))
     Result = Kernel._environment;
    else if (INHERIT(OWNER(v9332),Kernel._class))
     Result = Kernel._class;
    else if (INHERIT(OWNER(v9332),Language._Call_slot))
     { slot * v15435 = OBJECT(Call_slot,v9332)->selector;
      property * v15432 = v15435->selector;
      { ITERATE(v3399);
        for (START(v15432->definition); NEXT(v3399);)
        if (Kernel._slot == OBJECT(ClaireObject,v3399)->isa)
         { if (_inf_equal_type(domain_I_restriction(v15435),domain_I_restriction(OBJECT(restriction,v3399))) == CTRUE)
           v15435= OBJECT(slot,v3399);
          } 
        } 
      Result = class_I_type(v15435->range);
      } 
    else if (INHERIT(OWNER(v9332),Language._Call_method))
     Result = class_I_type(OBJECT(Call_method,v9332)->arg->range);
    else if (INHERIT(OWNER(v9332),Language._Call))
     Result = selector_psort_Call(OBJECT(Call,v9332));
    else if (INHERIT(OWNER(v9332),Optimize._to_C))
     Result = OBJECT(Compile_to_C,v9332)->set_arg;
    else if (INHERIT(OWNER(v9332),Optimize._to_protect))
     Result = stupid_t_any1(GC_OID(OBJECT(Compile_to_protect,v9332)->arg));
    else if (INHERIT(OWNER(v9332),Kernel._symbol))
     Result = OWNER(v9332);
    else if (INHERIT(OWNER(v9332),Kernel._char))
     Result = OWNER(v9332);
    else if (Kernel._boolean == OWNER(v9332))
     Result = OWNER(v9332);
    else if (INHERIT(OWNER(v9332),Kernel._primitive))
     Result = OWNER(v9332);
    else if (INHERIT(OWNER(v9332),Language._Assign))
     Result = stupid_t_any1(GC_OID(OBJECT(Assign,v9332)->arg));
    else if (INHERIT(OWNER(v9332),Language._Let))
     Result = stupid_t_any1(GC_OID(OBJECT(Let,v9332)->arg));
    else if (INHERIT(OWNER(v9332),Language._Do))
     Result = stupid_t_any1(GC_OID(last_list(OBJECT(Do,v9332)->args)));
    else if (INHERIT(OWNER(v9332),Language._If))
     Result = meet_class(stupid_t_any1(GC_OID(OBJECT(If,v9332)->arg)),stupid_t_any1(GC_OID(OBJECT(If,v9332)->other)));
    else if (INHERIT(OWNER(v9332),Language._Collect))
     Result = Kernel._list;
    else if (INHERIT(OWNER(v9332),Language._Image))
     Result = Kernel._set;
    else if (INHERIT(OWNER(v9332),Language._Or))
     Result = Kernel._boolean;
    else if (INHERIT(OWNER(v9332),Language._Select))
     Result = Kernel._set;
    else if (INHERIT(OWNER(v9332),Language._Lselect))
     Result = Kernel._list;
    else if (INHERIT(OWNER(v9332),Language._List))
     Result = Kernel._list;
    else if (INHERIT(OWNER(v9332),Language._Set))
     Result = Kernel._set;
    else Result = ((INHERIT(OWNER(v9332),Kernel._thing)) ?
      OWNER(v9332) :
      ((INHERIT(OWNER(v9332),Language._Tuple)) ?
        Kernel._tuple :
        ((INHERIT(OWNER(v9332),Language._Exists)) ?
          ((OBJECT(Exists,v9332)->other == CNULL) ?
            Kernel._any :
            Kernel._boolean ) :
          ((INHERIT(OWNER(v9332),Kernel._integer)) ?
            Kernel._integer :
            Kernel._any ) ) ) );
    GC_UNBIND; return (Result);} 
  } 

ClaireBoolean * stupid_t_any2(OID v9332,OID v15440)
{ { ClaireBoolean *Result ;
    { ClaireClass * v2904 = stupid_t_any1(v9332);
      ClaireClass * v2903 = stupid_t_any1(v15440);
      Result = ((v2904 != Kernel._any) ? ((v2904 == v2903) ? CTRUE: CFALSE): CFALSE);
      } 
    return (Result);} 
  } 

ClaireBoolean * extended_ask_type(ClaireType *v9332)
{ { ClaireBoolean *Result ;
    Result = ((INHERIT(v9332->isa,Core._Union)) ?
      ((Kernel._set == CLREAD(Union,v9332,t2)->isa) ? ((boolean_I_any(_oid_(CLREAD(Union,v9332,t2))) == CTRUE) ? (((*(((bag *) CLREAD(Union,v9332,t2))))[1] == CNULL) ? CTRUE: CFALSE): CFALSE): CFALSE) :
      CFALSE );
    return (Result);} 
  } 

ClaireType * extends_type(ClaireType *v15440)
{ GC_BIND;
  { ClaireType *Result ;
    { Optimize_optUnion * v10264 = ((Optimize_optUnion *) GC_OBJECT(Optimize_optUnion,new_object_class(Optimize._optUnion)));
      (v10264->t1 = v15440);
      (v10264->t2 = set::alloc(Kernel.emptySet,1,CNULL));
      Result = v10264;
      } 
    GC_UNBIND; return (Result);} 
  } 

ClaireType * sort_abstract_I_type(ClaireType *v15440)
{ GC_BIND;
  { ClaireType *Result ;
    if (((_oid_((INHERIT(v15440->isa,Kernel._class) ? (ClaireObject *) sort_I_class((ClaireClass *) OBJECT(ClaireClass,_oid_(v15440))) :  (ClaireObject *)  sort_I_type((ClaireType *) OBJECT(ClaireType,_oid_(v15440))))) != _oid_(Kernel._any)) && 
          ((_oid_((INHERIT(v15440->isa,Kernel._class) ? (ClaireObject *) sort_I_class((ClaireClass *) OBJECT(ClaireClass,_oid_(v15440))) :  (ClaireObject *)  sort_I_type((ClaireType *) OBJECT(ClaireType,_oid_(v15440))))) != _oid_(Kernel._integer)) || 
              (Optimize.compiler->overflow_ask == CTRUE))) || 
        (v15440 == Kernel._float))
     { Union * v10264 = ((Union *) GC_OBJECT(Union,new_object_class(Core._Union)));
      (v10264->t1 = Kernel._any);
      (v10264->t2 = v15440);
      Result = v10264;
      } 
    else Result = v15440;
      GC_UNBIND; return (Result);} 
  } 

ClaireBoolean * sort_abstract_ask_type(ClaireType *v15440)
{ { ClaireBoolean *Result ;
    Result = ((INHERIT(v15440->isa,Core._Union)) ?
      equal(_oid_(CLREAD(Union,v15440,t1)),_oid_(Kernel._any)) :
      CFALSE );
    return (Result);} 
  } 

ClaireType * ptype_type(ClaireType *v15440)
{ { ClaireType *Result ;
    Result = ((INHERIT(v15440->isa,Core._Union)) ?
      ((CLREAD(Union,v15440,t1) == Kernel._any) ?
        CLREAD(Union,v15440,t2) :
        v15440 ) :
      v15440 );
    return (Result);} 
  } 

ClaireType * pmember_type(ClaireType *v15440)
{ GC_BIND;
  { ClaireType *Result ;
    Result = member_type(GC_OBJECT(ClaireType,ptype_type(v15440)));
    GC_UNBIND; return (Result);} 
  } 

OID  enumerate_code_any(OID v9332,ClaireType *v1047)
{ GC_BIND;
  { OID Result = 0;
    if (_inf_equal_type(GC_OBJECT(ClaireType,ptype_type(v1047)),Kernel._bag) == CTRUE)
     Result = c_strict_code_any(v9332,Kernel._bag);
    else { if (Optimize.compiler->optimize_ask == CTRUE)
         { notice_void();
          ;} 
        Result = c_code_method_method1(GC_OBJECT(method,((method *) _at_property1(Core.enumerate,Kernel._any))),list::alloc(1,v9332),list::alloc(1,_oid_(v1047)));
        } 
      GC_UNBIND; return (Result);} 
  } 

OID  range_infers_for_Variable(Variable *v9332,ClaireType *v15441,ClaireType *v3495)
{ GC_BIND;
  if (v9332->range == (NULL))
   { if (INHERIT(v15441->isa,Core._Interval))
     v15441= Kernel._integer;
    (v9332->range = v15441);
    } 
  else if ((_inf_equal_type(v15441,GC_OBJECT(ClaireType,v9332->range)) != CTRUE) && 
      (Optimize.compiler->safety <= 1))
   { if (((boolean_I_any(_oid_(v15441)) == CTRUE) ? ((boolean_I_any(_oid_(v9332->range)) == CTRUE) ? CTRUE: CFALSE): CFALSE) != CTRUE)
     { warn_void();
      tformat_string(CSTRING("range of variable in ~S is wrong [258]\n"),2,list::alloc(1,_oid_(v9332)));
      } 
    } 
  { OID Result = 0;
    if ((sort_Variable(v9332) != Kernel._any) && 
        (((sort_Variable(v9332) != Kernel._integer) || 
            (Optimize.compiler->overflow_ask == CTRUE)) && 
          (((_inf_equal_type(v3495,Kernel._array) == CTRUE) ? ((_inf_equal_type(v15441,Kernel._float) == CTRUE) ? CTRUE: CFALSE): CFALSE) != CTRUE)))
     { Result = _void_((v9332->range = sort_abstract_I_type(GC_OBJECT(ClaireType,v9332->range))));
      } 
    else Result = Kernel.cfalse;
      GC_UNBIND; return (Result);} 
  } 

OID  range_infers_Variable(Variable *v9332,ClaireType *v15441)
{ gc_register_Variable(v9332);
  { OID Result = 0;
    if ((v9332->range == (NULL)) || 
        ((extended_ask_type(v9332->range) == CTRUE) && 
            (INHERIT(v9332->range->isa,Optimize._optUnion))))
     { if (Kernel._set == v15441->isa)
       Result = _void_((v9332->range = class_I_type(v15441)));
      else Result = _void_((v9332->range = v15441));
        } 
    else Result = Kernel.cfalse;
      return (Result);} 
  } 

void  range_infer_case_any(OID v9332,ClaireType *v15441)
{ GC_BIND;
  if (INHERIT(OWNER(v9332),Language._Variable))
   { if (boolean_I_any(sort_equal_class(osort_any(_oid_(OBJECT(Variable,v9332)->range)),osort_any(_oid_(v15441)))) == CTRUE)
     { ClaireClass * v2904 = psort_any(_oid_(class_I_type(OBJECT(Variable,v9332)->range)));
      if (v2904 != psort_any(_oid_(class_I_type(v15441))))
       { Variable * v14883 = OBJECT(Variable,v9332); 
        ClaireType * v14885;
        { Union * v10264 = ((Union *) GC_OBJECT(Union,new_object_class(Core._Union)));
          (v10264->t1 = Kernel.emptySet);
          { Union * v14886 = v10264; 
            ClaireType * v14907;
            { Union * v10264 = ((Union *) GC_OBJECT(Union,new_object_class(Core._Union)));
              (v10264->t1 = v2904);
              (v10264->t2 = v15441);
              v14907 = v10264;
              } 
            (v14886->t2 = v14907);} 
          v14885 = v10264;
          } 
        (v14883->range = v14885);} 
      else (OBJECT(Variable,v9332)->range = v15441);
        } 
    else if (osort_any(_oid_(OBJECT(Variable,v9332)->range)) == Kernel._any)
     (OBJECT(Variable,v9332)->range = sort_abstract_I_type(v15441));
    } 
  GC_UNBIND;} 

OID  c_check_any(OID v15440,OID v15441)
{ GC_BIND;
  { OID Result = 0;
    { method * v15429 = ((method *) _at_property1(Core.check_in,Kernel._any));
      if (Optimize.compiler->safety > 3)
       Result = v15440;
      else { legal_ask_module(v15429->module_I,_oid_(v15429));
          { Call_method2 * v10264 = ((Call_method2 *) GC_OBJECT(Call_method2,new_object_class(Language._Call_method2)));
            (v10264->arg = v15429);
            (v10264->args = list::alloc(2,GC_OID(c_gc_I_any1(v15440)),GC_OID(c_gc_I_any1(v15441))));
            add_I_property(Kernel.instances,Language._Call_method2,11,_oid_(v10264));
            Result = _oid_(v10264);
            } 
          } 
        } 
    GC_UNBIND; return (Result);} 
  } 

void  range_sets_any(OID v9332,ClaireType *v15441)
{ GC_BIND;
  if (INHERIT(OWNER(v9332),Language._Variable))
   { if (boolean_I_any(sort_equal_class(osort_any(_oid_(OBJECT(Variable,v9332)->range)),osort_any(_oid_(v15441)))) == CTRUE)
     { ClaireClass * v2904 = psort_any(_oid_(class_I_type(OBJECT(Variable,v9332)->range)));
      if (v2904 != psort_any(_oid_(class_I_type(v15441))))
       { Variable * v14908 = OBJECT(Variable,v9332); 
        ClaireType * v14909;
        { Union * v10264 = ((Union *) GC_OBJECT(Union,new_object_class(Core._Union)));
          (v10264->t1 = Kernel.emptySet);
          { Union * v14911 = v10264; 
            ClaireType * v14912;
            { Union * v10264 = ((Union *) GC_OBJECT(Union,new_object_class(Core._Union)));
              (v10264->t1 = v2904);
              (v10264->t2 = v15441);
              v14912 = v10264;
              } 
            (v14911->t2 = v14912);} 
          v14909 = v10264;
          } 
        (v14908->range = v14909);} 
      else (OBJECT(Variable,v9332)->range = v15441);
        } 
    else if (osort_any(_oid_(OBJECT(Variable,v9332)->range)) == Kernel._any)
     (OBJECT(Variable,v9332)->range = sort_abstract_I_type(v15441));
    } 
  GC_UNBIND;} 

ClaireClass * c_srange_method(method *v15429)
{ { ClaireClass *Result ;
    Result = ((v15429->range == Kernel._float) ?
      Kernel._float :
      OBJECT(ClaireClass,last_list(v15429->srange)) );
    return (Result);} 
  } 

ClaireBoolean * nativeVar_ask_global_variable(global_variable *v15440)
{ return (((Optimize.compiler->optimize_ask == CTRUE) ? ((v15440->store_ask == CFALSE) ? ((v15440->name->module_I == v15440->name->definition) ? (((OBJECT(ClaireBoolean,_oid_((INHERIT(v15440->range->isa,Kernel._class) ? (ClaireObject *) gcsafe_ask_class((ClaireClass *) OBJECT(ClaireClass,_oid_(v15440->range))) :  (ClaireObject *)  gcsafe_ask_type((ClaireType *) OBJECT(ClaireType,_oid_(v15440->range))))))) == CTRUE) ? CTRUE: CFALSE): CFALSE): CFALSE): CFALSE));} 

ClaireType * return_type_any(OID v9332)
{ GC_RESERVE(1);  // HOHO v3.0.55 optim !
  { ClaireType *Result ;
    if (INHERIT(OWNER(v9332),Optimize._to_C))
     Result = return_type_any(GC_OID(OBJECT(Compile_to_C,v9332)->arg));
    else if (INHERIT(OWNER(v9332),Optimize._to_protect))
     Result = return_type_any(GC_OID(OBJECT(Compile_to_protect,v9332)->arg));
    else if (INHERIT(OWNER(v9332),Language._Let))
     Result = return_type_any(GC_OID(OBJECT(Let,v9332)->arg));
    else if (INHERIT(OWNER(v9332),Language._Do))
     { set * v15440 = Kernel.emptySet;
      { OID gc_local;
        ITERATE(v15441);
        bag *v15441_support;
        v15441_support = GC_OBJECT(list,OBJECT(Do,v9332)->args);
        for (START(v15441_support); NEXT(v15441);)
        { GC_LOOP;
          GC__ANY(v15440 = OBJECT(set,(*Kernel._exp)(_oid_(v15440),
            GC_OID(_oid_(return_type_any(v15441))))), 1);
          GC_UNLOOP;} 
        } 
      Result = v15440;
      } 
    else if (INHERIT(OWNER(v9332),Language._If))
     Result = OBJECT(ClaireType,(*Kernel._exp)(GC_OID(_oid_(return_type_any(GC_OID(OBJECT(If,v9332)->arg)))),
      GC_OID(_oid_(return_type_any(GC_OID(OBJECT(If,v9332)->other))))));
    else if (INHERIT(OWNER(v9332),Language._Return))
     Result = OBJECT(ClaireType,(*Optimize.c_type)(GC_OID(OBJECT(Return,v9332)->arg)));
    else if (INHERIT(OWNER(v9332),Language._Case))
     { set * v15440 = Kernel.emptySet;
      { OID gc_local;
        ITERATE(v15441);
        bag *v15441_support;
        v15441_support = GC_OBJECT(list,OBJECT(Case,v9332)->args);
        for (START(v15441_support); NEXT(v15441);)
        { GC_LOOP;
          GC__ANY(v15440 = OBJECT(set,(*Kernel._exp)(_oid_(v15440),
            GC_OID(_oid_(return_type_any(v15441))))), 1);
          GC_UNLOOP;} 
        } 
      Result = v15440;
      } 
    else if (INHERIT(OWNER(v9332),Language._Handle))
     Result = return_type_any(GC_OID(OBJECT(ClaireHandle,v9332)->arg));
    else Result = Kernel.emptySet;
      GC_UNBIND; return (Result);} 
  } 

OID  c_code_Type_Optimize(Type *v9332,ClaireClass *v15435)
{ GC_BIND;
  { OID Result = 0;
    Result = (*Optimize.c_code)(GC_OID((*Optimize.self_code)(_oid_(v9332))),
      _oid_(v15435));
    GC_UNBIND; return (Result);} 
  } 

OID  self_code_subtype(subtype *v9332)
{ GC_BIND;
  { OID Result = 0;
    { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
      (v10264->selector = Kernel.nth);
      (v10264->args = list::alloc(2,_oid_(v9332->arg),GC_OID((*Optimize.c_code)(GC_OID(_oid_(v9332->t1)),
        _oid_(Kernel._type)))));
      add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
      Result = _oid_(v10264);
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  self_code_Param(Param *v9332)
{ GC_BIND;
  { OID Result = 0;
    if ((v9332->params->length == 1) && 
        (((*(v9332->params))[1] == _oid_(Kernel.of)) && 
          (Kernel._set == OWNER((*(v9332->args))[1]))))
     { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
      (v10264->selector = Core.param_I);
      (v10264->args = list::alloc(2,_oid_(v9332->arg),GC_OID((*Optimize.c_code)(GC_OID((*Kernel.nth)(GC_OID((*(v9332->args))[1]),
          1)),
        _oid_(Kernel._type)))));
      add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
      Result = _oid_(v10264);
      } 
    else { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
        (v10264->selector = Kernel.nth);
        { Call * v14913 = v10264; 
          list * v14914;
          { OID v_bag;
            GC_ANY(v14914= list::empty(Kernel.emptySet));
            ((list *) v14914)->addFast(_oid_(v9332->arg));
            ((list *) v14914)->addFast(GC_OID(_oid_(v9332->params)));
            { { list * v157;{ bag *v_list; OID v_val;
                  OID v15441,CLcount;
                  v_list = GC_OBJECT(list,v9332->args);
                   v157 = v_list->clone();
                  for (CLcount= 1; CLcount <= v_list->length; CLcount++)
                  { v15441 = (*(v_list))[CLcount];
                    v_val = (*Optimize.c_code)(v15441,
                      _oid_(Kernel._type));
                    
                    (*((list *) v157))[CLcount] = v_val;} 
                  } 
                
                v_bag=_oid_(v157);} 
              GC_OID(v_bag);} 
            ((list *) v14914)->addFast(v_bag);} 
          (v14913->args = v14914);} 
        add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
        Result = _oid_(v10264);
        } 
      GC_UNBIND; return (Result);} 
  } 

OID  self_code_Union(Union *v9332)
{ GC_BIND;
  { OID Result = 0;
    { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
      (v10264->selector = Core.U);
      (v10264->args = list::alloc(2,GC_OID((*Optimize.c_code)(GC_OID(_oid_(v9332->t1)),
        _oid_(Kernel._type))),GC_OID((*Optimize.c_code)(GC_OID(_oid_(v9332->t2)),
        _oid_(Kernel._type)))));
      add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
      Result = _oid_(v10264);
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  self_code_Interval(Interval *v9332)
{ GC_BIND;
  { OID Result = 0;
    { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
      (v10264->selector = Kernel._dot_dot);
      (v10264->args = list::alloc(2,v9332->arg1,v9332->arg2));
      add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
      Result = _oid_(v10264);
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  self_code_Reference(Reference *v9332)
{ GC_BIND;
  { OID Result = 0;
    { Definition * v10264 = ((Definition *) GC_OBJECT(Definition,new_object_class(Language._Definition)));
      (v10264->arg = Core._Reference);
      { Definition * v14915 = v10264; 
        list * v14916;
        { OID v_bag;
          GC_ANY(v14916= list::empty(Kernel.emptySet));
          { { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
              (v10264->selector = Kernel._equal);
              (v10264->args = list::alloc(2,_oid_(Core.args),GC_OID(_oid_(v9332->args))));
              add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
              v_bag = _oid_(v10264);
              } 
            GC_OID(v_bag);} 
          ((list *) v14916)->addFast(v_bag);
          { { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
              (v10264->selector = Kernel._equal);
              (v10264->args = list::alloc(2,_oid_(Kernel.index),v9332->index));
              add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
              v_bag = _oid_(v10264);
              } 
            GC_OID(v_bag);} 
          ((list *) v14916)->addFast(v_bag);
          { { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
              (v10264->selector = Kernel._equal);
              (v10264->args = list::alloc(2,_oid_(Kernel.arg),_oid_(v9332->arg)));
              add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
              v_bag = _oid_(v10264);
              } 
            GC_OID(v_bag);} 
          ((list *) v14916)->addFast(v_bag);} 
        (v14915->args = v14916);} 
      add_I_property(Kernel.instances,Language._Definition,11,_oid_(v10264));
      Result = _oid_(v10264);
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  self_code_Pattern(Optimize_ClairePattern *v9332)
{ GC_BIND;
  { OID Result = 0;
    if (Optimize.compiler->inline_ask == CTRUE)
     { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
      (v10264->selector = Kernel.nth);
      { Call * v14938 = v10264; 
        list * v14939;
        { OID v_bag;
          GC_ANY(v14939= list::empty(Kernel.emptySet));
          ((list *) v14939)->addFast(_oid_(v9332->selector));
          { { Tuple * v10264 = ((Tuple *) GC_OBJECT(Tuple,new_object_class(Language._Tuple)));
              (v10264->args = v9332->arg);
              add_I_property(Kernel.instances,Language._Tuple,11,_oid_(v10264));
              v_bag = _oid_(v10264);
              } 
            GC_OID(v_bag);} 
          ((list *) v14939)->addFast(v_bag);} 
        (v14938->args = v14939);} 
      add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
      Result = _oid_(v10264);
      } 
    else Result = _oid_(Language._Call);
      GC_UNBIND; return (Result);} 
  } 

OID  member_code_class2(ClaireClass *v9332,OID v15440)
{ GC_BIND;
  { OID Result = 0;
    { Call * v16313;
      { { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
          (v10264->selector = ((_inf_equal_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(v15440))),Kernel._object) == CTRUE) ?
            Kernel.isa :
            Core.owner ));
          (v10264->args = list::alloc(1,v15440));
          add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
          v16313 = v10264;
          } 
        GC_OBJECT(Call,v16313);} 
      if (((v9332->open <= -1) || 
            (v9332->open == 1)) && 
          (boolean_I_any(_oid_(v9332->subclass)) != CTRUE))
       { OID  v7676;
        { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
          (v10264->selector = Kernel._equal);
          (v10264->args = list::alloc(2,_oid_(v9332),_oid_(v16313)));
          add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
          v7676 = _oid_(v10264);
          } 
        Result = (*Optimize.c_code)(v7676);
        } 
      else { OID  v8637;
          { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
            (v10264->selector = Core.inherit_ask);
            (v10264->args = list::alloc(2,_oid_(v16313),_oid_(v9332)));
            add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
            v8637 = _oid_(v10264);
            } 
          Result = (*Optimize.c_code)(v8637);
          } 
        } 
    GC_UNBIND; return (Result);} 
  } 

OID  member_code_Type(Type *v9332,OID v15440)
{ GC_BIND;
  { OID Result = 0;
    { Call_method2 * v10264 = ((Call_method2 *) GC_OBJECT(Call_method2,new_object_class(Language._Call_method2)));
      update_property(Kernel.arg,
        v10264,
        2,
        Kernel._object,
        GC_OID(_oid_(_at_property2(Kernel._Z,list::alloc(2,_oid_(Kernel._any),_oid_(Kernel._any))))));
      (v10264->args = list::alloc(2,GC_OID((*Optimize.c_code)(v15440,
        _oid_(Kernel._any))),GC_OID((*Optimize.c_code)(_oid_(v9332),
        _oid_(Kernel._any)))));
      add_I_property(Kernel.instances,Language._Call_method2,11,_oid_(v10264));
      Result = _oid_(v10264);
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  member_code_Union(Union *v9332,OID v15440)
{ GC_BIND;
  { OID Result = 0;
    { Or * v10264 = ((Or *) GC_OBJECT(Or,new_object_class(Language._Or)));
      (v10264->args = list::alloc(2,GC_OID((*Optimize.member_code)(GC_OID(_oid_(v9332->t1)),
        v15440)),GC_OID((*Optimize.member_code)(GC_OID(_oid_(v9332->t2)),
        v15440))));
      add_I_property(Kernel.instances,Language._Or,11,_oid_(v10264));
      Result = _oid_(v10264);
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  member_code_Interval(Interval *v9332,OID v15440)
{ GC_BIND;
  { OID Result = 0;
    { OID  v9598;
      { And * v10264 = ((And *) GC_OBJECT(And,new_object_class(Language._And)));
        { And * v14943 = v10264; 
          list * v14944;
          { OID v_bag;
            GC_ANY(v14944= list::empty(Kernel.emptySet));
            { { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                (v10264->selector = Kernel._sup_equal);
                (v10264->args = list::alloc(2,v15440,v9332->arg1));
                add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
                v_bag = _oid_(v10264);
                } 
              GC_OID(v_bag);} 
            ((list *) v14944)->addFast(v_bag);
            { { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                (v10264->selector = Kernel._inf_equal);
                (v10264->args = list::alloc(2,v15440,v9332->arg2));
                add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
                v_bag = _oid_(v10264);
                } 
              GC_OID(v_bag);} 
            ((list *) v14944)->addFast(v_bag);} 
          (v14943->args = v14944);} 
        add_I_property(Kernel.instances,Language._And,11,_oid_(v10264));
        v9598 = _oid_(v10264);
        } 
      Result = (*Optimize.c_code)(v9598,
        _oid_(Kernel._any));
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  member_code_Param(Param *v9332,OID v15440)
{ GC_BIND;
  { OID Result = 0;
    { OID  v13442;
      { And * v10264 = ((And *) GC_OBJECT(And,new_object_class(Language._And)));
        { And * v14947 = v10264; 
          list * v14969;
          { list * v3738;
            { { OID v_bag;
                GC_ANY(v3738= list::empty(Kernel.emptySet));
                { { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                    (v10264->selector = Kernel._Z);
                    (v10264->args = list::alloc(2,v15440,_oid_(v9332->arg)));
                    add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
                    v_bag = _oid_(v10264);
                    } 
                  GC_OID(v_bag);} 
                ((list *) v3738)->addFast(v_bag);} 
              GC_OBJECT(list,v3738);} 
            list * v4699;
            { list * v7946 = list::empty(Kernel.emptySet);
              { Cint  v15425 = 1;
                Cint  v14945 = v9332->params->length;
                { OID gc_local;
                  while ((v15425 <= v14945))
                  { GC_LOOP;
                    { OID  v5660;
                      { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                        (v10264->selector = Kernel._Z);
                        { Call * v14973 = v10264; 
                          list * v14974;
                          { OID v_bag;
                            GC_ANY(v14974= list::empty(Kernel.emptySet));
                            { { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                                update_property(Kernel.selector,
                                  v10264,
                                  2,
                                  Kernel._object,
                                  GC_OID((*(v9332->params))[v15425]));
                                (v10264->args = list::alloc(1,v15440));
                                add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
                                v_bag = _oid_(v10264);
                                } 
                              GC_OID(v_bag);} 
                            ((list *) v14974)->addFast(v_bag);
                            ((list *) v14974)->addFast(GC_OID((*(v9332->args))[v15425]));} 
                          (v14973->args = v14974);} 
                        add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
                        v5660 = _oid_(v10264);
                        } 
                      v7946->addFast(v5660);
                      } 
                    ++v15425;
                    GC_UNLOOP;} 
                  } 
                } 
              v4699 = GC_OBJECT(list,v7946);
              } 
            v14969 = append_list(v3738,v4699);
            } 
          (v14947->args = v14969);} 
        add_I_property(Kernel.instances,Language._And,11,_oid_(v10264));
        v13442 = _oid_(v10264);
        } 
      Result = (*Optimize.c_code)(v13442,
        _oid_(Kernel._any));
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  member_code_tuple(tuple *v9332,OID v15440)
{ GC_BIND;
  { OID Result = 0;
    if (INHERIT(OWNER(v15440),Language._Tuple))
     { if (length_bag(OBJECT(bag,(*Core.args)(v15440))) != v9332->length)
       Result = Kernel.cfalse;
      else { OID  v9504;
          { And * v10264 = ((And *) GC_OBJECT(And,new_object_class(Language._And)));
            { And * v14977 = v10264; 
              list * v14978;
              { list * v7946 = list::empty(Kernel.emptySet);
                { Cint  v15425 = 1;
                  Cint  v14975 = v9332->length;
                  { OID gc_local;
                    while ((v15425 <= v14975))
                    { GC_LOOP;
                      { OID  v16184;
                        { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                          (v10264->selector = Kernel._Z);
                          (v10264->args = list::alloc(2,GC_OID((*(OBJECT(bag,(*Core.args)(v15440))))[v15425]),(*(v9332))[v15425]));
                          add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
                          v16184 = _oid_(v10264);
                          } 
                        v7946->addFast(v16184);
                        } 
                      ++v15425;
                      GC_UNLOOP;} 
                    } 
                  } 
                v14978 = GC_OBJECT(list,v7946);
                } 
              (v14977->args = v14978);} 
            add_I_property(Kernel.instances,Language._And,11,_oid_(v10264));
            v9504 = _oid_(v10264);
            } 
          Result = (*Optimize.c_code)(v9504,
            _oid_(Kernel._any));
          } 
        } 
    else Result = c_code_method_method1(GC_OBJECT(method,((method *) _at_property2(Kernel._Z,GC_OBJECT(list,list::alloc(2,_oid_(Kernel._any),_oid_(Kernel._any)))))),GC_OBJECT(list,list::alloc(2,v15440,_oid_(v9332))),GC_OBJECT(list,list::alloc(2,_oid_(Kernel._any),_oid_(Kernel._any))));
      GC_UNBIND; return (Result);} 
  } 

OID  member_code_any(OID v9332,OID v15440)
{ GC_BIND;
  (Language.LDEF->value= Core.nil->value);
  { OID Result = 0;
    { list * v1207 = list::alloc(2,GC_OID((*Optimize.c_type)(v15440)),GC_OID((*Optimize.c_type)(v9332)));
      OID  v15434 = GC_OID(extract_pattern_any(v9332,Kernel.nil));
      { ClaireBoolean * g0071I;
        { ClaireBoolean *v_or;
          { v_or = ((v15434 == CNULL) ? CTRUE : CFALSE);
            if (v_or == CTRUE) g0071I =CTRUE; 
            else { v_or = ((v9332 == _oid_(Kernel._object)) ? CTRUE : CFALSE);
              if (v_or == CTRUE) g0071I =CTRUE; 
              else { { OID  v1722;
                  if (INHERIT(OWNER(v9332),Core._global_variable))
                   v1722 = _oid_(OBJECT(global_variable,v9332)->range);
                  else v1722 = Kernel.cfalse;
                    v_or = boolean_I_any(v1722);
                  } 
                if (v_or == CTRUE) g0071I =CTRUE; 
                else g0071I = CFALSE;} 
              } 
            } 
          } 
        
        if (g0071I == CTRUE) Result = c_code_method_method1(GC_OBJECT(method,((method *) _at_property2(Kernel._Z,v1207))),list::alloc(2,v15440,v9332),v1207);
          else Result = (*Optimize.member_code)(v15434,
          v15440);
        } 
      } 
    GC_UNBIND; return (Result);} 
  } 

ClaireBoolean * _Z_any4(OID v15440,OID v15441)
{ GC_BIND;
  { ClaireBoolean *Result ;
    Result = (((OBJECT(ClaireBoolean,(*Kernel._inf_equal)(v15440,
      GC_OID(OPT_EVAL((*(OBJECT(Call,v15441)->args))[2]))))) == CTRUE) ? (((OBJECT(ClaireBoolean,(*Kernel._inf_equal)(GC_OID(OPT_EVAL((*(OBJECT(Call,v15441)->args))[1])),
      v15440))) == CTRUE) ? CTRUE: CFALSE): CFALSE);
    GC_UNBIND; return (Result);} 
  } 

ClaireBoolean * _Z_any5(OID v15440,OID v15441)
{ GC_BIND;
  { ClaireBoolean *Result ;
    Result = ((belong_to(v15440,OPT_EVAL((*(OBJECT(Call,v15441)->args))[1])) == CTRUE) ? ((equal(v15440,OPT_EVAL((*(OBJECT(Call,v15441)->args))[2])) != CTRUE) ? CTRUE: CFALSE): CFALSE);
    GC_UNBIND; return (Result);} 
  } 

ClaireBoolean * gcsafe_ask_class(ClaireClass *v9332)
{ return (((v9332 == Kernel._void) ? CTRUE : 
  ((INHERIT(v9332,Kernel._thing)) ? CTRUE : 
  ((INHERIT(v9332,Kernel._class)) ? CTRUE : 
  (((v9332 != Kernel._object) && 
      ((INHERIT(v9332,Kernel._object)) && 
        ((v9332->open < 3) && 
          ((inherit_ask_class(v9332,Kernel._collection) != CTRUE) && 
            (v9332 != Core._lambda))))) ? CTRUE : 
  ((v9332 == Kernel._integer) ? CTRUE : 
  ((v9332 == Kernel._char) ? CTRUE : 
  ((INHERIT(v9332,Kernel._boolean)) ? CTRUE : 
  ((v9332 == Kernel._function) ? CTRUE : 
  CFALSE)))))))));} 

ClaireBoolean * gcsafe_ask_type(ClaireType *v9332)
{ { ClaireBoolean *Result ;
    Result = ((equal(_oid_(v9332),_oid_(Kernel.emptySet)) == CTRUE) ?
      CTRUE :
      ((INHERIT(v9332->isa,Core._Union)) ?
        (((OBJECT(ClaireBoolean,_oid_((INHERIT(CLREAD(Union,v9332,t1)->isa,Kernel._class) ? (ClaireObject *) gcsafe_ask_class((ClaireClass *) OBJECT(ClaireClass,_oid_(CLREAD(Union,v9332,t1)))) :  (ClaireObject *)  gcsafe_ask_type((ClaireType *) OBJECT(ClaireType,_oid_(CLREAD(Union,v9332,t1)))))))) == CTRUE) ? (((OBJECT(ClaireBoolean,_oid_((INHERIT(CLREAD(Union,v9332,t2)->isa,Kernel._class) ? (ClaireObject *) gcsafe_ask_class((ClaireClass *) OBJECT(ClaireClass,_oid_(CLREAD(Union,v9332,t2)))) :  (ClaireObject *)  gcsafe_ask_type((ClaireType *) OBJECT(ClaireType,_oid_(CLREAD(Union,v9332,t2)))))))) == CTRUE) ? CTRUE: CFALSE): CFALSE) :
        gcsafe_ask_class(class_I_type(v9332)) ) );
    return (Result);} 
  } 

ClaireBoolean * gcsafe_ask_property(property *v9332)
{ { ClaireBoolean *Result ;
    { OID  v2683;
      { ITERATE(v15440);
        v2683= Kernel.cfalse;
        for (START(v9332->restrictions); NEXT(v15440);)
        if (_oid_((INHERIT(v9332->range->isa,Kernel._class) ? (ClaireObject *) gcsafe_ask_class((ClaireClass *) OBJECT(ClaireClass,_oid_(v9332->range))) :  (ClaireObject *)  gcsafe_ask_type((ClaireType *) OBJECT(ClaireType,_oid_(v9332->range))))) != Kernel.ctrue)
         { v2683 = Kernel.ctrue;
          break;} 
        } 
      Result = not_any(v2683);
      } 
    return (Result);} 
  } 

OID  c_gc_I_any1(OID v9332)
{ GC_BIND;
  { OID Result = 0;
    if ((Optimize.OPT->online_ask != CTRUE) && 
        ((OBJECT(ClaireBoolean,(*Optimize.c_gc_ask)(v9332))) == CTRUE))
     { (Optimize.OPT->protection = CTRUE);
      { Compile_to_protect * v10264 = ((Compile_to_protect *) GC_OBJECT(Compile_to_protect,new_object_class(Optimize._to_protect)));
        (v10264->arg = v9332);
        add_I_property(Kernel.instances,Optimize._to_protect,11,_oid_(v10264));
        Result = _oid_(v10264);
        } 
      } 
    else Result = v9332;
      GC_UNBIND; return (Result);} 
  } 

OID  c_gc_I_any2(OID v9332,ClaireType *v15436)
{ GC_BIND;
  { OID Result = 0;
    if ((Optimize.OPT->online_ask != CTRUE) && 
        ((((OBJECT(ClaireBoolean,(*Optimize.c_gc_ask)(v9332))) == CTRUE) || 
            ((INHERIT(OWNER(v9332),Language._Let)) && 
                ((*Optimize.gcsafe_ask)(GC_OID((*Optimize.c_type)(v9332))) != Kernel.ctrue))) && 
          (_oid_((INHERIT(v15436->isa,Kernel._class) ? (ClaireObject *) gcsafe_ask_class((ClaireClass *) OBJECT(ClaireClass,_oid_(v15436))) :  (ClaireObject *)  gcsafe_ask_type((ClaireType *) OBJECT(ClaireType,_oid_(v15436))))) != Kernel.ctrue)))
     { (Optimize.OPT->protection = CTRUE);
      { Compile_to_protect * v10264 = ((Compile_to_protect *) GC_OBJECT(Compile_to_protect,new_object_class(Optimize._to_protect)));
        (v10264->arg = v9332);
        add_I_property(Kernel.instances,Optimize._to_protect,11,_oid_(v10264));
        Result = _oid_(v10264);
        } 
      } 
    else Result = v9332;
      GC_UNBIND; return (Result);} 
  } 

ClaireBoolean * need_protect_any(OID v15440)
{ GC_BIND;
  { ClaireBoolean *Result ;
    Result = ((INHERIT(OWNER(v15440),Language._Call_slot)) ?
      Optimize.OPT->use_update :
      ((INHERIT(OWNER(v15440),Language._Call_method2)) ?
        ((OBJECT(Call_method,v15440)->arg->selector == Kernel.nth) ?
          ((Optimize.OPT->use_nth_equal == CTRUE) ? CTRUE : ((domain_I_restriction(OBJECT(Call_method,v15440)->arg) == Kernel._class) ? CTRUE : ((_inf_equal_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)((*(OBJECT(Call_method,v15440)->args))[1]))),Kernel._tuple) == CTRUE) ? CTRUE : CFALSE))) :
          CTRUE ) :
        CTRUE ) );
    GC_UNBIND; return (Result);} 
  } 

Variable * Variable_I_symbol(symbol *v15435,Cint v15431,ClaireType *v15436)
{ GC_BIND;
  { Variable *Result ;
    { Variable * v10264 = ((Variable *) GC_OBJECT(Variable,new_object_class(Language._Variable)));
      (v10264->pname = v15435);
      (v10264->index = v15431);
      (v10264->range = v15436);
      add_I_property(Kernel.instances,Language._Variable,11,_oid_(v10264));
      Result = v10264;
      } 
    GC_UNBIND; return (Result);} 
  } 

list * get_indexed_class_Optimize(ClaireClass *v15419)
{ return (v15419->slots);} 

ClaireBoolean * designated_ask_any(OID v9332)
{ GC_BIND;
  { ClaireBoolean *Result ;
    { ClaireBoolean *v_or;
      { v_or = inherit_ask_class(OWNER(v9332),Kernel._thing);
        if (v_or == CTRUE) Result =CTRUE; 
        else { v_or = inherit_ask_class(OWNER(v9332),Language._Variable);
          if (v_or == CTRUE) Result =CTRUE; 
          else { v_or = inherit_ask_class(OWNER(v9332),Kernel._integer);
            if (v_or == CTRUE) Result =CTRUE; 
            else { v_or = ((Kernel._boolean == OWNER(v9332)) ? CTRUE : CFALSE);
              if (v_or == CTRUE) Result =CTRUE; 
              else { v_or = ((equal(v9332,Core.nil->value) == CTRUE) ? CTRUE : CFALSE);
                if (v_or == CTRUE) Result =CTRUE; 
                else { v_or = ((equal(v9332,_oid_(Kernel.emptySet)) == CTRUE) ? CTRUE : CFALSE);
                  if (v_or == CTRUE) Result =CTRUE; 
                  else { v_or = ((v9332 == CNULL) ? CTRUE : CFALSE);
                    if (v_or == CTRUE) Result =CTRUE; 
                    else { v_or = ((Kernel._float == OWNER(v9332)) ? CTRUE : CFALSE);
                      if (v_or == CTRUE) Result =CTRUE; 
                      else { if (INHERIT(OWNER(v9332),Language._Call))
                         { OID  v15440 = GC_OID((*Optimize.c_code)(v9332));
                          v_or = (((inherit_ask_class(OWNER(v15440),Language._Call) != CTRUE) && 
                              (designated_ask_any(v15440) == CTRUE)) ? CTRUE : ((OBJECT(Call,v9332)->selector == Core.get_stack) ? CTRUE : CFALSE));
                          } 
                        else if (INHERIT(OWNER(v9332),Language._Call_slot))
                         v_or = designated_ask_any(GC_OID(OBJECT(Call_slot,v9332)->arg));
                        else if (INHERIT(OWNER(v9332),Language._Call_table))
                         v_or = designated_ask_any(GC_OID(OBJECT(Call_table,v9332)->arg));
                        else if (INHERIT(OWNER(v9332),Optimize._to_protect))
                         v_or = ((need_protect_any(GC_OID(OBJECT(Compile_to_protect,v9332)->arg)) != CTRUE) ? ((designated_ask_any(GC_OID(OBJECT(Compile_to_protect,v9332)->arg)) == CTRUE) ? CTRUE: CFALSE): CFALSE);
                        else if (INHERIT(OWNER(v9332),Language._Call_method))
                         { ClaireBoolean *v_and;
                          { v_and = ((contain_ask_set(Optimize.OPT->simple_operations,_oid_(OBJECT(Call_method,v9332)->arg->selector)) == CTRUE) ? CTRUE : ((OBJECT(Call_method,v9332)->arg == _at_property1(Kernel.nth,Kernel._bag)) ? CTRUE : CFALSE));
                            if (v_and == CFALSE) v_or =CFALSE; 
                            else { { OID  v3644;
                                { OID gc_local;
                                  ITERATE(v15441);
                                  v3644= Kernel.cfalse;
                                  bag *v15441_support;
                                  v15441_support = GC_OBJECT(list,OBJECT(Call_method,v9332)->args);
                                  for (START(v15441_support); NEXT(v15441);)
                                  if (designated_ask_any(v15441) != CTRUE)
                                   { v3644 = Kernel.ctrue;
                                    break;} 
                                  } 
                                v_and = not_any(v3644);
                                } 
                              if (v_and == CFALSE) v_or =CFALSE; 
                              else v_or = CTRUE;} 
                            } 
                          } 
                        else v_or = ((INHERIT(OWNER(v9332),Optimize._to_CL)) ?
                          designated_ask_any(GC_OID(OBJECT(Compile_to_CL,v9332)->arg)) :
                          ((INHERIT(OWNER(v9332),Optimize._to_C)) ?
                            designated_ask_any(GC_OID(OBJECT(Compile_to_C,v9332)->arg)) :
                            CFALSE ) );
                        if (v_or == CTRUE) Result =CTRUE; 
                        else Result = CFALSE;} 
                      } 
                    } 
                  } 
                } 
              } 
            } 
          } 
        } 
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  gc_register_Variable(Variable *v9332)
{ if ((0 <= Optimize.OPT->loop_index) && 
      (v9332->index > Optimize.OPT->loop_index))
   (Optimize.OPT->loop_index = v9332->index);
  return (Kernel.ctrue);} 

OID  gc_register_Variable2(Variable *v9332,OID v2350)
{ ;{ OID Result = 0;
    if (inner2outer_ask_any(v2350) == CTRUE)
     Result = gc_register_Variable(v9332);
    else Result = Kernel.cfalse;
      return (Result);} 
  } 

ClaireBoolean * inner2outer_ask_any(OID v15440)
{ { ClaireBoolean *Result ;
    if (INHERIT(OWNER(v15440),Optimize._to_protect))
     Result = CTRUE;
    else if (INHERIT(OWNER(v15440),Language._Variable))
     Result = not_any(_oid_((INHERIT(OBJECT(Variable,v15440)->range->isa,Kernel._class) ? (ClaireObject *) gcsafe_ask_class((ClaireClass *) OBJECT(ClaireClass,_oid_(OBJECT(Variable,v15440)->range))) :  (ClaireObject *)  gcsafe_ask_type((ClaireType *) OBJECT(ClaireType,_oid_(OBJECT(Variable,v15440)->range))))));
    else if (INHERIT(OWNER(v15440),Language._Call_method))
     Result = (((OBJECT(Call_method,v15440)->arg->selector == Kernel.copy) && 
        (OBJECT(Call_method,v15440)->arg->range == Kernel._bag)) ? CTRUE : (((BCONTAIN(OBJECT(Call_method,v15440)->arg->status,4)) && 
        (inner2outer_ask_any((*(OBJECT(Call_method,v15440)->args))[1]) == CTRUE)) ? CTRUE : CFALSE));
    else if (INHERIT(OWNER(v15440),Optimize._to_CL))
     Result = inner2outer_ask_any(OBJECT(Compile_to_CL,v15440)->arg);
    else Result = ((INHERIT(OWNER(v15440),Optimize._to_C)) ?
      inner2outer_ask_any(OBJECT(Compile_to_C,v15440)->arg) :
      ((INHERIT(OWNER(v15440),Language._List)) ?
        CTRUE :
        ((INHERIT(OWNER(v15440),Language._Set)) ?
          CTRUE :
          ((INHERIT(OWNER(v15440),Language._Let)) ?
            inner2outer_ask_any(_oid_(OBJECT(Instruction_with_var,v15440)->var)) :
            CFALSE ) ) ) );
    return (Result);} 
  } 

ClaireBoolean * identifiable_ask_any(OID v9332)
{ GC_BIND;
  { ClaireBoolean *Result ;
    { ClaireBoolean *v_or;
      { v_or = ((v9332 == CNULL) ? CTRUE : CFALSE);
        if (v_or == CTRUE) Result =CTRUE; 
        else { if (INHERIT(OWNER(v9332),Optimize._to_CL))
           v_or = identifiable_ask_any(GC_OID(OBJECT(Compile_to_CL,v9332)->arg));
          else { ClaireClass * v15436 = class_I_type(OBJECT(ClaireType,(*Optimize.c_type)(v9332)));
              v_or = not_any(_oid_(contain_ask_set(Optimize.OPT->non_identifiable_set,_oid_(v15436))));
              } 
            if (v_or == CTRUE) Result =CTRUE; 
          else Result = CFALSE;} 
        } 
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_inline_method1(method *v9332,list *v15428,ClaireClass *v15435)
{ GC_BIND;
  ;{ OID Result = 0;
    Result = (*Optimize.c_code)(GC_OID(c_inline_method2(v9332,v15428)),
      _oid_(v15435));
    GC_UNBIND; return (Result);} 
  } 

OID  c_inline_method2(method *v9332,list *v15428)
{ GC_RESERVE(11);  // v3.0.55 optim !
  { OID Result = 0;
    { lambda * v15422 = GC_OBJECT(lambda,v9332->formula);
      OID  v15440 = GC_OID(v15422->body);
      list * v1944 = GC_OBJECT(list,bound_variables_any(v15440));
      symbol * v6338 = (((v9332->selector == Language.iterate) || 
          (v9332->selector == Language.Iterate)) ?
        OBJECT(Variable,(*(v15422->vars))[2])->pname :
        Kernel._class->name );
      v15440= GC_OID(instruction_copy_any(v15440));
      { OID gc_local;
        ITERATE(v15438);
        for (START(v1944); NEXT(v15438);)
        { GC_LOOP;
          { Variable * v3492;
            { { Variable * v10264 = ((Variable *) GC_OBJECT(Variable,new_object_class(Language._Variable)));
                (v10264->pname = ((OBJECT(Variable,v15438)->pname == v6338) ?
                  v6338 :
                  gensym_void() ));
                (v10264->index = 1000);
                add_I_property(Kernel.instances,Language._Variable,11,_oid_(v10264));
                v3492 = v10264;
                } 
              GC_OBJECT(Variable,v3492);} 
            store_object(v3492,
              3,
              Kernel._object,
              get_property(Kernel.range,OBJECT(ClaireObject,v15438)),
              CFALSE);
            GC__OID(v15440 = substitution_any(v15440,OBJECT(Variable,v15438),_oid_(v3492)), 5);
            } 
          GC_UNLOOP;} 
        } 
      (Optimize.OPT->max_vars = (Optimize.OPT->max_vars+v1944->length));
      Result = c_substitution_any(v15440,GC_OBJECT(list,v15422->vars),v15428,CFALSE);
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_inline_arg_ask_any(OID v9332)
{ GC_BIND;
  { OID Result = 0;
    if (INHERIT(OWNER(v9332),Language._Call))
     { list * v15428 = GC_OBJECT(list,OBJECT(Call,v9332)->args);
      OID  v15429;
      { { list * v5566;
          { { bag *v_list; OID v_val;
              OID v15440,CLcount;
              v_list = v15428;
               v5566 = v_list->clone();
              for (CLcount= 1; CLcount <= v_list->length; CLcount++)
              { v15440 = (*(v_list))[CLcount];
                v_val = (*Optimize.c_type)(v15440);
                
                (*((list *) v5566))[CLcount] = v_val;} 
              } 
            GC_OBJECT(list,v5566);} 
          v15429 = restriction_I_property(OBJECT(Call,v9332)->selector,v5566,CTRUE);
          } 
        GC_OID(v15429);} 
      if (Kernel._method == OWNER(v15429))
       { if ((OBJECT(method,v15429)->inline_ask == CTRUE) && 
            (c_inline_ask_method(OBJECT(method,v15429),v15428) == CTRUE))
         Result = c_inline_method2(OBJECT(method,v15429),v15428);
        else Result = Kernel.cfalse;
          } 
      else Result = Core.nil->value;
        } 
    else { OID  v6527;
        { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
          (v10264->selector = Kernel.set_I);
          (v10264->args = list::alloc(1,v9332));
          add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
          v6527 = _oid_(v10264);
          } 
        Result = c_inline_arg_ask_any(v6527);
        } 
      GC_UNBIND; return (Result);} 
  } 

OID  c_substitution_any(OID v9332,list *v3252,list *v11513,ClaireBoolean *v13051)
{ GC_RESERVE(1);  // HOHO v3.0.55 optim !
  { OID Result = 0;
    if (INHERIT(OWNER(v9332),Language._Variable))
     { OID  v15425;
      { { OID  v2769 = CNULL;
          { Cint  v15426 = 1;
            Cint  v15008 = v3252->length;
            { OID gc_local;
              while ((v15426 <= v15008))
              { if (OBJECT(Variable,v9332)->pname == OBJECT(Variable,(*(v3252))[v15426])->pname)
                 { v2769= v15426;
                  break;} 
                ++v15426;
                } 
              } 
            } 
          v15425 = v2769;
          } 
        GC_OID(v15425);} 
      if (v15425 != CNULL)
       Result = (*(v11513))[v15425];
      else Result = v9332;
        } 
    else if (INHERIT(OWNER(v9332),Kernel._bag))
     { { Cint  v15425 = 1;
        Cint  v15009 = OBJECT(bag,v9332)->length;
        { OID gc_local;
          while ((v15425 <= v15009))
          { ((*(OBJECT(list,v9332)))[v15425]=c_substitution_any((*(OBJECT(bag,v9332)))[v15425],v3252,v11513,v13051));
            ++v15425;
            } 
          } 
        } 
      Result = v9332;
      } 
    else if (INHERIT(OWNER(v9332),Language._Call))
     { if (OBJECT(Call,v9332)->selector == Core.eval)
       Result = c_substitution_any(GC_OID((*(OBJECT(Call,v9332)->args))[1]),v3252,v11513,((OBJECT(Call,v9332)->args->length == 1) ? CTRUE : (((OBJECT(Call,v9332)->args->length == 2) && 
          (belong_to((*(v11513))[1],(*(OBJECT(Call,v9332)->args))[2]) == CTRUE)) ? CTRUE : CFALSE)));
      else if (v13051 == CTRUE)
       { ClaireHandler c_handle = ClaireHandler();
        if ERROR_IN 
        { { list * v13207;
            { { bag *v_list; OID v_val;
                OID v15441,CLcount;
                v_list = GC_OBJECT(list,OBJECT(Call,v9332)->args);
                 v13207 = v_list->clone();
                for (CLcount= 1; CLcount <= v_list->length; CLcount++)
                { v15441 = (*(v_list))[CLcount];
                  v_val = c_substitution_any(v15441,v3252,v11513,CTRUE);
                  
                  (*((list *) v13207))[CLcount] = v_val;} 
                } 
              GC_OBJECT(list,v13207);} 
            Result = apply_property(OBJECT(Call,v9332)->selector,v13207);
            } 
          ClEnv->cHandle--;} 
        else if (belong_to(_oid_(ClEnv->exception_I),_oid_(Kernel._any)) == CTRUE)
        { c_handle.catchIt();{ tformat_string(CSTRING("a strange problem happens ~A \n"),0,GC_OBJECT(list,list::alloc(1,ClEnv->verbose)));
            warn_void();
            tformat_string(CSTRING("failed substitution: ~S"),2,GC_OBJECT(list,list::alloc(1,GC_OID(_oid_(ClEnv->exception_I)))));
            c_substitution_any(GC_OID(_oid_(OBJECT(Call,v9332)->args)),v3252,v11513,CFALSE);
            Result = v9332;
            } 
          } 
        else PREVIOUS_HANDLER;} 
      else { c_substitution_any(GC_OID(_oid_(OBJECT(Call,v9332)->args)),v3252,v11513,CFALSE);
          Result = v9332;
          } 
        } 
    else if (INHERIT(OWNER(v9332),Language._Instruction))
     { { OID gc_local;
        ITERATE(v15435);
        bag *v15435_support;
        v15435_support = OWNER(v9332)->slots;
        for (START(v15435_support); NEXT(v15435);)
        { GC_LOOP;
          { OID  v15441 = GC_OID(get_slot(OBJECT(slot,v15435),OBJECT(ClaireObject,v9332)));
            put_slot(OBJECT(slot,v15435),OBJECT(ClaireObject,v9332),c_substitution_any(v15441,v3252,v11513,v13051));
            } 
          GC_UNLOOP;} 
        } 
      Result = v9332;
      } 
    else Result = v9332;
      GC_UNBIND; return (Result);} 
  } 

OID  eval_any2(OID v15440,ClaireClass *v15441)
{ return (OPT_EVAL(v15440));} 

list * bound_variables_any(OID v9332)
{ GC_RESERVE(1);  // HOHO v3.0.55 optim !
  { list *Result ;
    { list * v15428 = list::empty(Kernel._any);
      if (INHERIT(OWNER(v9332),Language._Instruction_with_var))
       v15428= list::alloc(Kernel._any,1,GC_OID(_oid_(OBJECT(For,v9332)->var)));
      if (INHERIT(OWNER(v9332),Language._Variable))
       ;else if (INHERIT(OWNER(v9332),Language._Instruction))
       { OID gc_local;
        ITERATE(v15435);
        for (START(OBJECT(ClaireObject,v9332)->isa->slots); NEXT(v15435);)
        { GC_LOOP;
          GC__ANY(v15428 = add_star_list(v15428,GC_OBJECT(list,bound_variables_any(GC_OID(get_slot(OBJECT(slot,v15435),OBJECT(ClaireObject,v9332)))))), 1);
          GC_UNLOOP;} 
        } 
      else if (INHERIT(OWNER(v9332),Kernel._bag))
       { OID gc_local;
        ITERATE(v15440);
        for (START(OBJECT(bag,v9332)); NEXT(v15440);)
        { GC_LOOP;
          v15428= add_star_list(v15428,GC_OBJECT(list,bound_variables_any(v15440)));
          GC_UNLOOP;} 
        } 
      Result = v15428;
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_boolean_any(OID v15440)
{ GC_BIND;
  { OID Result = 0;
    { ClaireType * v3500 = GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(v15440)));
      ClaireType * v6348 = GC_OBJECT(ClaireType,ptype_type(v3500));
      if (_inf_equal_type(v6348,Kernel._boolean) == CTRUE)
       { if (INHERIT(OWNER(v15440),Language._Call))
         { if ((OBJECT(Call,v15440)->selector == Core.NOT) && 
              (ptype_type(OBJECT(ClaireType,(*Optimize.c_type)(GC_OID((*(OBJECT(Call,v15440)->args))[1])))) != Kernel._boolean))
           { { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
              (v10264->selector = Core._I_equal);
              { Call * v15032 = v10264; 
                list * v15033;
                { OID v_bag;
                  GC_ANY(v15033= list::empty(Kernel.emptySet));
                  { { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                      (v10264->selector = Kernel.boolean_I);
                      (v10264->args = list::alloc(1,GC_OID((*(OBJECT(Call,v15440)->args))[1])));
                      add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
                      v_bag = _oid_(v10264);
                      } 
                    GC_OID(v_bag);} 
                  ((list *) v15033)->addFast(v_bag);
                  ((list *) v15033)->addFast(Kernel.ctrue);} 
                (v15032->args = v15033);} 
              add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
              v15440 = _oid_(v10264);
              } 
            GC_OID(v15440);} 
          } 
        if (_inf_equal_type(v3500,Kernel._boolean) == CTRUE)
         Result = c_strict_code_any(v15440,Kernel._boolean);
        else Result = (*Optimize.c_code)(v15440,
            _oid_(Kernel._boolean));
          } 
      else if (_inf_equal_type(v3500,Kernel._bag) == CTRUE)
       { OID  v16090;
        { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
          (v10264->selector = Core._I_equal);
          { Call * v15036 = v10264; 
            list * v15037;
            { OID v_bag;
              GC_ANY(v15037= list::empty(Kernel.emptySet));
              { { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                  (v10264->selector = Kernel.length);
                  (v10264->args = list::alloc(1,v15440));
                  add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
                  v_bag = _oid_(v10264);
                  } 
                GC_OID(v_bag);} 
              ((list *) v15037)->addFast(v_bag);
              ((list *) v15037)->addFast(0);} 
            (v15036->args = v15037);} 
          add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
          v16090 = _oid_(v10264);
          } 
        Result = (*Optimize.c_code)(v16090);
        } 
      else { OID  v2589;
          { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
            (v10264->selector = Kernel.boolean_I);
            (v10264->args = list::alloc(1,v15440));
            add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
            v2589 = _oid_(v10264);
            } 
          Result = (*Optimize.c_code)(v2589);
          } 
        } 
    GC_UNBIND; return (Result);} 
  } 

