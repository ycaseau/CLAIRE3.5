/***** CLAIRE Compilation of file e:\claire\v3.5\src\compile\osystem.cl 
         [version 3.5.0 / safety 5] Sun May 28 08:25:58 2017 *****/

#include <claire.h>
#include <Kernel.h>
#include <Core.h>
#include <Language.h>
#include <Reader.h>
#include <Optimize.h>
char * home_void()
{ return (getenv_string(CSTRING("CLAIRE3_HOME")));} 

OID  safe_any2(OID v15440)
{ return (v15440);} 

ClaireType * safe_any2_type(ClaireType *v15440)
{ return (v15440);} 

ClaireType * c_type_any_Optimize(OID v9332)
{ GC_BIND;
  { ClaireType *Result ;
    { ClaireObject *V_CC ;
      if (INHERIT(OWNER(v9332),Language._Variable))
       { OID  v15434 = GC_OID(get_property(Kernel.range,OBJECT(ClaireObject,v9332)));
        if (v15434 == CNULL)
         V_CC = Kernel._any;
        else V_CC = (((INHERIT(OWNER(v15434),Core._Union)) && (equal(_oid_(OBJECT(Union,v15434)->t1),_oid_(Kernel.emptySet)) == CTRUE)) ?
          CLREAD(Union,OBJECT(Union,v15434)->t2,t2) :
          ptype_type(OBJECT(ClaireType,v15434)) );
        } 
      else if (INHERIT(OWNER(v9332),Core._global_variable))
       { ClaireType * v15434 = OBJECT(global_variable,v9332)->range;
        if (boolean_I_any(_oid_(v15434)) == CTRUE)
         V_CC = v15434;
        else V_CC = set::alloc(1,OBJECT(global_variable,v9332)->value);
          } 
      else if (INHERIT(OWNER(v9332),Kernel._unbound_symbol))
       V_CC = OBJECT(ClaireType,(*Optimize.Cerror)(_string_(CSTRING("[215] the symbol ~A is unbound_symbol")),
        _oid_(OBJECT(unbound_symbol,v9332)->name)));
      else if (INHERIT(OWNER(v9332),Kernel._error))
       V_CC = Kernel.emptySet;
      else if (INHERIT(OWNER(v9332),Language._Update))
       V_CC = OBJECT(ClaireType,(*Optimize.c_type)(OBJECT(Update,v9332)->value));
      else if (INHERIT(OWNER(v9332),Language._Construct))
       { if (((INHERIT(OBJECT(ClaireObject,v9332)->isa,Language._List)) ? CTRUE : ((INHERIT(OBJECT(ClaireObject,v9332)->isa,Language._Set)) ? CTRUE : CFALSE)) != CTRUE)
         V_CC = Kernel._any;
        else { ClaireType * v8067 = Kernel.emptySet;
            { OID gc_local;
              ITERATE(v1051);
              for (START(OBJECT(Construct,v9332)->args); NEXT(v1051);)
              if (boolean_I_any(_oid_(v8067)) == CTRUE)
               v8067= meet_class(((ClaireClass *) v8067),class_I_type(OBJECT(ClaireType,(*Optimize.c_type)(v1051))));
              else v8067= class_I_type(OBJECT(ClaireType,(*Optimize.c_type)(v1051)));
                } 
            V_CC = nth_class1(((INHERIT(OBJECT(ClaireObject,v9332)->isa,Language._Set)) ?
              Kernel._set :
              Kernel._list ),v8067);
            } 
          } 
      else if (INHERIT(OWNER(v9332),Language._Instruction))
       close_exception(((general_error *) (*Core._general_error)(_string_(CSTRING("c_type of ~S is not defined")),
        _oid_(list::alloc(1,_oid_(OWNER(v9332)))))));
      else V_CC = set::alloc(1,v9332);
        Result= (ClaireType *) V_CC;} 
    GC_UNBIND; return (Result);} 
  } 

OID  c_strict_code_any(OID v15440,ClaireClass *v15435)
{ GC_BIND;
  { OID Result = 0;
    Result = (*Optimize.c_strict_check)(GC_OID((*Optimize.c_code)(v15440,
        _oid_(v15435))),
      _oid_(v15435));
    GC_UNBIND; return (Result);} 
  } 

OID  c_strict_check_any_Optimize(OID v15440,ClaireClass *v15435)
{ GC_BIND;
  { OID Result = 0;
    if ((Optimize.OPT->online_ask != CTRUE) && 
        ((INHERIT(v15435,Kernel._object)) && 
          (inherit_ask_class(stupid_t_any1(v15440),v15435) != CTRUE)))
     { if ((*Optimize.c_type)(v15440) == _oid_(Kernel._any))
       (*Optimize.Cerror)(_string_(CSTRING("Need explict cast: ~S is not a ~S")),
        v15440,
        _oid_(v15435));
      { Compile_C_cast * v10264 = ((Compile_C_cast *) GC_OBJECT(Compile_C_cast,new_object_class(Optimize._C_cast)));
        (v10264->arg = v15440);
        (v10264->set_arg = v15435);
        add_I_property(Kernel.instances,Optimize._C_cast,11,_oid_(v10264));
        Result = _oid_(v10264);
        } 
      } 
    else Result = v15440;
      GC_UNBIND; return (Result);} 
  } 

OID  c_code_any1_Optimize(OID v15440,ClaireClass *v15435)
{ GC_BIND;
  { OID Result = 0;
    { OID  v15441;
      { if (INHERIT(OWNER(v15440),Language._Call))
         v15441 = c_code_call_Call(OBJECT(Call,v15440),v15435);
        else v15441 = (*Optimize.c_code)(v15440);
          GC_OID(v15441);} 
      ClaireClass * v15442 = OBJECT(ClaireClass,(*Optimize.c_sort)(v15441));
      if ((v15435 == Kernel._void) || 
          ((v15442 == v15435) || 
            (Optimize.OPT->online_ask == CTRUE)))
       { if ((v15435 == Kernel._void) && 
            ((INHERIT(OWNER(v15440),Language._Call)) && (OBJECT(Call,v15440)->selector == Kernel._equal)))
         { warn_void();
          tformat_string(CSTRING("-- Equality meant as an assignment: ~S [264]\n"),2,list::alloc(1,v15440));
          } 
        Result = v15441;
        } 
      else if (v15435 == Kernel._any)
       { if ((v15442 == Kernel._integer) && 
            ((INHERIT(OWNER(v15441),Language._Call_slot)) && 
              (((Optimize.compiler->overflow_ask == CTRUE) ? ((Optimize.compiler->class2file_ask == CTRUE) ? CTRUE: CFALSE): CFALSE) != CTRUE)))
         Result = v15441;
        else if (INHERIT(OWNER(v15441),Optimize._to_C))
         Result = OBJECT(Compile_to_C,v15441)->arg;
        else { if (v15442 == Kernel._float)
             { (Optimize.OPT->protection = CTRUE);
              (Optimize.OPT->allocation = CTRUE);
              } 
            { Compile_to_CL * v10264 = ((Compile_to_CL *) GC_OBJECT(Compile_to_CL,new_object_class(Optimize._to_CL)));
              (v10264->arg = v15441);
              (v10264->set_arg = psort_any((*Optimize.c_type)(v15441)));
              add_I_property(Kernel.instances,Optimize._to_CL,11,_oid_(v10264));
              Result = _oid_(v10264);
              } 
            } 
          } 
      else if (v15442 == Kernel._any)
       { Compile_to_C * v10264 = ((Compile_to_C *) GC_OBJECT(Compile_to_C,new_object_class(Optimize._to_C)));
        (v10264->arg = v15441);
        (v10264->set_arg = v15435);
        add_I_property(Kernel.instances,Optimize._to_C,11,_oid_(v10264));
        Result = _oid_(v10264);
        } 
      else Result = v15441;
        } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_any2_Optimize(OID v9332)
{ GC_BIND;
  { OID Result = 0;
    if (INHERIT(OWNER(v9332),Kernel._unbound_symbol))
     Result = (*Optimize.Cerror)(_string_(CSTRING("[215] the symbol ~A is unbound_symbol")),
      _oid_(OBJECT(unbound_symbol,v9332)->name));
    else if (INHERIT(OWNER(v9332),Language._Variable))
     Result = v9332;
    else if (INHERIT(OWNER(v9332),Core._global_variable))
     { c_register_object(OBJECT(ClaireObject,v9332));
      Result = v9332;
      } 
    else if (INHERIT(OWNER(v9332),Language._Optimized_instruction))
     Result = v9332;
    else if (INHERIT(OWNER(v9332),Language._Instruction))
     Result = (*Optimize.Cerror)(_string_(CSTRING("[internal] c_code(~S) should have a parameter")),
      v9332);
    else if (Kernel._set == OWNER(v9332))
     { if (OBJECT(bag,v9332)->length != 0)
       { Set * v15440;
        { { Set * v10264 = ((Set *) GC_OBJECT(Set,new_object_class(Language._Set)));
            (v10264->args = list_I_set(OBJECT(set,v9332)));
            add_I_property(Kernel.instances,Language._Set,11,_oid_(v10264));
            v15440 = v10264;
            } 
          GC_OBJECT(Set,v15440);} 
        if (of_bag(OBJECT(bag,v9332)) != Kernel._void)
         (v15440->of = of_bag(OBJECT(bag,v9332)));
        Result = (*Optimize.c_code)(_oid_(v15440));
        } 
      else Result = v9332;
        } 
    else if (INHERIT(OWNER(v9332),Kernel._list))
     { if (OBJECT(bag,v9332)->length != 0)
       { List * v15440;
        { { List * v10264 = ((List *) GC_OBJECT(List,new_object_class(Language._List)));
            (v10264->args = OBJECT(list,v9332));
            add_I_property(Kernel.instances,Language._List,11,_oid_(v10264));
            v15440 = v10264;
            } 
          GC_OBJECT(List,v15440);} 
        if (of_bag(OBJECT(bag,v9332)) != Kernel._void)
         (v15440->of = of_bag(OBJECT(bag,v9332)));
        Result = (*Optimize.c_code)(_oid_(v15440));
        } 
      else Result = v9332;
        } 
    else if (INHERIT(OWNER(v9332),Kernel._tuple))
     { OID  v6177;
      { Tuple * v10264 = ((Tuple *) GC_OBJECT(Tuple,new_object_class(Language._Tuple)));
        (v10264->args = OBJECT(list,v9332));
        add_I_property(Kernel.instances,Language._Tuple,11,_oid_(v10264));
        v6177 = _oid_(v10264);
        } 
      Result = (*Optimize.c_code)(v6177);
      } 
    else { if (INHERIT(OWNER(v9332),Kernel._thing))
         (*Optimize.c_register)(v9332);
        if ((Kernel._float == OWNER(v9332)) || 
            (INHERIT(OWNER(v9332),Kernel._function)))
         (Optimize.OPT->allocation = CTRUE);
        Result = v9332;
        } 
      GC_UNBIND; return (Result);} 
  } 

ClaireBoolean * c_gc_ask_any(OID v9332)
{ { ClaireBoolean *Result ;
    if (INHERIT(OWNER(v9332),Language._Variable))
     Result = CFALSE;
    else Result = ((INHERIT(OWNER(v9332),Core._global_variable)) ?
      not_any(_oid_((INHERIT(OBJECT(global_variable,v9332)->range->isa,Kernel._class) ? (ClaireObject *) gcsafe_ask_class((ClaireClass *) OBJECT(ClaireClass,_oid_(OBJECT(global_variable,v9332)->range))) :  (ClaireObject *)  gcsafe_ask_type((ClaireType *) OBJECT(ClaireType,_oid_(OBJECT(global_variable,v9332)->range)))))) :
      ((INHERIT(OWNER(v9332),Language._Construct)) ?
        ((Optimize.OPT->loop_gc == CTRUE) ? (((INHERIT(OBJECT(ClaireObject,v9332)->isa,Language._List)) || 
            (INHERIT(OBJECT(ClaireObject,v9332)->isa,Language._Set))) ? CTRUE: CFALSE): CFALSE) :
        ((INHERIT(OWNER(v9332),Language._Instruction)) ?
          CFALSE :
          ((Kernel._string == OWNER(v9332)) ?
            Optimize.OPT->use_string_update :
            CFALSE ) ) ) );
    return (Result);} 
  } 

ClaireClass * c_sort_any_Optimize(OID v9332)
{ GC_BIND;
  { ClaireClass *Result ;
    { ClaireObject *V_CC ;
      if (INHERIT(OWNER(v9332),Core._global_variable))
       { V_CC = ((nativeVar_ask_global_variable(OBJECT(global_variable,v9332)) == CTRUE) ?
          ((equal(_oid_(OBJECT(global_variable,v9332)->range),_oid_(Kernel.emptySet)) == CTRUE) ?
            osort_any(_oid_(OWNER(OBJECT(global_variable,v9332)->value))) :
            osort_any(_oid_(OBJECT(global_variable,v9332)->range)) ) :
          Kernel._any );
        } 
      else if (INHERIT(OWNER(v9332),Language._Instruction))
       { if (INHERIT(OBJECT(ClaireObject,v9332)->isa,Language._Variable))
         V_CC = sort_Variable(OBJECT(Variable,v9332));
        else if (INHERIT(OBJECT(ClaireObject,v9332)->isa,Language._Assign))
         V_CC = sort_Variable(OBJECT(Variable,OBJECT(Assign,v9332)->var));
        else if (INHERIT(OBJECT(ClaireObject,v9332)->isa,Language._Call))
         V_CC = osort_any(_oid_(selector_psort_Call(OBJECT(Call,v9332))));
        else if (INHERIT(OBJECT(ClaireObject,v9332)->isa,Language._Call_method))
         { V_CC = (((OBJECT(Call_method,v9332)->arg->selector == Core.externC) && 
              (OBJECT(Call_method,v9332)->args->length == 2)) ?
            psort_any((*(OBJECT(Call_method,v9332)->args))[2]) :
            c_srange_method(OBJECT(Call_method,v9332)->arg) );
          } 
        else if (INHERIT(OBJECT(ClaireObject,v9332)->isa,Language._Call_slot))
         V_CC = OBJECT(Call_slot,v9332)->selector->srange;
        else if (INHERIT(OBJECT(ClaireObject,v9332)->isa,Language._Call_table))
         V_CC = Kernel._any;
        else if (INHERIT(OBJECT(ClaireObject,v9332)->isa,Language._Call_array))
         { V_CC = ((OBJECT(Call_array,v9332)->test == _oid_(Kernel._float)) ?
            Kernel._float :
            Kernel._any );
          } 
        else if (INHERIT(OBJECT(ClaireObject,v9332)->isa,Language._Definition))
         V_CC = Kernel._object;
        else if (INHERIT(OBJECT(ClaireObject,v9332)->isa,Optimize._to_C))
         V_CC = OBJECT(Compile_to_C,v9332)->set_arg;
        else if (INHERIT(OBJECT(ClaireObject,v9332)->isa,Optimize._to_protect))
         V_CC = OBJECT(ClaireClass,(*Optimize.c_sort)(OBJECT(Compile_to_protect,v9332)->arg));
        else if (INHERIT(OBJECT(ClaireObject,v9332)->isa,Language._Update))
         V_CC = OBJECT(ClaireClass,(*Optimize.c_sort)(OBJECT(Update,v9332)->value));
        else if (INHERIT(OBJECT(ClaireObject,v9332)->isa,Language._If))
         V_CC = psort_any(_oid_(meet_class(OBJECT(ClaireClass,(*Optimize.c_sort)(OBJECT(If,v9332)->arg)),OBJECT(ClaireClass,(*Optimize.c_sort)(OBJECT(If,v9332)->other)))));
        else if (INHERIT(OBJECT(ClaireObject,v9332)->isa,Language._Handle))
         V_CC = psort_any(_oid_(meet_class(OBJECT(ClaireClass,(*Optimize.c_sort)(OBJECT(ClaireHandle,v9332)->arg)),OBJECT(ClaireClass,(*Optimize.c_sort)(OBJECT(ClaireHandle,v9332)->other)))));
        else if (INHERIT(OBJECT(ClaireObject,v9332)->isa,Language._Let))
         V_CC = OBJECT(ClaireClass,(*Optimize.c_sort)(OBJECT(Let,v9332)->arg));
        else if (INHERIT(OBJECT(ClaireObject,v9332)->isa,Optimize._to_CL))
         V_CC = Kernel._any;
        else if (INHERIT(OBJECT(ClaireObject,v9332)->isa,Language._Return))
         V_CC = Kernel._any;
        else if (INHERIT(OBJECT(ClaireObject,v9332)->isa,Language._List))
         V_CC = Kernel._object;
        else if (INHERIT(OBJECT(ClaireObject,v9332)->isa,Language._Set))
         V_CC = Kernel._object;
        else if (INHERIT(OBJECT(ClaireObject,v9332)->isa,Language._Tuple))
         V_CC = Kernel._object;
        else if (INHERIT(OBJECT(ClaireObject,v9332)->isa,Language._Construct))
         V_CC = Kernel._any;
        else if (INHERIT(OBJECT(ClaireObject,v9332)->isa,Language._Gassign))
         V_CC = Kernel._any;
        else if (INHERIT(OBJECT(ClaireObject,v9332)->isa,Language._Super))
         V_CC = Kernel._any;
        else if (INHERIT(OBJECT(ClaireObject,v9332)->isa,Language._For))
         V_CC = Kernel._any;
        else if (INHERIT(OBJECT(ClaireObject,v9332)->isa,Language._Exists))
         { V_CC = ((OBJECT(Exists,v9332)->other == CNULL) ?
            Kernel._any :
            Kernel._object );
          } 
        else if (INHERIT(OBJECT(ClaireObject,v9332)->isa,Language._Iteration))
         V_CC = Kernel._object;
        else if (INHERIT(OBJECT(ClaireObject,v9332)->isa,Language._And))
         V_CC = Kernel._boolean;
        else if (INHERIT(OBJECT(ClaireObject,v9332)->isa,Language._Or))
         V_CC = Kernel._boolean;
        else if (INHERIT(OBJECT(ClaireObject,v9332)->isa,Language._While))
         V_CC = Kernel._any;
        else if (INHERIT(OBJECT(ClaireObject,v9332)->isa,Language._Do))
         V_CC = OBJECT(ClaireClass,(*Optimize.c_sort)(GC_OID(last_list(OBJECT(Do,v9332)->args))));
        else close_exception(((general_error *) (*Core._general_error)(_string_(CSTRING("[internal] c_sort is not implemented for ~S")),
            _oid_(list::alloc(1,_oid_(OWNER(v9332)))))));
          } 
      else V_CC = ((Kernel._float == OWNER(v9332)) ?
        Kernel._float :
        psort_any((*Optimize.c_type)(v9332)) );
      Result= (ClaireClass *) V_CC;} 
    GC_UNBIND; return (Result);} 
  } 

ClaireClass * selector_psort_Call(Call *v9332)
{ { ClaireClass *Result ;
    { property * v15432 = v9332->selector;
      Result = (((v15432 == Core.base_I) || 
          (v15432 == Core.index_I)) ?
        Kernel._integer :
        ((v15432 == Optimize.anyObject_I) ?
          OBJECT(ClaireClass,(*(v9332->args))[1]) :
          ((v15432 == Optimize.object_I) ?
            OBJECT(ClaireClass,(*(v9332->args))[2]) :
            Kernel._any ) ) );
      } 
    return (Result);} 
  } 

Cint  c_status_any(OID v9332,list *v15428)
{ GC_BIND;
  { Cint Result = 0;
    if (INHERIT(OWNER(v9332),Language._Instruction))
     { if (INHERIT(OBJECT(ClaireObject,v9332)->isa,Language._Variable))
       { Result = (((OBJECT(Variable,v9332)->range == (NULL)) || 
            (_oid_((INHERIT(OBJECT(Variable,v9332)->range->isa,Kernel._class) ? (ClaireObject *) gcsafe_ask_class((ClaireClass *) OBJECT(ClaireClass,_oid_(OBJECT(Variable,v9332)->range))) :  (ClaireObject *)  gcsafe_ask_type((ClaireType *) OBJECT(ClaireType,_oid_(OBJECT(Variable,v9332)->range))))) != Kernel.ctrue)) ?
          ((contain_ask_list(v15428,v9332) == CTRUE) ?
            16 :
            (((((OBJECT(Variable,v9332)->range == (NULL)) ? CTRUE : CFALSE) != CTRUE) && 
                (_inf_equal_type(GC_OBJECT(ClaireType,OBJECT(Variable,v9332)->range),Kernel._float) == CTRUE)) ?
              2 :
              0 ) ) :
          32 );
        } 
      else if (INHERIT(OBJECT(ClaireObject,v9332)->isa,Language._Error))
       Result = 32;
      else if (INHERIT(OBJECT(ClaireObject,v9332)->isa,Language._Printf))
       { Cint  v2145;
        { Cint  v14786 = 0;
          { OID gc_local;
            ITERATE(v14788);
            bag *v14788_support;
            v14788_support = GC_OBJECT(list,OBJECT(Construct,v9332)->args);
            for (START(v14788_support); NEXT(v14788);)
            { Cint  v14787 = c_status_any(v14788,v15428);
              v14786= c_or_integer(v14786,v14787);
              } 
            } 
          v2145 = v14786;
          } 
        Result = c_return_integer(0,v2145);
        } 
      else if (INHERIT(OBJECT(ClaireObject,v9332)->isa,Language._Construct))
       Result = 2;
      else if (INHERIT(OBJECT(ClaireObject,v9332)->isa,Language._Definition))
       Result = 2;
      else if (INHERIT(OBJECT(ClaireObject,v9332)->isa,Language._Call))
       { Cint  v3367 = c_status_call_property(OBJECT(Call,v9332)->selector,GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)((*(v15428))[1]))));
        Cint  v3368;
        { Cint  v14789 = 0;
          { OID gc_local;
            ITERATE(v14792);
            bag *v14792_support;
            v14792_support = GC_OBJECT(list,OBJECT(Call,v9332)->args);
            for (START(v14792_support); NEXT(v14792);)
            { Cint  v14791 = c_status_any(v14792,v15428);
              v14789= c_or_integer(v14789,v14791);
              } 
            } 
          v3368 = v14789;
          } 
        Result = c_return_integer(v3367,v3368);
        } 
      else if (INHERIT(OBJECT(ClaireObject,v9332)->isa,Language._If))
       { Cint  v3367 = c_status_any(GC_OID(OBJECT(If,v9332)->arg),v15428);
        Cint  v3368 = c_status_any(GC_OID(OBJECT(If,v9332)->other),v15428);
        Result = c_return_integer(c_or_integer(v3367,v3368),c_status_any(GC_OID(OBJECT(If,v9332)->test),v15428));
        } 
      else if (INHERIT(OBJECT(ClaireObject,v9332)->isa,Language._Do))
       { OID  v15441 = GC_OID(last_list(OBJECT(Do,v9332)->args));
        Cint  v3367 = c_status_any(v15441,v15428);
        Cint  v3368;
        { Cint  v14793 = 0;
          { OID gc_local;
            ITERATE(v14815);
            bag *v14815_support;
            v14815_support = GC_OBJECT(list,OBJECT(Do,v9332)->args);
            for (START(v14815_support); NEXT(v14815);)
            if (equal(v14815,v15441) != CTRUE)
             { Cint  v14814 = c_status_any(v14815,v15428);
              v14793= c_or_integer(v14793,v14814);
              } 
            } 
          v3368 = v14793;
          } 
        Result = c_return_integer(v3367,v3368);
        } 
      else if (INHERIT(OBJECT(ClaireObject,v9332)->isa,Language._For))
       Result = c_return_integer(c_status_any(GC_OID(OBJECT(Iteration,v9332)->arg),v15428),c_status_any(GC_OID(OBJECT(Iteration,v9332)->set_arg),v15428));
      else if (INHERIT(OBJECT(ClaireObject,v9332)->isa,Language._Iteration))
       Result = c_return_integer(2,c_status_any(GC_OID(OBJECT(Iteration,v9332)->arg),v15428));
      else if (INHERIT(OBJECT(ClaireObject,v9332)->isa,Language._Let))
       Result = c_return_integer(c_status_any(GC_OID(OBJECT(Let,v9332)->arg),v15428),c_status_any(GC_OID(OBJECT(Let,v9332)->value),v15428));
      else if (INHERIT(OBJECT(ClaireObject,v9332)->isa,Language._Assign))
       Result = c_status_any(GC_OID(OBJECT(Assign,v9332)->arg),v15428);
      else if (INHERIT(OBJECT(ClaireObject,v9332)->isa,Language._Gassign))
       Result = c_status_any(GC_OID(OBJECT(Gassign,v9332)->arg),v15428);
      else if (INHERIT(OBJECT(ClaireObject,v9332)->isa,Language._And))
       { Cint  v3106;
        { Cint  v14816 = 0;
          { OID gc_local;
            ITERATE(v14818);
            bag *v14818_support;
            v14818_support = GC_OBJECT(list,OBJECT(And,v9332)->args);
            for (START(v14818_support); NEXT(v14818);)
            { Cint  v14817 = c_status_any(v14818,v15428);
              v14816= c_or_integer(v14816,v14817);
              } 
            } 
          v3106 = v14816;
          } 
        Result = c_return_integer(0,v3106);
        } 
      else if (INHERIT(OBJECT(ClaireObject,v9332)->isa,Language._Or))
       { Cint  v4067;
        { Cint  v14819 = 0;
          { OID gc_local;
            ITERATE(v14821);
            bag *v14821_support;
            v14821_support = GC_OBJECT(list,OBJECT(Or,v9332)->args);
            for (START(v14821_support); NEXT(v14821);)
            { Cint  v14820 = c_status_any(v14821,v15428);
              v14819= c_or_integer(v14819,v14820);
              } 
            } 
          v4067 = v14819;
          } 
        Result = c_return_integer(0,v4067);
        } 
      else if (INHERIT(OBJECT(ClaireObject,v9332)->isa,Language._Cast))
       Result = c_status_any(GC_OID(OBJECT(Cast,v9332)->arg),v15428);
      else if (INHERIT(OBJECT(ClaireObject,v9332)->isa,Language._Super))
       { Cint  v3367 = c_status_call_property(OBJECT(Super,v9332)->selector,GC_OBJECT(ClaireType,OBJECT(Super,v9332)->cast_to));
        Cint  v3368;
        { Cint  v14822 = 0;
          { OID gc_local;
            ITERATE(v14846);
            bag *v14846_support;
            v14846_support = GC_OBJECT(list,OBJECT(Super,v9332)->args);
            for (START(v14846_support); NEXT(v14846);)
            { Cint  v14823 = c_status_any(v14846,v15428);
              v14822= c_or_integer(v14822,v14823);
              } 
            } 
          v3368 = v14822;
          } 
        Result = c_return_integer(v3367,v3368);
        } 
      else if (INHERIT(OBJECT(ClaireObject,v9332)->isa,Language._Case))
       { Cint  v14847 = 0;
        { OID gc_local;
          ITERATE(v14849);
          bag *v14849_support;
          v14849_support = GC_OBJECT(list,OBJECT(Case,v9332)->args);
          for (START(v14849_support); NEXT(v14849);)
          { Cint  v14848 = c_status_any(v14849,v15428);
            v14847= c_or_integer(v14847,v14848);
            } 
          } 
        Result = v14847;
        } 
      else Result = ((INHERIT(OBJECT(ClaireObject,v9332)->isa,Language._While)) ?
        c_return_integer(c_status_any(GC_OID(OBJECT(While,v9332)->arg),v15428),c_status_any(GC_OID(OBJECT(While,v9332)->test),v15428)) :
        ((INHERIT(OBJECT(ClaireObject,v9332)->isa,Language._Return)) ?
          c_status_any(GC_OID(OBJECT(Return,v9332)->arg),v15428) :
          ((INHERIT(OBJECT(ClaireObject,v9332)->isa,Language._Handle)) ?
            c_return_integer(c_or_integer(c_status_any(GC_OID(OBJECT(ClaireHandle,v9332)->arg),v15428),c_status_any(GC_OID(OBJECT(ClaireHandle,v9332)->other),v15428)),c_status_any(GC_OID(OBJECT(ClaireHandle,v9332)->test),v15428)) :
            ((INHERIT(OBJECT(ClaireObject,v9332)->isa,Kernel._unbound_symbol)) ?
              0 :
              (*Optimize.Cerror)(_string_(CSTRING("[internal] oops .. I forgot ~S")),
                _oid_(OWNER(v9332))) ) ) ) );
      } 
    else Result = ((Kernel._float == OWNER(v9332)) ?
      2 :
      ((Kernel._string == OWNER(v9332)) ?
        2 :
        ((INHERIT(OWNER(v9332),Kernel._function)) ?
          2 :
          ((INHERIT(OWNER(v9332),Core._Type)) ?
            2 :
            0 ) ) ) );
    GC_UNBIND; return (Result);} 
  } 

Cint  c_or_integer(Cint v15440,Cint v15441)
{ { Cint Result = 0;
    { Cint  v15420 = or_integer(v15440,v15441);
      if ((BCONTAIN(v15420,5)) && 
          (((BCONTAIN(v15440,5)) ? ((BCONTAIN(v15441,5)) ? CTRUE: CFALSE): CFALSE) != CTRUE))
       v15420= (v15420-exp2_integer(5));
      if ((BCONTAIN(v15420,6)) && 
          (((BCONTAIN(v15440,6)) ? ((BCONTAIN(v15441,6)) ? CTRUE: CFALSE): CFALSE) != CTRUE))
       v15420= (v15420-exp2_integer(6));
      if ((BCONTAIN(v15420,4)) && 
          (((BCONTAIN(v15440,4)) ? ((BCONTAIN(v15441,4)) ? CTRUE: CFALSE): CFALSE) != CTRUE))
       v15420= (v15420-exp2_integer(4));
      Result = v15420;
      } 
    return (Result);} 
  } 

Cint  c_or_list(list *v15428)
{ { Cint Result = 0;
    { Cint  v15420 = 0;
      { ITERATE(v15440);
        for (START(v15428); NEXT(v15440);)
        v15420= c_or_integer(v15420,v15440);
        } 
      Result = v15420;
      } 
    return (Result);} 
  } 

Cint  status_I_restriction(restriction *v9332)
{ GC_BIND;
  { Cint Result = 0;
    if (Kernel._method == v9332->isa)
     { if (((CLREAD(method,v9332,status) == (CNULL)) ? CTRUE : CFALSE) != CTRUE)
       Result = CLREAD(method,v9332,status);
      else if (CLREAD(method,v9332,formula) == (NULL))
       { (CLREAD(method,v9332,status) = 0);
        Result = 0;
        } 
      else { (CLREAD(method,v9332,status) = 0);
          (CLREAD(method,v9332,status) = c_status_any(GC_OID(CLREAD(method,v9332,formula)->body),GC_OBJECT(list,CLREAD(method,v9332,formula)->vars)));
          Result = CLREAD(method,v9332,status);
          } 
        } 
    else Result = 0;
      GC_UNBIND; return (Result);} 
  } 

Cint  c_return_integer(Cint v15440,Cint v15441)
{ { Cint Result = 0;
    { Cint  v15420 = or_integer(v15440,v15441);
      if ((nth_integer(v15440,5) != CTRUE) && 
          (BCONTAIN(v15441,5)))
       v15420= (v15420-exp2_integer(5));
      if ((nth_integer(v15440,4) != CTRUE) && 
          (BCONTAIN(v15441,4)))
       v15420= (v15420-exp2_integer(4));
      Result = v15420;
      } 
    return (Result);} 
  } 

Cint  c_status_call_property(property *v9332,ClaireType *v15436)
{ { Cint Result = 0;
    { Cint  v15434 = ((stable_ask_relation(v9332) == CTRUE) ?
        0 :
        (*Language.bit_vector)(1,
          2,
          3) );
      { ITERATE(v15440);
        for (START(v9332->restrictions); NEXT(v15440);)
        if (boolean_I_any((*Core.glb)(_oid_(v15436),
          (*(OBJECT(restriction,v15440)->domain))[1])) == CTRUE)
         { if (Kernel._method == OBJECT(ClaireObject,v15440)->isa)
           { if (((last_list(OBJECT(method,v15440)->srange) == _oid_(Kernel._integer)) ? CTRUE : ((last_list(OBJECT(method,v15440)->srange) == _oid_(Kernel._object)) ? CTRUE : ((last_list(OBJECT(method,v15440)->srange) == _oid_(Kernel._any)) ? CTRUE : ((last_list(OBJECT(method,v15440)->srange) == _oid_(Kernel._void)) ? CTRUE : CFALSE)))) != CTRUE)
             v15434= c_or_integer(v15434,2);
            v15434= c_or_integer(v15434,status_I_restriction(OBJECT(restriction,v15440)));
            } 
          else if (Kernel._slot == OBJECT(ClaireObject,v15440)->isa)
           v15434= c_or_integer(v15434,exp2_integer(4));
          } 
        } 
      Result = v15434;
      } 
    return (Result);} 
  } 

OID  showstatus_method2(method *v15429)
{ GC_RESERVE(1);  // HOHO v3.0.55 optim !
  { OID Result = 0;
    { list * v3181 = list::alloc(7,_string_(CSTRING("NEW_ALLOC")),
        _string_(CSTRING("BAG_UPDATE")),
        _string_(CSTRING("SLOT_UPDATE")),
        _string_(CSTRING("RETURN_ARG")),
        _string_(CSTRING("SAFE_RESULT")),
        _string_(CSTRING("SAFE_GC")),
        _string_(CSTRING("STRING_UPDATE")));
      list * v15428 = list::empty(Kernel._any);
      Cint  v15435 = v15429->status;
      { Cint  v15425 = 1;
        Cint  v14853 = 7;
        { OID gc_local;
          while ((v15425 <= v14853))
          { GC_LOOP;
            if (BCONTAIN(v15435,v15425))
             GC__ANY(v15428 = v15428->addFast((*(v3181))[v15425]), 1);
            ++v15425;
            GC_UNLOOP;} 
          } 
        } 
      Result = _oid_(v15428);
      } 
    GC_UNBIND; return (Result);} 
  } 

void  s_test_method2(method *v15429)
{ GC_BIND;
  { lambda * v3229 = GC_OBJECT(lambda,v15429->formula);
    Cint  v8187 = c_status_any(GC_OID(v3229->body),GC_OBJECT(list,v3229->vars));
    tformat_string(CSTRING("status(~S) := ~S \n"),0,list::alloc(2,_oid_(v15429),v8187));
    (v15429->status = v8187);
    showstatus_method2(v15429);
    } 
  GC_UNBIND;} 

ClaireBoolean * legal_ask_module(module *v9332,OID v15440)
{ if ((v15440 == _oid_(Optimize.object_I)) || 
      (v15440 == _oid_(Optimize.anyObject_I))) 
  { { ClaireBoolean *Result ;
      Result = CTRUE;
      return (Result);} 
     } 
  else{ GC_BIND;
    { ClaireBoolean *Result ;
      if (Optimize.OPT->legal_modules->length != 0)
       { if ((contain_ask_set(Optimize.OPT->legal_modules,_oid_(v9332)) != CTRUE) && 
            ((Kernel._method == OWNER(v15440)) && ((OBJECT(method,v15440)->inline_ask == CFALSE) || 
                (Optimize.compiler->inline_ask != CTRUE))))
         { tformat_string(CSTRING("legal_modules = ~S\n"),0,list::alloc(1,GC_OID(_oid_(Optimize.OPT->legal_modules))));
          tformat_string(CSTRING("---- ERROR: ~S implies using ~S !\n\n"),0,list::alloc(2,v15440,_oid_(v9332)));
          Result = CFALSE;
          } 
        else Result = CTRUE;
          } 
      else { GC_OBJECT(set,Optimize.OPT->need_modules)->addFast(_oid_(v9332));
          Result = CTRUE;
          } 
        GC_UNBIND; return (Result);} 
    } 
  } 

OID  legal_ask_environment(ClaireEnvironment *v9332,OID v15440)
{ return (Kernel.ctrue);} 

OID  c_register_object(ClaireObject *v9332)
{ GC_BIND;
  { OID Result = 0;
    { OID  v15440 = GC_OID(get_module_object(v9332));
      if (v15440 != _oid_(ClEnv))
       Result = (*Optimize.legal_ask)(v15440,
        _oid_(v9332));
      else Result = Kernel.ctrue;
        } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_register_property(property *v9332)
{ GC_BIND;
  { OID Result = 0;
    { module * v15429 = ClEnv->module_I;
      OID  v3213 = GC_OID(get_module_object(v9332));
      if (((v3213 == _oid_(claire.it)) || 
            (v3213 == _oid_(v15429))) && 
          (Optimize.OPT->objects->memq(_oid_(v9332)) != CTRUE))
       GC_OBJECT(set,Optimize.OPT->properties)->addFast(_oid_(v9332));
      Result = c_register_object(v9332);
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  selector_register_property(property *v9332)
{ c_register_property(v9332);
  if (allocate_ask_property(v9332) == Kernel.ctrue)
   (Optimize.OPT->allocation = CTRUE);
  return (_oid_(v9332));} 

OID  allocate_ask_property(property *v9332)
{ { OID Result = 0;
    { ITERATE(v15440);
      Result= Kernel.cfalse;
      for (START(v9332->restrictions); NEXT(v15440);)
      if (Kernel._slot == OBJECT(ClaireObject,v15440)->isa)
       { if ((_oid_((INHERIT(OBJECT(restriction,v15440)->range->isa,Kernel._class) ? (ClaireObject *) gcsafe_ask_class((ClaireClass *) OBJECT(ClaireClass,_oid_(OBJECT(restriction,v15440)->range))) :  (ClaireObject *)  gcsafe_ask_type((ClaireType *) OBJECT(ClaireType,_oid_(OBJECT(restriction,v15440)->range))))) != Kernel.ctrue) && 
            (OBJECT(slot,v15440)->srange != Kernel._any))
         { Result = Kernel.ctrue;
          break;} 
        else if ((_oid_((INHERIT(OBJECT(restriction,v15440)->range->isa,Kernel._class) ? (ClaireObject *) gcsafe_ask_class((ClaireClass *) OBJECT(ClaireClass,_oid_(OBJECT(restriction,v15440)->range))) :  (ClaireObject *)  gcsafe_ask_type((ClaireType *) OBJECT(ClaireType,_oid_(OBJECT(restriction,v15440)->range))))) != Kernel.ctrue) && 
            (gcsafe_ask_class(domain_I_restriction(OBJECT(restriction,v15440))) != CTRUE))
         { Result = 0;
          break;} 
        } 
      else if (Kernel._method == OBJECT(ClaireObject,v15440)->isa)
       { if ((BCONTAIN(status_I_restriction(OBJECT(restriction,v15440)),1)) || 
            ((((c_srange_method(OBJECT(method,v15440)) == Kernel._integer) ? CTRUE : ((c_srange_method(OBJECT(method,v15440)) == Kernel._object) ? CTRUE : ((c_srange_method(OBJECT(method,v15440)) == Kernel._any) ? CTRUE : CFALSE))) != CTRUE) || 
              (_oid_((INHERIT(OBJECT(restriction,v15440)->range->isa,Kernel._class) ? (ClaireObject *) gcsafe_ask_class((ClaireClass *) OBJECT(ClaireClass,_oid_(OBJECT(restriction,v15440)->range))) :  (ClaireObject *)  gcsafe_ask_type((ClaireType *) OBJECT(ClaireType,_oid_(OBJECT(restriction,v15440)->range))))) != Kernel.ctrue)))
         { Result = Kernel.ctrue;
          break;} 
        } 
      } 
    return (Result);} 
  } 

ClaireBoolean * stable_ask_relation(ClaireRelation *v9332)
{ { OID  v15429 = get_module_object(v9332);
    if (v9332->open == 2)
     (v9332->open = 1);
    } 
  return (((v9332->open <= 1) ? CTRUE : ((v9332->open == 4) ? CTRUE : CFALSE)));} 

OID  get_module_object(ClaireObject *v9332)
{ return (_oid_(defined_symbol(OBJECT(symbol,(*Kernel.name)(_oid_(v9332))))));} 

OID  known_I_listargs(listargs *v15428)
{ GC_BIND;
  GC_OBJECT(set,Optimize.OPT->to_remove)->addFast(_oid_(Reader.known_I));
  { OID Result = 0;
    { OID gc_local;
      ITERATE(v15434);
      Result= Kernel.cfalse;
      for (START(v15428); NEXT(v15434);)
      { GC_LOOP;
        if (INHERIT(OWNER(v15434),Kernel._property))
         GC_OBJECT(set,Optimize.OPT->knowns)->addFast(v15434);
        GC_UNLOOP;} 
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  oload_module(module *v15429)
{ load_module(v15429);
  return (turbo_module(v15429));} 

OID  oload_string(char *v15422)
{ load_string(v15422);
  return (turbo_module(ClEnv->module_I));} 

OID  turbo_module(module *v15429)
{ GC_RESERVE(5);  // v3.0.55 optim !
  { OID Result = 0;
    { Cint  v3540 = ClEnv->verbose;
      (Optimize.OPT->online_ask = CTRUE);
      (ClEnv->verbose = 0);
      { OID gc_local;
        ITERATE(v15440);
        bag *v15440_support;
        v15440_support = Kernel._method->instances;
        for (START(v15440_support); NEXT(v15440);)
        { GC_LOOP;
          if ((OBJECT(restriction,v15440)->module_I == v15429) && 
              ((OBJECT(method,v15440)->inline_ask != CTRUE) && 
                (((OBJECT(method,v15440)->formula == (NULL)) ? CTRUE : CFALSE) != CTRUE)))
           { lambda * v15428 = GC_OBJECT(lambda,OBJECT(method,v15440)->formula);
            OID  v15441 = GC_OID(v15428->body);
            { ClaireHandler c_handle = ClaireHandler();
              if ERROR_IN 
              { { if (OBJECT(restriction,v15440)->range == Kernel._any)
                   update_property(Kernel.range,
                    OBJECT(ClaireObject,v15440),
                    5,
                    Kernel._object,
                    GC_OID((*Optimize.c_type)(v15441)));
                  (v15428->body = (*Optimize.c_code)(v15441,
                    _oid_(Kernel._any)));
                  (Language._starvariable_index_star->value= (v15428->vars->length+1));
                  (v15428->body = lexical_build_any(GC_OID(v15428->body),GC_OBJECT(list,v15428->vars),Language._starvariable_index_star->value));
                  (v15428->dimension = Language._starvariable_index_star->value);
                  } 
                ClEnv->cHandle--;} 
              else if (belong_to(_oid_(ClEnv->exception_I),_oid_(Kernel._any)) == CTRUE)
              { c_handle.catchIt();{ (v15428->body = v15441);
                  ;} 
                } 
              else PREVIOUS_HANDLER;} 
            } 
          GC_UNLOOP;} 
        } 
      (Optimize.OPT->online_ask = CFALSE);
      (ClEnv->verbose = v3540);
      Result = Kernel.ctrue;
      } 
    GC_UNBIND; return (Result);} 
  } 

void  stats_meta_OPT(Optimize_meta_OPT *v15440)
{ ;} 

