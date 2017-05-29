/***** CLAIRE Compilation of file /Users/ycaseau/claire/v3.5/src/compile/ocontrol.cl 
         [version 3.5.01 / safety 5] Sun Jul 24 08:43:46 2016 *****/

#include <claire.h>
#include <Kernel.h>
#include <Core.h>
#include <Language.h>
#include <Reader.h>
#include <Optimize.h>
ClaireType * c_type_Assign_Optimize(Assign *v13540)
{ GC_BIND;
  { ClaireType *Result ;
    Result = OBJECT(ClaireType,(*Optimize.c_type)(v13540->arg));
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_Assign_Optimize(Assign *v13540)
{ GC_BIND;
  { OID Result = 0;
    { OID  v82398 = GC_OID(v13540->var);
      OID  v82400 = GC_OID(v13540->arg);
      ClaireType * v16967 = GC_OBJECT(ClaireType,ptype_type(OBJECT(ClaireType,(*Optimize.c_type)(v82400))));
      if (inherit_ask_class(OWNER(v82398),Language._Variable) != CTRUE)
       (*Optimize.Cerror)(_string_(CSTRING("[213] ~S is not a variable")),
        v82398);
      if (_oid_((ClaireObject *) Core._inf_equalt->fcall(((Cint) v16967),((Cint) OBJECT(ClaireObject,GC_OID((*Kernel.range)(v82398)))))) != Kernel.ctrue)
       v82400= GC_OID((*Optimize.c_warn)(GC_OID(v13540->var),
        v82400,
        _oid_(v16967)));
      { OID  v45481 = GC_OID(c_gc_I_any2(GC_OID(c_strict_code_any(v82400,psort_any((*Kernel.range)(v82398)))),GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Kernel._exp)(GC_OID((*Kernel.range)(v82398)),
          _oid_(v16967))))));
        gc_register_Variable2(OBJECT(Variable,v82398),v45481);
        { Assign * v88616 = ((Assign *) GC_OBJECT(Assign,new_object_class(Language._Assign)));
          (v88616->var = v82398);
          (v88616->arg = v45481);
          add_I_property(Kernel.instances,Language._Assign,11,_oid_(v88616));
          Result = _oid_(v88616);
          } 
        } 
      } 
    GC_UNBIND; return (Result);} 
  } 

ClaireBoolean * c_gc_ask_Assign(Assign *v13540)
{ GC_BIND;
  { ClaireBoolean *Result ;
    Result = OBJECT(ClaireBoolean,(*Optimize.c_gc_ask)(v13540->arg));
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_Gassign_Optimize(Gassign *v13540)
{ GC_BIND;
  { ClaireType *Result ;
    Result = OBJECT(ClaireType,(*Optimize.c_type)(v13540->arg));
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_Gassign_Optimize(Gassign *v13540)
{ GC_BIND;
  { OID Result = 0;
    { OID  v61589 = GC_OID(v13540->arg);
      ClaireType * v16967 = GC_OBJECT(ClaireType,ptype_type(OBJECT(ClaireType,(*Optimize.c_type)(v61589))));
      if (boolean_I_any(_oid_(v13540->var->range)) != CTRUE)
       (*Optimize.Cerror)(_string_(CSTRING("[214] cannot assign ~S")),
        _oid_(v13540));
      if (_oid_((ClaireObject *) Core._inf_equalt->fcall(((Cint) v16967),((Cint) v13540->var->range))) != Kernel.ctrue)
       v61589= GC_OID(c_check_any(GC_OID((*Optimize.c_code)(v61589,
        _oid_(Kernel._any))),GC_OID((*Optimize.c_code)(_oid_(v13540->var->range),
        _oid_(Kernel._type)))));
      { Gassign * v88616 = ((Gassign *) GC_OBJECT(Gassign,new_object_class(Language._Gassign)));
        store_object(v88616,
          2,
          Kernel._object,
          (*Optimize.c_code)(_oid_(v13540->var)),
          CFALSE);
        { Gassign * v62511 = v88616; 
          OID  v62512;
          if (nativeVar_ask_global_variable(v13540->var) == CTRUE)
           v62512 = c_strict_code_any(v61589,psort_any(_oid_(v13540->var->range)));
          else v62512 = (*Optimize.c_code)(v61589,
              _oid_(Kernel._any));
            (v62511->arg = v62512);} 
        add_I_property(Kernel.instances,Language._Gassign,11,_oid_(v88616));
        Result = _oid_(v88616);
        } 
      } 
    GC_UNBIND; return (Result);} 
  } 

ClaireBoolean * c_gc_ask_Gassign(Gassign *v13540)
{ GC_BIND;
  { ClaireBoolean *Result ;
    Result = OBJECT(ClaireBoolean,(*Optimize.c_gc_ask)(v13540->arg));
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_And_Optimize(And *v13540)
{ return (Kernel._boolean);} 

OID  c_code_And_Optimize(And *v13540)
{ GC_BIND;
  { OID Result = 0;
    { And * v88616 = ((And *) GC_OBJECT(And,new_object_class(Language._And)));
      { And * v62513 = v88616; 
        list * v62514;
        { bag *v_list; OID v_val;
          OID v82400,CLcount;
          v_list = GC_OBJECT(list,v13540->args);
           v62514 = v_list->clone();
          for (CLcount= 1; CLcount <= v_list->length; CLcount++)
          { v82400 = (*(v_list))[CLcount];
            { if ((*Optimize.c_type)(v82400) == _oid_(Kernel._void))
               (*Optimize.Cerror)(_string_(CSTRING("[206] void ~S in ~S")),
                v82400,
                _oid_(v13540));
              v_val = c_boolean_any(v82400);
              } 
            
            (*((list *) v62514))[CLcount] = v_val;} 
          } 
        (v62513->args = v62514);} 
      add_I_property(Kernel.instances,Language._And,11,_oid_(v88616));
      Result = _oid_(v88616);
      } 
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_Or_Optimize(Or *v13540)
{ return (Kernel._boolean);} 

OID  c_code_Or_Optimize(Or *v13540)
{ GC_BIND;
  { OID Result = 0;
    { Or * v88616 = ((Or *) GC_OBJECT(Or,new_object_class(Language._Or)));
      { Or * v62515 = v88616; 
        list * v62516;
        { bag *v_list; OID v_val;
          OID v82400,CLcount;
          v_list = GC_OBJECT(list,v13540->args);
           v62516 = v_list->clone();
          for (CLcount= 1; CLcount <= v_list->length; CLcount++)
          { v82400 = (*(v_list))[CLcount];
            { if ((*Optimize.c_type)(v82400) == _oid_(Kernel._void))
               (*Optimize.Cerror)(_string_(CSTRING("[206] void ~S in ~S")),
                v82400,
                _oid_(v13540));
              v_val = c_boolean_any(v82400);
              } 
            
            (*((list *) v62516))[CLcount] = v_val;} 
          } 
        (v62515->args = v62516);} 
      add_I_property(Kernel.instances,Language._Or,11,_oid_(v88616));
      Result = _oid_(v88616);
      } 
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_Quote_Optimize(Quote *v13540)
{ return (OWNER(v13540->arg));} 

void  c_code_Quote_Optimize(Quote *v13540)
{ (*Optimize.Cerror)(_string_(CSTRING("[internal] optimization of quote not implemented yet! ~S")),
    _oid_(v13540));
  } 

ClaireType * c_type_to_protect_Optimize(Compile_to_protect *v13540)
{ GC_BIND;
  { ClaireType *Result ;
    Result = OBJECT(ClaireType,(*Optimize.c_type)(v13540->arg));
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_to_protect_Optimize(Compile_to_protect *v13540)
{ return (_oid_(v13540));} 

ClaireBoolean * c_gc_ask_to_protect(Compile_to_protect *v13540)
{ return (CFALSE);} 

ClaireType * c_type_Return_Optimize(Return *v13540)
{ return (Kernel._any);} 

OID  c_code_Return_Optimize(Return *v13540)
{ GC_BIND;
  (Optimize.OPT->loop_gc = CFALSE);
  { OID Result = 0;
    { Return * v88616 = ((Return *) GC_OBJECT(Return,new_object_class(Language._Return)));
      (v88616->arg = (*Optimize.c_code)(GC_OID(v13540->arg),
        _oid_(Kernel._any)));
      add_I_property(Kernel.instances,Language._Return,11,_oid_(v88616));
      Result = _oid_(v88616);
      } 
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_Handle_Optimize(ClaireHandle *v13540)
{ GC_BIND;
  { ClaireType *Result ;
    Result = U_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(GC_OID(v13540->arg)))),GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(GC_OID(v13540->other)))));
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_Handle_Optimize(ClaireHandle *v13540,ClaireClass *v82395)
{ GC_BIND;
  { OID Result = 0;
    { ClaireHandle * v82400;
      { { ClaireHandle * v88616 = ((ClaireHandle *) GC_OBJECT(ClaireHandle,new_object_class(Language._Handle)));
          (v88616->test = _oid_(Kernel._any));
          (v88616->arg = (*Optimize.c_code)(GC_OID(v13540->arg),
            _oid_(v82395)));
          (v88616->other = (*Optimize.c_code)(GC_OID(v13540->other),
            _oid_(v82395)));
          add_I_property(Kernel.instances,Language._Handle,11,_oid_(v88616));
          v82400 = v88616;
          } 
        GC_OBJECT(ClaireHandle,v82400);} 
      if (v13540->test != _oid_(Core._contradiction))
       (Optimize.OPT->allocation = CTRUE);
      (v82400->test = v13540->test);
      Result = _oid_(v82400);
      } 
    GC_UNBIND; return (Result);} 
  } 

ClaireBoolean * c_gc_ask_Handle(ClaireHandle *v13540)
{ GC_BIND;
  { ClaireBoolean *Result ;
    Result = (((OBJECT(ClaireBoolean,(*Optimize.c_gc_ask)(v13540->arg))) == CTRUE) ? CTRUE : (((OBJECT(ClaireBoolean,(*Optimize.c_gc_ask)(v13540->other))) == CTRUE) ? CTRUE : CFALSE));
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_Cast_Optimize(Cast *v13540)
{ return (v13540->set_arg);} 

OID  c_code_Cast_Optimize(Cast *v13540)
{ GC_BIND;
  { OID Result = 0;
    { ClaireType * v82401 = GC_OBJECT(ClaireType,v13540->set_arg);
      ClaireClass * v14856 = psort_any(_oid_(v82401));
      if ((INHERIT(v82401->isa,Core._Param)) && (((CLREAD(Param,v82401,arg) == Kernel._list) || 
            (CLREAD(Param,v82401,arg) == Kernel._set)) && 
          (Kernel._set == OWNER((*(CLREAD(Param,v82401,args)))[1]))))
       { OID  v105111 = GC_OID((*(OBJECT(set,(*(CLREAD(Param,v82401,args)))[1])))[1]);
        if ((equal(_oid_(_at_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(GC_OID(v13540->arg)))),Kernel.of)),v105111) == CTRUE) || 
            (Optimize.compiler->safety > 4))
         Result = (*Optimize.c_code)(GC_OID(v13540->arg),
          _oid_(v14856));
        else { OID  v70762;
            { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
              (v88616->selector = Core.check_in);
              (v88616->args = list::alloc(3,GC_OID(v13540->arg),
                _oid_(CLREAD(Param,v82401,arg)),
                v105111));
              add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
              v70762 = _oid_(v88616);
              } 
            Result = (*Optimize.c_code)(v70762,
              _oid_(v14856));
            } 
          } 
      else if ((_inf_equal_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(GC_OID(v13540->arg)))),v82401) == CTRUE) || 
          (Optimize.compiler->safety > 1))
       Result = (*Optimize.c_code)(GC_OID(v13540->arg),
        _oid_(v14856));
      else { OID  v71723;
          { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
            (v88616->selector = Core.check_in);
            (v88616->args = list::alloc(2,GC_OID(v13540->arg),_oid_(v82401)));
            add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
            v71723 = _oid_(v88616);
            } 
          Result = (*Optimize.c_code)(v71723,
            _oid_(v14856));
          } 
        } 
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_Super_Optimize(Super *v13540)
{ GC_BIND;
  { ClaireType *Result ;
    { list * v16967;
      { { bag *v_list; OID v_val;
          OID v82400,CLcount;
          v_list = GC_OBJECT(list,v13540->args);
           v16967 = v_list->clone();
          for (CLcount= 1; CLcount <= v_list->length; CLcount++)
          { v82400 = (*(v_list))[CLcount];
            v_val = (*Optimize.c_type)(v82400);
            
            (*((list *) v16967))[CLcount] = v_val;} 
          } 
        GC_OBJECT(list,v16967);} 
      property * v82395 = v13540->selector;
      ((*(v16967))[1]=_oid_(v13540->cast_to));
      { OID  v67835;
        { if (v82395->open == 3)
           v67835 = Core.nil->value;
          else v67835 = restriction_I_class(class_I_type(v13540->cast_to),v82395->definition,v16967);
            GC_OID(v67835);} 
        Result = ((Kernel._slot == OWNER(v67835)) ?
          OBJECT(restriction,v67835)->range :
          ((Kernel._method == OWNER(v67835)) ?
            use_range_method(OBJECT(method,v67835),v16967) :
            v82395->range ) );
        } 
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_Super_Optimize(Super *v13540)
{ GC_BIND;
  { OID Result = 0;
    { property * v82395 = v13540->selector;
      list * v82388 = GC_OBJECT(list,v13540->args);
      list * v16967;
      { { bag *v_list; OID v_val;
          OID v82400,CLcount;
          v_list = GC_OBJECT(list,v13540->args);
           v16967 = v_list->clone();
          for (CLcount= 1; CLcount <= v_list->length; CLcount++)
          { v82400 = (*(v_list))[CLcount];
            v_val = (*Optimize.c_type)(v82400);
            
            (*((list *) v16967))[CLcount] = v_val;} 
          } 
        GC_OBJECT(list,v16967);} 
      OID  v67835;
      { if (v82395->open == 3)
         v67835 = Core.nil->value;
        else v67835 = restriction_I_class(class_I_type(v13540->cast_to),v82395->definition,v16967);
          GC_OID(v67835);} 
      if (Kernel._slot == OWNER(v67835))
       { Call_slot * v88616 = ((Call_slot *) GC_OBJECT(Call_slot,new_object_class(Language._Call_slot)));
        (v88616->selector = OBJECT(slot,v67835));
        (v88616->arg = (*Optimize.c_code)((*(v82388))[1],
          _oid_(psort_any(_oid_(domain_I_restriction(OBJECT(restriction,v67835)))))));
        (v88616->test = ((belong_to(OBJECT(slot,v67835)->DEFAULT,_oid_(OBJECT(restriction,v67835)->range)) != CTRUE) ? ((Optimize.compiler->safety < 5) ? CTRUE: CFALSE): CFALSE));
        add_I_property(Kernel.instances,Language._Call_slot,11,_oid_(v88616));
        Result = _oid_(v88616);
        } 
      else if (Kernel._method == OWNER(v67835))
       Result = c_code_method_method1(OBJECT(method,v67835),v82388,v16967);
      else Result = c_warn_Super(v13540,_oid_(v16967));
        } 
    GC_UNBIND; return (Result);} 
  } 

void  self_print_Call_function2(Optimize_Call_function2 *v13540)
{ print_any(_oid_(v13540->arg));
  princ_string(CSTRING("("));
  princ_bag(v13540->args);
  princ_string(CSTRING(")"));
  } 

ClaireType * c_type_Call_function2_Optimize(Optimize_Call_function2 *v13540)
{ return (Kernel._any);} 

OID  c_code_Call_function2_Optimize(Optimize_Call_function2 *v13540)
{ GC_BIND;
  { OID Result = 0;
    { Optimize_Call_function2 * v88616 = ((Optimize_Call_function2 *) GC_OBJECT(Optimize_Call_function2,new_object_class(Optimize._Call_function2)));
      (v88616->arg = v13540->arg);
      { Optimize_Call_function2 * v62540 = v88616; 
        list * v62541;
        { bag *v_list; OID v_val;
          OID v82400,CLcount;
          v_list = v13540->args;
           v62541 = v_list->clone();
          for (CLcount= 1; CLcount <= v_list->length; CLcount++)
          { v82400 = (*(v_list))[CLcount];
            v_val = (*Optimize.c_code)(v82400,
              _oid_(Kernel._any));
            
            (*((list *) v62541))[CLcount] = v_val;} 
          } 
        (v62540->args = v62541);} 
      add_I_property(Kernel.instances,Optimize._Call_function2,11,_oid_(v88616));
      Result = _oid_(v88616);
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_Assert_Optimize(Assert *v13540)
{ if (Optimize.OPT->online_ask == CTRUE) 
  { { OID Result = 0;
      Result = _oid_(v13540);
      return (Result);} 
     } 
  else{ GC_BIND;
    { OID Result = 0;
      if ((Optimize.compiler->safety == 0) || 
          (Optimize.compiler->debug_ask->length != 0))
       { OID  v74606;
        { If * v88616 = ((If *) GC_OBJECT(If,new_object_class(Language._If)));
          { If * v62543 = v88616; 
            OID  v62544;
            { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
              (v88616->selector = Core.NOT);
              (v88616->args = list::alloc(1,GC_OID((*(v13540->args))[1])));
              add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
              v62544 = _oid_(v88616);
              } 
            (v62543->test = v62544);} 
          { If * v62545 = v88616; 
            OID  v62546;
            { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
              (v88616->selector = Core.tformat);
              { Call * v62547 = v88616; 
                list * v62569;
                { OID v_bag;
                  GC_ANY(v62569= list::empty(Kernel.emptySet));
                  ((list *) v62569)->addFast(_string_(CSTRING("Assertion violation in ~A line ~A\n")));
                  ((list *) v62569)->addFast(0);
                  { { List * v88616 = ((List *) GC_OBJECT(List,new_object_class(Language._List)));
                      (v88616->args = list::alloc(2,GC_OID(_string_(v13540->external)),v13540->index));
                      add_I_property(Kernel.instances,Language._List,11,_oid_(v88616));
                      v_bag = _oid_(v88616);
                      } 
                    GC_OID(v_bag);} 
                  ((list *) v62569)->addFast(v_bag);} 
                (v62547->args = v62569);} 
              add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
              v62546 = _oid_(v88616);
              } 
            (v62545->arg = v62546);} 
          (v88616->other = Kernel.cfalse);
          add_I_property(Kernel.instances,Language._If,11,_oid_(v88616));
          v74606 = _oid_(v88616);
          } 
        Result = (*Optimize.c_code)(v74606,
          _oid_(Kernel._any));
        } 
      else Result = Kernel.cfalse;
        GC_UNBIND; return (Result);} 
    } 
  } 

OID  c_code_Trace_Optimize(Trace *v13540)
{ GC_BIND;
  { OID Result = 0;
    { list * v82377 = GC_OBJECT(list,v13540->args);
      if (Optimize.OPT->online_ask == CTRUE)
       Result = _oid_(v13540);
      else if ((v82377->length == 1) && 
          (_inf_equal_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)((*(v82377))[1]))),Kernel._integer) == CTRUE))
       { OID  v101514;
        { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
          (v88616->selector = Core.write);
          (v88616->args = list::alloc(3,_oid_(Kernel.verbose),
            _oid_(ClEnv),
            (*(v82377))[1]));
          add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
          v101514 = _oid_(v88616);
          } 
        Result = (*Optimize.c_code)(v101514);
        } 
      else { ClaireBoolean * g0172I;
        { ClaireBoolean *v_and;
          { v_and = ((v82377->length > 1) ? CTRUE : CFALSE);
            if (v_and == CFALSE) g0172I =CFALSE; 
            else { v_and = ((Kernel._string == OWNER((*(v82377))[2])) ? CTRUE : CFALSE);
              if (v_and == CFALSE) g0172I =CFALSE; 
              else { { ClaireBoolean *v_or;
                  { v_or = ((Optimize.compiler->debug_ask->length != 0) ? CTRUE : CFALSE);
                    if (v_or == CTRUE) v_and =CTRUE; 
                    else { { ClaireObject *V_CC ;
                        { ClaireHandler c_handle = ClaireHandler();
                          if ERROR_IN 
                          { V_CC = ((OPT_EVAL((*(v82377))[1]) <= ClEnv->verbose) ? CTRUE : CFALSE);
                            ClEnv->cHandle--;} 
                          else if (belong_to(_oid_(ClEnv->exception_I),_oid_(Kernel._any)) == CTRUE)
                          { c_handle.catchIt();V_CC = CTRUE;
                            } 
                          else PREVIOUS_HANDLER;} 
                        v_or= (ClaireBoolean *) V_CC;} 
                      if (v_or == CTRUE) v_and =CTRUE; 
                      else v_and = CFALSE;} 
                    } 
                  } 
                if (v_and == CFALSE) g0172I =CFALSE; 
                else g0172I = CTRUE;} 
              } 
            } 
          } 
        
        if (g0172I == CTRUE) { Call * v61558;
            { { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                (v88616->selector = Core.tformat);
                { Call * v62572 = v88616; 
                  list * v62573;
                  { OID v_bag;
                    GC_ANY(v62573= list::empty(Kernel.emptySet));
                    ((list *) v62573)->addFast((*(v82377))[2]);
                    ((list *) v62573)->addFast((*(v82377))[1]);
                    { { List * v88616 = ((List *) GC_OBJECT(List,new_object_class(Language._List)));
                        (v88616->args = skip_list(((list *) copy_bag(v82377)),2));
                        add_I_property(Kernel.instances,Language._List,11,_oid_(v88616));
                        v_bag = _oid_(v88616);
                        } 
                      GC_OID(v_bag);} 
                    ((list *) v62573)->addFast(v_bag);} 
                  (v62572->args = v62573);} 
                add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
                v61558 = v88616;
                } 
              GC_OBJECT(Call,v61558);} 
            { OID  v105358;
              if (inherit_ask_class(OWNER((*(v82377))[1]),Kernel._integer) != CTRUE)
               { If * v88616 = ((If *) GC_OBJECT(If,new_object_class(Language._If)));
                { If * v62575 = v88616; 
                  OID  v62576;
                  { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                    (v88616->selector = Kernel._inf_equal);
                    { Call * v62577 = v88616; 
                      list * v62578;
                      { OID v_bag;
                        GC_ANY(v62578= list::empty(Kernel.emptySet));
                        ((list *) v62578)->addFast((*(v82377))[1]);
                        { { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                            (v88616->selector = Kernel.verbose);
                            (v88616->args = list::alloc(1,_oid_(ClEnv)));
                            add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
                            v_bag = _oid_(v88616);
                            } 
                          GC_OID(v_bag);} 
                        ((list *) v62578)->addFast(v_bag);} 
                      (v62577->args = v62578);} 
                    add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
                    v62576 = _oid_(v88616);
                    } 
                  (v62575->test = v62576);} 
                (v88616->arg = _oid_(v61558));
                (v88616->other = Kernel.cfalse);
                add_I_property(Kernel.instances,Language._If,11,_oid_(v88616));
                v105358 = _oid_(v88616);
                } 
              else v105358 = _oid_(v61558);
                Result = (*Optimize.c_code)(v105358,
                _oid_(Kernel._any));
              } 
            } 
          else Result = Kernel.cfalse;
        } 
      } 
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_Assert_Optimize(Assert *v13540)
{ return (Kernel._any);} 

ClaireType * c_type_Trace_Optimize(Trace *v13540)
{ return (Kernel._any);} 

ClaireType * c_type_Branch_Optimize(Branch *v13540)
{ return (Kernel._boolean);} 

OID  c_code_Branch_Optimize(Branch *v13540)
{ GC_BIND;
  { OID Result = 0;
    { OID  v130344;
      { ClaireHandle * v88616 = ((ClaireHandle *) GC_OBJECT(ClaireHandle,new_object_class(Language._Handle)));
        { ClaireHandle * v62601 = v88616; 
          OID  v62602;
          { Do * v88616 = ((Do *) GC_OBJECT(Do,new_object_class(Language._Do)));
            { Do * v62603 = v88616; 
              list * v62604;
              { OID v_bag;
                GC_ANY(v62604= list::empty(Kernel.emptySet));
                { { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                    (v88616->selector = Kernel.choice);
                    (v88616->args = list::alloc(1,_oid_(ClEnv)));
                    add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
                    v_bag = _oid_(v88616);
                    } 
                  GC_OID(v_bag);} 
                ((list *) v62604)->addFast(v_bag);
                { { If * v88616 = ((If *) GC_OBJECT(If,new_object_class(Language._If)));
                    (v88616->test = (*(v13540->args))[1]);
                    (v88616->arg = Kernel.ctrue);
                    { If * v62605 = v88616; 
                      OID  v62606;
                      { Do * v88616 = ((Do *) GC_OBJECT(Do,new_object_class(Language._Do)));
                        { Do * v62607 = v88616; 
                          list * v62608;
                          { OID v_bag;
                            GC_ANY(v62608= list::empty(Kernel.emptySet));
                            { { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                                (v88616->selector = Kernel.backtrack);
                                (v88616->args = list::alloc(1,_oid_(ClEnv)));
                                add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
                                v_bag = _oid_(v88616);
                                } 
                              GC_OID(v_bag);} 
                            ((list *) v62608)->addFast(v_bag);
                            ((list *) v62608)->addFast(Kernel.cfalse);} 
                          (v62607->args = v62608);} 
                        add_I_property(Kernel.instances,Language._Do,11,_oid_(v88616));
                        v62606 = _oid_(v88616);
                        } 
                      (v62605->other = v62606);} 
                    add_I_property(Kernel.instances,Language._If,11,_oid_(v88616));
                    v_bag = _oid_(v88616);
                    } 
                  GC_OID(v_bag);} 
                ((list *) v62604)->addFast(v_bag);} 
              (v62603->args = v62604);} 
            add_I_property(Kernel.instances,Language._Do,11,_oid_(v88616));
            v62602 = _oid_(v88616);
            } 
          (v62601->arg = v62602);} 
        (v88616->test = _oid_(Core._contradiction));
        { ClaireHandle * v62609 = v88616; 
          OID  v62631;
          { Do * v88616 = ((Do *) GC_OBJECT(Do,new_object_class(Language._Do)));
            { Do * v62632 = v88616; 
              list * v62633;
              { OID v_bag;
                GC_ANY(v62633= list::empty(Kernel.emptySet));
                { { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                    (v88616->selector = Kernel.backtrack);
                    (v88616->args = list::alloc(1,_oid_(ClEnv)));
                    add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
                    v_bag = _oid_(v88616);
                    } 
                  GC_OID(v_bag);} 
                ((list *) v62633)->addFast(v_bag);
                ((list *) v62633)->addFast(Kernel.cfalse);} 
              (v62632->args = v62633);} 
            add_I_property(Kernel.instances,Language._Do,11,_oid_(v88616));
            v62631 = _oid_(v88616);
            } 
          (v62609->other = v62631);} 
        add_I_property(Kernel.instances,Language._Handle,11,_oid_(v88616));
        v130344 = _oid_(v88616);
        } 
      Result = (*Optimize.c_code)(v130344,
        _oid_(Kernel._any));
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_Macro_Optimize(Macro *v13540,ClaireClass *v82395)
{ GC_BIND;
  { OID Result = 0;
    Result = (*Optimize.c_code)(GC_OID((*Language.macroexpand)(_oid_(v13540))),
      _oid_(v82395));
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_Macro_Optimize(Macro *v13540)
{ GC_BIND;
  { ClaireType *Result ;
    Result = OBJECT(ClaireType,(*Optimize.c_type)(GC_OID((*Language.macroexpand)(_oid_(v13540)))));
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_Printf_Optimize(Printf *v13540)
{ return (Kernel._any);} 

OID  c_code_Printf_Optimize(Printf *v13540)
{ GC_RESERVE(13);  // v3.0.55 optim !
  { OID Result = 0;
    { list * v82388 = GC_OBJECT(list,v13540->args);
      if (equal(_oid_(Kernel._string),_oid_(OWNER((*(v82388))[1]))) != CTRUE)
       Result = (*Optimize.Cerror)(_string_(CSTRING("[209] the first argument in ~S must be a string")),
        _oid_(v13540));
      else { char * v82395 = string_v((*(v82388))[1]);
          Cint  v82385 = 1;
          Cint  v82390 = get_string(v82395,_char_('~'));
          list * v82394 = list::empty(Kernel._any);
          { OID gc_local;
            while ((equal(v82390,0) != CTRUE))
            { GC_LOOP;
              { ClaireChar * v82389 = _char_(v82395[(v82390+1) - 1]);
                if (v82385 < v82388->length)
                 ++v82385;
                else (*Optimize.Cerror)(_string_(CSTRING("[210] not enough arguments in ~S")),
                    _oid_(v13540));
                  if (v82390 > 1)
                 { { OID  v31946;
                    { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                      (v88616->selector = Kernel.princ);
                      (v88616->args = list::alloc(1,GC_OID(_string_(substring_string(v82395,1,(v82390-1))))));
                      add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
                      v31946 = _oid_(v88616);
                      } 
                    v82394 = v82394->addFast(v31946);
                    } 
                   GC__ANY(v82394, 7);} 
                { { OID  v32907;
                    if ('A' == ((char) v82389->ascii))
                     { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                      (v88616->selector = Kernel.princ);
                      (v88616->args = list::alloc(1,(*(v82388))[v82385]));
                      add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
                      v32907 = _oid_(v88616);
                      } 
                    else if ('S' == ((char) v82389->ascii))
                     { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                      (v88616->selector = Kernel.print);
                      (v88616->args = list::alloc(1,(*(v82388))[v82385]));
                      add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
                      v32907 = _oid_(v88616);
                      } 
                    else if ('F' == ((char) v82389->ascii))
                     { ClaireBoolean * v63821 = CFALSE;
                      Cint  v82386 = (integer_I_char(_char_(v82395[(v82390+2) - 1]))-48);
                      if ('%' == v82395[(v82390+2) - 1])
                       { v63821= CTRUE;
                        v82386= 1;
                        } 
                      else if ((v82386 < 0) || 
                          (v82386 > 9))
                       close_exception(((general_error *) (*Core._general_error)(_string_(CSTRING("[189] F requires a single digit integer in ~S")),
                        _oid_(list::alloc(1,_oid_(v13540))))));
                      if ((v63821 != CTRUE) && 
                          ('%' == v82395[(v82390+3) - 1]))
                       { v63821= CTRUE;
                        ++v82390;
                        } 
                      ++v82390;
                      { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                        (v88616->selector = Core.printFDigit);
                        { Call * v62636 = v88616; 
                          list * v62637;
                          { OID v_bag;
                            GC_ANY(v62637= list::empty(Kernel.emptySet));
                            if (v63821 == CTRUE)
                             { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                              (v88616->selector = Kernel._star);
                              (v88616->args = list::alloc(2,(*(v82388))[v82385],GC_OID(_float_(100.0))));
                              add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
                              v_bag = _oid_(v88616);
                              } 
                            else v_bag = (*(v82388))[v82385];
                              ((list *) v62637)->addFast(v_bag);
                            ((list *) v62637)->addFast(v82386);} 
                          (v62636->args = v62637);} 
                        add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
                        v32907 = _oid_(v88616);
                        } 
                      } 
                    else if ('I' == ((char) v82389->ascii))
                     v32907 = (*(v82388))[v82385];
                    else v32907 = Kernel.cfalse;
                      v82394 = v82394->addFast(v32907);
                    } 
                   GC__ANY(v82394, 7);} 
                GC__STRING(v82395 = substring_string(v82395,(v82390+2),1000), 4);
                v82390= get_string(v82395,_char_('~'));
                } 
              GC_UNLOOP;} 
            } 
          if (boolean_I_any(_string_(v82395)) == CTRUE)
           { OID  v35790;
            { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
              (v88616->selector = Kernel.princ);
              (v88616->args = list::alloc(1,_string_(v82395)));
              add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
              v35790 = _oid_(v88616);
              } 
            v82394 = v82394->addFast(v35790);
            } 
          { OID  v36751;
            { Do * v88616 = ((Do *) GC_OBJECT(Do,new_object_class(Language._Do)));
              (v88616->args = v82394);
              add_I_property(Kernel.instances,Language._Do,11,_oid_(v88616));
              v36751 = _oid_(v88616);
              } 
            Result = (*Optimize.c_code)(v36751,
              _oid_(Kernel._any));
            } 
          } 
        } 
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_Error_Optimize(Error *v13540)
{ return (Kernel.emptySet);} 

OID  c_code_Error_Optimize(Error *v13540)
{ GC_BIND;
  { OID Result = 0;
    { ClaireBoolean * v82400 = Optimize.OPT->allocation;
      OID  v82401;
      { { OID  v37712;
          { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
            (v88616->selector = Kernel.close);
            { Call * v63313 = v88616; 
              list * v63314;
              { OID v_bag;
                GC_ANY(v63314= list::empty(Kernel.emptySet));
                { { Cast * v88616 = ((Cast *) GC_OBJECT(Cast,new_object_class(Language._Cast)));
                    { Cast * v63315 = v88616; 
                      OID  v63316;
                      { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                        (v88616->selector = Optimize.anyObject_I);
                        { Call * v63317 = v88616; 
                          list * v63318;
                          { OID v_bag;
                            GC_ANY(v63318= list::empty(Kernel.emptySet));
                            ((list *) v63318)->addFast(_oid_(Core._general_error));
                            ((list *) v63318)->addFast(GC_OID((*Optimize.c_code)(GC_OID(car_list(v13540->args)),
                              _oid_(Kernel._any))));
                            { { OID  v34871;
                                if (v13540->args->length != 1)
                                 { List * v88616 = ((List *) GC_OBJECT(List,new_object_class(Language._List)));
                                  (v88616->args = cdr_list(GC_OBJECT(list,v13540->args)));
                                  add_I_property(Kernel.instances,Language._List,11,_oid_(v88616));
                                  v34871 = _oid_(v88616);
                                  } 
                                else v34871 = Core.nil->value;
                                  v_bag = (*Optimize.c_code)(v34871,
                                  _oid_(Kernel._any));
                                } 
                              GC_OID(v_bag);} 
                            ((list *) v63318)->addFast(v_bag);} 
                          (v63317->args = v63318);} 
                        add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
                        v63316 = _oid_(v88616);
                        } 
                      (v63315->arg = v63316);} 
                    (v88616->set_arg = Kernel._exception);
                    add_I_property(Kernel.instances,Language._Cast,11,_oid_(v88616));
                    v_bag = _oid_(v88616);
                    } 
                  GC_OID(v_bag);} 
                ((list *) v63314)->addFast(v_bag);} 
              (v63313->args = v63314);} 
            add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
            v37712 = _oid_(v88616);
            } 
          v82401 = (*Optimize.c_code)(v37712,
            _oid_(Kernel._void));
          } 
        GC_OID(v82401);} 
      (Optimize.OPT->allocation = v82400);
      Result = v82401;
      } 
    GC_UNBIND; return (Result);} 
  } 

ClaireType * extendedTest_ask_If(If *v13540)
{ GC_BIND;
  { ClaireType *Result ;
    { OID  v61575 = v13540->test;
      if (INHERIT(OWNER(v61575),Language._Call))
       { if ((INHERIT(OWNER((*(OBJECT(Call,v61575)->args))[1]),Language._Variable)) && 
            (OBJECT(Call,v61575)->selector == Core.known_ask))
         Result = OBJECT(ClaireType,(*Kernel.range)((*(OBJECT(Call,v61575)->args))[1]));
        else Result = Kernel._any;
          } 
      else Result = Kernel._any;
        } 
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_If_Optimize(If *v13540)
{ GC_BIND;
  { ClaireType *Result ;
    { ClaireType * v61573 = GC_OBJECT(ClaireType,extendedTest_ask_If(v13540));
      if (extended_ask_type(v61573) == CTRUE)
       range_sets_any(GC_OID((*(OBJECT(bag,(*Core.args)(GC_OID(v13540->test)))))[1]),GC_OBJECT(ClaireType,sort_abstract_I_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Core.t1)(_oid_(v61573)))))));
      { ClaireType * v75701 = GC_OBJECT(ClaireType,U_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(GC_OID(v13540->arg)))),GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(GC_OID(v13540->other))))));
        if (extended_ask_type(v61573) == CTRUE)
         put_property2(Kernel.range,GC_OBJECT(ClaireObject,OBJECT(ClaireObject,(*(OBJECT(bag,(*Core.args)(GC_OID(v13540->test)))))[1])),_oid_(v61573));
        Result = v75701;
        } 
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_If_Optimize(If *v13540,ClaireClass *v82395)
{ GC_BIND;
  { OID Result = 0;
    { ClaireType * v61573 = GC_OBJECT(ClaireType,extendedTest_ask_If(v13540));
      if (extended_ask_type(v61573) == CTRUE)
       range_sets_any(GC_OID((*(OBJECT(bag,(*Core.args)(GC_OID(v13540->test)))))[1]),GC_OBJECT(ClaireType,sort_abstract_I_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Core.t1)(_oid_(v61573)))))));
      if ((_inf_equal_type(GC_OBJECT(ClaireType,ptype_type(OBJECT(ClaireType,(*Optimize.c_type)(GC_OID(v13540->test))))),Kernel._boolean) != CTRUE) && 
          (Optimize.PENIBLE->value == Kernel.ctrue))
       { warn_void();
        tformat_string(CSTRING("CLAIRE 3.3 SYNTAX - Test in ~S should be a boolean [260]\n"),2,list::alloc(1,_oid_(v13540)));
        } 
      { If * v75701;
        { { If * v88616 = ((If *) GC_OBJECT(If,new_object_class(Language._If)));
            (v88616->test = c_boolean_any(GC_OID(v13540->test)));
            (v88616->arg = (*Optimize.c_code)(GC_OID(v13540->arg),
              _oid_(v82395)));
            (v88616->other = (*Optimize.c_code)(GC_OID(v13540->other),
              _oid_(v82395)));
            add_I_property(Kernel.instances,Language._If,11,_oid_(v88616));
            v75701 = v88616;
            } 
          GC_OBJECT(If,v75701);} 
        if (extended_ask_type(v61573) == CTRUE)
         put_property2(Kernel.range,GC_OBJECT(ClaireObject,OBJECT(ClaireObject,(*(OBJECT(bag,(*Core.args)(GC_OID(v13540->test)))))[1])),_oid_(v61573));
        Result = _oid_(v75701);
        } 
      } 
    GC_UNBIND; return (Result);} 
  } 

ClaireBoolean * c_gc_ask_If(If *v13540)
{ GC_BIND;
  { ClaireBoolean *Result ;
    Result = (((OBJECT(ClaireBoolean,(*Optimize.c_gc_ask)(v13540->arg))) == CTRUE) ? CTRUE : (((OBJECT(ClaireBoolean,(*Optimize.c_gc_ask)(v13540->other))) == CTRUE) ? CTRUE : CFALSE));
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_Case_Optimize(Case *v13540)
{ GC_RESERVE(6);  // v3.0.55 optim !
  { ClaireType *Result ;
    { OID  v65146 = GC_OID(v13540->var);
      OID  v16967;
      { if (INHERIT(OWNER(v65146),Language._Variable))
         v16967 = get_property(Kernel.range,OBJECT(ClaireObject,v65146));
        else v16967 = _oid_(Kernel._any);
          GC_OID(v16967);} 
      list * v82388 = GC_OBJECT(list,((list *) copy_bag(v13540->args)));
      ClaireType * v87060 = Kernel.emptySet;
      ClaireType * v105111 = Kernel.emptySet;
      { OID gc_local;
        while ((v82388->length > 0))
        { GC_LOOP;
          if (INHERIT(OWNER((*(v82388))[1]),Kernel._type))
           { GC__ANY(v105111 = U_type(v105111,OBJECT(ClaireType,(*(v82388))[1])), 6);
            if (osort_any(v16967) == osort_any((*(v82388))[1]))
             range_sets_any(v65146,OBJECT(ClaireType,(*(v82388))[1]));
            else if (osort_any(v16967) == Kernel._any)
             range_sets_any(v65146,GC_OBJECT(ClaireType,sort_abstract_I_type(OBJECT(ClaireType,(*(v82388))[1]))));
            } 
          else (*Optimize.Cerror)(_string_(CSTRING("[208] wrong type declaration for case: ~S in ~S")),
              GC_OID(car_list(v82388)),
              _oid_(v13540));
            GC__ANY(v87060 = U_type(v87060,GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)((*(v82388))[2])))), 5);
          if (INHERIT(OWNER(v65146),Language._Variable))
           store_object(OBJECT(ClaireObject,v65146),
            3,
            Kernel._object,
            v16967,
            CFALSE);
          GC__ANY(v82388 = skip_list(v82388,2), 4);
          GC_UNLOOP;} 
        } 
      if (_inf_equal_type(OBJECT(ClaireType,v16967),v105111) == CTRUE)
       Result = v87060;
      else Result = ((_inf_equal_type(v87060,Kernel._boolean) == CTRUE) ?
        Kernel._boolean :
        Kernel._any );
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_Case_Optimize(Case *v13540,ClaireClass *v82395)
{ GC_RESERVE(13);  // v3.0.55 optim !
  { OID Result = 0;
    { OID  v65146 = GC_OID(v13540->var);
      OID  v16967;
      { if (INHERIT(OWNER(v65146),Language._Variable))
         v16967 = get_property(Kernel.range,OBJECT(ClaireObject,v65146));
        else v16967 = _oid_(Kernel._any);
          GC_OID(v16967);} 
      list * v82388 = GC_OBJECT(list,((list *) copy_bag(v13540->args)));
      OID  v105111 = _oid_(Kernel.emptySet);
      OID  v94965;
      { { OID  v35832;
          { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
            (v88616->selector = Kernel._Z);
            (v88616->args = list::alloc(2,v65146,(*(v82388))[1]));
            add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
            v35832 = _oid_(v88616);
            } 
          v94965 = c_boolean_any(v35832);
          } 
        GC_OID(v94965);} 
      range_sets_any(v65146,OBJECT(ClaireType,(*(v82388))[1]));
      { If * v16389;
        { { If * v88616 = ((If *) GC_OBJECT(If,new_object_class(Language._If)));
            (v88616->test = v94965);
            (v88616->arg = (*Optimize.c_code)((*(v82388))[2],
              _oid_(v82395)));
            (v88616->other = (*Optimize.c_code)(Kernel.cfalse,
              _oid_(v82395)));
            add_I_property(Kernel.instances,Language._If,11,_oid_(v88616));
            v16389 = v88616;
            } 
          GC_OBJECT(If,v16389);} 
        If * v119205 = v16389;
        if (INHERIT(OWNER(v65146),Language._Variable))
         store_object(OBJECT(ClaireObject,v65146),
          3,
          Kernel._object,
          v16967,
          CFALSE);
        v82388= GC_OBJECT(list,skip_list(v82388,2));
        { OID gc_local;
          while ((v82388->length > 0))
          { GC_LOOP;
            GC__OID(v105111 = _oid_(U_type(OBJECT(ClaireType,v105111),OBJECT(ClaireType,(*(v82388))[1]))), 7);
            if (_inf_equal_type(OBJECT(ClaireType,v16967),OBJECT(ClaireType,v105111)) == CTRUE)
             { if (osort_any(v16967) == osort_any((*(v82388))[1]))
               range_sets_any(v65146,OBJECT(ClaireType,(*(v82388))[1]));
              else if (osort_any(v16967) == Kernel._any)
               range_sets_any(v65146,GC_OBJECT(ClaireType,sort_abstract_I_type(OBJECT(ClaireType,(*(v82388))[1]))));
              (v119205->other = (*Optimize.c_code)((*(v82388))[2],
                _oid_(v82395)));
              if (INHERIT(OWNER(v65146),Language._Variable))
               store_object(OBJECT(ClaireObject,v65146),
                3,
                Kernel._object,
                v16967,
                CFALSE);
              { ;break;} 
              } 
            else { OID  v108765;
                { { OID  v36793;
                    { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                      (v88616->selector = Kernel._Z);
                      (v88616->args = list::alloc(2,v65146,(*(v82388))[1]));
                      add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
                      v36793 = _oid_(v88616);
                      } 
                    v108765 = c_boolean_any(v36793);
                    } 
                  GC_OID(v108765);} 
                range_sets_any(v65146,OBJECT(ClaireType,(*(v82388))[1]));
                { If * v63322 = v119205; 
                  OID  v63344;
                  { If * v88616 = ((If *) GC_OBJECT(If,new_object_class(Language._If)));
                    (v88616->test = v108765);
                    (v88616->arg = (*Optimize.c_code)((*(v82388))[2],
                      _oid_(v82395)));
                    (v88616->other = (*Optimize.c_code)(Kernel.cfalse,
                      _oid_(v82395)));
                    add_I_property(Kernel.instances,Language._If,11,_oid_(v88616));
                    v63344 = _oid_(v88616);
                    } 
                  (v63322->other = v63344);} 
                GC__ANY(v119205 = OBJECT(If,v119205->other), 10);
                } 
              if (INHERIT(OWNER(v65146),Language._Variable))
             store_object(OBJECT(ClaireObject,v65146),
              3,
              Kernel._object,
              v16967,
              CFALSE);
            GC__ANY(v82388 = skip_list(v82388,2), 6);
            GC_UNLOOP;} 
          } 
        if ((INHERIT(OWNER(v65146),Language._Definition)) && (INHERIT(OBJECT(Definition,v65146)->arg->isa,Kernel._exception)))
         Result = v65146;
        else Result = _oid_(v16389);
          } 
      } 
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_Do_Optimize(Do *v13540)
{ GC_BIND;
  { ClaireType *Result ;
    Result = OBJECT(ClaireType,(*Optimize.c_type)(GC_OID(last_list(v13540->args))));
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_Do_Optimize(Do *v13540,ClaireClass *v82395)
{ GC_BIND;
  { OID Result = 0;
    { Do * v88616 = ((Do *) GC_OBJECT(Do,new_object_class(Language._Do)));
      { Do * v63345 = v88616; 
        list * v63346;
        { Cint  v82389 = v13540->args->length;
          Cint  v82390 = 0;
          { bag *v_list; OID v_val;
            OID v82400,CLcount;
            v_list = GC_OBJECT(list,v13540->args);
             v63346 = v_list->clone();
            for (CLcount= 1; CLcount <= v_list->length; CLcount++)
            { v82400 = (*(v_list))[CLcount];
              { ++v82390;
                { OID  v61779;
                  if (v82390 == v82389)
                   v61779 = _oid_(v82395);
                  else v61779 = _oid_(Kernel._void);
                    v_val = (*Optimize.c_code)(v82400,
                    v61779);
                  } 
                } 
              
              (*((list *) v63346))[CLcount] = v_val;} 
            } 
          } 
        (v63345->args = v63346);} 
      add_I_property(Kernel.instances,Language._Do,11,_oid_(v88616));
      Result = _oid_(v88616);
      } 
    GC_UNBIND; return (Result);} 
  } 

ClaireBoolean * c_gc_ask_Do(Do *v13540)
{ GC_BIND;
  { ClaireBoolean *Result ;
    Result = OBJECT(ClaireBoolean,(*Optimize.c_gc_ask)(GC_OID(last_list(v13540->args))));
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_Let_Optimize(Let *v13540)
{ GC_BIND;
  range_infers_Variable(GC_OBJECT(Variable,v13540->var),GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(GC_OID(v13540->value)))));
  { ClaireType *Result ;
    Result = OBJECT(ClaireType,(*Optimize.c_type)(GC_OID(v13540->arg)));
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_Let_Optimize(Let *v13540,ClaireClass *v82395)
{ GC_RESERVE(1);  // HOHO v3.0.55 optim !
  { OID Result = 0;
    { OID  v61589 = GC_OID(v13540->value);
      ClaireType * v16967 = GC_OBJECT(ClaireType,ptype_type(OBJECT(ClaireType,(*Optimize.c_type)(v61589))));
      range_infers_Variable(v13540->var,v16967);
      if (_inf_equal_type(v16967,GC_OBJECT(ClaireType,v13540->var->range)) != CTRUE)
       v61589= GC_OID(c_warn_Variable(GC_OBJECT(Variable,v13540->var),v61589,v16967));
      { Let * v82400;
        { { Let * v88616 = ((Let *) GC_OBJECT(Let,new_object_class(Language._Let)));
            (v88616->var = v13540->var);
            (v88616->value = c_gc_I_any2(GC_OID(c_strict_code_any(v61589,psort_any(_oid_(v13540->var->range)))),v16967));
            (v88616->arg = (*Optimize.c_code)(GC_OID(v13540->arg),
              _oid_(v82395)));
            add_I_property(Kernel.instances,Language._Let,11,_oid_(v88616));
            v82400 = v88616;
            } 
          GC_OBJECT(Let,v82400);} 
        (v82400->isa = v13540->isa);
        if ((INHERIT(v82400->isa,Language._Let_star)) && 
            ((INHERIT(v16967->isa,Kernel._tuple)) && 
              (BCONTAIN(c_status_any(GC_OID(v13540->value),Kernel.nil),1))))
         { Cint  v82385 = 1;
          OID  v82402 = GC_OID(v82400->arg);
          { OID gc_local;
            while (((INHERIT(OWNER(v82402),Language._Let)) && 
                (v82385 <= ((bag *) v16967)->length)))
            { GC_LOOP;
              if ((((OBJECT(ClaireBoolean,(*Optimize.gcsafe_ask)((*(((bag *) v16967)))[v82385]))) == CTRUE) ? CTRUE : ((INHERIT(owner_any((*Kernel.value)(v82402)),Optimize._to_protect)) ? CTRUE : CFALSE)) != CTRUE)
               { (Optimize.OPT->protection = CTRUE);
                { OID  v62740;
                  { Compile_to_protect * v88616 = ((Compile_to_protect *) GC_OBJECT(Compile_to_protect,new_object_class(Optimize._to_protect)));
                    (v88616->arg = (*Kernel.value)(v82402));
                    add_I_property(Kernel.instances,Optimize._to_protect,11,_oid_(v88616));
                    v62740 = _oid_(v88616);
                    } 
                  write_property(Kernel.value,OBJECT(ClaireObject,v82402),v62740);
                  } 
                } 
              ++v82385;
              GC__OID(v82402 = (*Kernel.arg)(v82402), 8);
              GC_UNLOOP;} 
            } 
          } 
        Result = _oid_(v82400);
        } 
      } 
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_When_Optimize(When *v13540)
{ GC_BIND;
  { ClaireType *Result ;
    { OID  v61589 = GC_OID(v13540->value);
      Variable * v82398 = GC_OBJECT(Variable,v13540->var);
      OID  v82380 = GC_OID(daccess_any(v61589,CTRUE));
      OID  v16967;
      { if (v82380 != CNULL)
         v16967 = (*Optimize.c_type)(v82380);
        else v16967 = (*Optimize.c_type)(v61589);
          GC_OID(v16967);} 
      if (extended_ask_type(OBJECT(ClaireType,v16967)) == CTRUE)
       v16967= GC_OID((*Core.t1)(v16967));
      range_infers_Variable(v82398,OBJECT(ClaireType,v16967));
      Result = U_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(GC_OID(v13540->arg)))),GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(GC_OID(v13540->other)))));
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_When_Optimize(When *v13540,ClaireClass *v82395)
{ GC_BIND;
  { OID Result = 0;
    { OID  v61589 = GC_OID(v13540->value);
      Variable * v82398 = GC_OBJECT(Variable,v13540->var);
      OID  v82380 = GC_OID(daccess_any(v61589,CTRUE));
      Variable * v64020 = GC_OBJECT(Variable,Variable_I_symbol(append_symbol(v13540->var->pname,_string_(CSTRING("test"))),v13540->var->index,Kernel._any));
      OID  v16967;
      { if (v82380 != CNULL)
         v16967 = (*Optimize.c_type)(v82380);
        else v16967 = (*Optimize.c_type)(v61589);
          GC_OID(v16967);} 
      if (extended_ask_type(OBJECT(ClaireType,v16967)) == CTRUE)
       v16967= GC_OID((*Core.t1)(v16967));
      range_infers_Variable(v82398,OBJECT(ClaireType,v16967));
      if ((v82380 != CNULL) && 
          (extended_ask_type(OBJECT(ClaireType,(*Kernel.range)(GC_OID((*Kernel.selector)(v82380))))) != CTRUE))
       { Let * v88616 = ((Let *) GC_OBJECT(Let,new_object_class(Language._Let)));
        (v88616->var = v82398);
        (v88616->value = c_gc_I_any2(v82380,OBJECT(ClaireType,v16967)));
        { Let * v63349 = v88616; 
          OID  v63350;
          { If * v88616 = ((If *) GC_OBJECT(If,new_object_class(Language._If)));
            { If * v63351 = v88616; 
              OID  v63352;
              { Call_method2 * v88616 = ((Call_method2 *) GC_OBJECT(Call_method2,new_object_class(Language._Call_method2)));
                (v88616->arg = ((method *) _at_property1(Core.identical_ask,Kernel._any)));
                (v88616->args = list::alloc(2,_oid_(v82398),GC_OID((*Optimize.c_code)(CNULL,
                  GC_OID((*Optimize.c_sort)(_oid_(v82398)))))));
                add_I_property(Kernel.instances,Language._Call_method2,11,_oid_(v88616));
                v63352 = _oid_(v88616);
                } 
              (v63351->test = v63352);} 
            (v88616->arg = (*Optimize.c_code)(GC_OID(v13540->other),
              _oid_(v82395)));
            (v88616->other = (*Optimize.c_code)(GC_OID(v13540->arg),
              _oid_(v82395)));
            add_I_property(Kernel.instances,Language._If,11,_oid_(v88616));
            v63350 = _oid_(v88616);
            } 
          (v63349->arg = v63350);} 
        add_I_property(Kernel.instances,Language._Let,11,_oid_(v88616));
        Result = _oid_(v88616);
        } 
      else if (((*Optimize.c_sort)(_oid_(v82398)) == _oid_(Kernel._any)) && 
          ((_inf_equal_type(OBJECT(ClaireType,v16967),GC_OBJECT(ClaireType,v82398->range)) == CTRUE) && 
            (3 <= Optimize.compiler->safety)))
       { OID  v67545;
        { Let * v88616 = ((Let *) GC_OBJECT(Let,new_object_class(Language._Let)));
          (v88616->var = v82398);
          (v88616->value = v61589);
          { Let * v63375 = v88616; 
            OID  v63376;
            { If * v88616 = ((If *) GC_OBJECT(If,new_object_class(Language._If)));
              { If * v63377 = v88616; 
                OID  v63378;
                { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                  (v88616->selector = Core._I_equal);
                  (v88616->args = list::alloc(2,_oid_(v82398),CNULL));
                  add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
                  v63378 = _oid_(v88616);
                  } 
                (v63377->test = v63378);} 
              (v88616->arg = v13540->arg);
              (v88616->other = v13540->other);
              add_I_property(Kernel.instances,Language._If,11,_oid_(v88616));
              v63376 = _oid_(v88616);
              } 
            (v63375->arg = v63376);} 
          add_I_property(Kernel.instances,Language._Let,11,_oid_(v88616));
          v67545 = _oid_(v88616);
          } 
        Result = (*Optimize.c_code)(v67545,
          _oid_(v82395));
        } 
      else { OID  v92531;
          { Let * v88616 = ((Let *) GC_OBJECT(Let,new_object_class(Language._Let)));
            (v88616->var = v64020);
            (v88616->value = v61589);
            { Let * v63380 = v88616; 
              OID  v63381;
              { If * v88616 = ((If *) GC_OBJECT(If,new_object_class(Language._If)));
                { If * v63382 = v88616; 
                  OID  v63383;
                  { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                    (v88616->selector = Core._I_equal);
                    (v88616->args = list::alloc(2,_oid_(v64020),CNULL));
                    add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
                    v63383 = _oid_(v88616);
                    } 
                  (v63382->test = v63383);} 
                { If * v63384 = v88616; 
                  OID  v63406;
                  { Let * v88616 = ((Let *) GC_OBJECT(Let,new_object_class(Language._Let)));
                    (v88616->var = v82398);
                    { Let * v63407 = v88616; 
                      OID  v63408;
                      { Cast * v88616 = ((Cast *) GC_OBJECT(Cast,new_object_class(Language._Cast)));
                        (v88616->arg = _oid_(v64020));
                        (v88616->set_arg = OBJECT(ClaireType,v16967));
                        add_I_property(Kernel.instances,Language._Cast,11,_oid_(v88616));
                        v63408 = _oid_(v88616);
                        } 
                      (v63407->value = v63408);} 
                    (v88616->arg = v13540->arg);
                    add_I_property(Kernel.instances,Language._Let,11,_oid_(v88616));
                    v63406 = _oid_(v88616);
                    } 
                  (v63384->arg = v63406);} 
                (v88616->other = (*Optimize.c_code)(GC_OID(v13540->other),
                  _oid_(v82395)));
                add_I_property(Kernel.instances,Language._If,11,_oid_(v88616));
                v63381 = _oid_(v88616);
                } 
              (v63380->arg = v63381);} 
            add_I_property(Kernel.instances,Language._Let,11,_oid_(v88616));
            v92531 = _oid_(v88616);
            } 
          Result = (*Optimize.c_code)(v92531,
            _oid_(v82395));
          } 
        } 
    GC_UNBIND; return (Result);} 
  } 

ClaireBoolean * c_gc_ask_Let(Let *v13540)
{ GC_BIND;
  { ClaireBoolean *Result ;
    Result = OBJECT(ClaireBoolean,(*Optimize.c_gc_ask)(v13540->arg));
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_For_Optimize(For *v13540)
{ GC_BIND;
  { ClaireType *Result ;
    Result = infers_from_type2(GC_OBJECT(ClaireType,return_type_any(GC_OID(v13540->arg))),_oid_(v13540));
    GC_UNBIND; return (Result);} 
  } 

ClaireType * infers_from_type2(ClaireType *v82396,OID v13540)
{ if (equal(_oid_(v82396),_oid_(Kernel.emptySet)) == CTRUE) 
  { { ClaireType *Result ;
      Result = sort_abstract_I_type(Kernel._boolean);
      return (Result);} 
     } 
  else{ GC_BIND;
    { ClaireType *Result ;
      if (Optimize.compiler->safety > 3)
       { tformat_string(CSTRING("... c_type(~S) -> ~S - ~S \n"),2,list::alloc(3,v13540,
          _oid_(v82396),
          GC_OID(_oid_(sort_abstract_I_type(v82396)))));
        Result = sort_abstract_I_type(v82396);
        } 
      else Result = Kernel._any;
        GC_UNBIND; return (Result);} 
    } 
  } 

OID  c_code_For_Optimize(For *v13540,ClaireClass *v82395)
{ GC_BIND;
  { OID Result = 0;
    { OID  v63997 = GC_OID(v13540->set_arg);
      ClaireBoolean * v82378 = Optimize.OPT->protection;
      Cint  v63837 = Optimize.compiler->safety;
      Variable * v112521 = GC_OBJECT(Variable,v13540->var);
      Variable * v82398;
      { { Variable * v88616 = ((Variable *) GC_OBJECT(Variable,new_object_class(Language._Variable)));
          (v88616->pname = v112521->pname);
          (v88616->range = v112521->range);
          (v88616->index = v112521->index);
          add_I_property(Kernel.instances,Language._Variable,11,_oid_(v88616));
          v82398 = v88616;
          } 
        GC_OBJECT(Variable,v82398);} 
      OID  v123072 = GC_OID(substitution_any(v13540->arg,v112521,_oid_(v82398)));
      OID  v17291 = GC_OID(c_inline_arg_ask_any(v63997));
      (Optimize.OPT->protection = CFALSE);
      if (INHERIT(OWNER(v63997),Core._global_variable))
       { if (boolean_I_any(_oid_(OBJECT(global_variable,v63997)->range)) != CTRUE)
         { (v13540->set_arg = OBJECT(global_variable,v63997)->value);
          v63997= GC_OID(OBJECT(global_variable,v63997)->value);
          } 
        } 
      else if (INHERIT(OWNER(v63997),Language._Select))
       { ClaireType * v61575 = GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(v63997)));
        if ((_inf_equal_type(v61575,Kernel._bag) != CTRUE) || 
            (_inf_equal_type(v61575,Kernel._set) == CTRUE))
         { v13540= GC_OBJECT(For,((For *) copy_object(v13540)));
          (v13540->isa = Language._Select);
          } 
        } 
      else if (INHERIT(OWNER(v63997),Kernel._class))
       { if ((OBJECT(ClaireClass,v63997)->open <= 1) && 
            (boolean_I_any(_oid_(OBJECT(ClaireClass,v63997)->subclass)) != CTRUE))
         { Iteration * v63409 = v13540; 
          OID  v63410;
          { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
            (v88616->selector = Kernel.instances);
            (v88616->args = list::alloc(1,v63997));
            add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
            v63410 = _oid_(v88616);
            } 
          (v63409->set_arg = v63410);} 
        } 
      { OID  v61575 = GC_OID((*Optimize.c_type)(GC_OID(v13540->set_arg)));
        ClaireType * v73867 = GC_OBJECT(ClaireType,pmember_type(OBJECT(ClaireType,v61575)));
        ClaireType * v73868;
        { { ClaireType * v123283;
            { { OID v55170;{ OID  v124244;
                  { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                    (v88616->selector = Kernel.set_I);
                    (v88616->args = list::alloc(1,v63997));
                    add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
                    v124244 = _oid_(v88616);
                    } 
                  v55170 = (*Optimize.c_type)(v124244);
                  } 
                
                v123283=OBJECT(ClaireType,v55170);} 
              GC_OBJECT(ClaireType,v123283);} 
            v73868 = pmember_type(v123283);
            } 
          GC_OBJECT(ClaireType,v73868);} 
        if (_inf_equal_type(v73868,v73867) == CTRUE)
         v73867= v73868;
        range_infers_for_Variable(v82398,v73867,OBJECT(ClaireType,v61575));
        (Optimize.compiler->safety = 1);
        v73867= GC_OBJECT(ClaireType,v82398->range);
        (v82398->range = ptype_type(v73867));
        { OID  v82389 = GC_OID(Iterate_I_Iteration(v13540));
          if (equal(_oid_(Kernel._method),_oid_(OWNER(v82389))) != CTRUE)
           { OID  v63741 = GC_OID(restriction_I_property(Language.iterate,list::alloc(3,v61575,
              _oid_(set::alloc(1,_oid_(v82398))),
              _oid_(Kernel._any)),CTRUE));
            if (Kernel._method == OWNER(v63741))
             v82389= v63741;
            } 
          (Optimize.compiler->safety = v63837);
          (v82398->range = v73867);
          { OID  v82394;
            { if ((Kernel._method == OWNER(v82389)) && (OBJECT(method,v82389)->inline_ask == CTRUE))
               { if ((Optimize.compiler->safety < 6) && 
                    (BCONTAIN(c_status_any(v123072,Kernel.nil),1)))
                 (Optimize.OPT->loop_gc = CTRUE);
                if (sort_abstract_ask_type(v82398->range) == CTRUE)
                 (v82398->range = CLREAD(Union,v82398->range,t2));
                v82394 = c_inline_method1(OBJECT(method,v82389),list::alloc(3,GC_OID(instruction_copy_any(GC_OID(v13540->set_arg))),
                  _oid_(v82398),
                  v123072),v82395);
                } 
              else if (boolean_I_any(v17291) == CTRUE)
               { OID  v125205;
                { For * v88616 = ((For *) GC_OBJECT(For,new_object_class(Language._For)));
                  (v88616->var = v82398);
                  (v88616->set_arg = v17291);
                  (v88616->arg = v123072);
                  add_I_property(Kernel.instances,Language._For,11,_oid_(v88616));
                  v125205 = _oid_(v88616);
                  } 
                v82394 = (*Optimize.c_code)(v125205,
                  _oid_(v82395));
                } 
              else if ((INHERIT(OWNER(v63997),Language._Call)) && (OBJECT(Call,v63997)->selector == Core.Id))
               v82394 = c_code_multiple_For(v13540,OBJECT(ClaireType,v61575),v82395);
              else { For * v63896;
                  { { For * v88616 = ((For *) GC_OBJECT(For,new_object_class(Language._For)));
                      (v88616->var = v82398);
                      (v88616->set_arg = c_gc_I_any1(GC_OID(enumerate_code_any(GC_OID(v13540->set_arg),OBJECT(ClaireType,v61575)))));
                      (v88616->arg = (*Optimize.c_code)(v123072,
                        _oid_(Kernel._void)));
                      add_I_property(Kernel.instances,Language._For,11,_oid_(v88616));
                      v63896 = v88616;
                      } 
                    GC_OBJECT(For,v63896);} 
                  if (v82395 == Kernel._any)
                   v82394 = _oid_(v63896);
                  else { Compile_to_C * v88616 = ((Compile_to_C *) GC_OBJECT(Compile_to_C,new_object_class(Optimize._to_C)));
                      (v88616->arg = _oid_(v63896));
                      (v88616->set_arg = v82395);
                      add_I_property(Kernel.instances,Optimize._to_C,11,_oid_(v88616));
                      v82394 = _oid_(v88616);
                      } 
                    } 
                GC_OID(v82394);} 
            if ((Optimize.OPT->protection == CTRUE) && 
                ((0 <= Optimize.OPT->loop_index) && 
                  (Optimize.compiler->safety < 6)))
             (Optimize.OPT->loop_gc = CTRUE);
            (Optimize.OPT->protection = ((Optimize.OPT->protection == CTRUE) ? CTRUE : ((v82378 == CTRUE) ? CTRUE : CFALSE)));
            Result = v82394;
            } 
          } 
        } 
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_multiple_For(For *v13540,ClaireType *v61575,ClaireClass *v82395)
{ GC_RESERVE(14);  // v3.0.55 optim !
  { OID Result = 0;
    { Variable * v82398 = GC_OBJECT(Variable,v13540->var);
      OID  v63997 = GC_OID((*(OBJECT(Call,v13540->set_arg)->args))[1]);
      Variable * v64020 = GC_OBJECT(Variable,Variable_I_symbol(append_symbol(v82398->pname,_string_(CSTRING("test"))),v13540->var->index,v61575));
      Let * v82390;
      { { Let * v88616 = ((Let *) GC_OBJECT(Let,new_object_class(Language._Let)));
          (v88616->var = v64020);
          (v88616->value = v63997);
          { Let * v63414 = v88616; 
            OID  v63415;
            { For * v88616 = ((For *) GC_OBJECT(For,new_object_class(Language._For)));
              (v88616->var = v13540->var);
              (v88616->set_arg = enumerate_code_any(v63997,v61575));
              (v88616->arg = v13540->arg);
              add_I_property(Kernel.instances,Language._For,11,_oid_(v88616));
              v63415 = _oid_(v88616);
              } 
            (v63414->arg = v63415);} 
          add_I_property(Kernel.instances,Language._Let,11,_oid_(v88616));
          v82390 = v88616;
          } 
        GC_OBJECT(Let,v82390);} 
      tformat_string(CSTRING("---- note: use an expended iteration for {~S} \n"),0,list::alloc(1,_oid_(v13540)));
      { OID gc_local;
        ITERATE(v82394);
        for (START(Language.iterate->restrictions); NEXT(v82394);)
        { GC_LOOP;
          if ((_inf_equalt_class(domain_I_restriction(OBJECT(restriction,v82394)),v61575) == CTRUE) && 
              ((_inf_equalt_class(domain_I_restriction(OBJECT(restriction,v82394)),Kernel._collection) == CTRUE) && 
                ((OBJECT(method,v82394)->inline_ask == CTRUE) && 
                  (belong_to(_oid_(v82398),(*(OBJECT(restriction,v82394)->domain))[2]) == CTRUE))))
           { Variable * v111362;
            { { Variable * v88616 = ((Variable *) GC_OBJECT(Variable,new_object_class(Language._Variable)));
                (v88616->pname = v82398->pname);
                (v88616->range = v82398->range);
                (v88616->index = v82398->index);
                add_I_property(Kernel.instances,Language._Variable,11,_oid_(v88616));
                v111362 = v88616;
                } 
              GC_OBJECT(Variable,v111362);} 
            OID  v123072 = GC_OID(substitution_any(v13540->arg,v82398,_oid_(v111362)));
            { Let * v63437 = v82390; 
              OID  v63438;
              { If * v88616 = ((If *) GC_OBJECT(If,new_object_class(Language._If)));
                { If * v63439 = v88616; 
                  OID  v63440;
                  { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                    (v88616->selector = Kernel._Z);
                    (v88616->args = list::alloc(2,_oid_(v64020),(*(OBJECT(restriction,v82394)->domain))[1]));
                    add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
                    v63440 = _oid_(v88616);
                    } 
                  (v63439->test = v63440);} 
                { If * v63441 = v88616; 
                  OID  v63442;
                  { if ((Optimize.compiler->safety < 6) && 
                        (BCONTAIN(c_status_any(GC_OID(v13540->arg),Kernel.nil),1)))
                     (Optimize.OPT->loop_gc = CTRUE);
                    if (sort_abstract_ask_type(v111362->range) == CTRUE)
                     (v111362->range = CLREAD(Union,v82398->range,t2));
                    v63442 = c_inline_method1(OBJECT(method,v82394),GC_OBJECT(list,list::alloc(3,_oid_(v64020),
                      _oid_(v111362),
                      v123072)),v82395);
                    } 
                  (v63441->arg = v63442);} 
                (v88616->other = v82390->arg);
                add_I_property(Kernel.instances,Language._If,11,_oid_(v88616));
                v63438 = _oid_(v88616);
                } 
              (v63437->arg = v63438);} 
            } 
          GC_UNLOOP;} 
        } 
      Result = (*Optimize.c_code)(_oid_(v82390),
        _oid_(v82395));
      } 
    GC_UNBIND; return (Result);} 
  } 

ClaireBoolean * c_gc_ask_Iteration(Iteration *v13540)
{ return (CTRUE);} 

ClaireType * c_type_Iteration_Optimize(Iteration *v13540)
{ GC_BIND;
  { ClaireType *Result ;
    { OID  v61575 = GC_OID((*Optimize.c_type)(GC_OID(v13540->set_arg)));
      range_infers_for_Variable(GC_OBJECT(Variable,v13540->var),GC_OBJECT(ClaireType,pmember_type(OBJECT(ClaireType,v61575))),OBJECT(ClaireType,v61575));
      Result = ((get_property(Kernel.of,v13540) != CNULL) ?
        param_I_class((((INHERIT(v13540->isa,Language._Select)) || 
            (INHERIT(v13540->isa,Language._Image))) ?
          Kernel._set :
          Kernel._list ),GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Kernel.of)(_oid_(v13540))))) :
        nth_class1((((INHERIT(v13540->isa,Language._Select)) || 
            (INHERIT(v13540->isa,Language._Image))) ?
          Kernel._set :
          Kernel._list ),GC_OBJECT(ClaireType,(((INHERIT(v13540->isa,Language._Select)) || 
            (INHERIT(v13540->isa,Language._Lselect))) ?
          pmember_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(GC_OID(v13540->set_arg))))) :
          ptype_type(OBJECT(ClaireType,(*Optimize.c_type)(GC_OID(v13540->arg)))) ))) );
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_Iteration_Optimize(Iteration *v13540)
{ GC_BIND;
  { OID Result = 0;
    { OID  v63997 = GC_OID(v13540->set_arg);
      OID  v61575 = GC_OID((*Optimize.c_type)(v63997));
      if (INHERIT(v13540->isa,Language._For))
       Result = (*Optimize.c_code)(_oid_(v13540),
        _oid_(Kernel._any));
      else if ((INHERIT(v13540->isa,Language._Collect)) && (_inf_equal_type(OBJECT(ClaireType,v61575),Kernel._bag) == CTRUE))
       { (Optimize.OPT->allocation = CTRUE);
        range_infers_for_Variable(GC_OBJECT(Variable,v13540->var),GC_OBJECT(ClaireType,pmember_type(OBJECT(ClaireType,v61575))),OBJECT(ClaireType,v61575));
        { ClaireType * v64029 = GC_OBJECT(ClaireType,ptype_type(OBJECT(ClaireType,(*Optimize.c_type)(GC_OID(v13540->arg)))));
          Collect * v82400;
          { { Collect * v88616 = ((Collect *) GC_OBJECT(Collect,new_object_class(Language._Collect)));
              (v88616->var = v13540->var);
              (v88616->set_arg = c_gc_I_any1(GC_OID(c_strict_code_any(v63997,Kernel._bag))));
              (v88616->arg = (*Optimize.c_code)(GC_OID(v13540->arg),
                _oid_(Kernel._any)));
              add_I_property(Kernel.instances,Language._Collect,11,_oid_(v88616));
              v82400 = v88616;
              } 
            GC_OBJECT(Collect,v82400);} 
          if (v64029 == Kernel._void)
           (*Optimize.Cerror)(_string_(CSTRING("[205] use of void expression ~S in ~S")),
            GC_OID(v13540->arg),
            _oid_(v13540));
          if (get_property(Kernel.of,v13540) != CNULL)
           { if ((Optimize.compiler->safety > 4) || 
                (_inf_equal_type(v64029,GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Kernel.of)(_oid_(v13540))))) == CTRUE))
             { update_property(Kernel.of,
                v82400,
                5,
                Kernel._object,
                GC_OID((*Kernel.of)(_oid_(v13540))));
              Result = _oid_(v82400);
              } 
            else { warn_void();
                tformat_string(CSTRING("unsafe typed collect (~S): ~S not in ~S [261]\n"),2,list::alloc(3,_oid_(v13540),
                  GC_OID((*Optimize.c_type)(GC_OID(v13540->arg))),
                  GC_OID((*Kernel.of)(_oid_(v13540)))));
                { OID  v23924;
                  { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                    (v88616->selector = Core.check_in);
                    (v88616->args = list::alloc(3,_oid_(v82400),
                      _oid_(Kernel._list),
                      GC_OID((*Kernel.of)(_oid_(v13540)))));
                    add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
                    v23924 = _oid_(v88616);
                    } 
                  Result = (*Optimize.c_code)(v23924,
                    _oid_(Kernel._list));
                  } 
                } 
              } 
          else Result = _oid_(v82400);
            } 
        } 
      else { OID  v20105;
          if (INHERIT(v13540->isa,Language._Image))
           v20105 = _oid_(set::empty());
          else v20105 = _oid_(list::empty());
            Variable * v82398;
          { { Cint  v24885;
              { (Optimize.OPT->max_vars = (Optimize.OPT->max_vars+1));
                v24885 = 0;
                } 
              v82398 = Variable_I_symbol(append_symbol(v13540->var->pname,_string_(CSTRING("_bag"))),v24885,((INHERIT(v13540->isa,Language._Image)) ?
                Kernel._set :
                Kernel._list ));
              } 
            GC_OBJECT(Variable,v82398);} 
          if (get_property(Kernel.of,v13540) != CNULL)
           { ClaireType * v54732 = GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(GC_OID(v13540->arg))));
            if ((_inf_equal_type(GC_OBJECT(ClaireType,ptype_type(v54732)),GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Kernel.of)(_oid_(v13540))))) != CTRUE) && 
                (Optimize.compiler->safety <= 4))
             { warn_void();
              tformat_string(CSTRING("unsafe bag construction (~S) : a ~S is not a ~S [262]\n"),2,list::alloc(3,GC_OID(_oid_(v13540->var)),
                _oid_(v54732),
                GC_OID((*Kernel.of)(_oid_(v13540)))));
              } 
            cast_I_bag(OBJECT(bag,v20105),OBJECT(ClaireType,(*Kernel.of)(_oid_(v13540))));
            (v82398->range = param_I_class(GC_OBJECT(ClaireClass,((ClaireClass *) v82398->range)),GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Kernel.of)(_oid_(v13540))))));
            } 
          else if (Kernel._set == OWNER(v20105))
             { Set * v88616 = ((Set *) GC_OBJECT(Set,new_object_class(Language._Set)));
              (v88616->of = Kernel.emptySet);
              add_I_property(Kernel.instances,Language._Set,11,_oid_(v88616));
              v20105 = _oid_(v88616);
              } 
            else { List * v88616 = ((List *) GC_OBJECT(List,new_object_class(Language._List)));
                (v88616->of = Kernel.emptySet);
                add_I_property(Kernel.instances,Language._List,11,_oid_(v88616));
                v20105 = _oid_(v88616);
                } 
              { Let * v88616 = ((Let *) GC_OBJECT(Let,new_object_class(Language._Let)));
            (v88616->var = v82398);
            (v88616->value = v20105);
            { Let * v63446 = v88616; 
              OID  v63468;
              { Do * v88616 = ((Do *) GC_OBJECT(Do,new_object_class(Language._Do)));
                { Do * v63469 = v88616; 
                  list * v63470;
                  { OID v_bag;
                    GC_ANY(v63470= list::empty(Kernel.emptySet));
                    { { OID  v49871;
                        { For * v88616 = ((For *) GC_OBJECT(For,new_object_class(Language._For)));
                          (v88616->var = v13540->var);
                          (v88616->set_arg = v63997);
                          { Iteration * v63472 = v88616; 
                            OID  v63473;
                            { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                              (v88616->selector = Kernel.add_I);
                              (v88616->args = list::alloc(2,_oid_(v82398),GC_OID(v13540->arg)));
                              add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
                              v63473 = _oid_(v88616);
                              } 
                            (v63472->arg = v63473);} 
                          add_I_property(Kernel.instances,Language._For,11,_oid_(v88616));
                          v49871 = _oid_(v88616);
                          } 
                        v_bag = (*Optimize.c_code)(v49871,
                          _oid_(Kernel._any));
                        } 
                      GC_OID(v_bag);} 
                    ((list *) v63470)->addFast(v_bag);
                    if (Optimize.OPT->online_ask != CTRUE)
                     { (Optimize.OPT->protection = CTRUE);
                      { Compile_to_protect * v88616 = ((Compile_to_protect *) GC_OBJECT(Compile_to_protect,new_object_class(Optimize._to_protect)));
                        (v88616->arg = _oid_(v82398));
                        add_I_property(Kernel.instances,Optimize._to_protect,11,_oid_(v88616));
                        v_bag = _oid_(v88616);
                        } 
                      } 
                    else v_bag = _oid_(v82398);
                      ((list *) v63470)->addFast(v_bag);} 
                  (v63469->args = v63470);} 
                add_I_property(Kernel.instances,Language._Do,11,_oid_(v88616));
                v63468 = _oid_(v88616);
                } 
              (v63446->arg = v63468);} 
            add_I_property(Kernel.instances,Language._Let,11,_oid_(v88616));
            Result = _oid_(v88616);
            } 
          } 
        } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_Select_Optimize(Select *v13540)
{ return (c_code_select_Iteration(v13540,Kernel._set));} 

OID  c_code_Lselect_Optimize(Lselect *v13540)
{ return (c_code_select_Iteration(v13540,Kernel._list));} 

OID  c_code_select_Iteration(Iteration *v13540,ClaireClass *v82400)
{ GC_BIND;
  { OID Result = 0;
    { OID  v63997 = GC_OID(v13540->set_arg);
      OID  v61575 = GC_OID((*Optimize.c_type)(v63997));
      OID  v63993 = GC_OID(enumerate_code_any(v63997,OBJECT(ClaireType,v61575)));
      bag * v20105;
      if (v82400 == Kernel._set)
       v20105 = set::empty();
      else v20105 = list::empty();
        Variable * v64019;
      { { Cint  v54676;
          { (Optimize.OPT->max_vars = (Optimize.OPT->max_vars+1));
            v54676 = 0;
            } 
          v64019 = Variable_I_symbol(append_symbol(v13540->var->pname,_string_(CSTRING("_in"))),v54676,Kernel._bag);
          } 
        GC_OBJECT(Variable,v64019);} 
      Variable * v64020;
      { { Cint  v55637;
          { (Optimize.OPT->max_vars = (Optimize.OPT->max_vars+1));
            v55637 = 0;
            } 
          v64020 = Variable_I_symbol(append_symbol(v13540->var->pname,_string_(CSTRING("_out"))),v55637,v82400);
          } 
        GC_OBJECT(Variable,v64020);} 
      if (get_property(Kernel.of,v13540) != CNULL)
       { ClaireType * v54732 = GC_OBJECT(ClaireType,pmember_type(OBJECT(ClaireType,v61575)));
        if ((_inf_equal_type(GC_OBJECT(ClaireType,ptype_type(v54732)),GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Kernel.of)(_oid_(v13540))))) != CTRUE) && 
            (Optimize.compiler->safety <= 4))
         { warn_void();
          tformat_string(CSTRING("unsafe bag construction (~S) : a ~S is not a ~S [262]\n"),2,list::alloc(3,GC_OID(_oid_(v13540->var)),
            _oid_(v54732),
            GC_OID((*Kernel.of)(_oid_(v13540)))));
          } 
        cast_I_bag(v20105,OBJECT(ClaireType,(*Kernel.of)(_oid_(v13540))));
        (v64020->range = param_I_class(v82400,GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Kernel.of)(_oid_(v13540))))));
        Result = inner_select_Iteration(v13540,_oid_(v64020),v63997,_oid_(v20105));
        } 
      else if (_inf_equal_type(OBJECT(ClaireType,v61575),v82400) == CTRUE)
       { Let * v88616 = ((Let *) GC_OBJECT(Let,new_object_class(Language._Let)));
        (v88616->var = v64019);
        (v88616->value = v63993);
        { Let * v63499 = v88616; 
          OID  v63500;
          { OID  v78701;
            { Compile_C_cast * v88616 = ((Compile_C_cast *) GC_OBJECT(Compile_C_cast,new_object_class(Optimize._C_cast)));
              { Compile_to_C * v63502 = v88616; 
                OID  v63503;
                { OID  v81584;
                  { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                    (v88616->selector = Kernel.empty);
                    (v88616->args = list::alloc(1,_oid_(v64019)));
                    add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
                    v81584 = _oid_(v88616);
                    } 
                  v63503 = (*Optimize.c_code)(v81584,
                    _oid_(Kernel._bag));
                  } 
                (v63502->arg = v63503);} 
              (v88616->set_arg = v82400);
              add_I_property(Kernel.instances,Optimize._C_cast,11,_oid_(v88616));
              v78701 = _oid_(v88616);
              } 
            v63500 = inner_select_Iteration(v13540,_oid_(v64020),_oid_(v64019),v78701);
            } 
          (v63499->arg = v63500);} 
        add_I_property(Kernel.instances,Language._Let,11,_oid_(v88616));
        Result = _oid_(v88616);
        } 
      else { OID  v82545;
          if (v82400 == Kernel._set)
           { Set * v88616 = ((Set *) GC_OBJECT(Set,new_object_class(Language._Set)));
            (v88616->of = Kernel.emptySet);
            add_I_property(Kernel.instances,Language._Set,11,_oid_(v88616));
            v82545 = _oid_(v88616);
            } 
          else { List * v88616 = ((List *) GC_OBJECT(List,new_object_class(Language._List)));
              (v88616->of = Kernel.emptySet);
              add_I_property(Kernel.instances,Language._List,11,_oid_(v88616));
              v82545 = _oid_(v88616);
              } 
            Result = inner_select_Iteration(v13540,_oid_(v64020),v63997,v82545);
          } 
        } 
    GC_UNBIND; return (Result);} 
  } 

OID  inner_select_Iteration(Iteration *v13540,OID v64020,OID v63997,OID v20105)
{ GC_BIND;
  { OID Result = 0;
    { Let * v88616 = ((Let *) GC_OBJECT(Let,new_object_class(Language._Let)));
      store_object(v88616,
        2,
        Kernel._object,
        v64020,
        CFALSE);
      (v88616->value = v20105);
      { Let * v63506 = v88616; 
        OID  v63507;
        { Do * v88616 = ((Do *) GC_OBJECT(Do,new_object_class(Language._Do)));
          { Do * v63508 = v88616; 
            list * v63530;
            { OID v_bag;
              GC_ANY(v63530= list::empty(Kernel.emptySet));
              { { OID  v107531;
                  { For * v88616 = ((For *) GC_OBJECT(For,new_object_class(Language._For)));
                    (v88616->var = v13540->var);
                    (v88616->set_arg = v63997);
                    { Iteration * v63532 = v88616; 
                      OID  v63533;
                      { If * v88616 = ((If *) GC_OBJECT(If,new_object_class(Language._If)));
                        (v88616->test = v13540->arg);
                        { If * v63534 = v88616; 
                          OID  v63535;
                          { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                            (v88616->selector = Kernel.add_I);
                            (v88616->args = list::alloc(2,v64020,GC_OID(_oid_(v13540->var))));
                            add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
                            v63535 = _oid_(v88616);
                            } 
                          (v63534->arg = v63535);} 
                        add_I_property(Kernel.instances,Language._If,11,_oid_(v88616));
                        (v88616->other = Kernel.cfalse);
                        v63533 = _oid_(v88616);
                        } 
                      (v63532->arg = v63533);} 
                    add_I_property(Kernel.instances,Language._For,11,_oid_(v88616));
                    v107531 = _oid_(v88616);
                    } 
                  v_bag = (*Optimize.c_code)(v107531,
                    _oid_(Kernel._any));
                  } 
                GC_OID(v_bag);} 
              ((list *) v63530)->addFast(v_bag);
              if (Optimize.OPT->online_ask != CTRUE)
               { (Optimize.OPT->protection = CTRUE);
                { Compile_to_protect * v88616 = ((Compile_to_protect *) GC_OBJECT(Compile_to_protect,new_object_class(Optimize._to_protect)));
                  (v88616->arg = v64020);
                  add_I_property(Kernel.instances,Optimize._to_protect,11,_oid_(v88616));
                  v_bag = _oid_(v88616);
                  } 
                } 
              else v_bag = v64020;
                ((list *) v63530)->addFast(v_bag);} 
            (v63508->args = v63530);} 
          add_I_property(Kernel.instances,Language._Do,11,_oid_(v88616));
          v63507 = _oid_(v88616);
          } 
        (v63506->arg = v63507);} 
      add_I_property(Kernel.instances,Language._Let,11,_oid_(v88616));
      Result = _oid_(v88616);
      } 
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_Exists_Optimize(Exists *v13540)
{ GC_BIND;
  { ClaireType *Result ;
    { OID  v61575 = GC_OID((*Optimize.c_type)(GC_OID(v13540->set_arg)));
      range_infers_for_Variable(GC_OBJECT(Variable,v13540->var),GC_OBJECT(ClaireType,pmember_type(OBJECT(ClaireType,v61575))),OBJECT(ClaireType,v61575));
      if (v13540->other == CNULL)
       Result = extends_type(GC_OBJECT(ClaireType,pmember_type(OBJECT(ClaireType,v61575))));
      else Result = Kernel._boolean;
        } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_Exists_Optimize(Exists *v13540,ClaireClass *v82395)
{ GC_BIND;
  { OID Result = 0;
    { OID  v61575 = GC_OID((*Optimize.c_type)(GC_OID(v13540->set_arg)));
      range_infers_for_Variable(GC_OBJECT(Variable,v13540->var),GC_OBJECT(ClaireType,pmember_type(OBJECT(ClaireType,v61575))),OBJECT(ClaireType,v61575));
      if (v13540->other == Kernel.ctrue)
       { OID  v113297;
        { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
          (v88616->selector = Core.NOT);
          { Call * v63538 = v88616; 
            list * v63539;
            { OID v_bag;
              GC_ANY(v63539= list::empty(Kernel.emptySet));
              { { For * v88616 = ((For *) GC_OBJECT(For,new_object_class(Language._For)));
                  (v88616->var = v13540->var);
                  (v88616->set_arg = v13540->set_arg);
                  { Iteration * v63561 = v88616; 
                    OID  v63562;
                    { If * v88616 = ((If *) GC_OBJECT(If,new_object_class(Language._If)));
                      { If * v63563 = v88616; 
                        OID  v63564;
                        { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                          (v88616->selector = Core.NOT);
                          (v88616->args = list::alloc(1,GC_OID(v13540->arg)));
                          add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
                          v63564 = _oid_(v88616);
                          } 
                        (v63563->test = v63564);} 
                      { If * v63565 = v88616; 
                        OID  v63566;
                        { Return * v88616 = ((Return *) GC_OBJECT(Return,new_object_class(Language._Return)));
                          (v88616->arg = Kernel.ctrue);
                          add_I_property(Kernel.instances,Language._Return,11,_oid_(v88616));
                          v63566 = _oid_(v88616);
                          } 
                        (v63565->arg = v63566);} 
                      add_I_property(Kernel.instances,Language._If,11,_oid_(v88616));
                      (v88616->other = Kernel.cfalse);
                      v63562 = _oid_(v88616);
                      } 
                    (v63561->arg = v63562);} 
                  add_I_property(Kernel.instances,Language._For,11,_oid_(v88616));
                  v_bag = _oid_(v88616);
                  } 
                GC_OID(v_bag);} 
              ((list *) v63539)->addFast(v_bag);} 
            (v63538->args = v63539);} 
          add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
          v113297 = _oid_(v88616);
          } 
        Result = (*Optimize.c_code)(v113297,
          _oid_(v82395));
        } 
      else if (v13540->other == CNULL)
       { Variable * v82398;
        { { Cint  v11055;
            { (Optimize.OPT->max_vars = (Optimize.OPT->max_vars+1));
              v11055 = 0;
              } 
            v82398 = Variable_I_symbol(append_symbol(v13540->var->pname,_string_(CSTRING("_some"))),v11055,GC_OBJECT(ClaireType,extends_type(GC_OBJECT(ClaireType,v13540->var->range))));
            } 
          GC_OBJECT(Variable,v82398);} 
        { OID  v12016;
          { Let * v88616 = ((Let *) GC_OBJECT(Let,new_object_class(Language._Let)));
            (v88616->var = v82398);
            (v88616->value = CNULL);
            { Let * v63569 = v88616; 
              OID  v63571;
              { Do * v88616 = ((Do *) GC_OBJECT(Do,new_object_class(Language._Do)));
                { Do * v63592 = v88616; 
                  list * v63593;
                  { OID v_bag;
                    GC_ANY(v63593= list::empty(Kernel.emptySet));
                    { { For * v88616 = ((For *) GC_OBJECT(For,new_object_class(Language._For)));
                        (v88616->var = v13540->var);
                        (v88616->set_arg = v13540->set_arg);
                        { Iteration * v63594 = v88616; 
                          OID  v63595;
                          { If * v88616 = ((If *) GC_OBJECT(If,new_object_class(Language._If)));
                            (v88616->test = v13540->arg);
                            { If * v63596 = v88616; 
                              OID  v63597;
                              { Return * v88616 = ((Return *) GC_OBJECT(Return,new_object_class(Language._Return)));
                                { Return * v63598 = v88616; 
                                  OID  v63599;
                                  { Assign * v88616 = ((Assign *) GC_OBJECT(Assign,new_object_class(Language._Assign)));
                                    (v88616->var = _oid_(v82398));
                                    (v88616->arg = _oid_(v13540->var));
                                    add_I_property(Kernel.instances,Language._Assign,11,_oid_(v88616));
                                    v63599 = _oid_(v88616);
                                    } 
                                  (v63598->arg = v63599);} 
                                add_I_property(Kernel.instances,Language._Return,11,_oid_(v88616));
                                v63597 = _oid_(v88616);
                                } 
                              (v63596->arg = v63597);} 
                            add_I_property(Kernel.instances,Language._If,11,_oid_(v88616));
                            (v88616->other = Kernel.cfalse);
                            v63595 = _oid_(v88616);
                            } 
                          (v63594->arg = v63595);} 
                        add_I_property(Kernel.instances,Language._For,11,_oid_(v88616));
                        v_bag = _oid_(v88616);
                        } 
                      GC_OID(v_bag);} 
                    ((list *) v63593)->addFast(v_bag);
                    ((list *) v63593)->addFast(_oid_(v82398));} 
                  (v63592->args = v63593);} 
                add_I_property(Kernel.instances,Language._Do,11,_oid_(v88616));
                v63571 = _oid_(v88616);
                } 
              (v63569->arg = v63571);} 
            add_I_property(Kernel.instances,Language._Let,11,_oid_(v88616));
            v12016 = _oid_(v88616);
            } 
          Result = (*Optimize.c_code)(v12016,
            _oid_(v82395));
          } 
        } 
      else { OID  v42768;
          { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
            (v88616->selector = Kernel.boolean_I);
            { Call * v63601 = v88616; 
              list * v64274;
              { OID v_bag;
                GC_ANY(v64274= list::empty(Kernel.emptySet));
                { { For * v88616 = ((For *) GC_OBJECT(For,new_object_class(Language._For)));
                    (v88616->var = v13540->var);
                    (v88616->set_arg = v13540->set_arg);
                    { Iteration * v64275 = v88616; 
                      OID  v64276;
                      { If * v88616 = ((If *) GC_OBJECT(If,new_object_class(Language._If)));
                        (v88616->test = v13540->arg);
                        { If * v64277 = v88616; 
                          OID  v64278;
                          { Return * v88616 = ((Return *) GC_OBJECT(Return,new_object_class(Language._Return)));
                            (v88616->arg = Kernel.ctrue);
                            add_I_property(Kernel.instances,Language._Return,11,_oid_(v88616));
                            v64278 = _oid_(v88616);
                            } 
                          (v64277->arg = v64278);} 
                        add_I_property(Kernel.instances,Language._If,11,_oid_(v88616));
                        (v88616->other = Kernel.cfalse);
                        v64276 = _oid_(v88616);
                        } 
                      (v64275->arg = v64276);} 
                    add_I_property(Kernel.instances,Language._For,11,_oid_(v88616));
                    v_bag = _oid_(v88616);
                    } 
                  GC_OID(v_bag);} 
                ((list *) v64274)->addFast(v_bag);} 
              (v63601->args = v64274);} 
            add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
            v42768 = _oid_(v88616);
            } 
          Result = (*Optimize.c_code)(v42768,
            _oid_(v82395));
          } 
        } 
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_Image_Optimize(Image *v13540)
{ GC_BIND;
  { ClaireType *Result ;
    { ClaireType * v61575 = GC_OBJECT(ClaireType,ptype_type(OBJECT(ClaireType,(*Optimize.c_type)(GC_OID(v13540->set_arg)))));
      range_infers_for_Variable(GC_OBJECT(Variable,v13540->var),GC_OBJECT(ClaireType,pmember_type(v61575)),v61575);
      Result = ((((v13540->of == (NULL)) ? CTRUE : CFALSE) != CTRUE) ?
        param_I_class(Kernel._set,GC_OBJECT(ClaireType,v13540->of)) :
        nth_class1(Kernel._set,GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(GC_OID(v13540->arg))))) );
      } 
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_Select_Optimize(Select *v13540)
{ GC_BIND;
  { ClaireType *Result ;
    { OID  v61575 = GC_OID((*Optimize.c_type)(GC_OID(v13540->set_arg)));
      range_infers_for_Variable(GC_OBJECT(Variable,v13540->var),GC_OBJECT(ClaireType,pmember_type(OBJECT(ClaireType,v61575))),OBJECT(ClaireType,v61575));
      Result = ((((v13540->of == (NULL)) ? CTRUE : CFALSE) != CTRUE) ?
        param_I_class(Kernel._set,GC_OBJECT(ClaireType,v13540->of)) :
        nth_class1(Kernel._set,GC_OBJECT(ClaireType,pmember_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(GC_OID(v13540->set_arg))))))) );
      } 
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_Lselect_Optimize(Lselect *v13540)
{ GC_BIND;
  { ClaireType *Result ;
    { OID  v61575 = GC_OID((*Optimize.c_type)(GC_OID(v13540->set_arg)));
      range_infers_for_Variable(GC_OBJECT(Variable,v13540->var),GC_OBJECT(ClaireType,pmember_type(OBJECT(ClaireType,v61575))),OBJECT(ClaireType,v61575));
      Result = ((((v13540->of == (NULL)) ? CTRUE : CFALSE) != CTRUE) ?
        param_I_class(Kernel._list,GC_OBJECT(ClaireType,v13540->of)) :
        nth_class1(Kernel._list,GC_OBJECT(ClaireType,pmember_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(GC_OID(v13540->set_arg))))))) );
      } 
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_While_Optimize(While *v13540)
{ GC_BIND;
  { ClaireType *Result ;
    Result = infers_from_type2(GC_OBJECT(ClaireType,return_type_any(GC_OID(v13540->arg))),_oid_(v13540));
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_While_Optimize(While *v13540,ClaireClass *v82395)
{ GC_BIND;
  { OID Result = 0;
    { ClaireBoolean * v82378 = Optimize.OPT->protection;
      (Optimize.OPT->protection = CFALSE);
      { While * v82394;
        { { While * v88616 = ((While *) GC_OBJECT(While,new_object_class(Language._While)));
            (v88616->test = c_boolean_any(GC_OID(v13540->test)));
            (v88616->arg = (*Optimize.c_code)(GC_OID(v13540->arg),
              _oid_(Kernel._void)));
            (v88616->other = v13540->other);
            add_I_property(Kernel.instances,Language._While,11,_oid_(v88616));
            v82394 = v88616;
            } 
          GC_OBJECT(While,v82394);} 
        if ((Optimize.OPT->protection == CTRUE) && 
            (0 <= Optimize.OPT->loop_index))
         (Optimize.OPT->loop_gc = CTRUE);
        (Optimize.OPT->protection = ((Optimize.OPT->protection == CTRUE) ? CTRUE : ((v82378 == CTRUE) ? CTRUE : CFALSE)));
        if ((v82395 != Kernel._void) && 
            (v82395 != Kernel._any))
         { { Compile_to_C * v88616 = ((Compile_to_C *) GC_OBJECT(Compile_to_C,new_object_class(Optimize._to_C)));
            (v88616->arg = _oid_(v82394));
            (v88616->set_arg = v82395);
            add_I_property(Kernel.instances,Optimize._to_C,11,_oid_(v88616));
            Result = _oid_(v88616);
            } 
          } 
        else Result = _oid_(v82394);
          } 
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  Iterate_I_Iteration(Iteration *v13540)
{ GC_BIND;
  { OID Result = 0;
    Result = restriction_I_property(Language.Iterate,list::alloc(3,_oid_(set::alloc(1,GC_OID(v13540->set_arg))),
      _oid_(set::alloc(1,GC_OID(_oid_(v13540->var)))),
      _oid_(Kernel._any)),CTRUE);
    GC_UNBIND; return (Result);} 
  } 

OID  iterate_Interval(Interval *v82400,Variable *v82398,OID v82381)
{ GC_RESERVE(1);  // HOHO v3.0.55 optim !
  { OID Result = 0;
    { OID  v82398 = GC_OID(eval_any2(v82400->arg1,Core._Interval));
      Cint  v56503 = eval_any2(v82400->arg2,Core._Interval);
      { OID gc_local;
        Result= _oid_(CFALSE);
        while ((v82398 <= v56503))
        { GC_LOOP;
          ;GC__OID(v82398 = (*Core._plus)(v82398,
            1), 1);
          GC_UNLOOP;} 
        } 
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  iterate_array(OID *v82400,Variable *v82398,OID v82381)
{ { OID Result = 0;
    { Cint  v61564 = 1;
      OID * v61556 = v82400;
      Cint  v56503 = v61556[0];
      { Result= _oid_(CFALSE);
        while ((v61564 <= v56503))
        { { OID  v82398 = nth_array(v61556,v61564);
            ;++v61564;
            } 
          } 
        } 
      } 
    return (Result);} 
  } 

OID  Iterate_class(ClaireClass *v82400,Variable *v82398,OID v82381)
{ { OID Result = 0;
    { ITERATE(v65019);
      Result= Kernel.cfalse;
      for (START(v82400->descendents); NEXT(v65019);)
      { ClaireBoolean * v65020;
        { OID v55170;{ ITERATE(v82398);
            v55170= Kernel.cfalse;
            for (START(OBJECT(ClaireClass,v65019)->instances); NEXT(v82398);)
            ;} 
          
          v65020=OBJECT(ClaireBoolean,v55170);} 
        if (v65020 == CTRUE)
         { Result = _oid_(v65020);
          break;} 
        } 
      } 
    return (Result);} 
  } 

OID  Iterate_any1(OID v82400,Variable *v82398,OID v82381)
{ GC_RESERVE(1);  // HOHO v3.0.55 optim !
  { OID Result = 0;
    { OID  v82398 = GC_OID(OPT_EVAL((*(OBJECT(Call,v82400)->args))[1]));
      OID  v56503 = GC_OID(OPT_EVAL((*(OBJECT(Call,v82400)->args))[2]));
      { OID gc_local;
        Result= _oid_(CFALSE);
        while (((OBJECT(ClaireBoolean,(*Kernel._inf_equal)(v82398,
          v56503))) == CTRUE))
        { GC_LOOP;
          ;GC__OID(v82398 = (*Core._plus)(v82398,
            1), 1);
          GC_UNLOOP;} 
        } 
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  Iterate_Lselect(Lselect *v82400,Variable *v82398,OID v82381)
{ GC_BIND;
  { OID Result = 0;
    { OID gc_local;
      ITERATE(v82398);
      Result= Kernel.cfalse;
      bag *v82398_support;
      v82398_support = GC_OBJECT(bag,enumerate_any(GC_OID(eval_any(GC_OID(v82400->set_arg)))));
      for (START(v82398_support); NEXT(v82398);)
      { GC_LOOP;
        if (boolean_I_any(eval_any(GC_OID(substitution_any(v82400->arg,v82400->var,v82398)))) == CTRUE)
         ;GC_UNLOOP;} 
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  Iterate_Select(Select *v82400,Variable *v82398,OID v82381)
{ GC_BIND;
  { OID Result = 0;
    { OID gc_local;
      ITERATE(v82398);
      Result= Kernel.cfalse;
      bag *v82398_support;
      v82398_support = GC_OBJECT(bag,enumerate_any(GC_OID(eval_any(GC_OID(v82400->set_arg)))));
      for (START(v82398_support); NEXT(v82398);)
      { GC_LOOP;
        if (boolean_I_any(eval_any(GC_OID(substitution_any(v82400->arg,v82400->var,v82398)))) == CTRUE)
         ;GC_UNLOOP;} 
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  Iterate_Collect(Collect *v82400,Variable *v82398,OID v82381)
{ GC_RESERVE(1);  // HOHO v3.0.55 optim !
  { OID Result = 0;
    { OID gc_local;
      ITERATE(v100316);
      Result= Kernel.cfalse;
      bag *v100316_support;
      v100316_support = GC_OBJECT(bag,enumerate_any(GC_OID(eval_any(GC_OID(v82400->set_arg)))));
      for (START(v100316_support); NEXT(v100316);)
      { GC_LOOP;
        { OID  v82398 = GC_OID(eval_any(GC_OID(substitution_any(v82400->arg,v82400->var,v100316))));
          ;} 
        GC_UNLOOP;} 
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  Iterate_any2(OID v82400,Variable *v82398,OID v82381)
{ GC_BIND;
  { OID Result = 0;
    { OID gc_local;
      ITERATE(v82398);
      Result= Kernel.cfalse;
      bag *v82398_support;
      v82398_support = GC_OBJECT(bag,enumerate_any(GC_OID(OPT_EVAL((*(OBJECT(Call,v82400)->args))[1]))));
      for (START(v82398_support); NEXT(v82398);)
      { GC_LOOP;
        if (equal(v82398,OPT_EVAL((*(OBJECT(Call,v82400)->args))[2])) != CTRUE)
         ;GC_UNLOOP;} 
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  Iterate_any3(OID v82400,Variable *v82398,OID v82381)
{ GC_BIND;
  { OID gc_local;
    ITERATE(v82398);
    bag *v82398_support;
    v82398_support = GC_OBJECT(bag,enumerate_any(GC_OID(OPT_EVAL((*(OBJECT(Call,v82400)->args))[1]))));
    for (START(v82398_support); NEXT(v82398);)
    ;} 
  { OID Result = 0;
    { OID gc_local;
      ITERATE(v82398);
      Result= Kernel.cfalse;
      bag *v82398_support;
      v82398_support = GC_OBJECT(bag,enumerate_any(GC_OID(OPT_EVAL((*(OBJECT(Call,v82400)->args))[2]))));
      for (START(v82398_support); NEXT(v82398);)
      ;} 
    GC_UNBIND; return (Result);} 
  } 

