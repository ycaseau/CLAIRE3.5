/***** CLAIRE Compilation of file /Users/ycaseau/claire/v3.5/src/compile/otool.cl 
         [version 3.5.01 / safety 5] Sun Jul 24 08:43:46 2016 *****/

#include <claire.h>
#include <Kernel.h>
#include <Core.h>
#include <Language.h>
#include <Reader.h>
#include <Optimize.h>
void  self_print_to_protect(Compile_to_protect *v82400)
{ GC_BIND;
  princ_string(CSTRING("[to_protect "));
  print_any(GC_OID(v82400->arg));
  princ_string(CSTRING("]"));
  GC_UNBIND;} 

OID  self_eval_to_protect(Compile_to_protect *v82400)
{ GC_BIND;
  { OID Result = 0;
    Result = OPT_EVAL(v82400->arg);
    GC_UNBIND; return (Result);} 
  } 

void  self_print_to_CL(Compile_to_CL *v13540)
{ GC_BIND;
  princ_string(CSTRING("CL{"));
  print_any(GC_OID(v13540->arg));
  princ_string(CSTRING("}:"));
  print_any(_oid_(v13540->set_arg));
  princ_string(CSTRING(""));
  GC_UNBIND;} 

ClaireType * c_type_to_CL_Optimize(Compile_to_CL *v13540)
{ GC_BIND;
  { ClaireType *Result ;
    Result = sort_abstract_I_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(v13540->arg))));
    GC_UNBIND; return (Result);} 
  } 

ClaireBoolean * c_gc_ask_to_CL(Compile_to_CL *v13540)
{ GC_BIND;
  { ClaireBoolean *Result ;
    Result = (((gcsafe_ask_class(v13540->set_arg) != CTRUE) && 
        ((v13540->set_arg == Kernel._float) || 
            (_inf_equalt_class(v13540->set_arg,Kernel._cl_import) == CTRUE))) ? CTRUE : (((OBJECT(ClaireBoolean,(*Optimize.c_gc_ask)(GC_OID(v13540->arg)))) == CTRUE) ? CTRUE : CFALSE));
    GC_UNBIND; return (Result);} 
  } 

void  self_print_to_C(Compile_to_C *v13540)
{ GC_BIND;
  princ_string(CSTRING("C{"));
  print_any(GC_OID(v13540->arg));
  princ_string(CSTRING("}:"));
  print_any(_oid_(v13540->set_arg));
  princ_string(CSTRING(""));
  GC_UNBIND;} 

ClaireBoolean * c_gc_ask_to_C(Compile_to_C *v13540)
{ GC_BIND;
  { ClaireBoolean *Result ;
    Result = ((gcsafe_ask_class(v13540->set_arg) != CTRUE) ? (((OBJECT(ClaireBoolean,(*Optimize.c_gc_ask)(GC_OID(v13540->arg)))) == CTRUE) ? (((_inf_equalt_class(v13540->set_arg,Kernel._object) == CTRUE) || 
        (v13540->set_arg == Kernel._string)) ? CTRUE: CFALSE): CFALSE): CFALSE);
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_to_C_Optimize(Compile_to_C *v13540)
{ GC_BIND;
  { ClaireType *Result ;
    Result = glb_class(v13540->set_arg,GC_OBJECT(ClaireType,ptype_type(OBJECT(ClaireType,(*Optimize.c_type)(GC_OID(v13540->arg))))));
    GC_UNBIND; return (Result);} 
  } 

void  self_print_C_cast(Compile_C_cast *v13540)
{ GC_BIND;
  princ_string(CSTRING("<"));
  print_any(GC_OID(v13540->arg));
  princ_string(CSTRING(":"));
  print_any(_oid_(v13540->set_arg));
  princ_string(CSTRING(">"));
  GC_UNBIND;} 

ClaireBoolean * c_gc_ask_C_cast(Compile_C_cast *v13540)
{ GC_BIND;
  { ClaireBoolean *Result ;
    Result = OBJECT(ClaireBoolean,(*Optimize.c_gc_ask)(v13540->arg));
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_C_cast_Optimize(Compile_C_cast *v13540)
{ return (v13540->set_arg);} 

OID  c_code_C_cast_Optimize(Compile_C_cast *v13540,ClaireClass *v82395)
{ GC_BIND;
  { OID Result = 0;
    if (INHERIT(v82395,Kernel._object))
     { Compile_C_cast * v88616 = ((Compile_C_cast *) GC_OBJECT(Compile_C_cast,new_object_class(Optimize._C_cast)));
      (v88616->arg = (*Optimize.c_code)(GC_OID(v13540->arg),
        _oid_(v82395)));
      (v88616->set_arg = v13540->set_arg);
      add_I_property(Kernel.instances,Optimize._C_cast,11,_oid_(v88616));
      Result = _oid_(v88616);
      } 
    else Result = (*Optimize.c_code)(GC_OID(v13540->arg),
        _oid_(v82395));
      GC_UNBIND; return (Result);} 
  } 

void  self_print_Pattern(Optimize_ClairePattern *v13540)
{ GC_BIND;
  print_any(_oid_(v13540->selector));
  princ_string(CSTRING("[tuple("));
  princ_bag(GC_OBJECT(list,v13540->arg));
  princ_string(CSTRING(")]"));
  GC_UNBIND;} 

ClaireBoolean * _Z_any3(OID v82400,Optimize_ClairePattern *v82401)
{ GC_BIND;
  { ClaireBoolean *Result ;
    if (INHERIT(OWNER(v82400),Language._Call))
     { ClaireBoolean *v_and;
      { v_and = ((OBJECT(Call,v82400)->selector == v82401->selector) ? CTRUE : CFALSE);
        if (v_and == CFALSE) Result =CFALSE; 
        else { { list * v108366;
            { { bag *v_list; OID v_val;
                OID v82402,CLcount;
                v_list = GC_OBJECT(list,OBJECT(Call,v82400)->args);
                 v108366 = v_list->clone();
                for (CLcount= 1; CLcount <= v_list->length; CLcount++)
                { v82402 = (*(v_list))[CLcount];
                  v_val = (*Optimize.c_type)(v82402);
                  
                  (*((list *) v108366))[CLcount] = v_val;} 
                } 
              GC_OBJECT(list,v108366);} 
            v_and = tmatch_ask_list(v108366,GC_OBJECT(list,v82401->arg));
            } 
          if (v_and == CFALSE) Result =CFALSE; 
          else Result = CTRUE;} 
        } 
      } 
    else Result = CFALSE;
      GC_UNBIND; return (Result);} 
  } 

ClaireType * glb_Pattern(Optimize_ClairePattern *v82400,ClaireType *v82401)
{ return (Kernel.emptySet);} 

ClaireBoolean * less_ask_Pattern(Optimize_ClairePattern *v82400,OID v82401)
{ GC_BIND;
  { ClaireBoolean *Result ;
    if (INHERIT(OWNER(v82401),Optimize._Pattern))
     { ClaireBoolean *v_and;
      { v_and = ((v82400->selector == OBJECT(Optimize_ClairePattern,v82401)->selector) ? CTRUE : CFALSE);
        if (v_and == CFALSE) Result =CFALSE; 
        else { v_and = ((v82400->arg->length == OBJECT(Optimize_ClairePattern,v82401)->arg->length) ? CTRUE : CFALSE);
          if (v_and == CFALSE) Result =CFALSE; 
          else { { OID  v110288;
              { Cint  v82385 = 1;
                Cint  v61487 = v82400->arg->length;
                { OID gc_local;
                  v110288= _oid_(CFALSE);
                  while ((v82385 <= v61487))
                  { GC_LOOP;
                    if (_equaltype_ask_any(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*(v82400->arg))[v82385])),GC_OBJECT(ClaireType,OBJECT(ClaireType,(*(OBJECT(Optimize_ClairePattern,v82401)->arg))[v82385]))) != CTRUE)
                     { v110288 = Kernel.ctrue;
                      break;} 
                    ++v82385;
                    GC_UNLOOP;} 
                  } 
                } 
              v_and = not_any(v110288);
              } 
            if (v_and == CFALSE) Result =CFALSE; 
            else Result = CTRUE;} 
          } 
        } 
      } 
    else Result = OBJECT(ClaireBoolean,(*Core._inf_equalt)(_oid_(Language._Call),
        v82401));
      GC_UNBIND; return (Result);} 
  } 

ClaireBoolean * less_ask_any(OID v82400,Optimize_ClairePattern *v82401)
{ GC_BIND;
  { ClaireBoolean *Result ;
    if (INHERIT(OWNER(v82400),Optimize._Pattern))
     { ClaireBoolean *v_and;
      { v_and = ((OBJECT(Optimize_ClairePattern,v82400)->selector == v82401->selector) ? CTRUE : CFALSE);
        if (v_and == CFALSE) Result =CFALSE; 
        else { v_and = ((OBJECT(Optimize_ClairePattern,v82400)->arg->length == v82401->arg->length) ? CTRUE : CFALSE);
          if (v_and == CFALSE) Result =CFALSE; 
          else { { OID  v112210;
              { Cint  v82385 = 1;
                Cint  v61489 = OBJECT(Optimize_ClairePattern,v82400)->arg->length;
                { OID gc_local;
                  v112210= _oid_(CFALSE);
                  while ((v82385 <= v61489))
                  { GC_LOOP;
                    if (_equaltype_ask_any(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*(OBJECT(Optimize_ClairePattern,v82400)->arg))[v82385])),GC_OBJECT(ClaireType,OBJECT(ClaireType,(*(v82401->arg))[v82385]))) != CTRUE)
                     { v112210 = Kernel.ctrue;
                      break;} 
                    ++v82385;
                    GC_UNLOOP;} 
                  } 
                } 
              v_and = not_any(v112210);
              } 
            if (v_and == CFALSE) Result =CFALSE; 
            else Result = CTRUE;} 
          } 
        } 
      } 
    else Result = CFALSE;
      GC_UNBIND; return (Result);} 
  } 

Optimize_ClairePattern * nth_property(property *v82392,tuple *v82400)
{ GC_BIND;
  { Optimize_ClairePattern *Result ;
    { Optimize_ClairePattern * v88616 = ((Optimize_ClairePattern *) GC_OBJECT(Optimize_ClairePattern,new_object_class(Optimize._Pattern)));
      (v88616->selector = v82392);
      (v88616->arg = list_I_tuple(v82400));
      add_I_property(Kernel.instances,Optimize._Pattern,11,_oid_(v88616));
      Result = v88616;
      } 
    GC_UNBIND; return (Result);} 
  } 

void  warn_void()
{ GC_BIND;
  if (Optimize.OPT->in_method != CNULL)
   tformat_string(CSTRING("---- WARNING[in ~S]: "),2,list::alloc(1,GC_OID(Optimize.OPT->in_method)));
  else tformat_string(CSTRING("---- WARNING: "),2,list::empty());
    GC_UNBIND;} 

void  Cerror_string(char *v82395,listargs *v82388)
{ GC_BIND;
  princ_string(CSTRING("---- Compiler Error[in "));
  print_any(GC_OID(Optimize.OPT->in_method));
  princ_string(CSTRING("]:\n"));
  princ_string(CSTRING("---- file read up to line "));
  princ_integer(Reader.reader->nb_line);
  princ_string(CSTRING("\n"));
  close_exception(((general_error *) (*Core._general_error)(_string_(v82395),
    _oid_(v82388))));
  GC_UNBIND;} 

void  notice_void()
{ if (Optimize.OPT->in_method != CNULL)
   ;} 

OID  c_warn_Call(Call *v13540,OID v16967)
{ GC_BIND;
  { OID Result = 0;
    { property * v82395 = v13540->selector;
      if (v16967 == _oid_(Kernel._void))
       (*Optimize.Cerror)(_string_(CSTRING("[205] message ~S sent to void object")),
        _oid_(v13540));
      else if ((boolean_I_any(_oid_(v82395->restrictions)) != CTRUE) && 
          (contain_ask_set(Optimize.OPT->ignore,_oid_(v82395)) != CTRUE))
       { warn_void();
        tformat_string(CSTRING("the property ~S is undefined [255]\n"),2,list::alloc(1,_oid_(v82395)));
        } 
      else if ((contain_ask_set(Optimize.OPT->ignore,_oid_(v82395)) != CTRUE) && 
          (((v82395->open <= 1) || 
              (v82395->open == 4)) && 
            ((INHERIT(OWNER(v16967),Kernel._list)) && (class_I_type(OBJECT(ClaireType,(*(OBJECT(bag,v16967)))[1]))->open != 3))))
       { warn_void();
        tformat_string(CSTRING("wrongly typed message ~S (~S) [256]\n"),2,list::alloc(2,_oid_(v13540),v16967));
        } 
      else if (Optimize.compiler->optimize_ask == CTRUE)
       { notice_void();
        ;} 
      Result = _oid_(open_message_property(v13540->selector,GC_OBJECT(list,v13540->args)));
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_warn_Super(Super *v13540,OID v16967)
{ GC_BIND;
  { OID Result = 0;
    { property * v82395 = v13540->selector;
      if (v16967 == _oid_(Kernel._void))
       (*Optimize.Cerror)(_string_(CSTRING("[205] message ~S sent to void object")),
        _oid_(v13540));
      else if (boolean_I_any(_oid_(v82395->restrictions)) != CTRUE)
       { warn_void();
        tformat_string(CSTRING("the property ~S is undefined [255]\n"),2,list::alloc(1,_oid_(v82395)));
        } 
      else if ((contain_ask_set(Optimize.OPT->ignore,_oid_(v82395)) != CTRUE) && 
          (v82395->open <= 1))
       ;{ Call * v82389 = GC_OBJECT(Call,open_message_property(v13540->selector,GC_OBJECT(list,v13540->args)));
        Super * v88616 = ((Super *) GC_OBJECT(Super,new_object_class(Language._Super)));
        (v88616->selector = v82389->selector);
        (v88616->cast_to = v13540->cast_to);
        (v88616->args = v82389->args);
        add_I_property(Kernel.instances,Language._Super,11,_oid_(v88616));
        Result = _oid_(v88616);
        } 
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_warn_property(property *v13540,list *v82388,list *v16967)
{ if ((v13540->open <= 1) && 
      ((contain_ask_set(Optimize.OPT->ignore,_oid_(v13540)) != CTRUE) && 
        (Optimize.compiler->safety > 1)))
   ;return (_oid_(open_message_property(v13540,v82388)));} 

OID  c_warn_Variable(Variable *v13540,OID v82400,ClaireType *v82401)
{ GC_BIND;
  if (boolean_I_any((*Kernel._exp)(_oid_(v82401),
    GC_OID(_oid_(v13540->range)))) != CTRUE)
   { if (Optimize.compiler->safety > 4)
     { warn_void();
      tformat_string(CSTRING("~S of type ~S is put in the variable ~S:~S [257]\n"),2,list::alloc(4,v82400,
        _oid_(v82401),
        _oid_(v13540),
        GC_OID(_oid_(v13540->range))));
      } 
    else (*Optimize.Cerror)(_string_(CSTRING("[212] the value ~S of type ~S cannot be placed in the variable ~S:~S")),
        v82400,
        _oid_(v82401),
        _oid_(v13540),
        GC_OID(_oid_(v13540->range)));
      } 
  else if ((Optimize.compiler->safety <= 1) || 
      (boolean_I_any(sort_equal_class(osort_any(_oid_(v13540->range)),osort_any(_oid_(v82401)))) != CTRUE))
   { warn_void();
    tformat_string(CSTRING("~S of type ~S is put in the variable ~S:~S [257]\n"),2,list::alloc(4,v82400,
      _oid_(v82401),
      _oid_(v13540),
      GC_OID(_oid_(v13540->range))));
    } 
  { OID Result = 0;
    if ((Optimize.compiler->safety <= 1) && 
        (_inf_equal_type(v82401,GC_OBJECT(ClaireType,v13540->range)) != CTRUE))
     Result = c_check_any(GC_OID((*Optimize.c_code)(v82400,
      _oid_(Kernel._any))),GC_OID((*Optimize.c_code)(GC_OID(_oid_(v13540->range)),
      _oid_(Kernel._type))));
    else Result = v82400;
      GC_UNBIND; return (Result);} 
  } 

OID  sort_equal_class(ClaireClass *v82379,ClaireClass *v63431)
{ { OID Result = 0;
    if (INHERIT(v82379,Kernel._object))
     Result = _oid_(inherit_ask_class(v63431,Kernel._object));
    else Result = _oid_(((v82379 == v63431) ? CTRUE : ((((Optimize.compiler->overflow_ask != CTRUE) && 
            ((v82379 == Kernel._any) && 
                (v63431 == Kernel._integer))) || 
          ((v82379 == Kernel._integer) && 
              (v63431 == Kernel._any))) ? CTRUE : CFALSE)));
      return (Result);} 
  } 

ClaireClass * psort_any(OID v82400)
{ { ClaireClass *Result ;
    { ClaireClass * v82379 = class_I_type(OBJECT(ClaireType,v82400));
      Result = ((INHERIT(v82379,Kernel._object)) ?
        v82379 :
        ((v82379 == Kernel._float) ?
          v82379 :
          sort_I_class(v82379) ) );
      } 
    return (Result);} 
  } 

ClaireClass * osort_any(OID v82400)
{ { ClaireClass *Result ;
    { ClaireClass * v82379 = class_I_type(OBJECT(ClaireType,v82400));
      Result = ((v82379 == Kernel._float) ?
        v82379 :
        sort_I_class(v82379) );
      } 
    return (Result);} 
  } 

ClaireClass * sort_Variable(Variable *v82400)
{ { ClaireClass *Result ;
    { ClaireType * v82394 = v82400->range;
      Result = (((INHERIT(v82394->isa,Core._Union)) && (equal(_oid_(CLREAD(Union,v82394,t1)),_oid_(Kernel.emptySet)) == CTRUE)) ?
        psort_any(_oid_(CLREAD(Union,CLREAD(Union,v82394,t2),t2))) :
        psort_any(_oid_(v82394)) );
      } 
    return (Result);} 
  } 

ClaireClass * stupid_t_any1(OID v13540)
{ GC_BIND;
  { ClaireClass *Result ;
    if (INHERIT(OWNER(v13540),Language._Variable))
     { ClaireType * v82394 = GC_OBJECT(ClaireType,OBJECT(Variable,v13540)->range);
      Result = ((sort_abstract_ask_type(v82394) == CTRUE) ?
        Kernel._any :
        (((INHERIT(v82394->isa,Core._Union)) && (equal(_oid_(CLREAD(Union,v82394,t1)),_oid_(Kernel.emptySet)) == CTRUE)) ?
          OBJECT(ClaireClass,(*Core.t1)(GC_OID(_oid_(CLREAD(Union,v82394,t2))))) :
          class_I_type(v82394) ) );
      } 
    else if (INHERIT(OWNER(v13540),Core._global_variable))
     { ClaireType * v82394 = OBJECT(global_variable,v13540)->range;
      Result = ((boolean_I_any(_oid_(v82394)) == CTRUE) ?
        class_I_type(v82394) :
        OWNER(OBJECT(global_variable,v13540)->value) );
      } 
    else if (INHERIT(OWNER(v13540),Language._And))
     Result = Kernel._boolean;
    else if (INHERIT(OWNER(v13540),Kernel._bag))
     Result = OWNER(v13540);
    else if (INHERIT(OWNER(v13540),Kernel._environment))
     Result = Kernel._environment;
    else if (INHERIT(OWNER(v13540),Kernel._class))
     Result = Kernel._class;
    else if (INHERIT(OWNER(v13540),Language._Call_slot))
     { slot * v82395 = OBJECT(Call_slot,v13540)->selector;
      property * v82392 = v82395->selector;
      { ITERATE(v63927);
        for (START(v82392->definition); NEXT(v63927);)
        if (Kernel._slot == OBJECT(ClaireObject,v63927)->isa)
         { if (_inf_equal_type(domain_I_restriction(v82395),domain_I_restriction(OBJECT(restriction,v63927))) == CTRUE)
           v82395= OBJECT(slot,v63927);
          } 
        } 
      Result = class_I_type(v82395->range);
      } 
    else if (INHERIT(OWNER(v13540),Language._Call_method))
     Result = class_I_type(OBJECT(Call_method,v13540)->arg->range);
    else if (INHERIT(OWNER(v13540),Language._Call))
     Result = selector_psort_Call(OBJECT(Call,v13540));
    else if (INHERIT(OWNER(v13540),Optimize._to_C))
     Result = OBJECT(Compile_to_C,v13540)->set_arg;
    else if (INHERIT(OWNER(v13540),Optimize._to_protect))
     Result = stupid_t_any1(GC_OID(OBJECT(Compile_to_protect,v13540)->arg));
    else if (INHERIT(OWNER(v13540),Kernel._symbol))
     Result = OWNER(v13540);
    else if (INHERIT(OWNER(v13540),Kernel._char))
     Result = OWNER(v13540);
    else if (Kernel._boolean == OWNER(v13540))
     Result = OWNER(v13540);
    else if (INHERIT(OWNER(v13540),Kernel._primitive))
     Result = OWNER(v13540);
    else if (INHERIT(OWNER(v13540),Language._Assign))
     Result = stupid_t_any1(GC_OID(OBJECT(Assign,v13540)->arg));
    else if (INHERIT(OWNER(v13540),Language._Let))
     Result = stupid_t_any1(GC_OID(OBJECT(Let,v13540)->arg));
    else if (INHERIT(OWNER(v13540),Language._Do))
     Result = stupid_t_any1(GC_OID(last_list(OBJECT(Do,v13540)->args)));
    else if (INHERIT(OWNER(v13540),Language._If))
     Result = meet_class(stupid_t_any1(GC_OID(OBJECT(If,v13540)->arg)),stupid_t_any1(GC_OID(OBJECT(If,v13540)->other)));
    else if (INHERIT(OWNER(v13540),Language._Collect))
     Result = Kernel._list;
    else if (INHERIT(OWNER(v13540),Language._Image))
     Result = Kernel._set;
    else if (INHERIT(OWNER(v13540),Language._Or))
     Result = Kernel._boolean;
    else if (INHERIT(OWNER(v13540),Language._Select))
     Result = Kernel._set;
    else if (INHERIT(OWNER(v13540),Language._Lselect))
     Result = Kernel._list;
    else if (INHERIT(OWNER(v13540),Language._List))
     Result = Kernel._list;
    else if (INHERIT(OWNER(v13540),Language._Set))
     Result = Kernel._set;
    else Result = ((INHERIT(OWNER(v13540),Kernel._thing)) ?
      OWNER(v13540) :
      ((INHERIT(OWNER(v13540),Language._Tuple)) ?
        Kernel._tuple :
        ((INHERIT(OWNER(v13540),Language._Exists)) ?
          ((OBJECT(Exists,v13540)->other == CNULL) ?
            Kernel._any :
            Kernel._boolean ) :
          ((INHERIT(OWNER(v13540),Kernel._integer)) ?
            Kernel._integer :
            Kernel._any ) ) ) );
    GC_UNBIND; return (Result);} 
  } 

ClaireBoolean * stupid_t_any2(OID v13540,OID v82400)
{ { ClaireBoolean *Result ;
    { ClaireClass * v63430 = stupid_t_any1(v13540);
      ClaireClass * v63431 = stupid_t_any1(v82400);
      Result = ((v63430 != Kernel._any) ? ((v63430 == v63431) ? CTRUE: CFALSE): CFALSE);
      } 
    return (Result);} 
  } 

ClaireBoolean * extended_ask_type(ClaireType *v13540)
{ { ClaireBoolean *Result ;
    Result = ((INHERIT(v13540->isa,Core._Union)) ?
      ((Kernel._set == CLREAD(Union,v13540,t2)->isa) ? ((boolean_I_any(_oid_(CLREAD(Union,v13540,t2))) == CTRUE) ? (((*(((bag *) CLREAD(Union,v13540,t2))))[1] == CNULL) ? CTRUE: CFALSE): CFALSE): CFALSE) :
      CFALSE );
    return (Result);} 
  } 

ClaireType * extends_type(ClaireType *v82400)
{ GC_BIND;
  { ClaireType *Result ;
    { Optimize_optUnion * v88616 = ((Optimize_optUnion *) GC_OBJECT(Optimize_optUnion,new_object_class(Optimize._optUnion)));
      (v88616->t1 = v82400);
      (v88616->t2 = set::alloc(Kernel.emptySet,1,CNULL));
      Result = v88616;
      } 
    GC_UNBIND; return (Result);} 
  } 

ClaireType * sort_abstract_I_type(ClaireType *v82400)
{ GC_BIND;
  { ClaireType *Result ;
    if (((_oid_((INHERIT(v82400->isa,Kernel._class) ? (ClaireObject *) sort_I_class((ClaireClass *) OBJECT(ClaireClass,_oid_(v82400))) :  (ClaireObject *)  sort_I_type((ClaireType *) OBJECT(ClaireType,_oid_(v82400))))) != _oid_(Kernel._any)) && 
          ((_oid_((INHERIT(v82400->isa,Kernel._class) ? (ClaireObject *) sort_I_class((ClaireClass *) OBJECT(ClaireClass,_oid_(v82400))) :  (ClaireObject *)  sort_I_type((ClaireType *) OBJECT(ClaireType,_oid_(v82400))))) != _oid_(Kernel._integer)) || 
              (Optimize.compiler->overflow_ask == CTRUE))) || 
        (v82400 == Kernel._float))
     { Union * v88616 = ((Union *) GC_OBJECT(Union,new_object_class(Core._Union)));
      (v88616->t1 = Kernel._any);
      (v88616->t2 = v82400);
      Result = v88616;
      } 
    else Result = v82400;
      GC_UNBIND; return (Result);} 
  } 

ClaireBoolean * sort_abstract_ask_type(ClaireType *v82400)
{ { ClaireBoolean *Result ;
    Result = ((INHERIT(v82400->isa,Core._Union)) ?
      equal(_oid_(CLREAD(Union,v82400,t1)),_oid_(Kernel._any)) :
      CFALSE );
    return (Result);} 
  } 

ClaireType * ptype_type(ClaireType *v82400)
{ { ClaireType *Result ;
    Result = ((INHERIT(v82400->isa,Core._Union)) ?
      ((CLREAD(Union,v82400,t1) == Kernel._any) ?
        CLREAD(Union,v82400,t2) :
        v82400 ) :
      v82400 );
    return (Result);} 
  } 

ClaireType * pmember_type(ClaireType *v82400)
{ GC_BIND;
  { ClaireType *Result ;
    Result = member_type(GC_OBJECT(ClaireType,ptype_type(v82400)));
    GC_UNBIND; return (Result);} 
  } 

OID  enumerate_code_any(OID v13540,ClaireType *v61575)
{ GC_BIND;
  { OID Result = 0;
    if (_inf_equal_type(GC_OBJECT(ClaireType,ptype_type(v61575)),Kernel._bag) == CTRUE)
     Result = c_strict_code_any(v13540,Kernel._bag);
    else { if (Optimize.compiler->optimize_ask == CTRUE)
         { notice_void();
          ;} 
        Result = c_code_method_method1(GC_OBJECT(method,((method *) _at_property1(Core.enumerate,Kernel._any))),list::alloc(1,v13540),list::alloc(1,_oid_(v61575)));
        } 
      GC_UNBIND; return (Result);} 
  } 

OID  range_infers_for_Variable(Variable *v13540,ClaireType *v82401,ClaireType *v64023)
{ GC_BIND;
  if (v13540->range == (NULL))
   { if (INHERIT(v82401->isa,Core._Interval))
     v82401= Kernel._integer;
    (v13540->range = v82401);
    } 
  else if ((_inf_equal_type(v82401,GC_OBJECT(ClaireType,v13540->range)) != CTRUE) && 
      (Optimize.compiler->safety <= 1))
   { if (((boolean_I_any(_oid_(v82401)) == CTRUE) ? ((boolean_I_any(_oid_(v13540->range)) == CTRUE) ? CTRUE: CFALSE): CFALSE) != CTRUE)
     { warn_void();
      tformat_string(CSTRING("range of variable in ~S is wrong [258]\n"),2,list::alloc(1,_oid_(v13540)));
      } 
    } 
  { OID Result = 0;
    if ((sort_Variable(v13540) != Kernel._any) && 
        (((sort_Variable(v13540) != Kernel._integer) || 
            (Optimize.compiler->overflow_ask == CTRUE)) && 
          (((_inf_equal_type(v64023,Kernel._array) == CTRUE) ? ((_inf_equal_type(v82401,Kernel._float) == CTRUE) ? CTRUE: CFALSE): CFALSE) != CTRUE)))
     { Result = _void_((v13540->range = sort_abstract_I_type(GC_OBJECT(ClaireType,v13540->range))));
      } 
    else Result = Kernel.cfalse;
      GC_UNBIND; return (Result);} 
  } 

OID  range_infers_Variable(Variable *v13540,ClaireType *v82401)
{ gc_register_Variable(v13540);
  { OID Result = 0;
    if ((v13540->range == (NULL)) || 
        ((extended_ask_type(v13540->range) == CTRUE) && 
            (INHERIT(v13540->range->isa,Optimize._optUnion))))
     { if (Kernel._set == v82401->isa)
       Result = _void_((v13540->range = class_I_type(v82401)));
      else Result = _void_((v13540->range = v82401));
        } 
    else Result = Kernel.cfalse;
      return (Result);} 
  } 

void  range_infer_case_any(OID v13540,ClaireType *v82401)
{ GC_BIND;
  if (INHERIT(OWNER(v13540),Language._Variable))
   { if (boolean_I_any(sort_equal_class(osort_any(_oid_(OBJECT(Variable,v13540)->range)),osort_any(_oid_(v82401)))) == CTRUE)
     { ClaireClass * v63430 = psort_any(_oid_(class_I_type(OBJECT(Variable,v13540)->range)));
      if (v63430 != psort_any(_oid_(class_I_type(v82401))))
       { Variable * v61491 = OBJECT(Variable,v13540); 
        ClaireType * v61492;
        { Union * v88616 = ((Union *) GC_OBJECT(Union,new_object_class(Core._Union)));
          (v88616->t1 = Kernel.emptySet);
          { Union * v61493 = v88616; 
            ClaireType * v61515;
            { Union * v88616 = ((Union *) GC_OBJECT(Union,new_object_class(Core._Union)));
              (v88616->t1 = v63430);
              (v88616->t2 = v82401);
              v61515 = v88616;
              } 
            (v61493->t2 = v61515);} 
          v61492 = v88616;
          } 
        (v61491->range = v61492);} 
      else (OBJECT(Variable,v13540)->range = v82401);
        } 
    else if (osort_any(_oid_(OBJECT(Variable,v13540)->range)) == Kernel._any)
     (OBJECT(Variable,v13540)->range = sort_abstract_I_type(v82401));
    } 
  GC_UNBIND;} 

OID  c_check_any(OID v82400,OID v82401)
{ GC_BIND;
  { OID Result = 0;
    { method * v82389 = ((method *) _at_property1(Core.check_in,Kernel._any));
      if (Optimize.compiler->safety > 3)
       Result = v82400;
      else { legal_ask_module(v82389->module_I,_oid_(v82389));
          { Call_method2 * v88616 = ((Call_method2 *) GC_OBJECT(Call_method2,new_object_class(Language._Call_method2)));
            (v88616->arg = v82389);
            (v88616->args = list::alloc(2,GC_OID(c_gc_I_any1(v82400)),GC_OID(c_gc_I_any1(v82401))));
            add_I_property(Kernel.instances,Language._Call_method2,11,_oid_(v88616));
            Result = _oid_(v88616);
            } 
          } 
        } 
    GC_UNBIND; return (Result);} 
  } 

void  range_sets_any(OID v13540,ClaireType *v82401)
{ GC_BIND;
  if (INHERIT(OWNER(v13540),Language._Variable))
   { if (boolean_I_any(sort_equal_class(osort_any(_oid_(OBJECT(Variable,v13540)->range)),osort_any(_oid_(v82401)))) == CTRUE)
     { ClaireClass * v63430 = psort_any(_oid_(class_I_type(OBJECT(Variable,v13540)->range)));
      if (v63430 != psort_any(_oid_(class_I_type(v82401))))
       { Variable * v61516 = OBJECT(Variable,v13540); 
        ClaireType * v61517;
        { Union * v88616 = ((Union *) GC_OBJECT(Union,new_object_class(Core._Union)));
          (v88616->t1 = Kernel.emptySet);
          { Union * v61518 = v88616; 
            ClaireType * v61519;
            { Union * v88616 = ((Union *) GC_OBJECT(Union,new_object_class(Core._Union)));
              (v88616->t1 = v63430);
              (v88616->t2 = v82401);
              v61519 = v88616;
              } 
            (v61518->t2 = v61519);} 
          v61517 = v88616;
          } 
        (v61516->range = v61517);} 
      else (OBJECT(Variable,v13540)->range = v82401);
        } 
    else if (osort_any(_oid_(OBJECT(Variable,v13540)->range)) == Kernel._any)
     (OBJECT(Variable,v13540)->range = sort_abstract_I_type(v82401));
    } 
  GC_UNBIND;} 

ClaireClass * c_srange_method(method *v82389)
{ { ClaireClass *Result ;
    Result = ((v82389->range == Kernel._float) ?
      Kernel._float :
      OBJECT(ClaireClass,last_list(v82389->srange)) );
    return (Result);} 
  } 

ClaireBoolean * nativeVar_ask_global_variable(global_variable *v82400)
{ return (((Optimize.compiler->optimize_ask == CTRUE) ? ((v82400->store_ask == CFALSE) ? ((v82400->name->module_I == v82400->name->definition) ? (((OBJECT(ClaireBoolean,_oid_((INHERIT(v82400->range->isa,Kernel._class) ? (ClaireObject *) gcsafe_ask_class((ClaireClass *) OBJECT(ClaireClass,_oid_(v82400->range))) :  (ClaireObject *)  gcsafe_ask_type((ClaireType *) OBJECT(ClaireType,_oid_(v82400->range))))))) == CTRUE) ? CTRUE: CFALSE): CFALSE): CFALSE): CFALSE));} 

ClaireType * return_type_any(OID v13540)
{ GC_RESERVE(1);  // HOHO v3.0.55 optim !
  { ClaireType *Result ;
    if (INHERIT(OWNER(v13540),Optimize._to_C))
     Result = return_type_any(GC_OID(OBJECT(Compile_to_C,v13540)->arg));
    else if (INHERIT(OWNER(v13540),Optimize._to_protect))
     Result = return_type_any(GC_OID(OBJECT(Compile_to_protect,v13540)->arg));
    else if (INHERIT(OWNER(v13540),Language._Let))
     Result = return_type_any(GC_OID(OBJECT(Let,v13540)->arg));
    else if (INHERIT(OWNER(v13540),Language._Do))
     { set * v82400 = Kernel.emptySet;
      { OID gc_local;
        ITERATE(v82401);
        bag *v82401_support;
        v82401_support = GC_OBJECT(list,OBJECT(Do,v13540)->args);
        for (START(v82401_support); NEXT(v82401);)
        { GC_LOOP;
          GC__ANY(v82400 = OBJECT(set,(*Kernel._exp)(_oid_(v82400),
            GC_OID(_oid_(return_type_any(v82401))))), 1);
          GC_UNLOOP;} 
        } 
      Result = v82400;
      } 
    else if (INHERIT(OWNER(v13540),Language._If))
     Result = OBJECT(ClaireType,(*Kernel._exp)(GC_OID(_oid_(return_type_any(GC_OID(OBJECT(If,v13540)->arg)))),
      GC_OID(_oid_(return_type_any(GC_OID(OBJECT(If,v13540)->other))))));
    else if (INHERIT(OWNER(v13540),Language._Return))
     Result = OBJECT(ClaireType,(*Optimize.c_type)(GC_OID(OBJECT(Return,v13540)->arg)));
    else if (INHERIT(OWNER(v13540),Language._Case))
     { set * v82400 = Kernel.emptySet;
      { OID gc_local;
        ITERATE(v82401);
        bag *v82401_support;
        v82401_support = GC_OBJECT(list,OBJECT(Case,v13540)->args);
        for (START(v82401_support); NEXT(v82401);)
        { GC_LOOP;
          GC__ANY(v82400 = OBJECT(set,(*Kernel._exp)(_oid_(v82400),
            GC_OID(_oid_(return_type_any(v82401))))), 1);
          GC_UNLOOP;} 
        } 
      Result = v82400;
      } 
    else if (INHERIT(OWNER(v13540),Language._Handle))
     Result = return_type_any(GC_OID(OBJECT(ClaireHandle,v13540)->arg));
    else Result = Kernel.emptySet;
      GC_UNBIND; return (Result);} 
  } 

OID  c_code_Type_Optimize(Type *v13540,ClaireClass *v82395)
{ GC_BIND;
  { OID Result = 0;
    Result = (*Optimize.c_code)(GC_OID((*Optimize.self_code)(_oid_(v13540))),
      _oid_(v82395));
    GC_UNBIND; return (Result);} 
  } 

OID  self_code_subtype(subtype *v13540)
{ GC_BIND;
  { OID Result = 0;
    { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
      (v88616->selector = Kernel.nth);
      (v88616->args = list::alloc(2,_oid_(v13540->arg),GC_OID((*Optimize.c_code)(GC_OID(_oid_(v13540->t1)),
        _oid_(Kernel._type)))));
      add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
      Result = _oid_(v88616);
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  self_code_Param(Param *v13540)
{ GC_BIND;
  { OID Result = 0;
    if ((v13540->params->length == 1) && 
        (((*(v13540->params))[1] == _oid_(Kernel.of)) && 
          (Kernel._set == OWNER((*(v13540->args))[1]))))
     { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
      (v88616->selector = Core.param_I);
      (v88616->args = list::alloc(2,_oid_(v13540->arg),GC_OID((*Optimize.c_code)(GC_OID((*Kernel.nth)(GC_OID((*(v13540->args))[1]),
          1)),
        _oid_(Kernel._type)))));
      add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
      Result = _oid_(v88616);
      } 
    else { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
        (v88616->selector = Kernel.nth);
        { Call * v61520 = v88616; 
          list * v61521;
          { OID v_bag;
            GC_ANY(v61521= list::empty(Kernel.emptySet));
            ((list *) v61521)->addFast(_oid_(v13540->arg));
            ((list *) v61521)->addFast(GC_OID(_oid_(v13540->params)));
            { { list * v69773;{ bag *v_list; OID v_val;
                  OID v82401,CLcount;
                  v_list = GC_OBJECT(list,v13540->args);
                   v69773 = v_list->clone();
                  for (CLcount= 1; CLcount <= v_list->length; CLcount++)
                  { v82401 = (*(v_list))[CLcount];
                    v_val = (*Optimize.c_code)(v82401,
                      _oid_(Kernel._type));
                    
                    (*((list *) v69773))[CLcount] = v_val;} 
                  } 
                
                v_bag=_oid_(v69773);} 
              GC_OID(v_bag);} 
            ((list *) v61521)->addFast(v_bag);} 
          (v61520->args = v61521);} 
        add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
        Result = _oid_(v88616);
        } 
      GC_UNBIND; return (Result);} 
  } 

OID  self_code_Union(Union *v13540)
{ GC_BIND;
  { OID Result = 0;
    { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
      (v88616->selector = Core.U);
      (v88616->args = list::alloc(2,GC_OID((*Optimize.c_code)(GC_OID(_oid_(v13540->t1)),
        _oid_(Kernel._type))),GC_OID((*Optimize.c_code)(GC_OID(_oid_(v13540->t2)),
        _oid_(Kernel._type)))));
      add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
      Result = _oid_(v88616);
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  self_code_Interval(Interval *v13540)
{ GC_BIND;
  { OID Result = 0;
    { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
      (v88616->selector = Kernel._dot_dot);
      (v88616->args = list::alloc(2,v13540->arg1,v13540->arg2));
      add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
      Result = _oid_(v88616);
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  self_code_Reference(Reference *v13540)
{ GC_BIND;
  { OID Result = 0;
    { Definition * v88616 = ((Definition *) GC_OBJECT(Definition,new_object_class(Language._Definition)));
      (v88616->arg = Core._Reference);
      { Definition * v61523 = v88616; 
        list * v61524;
        { OID v_bag;
          GC_ANY(v61524= list::empty(Kernel.emptySet));
          { { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
              (v88616->selector = Kernel._equal);
              (v88616->args = list::alloc(2,_oid_(Core.args),GC_OID(_oid_(v13540->args))));
              add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
              v_bag = _oid_(v88616);
              } 
            GC_OID(v_bag);} 
          ((list *) v61524)->addFast(v_bag);
          { { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
              (v88616->selector = Kernel._equal);
              (v88616->args = list::alloc(2,_oid_(Kernel.index),v13540->index));
              add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
              v_bag = _oid_(v88616);
              } 
            GC_OID(v_bag);} 
          ((list *) v61524)->addFast(v_bag);
          { { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
              (v88616->selector = Kernel._equal);
              (v88616->args = list::alloc(2,_oid_(Kernel.arg),_oid_(v13540->arg)));
              add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
              v_bag = _oid_(v88616);
              } 
            GC_OID(v_bag);} 
          ((list *) v61524)->addFast(v_bag);} 
        (v61523->args = v61524);} 
      add_I_property(Kernel.instances,Language._Definition,11,_oid_(v88616));
      Result = _oid_(v88616);
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  self_code_Pattern(Optimize_ClairePattern *v13540)
{ GC_BIND;
  { OID Result = 0;
    if (Optimize.compiler->inline_ask == CTRUE)
     { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
      (v88616->selector = Kernel.nth);
      { Call * v61546 = v88616; 
        list * v61547;
        { OID v_bag;
          GC_ANY(v61547= list::empty(Kernel.emptySet));
          ((list *) v61547)->addFast(_oid_(v13540->selector));
          { { Tuple * v88616 = ((Tuple *) GC_OBJECT(Tuple,new_object_class(Language._Tuple)));
              (v88616->args = v13540->arg);
              add_I_property(Kernel.instances,Language._Tuple,11,_oid_(v88616));
              v_bag = _oid_(v88616);
              } 
            GC_OID(v_bag);} 
          ((list *) v61547)->addFast(v_bag);} 
        (v61546->args = v61547);} 
      add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
      Result = _oid_(v88616);
      } 
    else Result = _oid_(Language._Call);
      GC_UNBIND; return (Result);} 
  } 

OID  member_code_class2(ClaireClass *v13540,OID v82400)
{ GC_BIND;
  { OID Result = 0;
    { Call * v74057;
      { { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
          (v88616->selector = ((_inf_equal_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(v82400))),Kernel._object) == CTRUE) ?
            Kernel.isa :
            Core.owner ));
          (v88616->args = list::alloc(1,v82400));
          add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
          v74057 = v88616;
          } 
        GC_OBJECT(Call,v74057);} 
      if (((v13540->open <= -1) || 
            (v13540->open == 1)) && 
          (boolean_I_any(_oid_(v13540->subclass)) != CTRUE))
       { OID  v36876;
        { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
          (v88616->selector = Kernel._equal);
          (v88616->args = list::alloc(2,_oid_(v13540),_oid_(v74057)));
          add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
          v36876 = _oid_(v88616);
          } 
        Result = (*Optimize.c_code)(v36876);
        } 
      else { OID  v37837;
          { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
            (v88616->selector = Core.inherit_ask);
            (v88616->args = list::alloc(2,_oid_(v74057),_oid_(v13540)));
            add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
            v37837 = _oid_(v88616);
            } 
          Result = (*Optimize.c_code)(v37837);
          } 
        } 
    GC_UNBIND; return (Result);} 
  } 

OID  member_code_Type(Type *v13540,OID v82400)
{ GC_BIND;
  { OID Result = 0;
    { Call_method2 * v88616 = ((Call_method2 *) GC_OBJECT(Call_method2,new_object_class(Language._Call_method2)));
      update_property(Kernel.arg,
        v88616,
        2,
        Kernel._object,
        GC_OID(_oid_(_at_property2(Kernel._Z,list::alloc(2,_oid_(Kernel._any),_oid_(Kernel._any))))));
      (v88616->args = list::alloc(2,GC_OID((*Optimize.c_code)(v82400,
        _oid_(Kernel._any))),GC_OID((*Optimize.c_code)(_oid_(v13540),
        _oid_(Kernel._any)))));
      add_I_property(Kernel.instances,Language._Call_method2,11,_oid_(v88616));
      Result = _oid_(v88616);
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  member_code_Union(Union *v13540,OID v82400)
{ GC_BIND;
  { OID Result = 0;
    { Or * v88616 = ((Or *) GC_OBJECT(Or,new_object_class(Language._Or)));
      (v88616->args = list::alloc(2,GC_OID((*Optimize.member_code)(GC_OID(_oid_(v13540->t1)),
        v82400)),GC_OID((*Optimize.member_code)(GC_OID(_oid_(v13540->t2)),
        v82400))));
      add_I_property(Kernel.instances,Language._Or,11,_oid_(v88616));
      Result = _oid_(v88616);
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  member_code_Interval(Interval *v13540,OID v82400)
{ GC_BIND;
  { OID Result = 0;
    { OID  v38798;
      { And * v88616 = ((And *) GC_OBJECT(And,new_object_class(Language._And)));
        { And * v61551 = v88616; 
          list * v61552;
          { OID v_bag;
            GC_ANY(v61552= list::empty(Kernel.emptySet));
            { { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                (v88616->selector = Kernel._sup_equal);
                (v88616->args = list::alloc(2,v82400,v13540->arg1));
                add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
                v_bag = _oid_(v88616);
                } 
              GC_OID(v_bag);} 
            ((list *) v61552)->addFast(v_bag);
            { { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                (v88616->selector = Kernel._inf_equal);
                (v88616->args = list::alloc(2,v82400,v13540->arg2));
                add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
                v_bag = _oid_(v88616);
                } 
              GC_OID(v_bag);} 
            ((list *) v61552)->addFast(v_bag);} 
          (v61551->args = v61552);} 
        add_I_property(Kernel.instances,Language._And,11,_oid_(v88616));
        v38798 = _oid_(v88616);
        } 
      Result = (*Optimize.c_code)(v38798,
        _oid_(Kernel._any));
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  member_code_Param(Param *v13540,OID v82400)
{ GC_BIND;
  { OID Result = 0;
    { OID  v42642;
      { And * v88616 = ((And *) GC_OBJECT(And,new_object_class(Language._And)));
        { And * v61555 = v88616; 
          list * v61577;
          { list * v65706;
            { { OID v_bag;
                GC_ANY(v65706= list::empty(Kernel.emptySet));
                { { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                    (v88616->selector = Kernel._Z);
                    (v88616->args = list::alloc(2,v82400,_oid_(v13540->arg)));
                    add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
                    v_bag = _oid_(v88616);
                    } 
                  GC_OID(v_bag);} 
                ((list *) v65706)->addFast(v_bag);} 
              GC_OBJECT(list,v65706);} 
            list * v66667;
            { list * v40090 = list::empty(Kernel.emptySet);
              { Cint  v82385 = 1;
                Cint  v61553 = v13540->params->length;
                { OID gc_local;
                  while ((v82385 <= v61553))
                  { GC_LOOP;
                    { OID  v67628;
                      { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                        (v88616->selector = Kernel._Z);
                        { Call * v61582 = v88616; 
                          list * v61583;
                          { OID v_bag;
                            GC_ANY(v61583= list::empty(Kernel.emptySet));
                            { { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                                update_property(Kernel.selector,
                                  v88616,
                                  2,
                                  Kernel._object,
                                  GC_OID((*(v13540->params))[v82385]));
                                (v88616->args = list::alloc(1,v82400));
                                add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
                                v_bag = _oid_(v88616);
                                } 
                              GC_OID(v_bag);} 
                            ((list *) v61583)->addFast(v_bag);
                            ((list *) v61583)->addFast(GC_OID((*(v13540->args))[v82385]));} 
                          (v61582->args = v61583);} 
                        add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
                        v67628 = _oid_(v88616);
                        } 
                      v40090->addFast(v67628);
                      } 
                    ++v82385;
                    GC_UNLOOP;} 
                  } 
                } 
              v66667 = GC_OBJECT(list,v40090);
              } 
            v61577 = append_list(v65706,v66667);
            } 
          (v61555->args = v61577);} 
        add_I_property(Kernel.instances,Language._And,11,_oid_(v88616));
        v42642 = _oid_(v88616);
        } 
      Result = (*Optimize.c_code)(v42642,
        _oid_(Kernel._any));
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  member_code_tuple(tuple *v13540,OID v82400)
{ GC_BIND;
  { OID Result = 0;
    if (INHERIT(OWNER(v82400),Language._Tuple))
     { if (length_bag(OBJECT(bag,(*Core.args)(v82400))) != v13540->length)
       Result = Kernel.cfalse;
      else { OID  v71472;
          { And * v88616 = ((And *) GC_OBJECT(And,new_object_class(Language._And)));
            { And * v61586 = v88616; 
              list * v61587;
              { list * v40090 = list::empty(Kernel.emptySet);
                { Cint  v82385 = 1;
                  Cint  v61584 = v13540->length;
                  { OID gc_local;
                    while ((v82385 <= v61584))
                    { GC_LOOP;
                      { OID  v94536;
                        { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                          (v88616->selector = Kernel._Z);
                          (v88616->args = list::alloc(2,GC_OID((*(OBJECT(bag,(*Core.args)(v82400))))[v82385]),(*(v13540))[v82385]));
                          add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
                          v94536 = _oid_(v88616);
                          } 
                        v40090->addFast(v94536);
                        } 
                      ++v82385;
                      GC_UNLOOP;} 
                    } 
                  } 
                v61587 = GC_OBJECT(list,v40090);
                } 
              (v61586->args = v61587);} 
            add_I_property(Kernel.instances,Language._And,11,_oid_(v88616));
            v71472 = _oid_(v88616);
            } 
          Result = (*Optimize.c_code)(v71472,
            _oid_(Kernel._any));
          } 
        } 
    else Result = c_code_method_method1(GC_OBJECT(method,((method *) _at_property2(Kernel._Z,GC_OBJECT(list,list::alloc(2,_oid_(Kernel._any),_oid_(Kernel._any)))))),GC_OBJECT(list,list::alloc(2,v82400,_oid_(v13540))),GC_OBJECT(list,list::alloc(2,_oid_(Kernel._any),_oid_(Kernel._any))));
      GC_UNBIND; return (Result);} 
  } 

OID  member_code_any(OID v13540,OID v82400)
{ GC_BIND;
  (Language.LDEF->value= Core.nil->value);
  { OID Result = 0;
    { list * v16967 = list::alloc(2,GC_OID((*Optimize.c_type)(v82400)),GC_OID((*Optimize.c_type)(v13540)));
      OID  v82394 = GC_OID(extract_pattern_any(v13540,Kernel.nil));
      { ClaireBoolean * g0071I;
        { ClaireBoolean *v_or;
          { v_or = ((v82394 == CNULL) ? CTRUE : CFALSE);
            if (v_or == CTRUE) g0071I =CTRUE; 
            else { v_or = ((v13540 == _oid_(Kernel._object)) ? CTRUE : CFALSE);
              if (v_or == CTRUE) g0071I =CTRUE; 
              else { { OID  v96458;
                  if (INHERIT(OWNER(v13540),Core._global_variable))
                   v96458 = _oid_(OBJECT(global_variable,v13540)->range);
                  else v96458 = Kernel.cfalse;
                    v_or = boolean_I_any(v96458);
                  } 
                if (v_or == CTRUE) g0071I =CTRUE; 
                else g0071I = CFALSE;} 
              } 
            } 
          } 
        
        if (g0071I == CTRUE) Result = c_code_method_method1(GC_OBJECT(method,((method *) _at_property2(Kernel._Z,v16967))),list::alloc(2,v82400,v13540),v16967);
          else Result = (*Optimize.member_code)(v82394,
          v82400);
        } 
      } 
    GC_UNBIND; return (Result);} 
  } 

ClaireBoolean * _Z_any4(OID v82400,OID v82401)
{ GC_BIND;
  { ClaireBoolean *Result ;
    Result = (((OBJECT(ClaireBoolean,(*Kernel._inf_equal)(v82400,
      GC_OID(OPT_EVAL((*(OBJECT(Call,v82401)->args))[2]))))) == CTRUE) ? (((OBJECT(ClaireBoolean,(*Kernel._inf_equal)(GC_OID(OPT_EVAL((*(OBJECT(Call,v82401)->args))[1])),
      v82400))) == CTRUE) ? CTRUE: CFALSE): CFALSE);
    GC_UNBIND; return (Result);} 
  } 

ClaireBoolean * _Z_any5(OID v82400,OID v82401)
{ GC_BIND;
  { ClaireBoolean *Result ;
    Result = ((belong_to(v82400,OPT_EVAL((*(OBJECT(Call,v82401)->args))[1])) == CTRUE) ? ((equal(v82400,OPT_EVAL((*(OBJECT(Call,v82401)->args))[2])) != CTRUE) ? CTRUE: CFALSE): CFALSE);
    GC_UNBIND; return (Result);} 
  } 

ClaireBoolean * gcsafe_ask_class(ClaireClass *v13540)
{ return (((v13540 == Kernel._void) ? CTRUE : 
  ((INHERIT(v13540,Kernel._thing)) ? CTRUE : 
  ((INHERIT(v13540,Kernel._class)) ? CTRUE : 
  (((v13540 != Kernel._object) && 
      ((INHERIT(v13540,Kernel._object)) && 
        ((v13540->open < 3) && 
          ((inherit_ask_class(v13540,Kernel._collection) != CTRUE) && 
            (v13540 != Core._lambda))))) ? CTRUE : 
  ((v13540 == Kernel._integer) ? CTRUE : 
  ((v13540 == Kernel._char) ? CTRUE : 
  ((INHERIT(v13540,Kernel._boolean)) ? CTRUE : 
  ((v13540 == Kernel._function) ? CTRUE : 
  CFALSE)))))))));} 

ClaireBoolean * gcsafe_ask_type(ClaireType *v13540)
{ { ClaireBoolean *Result ;
    Result = ((equal(_oid_(v13540),_oid_(Kernel.emptySet)) == CTRUE) ?
      CTRUE :
      ((INHERIT(v13540->isa,Core._Union)) ?
        (((OBJECT(ClaireBoolean,_oid_((INHERIT(CLREAD(Union,v13540,t1)->isa,Kernel._class) ? (ClaireObject *) gcsafe_ask_class((ClaireClass *) OBJECT(ClaireClass,_oid_(CLREAD(Union,v13540,t1)))) :  (ClaireObject *)  gcsafe_ask_type((ClaireType *) OBJECT(ClaireType,_oid_(CLREAD(Union,v13540,t1)))))))) == CTRUE) ? (((OBJECT(ClaireBoolean,_oid_((INHERIT(CLREAD(Union,v13540,t2)->isa,Kernel._class) ? (ClaireObject *) gcsafe_ask_class((ClaireClass *) OBJECT(ClaireClass,_oid_(CLREAD(Union,v13540,t2)))) :  (ClaireObject *)  gcsafe_ask_type((ClaireType *) OBJECT(ClaireType,_oid_(CLREAD(Union,v13540,t2)))))))) == CTRUE) ? CTRUE: CFALSE): CFALSE) :
        gcsafe_ask_class(class_I_type(v13540)) ) );
    return (Result);} 
  } 

ClaireBoolean * gcsafe_ask_property(property *v13540)
{ { ClaireBoolean *Result ;
    { OID  v97419;
      { ITERATE(v82400);
        v97419= Kernel.cfalse;
        for (START(v13540->restrictions); NEXT(v82400);)
        if (_oid_((INHERIT(v13540->range->isa,Kernel._class) ? (ClaireObject *) gcsafe_ask_class((ClaireClass *) OBJECT(ClaireClass,_oid_(v13540->range))) :  (ClaireObject *)  gcsafe_ask_type((ClaireType *) OBJECT(ClaireType,_oid_(v13540->range))))) != Kernel.ctrue)
         { v97419 = Kernel.ctrue;
          break;} 
        } 
      Result = not_any(v97419);
      } 
    return (Result);} 
  } 

OID  c_gc_I_any1(OID v13540)
{ GC_BIND;
  { OID Result = 0;
    if ((Optimize.OPT->online_ask != CTRUE) && 
        ((OBJECT(ClaireBoolean,(*Optimize.c_gc_ask)(v13540))) == CTRUE))
     { (Optimize.OPT->protection = CTRUE);
      { Compile_to_protect * v88616 = ((Compile_to_protect *) GC_OBJECT(Compile_to_protect,new_object_class(Optimize._to_protect)));
        (v88616->arg = v13540);
        add_I_property(Kernel.instances,Optimize._to_protect,11,_oid_(v88616));
        Result = _oid_(v88616);
        } 
      } 
    else Result = v13540;
      GC_UNBIND; return (Result);} 
  } 

OID  c_gc_I_any2(OID v13540,ClaireType *v82396)
{ GC_BIND;
  { OID Result = 0;
    if ((Optimize.OPT->online_ask != CTRUE) && 
        ((((OBJECT(ClaireBoolean,(*Optimize.c_gc_ask)(v13540))) == CTRUE) || 
            ((INHERIT(OWNER(v13540),Language._Let)) && 
                ((*Optimize.gcsafe_ask)(GC_OID((*Optimize.c_type)(v13540))) != Kernel.ctrue))) && 
          (_oid_((INHERIT(v82396->isa,Kernel._class) ? (ClaireObject *) gcsafe_ask_class((ClaireClass *) OBJECT(ClaireClass,_oid_(v82396))) :  (ClaireObject *)  gcsafe_ask_type((ClaireType *) OBJECT(ClaireType,_oid_(v82396))))) != Kernel.ctrue)))
     { (Optimize.OPT->protection = CTRUE);
      { Compile_to_protect * v88616 = ((Compile_to_protect *) GC_OBJECT(Compile_to_protect,new_object_class(Optimize._to_protect)));
        (v88616->arg = v13540);
        add_I_property(Kernel.instances,Optimize._to_protect,11,_oid_(v88616));
        Result = _oid_(v88616);
        } 
      } 
    else Result = v13540;
      GC_UNBIND; return (Result);} 
  } 

ClaireBoolean * need_protect_any(OID v82400)
{ GC_BIND;
  { ClaireBoolean *Result ;
    Result = ((INHERIT(OWNER(v82400),Language._Call_slot)) ?
      Optimize.OPT->use_update :
      ((INHERIT(OWNER(v82400),Language._Call_method2)) ?
        ((OBJECT(Call_method,v82400)->arg->selector == Kernel.nth) ?
          ((Optimize.OPT->use_nth_equal == CTRUE) ? CTRUE : ((domain_I_restriction(OBJECT(Call_method,v82400)->arg) == Kernel._class) ? CTRUE : ((_inf_equal_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)((*(OBJECT(Call_method,v82400)->args))[1]))),Kernel._tuple) == CTRUE) ? CTRUE : CFALSE))) :
          CTRUE ) :
        CTRUE ) );
    GC_UNBIND; return (Result);} 
  } 

Variable * Variable_I_symbol(symbol *v82395,Cint v82390,ClaireType *v82396)
{ GC_BIND;
  { Variable *Result ;
    { Variable * v88616 = ((Variable *) GC_OBJECT(Variable,new_object_class(Language._Variable)));
      (v88616->pname = v82395);
      (v88616->index = v82390);
      (v88616->range = v82396);
      add_I_property(Kernel.instances,Language._Variable,11,_oid_(v88616));
      Result = v88616;
      } 
    GC_UNBIND; return (Result);} 
  } 

list * get_indexed_class_Optimize(ClaireClass *v82379)
{ return (v82379->slots);} 

ClaireBoolean * designated_ask_any(OID v13540)
{ GC_BIND;
  { ClaireBoolean *Result ;
    { ClaireBoolean *v_or;
      { v_or = inherit_ask_class(OWNER(v13540),Kernel._thing);
        if (v_or == CTRUE) Result =CTRUE; 
        else { v_or = inherit_ask_class(OWNER(v13540),Language._Variable);
          if (v_or == CTRUE) Result =CTRUE; 
          else { v_or = inherit_ask_class(OWNER(v13540),Kernel._integer);
            if (v_or == CTRUE) Result =CTRUE; 
            else { v_or = ((Kernel._boolean == OWNER(v13540)) ? CTRUE : CFALSE);
              if (v_or == CTRUE) Result =CTRUE; 
              else { v_or = ((equal(v13540,Core.nil->value) == CTRUE) ? CTRUE : CFALSE);
                if (v_or == CTRUE) Result =CTRUE; 
                else { v_or = ((equal(v13540,_oid_(Kernel.emptySet)) == CTRUE) ? CTRUE : CFALSE);
                  if (v_or == CTRUE) Result =CTRUE; 
                  else { v_or = ((v13540 == CNULL) ? CTRUE : CFALSE);
                    if (v_or == CTRUE) Result =CTRUE; 
                    else { v_or = ((Kernel._float == OWNER(v13540)) ? CTRUE : CFALSE);
                      if (v_or == CTRUE) Result =CTRUE; 
                      else { if (INHERIT(OWNER(v13540),Language._Call))
                         { OID  v82400 = GC_OID((*Optimize.c_code)(v13540));
                          v_or = (((inherit_ask_class(OWNER(v82400),Language._Call) != CTRUE) && 
                              (designated_ask_any(v82400) == CTRUE)) ? CTRUE : ((OBJECT(Call,v13540)->selector == Core.get_stack) ? CTRUE : CFALSE));
                          } 
                        else if (INHERIT(OWNER(v13540),Language._Call_slot))
                         v_or = designated_ask_any(GC_OID(OBJECT(Call_slot,v13540)->arg));
                        else if (INHERIT(OWNER(v13540),Language._Call_table))
                         v_or = designated_ask_any(GC_OID(OBJECT(Call_table,v13540)->arg));
                        else if (INHERIT(OWNER(v13540),Optimize._to_protect))
                         v_or = ((need_protect_any(GC_OID(OBJECT(Compile_to_protect,v13540)->arg)) != CTRUE) ? ((designated_ask_any(GC_OID(OBJECT(Compile_to_protect,v13540)->arg)) == CTRUE) ? CTRUE: CFALSE): CFALSE);
                        else if (INHERIT(OWNER(v13540),Language._Call_method))
                         { ClaireBoolean *v_and;
                          { v_and = ((contain_ask_set(Optimize.OPT->simple_operations,_oid_(OBJECT(Call_method,v13540)->arg->selector)) == CTRUE) ? CTRUE : ((OBJECT(Call_method,v13540)->arg == _at_property1(Kernel.nth,Kernel._bag)) ? CTRUE : CFALSE));
                            if (v_and == CFALSE) v_or =CFALSE; 
                            else { { OID  v98380;
                                { OID gc_local;
                                  ITERATE(v82401);
                                  v98380= Kernel.cfalse;
                                  bag *v82401_support;
                                  v82401_support = GC_OBJECT(list,OBJECT(Call_method,v13540)->args);
                                  for (START(v82401_support); NEXT(v82401);)
                                  if (designated_ask_any(v82401) != CTRUE)
                                   { v98380 = Kernel.ctrue;
                                    break;} 
                                  } 
                                v_and = not_any(v98380);
                                } 
                              if (v_and == CFALSE) v_or =CFALSE; 
                              else v_or = CTRUE;} 
                            } 
                          } 
                        else v_or = ((INHERIT(OWNER(v13540),Optimize._to_CL)) ?
                          designated_ask_any(GC_OID(OBJECT(Compile_to_CL,v13540)->arg)) :
                          ((INHERIT(OWNER(v13540),Optimize._to_C)) ?
                            designated_ask_any(GC_OID(OBJECT(Compile_to_C,v13540)->arg)) :
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

OID  gc_register_Variable(Variable *v13540)
{ if ((0 <= Optimize.OPT->loop_index) && 
      (v13540->index > Optimize.OPT->loop_index))
   (Optimize.OPT->loop_index = v13540->index);
  return (Kernel.ctrue);} 

OID  gc_register_Variable2(Variable *v13540,OID v66366)
{ ;{ OID Result = 0;
    if (inner2outer_ask_any(v66366) == CTRUE)
     Result = gc_register_Variable(v13540);
    else Result = Kernel.cfalse;
      return (Result);} 
  } 

ClaireBoolean * inner2outer_ask_any(OID v82400)
{ { ClaireBoolean *Result ;
    if (INHERIT(OWNER(v82400),Optimize._to_protect))
     Result = CTRUE;
    else if (INHERIT(OWNER(v82400),Language._Variable))
     Result = not_any(_oid_((INHERIT(OBJECT(Variable,v82400)->range->isa,Kernel._class) ? (ClaireObject *) gcsafe_ask_class((ClaireClass *) OBJECT(ClaireClass,_oid_(OBJECT(Variable,v82400)->range))) :  (ClaireObject *)  gcsafe_ask_type((ClaireType *) OBJECT(ClaireType,_oid_(OBJECT(Variable,v82400)->range))))));
    else if (INHERIT(OWNER(v82400),Language._Call_method))
     Result = (((OBJECT(Call_method,v82400)->arg->selector == Kernel.copy) && 
        (OBJECT(Call_method,v82400)->arg->range == Kernel._bag)) ? CTRUE : (((BCONTAIN(OBJECT(Call_method,v82400)->arg->status,4)) && 
        (inner2outer_ask_any((*(OBJECT(Call_method,v82400)->args))[1]) == CTRUE)) ? CTRUE : CFALSE));
    else if (INHERIT(OWNER(v82400),Optimize._to_CL))
     Result = inner2outer_ask_any(OBJECT(Compile_to_CL,v82400)->arg);
    else Result = ((INHERIT(OWNER(v82400),Optimize._to_C)) ?
      inner2outer_ask_any(OBJECT(Compile_to_C,v82400)->arg) :
      ((INHERIT(OWNER(v82400),Language._List)) ?
        CTRUE :
        ((INHERIT(OWNER(v82400),Language._Set)) ?
          CTRUE :
          ((INHERIT(OWNER(v82400),Language._Let)) ?
            inner2outer_ask_any(_oid_(OBJECT(Instruction_with_var,v82400)->var)) :
            CFALSE ) ) ) );
    return (Result);} 
  } 

ClaireBoolean * identifiable_ask_any(OID v13540)
{ GC_BIND;
  { ClaireBoolean *Result ;
    { ClaireBoolean *v_or;
      { v_or = ((v13540 == CNULL) ? CTRUE : CFALSE);
        if (v_or == CTRUE) Result =CTRUE; 
        else { if (INHERIT(OWNER(v13540),Optimize._to_CL))
           v_or = identifiable_ask_any(GC_OID(OBJECT(Compile_to_CL,v13540)->arg));
          else { ClaireClass * v82396 = class_I_type(OBJECT(ClaireType,(*Optimize.c_type)(v13540)));
              v_or = not_any(_oid_(contain_ask_set(Optimize.OPT->non_identifiable_set,_oid_(v82396))));
              } 
            if (v_or == CTRUE) Result =CTRUE; 
          else Result = CFALSE;} 
        } 
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_inline_method1(method *v13540,list *v82388,ClaireClass *v82395)
{ GC_BIND;
  ;{ OID Result = 0;
    Result = (*Optimize.c_code)(GC_OID(c_inline_method2(v13540,v82388)),
      _oid_(v82395));
    GC_UNBIND; return (Result);} 
  } 

OID  c_inline_method2(method *v13540,list *v82388)
{ GC_RESERVE(11);  // v3.0.55 optim !
  { OID Result = 0;
    { lambda * v82382 = GC_OBJECT(lambda,v13540->formula);
      OID  v82400 = GC_OID(v82382->body);
      list * v10536 = GC_OBJECT(list,bound_variables_any(v82400));
      symbol * v14930 = (((v13540->selector == Language.iterate) || 
          (v13540->selector == Language.Iterate)) ?
        OBJECT(Variable,(*(v82382->vars))[2])->pname :
        Kernel._class->name );
      v82400= GC_OID(instruction_copy_any(v82400));
      { OID gc_local;
        ITERATE(v82398);
        for (START(v10536); NEXT(v82398);)
        { GC_LOOP;
          { Variable * v64020;
            { { Variable * v88616 = ((Variable *) GC_OBJECT(Variable,new_object_class(Language._Variable)));
                (v88616->pname = ((OBJECT(Variable,v82398)->pname == v14930) ?
                  v14930 :
                  gensym_void() ));
                (v88616->index = 1000);
                add_I_property(Kernel.instances,Language._Variable,11,_oid_(v88616));
                v64020 = v88616;
                } 
              GC_OBJECT(Variable,v64020);} 
            store_object(v64020,
              3,
              Kernel._object,
              get_property(Kernel.range,OBJECT(ClaireObject,v82398)),
              CFALSE);
            GC__OID(v82400 = substitution_any(v82400,OBJECT(Variable,v82398),_oid_(v64020)), 5);
            } 
          GC_UNLOOP;} 
        } 
      (Optimize.OPT->max_vars = (Optimize.OPT->max_vars+v10536->length));
      Result = c_substitution_any(v82400,GC_OBJECT(list,v82382->vars),v82388,CFALSE);
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_inline_arg_ask_any(OID v13540)
{ GC_BIND;
  { OID Result = 0;
    if (INHERIT(OWNER(v13540),Language._Call))
     { list * v82388 = GC_OBJECT(list,OBJECT(Call,v13540)->args);
      OID  v82389;
      { { list * v100302;
          { { bag *v_list; OID v_val;
              OID v82400,CLcount;
              v_list = v82388;
               v100302 = v_list->clone();
              for (CLcount= 1; CLcount <= v_list->length; CLcount++)
              { v82400 = (*(v_list))[CLcount];
                v_val = (*Optimize.c_type)(v82400);
                
                (*((list *) v100302))[CLcount] = v_val;} 
              } 
            GC_OBJECT(list,v100302);} 
          v82389 = restriction_I_property(OBJECT(Call,v13540)->selector,v100302,CTRUE);
          } 
        GC_OID(v82389);} 
      if (Kernel._method == OWNER(v82389))
       { if ((OBJECT(method,v82389)->inline_ask == CTRUE) && 
            (c_inline_ask_method(OBJECT(method,v82389),v82388) == CTRUE))
         Result = c_inline_method2(OBJECT(method,v82389),v82388);
        else Result = Kernel.cfalse;
          } 
      else Result = Core.nil->value;
        } 
    else { OID  v101263;
        { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
          (v88616->selector = Kernel.set_I);
          (v88616->args = list::alloc(1,v13540));
          add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
          v101263 = _oid_(v88616);
          } 
        Result = c_inline_arg_ask_any(v101263);
        } 
      GC_UNBIND; return (Result);} 
  } 

OID  c_substitution_any(OID v13540,list *v63780,list *v20105,ClaireBoolean *v45195)
{ GC_RESERVE(1);  // HOHO v3.0.55 optim !
  { OID Result = 0;
    if (INHERIT(OWNER(v13540),Language._Variable))
     { OID  v82385;
      { { OID  v114497 = CNULL;
          { Cint  v82386 = 1;
            Cint  v61616 = v63780->length;
            { OID gc_local;
              while ((v82386 <= v61616))
              { if (OBJECT(Variable,v13540)->pname == OBJECT(Variable,(*(v63780))[v82386])->pname)
                 { v114497= v82386;
                  break;} 
                ++v82386;
                } 
              } 
            } 
          v82385 = v114497;
          } 
        GC_OID(v82385);} 
      if (v82385 != CNULL)
       Result = (*(v20105))[v82385];
      else Result = v13540;
        } 
    else if (INHERIT(OWNER(v13540),Kernel._bag))
     { { Cint  v82385 = 1;
        Cint  v61617 = OBJECT(bag,v13540)->length;
        { OID gc_local;
          while ((v82385 <= v61617))
          { ((*(OBJECT(list,v13540)))[v82385]=c_substitution_any((*(OBJECT(bag,v13540)))[v82385],v63780,v20105,v45195));
            ++v82385;
            } 
          } 
        } 
      Result = v13540;
      } 
    else if (INHERIT(OWNER(v13540),Language._Call))
     { if (OBJECT(Call,v13540)->selector == Core.eval)
       Result = c_substitution_any(GC_OID((*(OBJECT(Call,v13540)->args))[1]),v63780,v20105,((OBJECT(Call,v13540)->args->length == 1) ? CTRUE : (((OBJECT(Call,v13540)->args->length == 2) && 
          (belong_to((*(v20105))[1],(*(OBJECT(Call,v13540)->args))[2]) == CTRUE)) ? CTRUE : CFALSE)));
      else if (v45195 == CTRUE)
       { ClaireHandler c_handle = ClaireHandler();
        if ERROR_IN 
        { { list * v124327;
            { { bag *v_list; OID v_val;
                OID v82401,CLcount;
                v_list = GC_OBJECT(list,OBJECT(Call,v13540)->args);
                 v124327 = v_list->clone();
                for (CLcount= 1; CLcount <= v_list->length; CLcount++)
                { v82401 = (*(v_list))[CLcount];
                  v_val = c_substitution_any(v82401,v63780,v20105,CTRUE);
                  
                  (*((list *) v124327))[CLcount] = v_val;} 
                } 
              GC_OBJECT(list,v124327);} 
            Result = apply_property(OBJECT(Call,v13540)->selector,v124327);
            } 
          ClEnv->cHandle--;} 
        else if (belong_to(_oid_(ClEnv->exception_I),_oid_(Kernel._any)) == CTRUE)
        { c_handle.catchIt();{ tformat_string(CSTRING("a strange problem happens ~A \n"),0,GC_OBJECT(list,list::alloc(1,ClEnv->verbose)));
            warn_void();
            tformat_string(CSTRING("failed substitution: ~S"),2,GC_OBJECT(list,list::alloc(1,GC_OID(_oid_(ClEnv->exception_I)))));
            c_substitution_any(GC_OID(_oid_(OBJECT(Call,v13540)->args)),v63780,v20105,CFALSE);
            Result = v13540;
            } 
          } 
        else PREVIOUS_HANDLER;} 
      else { c_substitution_any(GC_OID(_oid_(OBJECT(Call,v13540)->args)),v63780,v20105,CFALSE);
          Result = v13540;
          } 
        } 
    else if (INHERIT(OWNER(v13540),Language._Instruction))
     { { OID gc_local;
        ITERATE(v82395);
        bag *v82395_support;
        v82395_support = OWNER(v13540)->slots;
        for (START(v82395_support); NEXT(v82395);)
        { GC_LOOP;
          { OID  v82401 = GC_OID(get_slot(OBJECT(slot,v82395),OBJECT(ClaireObject,v13540)));
            put_slot(OBJECT(slot,v82395),OBJECT(ClaireObject,v13540),c_substitution_any(v82401,v63780,v20105,v45195));
            } 
          GC_UNLOOP;} 
        } 
      Result = v13540;
      } 
    else Result = v13540;
      GC_UNBIND; return (Result);} 
  } 

OID  eval_any2(OID v82400,ClaireClass *v82401)
{ return (OPT_EVAL(v82400));} 

list * bound_variables_any(OID v13540)
{ GC_RESERVE(1);  // HOHO v3.0.55 optim !
  { list *Result ;
    { list * v82388 = list::empty(Kernel._any);
      if (INHERIT(OWNER(v13540),Language._Instruction_with_var))
       v82388= list::alloc(Kernel._any,1,GC_OID(_oid_(OBJECT(For,v13540)->var)));
      if (INHERIT(OWNER(v13540),Language._Variable))
       ;else if (INHERIT(OWNER(v13540),Language._Instruction))
       { OID gc_local;
        ITERATE(v82395);
        for (START(OBJECT(ClaireObject,v13540)->isa->slots); NEXT(v82395);)
        { GC_LOOP;
          GC__ANY(v82388 = add_star_list(v82388,GC_OBJECT(list,bound_variables_any(GC_OID(get_slot(OBJECT(slot,v82395),OBJECT(ClaireObject,v13540)))))), 1);
          GC_UNLOOP;} 
        } 
      else if (INHERIT(OWNER(v13540),Kernel._bag))
       { OID gc_local;
        ITERATE(v82400);
        for (START(OBJECT(bag,v13540)); NEXT(v82400);)
        { GC_LOOP;
          v82388= add_star_list(v82388,GC_OBJECT(list,bound_variables_any(v82400)));
          GC_UNLOOP;} 
        } 
      Result = v82388;
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_boolean_any(OID v82400)
{ GC_BIND;
  { OID Result = 0;
    { ClaireType * v64028 = GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(v82400)));
      ClaireType * v14940 = GC_OBJECT(ClaireType,ptype_type(v64028));
      if (_inf_equal_type(v14940,Kernel._boolean) == CTRUE)
       { if (INHERIT(OWNER(v82400),Language._Call))
         { if ((OBJECT(Call,v82400)->selector == Core.NOT) && 
              (ptype_type(OBJECT(ClaireType,(*Optimize.c_type)(GC_OID((*(OBJECT(Call,v82400)->args))[1])))) != Kernel._boolean))
           { { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
              (v88616->selector = Core._I_equal);
              { Call * v61641 = v88616; 
                list * v61642;
                { OID v_bag;
                  GC_ANY(v61642= list::empty(Kernel.emptySet));
                  { { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                      (v88616->selector = Kernel.boolean_I);
                      (v88616->args = list::alloc(1,GC_OID((*(OBJECT(Call,v82400)->args))[1])));
                      add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
                      v_bag = _oid_(v88616);
                      } 
                    GC_OID(v_bag);} 
                  ((list *) v61642)->addFast(v_bag);
                  ((list *) v61642)->addFast(Kernel.ctrue);} 
                (v61641->args = v61642);} 
              add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
              v82400 = _oid_(v88616);
              } 
            GC_OID(v82400);} 
          } 
        if (_inf_equal_type(v64028,Kernel._boolean) == CTRUE)
         Result = c_strict_code_any(v82400,Kernel._boolean);
        else Result = (*Optimize.c_code)(v82400,
            _oid_(Kernel._boolean));
          } 
      else if (_inf_equal_type(v64028,Kernel._bag) == CTRUE)
       { OID  v127210;
        { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
          (v88616->selector = Core._I_equal);
          { Call * v61644 = v88616; 
            list * v61645;
            { OID v_bag;
              GC_ANY(v61645= list::empty(Kernel.emptySet));
              { { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                  (v88616->selector = Kernel.length);
                  (v88616->args = list::alloc(1,v82400));
                  add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
                  v_bag = _oid_(v88616);
                  } 
                GC_OID(v_bag);} 
              ((list *) v61645)->addFast(v_bag);
              ((list *) v61645)->addFast(0);} 
            (v61644->args = v61645);} 
          add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
          v127210 = _oid_(v88616);
          } 
        Result = (*Optimize.c_code)(v127210);
        } 
      else { OID  v130093;
          { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
            (v88616->selector = Kernel.boolean_I);
            (v88616->args = list::alloc(1,v82400));
            add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
            v130093 = _oid_(v88616);
            } 
          Result = (*Optimize.c_code)(v130093);
          } 
        } 
    GC_UNBIND; return (Result);} 
  } 

