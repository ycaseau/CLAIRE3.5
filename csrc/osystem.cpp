/***** CLAIRE Compilation of file /Users/ycaseau/claire/v3.5/src/compile/osystem.cl 
         [version 3.5.01 / safety 5] Sun Jul 24 08:43:46 2016 *****/

#include <claire.h>
#include <Kernel.h>
#include <Core.h>
#include <Language.h>
#include <Reader.h>
#include <Optimize.h>
char * home_void()
{ return (getenv_string(CSTRING("CLAIRE3_HOME")));} 

OID  safe_any2(OID v82400)
{ return (v82400);} 

ClaireType * safe_any2_type(ClaireType *v82400)
{ return (v82400);} 

ClaireType * c_type_any_Optimize(OID v13540)
{ GC_BIND;
  { ClaireType *Result ;
    { ClaireObject *V_CC ;
      if (INHERIT(OWNER(v13540),Language._Variable))
       { OID  v82394 = GC_OID(get_property(Kernel.range,OBJECT(ClaireObject,v13540)));
        if (v82394 == CNULL)
         V_CC = Kernel._any;
        else V_CC = (((INHERIT(OWNER(v82394),Core._Union)) && (equal(_oid_(OBJECT(Union,v82394)->t1),_oid_(Kernel.emptySet)) == CTRUE)) ?
          CLREAD(Union,OBJECT(Union,v82394)->t2,t2) :
          ptype_type(OBJECT(ClaireType,v82394)) );
        } 
      else if (INHERIT(OWNER(v13540),Core._global_variable))
       { ClaireType * v82394 = OBJECT(global_variable,v13540)->range;
        if (boolean_I_any(_oid_(v82394)) == CTRUE)
         V_CC = v82394;
        else V_CC = set::alloc(1,OBJECT(global_variable,v13540)->value);
          } 
      else if (INHERIT(OWNER(v13540),Kernel._unbound_symbol))
       V_CC = OBJECT(ClaireType,(*Optimize.Cerror)(_string_(CSTRING("[215] the symbol ~A is unbound_symbol")),
        _oid_(OBJECT(unbound_symbol,v13540)->name)));
      else if (INHERIT(OWNER(v13540),Kernel._error))
       V_CC = Kernel.emptySet;
      else if (INHERIT(OWNER(v13540),Language._Update))
       V_CC = OBJECT(ClaireType,(*Optimize.c_type)(OBJECT(Update,v13540)->value));
      else if (INHERIT(OWNER(v13540),Language._Construct))
       { if (((INHERIT(OBJECT(ClaireObject,v13540)->isa,Language._List)) ? CTRUE : ((INHERIT(OBJECT(ClaireObject,v13540)->isa,Language._Set)) ? CTRUE : CFALSE)) != CTRUE)
         V_CC = Kernel._any;
        else { ClaireType * v61427 = Kernel.emptySet;
            { OID gc_local;
              ITERATE(v61579);
              for (START(OBJECT(Construct,v13540)->args); NEXT(v61579);)
              if (boolean_I_any(_oid_(v61427)) == CTRUE)
               v61427= meet_class(((ClaireClass *) v61427),class_I_type(OBJECT(ClaireType,(*Optimize.c_type)(v61579))));
              else v61427= class_I_type(OBJECT(ClaireType,(*Optimize.c_type)(v61579)));
                } 
            V_CC = nth_class1(((INHERIT(OBJECT(ClaireObject,v13540)->isa,Language._Set)) ?
              Kernel._set :
              Kernel._list ),v61427);
            } 
          } 
      else if (INHERIT(OWNER(v13540),Language._Instruction))
       close_exception(((general_error *) (*Core._general_error)(_string_(CSTRING("c_type of ~S is not defined")),
        _oid_(list::alloc(1,_oid_(OWNER(v13540)))))));
      else V_CC = set::alloc(1,v13540);
        Result= (ClaireType *) V_CC;} 
    GC_UNBIND; return (Result);} 
  } 

OID  c_strict_code_any(OID v82400,ClaireClass *v82395)
{ GC_BIND;
  { OID Result = 0;
    Result = (*Optimize.c_strict_check)(GC_OID((*Optimize.c_code)(v82400,
        _oid_(v82395))),
      _oid_(v82395));
    GC_UNBIND; return (Result);} 
  } 

OID  c_strict_check_any_Optimize(OID v82400,ClaireClass *v82395)
{ GC_BIND;
  { OID Result = 0;
    if ((Optimize.OPT->online_ask != CTRUE) && 
        ((INHERIT(v82395,Kernel._object)) && 
          (inherit_ask_class(stupid_t_any1(v82400),v82395) != CTRUE)))
     { if ((*Optimize.c_type)(v82400) == _oid_(Kernel._any))
       (*Optimize.Cerror)(_string_(CSTRING("Need explict cast: ~S is not a ~S")),
        v82400,
        _oid_(v82395));
      { Compile_C_cast * v88616 = ((Compile_C_cast *) GC_OBJECT(Compile_C_cast,new_object_class(Optimize._C_cast)));
        (v88616->arg = v82400);
        (v88616->set_arg = v82395);
        add_I_property(Kernel.instances,Optimize._C_cast,11,_oid_(v88616));
        Result = _oid_(v88616);
        } 
      } 
    else Result = v82400;
      GC_UNBIND; return (Result);} 
  } 

OID  c_code_any1_Optimize(OID v82400,ClaireClass *v82395)
{ GC_BIND;
  { OID Result = 0;
    { OID  v82401;
      { if (INHERIT(OWNER(v82400),Language._Call))
         v82401 = c_code_call_Call(OBJECT(Call,v82400),v82395);
        else v82401 = (*Optimize.c_code)(v82400);
          GC_OID(v82401);} 
      ClaireClass * v82402 = OBJECT(ClaireClass,(*Optimize.c_sort)(v82401));
      if ((v82395 == Kernel._void) || 
          ((v82402 == v82395) || 
            (Optimize.OPT->online_ask == CTRUE)))
       { if ((v82395 == Kernel._void) && 
            ((INHERIT(OWNER(v82400),Language._Call)) && (OBJECT(Call,v82400)->selector == Kernel._equal)))
         { warn_void();
          tformat_string(CSTRING("-- Equality meant as an assignment: ~S [264]\n"),2,list::alloc(1,v82400));
          } 
        Result = v82401;
        } 
      else if (v82395 == Kernel._any)
       { if ((v82402 == Kernel._integer) && 
            ((INHERIT(OWNER(v82401),Language._Call_slot)) && 
              (((Optimize.compiler->overflow_ask == CTRUE) ? ((Optimize.compiler->class2file_ask == CTRUE) ? CTRUE: CFALSE): CFALSE) != CTRUE)))
         Result = v82401;
        else if (INHERIT(OWNER(v82401),Optimize._to_C))
         Result = OBJECT(Compile_to_C,v82401)->arg;
        else { if (v82402 == Kernel._float)
             { (Optimize.OPT->protection = CTRUE);
              (Optimize.OPT->allocation = CTRUE);
              } 
            { Compile_to_CL * v88616 = ((Compile_to_CL *) GC_OBJECT(Compile_to_CL,new_object_class(Optimize._to_CL)));
              (v88616->arg = v82401);
              (v88616->set_arg = psort_any((*Optimize.c_type)(v82401)));
              add_I_property(Kernel.instances,Optimize._to_CL,11,_oid_(v88616));
              Result = _oid_(v88616);
              } 
            } 
          } 
      else if (v82402 == Kernel._any)
       { Compile_to_C * v88616 = ((Compile_to_C *) GC_OBJECT(Compile_to_C,new_object_class(Optimize._to_C)));
        (v88616->arg = v82401);
        (v88616->set_arg = v82395);
        add_I_property(Kernel.instances,Optimize._to_C,11,_oid_(v88616));
        Result = _oid_(v88616);
        } 
      else Result = v82401;
        } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_any2_Optimize(OID v13540)
{ GC_BIND;
  { OID Result = 0;
    if (INHERIT(OWNER(v13540),Kernel._unbound_symbol))
     Result = (*Optimize.Cerror)(_string_(CSTRING("[215] the symbol ~A is unbound_symbol")),
      _oid_(OBJECT(unbound_symbol,v13540)->name));
    else if (INHERIT(OWNER(v13540),Language._Variable))
     Result = v13540;
    else if (INHERIT(OWNER(v13540),Core._global_variable))
     { c_register_object(OBJECT(ClaireObject,v13540));
      Result = v13540;
      } 
    else if (INHERIT(OWNER(v13540),Language._Optimized_instruction))
     Result = v13540;
    else if (INHERIT(OWNER(v13540),Language._Instruction))
     Result = (*Optimize.Cerror)(_string_(CSTRING("[internal] c_code(~S) should have a parameter")),
      v13540);
    else if (Kernel._set == OWNER(v13540))
     { if (OBJECT(bag,v13540)->length != 0)
       { Set * v82400;
        { { Set * v88616 = ((Set *) GC_OBJECT(Set,new_object_class(Language._Set)));
            (v88616->args = list_I_set(OBJECT(set,v13540)));
            add_I_property(Kernel.instances,Language._Set,11,_oid_(v88616));
            v82400 = v88616;
            } 
          GC_OBJECT(Set,v82400);} 
        if (of_bag(OBJECT(bag,v13540)) != Kernel._void)
         (v82400->of = of_bag(OBJECT(bag,v13540)));
        Result = (*Optimize.c_code)(_oid_(v82400));
        } 
      else Result = v13540;
        } 
    else if (INHERIT(OWNER(v13540),Kernel._list))
     { if (OBJECT(bag,v13540)->length != 0)
       { List * v82400;
        { { List * v88616 = ((List *) GC_OBJECT(List,new_object_class(Language._List)));
            (v88616->args = OBJECT(list,v13540));
            add_I_property(Kernel.instances,Language._List,11,_oid_(v88616));
            v82400 = v88616;
            } 
          GC_OBJECT(List,v82400);} 
        if (of_bag(OBJECT(bag,v13540)) != Kernel._void)
         (v82400->of = of_bag(OBJECT(bag,v13540)));
        Result = (*Optimize.c_code)(_oid_(v82400));
        } 
      else Result = v13540;
        } 
    else if (INHERIT(OWNER(v13540),Kernel._tuple))
     { OID  v18993;
      { Tuple * v88616 = ((Tuple *) GC_OBJECT(Tuple,new_object_class(Language._Tuple)));
        (v88616->args = OBJECT(list,v13540));
        add_I_property(Kernel.instances,Language._Tuple,11,_oid_(v88616));
        v18993 = _oid_(v88616);
        } 
      Result = (*Optimize.c_code)(v18993);
      } 
    else { if (INHERIT(OWNER(v13540),Kernel._thing))
         (*Optimize.c_register)(v13540);
        if ((Kernel._float == OWNER(v13540)) || 
            (INHERIT(OWNER(v13540),Kernel._function)))
         (Optimize.OPT->allocation = CTRUE);
        Result = v13540;
        } 
      GC_UNBIND; return (Result);} 
  } 

ClaireBoolean * c_gc_ask_any(OID v13540)
{ { ClaireBoolean *Result ;
    if (INHERIT(OWNER(v13540),Language._Variable))
     Result = CFALSE;
    else Result = ((INHERIT(OWNER(v13540),Core._global_variable)) ?
      not_any(_oid_((INHERIT(OBJECT(global_variable,v13540)->range->isa,Kernel._class) ? (ClaireObject *) gcsafe_ask_class((ClaireClass *) OBJECT(ClaireClass,_oid_(OBJECT(global_variable,v13540)->range))) :  (ClaireObject *)  gcsafe_ask_type((ClaireType *) OBJECT(ClaireType,_oid_(OBJECT(global_variable,v13540)->range)))))) :
      ((INHERIT(OWNER(v13540),Language._Construct)) ?
        ((Optimize.OPT->loop_gc == CTRUE) ? (((INHERIT(OBJECT(ClaireObject,v13540)->isa,Language._List)) || 
            (INHERIT(OBJECT(ClaireObject,v13540)->isa,Language._Set))) ? CTRUE: CFALSE): CFALSE) :
        ((INHERIT(OWNER(v13540),Language._Instruction)) ?
          CFALSE :
          ((Kernel._string == OWNER(v13540)) ?
            Optimize.OPT->use_string_update :
            CFALSE ) ) ) );
    return (Result);} 
  } 

ClaireClass * c_sort_any_Optimize(OID v13540)
{ GC_BIND;
  { ClaireClass *Result ;
    { ClaireObject *V_CC ;
      if (INHERIT(OWNER(v13540),Core._global_variable))
       { V_CC = ((nativeVar_ask_global_variable(OBJECT(global_variable,v13540)) == CTRUE) ?
          ((equal(_oid_(OBJECT(global_variable,v13540)->range),_oid_(Kernel.emptySet)) == CTRUE) ?
            osort_any(_oid_(OWNER(OBJECT(global_variable,v13540)->value))) :
            osort_any(_oid_(OBJECT(global_variable,v13540)->range)) ) :
          Kernel._any );
        } 
      else if (INHERIT(OWNER(v13540),Language._Instruction))
       { if (INHERIT(OBJECT(ClaireObject,v13540)->isa,Language._Variable))
         V_CC = sort_Variable(OBJECT(Variable,v13540));
        else if (INHERIT(OBJECT(ClaireObject,v13540)->isa,Language._Assign))
         V_CC = sort_Variable(OBJECT(Variable,OBJECT(Assign,v13540)->var));
        else if (INHERIT(OBJECT(ClaireObject,v13540)->isa,Language._Call))
         V_CC = osort_any(_oid_(selector_psort_Call(OBJECT(Call,v13540))));
        else if (INHERIT(OBJECT(ClaireObject,v13540)->isa,Language._Call_method))
         { V_CC = (((OBJECT(Call_method,v13540)->arg->selector == Core.externC) && 
              (OBJECT(Call_method,v13540)->args->length == 2)) ?
            psort_any((*(OBJECT(Call_method,v13540)->args))[2]) :
            c_srange_method(OBJECT(Call_method,v13540)->arg) );
          } 
        else if (INHERIT(OBJECT(ClaireObject,v13540)->isa,Language._Call_slot))
         V_CC = OBJECT(Call_slot,v13540)->selector->srange;
        else if (INHERIT(OBJECT(ClaireObject,v13540)->isa,Language._Call_table))
         V_CC = Kernel._any;
        else if (INHERIT(OBJECT(ClaireObject,v13540)->isa,Language._Call_array))
         { V_CC = ((OBJECT(Call_array,v13540)->test == _oid_(Kernel._float)) ?
            Kernel._float :
            Kernel._any );
          } 
        else if (INHERIT(OBJECT(ClaireObject,v13540)->isa,Language._Definition))
         V_CC = Kernel._object;
        else if (INHERIT(OBJECT(ClaireObject,v13540)->isa,Optimize._to_C))
         V_CC = OBJECT(Compile_to_C,v13540)->set_arg;
        else if (INHERIT(OBJECT(ClaireObject,v13540)->isa,Optimize._to_protect))
         V_CC = OBJECT(ClaireClass,(*Optimize.c_sort)(OBJECT(Compile_to_protect,v13540)->arg));
        else if (INHERIT(OBJECT(ClaireObject,v13540)->isa,Language._Update))
         V_CC = OBJECT(ClaireClass,(*Optimize.c_sort)(OBJECT(Update,v13540)->value));
        else if (INHERIT(OBJECT(ClaireObject,v13540)->isa,Language._If))
         V_CC = psort_any(_oid_(meet_class(OBJECT(ClaireClass,(*Optimize.c_sort)(OBJECT(If,v13540)->arg)),OBJECT(ClaireClass,(*Optimize.c_sort)(OBJECT(If,v13540)->other)))));
        else if (INHERIT(OBJECT(ClaireObject,v13540)->isa,Language._Handle))
         V_CC = psort_any(_oid_(meet_class(OBJECT(ClaireClass,(*Optimize.c_sort)(OBJECT(ClaireHandle,v13540)->arg)),OBJECT(ClaireClass,(*Optimize.c_sort)(OBJECT(ClaireHandle,v13540)->other)))));
        else if (INHERIT(OBJECT(ClaireObject,v13540)->isa,Language._Let))
         V_CC = OBJECT(ClaireClass,(*Optimize.c_sort)(OBJECT(Let,v13540)->arg));
        else if (INHERIT(OBJECT(ClaireObject,v13540)->isa,Optimize._to_CL))
         V_CC = Kernel._any;
        else if (INHERIT(OBJECT(ClaireObject,v13540)->isa,Language._Return))
         V_CC = Kernel._any;
        else if (INHERIT(OBJECT(ClaireObject,v13540)->isa,Language._List))
         V_CC = Kernel._object;
        else if (INHERIT(OBJECT(ClaireObject,v13540)->isa,Language._Set))
         V_CC = Kernel._object;
        else if (INHERIT(OBJECT(ClaireObject,v13540)->isa,Language._Tuple))
         V_CC = Kernel._object;
        else if (INHERIT(OBJECT(ClaireObject,v13540)->isa,Language._Construct))
         V_CC = Kernel._any;
        else if (INHERIT(OBJECT(ClaireObject,v13540)->isa,Language._Gassign))
         V_CC = Kernel._any;
        else if (INHERIT(OBJECT(ClaireObject,v13540)->isa,Language._Super))
         V_CC = Kernel._any;
        else if (INHERIT(OBJECT(ClaireObject,v13540)->isa,Language._For))
         V_CC = Kernel._any;
        else if (INHERIT(OBJECT(ClaireObject,v13540)->isa,Language._Exists))
         { V_CC = ((OBJECT(Exists,v13540)->other == CNULL) ?
            Kernel._any :
            Kernel._object );
          } 
        else if (INHERIT(OBJECT(ClaireObject,v13540)->isa,Language._Iteration))
         V_CC = Kernel._object;
        else if (INHERIT(OBJECT(ClaireObject,v13540)->isa,Language._And))
         V_CC = Kernel._boolean;
        else if (INHERIT(OBJECT(ClaireObject,v13540)->isa,Language._Or))
         V_CC = Kernel._boolean;
        else if (INHERIT(OBJECT(ClaireObject,v13540)->isa,Language._While))
         V_CC = Kernel._any;
        else if (INHERIT(OBJECT(ClaireObject,v13540)->isa,Language._Do))
         V_CC = OBJECT(ClaireClass,(*Optimize.c_sort)(GC_OID(last_list(OBJECT(Do,v13540)->args))));
        else close_exception(((general_error *) (*Core._general_error)(_string_(CSTRING("[internal] c_sort is not implemented for ~S")),
            _oid_(list::alloc(1,_oid_(OWNER(v13540)))))));
          } 
      else V_CC = ((Kernel._float == OWNER(v13540)) ?
        Kernel._float :
        psort_any((*Optimize.c_type)(v13540)) );
      Result= (ClaireClass *) V_CC;} 
    GC_UNBIND; return (Result);} 
  } 

ClaireClass * selector_psort_Call(Call *v13540)
{ { ClaireClass *Result ;
    { property * v82392 = v13540->selector;
      Result = (((v82392 == Core.base_I) || 
          (v82392 == Core.index_I)) ?
        Kernel._integer :
        ((v82392 == Optimize.anyObject_I) ?
          OBJECT(ClaireClass,(*(v13540->args))[1]) :
          ((v82392 == Optimize.object_I) ?
            OBJECT(ClaireClass,(*(v13540->args))[2]) :
            Kernel._any ) ) );
      } 
    return (Result);} 
  } 

Cint  c_status_any(OID v13540,list *v82388)
{ GC_BIND;
  { Cint Result = 0;
    if (INHERIT(OWNER(v13540),Language._Instruction))
     { if (INHERIT(OBJECT(ClaireObject,v13540)->isa,Language._Variable))
       { Result = (((OBJECT(Variable,v13540)->range == (NULL)) || 
            (_oid_((INHERIT(OBJECT(Variable,v13540)->range->isa,Kernel._class) ? (ClaireObject *) gcsafe_ask_class((ClaireClass *) OBJECT(ClaireClass,_oid_(OBJECT(Variable,v13540)->range))) :  (ClaireObject *)  gcsafe_ask_type((ClaireType *) OBJECT(ClaireType,_oid_(OBJECT(Variable,v13540)->range))))) != Kernel.ctrue)) ?
          ((contain_ask_list(v82388,v13540) == CTRUE) ?
            16 :
            (((((OBJECT(Variable,v13540)->range == (NULL)) ? CTRUE : CFALSE) != CTRUE) && 
                (_inf_equal_type(GC_OBJECT(ClaireType,OBJECT(Variable,v13540)->range),Kernel._float) == CTRUE)) ?
              2 :
              0 ) ) :
          32 );
        } 
      else if (INHERIT(OBJECT(ClaireObject,v13540)->isa,Language._Error))
       Result = 32;
      else if (INHERIT(OBJECT(ClaireObject,v13540)->isa,Language._Printf))
       { Cint  v80497;
        { Cint  v61394 = 0;
          { OID gc_local;
            ITERATE(v61396);
            bag *v61396_support;
            v61396_support = GC_OBJECT(list,OBJECT(Construct,v13540)->args);
            for (START(v61396_support); NEXT(v61396);)
            { Cint  v61395 = c_status_any(v61396,v82388);
              v61394= c_or_integer(v61394,v61395);
              } 
            } 
          v80497 = v61394;
          } 
        Result = c_return_integer(0,v80497);
        } 
      else if (INHERIT(OBJECT(ClaireObject,v13540)->isa,Language._Construct))
       Result = 2;
      else if (INHERIT(OBJECT(ClaireObject,v13540)->isa,Language._Definition))
       Result = 2;
      else if (INHERIT(OBJECT(ClaireObject,v13540)->isa,Language._Call))
       { Cint  v63895 = c_status_call_property(OBJECT(Call,v13540)->selector,GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)((*(v82388))[1]))));
        Cint  v63896;
        { Cint  v61397 = 0;
          { OID gc_local;
            ITERATE(v61399);
            bag *v61399_support;
            v61399_support = GC_OBJECT(list,OBJECT(Call,v13540)->args);
            for (START(v61399_support); NEXT(v61399);)
            { Cint  v61398 = c_status_any(v61399,v82388);
              v61397= c_or_integer(v61397,v61398);
              } 
            } 
          v63896 = v61397;
          } 
        Result = c_return_integer(v63895,v63896);
        } 
      else if (INHERIT(OBJECT(ClaireObject,v13540)->isa,Language._If))
       { Cint  v63895 = c_status_any(GC_OID(OBJECT(If,v13540)->arg),v82388);
        Cint  v63896 = c_status_any(GC_OID(OBJECT(If,v13540)->other),v82388);
        Result = c_return_integer(c_or_integer(v63895,v63896),c_status_any(GC_OID(OBJECT(If,v13540)->test),v82388));
        } 
      else if (INHERIT(OBJECT(ClaireObject,v13540)->isa,Language._Do))
       { OID  v82401 = GC_OID(last_list(OBJECT(Do,v13540)->args));
        Cint  v63895 = c_status_any(v82401,v82388);
        Cint  v63896;
        { Cint  v61400 = 0;
          { OID gc_local;
            ITERATE(v61423);
            bag *v61423_support;
            v61423_support = GC_OBJECT(list,OBJECT(Do,v13540)->args);
            for (START(v61423_support); NEXT(v61423);)
            if (equal(v61423,v82401) != CTRUE)
             { Cint  v61422 = c_status_any(v61423,v82388);
              v61400= c_or_integer(v61400,v61422);
              } 
            } 
          v63896 = v61400;
          } 
        Result = c_return_integer(v63895,v63896);
        } 
      else if (INHERIT(OBJECT(ClaireObject,v13540)->isa,Language._For))
       Result = c_return_integer(c_status_any(GC_OID(OBJECT(Iteration,v13540)->arg),v82388),c_status_any(GC_OID(OBJECT(Iteration,v13540)->set_arg),v82388));
      else if (INHERIT(OBJECT(ClaireObject,v13540)->isa,Language._Iteration))
       Result = c_return_integer(2,c_status_any(GC_OID(OBJECT(Iteration,v13540)->arg),v82388));
      else if (INHERIT(OBJECT(ClaireObject,v13540)->isa,Language._Let))
       Result = c_return_integer(c_status_any(GC_OID(OBJECT(Let,v13540)->arg),v82388),c_status_any(GC_OID(OBJECT(Let,v13540)->value),v82388));
      else if (INHERIT(OBJECT(ClaireObject,v13540)->isa,Language._Assign))
       Result = c_status_any(GC_OID(OBJECT(Assign,v13540)->arg),v82388);
      else if (INHERIT(OBJECT(ClaireObject,v13540)->isa,Language._Gassign))
       Result = c_status_any(GC_OID(OBJECT(Gassign,v13540)->arg),v82388);
      else if (INHERIT(OBJECT(ClaireObject,v13540)->isa,Language._And))
       { Cint  v81458;
        { Cint  v61424 = 0;
          { OID gc_local;
            ITERATE(v61426);
            bag *v61426_support;
            v61426_support = GC_OBJECT(list,OBJECT(And,v13540)->args);
            for (START(v61426_support); NEXT(v61426);)
            { Cint  v61425 = c_status_any(v61426,v82388);
              v61424= c_or_integer(v61424,v61425);
              } 
            } 
          v81458 = v61424;
          } 
        Result = c_return_integer(0,v81458);
        } 
      else if (INHERIT(OBJECT(ClaireObject,v13540)->isa,Language._Or))
       { Cint  v82419;
        { Cint  v61428 = 0;
          { OID gc_local;
            ITERATE(v61431);
            bag *v61431_support;
            v61431_support = GC_OBJECT(list,OBJECT(Or,v13540)->args);
            for (START(v61431_support); NEXT(v61431);)
            { Cint  v61430 = c_status_any(v61431,v82388);
              v61428= c_or_integer(v61428,v61430);
              } 
            } 
          v82419 = v61428;
          } 
        Result = c_return_integer(0,v82419);
        } 
      else if (INHERIT(OBJECT(ClaireObject,v13540)->isa,Language._Cast))
       Result = c_status_any(GC_OID(OBJECT(Cast,v13540)->arg),v82388);
      else if (INHERIT(OBJECT(ClaireObject,v13540)->isa,Language._Super))
       { Cint  v63895 = c_status_call_property(OBJECT(Super,v13540)->selector,GC_OBJECT(ClaireType,OBJECT(Super,v13540)->cast_to));
        Cint  v63896;
        { Cint  v61432 = 0;
          { OID gc_local;
            ITERATE(v61453);
            bag *v61453_support;
            v61453_support = GC_OBJECT(list,OBJECT(Super,v13540)->args);
            for (START(v61453_support); NEXT(v61453);)
            { Cint  v61433 = c_status_any(v61453,v82388);
              v61432= c_or_integer(v61432,v61433);
              } 
            } 
          v63896 = v61432;
          } 
        Result = c_return_integer(v63895,v63896);
        } 
      else if (INHERIT(OBJECT(ClaireObject,v13540)->isa,Language._Case))
       { Cint  v61454 = 0;
        { OID gc_local;
          ITERATE(v61456);
          bag *v61456_support;
          v61456_support = GC_OBJECT(list,OBJECT(Case,v13540)->args);
          for (START(v61456_support); NEXT(v61456);)
          { Cint  v61455 = c_status_any(v61456,v82388);
            v61454= c_or_integer(v61454,v61455);
            } 
          } 
        Result = v61454;
        } 
      else Result = ((INHERIT(OBJECT(ClaireObject,v13540)->isa,Language._While)) ?
        c_return_integer(c_status_any(GC_OID(OBJECT(While,v13540)->arg),v82388),c_status_any(GC_OID(OBJECT(While,v13540)->test),v82388)) :
        ((INHERIT(OBJECT(ClaireObject,v13540)->isa,Language._Return)) ?
          c_status_any(GC_OID(OBJECT(Return,v13540)->arg),v82388) :
          ((INHERIT(OBJECT(ClaireObject,v13540)->isa,Language._Handle)) ?
            c_return_integer(c_or_integer(c_status_any(GC_OID(OBJECT(ClaireHandle,v13540)->arg),v82388),c_status_any(GC_OID(OBJECT(ClaireHandle,v13540)->other),v82388)),c_status_any(GC_OID(OBJECT(ClaireHandle,v13540)->test),v82388)) :
            ((INHERIT(OBJECT(ClaireObject,v13540)->isa,Kernel._unbound_symbol)) ?
              0 :
              (*Optimize.Cerror)(_string_(CSTRING("[internal] oops .. I forgot ~S")),
                _oid_(OWNER(v13540))) ) ) ) );
      } 
    else Result = ((Kernel._float == OWNER(v13540)) ?
      2 :
      ((Kernel._string == OWNER(v13540)) ?
        2 :
        ((INHERIT(OWNER(v13540),Kernel._function)) ?
          2 :
          ((INHERIT(OWNER(v13540),Core._Type)) ?
            2 :
            0 ) ) ) );
    GC_UNBIND; return (Result);} 
  } 

Cint  c_or_integer(Cint v82400,Cint v82401)
{ { Cint Result = 0;
    { Cint  v82380 = or_integer(v82400,v82401);
      if ((BCONTAIN(v82380,5)) && 
          (((BCONTAIN(v82400,5)) ? ((BCONTAIN(v82401,5)) ? CTRUE: CFALSE): CFALSE) != CTRUE))
       v82380= (v82380-exp2_integer(5));
      if ((BCONTAIN(v82380,6)) && 
          (((BCONTAIN(v82400,6)) ? ((BCONTAIN(v82401,6)) ? CTRUE: CFALSE): CFALSE) != CTRUE))
       v82380= (v82380-exp2_integer(6));
      if ((BCONTAIN(v82380,4)) && 
          (((BCONTAIN(v82400,4)) ? ((BCONTAIN(v82401,4)) ? CTRUE: CFALSE): CFALSE) != CTRUE))
       v82380= (v82380-exp2_integer(4));
      Result = v82380;
      } 
    return (Result);} 
  } 

Cint  c_or_list(list *v82388)
{ { Cint Result = 0;
    { Cint  v82380 = 0;
      { ITERATE(v82400);
        for (START(v82388); NEXT(v82400);)
        v82380= c_or_integer(v82380,v82400);
        } 
      Result = v82380;
      } 
    return (Result);} 
  } 

Cint  status_I_restriction(restriction *v13540)
{ GC_BIND;
  { Cint Result = 0;
    if (Kernel._method == v13540->isa)
     { if (((CLREAD(method,v13540,status) == (CNULL)) ? CTRUE : CFALSE) != CTRUE)
       Result = CLREAD(method,v13540,status);
      else if (CLREAD(method,v13540,formula) == (NULL))
       { (CLREAD(method,v13540,status) = 0);
        Result = 0;
        } 
      else { (CLREAD(method,v13540,status) = 0);
          (CLREAD(method,v13540,status) = c_status_any(GC_OID(CLREAD(method,v13540,formula)->body),GC_OBJECT(list,CLREAD(method,v13540,formula)->vars)));
          Result = CLREAD(method,v13540,status);
          } 
        } 
    else Result = 0;
      GC_UNBIND; return (Result);} 
  } 

Cint  c_return_integer(Cint v82400,Cint v82401)
{ { Cint Result = 0;
    { Cint  v82380 = or_integer(v82400,v82401);
      if ((nth_integer(v82400,5) != CTRUE) && 
          (BCONTAIN(v82401,5)))
       v82380= (v82380-exp2_integer(5));
      if ((nth_integer(v82400,4) != CTRUE) && 
          (BCONTAIN(v82401,4)))
       v82380= (v82380-exp2_integer(4));
      Result = v82380;
      } 
    return (Result);} 
  } 

Cint  c_status_call_property(property *v13540,ClaireType *v82396)
{ { Cint Result = 0;
    { Cint  v82394 = ((stable_ask_relation(v13540) == CTRUE) ?
        0 :
        (*Language.bit_vector)(1,
          2,
          3) );
      { ITERATE(v82400);
        for (START(v13540->restrictions); NEXT(v82400);)
        if (boolean_I_any((*Core.glb)(_oid_(v82396),
          (*(OBJECT(restriction,v82400)->domain))[1])) == CTRUE)
         { if (Kernel._method == OBJECT(ClaireObject,v82400)->isa)
           { if (((last_list(OBJECT(method,v82400)->srange) == _oid_(Kernel._integer)) ? CTRUE : ((last_list(OBJECT(method,v82400)->srange) == _oid_(Kernel._object)) ? CTRUE : ((last_list(OBJECT(method,v82400)->srange) == _oid_(Kernel._any)) ? CTRUE : ((last_list(OBJECT(method,v82400)->srange) == _oid_(Kernel._void)) ? CTRUE : CFALSE)))) != CTRUE)
             v82394= c_or_integer(v82394,2);
            v82394= c_or_integer(v82394,status_I_restriction(OBJECT(restriction,v82400)));
            } 
          else if (Kernel._slot == OBJECT(ClaireObject,v82400)->isa)
           v82394= c_or_integer(v82394,exp2_integer(4));
          } 
        } 
      Result = v82394;
      } 
    return (Result);} 
  } 

OID  showstatus_method2(method *v82389)
{ GC_RESERVE(1);  // HOHO v3.0.55 optim !
  { OID Result = 0;
    { list * v63709 = list::alloc(7,_string_(CSTRING("NEW_ALLOC")),
        _string_(CSTRING("BAG_UPDATE")),
        _string_(CSTRING("SLOT_UPDATE")),
        _string_(CSTRING("RETURN_ARG")),
        _string_(CSTRING("SAFE_RESULT")),
        _string_(CSTRING("SAFE_GC")),
        _string_(CSTRING("STRING_UPDATE")));
      list * v82388 = list::empty(Kernel._any);
      Cint  v82395 = v82389->status;
      { Cint  v82385 = 1;
        Cint  v61460 = 7;
        { OID gc_local;
          while ((v82385 <= v61460))
          { GC_LOOP;
            if (BCONTAIN(v82395,v82385))
             GC__ANY(v82388 = v82388->addFast((*(v63709))[v82385]), 1);
            ++v82385;
            GC_UNLOOP;} 
          } 
        } 
      Result = _oid_(v82388);
      } 
    GC_UNBIND; return (Result);} 
  } 

void  s_test_method2(method *v82389)
{ GC_BIND;
  { lambda * v63757 = GC_OBJECT(lambda,v82389->formula);
    Cint  v127083 = c_status_any(GC_OID(v63757->body),GC_OBJECT(list,v63757->vars));
    tformat_string(CSTRING("status(~S) := ~S \n"),0,list::alloc(2,_oid_(v82389),v127083));
    (v82389->status = v127083);
    showstatus_method2(v82389);
    } 
  GC_UNBIND;} 

ClaireBoolean * legal_ask_module(module *v13540,OID v82400)
{ if ((v82400 == _oid_(Optimize.object_I)) || 
      (v82400 == _oid_(Optimize.anyObject_I))) 
  { { ClaireBoolean *Result ;
      Result = CTRUE;
      return (Result);} 
     } 
  else{ GC_BIND;
    { ClaireBoolean *Result ;
      if (Optimize.OPT->legal_modules->length != 0)
       { if ((contain_ask_set(Optimize.OPT->legal_modules,_oid_(v13540)) != CTRUE) && 
            ((Kernel._method == OWNER(v82400)) && ((OBJECT(method,v82400)->inline_ask == CFALSE) || 
                (Optimize.compiler->inline_ask != CTRUE))))
         { tformat_string(CSTRING("legal_modules = ~S\n"),0,list::alloc(1,GC_OID(_oid_(Optimize.OPT->legal_modules))));
          tformat_string(CSTRING("---- ERROR: ~S implies using ~S !\n\n"),0,list::alloc(2,v82400,_oid_(v13540)));
          Result = CFALSE;
          } 
        else Result = CTRUE;
          } 
      else { GC_OBJECT(set,Optimize.OPT->need_modules)->addFast(_oid_(v13540));
          Result = CTRUE;
          } 
        GC_UNBIND; return (Result);} 
    } 
  } 

OID  legal_ask_environment(ClaireEnvironment *v13540,OID v82400)
{ return (Kernel.ctrue);} 

OID  c_register_object(ClaireObject *v13540)
{ GC_BIND;
  { OID Result = 0;
    { OID  v82400 = GC_OID(get_module_object(v13540));
      if (v82400 != _oid_(ClEnv))
       Result = (*Optimize.legal_ask)(v82400,
        _oid_(v13540));
      else Result = Kernel.ctrue;
        } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_register_property(property *v13540)
{ GC_BIND;
  { OID Result = 0;
    { module * v82389 = ClEnv->module_I;
      OID  v63741 = GC_OID(get_module_object(v13540));
      if (((v63741 == _oid_(claire.it)) || 
            (v63741 == _oid_(v82389))) && 
          (Optimize.OPT->objects->memq(_oid_(v13540)) != CTRUE))
       GC_OBJECT(set,Optimize.OPT->properties)->addFast(_oid_(v13540));
      Result = c_register_object(v13540);
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  selector_register_property(property *v13540)
{ c_register_property(v13540);
  if (allocate_ask_property(v13540) == Kernel.ctrue)
   (Optimize.OPT->allocation = CTRUE);
  return (_oid_(v13540));} 

OID  allocate_ask_property(property *v13540)
{ { OID Result = 0;
    { ITERATE(v82400);
      Result= Kernel.cfalse;
      for (START(v13540->restrictions); NEXT(v82400);)
      if (Kernel._slot == OBJECT(ClaireObject,v82400)->isa)
       { if ((_oid_((INHERIT(OBJECT(restriction,v82400)->range->isa,Kernel._class) ? (ClaireObject *) gcsafe_ask_class((ClaireClass *) OBJECT(ClaireClass,_oid_(OBJECT(restriction,v82400)->range))) :  (ClaireObject *)  gcsafe_ask_type((ClaireType *) OBJECT(ClaireType,_oid_(OBJECT(restriction,v82400)->range))))) != Kernel.ctrue) && 
            (OBJECT(slot,v82400)->srange != Kernel._any))
         { Result = Kernel.ctrue;
          break;} 
        else if ((_oid_((INHERIT(OBJECT(restriction,v82400)->range->isa,Kernel._class) ? (ClaireObject *) gcsafe_ask_class((ClaireClass *) OBJECT(ClaireClass,_oid_(OBJECT(restriction,v82400)->range))) :  (ClaireObject *)  gcsafe_ask_type((ClaireType *) OBJECT(ClaireType,_oid_(OBJECT(restriction,v82400)->range))))) != Kernel.ctrue) && 
            (gcsafe_ask_class(domain_I_restriction(OBJECT(restriction,v82400))) != CTRUE))
         { Result = 0;
          break;} 
        } 
      else if (Kernel._method == OBJECT(ClaireObject,v82400)->isa)
       { if ((BCONTAIN(status_I_restriction(OBJECT(restriction,v82400)),1)) || 
            ((((c_srange_method(OBJECT(method,v82400)) == Kernel._integer) ? CTRUE : ((c_srange_method(OBJECT(method,v82400)) == Kernel._object) ? CTRUE : ((c_srange_method(OBJECT(method,v82400)) == Kernel._any) ? CTRUE : CFALSE))) != CTRUE) || 
              (_oid_((INHERIT(OBJECT(restriction,v82400)->range->isa,Kernel._class) ? (ClaireObject *) gcsafe_ask_class((ClaireClass *) OBJECT(ClaireClass,_oid_(OBJECT(restriction,v82400)->range))) :  (ClaireObject *)  gcsafe_ask_type((ClaireType *) OBJECT(ClaireType,_oid_(OBJECT(restriction,v82400)->range))))) != Kernel.ctrue)))
         { Result = Kernel.ctrue;
          break;} 
        } 
      } 
    return (Result);} 
  } 

ClaireBoolean * stable_ask_relation(ClaireRelation *v13540)
{ { OID  v82389 = get_module_object(v13540);
    if (v13540->open == 2)
     (v13540->open = 1);
    } 
  return (((v13540->open <= 1) ? CTRUE : ((v13540->open == 4) ? CTRUE : CFALSE)));} 

OID  get_module_object(ClaireObject *v13540)
{ return (_oid_(defined_symbol(OBJECT(symbol,(*Kernel.name)(_oid_(v13540))))));} 

OID  known_I_listargs(listargs *v82388)
{ GC_BIND;
  GC_OBJECT(set,Optimize.OPT->to_remove)->addFast(_oid_(Reader.known_I));
  { OID Result = 0;
    { OID gc_local;
      ITERATE(v82394);
      Result= Kernel.cfalse;
      for (START(v82388); NEXT(v82394);)
      { GC_LOOP;
        if (INHERIT(OWNER(v82394),Kernel._property))
         GC_OBJECT(set,Optimize.OPT->knowns)->addFast(v82394);
        GC_UNLOOP;} 
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  oload_module(module *v82389)
{ load_module(v82389);
  return (turbo_module(v82389));} 

OID  oload_string(char *v82382)
{ load_string(v82382);
  return (turbo_module(ClEnv->module_I));} 

OID  turbo_module(module *v82389)
{ GC_RESERVE(5);  // v3.0.55 optim !
  { OID Result = 0;
    { Cint  v64068 = ClEnv->verbose;
      (Optimize.OPT->online_ask = CTRUE);
      (ClEnv->verbose = 0);
      { OID gc_local;
        ITERATE(v82400);
        bag *v82400_support;
        v82400_support = Kernel._method->instances;
        for (START(v82400_support); NEXT(v82400);)
        { GC_LOOP;
          if ((OBJECT(restriction,v82400)->module_I == v82389) && 
              ((OBJECT(method,v82400)->inline_ask != CTRUE) && 
                (((OBJECT(method,v82400)->formula == (NULL)) ? CTRUE : CFALSE) != CTRUE)))
           { lambda * v82388 = GC_OBJECT(lambda,OBJECT(method,v82400)->formula);
            OID  v82401 = GC_OID(v82388->body);
            { ClaireHandler c_handle = ClaireHandler();
              if ERROR_IN 
              { { if (OBJECT(restriction,v82400)->range == Kernel._any)
                   update_property(Kernel.range,
                    OBJECT(ClaireObject,v82400),
                    5,
                    Kernel._object,
                    GC_OID((*Optimize.c_type)(v82401)));
                  (v82388->body = (*Optimize.c_code)(v82401,
                    _oid_(Kernel._any)));
                  (Language._starvariable_index_star->value= (v82388->vars->length+1));
                  (v82388->body = lexical_build_any(GC_OID(v82388->body),GC_OBJECT(list,v82388->vars),Language._starvariable_index_star->value));
                  (v82388->dimension = Language._starvariable_index_star->value);
                  } 
                ClEnv->cHandle--;} 
              else if (belong_to(_oid_(ClEnv->exception_I),_oid_(Kernel._any)) == CTRUE)
              { c_handle.catchIt();{ (v82388->body = v82401);
                  ;} 
                } 
              else PREVIOUS_HANDLER;} 
            } 
          GC_UNLOOP;} 
        } 
      (Optimize.OPT->online_ask = CFALSE);
      (ClEnv->verbose = v64068);
      Result = Kernel.ctrue;
      } 
    GC_UNBIND; return (Result);} 
  } 

void  stats_meta_OPT(Optimize_meta_OPT *v82400)
{ ;} 

