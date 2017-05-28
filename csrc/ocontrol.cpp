/***** CLAIRE Compilation of file e:\claire\v3.5\src\compile\ocontrol.cl 
         [version 3.5.0 / safety 5] Sun May 28 08:25:59 2017 *****/

#include <claire.h>
#include <Kernel.h>
#include <Core.h>
#include <Language.h>
#include <Reader.h>
#include <Optimize.h>
ClaireType * c_type_Assign_Optimize(Assign *v9332)
{ GC_BIND;
  { ClaireType *Result ;
    Result = OBJECT(ClaireType,(*Optimize.c_type)(v9332->arg));
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_Assign_Optimize(Assign *v9332)
{ GC_BIND;
  { OID Result = 0;
    { OID  v15438 = GC_OID(v9332->var);
      OID  v15440 = GC_OID(v9332->arg);
      ClaireType * v1207 = GC_OBJECT(ClaireType,ptype_type(OBJECT(ClaireType,(*Optimize.c_type)(v15440))));
      if (inherit_ask_class(OWNER(v15438),Language._Variable) != CTRUE)
       (*Optimize.Cerror)(_string_(CSTRING("[213] ~S is not a variable")),
        v15438);
      if (_oid_((ClaireObject *) Core._inf_equalt->fcall(((Cint) v1207),((Cint) OBJECT(ClaireObject,GC_OID((*Kernel.range)(v15438)))))) != Kernel.ctrue)
       v15440= GC_OID((*Optimize.c_warn)(GC_OID(v9332->var),
        v15440,
        _oid_(v1207)));
      { OID  v8505 = GC_OID(c_gc_I_any2(GC_OID(c_strict_code_any(v15440,psort_any((*Kernel.range)(v15438)))),GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Kernel._exp)(GC_OID((*Kernel.range)(v15438)),
          _oid_(v1207))))));
        gc_register_Variable2(OBJECT(Variable,v15438),v8505);
        { Assign * v10264 = ((Assign *) GC_OBJECT(Assign,new_object_class(Language._Assign)));
          (v10264->var = v15438);
          (v10264->arg = v8505);
          add_I_property(Kernel.instances,Language._Assign,11,_oid_(v10264));
          Result = _oid_(v10264);
          } 
        } 
      } 
    GC_UNBIND; return (Result);} 
  } 

ClaireBoolean * c_gc_ask_Assign(Assign *v9332)
{ GC_BIND;
  { ClaireBoolean *Result ;
    Result = OBJECT(ClaireBoolean,(*Optimize.c_gc_ask)(v9332->arg));
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_Gassign_Optimize(Gassign *v9332)
{ GC_BIND;
  { ClaireType *Result ;
    Result = OBJECT(ClaireType,(*Optimize.c_type)(v9332->arg));
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_Gassign_Optimize(Gassign *v9332)
{ GC_BIND;
  { OID Result = 0;
    { OID  v1049 = GC_OID(v9332->arg);
      ClaireType * v1207 = GC_OBJECT(ClaireType,ptype_type(OBJECT(ClaireType,(*Optimize.c_type)(v1049))));
      if (boolean_I_any(_oid_(v9332->var->range)) != CTRUE)
       (*Optimize.Cerror)(_string_(CSTRING("[214] cannot assign ~S")),
        _oid_(v9332));
      if (_oid_((ClaireObject *) Core._inf_equalt->fcall(((Cint) v1207),((Cint) v9332->var->range))) != Kernel.ctrue)
       v1049= GC_OID(c_check_any(GC_OID((*Optimize.c_code)(v1049,
        _oid_(Kernel._any))),GC_OID((*Optimize.c_code)(_oid_(v9332->var->range),
        _oid_(Kernel._type)))));
      { Gassign * v10264 = ((Gassign *) GC_OBJECT(Gassign,new_object_class(Language._Gassign)));
        store_object(v10264,
          2,
          Kernel._object,
          (*Optimize.c_code)(_oid_(v9332->var)),
          CFALSE);
        { Gassign * v15903 = v10264; 
          OID  v15904;
          if (nativeVar_ask_global_variable(v9332->var) == CTRUE)
           v15904 = c_strict_code_any(v1049,psort_any(_oid_(v9332->var->range)));
          else v15904 = (*Optimize.c_code)(v1049,
              _oid_(Kernel._any));
            (v15903->arg = v15904);} 
        add_I_property(Kernel.instances,Language._Gassign,11,_oid_(v10264));
        Result = _oid_(v10264);
        } 
      } 
    GC_UNBIND; return (Result);} 
  } 

ClaireBoolean * c_gc_ask_Gassign(Gassign *v9332)
{ GC_BIND;
  { ClaireBoolean *Result ;
    Result = OBJECT(ClaireBoolean,(*Optimize.c_gc_ask)(v9332->arg));
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_And_Optimize(And *v9332)
{ return (Kernel._boolean);} 

OID  c_code_And_Optimize(And *v9332)
{ GC_BIND;
  { OID Result = 0;
    { And * v10264 = ((And *) GC_OBJECT(And,new_object_class(Language._And)));
      { And * v15905 = v10264; 
        list * v15907;
        { bag *v_list; OID v_val;
          OID v15440,CLcount;
          v_list = GC_OBJECT(list,v9332->args);
           v15907 = v_list->clone();
          for (CLcount= 1; CLcount <= v_list->length; CLcount++)
          { v15440 = (*(v_list))[CLcount];
            { if ((*Optimize.c_type)(v15440) == _oid_(Kernel._void))
               (*Optimize.Cerror)(_string_(CSTRING("[206] void ~S in ~S")),
                v15440,
                _oid_(v9332));
              v_val = c_boolean_any(v15440);
              } 
            
            (*((list *) v15907))[CLcount] = v_val;} 
          } 
        (v15905->args = v15907);} 
      add_I_property(Kernel.instances,Language._And,11,_oid_(v10264));
      Result = _oid_(v10264);
      } 
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_Or_Optimize(Or *v9332)
{ return (Kernel._boolean);} 

OID  c_code_Or_Optimize(Or *v9332)
{ GC_BIND;
  { OID Result = 0;
    { Or * v10264 = ((Or *) GC_OBJECT(Or,new_object_class(Language._Or)));
      { Or * v15908 = v10264; 
        list * v15910;
        { bag *v_list; OID v_val;
          OID v15440,CLcount;
          v_list = GC_OBJECT(list,v9332->args);
           v15910 = v_list->clone();
          for (CLcount= 1; CLcount <= v_list->length; CLcount++)
          { v15440 = (*(v_list))[CLcount];
            { if ((*Optimize.c_type)(v15440) == _oid_(Kernel._void))
               (*Optimize.Cerror)(_string_(CSTRING("[206] void ~S in ~S")),
                v15440,
                _oid_(v9332));
              v_val = c_boolean_any(v15440);
              } 
            
            (*((list *) v15910))[CLcount] = v_val;} 
          } 
        (v15908->args = v15910);} 
      add_I_property(Kernel.instances,Language._Or,11,_oid_(v10264));
      Result = _oid_(v10264);
      } 
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_Quote_Optimize(Quote *v9332)
{ return (OWNER(v9332->arg));} 

void  c_code_Quote_Optimize(Quote *v9332)
{ (*Optimize.Cerror)(_string_(CSTRING("[internal] optimization of quote not implemented yet! ~S")),
    _oid_(v9332));
  } 

ClaireType * c_type_to_protect_Optimize(Compile_to_protect *v9332)
{ GC_BIND;
  { ClaireType *Result ;
    Result = OBJECT(ClaireType,(*Optimize.c_type)(v9332->arg));
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_to_protect_Optimize(Compile_to_protect *v9332)
{ return (_oid_(v9332));} 

ClaireBoolean * c_gc_ask_to_protect(Compile_to_protect *v9332)
{ return (CFALSE);} 

ClaireType * c_type_Return_Optimize(Return *v9332)
{ return (Kernel._any);} 

OID  c_code_Return_Optimize(Return *v9332)
{ GC_BIND;
  (Optimize.OPT->loop_gc = CFALSE);
  { OID Result = 0;
    { Return * v10264 = ((Return *) GC_OBJECT(Return,new_object_class(Language._Return)));
      (v10264->arg = (*Optimize.c_code)(GC_OID(v9332->arg),
        _oid_(Kernel._any)));
      add_I_property(Kernel.instances,Language._Return,11,_oid_(v10264));
      Result = _oid_(v10264);
      } 
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_Handle_Optimize(ClaireHandle *v9332)
{ GC_BIND;
  { ClaireType *Result ;
    Result = U_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(GC_OID(v9332->arg)))),GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(GC_OID(v9332->other)))));
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_Handle_Optimize(ClaireHandle *v9332,ClaireClass *v15435)
{ GC_BIND;
  { OID Result = 0;
    { ClaireHandle * v15440;
      { { ClaireHandle * v10264 = ((ClaireHandle *) GC_OBJECT(ClaireHandle,new_object_class(Language._Handle)));
          (v10264->test = _oid_(Kernel._any));
          (v10264->arg = (*Optimize.c_code)(GC_OID(v9332->arg),
            _oid_(v15435)));
          (v10264->other = (*Optimize.c_code)(GC_OID(v9332->other),
            _oid_(v15435)));
          add_I_property(Kernel.instances,Language._Handle,11,_oid_(v10264));
          v15440 = v10264;
          } 
        GC_OBJECT(ClaireHandle,v15440);} 
      if (v9332->test != _oid_(Core._contradiction))
       (Optimize.OPT->allocation = CTRUE);
      (v15440->test = v9332->test);
      Result = _oid_(v15440);
      } 
    GC_UNBIND; return (Result);} 
  } 

ClaireBoolean * c_gc_ask_Handle(ClaireHandle *v9332)
{ GC_BIND;
  { ClaireBoolean *Result ;
    Result = (((OBJECT(ClaireBoolean,(*Optimize.c_gc_ask)(v9332->arg))) == CTRUE) ? CTRUE : (((OBJECT(ClaireBoolean,(*Optimize.c_gc_ask)(v9332->other))) == CTRUE) ? CTRUE : CFALSE));
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_Cast_Optimize(Cast *v9332)
{ return (v9332->set_arg);} 

OID  c_code_Cast_Optimize(Cast *v9332)
{ GC_BIND;
  { OID Result = 0;
    { ClaireType * v15441 = GC_OBJECT(ClaireType,v9332->set_arg);
      ClaireClass * v15480 = psort_any(_oid_(v15441));
      if ((INHERIT(v15441->isa,Core._Param)) && (((CLREAD(Param,v15441,arg) == Kernel._list) || 
            (CLREAD(Param,v15441,arg) == Kernel._set)) && 
          (Kernel._set == OWNER((*(CLREAD(Param,v15441,args)))[1]))))
       { OID  v7432 = GC_OID((*(OBJECT(set,(*(CLREAD(Param,v15441,args)))[1])))[1]);
        if ((equal(_oid_(_at_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(GC_OID(v9332->arg)))),Kernel.of)),v7432) == CTRUE) || 
            (Optimize.compiler->safety > 4))
         Result = (*Optimize.c_code)(GC_OID(v9332->arg),
          _oid_(v15480));
        else { OID  v8794;
            { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
              (v10264->selector = Core.check_in);
              (v10264->args = list::alloc(3,GC_OID(v9332->arg),
                _oid_(CLREAD(Param,v15441,arg)),
                v7432));
              add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
              v8794 = _oid_(v10264);
              } 
            Result = (*Optimize.c_code)(v8794,
              _oid_(v15480));
            } 
          } 
      else if ((_inf_equal_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(GC_OID(v9332->arg)))),v15441) == CTRUE) || 
          (Optimize.compiler->safety > 1))
       Result = (*Optimize.c_code)(GC_OID(v9332->arg),
        _oid_(v15480));
      else { OID  v9755;
          { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
            (v10264->selector = Core.check_in);
            (v10264->args = list::alloc(2,GC_OID(v9332->arg),_oid_(v15441)));
            add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
            v9755 = _oid_(v10264);
            } 
          Result = (*Optimize.c_code)(v9755,
            _oid_(v15480));
          } 
        } 
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_Super_Optimize(Super *v9332)
{ GC_BIND;
  { ClaireType *Result ;
    { list * v1207;
      { { bag *v_list; OID v_val;
          OID v15440,CLcount;
          v_list = GC_OBJECT(list,v9332->args);
           v1207 = v_list->clone();
          for (CLcount= 1; CLcount <= v_list->length; CLcount++)
          { v15440 = (*(v_list))[CLcount];
            v_val = (*Optimize.c_type)(v15440);
            
            (*((list *) v1207))[CLcount] = v_val;} 
          } 
        GC_OBJECT(list,v1207);} 
      property * v15435 = v9332->selector;
      ((*(v1207))[1]=_oid_(v9332->cast_to));
      { OID  v14476;
        { if (v15435->open == 3)
           v14476 = Core.nil->value;
          else v14476 = restriction_I_class(class_I_type(v9332->cast_to),v15435->definition,v1207);
            GC_OID(v14476);} 
        Result = ((Kernel._slot == OWNER(v14476)) ?
          OBJECT(restriction,v14476)->range :
          ((Kernel._method == OWNER(v14476)) ?
            use_range_method(OBJECT(method,v14476),v1207) :
            v15435->range ) );
        } 
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_Super_Optimize(Super *v9332)
{ GC_BIND;
  { OID Result = 0;
    { property * v15435 = v9332->selector;
      list * v15428 = GC_OBJECT(list,v9332->args);
      list * v1207;
      { { bag *v_list; OID v_val;
          OID v15440,CLcount;
          v_list = GC_OBJECT(list,v9332->args);
           v1207 = v_list->clone();
          for (CLcount= 1; CLcount <= v_list->length; CLcount++)
          { v15440 = (*(v_list))[CLcount];
            v_val = (*Optimize.c_type)(v15440);
            
            (*((list *) v1207))[CLcount] = v_val;} 
          } 
        GC_OBJECT(list,v1207);} 
      OID  v14476;
      { if (v15435->open == 3)
         v14476 = Core.nil->value;
        else v14476 = restriction_I_class(class_I_type(v9332->cast_to),v15435->definition,v1207);
          GC_OID(v14476);} 
      if (Kernel._slot == OWNER(v14476))
       { Call_slot * v10264 = ((Call_slot *) GC_OBJECT(Call_slot,new_object_class(Language._Call_slot)));
        (v10264->selector = OBJECT(slot,v14476));
        (v10264->arg = (*Optimize.c_code)((*(v15428))[1],
          _oid_(psort_any(_oid_(domain_I_restriction(OBJECT(restriction,v14476)))))));
        (v10264->test = ((belong_to(OBJECT(slot,v14476)->DEFAULT,_oid_(OBJECT(restriction,v14476)->range)) != CTRUE) ? ((Optimize.compiler->safety < 5) ? CTRUE: CFALSE): CFALSE));
        add_I_property(Kernel.instances,Language._Call_slot,11,_oid_(v10264));
        Result = _oid_(v10264);
        } 
      else if (Kernel._method == OWNER(v14476))
       Result = c_code_method_method1(OBJECT(method,v14476),v15428,v1207);
      else Result = c_warn_Super(v9332,_oid_(v1207));
        } 
    GC_UNBIND; return (Result);} 
  } 

void  self_print_Call_function2(Optimize_Call_function2 *v9332)
{ print_any(_oid_(v9332->arg));
  princ_string(CSTRING("("));
  princ_bag(v9332->args);
  princ_string(CSTRING(")"));
  } 

ClaireType * c_type_Call_function2_Optimize(Optimize_Call_function2 *v9332)
{ return (Kernel._any);} 

OID  c_code_Call_function2_Optimize(Optimize_Call_function2 *v9332)
{ GC_BIND;
  { OID Result = 0;
    { Optimize_Call_function2 * v10264 = ((Optimize_Call_function2 *) GC_OBJECT(Optimize_Call_function2,new_object_class(Optimize._Call_function2)));
      (v10264->arg = v9332->arg);
      { Optimize_Call_function2 * v15932 = v10264; 
        list * v15933;
        { bag *v_list; OID v_val;
          OID v15440,CLcount;
          v_list = v9332->args;
           v15933 = v_list->clone();
          for (CLcount= 1; CLcount <= v_list->length; CLcount++)
          { v15440 = (*(v_list))[CLcount];
            v_val = (*Optimize.c_code)(v15440,
              _oid_(Kernel._any));
            
            (*((list *) v15933))[CLcount] = v_val;} 
          } 
        (v15932->args = v15933);} 
      add_I_property(Kernel.instances,Optimize._Call_function2,11,_oid_(v10264));
      Result = _oid_(v10264);
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_Assert_Optimize(Assert *v9332)
{ if (Optimize.OPT->online_ask == CTRUE) 
  { { OID Result = 0;
      Result = _oid_(v9332);
      return (Result);} 
     } 
  else{ GC_BIND;
    { OID Result = 0;
      if ((Optimize.compiler->safety == 0) || 
          (Optimize.compiler->debug_ask->length != 0))
       { OID  v12638;
        { If * v10264 = ((If *) GC_OBJECT(If,new_object_class(Language._If)));
          { If * v15935 = v10264; 
            OID  v15936;
            { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
              (v10264->selector = Core.NOT);
              (v10264->args = list::alloc(1,GC_OID((*(v9332->args))[1])));
              add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
              v15936 = _oid_(v10264);
              } 
            (v15935->test = v15936);} 
          { If * v15937 = v10264; 
            OID  v15938;
            { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
              (v10264->selector = Core.tformat);
              { Call * v15939 = v10264; 
                list * v15961;
                { OID v_bag;
                  GC_ANY(v15961= list::empty(Kernel.emptySet));
                  ((list *) v15961)->addFast(_string_(CSTRING("Assertion violation in ~A line ~A\n")));
                  ((list *) v15961)->addFast(0);
                  { { List * v10264 = ((List *) GC_OBJECT(List,new_object_class(Language._List)));
                      (v10264->args = list::alloc(2,GC_OID(_string_(v9332->external)),v9332->index));
                      add_I_property(Kernel.instances,Language._List,11,_oid_(v10264));
                      v_bag = _oid_(v10264);
                      } 
                    GC_OID(v_bag);} 
                  ((list *) v15961)->addFast(v_bag);} 
                (v15939->args = v15961);} 
              add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
              v15938 = _oid_(v10264);
              } 
            (v15937->arg = v15938);} 
          (v10264->other = Kernel.cfalse);
          add_I_property(Kernel.instances,Language._If,11,_oid_(v10264));
          v12638 = _oid_(v10264);
          } 
        Result = (*Optimize.c_code)(v12638,
          _oid_(Kernel._any));
        } 
      else Result = Kernel.cfalse;
        GC_UNBIND; return (Result);} 
    } 
  } 

OID  c_code_Trace_Optimize(Trace *v9332)
{ GC_BIND;
  { OID Result = 0;
    { list * v15417 = GC_OBJECT(list,v9332->args);
      if (Optimize.OPT->online_ask == CTRUE)
       Result = _oid_(v9332);
      else if ((v15417->length == 1) && 
          (_inf_equal_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)((*(v15417))[1]))),Kernel._integer) == CTRUE))
       { OID  v6778;
        { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
          (v10264->selector = Core.write);
          (v10264->args = list::alloc(3,_oid_(Kernel.verbose),
            _oid_(ClEnv),
            (*(v15417))[1]));
          add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
          v6778 = _oid_(v10264);
          } 
        Result = (*Optimize.c_code)(v6778);
        } 
      else { ClaireBoolean * g0172I;
        { ClaireBoolean *v_and;
          { v_and = ((v15417->length > 1) ? CTRUE : CFALSE);
            if (v_and == CFALSE) g0172I =CFALSE; 
            else { v_and = ((Kernel._string == OWNER((*(v15417))[2])) ? CTRUE : CFALSE);
              if (v_and == CFALSE) g0172I =CFALSE; 
              else { { ClaireBoolean *v_or;
                  { v_or = ((Optimize.compiler->debug_ask->length != 0) ? CTRUE : CFALSE);
                    if (v_or == CTRUE) v_and =CTRUE; 
                    else { { ClaireObject *V_CC ;
                        { ClaireHandler c_handle = ClaireHandler();
                          if ERROR_IN 
                          { V_CC = ((OPT_EVAL((*(v15417))[1]) <= ClEnv->verbose) ? CTRUE : CFALSE);
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
        
        if (g0172I == CTRUE) { Call * v1030;
            { { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                (v10264->selector = Core.tformat);
                { Call * v15964 = v10264; 
                  list * v15965;
                  { OID v_bag;
                    GC_ANY(v15965= list::empty(Kernel.emptySet));
                    ((list *) v15965)->addFast((*(v15417))[2]);
                    ((list *) v15965)->addFast((*(v15417))[1]);
                    { { List * v10264 = ((List *) GC_OBJECT(List,new_object_class(Language._List)));
                        (v10264->args = skip_list(((list *) copy_bag(v15417)),2));
                        add_I_property(Kernel.instances,Language._List,11,_oid_(v10264));
                        v_bag = _oid_(v10264);
                        } 
                      GC_OID(v_bag);} 
                    ((list *) v15965)->addFast(v_bag);} 
                  (v15964->args = v15965);} 
                add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
                v1030 = v10264;
                } 
              GC_OBJECT(Call,v1030);} 
            { OID  v10622;
              if (inherit_ask_class(OWNER((*(v15417))[1]),Kernel._integer) != CTRUE)
               { If * v10264 = ((If *) GC_OBJECT(If,new_object_class(Language._If)));
                { If * v15967 = v10264; 
                  OID  v15969;
                  { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                    (v10264->selector = Kernel._inf_equal);
                    { Call * v15970 = v10264; 
                      list * v15971;
                      { OID v_bag;
                        GC_ANY(v15971= list::empty(Kernel.emptySet));
                        ((list *) v15971)->addFast((*(v15417))[1]);
                        { { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                            (v10264->selector = Kernel.verbose);
                            (v10264->args = list::alloc(1,_oid_(ClEnv)));
                            add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
                            v_bag = _oid_(v10264);
                            } 
                          GC_OID(v_bag);} 
                        ((list *) v15971)->addFast(v_bag);} 
                      (v15970->args = v15971);} 
                    add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
                    v15969 = _oid_(v10264);
                    } 
                  (v15967->test = v15969);} 
                (v10264->arg = _oid_(v1030));
                (v10264->other = Kernel.cfalse);
                add_I_property(Kernel.instances,Language._If,11,_oid_(v10264));
                v10622 = _oid_(v10264);
                } 
              else v10622 = _oid_(v1030);
                Result = (*Optimize.c_code)(v10622,
                _oid_(Kernel._any));
              } 
            } 
          else Result = Kernel.cfalse;
        } 
      } 
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_Assert_Optimize(Assert *v9332)
{ return (Kernel._any);} 

ClaireType * c_type_Trace_Optimize(Trace *v9332)
{ return (Kernel._any);} 

ClaireType * c_type_Branch_Optimize(Branch *v9332)
{ return (Kernel._boolean);} 

OID  c_code_Branch_Optimize(Branch *v9332)
{ GC_BIND;
  { OID Result = 0;
    { OID  v2840;
      { ClaireHandle * v10264 = ((ClaireHandle *) GC_OBJECT(ClaireHandle,new_object_class(Language._Handle)));
        { ClaireHandle * v15994 = v10264; 
          OID  v15995;
          { Do * v10264 = ((Do *) GC_OBJECT(Do,new_object_class(Language._Do)));
            { Do * v15996 = v10264; 
              list * v15997;
              { OID v_bag;
                GC_ANY(v15997= list::empty(Kernel.emptySet));
                { { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                    (v10264->selector = Kernel.choice);
                    (v10264->args = list::alloc(1,_oid_(ClEnv)));
                    add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
                    v_bag = _oid_(v10264);
                    } 
                  GC_OID(v_bag);} 
                ((list *) v15997)->addFast(v_bag);
                { { If * v10264 = ((If *) GC_OBJECT(If,new_object_class(Language._If)));
                    (v10264->test = (*(v9332->args))[1]);
                    (v10264->arg = Kernel.ctrue);
                    { If * v15998 = v10264; 
                      OID  v15999;
                      { Do * v10264 = ((Do *) GC_OBJECT(Do,new_object_class(Language._Do)));
                        { Do * v16000 = v10264; 
                          list * v16001;
                          { OID v_bag;
                            GC_ANY(v16001= list::empty(Kernel.emptySet));
                            { { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                                (v10264->selector = Kernel.backtrack);
                                (v10264->args = list::alloc(1,_oid_(ClEnv)));
                                add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
                                v_bag = _oid_(v10264);
                                } 
                              GC_OID(v_bag);} 
                            ((list *) v16001)->addFast(v_bag);
                            ((list *) v16001)->addFast(Kernel.cfalse);} 
                          (v16000->args = v16001);} 
                        add_I_property(Kernel.instances,Language._Do,11,_oid_(v10264));
                        v15999 = _oid_(v10264);
                        } 
                      (v15998->other = v15999);} 
                    add_I_property(Kernel.instances,Language._If,11,_oid_(v10264));
                    v_bag = _oid_(v10264);
                    } 
                  GC_OID(v_bag);} 
                ((list *) v15997)->addFast(v_bag);} 
              (v15996->args = v15997);} 
            add_I_property(Kernel.instances,Language._Do,11,_oid_(v10264));
            v15995 = _oid_(v10264);
            } 
          (v15994->arg = v15995);} 
        (v10264->test = _oid_(Core._contradiction));
        { ClaireHandle * v16002 = v10264; 
          OID  v16023;
          { Do * v10264 = ((Do *) GC_OBJECT(Do,new_object_class(Language._Do)));
            { Do * v16024 = v10264; 
              list * v16025;
              { OID v_bag;
                GC_ANY(v16025= list::empty(Kernel.emptySet));
                { { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                    (v10264->selector = Kernel.backtrack);
                    (v10264->args = list::alloc(1,_oid_(ClEnv)));
                    add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
                    v_bag = _oid_(v10264);
                    } 
                  GC_OID(v_bag);} 
                ((list *) v16025)->addFast(v_bag);
                ((list *) v16025)->addFast(Kernel.cfalse);} 
              (v16024->args = v16025);} 
            add_I_property(Kernel.instances,Language._Do,11,_oid_(v10264));
            v16023 = _oid_(v10264);
            } 
          (v16002->other = v16023);} 
        add_I_property(Kernel.instances,Language._Handle,11,_oid_(v10264));
        v2840 = _oid_(v10264);
        } 
      Result = (*Optimize.c_code)(v2840,
        _oid_(Kernel._any));
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_Macro_Optimize(Macro *v9332,ClaireClass *v15435)
{ GC_BIND;
  { OID Result = 0;
    Result = (*Optimize.c_code)(GC_OID((*Language.macroexpand)(_oid_(v9332))),
      _oid_(v15435));
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_Macro_Optimize(Macro *v9332)
{ GC_BIND;
  { ClaireType *Result ;
    Result = OBJECT(ClaireType,(*Optimize.c_type)(GC_OID((*Language.macroexpand)(_oid_(v9332)))));
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_Printf_Optimize(Printf *v9332)
{ return (Kernel._any);} 

OID  c_code_Printf_Optimize(Printf *v9332)
{ GC_RESERVE(13);  // v3.0.55 optim !
  { OID Result = 0;
    { list * v15428 = GC_OBJECT(list,v9332->args);
      if (equal(_oid_(Kernel._string),_oid_(OWNER((*(v15428))[1]))) != CTRUE)
       Result = (*Optimize.Cerror)(_string_(CSTRING("[209] the first argument in ~S must be a string")),
        _oid_(v9332));
      else { char * v15435 = string_v((*(v15428))[1]);
          Cint  v15425 = 1;
          Cint  v15431 = get_string(v15435,_char_('~'));
          list * v15434 = list::empty(Kernel._any);
          { OID gc_local;
            while ((equal(v15431,0) != CTRUE))
            { GC_LOOP;
              { ClaireChar * v15429 = _char_(v15435[(v15431+1) - 1]);
                if (v15425 < v15428->length)
                 ++v15425;
                else (*Optimize.Cerror)(_string_(CSTRING("[210] not enough arguments in ~S")),
                    _oid_(v9332));
                  if (v15431 > 1)
                 { { OID  v2746;
                    { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                      (v10264->selector = Kernel.princ);
                      (v10264->args = list::alloc(1,GC_OID(_string_(substring_string(v15435,1,(v15431-1))))));
                      add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
                      v2746 = _oid_(v10264);
                      } 
                    v15434 = v15434->addFast(v2746);
                    } 
                   GC__ANY(v15434, 7);} 
                { { OID  v3707;
                    if ('A' == ((char) v15429->ascii))
                     { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                      (v10264->selector = Kernel.princ);
                      (v10264->args = list::alloc(1,(*(v15428))[v15425]));
                      add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
                      v3707 = _oid_(v10264);
                      } 
                    else if ('S' == ((char) v15429->ascii))
                     { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                      (v10264->selector = Kernel.print);
                      (v10264->args = list::alloc(1,(*(v15428))[v15425]));
                      add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
                      v3707 = _oid_(v10264);
                      } 
                    else if ('F' == ((char) v15429->ascii))
                     { ClaireBoolean * v3293 = CFALSE;
                      Cint  v15426 = (integer_I_char(_char_(v15435[(v15431+2) - 1]))-48);
                      if ('%' == v15435[(v15431+2) - 1])
                       { v3293= CTRUE;
                        v15426= 1;
                        } 
                      else if ((v15426 < 0) || 
                          (v15426 > 9))
                       close_exception(((general_error *) (*Core._general_error)(_string_(CSTRING("[189] F requires a single digit integer in ~S")),
                        _oid_(list::alloc(1,_oid_(v9332))))));
                      if ((v3293 != CTRUE) && 
                          ('%' == v15435[(v15431+3) - 1]))
                       { v3293= CTRUE;
                        ++v15431;
                        } 
                      ++v15431;
                      { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                        (v10264->selector = Core.printFDigit);
                        { Call * v16028 = v10264; 
                          list * v16029;
                          { OID v_bag;
                            GC_ANY(v16029= list::empty(Kernel.emptySet));
                            if (v3293 == CTRUE)
                             { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                              (v10264->selector = Kernel._star);
                              (v10264->args = list::alloc(2,(*(v15428))[v15425],GC_OID(_float_(100.0))));
                              add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
                              v_bag = _oid_(v10264);
                              } 
                            else v_bag = (*(v15428))[v15425];
                              ((list *) v16029)->addFast(v_bag);
                            ((list *) v16029)->addFast(v15426);} 
                          (v16028->args = v16029);} 
                        add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
                        v3707 = _oid_(v10264);
                        } 
                      } 
                    else if ('I' == ((char) v15429->ascii))
                     v3707 = (*(v15428))[v15425];
                    else v3707 = Kernel.cfalse;
                      v15434 = v15434->addFast(v3707);
                    } 
                   GC__ANY(v15434, 7);} 
                GC__STRING(v15435 = substring_string(v15435,(v15431+2),1000), 4);
                v15431= get_string(v15435,_char_('~'));
                } 
              GC_UNLOOP;} 
            } 
          if (boolean_I_any(_string_(v15435)) == CTRUE)
           { OID  v6590;
            { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
              (v10264->selector = Kernel.princ);
              (v10264->args = list::alloc(1,_string_(v15435)));
              add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
              v6590 = _oid_(v10264);
              } 
            v15434 = v15434->addFast(v6590);
            } 
          { OID  v7551;
            { Do * v10264 = ((Do *) GC_OBJECT(Do,new_object_class(Language._Do)));
              (v10264->args = v15434);
              add_I_property(Kernel.instances,Language._Do,11,_oid_(v10264));
              v7551 = _oid_(v10264);
              } 
            Result = (*Optimize.c_code)(v7551,
              _oid_(Kernel._any));
            } 
          } 
        } 
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_Error_Optimize(Error *v9332)
{ return (Kernel.emptySet);} 

OID  c_code_Error_Optimize(Error *v9332)
{ GC_BIND;
  { OID Result = 0;
    { ClaireBoolean * v15440 = Optimize.OPT->allocation;
      OID  v15441;
      { { OID  v8512;
          { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
            (v10264->selector = Kernel.close);
            { Call * v321 = v10264; 
              list * v322;
              { OID v_bag;
                GC_ANY(v322= list::empty(Kernel.emptySet));
                { { Cast * v10264 = ((Cast *) GC_OBJECT(Cast,new_object_class(Language._Cast)));
                    { Cast * v323 = v10264; 
                      OID  v324;
                      { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                        (v10264->selector = Optimize.anyObject_I);
                        { Call * v325 = v10264; 
                          list * v326;
                          { OID v_bag;
                            GC_ANY(v326= list::empty(Kernel.emptySet));
                            ((list *) v326)->addFast(_oid_(Core._general_error));
                            ((list *) v326)->addFast(GC_OID((*Optimize.c_code)(GC_OID(car_list(v9332->args)),
                              _oid_(Kernel._any))));
                            { { OID  v5672;
                                if (v9332->args->length != 1)
                                 { List * v10264 = ((List *) GC_OBJECT(List,new_object_class(Language._List)));
                                  (v10264->args = cdr_list(GC_OBJECT(list,v9332->args)));
                                  add_I_property(Kernel.instances,Language._List,11,_oid_(v10264));
                                  v5672 = _oid_(v10264);
                                  } 
                                else v5672 = Core.nil->value;
                                  v_bag = (*Optimize.c_code)(v5672,
                                  _oid_(Kernel._any));
                                } 
                              GC_OID(v_bag);} 
                            ((list *) v326)->addFast(v_bag);} 
                          (v325->args = v326);} 
                        add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
                        v324 = _oid_(v10264);
                        } 
                      (v323->arg = v324);} 
                    (v10264->set_arg = Kernel._exception);
                    add_I_property(Kernel.instances,Language._Cast,11,_oid_(v10264));
                    v_bag = _oid_(v10264);
                    } 
                  GC_OID(v_bag);} 
                ((list *) v322)->addFast(v_bag);} 
              (v321->args = v322);} 
            add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
            v8512 = _oid_(v10264);
            } 
          v15441 = (*Optimize.c_code)(v8512,
            _oid_(Kernel._void));
          } 
        GC_OID(v15441);} 
      (Optimize.OPT->allocation = v15440);
      Result = v15441;
      } 
    GC_UNBIND; return (Result);} 
  } 

ClaireType * extendedTest_ask_If(If *v9332)
{ GC_BIND;
  { ClaireType *Result ;
    { OID  v1047 = v9332->test;
      if (INHERIT(OWNER(v1047),Language._Call))
       { if ((INHERIT(OWNER((*(OBJECT(Call,v1047)->args))[1]),Language._Variable)) && 
            (OBJECT(Call,v1047)->selector == Core.known_ask))
         Result = OBJECT(ClaireType,(*Kernel.range)((*(OBJECT(Call,v1047)->args))[1]));
        else Result = Kernel._any;
          } 
      else Result = Kernel._any;
        } 
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_If_Optimize(If *v9332)
{ GC_BIND;
  { ClaireType *Result ;
    { ClaireType * v1045 = GC_OBJECT(ClaireType,extendedTest_ask_If(v9332));
      if (extended_ask_type(v1045) == CTRUE)
       range_sets_any(GC_OID((*(OBJECT(bag,(*Core.args)(GC_OID(v9332->test)))))[1]),GC_OBJECT(ClaireType,sort_abstract_I_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Core.t1)(_oid_(v1045)))))));
      { ClaireType * v13125 = GC_OBJECT(ClaireType,U_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(GC_OID(v9332->arg)))),GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(GC_OID(v9332->other))))));
        if (extended_ask_type(v1045) == CTRUE)
         put_property2(Kernel.range,GC_OBJECT(ClaireObject,OBJECT(ClaireObject,(*(OBJECT(bag,(*Core.args)(GC_OID(v9332->test)))))[1])),_oid_(v1045));
        Result = v13125;
        } 
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_If_Optimize(If *v9332,ClaireClass *v15435)
{ GC_BIND;
  { OID Result = 0;
    { ClaireType * v1045 = GC_OBJECT(ClaireType,extendedTest_ask_If(v9332));
      if (extended_ask_type(v1045) == CTRUE)
       range_sets_any(GC_OID((*(OBJECT(bag,(*Core.args)(GC_OID(v9332->test)))))[1]),GC_OBJECT(ClaireType,sort_abstract_I_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Core.t1)(_oid_(v1045)))))));
      if ((_inf_equal_type(GC_OBJECT(ClaireType,ptype_type(OBJECT(ClaireType,(*Optimize.c_type)(GC_OID(v9332->test))))),Kernel._boolean) != CTRUE) && 
          (Optimize.PENIBLE->value == Kernel.ctrue))
       { warn_void();
        tformat_string(CSTRING("CLAIRE 3.3 SYNTAX - Test in ~S should be a boolean [260]\n"),2,list::alloc(1,_oid_(v9332)));
        } 
      { If * v13125;
        { { If * v10264 = ((If *) GC_OBJECT(If,new_object_class(Language._If)));
            (v10264->test = c_boolean_any(GC_OID(v9332->test)));
            (v10264->arg = (*Optimize.c_code)(GC_OID(v9332->arg),
              _oid_(v15435)));
            (v10264->other = (*Optimize.c_code)(GC_OID(v9332->other),
              _oid_(v15435)));
            add_I_property(Kernel.instances,Language._If,11,_oid_(v10264));
            v13125 = v10264;
            } 
          GC_OBJECT(If,v13125);} 
        if (extended_ask_type(v1045) == CTRUE)
         put_property2(Kernel.range,GC_OBJECT(ClaireObject,OBJECT(ClaireObject,(*(OBJECT(bag,(*Core.args)(GC_OID(v9332->test)))))[1])),_oid_(v1045));
        Result = _oid_(v13125);
        } 
      } 
    GC_UNBIND; return (Result);} 
  } 

ClaireBoolean * c_gc_ask_If(If *v9332)
{ GC_BIND;
  { ClaireBoolean *Result ;
    Result = (((OBJECT(ClaireBoolean,(*Optimize.c_gc_ask)(v9332->arg))) == CTRUE) ? CTRUE : (((OBJECT(ClaireBoolean,(*Optimize.c_gc_ask)(v9332->other))) == CTRUE) ? CTRUE : CFALSE));
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_Case_Optimize(Case *v9332)
{ GC_RESERVE(6);  // v3.0.55 optim !
  { ClaireType *Result ;
    { OID  v11786 = GC_OID(v9332->var);
      OID  v1207;
      { if (INHERIT(OWNER(v11786),Language._Variable))
         v1207 = get_property(Kernel.range,OBJECT(ClaireObject,v11786));
        else v1207 = _oid_(Kernel._any);
          GC_OID(v1207);} 
      list * v15428 = GC_OBJECT(list,((list *) copy_bag(v9332->args)));
      ClaireType * v5765 = Kernel.emptySet;
      ClaireType * v7432 = Kernel.emptySet;
      { OID gc_local;
        while ((v15428->length > 0))
        { GC_LOOP;
          if (INHERIT(OWNER((*(v15428))[1]),Kernel._type))
           { GC__ANY(v7432 = U_type(v7432,OBJECT(ClaireType,(*(v15428))[1])), 6);
            if (osort_any(v1207) == osort_any((*(v15428))[1]))
             range_sets_any(v11786,OBJECT(ClaireType,(*(v15428))[1]));
            else if (osort_any(v1207) == Kernel._any)
             range_sets_any(v11786,GC_OBJECT(ClaireType,sort_abstract_I_type(OBJECT(ClaireType,(*(v15428))[1]))));
            } 
          else (*Optimize.Cerror)(_string_(CSTRING("[208] wrong type declaration for case: ~S in ~S")),
              GC_OID(car_list(v15428)),
              _oid_(v9332));
            GC__ANY(v5765 = U_type(v5765,GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)((*(v15428))[2])))), 5);
          if (INHERIT(OWNER(v11786),Language._Variable))
           store_object(OBJECT(ClaireObject,v11786),
            3,
            Kernel._object,
            v1207,
            CFALSE);
          GC__ANY(v15428 = skip_list(v15428,2), 4);
          GC_UNLOOP;} 
        } 
      if (_inf_equal_type(OBJECT(ClaireType,v1207),v7432) == CTRUE)
       Result = v5765;
      else Result = ((_inf_equal_type(v5765,Kernel._boolean) == CTRUE) ?
        Kernel._boolean :
        Kernel._any );
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_Case_Optimize(Case *v9332,ClaireClass *v15435)
{ GC_RESERVE(13);  // v3.0.55 optim !
  { OID Result = 0;
    { OID  v11786 = GC_OID(v9332->var);
      OID  v1207;
      { if (INHERIT(OWNER(v11786),Language._Variable))
         v1207 = get_property(Kernel.range,OBJECT(ClaireObject,v11786));
        else v1207 = _oid_(Kernel._any);
          GC_OID(v1207);} 
      list * v15428 = GC_OBJECT(list,((list *) copy_bag(v9332->args)));
      OID  v7432 = _oid_(Kernel.emptySet);
      OID  v16004;
      { { OID  v6632;
          { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
            (v10264->selector = Kernel._Z);
            (v10264->args = list::alloc(2,v11786,(*(v15428))[1]));
            add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
            v6632 = _oid_(v10264);
            } 
          v16004 = c_boolean_any(v6632);
          } 
        GC_OID(v16004);} 
      range_sets_any(v11786,OBJECT(ClaireType,(*(v15428))[1]));
      { If * v7797;
        { { If * v10264 = ((If *) GC_OBJECT(If,new_object_class(Language._If)));
            (v10264->test = v16004);
            (v10264->arg = (*Optimize.c_code)((*(v15428))[2],
              _oid_(v15435)));
            (v10264->other = (*Optimize.c_code)(Kernel.cfalse,
              _oid_(v15435)));
            add_I_property(Kernel.instances,Language._If,11,_oid_(v10264));
            v7797 = v10264;
            } 
          GC_OBJECT(If,v7797);} 
        If * v14357 = v7797;
        if (INHERIT(OWNER(v11786),Language._Variable))
         store_object(OBJECT(ClaireObject,v11786),
          3,
          Kernel._object,
          v1207,
          CFALSE);
        v15428= GC_OBJECT(list,skip_list(v15428,2));
        { OID gc_local;
          while ((v15428->length > 0))
          { GC_LOOP;
            GC__OID(v7432 = _oid_(U_type(OBJECT(ClaireType,v7432),OBJECT(ClaireType,(*(v15428))[1]))), 7);
            if (_inf_equal_type(OBJECT(ClaireType,v1207),OBJECT(ClaireType,v7432)) == CTRUE)
             { if (osort_any(v1207) == osort_any((*(v15428))[1]))
               range_sets_any(v11786,OBJECT(ClaireType,(*(v15428))[1]));
              else if (osort_any(v1207) == Kernel._any)
               range_sets_any(v11786,GC_OBJECT(ClaireType,sort_abstract_I_type(OBJECT(ClaireType,(*(v15428))[1]))));
              (v14357->other = (*Optimize.c_code)((*(v15428))[2],
                _oid_(v15435)));
              if (INHERIT(OWNER(v11786),Language._Variable))
               store_object(OBJECT(ClaireObject,v11786),
                3,
                Kernel._object,
                v1207,
                CFALSE);
              { ;break;} 
              } 
            else { OID  v11085;
                { { OID  v7593;
                    { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                      (v10264->selector = Kernel._Z);
                      (v10264->args = list::alloc(2,v11786,(*(v15428))[1]));
                      add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
                      v7593 = _oid_(v10264);
                      } 
                    v11085 = c_boolean_any(v7593);
                    } 
                  GC_OID(v11085);} 
                range_sets_any(v11786,OBJECT(ClaireType,(*(v15428))[1]));
                { If * v330 = v14357; 
                  OID  v352;
                  { If * v10264 = ((If *) GC_OBJECT(If,new_object_class(Language._If)));
                    (v10264->test = v11085);
                    (v10264->arg = (*Optimize.c_code)((*(v15428))[2],
                      _oid_(v15435)));
                    (v10264->other = (*Optimize.c_code)(Kernel.cfalse,
                      _oid_(v15435)));
                    add_I_property(Kernel.instances,Language._If,11,_oid_(v10264));
                    v352 = _oid_(v10264);
                    } 
                  (v330->other = v352);} 
                GC__ANY(v14357 = OBJECT(If,v14357->other), 10);
                } 
              if (INHERIT(OWNER(v11786),Language._Variable))
             store_object(OBJECT(ClaireObject,v11786),
              3,
              Kernel._object,
              v1207,
              CFALSE);
            GC__ANY(v15428 = skip_list(v15428,2), 6);
            GC_UNLOOP;} 
          } 
        if ((INHERIT(OWNER(v11786),Language._Definition)) && (INHERIT(OBJECT(Definition,v11786)->arg->isa,Kernel._exception)))
         Result = v11786;
        else Result = _oid_(v7797);
          } 
      } 
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_Do_Optimize(Do *v9332)
{ GC_BIND;
  { ClaireType *Result ;
    Result = OBJECT(ClaireType,(*Optimize.c_type)(GC_OID(last_list(v9332->args))));
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_Do_Optimize(Do *v9332,ClaireClass *v15435)
{ GC_BIND;
  { OID Result = 0;
    { Do * v10264 = ((Do *) GC_OBJECT(Do,new_object_class(Language._Do)));
      { Do * v353 = v10264; 
        list * v354;
        { Cint  v15429 = v9332->args->length;
          Cint  v15431 = 0;
          { bag *v_list; OID v_val;
            OID v15440,CLcount;
            v_list = GC_OBJECT(list,v9332->args);
             v354 = v_list->clone();
            for (CLcount= 1; CLcount <= v_list->length; CLcount++)
            { v15440 = (*(v_list))[CLcount];
              { ++v15431;
                { OID  v16195;
                  if (v15431 == v15429)
                   v16195 = _oid_(v15435);
                  else v16195 = _oid_(Kernel._void);
                    v_val = (*Optimize.c_code)(v15440,
                    v16195);
                  } 
                } 
              
              (*((list *) v354))[CLcount] = v_val;} 
            } 
          } 
        (v353->args = v354);} 
      add_I_property(Kernel.instances,Language._Do,11,_oid_(v10264));
      Result = _oid_(v10264);
      } 
    GC_UNBIND; return (Result);} 
  } 

ClaireBoolean * c_gc_ask_Do(Do *v9332)
{ GC_BIND;
  { ClaireBoolean *Result ;
    Result = OBJECT(ClaireBoolean,(*Optimize.c_gc_ask)(GC_OID(last_list(v9332->args))));
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_Let_Optimize(Let *v9332)
{ GC_BIND;
  range_infers_Variable(GC_OBJECT(Variable,v9332->var),GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(GC_OID(v9332->value)))));
  { ClaireType *Result ;
    Result = OBJECT(ClaireType,(*Optimize.c_type)(GC_OID(v9332->arg)));
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_Let_Optimize(Let *v9332,ClaireClass *v15435)
{ GC_RESERVE(1);  // HOHO v3.0.55 optim !
  { OID Result = 0;
    { OID  v1049 = GC_OID(v9332->value);
      ClaireType * v1207 = GC_OBJECT(ClaireType,ptype_type(OBJECT(ClaireType,(*Optimize.c_type)(v1049))));
      range_infers_Variable(v9332->var,v1207);
      if (_inf_equal_type(v1207,GC_OBJECT(ClaireType,v9332->var->range)) != CTRUE)
       v1049= GC_OID(c_warn_Variable(GC_OBJECT(Variable,v9332->var),v1049,v1207));
      { Let * v15440;
        { { Let * v10264 = ((Let *) GC_OBJECT(Let,new_object_class(Language._Let)));
            (v10264->var = v9332->var);
            (v10264->value = c_gc_I_any2(GC_OID(c_strict_code_any(v1049,psort_any(_oid_(v9332->var->range)))),v1207));
            (v10264->arg = (*Optimize.c_code)(GC_OID(v9332->arg),
              _oid_(v15435)));
            add_I_property(Kernel.instances,Language._Let,11,_oid_(v10264));
            v15440 = v10264;
            } 
          GC_OBJECT(Let,v15440);} 
        (v15440->isa = v9332->isa);
        if ((INHERIT(v15440->isa,Language._Let_star)) && 
            ((INHERIT(v1207->isa,Kernel._tuple)) && 
              (BCONTAIN(c_status_any(GC_OID(v9332->value),Kernel.nil),1))))
         { Cint  v15425 = 1;
          OID  v15442 = GC_OID(v15440->arg);
          { OID gc_local;
            while (((INHERIT(OWNER(v15442),Language._Let)) && 
                (v15425 <= ((bag *) v1207)->length)))
            { GC_LOOP;
              if ((((OBJECT(ClaireBoolean,(*Optimize.gcsafe_ask)((*(((bag *) v1207)))[v15425]))) == CTRUE) ? CTRUE : ((INHERIT(owner_any((*Kernel.value)(v15442)),Optimize._to_protect)) ? CTRUE : CFALSE)) != CTRUE)
               { (Optimize.OPT->protection = CTRUE);
                { OID  v773;
                  { Compile_to_protect * v10264 = ((Compile_to_protect *) GC_OBJECT(Compile_to_protect,new_object_class(Optimize._to_protect)));
                    (v10264->arg = (*Kernel.value)(v15442));
                    add_I_property(Kernel.instances,Optimize._to_protect,11,_oid_(v10264));
                    v773 = _oid_(v10264);
                    } 
                  write_property(Kernel.value,OBJECT(ClaireObject,v15442),v773);
                  } 
                } 
              ++v15425;
              GC__OID(v15442 = (*Kernel.arg)(v15442), 8);
              GC_UNLOOP;} 
            } 
          } 
        Result = _oid_(v15440);
        } 
      } 
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_When_Optimize(When *v9332)
{ GC_BIND;
  { ClaireType *Result ;
    { OID  v1049 = GC_OID(v9332->value);
      Variable * v15438 = GC_OBJECT(Variable,v9332->var);
      OID  v15420 = GC_OID(daccess_any(v1049,CTRUE));
      OID  v1207;
      { if (v15420 != CNULL)
         v1207 = (*Optimize.c_type)(v15420);
        else v1207 = (*Optimize.c_type)(v1049);
          GC_OID(v1207);} 
      if (extended_ask_type(OBJECT(ClaireType,v1207)) == CTRUE)
       v1207= GC_OID((*Core.t1)(v1207));
      range_infers_Variable(v15438,OBJECT(ClaireType,v1207));
      Result = U_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(GC_OID(v9332->arg)))),GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(GC_OID(v9332->other)))));
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_When_Optimize(When *v9332,ClaireClass *v15435)
{ GC_BIND;
  { OID Result = 0;
    { OID  v1049 = GC_OID(v9332->value);
      Variable * v15438 = GC_OBJECT(Variable,v9332->var);
      OID  v15420 = GC_OID(daccess_any(v1049,CTRUE));
      Variable * v3492 = GC_OBJECT(Variable,Variable_I_symbol(append_symbol(v9332->var->pname,_string_(CSTRING("test"))),v9332->var->index,Kernel._any));
      OID  v1207;
      { if (v15420 != CNULL)
         v1207 = (*Optimize.c_type)(v15420);
        else v1207 = (*Optimize.c_type)(v1049);
          GC_OID(v1207);} 
      if (extended_ask_type(OBJECT(ClaireType,v1207)) == CTRUE)
       v1207= GC_OID((*Core.t1)(v1207));
      range_infers_Variable(v15438,OBJECT(ClaireType,v1207));
      if ((v15420 != CNULL) && 
          (extended_ask_type(OBJECT(ClaireType,(*Kernel.range)(GC_OID((*Kernel.selector)(v15420))))) != CTRUE))
       { Let * v10264 = ((Let *) GC_OBJECT(Let,new_object_class(Language._Let)));
        (v10264->var = v15438);
        (v10264->value = c_gc_I_any2(v15420,OBJECT(ClaireType,v1207)));
        { Let * v357 = v10264; 
          OID  v358;
          { If * v10264 = ((If *) GC_OBJECT(If,new_object_class(Language._If)));
            { If * v359 = v10264; 
              OID  v360;
              { Call_method2 * v10264 = ((Call_method2 *) GC_OBJECT(Call_method2,new_object_class(Language._Call_method2)));
                (v10264->arg = ((method *) _at_property1(Core.identical_ask,Kernel._any)));
                (v10264->args = list::alloc(2,_oid_(v15438),GC_OID((*Optimize.c_code)(CNULL,
                  GC_OID((*Optimize.c_sort)(_oid_(v15438)))))));
                add_I_property(Kernel.instances,Language._Call_method2,11,_oid_(v10264));
                v360 = _oid_(v10264);
                } 
              (v359->test = v360);} 
            (v10264->arg = (*Optimize.c_code)(GC_OID(v9332->other),
              _oid_(v15435)));
            (v10264->other = (*Optimize.c_code)(GC_OID(v9332->arg),
              _oid_(v15435)));
            add_I_property(Kernel.instances,Language._If,11,_oid_(v10264));
            v358 = _oid_(v10264);
            } 
          (v357->arg = v358);} 
        add_I_property(Kernel.instances,Language._Let,11,_oid_(v10264));
        Result = _oid_(v10264);
        } 
      else if (((*Optimize.c_sort)(_oid_(v15438)) == _oid_(Kernel._any)) && 
          ((_inf_equal_type(OBJECT(ClaireType,v1207),GC_OBJECT(ClaireType,v15438->range)) == CTRUE) && 
            (3 <= Optimize.compiler->safety)))
       { OID  v5577;
        { Let * v10264 = ((Let *) GC_OBJECT(Let,new_object_class(Language._Let)));
          (v10264->var = v15438);
          (v10264->value = v1049);
          { Let * v383 = v10264; 
            OID  v384;
            { If * v10264 = ((If *) GC_OBJECT(If,new_object_class(Language._If)));
              { If * v385 = v10264; 
                OID  v386;
                { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                  (v10264->selector = Core._I_equal);
                  (v10264->args = list::alloc(2,_oid_(v15438),CNULL));
                  add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
                  v386 = _oid_(v10264);
                  } 
                (v385->test = v386);} 
              (v10264->arg = v9332->arg);
              (v10264->other = v9332->other);
              add_I_property(Kernel.instances,Language._If,11,_oid_(v10264));
              v384 = _oid_(v10264);
              } 
            (v383->arg = v384);} 
          add_I_property(Kernel.instances,Language._Let,11,_oid_(v10264));
          v5577 = _oid_(v10264);
          } 
        Result = (*Optimize.c_code)(v5577,
          _oid_(v15435));
        } 
      else { OID  v14179;
          { Let * v10264 = ((Let *) GC_OBJECT(Let,new_object_class(Language._Let)));
            (v10264->var = v3492);
            (v10264->value = v1049);
            { Let * v388 = v10264; 
              OID  v389;
              { If * v10264 = ((If *) GC_OBJECT(If,new_object_class(Language._If)));
                { If * v390 = v10264; 
                  OID  v391;
                  { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                    (v10264->selector = Core._I_equal);
                    (v10264->args = list::alloc(2,_oid_(v3492),CNULL));
                    add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
                    v391 = _oid_(v10264);
                    } 
                  (v390->test = v391);} 
                { If * v392 = v10264; 
                  OID  v414;
                  { Let * v10264 = ((Let *) GC_OBJECT(Let,new_object_class(Language._Let)));
                    (v10264->var = v15438);
                    { Let * v415 = v10264; 
                      OID  v416;
                      { Cast * v10264 = ((Cast *) GC_OBJECT(Cast,new_object_class(Language._Cast)));
                        (v10264->arg = _oid_(v3492));
                        (v10264->set_arg = OBJECT(ClaireType,v1207));
                        add_I_property(Kernel.instances,Language._Cast,11,_oid_(v10264));
                        v416 = _oid_(v10264);
                        } 
                      (v415->value = v416);} 
                    (v10264->arg = v9332->arg);
                    add_I_property(Kernel.instances,Language._Let,11,_oid_(v10264));
                    v414 = _oid_(v10264);
                    } 
                  (v392->arg = v414);} 
                (v10264->other = (*Optimize.c_code)(GC_OID(v9332->other),
                  _oid_(v15435)));
                add_I_property(Kernel.instances,Language._If,11,_oid_(v10264));
                v389 = _oid_(v10264);
                } 
              (v388->arg = v389);} 
            add_I_property(Kernel.instances,Language._Let,11,_oid_(v10264));
            v14179 = _oid_(v10264);
            } 
          Result = (*Optimize.c_code)(v14179,
            _oid_(v15435));
          } 
        } 
    GC_UNBIND; return (Result);} 
  } 

ClaireBoolean * c_gc_ask_Let(Let *v9332)
{ GC_BIND;
  { ClaireBoolean *Result ;
    Result = OBJECT(ClaireBoolean,(*Optimize.c_gc_ask)(v9332->arg));
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_For_Optimize(For *v9332)
{ GC_BIND;
  { ClaireType *Result ;
    Result = infers_from_type2(GC_OBJECT(ClaireType,return_type_any(GC_OID(v9332->arg))),_oid_(v9332));
    GC_UNBIND; return (Result);} 
  } 

ClaireType * infers_from_type2(ClaireType *v15436,OID v9332)
{ if (equal(_oid_(v15436),_oid_(Kernel.emptySet)) == CTRUE) 
  { { ClaireType *Result ;
      Result = sort_abstract_I_type(Kernel._boolean);
      return (Result);} 
     } 
  else{ GC_BIND;
    { ClaireType *Result ;
      if (Optimize.compiler->safety > 3)
       { tformat_string(CSTRING("... c_type(~S) -> ~S - ~S \n"),2,list::alloc(3,v9332,
          _oid_(v15436),
          GC_OID(_oid_(sort_abstract_I_type(v15436)))));
        Result = sort_abstract_I_type(v15436);
        } 
      else Result = Kernel._any;
        GC_UNBIND; return (Result);} 
    } 
  } 

OID  c_code_For_Optimize(For *v9332,ClaireClass *v15435)
{ GC_BIND;
  { OID Result = 0;
    { OID  v3469 = GC_OID(v9332->set_arg);
      ClaireBoolean * v15418 = Optimize.OPT->protection;
      Cint  v3309 = Optimize.compiler->safety;
      Variable * v10009 = GC_OBJECT(Variable,v9332->var);
      Variable * v15438;
      { { Variable * v10264 = ((Variable *) GC_OBJECT(Variable,new_object_class(Language._Variable)));
          (v10264->pname = v10009->pname);
          (v10264->range = v10009->range);
          (v10264->index = v10009->index);
          add_I_property(Kernel.instances,Language._Variable,11,_oid_(v10264));
          v15438 = v10264;
          } 
        GC_OBJECT(Variable,v15438);} 
      OID  v4176 = GC_OID(substitution_any(v9332->arg,v10009,_oid_(v15438)));
      OID  v8699 = GC_OID(c_inline_arg_ask_any(v3469));
      (Optimize.OPT->protection = CFALSE);
      if (INHERIT(OWNER(v3469),Core._global_variable))
       { if (boolean_I_any(_oid_(OBJECT(global_variable,v3469)->range)) != CTRUE)
         { (v9332->set_arg = OBJECT(global_variable,v3469)->value);
          v3469= GC_OID(OBJECT(global_variable,v3469)->value);
          } 
        } 
      else if (INHERIT(OWNER(v3469),Language._Select))
       { ClaireType * v1047 = GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(v3469)));
        if ((_inf_equal_type(v1047,Kernel._bag) != CTRUE) || 
            (_inf_equal_type(v1047,Kernel._set) == CTRUE))
         { v9332= GC_OBJECT(For,((For *) copy_object(v9332)));
          (v9332->isa = Language._Select);
          } 
        } 
      else if (INHERIT(OWNER(v3469),Kernel._class))
       { if ((OBJECT(ClaireClass,v3469)->open <= 1) && 
            (boolean_I_any(_oid_(OBJECT(ClaireClass,v3469)->subclass)) != CTRUE))
         { Iteration * v417 = v9332; 
          OID  v418;
          { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
            (v10264->selector = Kernel.instances);
            (v10264->args = list::alloc(1,v3469));
            add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
            v418 = _oid_(v10264);
            } 
          (v417->set_arg = v418);} 
        } 
      { OID  v1047 = GC_OID((*Optimize.c_type)(GC_OID(v9332->set_arg)));
        ClaireType * v16123 = GC_OBJECT(ClaireType,pmember_type(OBJECT(ClaireType,v1047)));
        ClaireType * v16124;
        { { ClaireType * v12163;
            { { OID v7538;{ OID  v13124;
                  { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                    (v10264->selector = Kernel.set_I);
                    (v10264->args = list::alloc(1,v3469));
                    add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
                    v13124 = _oid_(v10264);
                    } 
                  v7538 = (*Optimize.c_type)(v13124);
                  } 
                
                v12163=OBJECT(ClaireType,v7538);} 
              GC_OBJECT(ClaireType,v12163);} 
            v16124 = pmember_type(v12163);
            } 
          GC_OBJECT(ClaireType,v16124);} 
        if (_inf_equal_type(v16124,v16123) == CTRUE)
         v16123= v16124;
        range_infers_for_Variable(v15438,v16123,OBJECT(ClaireType,v1047));
        (Optimize.compiler->safety = 1);
        v16123= GC_OBJECT(ClaireType,v15438->range);
        (v15438->range = ptype_type(v16123));
        { OID  v15429 = GC_OID(Iterate_I_Iteration(v9332));
          if (equal(_oid_(Kernel._method),_oid_(OWNER(v15429))) != CTRUE)
           { OID  v3213 = GC_OID(restriction_I_property(Language.iterate,list::alloc(3,v1047,
              _oid_(set::alloc(1,_oid_(v15438))),
              _oid_(Kernel._any)),CTRUE));
            if (Kernel._method == OWNER(v3213))
             v15429= v3213;
            } 
          (Optimize.compiler->safety = v3309);
          (v15438->range = v16123);
          { OID  v15434;
            { if ((Kernel._method == OWNER(v15429)) && (OBJECT(method,v15429)->inline_ask == CTRUE))
               { if ((Optimize.compiler->safety < 6) && 
                    (BCONTAIN(c_status_any(v4176,Kernel.nil),1)))
                 (Optimize.OPT->loop_gc = CTRUE);
                if (sort_abstract_ask_type(v15438->range) == CTRUE)
                 (v15438->range = CLREAD(Union,v15438->range,t2));
                v15434 = c_inline_method1(OBJECT(method,v15429),list::alloc(3,GC_OID(instruction_copy_any(GC_OID(v9332->set_arg))),
                  _oid_(v15438),
                  v4176),v15435);
                } 
              else if (boolean_I_any(v8699) == CTRUE)
               { OID  v14085;
                { For * v10264 = ((For *) GC_OBJECT(For,new_object_class(Language._For)));
                  (v10264->var = v15438);
                  (v10264->set_arg = v8699);
                  (v10264->arg = v4176);
                  add_I_property(Kernel.instances,Language._For,11,_oid_(v10264));
                  v14085 = _oid_(v10264);
                  } 
                v15434 = (*Optimize.c_code)(v14085,
                  _oid_(v15435));
                } 
              else if ((INHERIT(OWNER(v3469),Language._Call)) && (OBJECT(Call,v3469)->selector == Core.Id))
               v15434 = c_code_multiple_For(v9332,OBJECT(ClaireType,v1047),v15435);
              else { For * v3368;
                  { { For * v10264 = ((For *) GC_OBJECT(For,new_object_class(Language._For)));
                      (v10264->var = v15438);
                      (v10264->set_arg = c_gc_I_any1(GC_OID(enumerate_code_any(GC_OID(v9332->set_arg),OBJECT(ClaireType,v1047)))));
                      (v10264->arg = (*Optimize.c_code)(v4176,
                        _oid_(Kernel._void)));
                      add_I_property(Kernel.instances,Language._For,11,_oid_(v10264));
                      v3368 = v10264;
                      } 
                    GC_OBJECT(For,v3368);} 
                  if (v15435 == Kernel._any)
                   v15434 = _oid_(v3368);
                  else { Compile_to_C * v10264 = ((Compile_to_C *) GC_OBJECT(Compile_to_C,new_object_class(Optimize._to_C)));
                      (v10264->arg = _oid_(v3368));
                      (v10264->set_arg = v15435);
                      add_I_property(Kernel.instances,Optimize._to_C,11,_oid_(v10264));
                      v15434 = _oid_(v10264);
                      } 
                    } 
                GC_OID(v15434);} 
            if ((Optimize.OPT->protection == CTRUE) && 
                ((0 <= Optimize.OPT->loop_index) && 
                  (Optimize.compiler->safety < 6)))
             (Optimize.OPT->loop_gc = CTRUE);
            (Optimize.OPT->protection = ((Optimize.OPT->protection == CTRUE) ? CTRUE : ((v15418 == CTRUE) ? CTRUE : CFALSE)));
            Result = v15434;
            } 
          } 
        } 
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_multiple_For(For *v9332,ClaireType *v1047,ClaireClass *v15435)
{ GC_RESERVE(14);  // v3.0.55 optim !
  { OID Result = 0;
    { Variable * v15438 = GC_OBJECT(Variable,v9332->var);
      OID  v3469 = GC_OID((*(OBJECT(Call,v9332->set_arg)->args))[1]);
      Variable * v3492 = GC_OBJECT(Variable,Variable_I_symbol(append_symbol(v15438->pname,_string_(CSTRING("test"))),v9332->var->index,v1047));
      Let * v15431;
      { { Let * v10264 = ((Let *) GC_OBJECT(Let,new_object_class(Language._Let)));
          (v10264->var = v3492);
          (v10264->value = v3469);
          { Let * v423 = v10264; 
            OID  v424;
            { For * v10264 = ((For *) GC_OBJECT(For,new_object_class(Language._For)));
              (v10264->var = v9332->var);
              (v10264->set_arg = enumerate_code_any(v3469,v1047));
              (v10264->arg = v9332->arg);
              add_I_property(Kernel.instances,Language._For,11,_oid_(v10264));
              v424 = _oid_(v10264);
              } 
            (v423->arg = v424);} 
          add_I_property(Kernel.instances,Language._Let,11,_oid_(v10264));
          v15431 = v10264;
          } 
        GC_OBJECT(Let,v15431);} 
      tformat_string(CSTRING("---- note: use an expended iteration for {~S} \n"),0,list::alloc(1,_oid_(v9332)));
      { OID gc_local;
        ITERATE(v15434);
        for (START(Language.iterate->restrictions); NEXT(v15434);)
        { GC_LOOP;
          if ((_inf_equalt_class(domain_I_restriction(OBJECT(restriction,v15434)),v1047) == CTRUE) && 
              ((_inf_equalt_class(domain_I_restriction(OBJECT(restriction,v15434)),Kernel._collection) == CTRUE) && 
                ((OBJECT(method,v15434)->inline_ask == CTRUE) && 
                  (belong_to(_oid_(v15438),(*(OBJECT(restriction,v15434)->domain))[2]) == CTRUE))))
           { Variable * v8850;
            { { Variable * v10264 = ((Variable *) GC_OBJECT(Variable,new_object_class(Language._Variable)));
                (v10264->pname = v15438->pname);
                (v10264->range = v15438->range);
                (v10264->index = v15438->index);
                add_I_property(Kernel.instances,Language._Variable,11,_oid_(v10264));
                v8850 = v10264;
                } 
              GC_OBJECT(Variable,v8850);} 
            OID  v4176 = GC_OID(substitution_any(v9332->arg,v15438,_oid_(v8850)));
            { Let * v445 = v15431; 
              OID  v446;
              { If * v10264 = ((If *) GC_OBJECT(If,new_object_class(Language._If)));
                { If * v447 = v10264; 
                  OID  v448;
                  { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                    (v10264->selector = Kernel._Z);
                    (v10264->args = list::alloc(2,_oid_(v3492),(*(OBJECT(restriction,v15434)->domain))[1]));
                    add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
                    v448 = _oid_(v10264);
                    } 
                  (v447->test = v448);} 
                { If * v449 = v10264; 
                  OID  v452;
                  { if ((Optimize.compiler->safety < 6) && 
                        (BCONTAIN(c_status_any(GC_OID(v9332->arg),Kernel.nil),1)))
                     (Optimize.OPT->loop_gc = CTRUE);
                    if (sort_abstract_ask_type(v8850->range) == CTRUE)
                     (v8850->range = CLREAD(Union,v15438->range,t2));
                    v452 = c_inline_method1(OBJECT(method,v15434),GC_OBJECT(list,list::alloc(3,_oid_(v3492),
                      _oid_(v8850),
                      v4176)),v15435);
                    } 
                  (v449->arg = v452);} 
                (v10264->other = v15431->arg);
                add_I_property(Kernel.instances,Language._If,11,_oid_(v10264));
                v446 = _oid_(v10264);
                } 
              (v445->arg = v446);} 
            } 
          GC_UNLOOP;} 
        } 
      Result = (*Optimize.c_code)(_oid_(v15431),
        _oid_(v15435));
      } 
    GC_UNBIND; return (Result);} 
  } 

ClaireBoolean * c_gc_ask_Iteration(Iteration *v9332)
{ return (CTRUE);} 

ClaireType * c_type_Iteration_Optimize(Iteration *v9332)
{ GC_BIND;
  { ClaireType *Result ;
    { OID  v1047 = GC_OID((*Optimize.c_type)(GC_OID(v9332->set_arg)));
      range_infers_for_Variable(GC_OBJECT(Variable,v9332->var),GC_OBJECT(ClaireType,pmember_type(OBJECT(ClaireType,v1047))),OBJECT(ClaireType,v1047));
      Result = ((get_property(Kernel.of,v9332) != CNULL) ?
        param_I_class((((INHERIT(v9332->isa,Language._Select)) || 
            (INHERIT(v9332->isa,Language._Image))) ?
          Kernel._set :
          Kernel._list ),GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Kernel.of)(_oid_(v9332))))) :
        nth_class1((((INHERIT(v9332->isa,Language._Select)) || 
            (INHERIT(v9332->isa,Language._Image))) ?
          Kernel._set :
          Kernel._list ),GC_OBJECT(ClaireType,(((INHERIT(v9332->isa,Language._Select)) || 
            (INHERIT(v9332->isa,Language._Lselect))) ?
          pmember_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(GC_OID(v9332->set_arg))))) :
          ptype_type(OBJECT(ClaireType,(*Optimize.c_type)(GC_OID(v9332->arg)))) ))) );
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_Iteration_Optimize(Iteration *v9332)
{ GC_BIND;
  { OID Result = 0;
    { OID  v3469 = GC_OID(v9332->set_arg);
      OID  v1047 = GC_OID((*Optimize.c_type)(v3469));
      if (INHERIT(v9332->isa,Language._For))
       Result = (*Optimize.c_code)(_oid_(v9332),
        _oid_(Kernel._any));
      else if ((INHERIT(v9332->isa,Language._Collect)) && (_inf_equal_type(OBJECT(ClaireType,v1047),Kernel._bag) == CTRUE))
       { (Optimize.OPT->allocation = CTRUE);
        range_infers_for_Variable(GC_OBJECT(Variable,v9332->var),GC_OBJECT(ClaireType,pmember_type(OBJECT(ClaireType,v1047))),OBJECT(ClaireType,v1047));
        { ClaireType * v3501 = GC_OBJECT(ClaireType,ptype_type(OBJECT(ClaireType,(*Optimize.c_type)(GC_OID(v9332->arg)))));
          Collect * v15440;
          { { Collect * v10264 = ((Collect *) GC_OBJECT(Collect,new_object_class(Language._Collect)));
              (v10264->var = v9332->var);
              (v10264->set_arg = c_gc_I_any1(GC_OID(c_strict_code_any(v3469,Kernel._bag))));
              (v10264->arg = (*Optimize.c_code)(GC_OID(v9332->arg),
                _oid_(Kernel._any)));
              add_I_property(Kernel.instances,Language._Collect,11,_oid_(v10264));
              v15440 = v10264;
              } 
            GC_OBJECT(Collect,v15440);} 
          if (v3501 == Kernel._void)
           (*Optimize.Cerror)(_string_(CSTRING("[205] use of void expression ~S in ~S")),
            GC_OID(v9332->arg),
            _oid_(v9332));
          if (get_property(Kernel.of,v9332) != CNULL)
           { if ((Optimize.compiler->safety > 4) || 
                (_inf_equal_type(v3501,GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Kernel.of)(_oid_(v9332))))) == CTRUE))
             { update_property(Kernel.of,
                v15440,
                5,
                Kernel._object,
                GC_OID((*Kernel.of)(_oid_(v9332))));
              Result = _oid_(v15440);
              } 
            else { warn_void();
                tformat_string(CSTRING("unsafe typed collect (~S): ~S not in ~S [261]\n"),2,list::alloc(3,_oid_(v9332),
                  GC_OID((*Optimize.c_type)(GC_OID(v9332->arg))),
                  GC_OID((*Kernel.of)(_oid_(v9332)))));
                { OID  v11108;
                  { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                    (v10264->selector = Core.check_in);
                    (v10264->args = list::alloc(3,_oid_(v15440),
                      _oid_(Kernel._list),
                      GC_OID((*Kernel.of)(_oid_(v9332)))));
                    add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
                    v11108 = _oid_(v10264);
                    } 
                  Result = (*Optimize.c_code)(v11108,
                    _oid_(Kernel._list));
                  } 
                } 
              } 
          else Result = _oid_(v15440);
            } 
        } 
      else { OID  v11513;
          if (INHERIT(v9332->isa,Language._Image))
           v11513 = _oid_(set::empty());
          else v11513 = _oid_(list::empty());
            Variable * v15438;
          { { Cint  v12070;
              { (Optimize.OPT->max_vars = (Optimize.OPT->max_vars+1));
                v12070 = 0;
                } 
              v15438 = Variable_I_symbol(append_symbol(v9332->var->pname,_string_(CSTRING("_bag"))),v12070,((INHERIT(v9332->isa,Language._Image)) ?
                Kernel._set :
                Kernel._list ));
              } 
            GC_OBJECT(Variable,v15438);} 
          if (get_property(Kernel.of,v9332) != CNULL)
           { ClaireType * v15423 = GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(GC_OID(v9332->arg))));
            if ((_inf_equal_type(GC_OBJECT(ClaireType,ptype_type(v15423)),GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Kernel.of)(_oid_(v9332))))) != CTRUE) && 
                (Optimize.compiler->safety <= 4))
             { warn_void();
              tformat_string(CSTRING("unsafe bag construction (~S) : a ~S is not a ~S [262]\n"),2,list::alloc(3,GC_OID(_oid_(v9332->var)),
                _oid_(v15423),
                GC_OID((*Kernel.of)(_oid_(v9332)))));
              } 
            cast_I_bag(OBJECT(bag,v11513),OBJECT(ClaireType,(*Kernel.of)(_oid_(v9332))));
            (v15438->range = param_I_class(GC_OBJECT(ClaireClass,((ClaireClass *) v15438->range)),GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Kernel.of)(_oid_(v9332))))));
            } 
          else if (Kernel._set == OWNER(v11513))
             { Set * v10264 = ((Set *) GC_OBJECT(Set,new_object_class(Language._Set)));
              (v10264->of = Kernel.emptySet);
              add_I_property(Kernel.instances,Language._Set,11,_oid_(v10264));
              v11513 = _oid_(v10264);
              } 
            else { List * v10264 = ((List *) GC_OBJECT(List,new_object_class(Language._List)));
                (v10264->of = Kernel.emptySet);
                add_I_property(Kernel.instances,Language._List,11,_oid_(v10264));
                v11513 = _oid_(v10264);
                } 
              { Let * v10264 = ((Let *) GC_OBJECT(Let,new_object_class(Language._Let)));
            (v10264->var = v15438);
            (v10264->value = v11513);
            { Let * v457 = v10264; 
              OID  v476;
              { Do * v10264 = ((Do *) GC_OBJECT(Do,new_object_class(Language._Do)));
                { Do * v477 = v10264; 
                  list * v478;
                  { OID v_bag;
                    GC_ANY(v478= list::empty(Kernel.emptySet));
                    { { OID  v4287;
                        { For * v10264 = ((For *) GC_OBJECT(For,new_object_class(Language._For)));
                          (v10264->var = v9332->var);
                          (v10264->set_arg = v3469);
                          { Iteration * v480 = v10264; 
                            OID  v481;
                            { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                              (v10264->selector = Kernel.add_I);
                              (v10264->args = list::alloc(2,_oid_(v15438),GC_OID(v9332->arg)));
                              add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
                              v481 = _oid_(v10264);
                              } 
                            (v480->arg = v481);} 
                          add_I_property(Kernel.instances,Language._For,11,_oid_(v10264));
                          v4287 = _oid_(v10264);
                          } 
                        v_bag = (*Optimize.c_code)(v4287,
                          _oid_(Kernel._any));
                        } 
                      GC_OID(v_bag);} 
                    ((list *) v478)->addFast(v_bag);
                    if (Optimize.OPT->online_ask != CTRUE)
                     { (Optimize.OPT->protection = CTRUE);
                      { Compile_to_protect * v10264 = ((Compile_to_protect *) GC_OBJECT(Compile_to_protect,new_object_class(Optimize._to_protect)));
                        (v10264->arg = _oid_(v15438));
                        add_I_property(Kernel.instances,Optimize._to_protect,11,_oid_(v10264));
                        v_bag = _oid_(v10264);
                        } 
                      } 
                    else v_bag = _oid_(v15438);
                      ((list *) v478)->addFast(v_bag);} 
                  (v477->args = v478);} 
                add_I_property(Kernel.instances,Language._Do,11,_oid_(v10264));
                v476 = _oid_(v10264);
                } 
              (v457->arg = v476);} 
            add_I_property(Kernel.instances,Language._Let,11,_oid_(v10264));
            Result = _oid_(v10264);
            } 
          } 
        } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_Select_Optimize(Select *v9332)
{ return (c_code_select_Iteration(v9332,Kernel._set));} 

OID  c_code_Lselect_Optimize(Lselect *v9332)
{ return (c_code_select_Iteration(v9332,Kernel._list));} 

OID  c_code_select_Iteration(Iteration *v9332,ClaireClass *v15440)
{ GC_BIND;
  { OID Result = 0;
    { OID  v3469 = GC_OID(v9332->set_arg);
      OID  v1047 = GC_OID((*Optimize.c_type)(v3469));
      OID  v3465 = GC_OID(enumerate_code_any(v3469,OBJECT(ClaireType,v1047)));
      bag * v11513;
      if (v15440 == Kernel._set)
       v11513 = set::empty();
      else v11513 = list::empty();
        Variable * v3491;
      { { Cint  v9092;
          { (Optimize.OPT->max_vars = (Optimize.OPT->max_vars+1));
            v9092 = 0;
            } 
          v3491 = Variable_I_symbol(append_symbol(v9332->var->pname,_string_(CSTRING("_in"))),v9092,Kernel._bag);
          } 
        GC_OBJECT(Variable,v3491);} 
      Variable * v3492;
      { { Cint  v10053;
          { (Optimize.OPT->max_vars = (Optimize.OPT->max_vars+1));
            v10053 = 0;
            } 
          v3492 = Variable_I_symbol(append_symbol(v9332->var->pname,_string_(CSTRING("_out"))),v10053,v15440);
          } 
        GC_OBJECT(Variable,v3492);} 
      if (get_property(Kernel.of,v9332) != CNULL)
       { ClaireType * v15423 = GC_OBJECT(ClaireType,pmember_type(OBJECT(ClaireType,v1047)));
        if ((_inf_equal_type(GC_OBJECT(ClaireType,ptype_type(v15423)),GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Kernel.of)(_oid_(v9332))))) != CTRUE) && 
            (Optimize.compiler->safety <= 4))
         { warn_void();
          tformat_string(CSTRING("unsafe bag construction (~S) : a ~S is not a ~S [262]\n"),2,list::alloc(3,GC_OID(_oid_(v9332->var)),
            _oid_(v15423),
            GC_OID((*Kernel.of)(_oid_(v9332)))));
          } 
        cast_I_bag(v11513,OBJECT(ClaireType,(*Kernel.of)(_oid_(v9332))));
        (v3492->range = param_I_class(v15440,GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Kernel.of)(_oid_(v9332))))));
        Result = inner_select_Iteration(v9332,_oid_(v3492),v3469,_oid_(v11513));
        } 
      else if (_inf_equal_type(OBJECT(ClaireType,v1047),v15440) == CTRUE)
       { Let * v10264 = ((Let *) GC_OBJECT(Let,new_object_class(Language._Let)));
        (v10264->var = v3491);
        (v10264->value = v3465);
        { Let * v507 = v10264; 
          OID  v508;
          { OID  v349;
            { Compile_C_cast * v10264 = ((Compile_C_cast *) GC_OBJECT(Compile_C_cast,new_object_class(Optimize._C_cast)));
              { Compile_to_C * v511 = v10264; 
                OID  v512;
                { OID  v3233;
                  { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                    (v10264->selector = Kernel.empty);
                    (v10264->args = list::alloc(1,_oid_(v3491)));
                    add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
                    v3233 = _oid_(v10264);
                    } 
                  v512 = (*Optimize.c_code)(v3233,
                    _oid_(Kernel._bag));
                  } 
                (v511->arg = v512);} 
              (v10264->set_arg = v15440);
              add_I_property(Kernel.instances,Optimize._C_cast,11,_oid_(v10264));
              v349 = _oid_(v10264);
              } 
            v508 = inner_select_Iteration(v9332,_oid_(v3492),_oid_(v3491),v349);
            } 
          (v507->arg = v508);} 
        add_I_property(Kernel.instances,Language._Let,11,_oid_(v10264));
        Result = _oid_(v10264);
        } 
      else { OID  v4193;
          if (v15440 == Kernel._set)
           { Set * v10264 = ((Set *) GC_OBJECT(Set,new_object_class(Language._Set)));
            (v10264->of = Kernel.emptySet);
            add_I_property(Kernel.instances,Language._Set,11,_oid_(v10264));
            v4193 = _oid_(v10264);
            } 
          else { List * v10264 = ((List *) GC_OBJECT(List,new_object_class(Language._List)));
              (v10264->of = Kernel.emptySet);
              add_I_property(Kernel.instances,Language._List,11,_oid_(v10264));
              v4193 = _oid_(v10264);
              } 
            Result = inner_select_Iteration(v9332,_oid_(v3492),v3469,v4193);
          } 
        } 
    GC_UNBIND; return (Result);} 
  } 

OID  inner_select_Iteration(Iteration *v9332,OID v3492,OID v3469,OID v11513)
{ GC_BIND;
  { OID Result = 0;
    { Let * v10264 = ((Let *) GC_OBJECT(Let,new_object_class(Language._Let)));
      store_object(v10264,
        2,
        Kernel._object,
        v3492,
        CFALSE);
      (v10264->value = v11513);
      { Let * v515 = v10264; 
        OID  v516;
        { Do * v10264 = ((Do *) GC_OBJECT(Do,new_object_class(Language._Do)));
          { Do * v517 = v10264; 
            list * v538;
            { OID v_bag;
              GC_ANY(v538= list::empty(Kernel.emptySet));
              { { OID  v12795;
                  { For * v10264 = ((For *) GC_OBJECT(For,new_object_class(Language._For)));
                    (v10264->var = v9332->var);
                    (v10264->set_arg = v3469);
                    { Iteration * v540 = v10264; 
                      OID  v541;
                      { If * v10264 = ((If *) GC_OBJECT(If,new_object_class(Language._If)));
                        (v10264->test = v9332->arg);
                        { If * v542 = v10264; 
                          OID  v543;
                          { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                            (v10264->selector = Kernel.add_I);
                            (v10264->args = list::alloc(2,v3492,GC_OID(_oid_(v9332->var))));
                            add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
                            v543 = _oid_(v10264);
                            } 
                          (v542->arg = v543);} 
                        add_I_property(Kernel.instances,Language._If,11,_oid_(v10264));
                        (v10264->other = Kernel.cfalse);
                        v541 = _oid_(v10264);
                        } 
                      (v540->arg = v541);} 
                    add_I_property(Kernel.instances,Language._For,11,_oid_(v10264));
                    v12795 = _oid_(v10264);
                    } 
                  v_bag = (*Optimize.c_code)(v12795,
                    _oid_(Kernel._any));
                  } 
                GC_OID(v_bag);} 
              ((list *) v538)->addFast(v_bag);
              if (Optimize.OPT->online_ask != CTRUE)
               { (Optimize.OPT->protection = CTRUE);
                { Compile_to_protect * v10264 = ((Compile_to_protect *) GC_OBJECT(Compile_to_protect,new_object_class(Optimize._to_protect)));
                  (v10264->arg = v3492);
                  add_I_property(Kernel.instances,Optimize._to_protect,11,_oid_(v10264));
                  v_bag = _oid_(v10264);
                  } 
                } 
              else v_bag = v3492;
                ((list *) v538)->addFast(v_bag);} 
            (v517->args = v538);} 
          add_I_property(Kernel.instances,Language._Do,11,_oid_(v10264));
          v516 = _oid_(v10264);
          } 
        (v515->arg = v516);} 
      add_I_property(Kernel.instances,Language._Let,11,_oid_(v10264));
      Result = _oid_(v10264);
      } 
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_Exists_Optimize(Exists *v9332)
{ GC_BIND;
  { ClaireType *Result ;
    { OID  v1047 = GC_OID((*Optimize.c_type)(GC_OID(v9332->set_arg)));
      range_infers_for_Variable(GC_OBJECT(Variable,v9332->var),GC_OBJECT(ClaireType,pmember_type(OBJECT(ClaireType,v1047))),OBJECT(ClaireType,v1047));
      if (v9332->other == CNULL)
       Result = extends_type(GC_OBJECT(ClaireType,pmember_type(OBJECT(ClaireType,v1047))));
      else Result = Kernel._boolean;
        } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_Exists_Optimize(Exists *v9332,ClaireClass *v15435)
{ GC_BIND;
  { OID Result = 0;
    { OID  v1047 = GC_OID((*Optimize.c_type)(GC_OID(v9332->set_arg)));
      range_infers_for_Variable(GC_OBJECT(Variable,v9332->var),GC_OBJECT(ClaireType,pmember_type(OBJECT(ClaireType,v1047))),OBJECT(ClaireType,v1047));
      if (v9332->other == Kernel.ctrue)
       { OID  v2177;
        { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
          (v10264->selector = Core.NOT);
          { Call * v546 = v10264; 
            list * v547;
            { OID v_bag;
              GC_ANY(v547= list::empty(Kernel.emptySet));
              { { For * v10264 = ((For *) GC_OBJECT(For,new_object_class(Language._For)));
                  (v10264->var = v9332->var);
                  (v10264->set_arg = v9332->set_arg);
                  { Iteration * v570 = v10264; 
                    OID  v571;
                    { If * v10264 = ((If *) GC_OBJECT(If,new_object_class(Language._If)));
                      { If * v572 = v10264; 
                        OID  v573;
                        { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                          (v10264->selector = Core.NOT);
                          (v10264->args = list::alloc(1,GC_OID(v9332->arg)));
                          add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
                          v573 = _oid_(v10264);
                          } 
                        (v572->test = v573);} 
                      { If * v574 = v10264; 
                        OID  v575;
                        { Return * v10264 = ((Return *) GC_OBJECT(Return,new_object_class(Language._Return)));
                          (v10264->arg = Kernel.ctrue);
                          add_I_property(Kernel.instances,Language._Return,11,_oid_(v10264));
                          v575 = _oid_(v10264);
                          } 
                        (v574->arg = v575);} 
                      add_I_property(Kernel.instances,Language._If,11,_oid_(v10264));
                      (v10264->other = Kernel.cfalse);
                      v571 = _oid_(v10264);
                      } 
                    (v570->arg = v571);} 
                  add_I_property(Kernel.instances,Language._For,11,_oid_(v10264));
                  v_bag = _oid_(v10264);
                  } 
                GC_OID(v_bag);} 
              ((list *) v547)->addFast(v_bag);} 
            (v546->args = v547);} 
          add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
          v2177 = _oid_(v10264);
          } 
        Result = (*Optimize.c_code)(v2177,
          _oid_(v15435));
        } 
      else if (v9332->other == CNULL)
       { Variable * v15438;
        { { Cint  v14623;
            { (Optimize.OPT->max_vars = (Optimize.OPT->max_vars+1));
              v14623 = 0;
              } 
            v15438 = Variable_I_symbol(append_symbol(v9332->var->pname,_string_(CSTRING("_some"))),v14623,GC_OBJECT(ClaireType,extends_type(GC_OBJECT(ClaireType,v9332->var->range))));
            } 
          GC_OBJECT(Variable,v15438);} 
        { OID  v15584;
          { Let * v10264 = ((Let *) GC_OBJECT(Let,new_object_class(Language._Let)));
            (v10264->var = v15438);
            (v10264->value = CNULL);
            { Let * v578 = v10264; 
              OID  v579;
              { Do * v10264 = ((Do *) GC_OBJECT(Do,new_object_class(Language._Do)));
                { Do * v600 = v10264; 
                  list * v601;
                  { OID v_bag;
                    GC_ANY(v601= list::empty(Kernel.emptySet));
                    { { For * v10264 = ((For *) GC_OBJECT(For,new_object_class(Language._For)));
                        (v10264->var = v9332->var);
                        (v10264->set_arg = v9332->set_arg);
                        { Iteration * v604 = v10264; 
                          OID  v605;
                          { If * v10264 = ((If *) GC_OBJECT(If,new_object_class(Language._If)));
                            (v10264->test = v9332->arg);
                            { If * v606 = v10264; 
                              OID  v607;
                              { Return * v10264 = ((Return *) GC_OBJECT(Return,new_object_class(Language._Return)));
                                { Return * v608 = v10264; 
                                  OID  v609;
                                  { Assign * v10264 = ((Assign *) GC_OBJECT(Assign,new_object_class(Language._Assign)));
                                    (v10264->var = _oid_(v15438));
                                    (v10264->arg = _oid_(v9332->var));
                                    add_I_property(Kernel.instances,Language._Assign,11,_oid_(v10264));
                                    v609 = _oid_(v10264);
                                    } 
                                  (v608->arg = v609);} 
                                add_I_property(Kernel.instances,Language._Return,11,_oid_(v10264));
                                v607 = _oid_(v10264);
                                } 
                              (v606->arg = v607);} 
                            add_I_property(Kernel.instances,Language._If,11,_oid_(v10264));
                            (v10264->other = Kernel.cfalse);
                            v605 = _oid_(v10264);
                            } 
                          (v604->arg = v605);} 
                        add_I_property(Kernel.instances,Language._For,11,_oid_(v10264));
                        v_bag = _oid_(v10264);
                        } 
                      GC_OID(v_bag);} 
                    ((list *) v601)->addFast(v_bag);
                    ((list *) v601)->addFast(_oid_(v15438));} 
                  (v600->args = v601);} 
                add_I_property(Kernel.instances,Language._Do,11,_oid_(v10264));
                v579 = _oid_(v10264);
                } 
              (v578->arg = v579);} 
            add_I_property(Kernel.instances,Language._Let,11,_oid_(v10264));
            v15584 = _oid_(v10264);
            } 
          Result = (*Optimize.c_code)(v15584,
            _oid_(v15435));
          } 
        } 
      else { OID  v13568;
          { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
            (v10264->selector = Kernel.boolean_I);
            { Call * v611 = v10264; 
              list * v1282;
              { OID v_bag;
                GC_ANY(v1282= list::empty(Kernel.emptySet));
                { { For * v10264 = ((For *) GC_OBJECT(For,new_object_class(Language._For)));
                    (v10264->var = v9332->var);
                    (v10264->set_arg = v9332->set_arg);
                    { Iteration * v1283 = v10264; 
                      OID  v1284;
                      { If * v10264 = ((If *) GC_OBJECT(If,new_object_class(Language._If)));
                        (v10264->test = v9332->arg);
                        { If * v1285 = v10264; 
                          OID  v1286;
                          { Return * v10264 = ((Return *) GC_OBJECT(Return,new_object_class(Language._Return)));
                            (v10264->arg = Kernel.ctrue);
                            add_I_property(Kernel.instances,Language._Return,11,_oid_(v10264));
                            v1286 = _oid_(v10264);
                            } 
                          (v1285->arg = v1286);} 
                        add_I_property(Kernel.instances,Language._If,11,_oid_(v10264));
                        (v10264->other = Kernel.cfalse);
                        v1284 = _oid_(v10264);
                        } 
                      (v1283->arg = v1284);} 
                    add_I_property(Kernel.instances,Language._For,11,_oid_(v10264));
                    v_bag = _oid_(v10264);
                    } 
                  GC_OID(v_bag);} 
                ((list *) v1282)->addFast(v_bag);} 
              (v611->args = v1282);} 
            add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
            v13568 = _oid_(v10264);
            } 
          Result = (*Optimize.c_code)(v13568,
            _oid_(v15435));
          } 
        } 
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_Image_Optimize(Image *v9332)
{ GC_BIND;
  { ClaireType *Result ;
    { ClaireType * v1047 = GC_OBJECT(ClaireType,ptype_type(OBJECT(ClaireType,(*Optimize.c_type)(GC_OID(v9332->set_arg)))));
      range_infers_for_Variable(GC_OBJECT(Variable,v9332->var),GC_OBJECT(ClaireType,pmember_type(v1047)),v1047);
      Result = ((((v9332->of == (NULL)) ? CTRUE : CFALSE) != CTRUE) ?
        param_I_class(Kernel._set,GC_OBJECT(ClaireType,v9332->of)) :
        nth_class1(Kernel._set,GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(GC_OID(v9332->arg))))) );
      } 
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_Select_Optimize(Select *v9332)
{ GC_BIND;
  { ClaireType *Result ;
    { OID  v1047 = GC_OID((*Optimize.c_type)(GC_OID(v9332->set_arg)));
      range_infers_for_Variable(GC_OBJECT(Variable,v9332->var),GC_OBJECT(ClaireType,pmember_type(OBJECT(ClaireType,v1047))),OBJECT(ClaireType,v1047));
      Result = ((((v9332->of == (NULL)) ? CTRUE : CFALSE) != CTRUE) ?
        param_I_class(Kernel._set,GC_OBJECT(ClaireType,v9332->of)) :
        nth_class1(Kernel._set,GC_OBJECT(ClaireType,pmember_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(GC_OID(v9332->set_arg))))))) );
      } 
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_Lselect_Optimize(Lselect *v9332)
{ GC_BIND;
  { ClaireType *Result ;
    { OID  v1047 = GC_OID((*Optimize.c_type)(GC_OID(v9332->set_arg)));
      range_infers_for_Variable(GC_OBJECT(Variable,v9332->var),GC_OBJECT(ClaireType,pmember_type(OBJECT(ClaireType,v1047))),OBJECT(ClaireType,v1047));
      Result = ((((v9332->of == (NULL)) ? CTRUE : CFALSE) != CTRUE) ?
        param_I_class(Kernel._list,GC_OBJECT(ClaireType,v9332->of)) :
        nth_class1(Kernel._list,GC_OBJECT(ClaireType,pmember_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(GC_OID(v9332->set_arg))))))) );
      } 
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_While_Optimize(While *v9332)
{ GC_BIND;
  { ClaireType *Result ;
    Result = infers_from_type2(GC_OBJECT(ClaireType,return_type_any(GC_OID(v9332->arg))),_oid_(v9332));
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_While_Optimize(While *v9332,ClaireClass *v15435)
{ GC_BIND;
  { OID Result = 0;
    { ClaireBoolean * v15418 = Optimize.OPT->protection;
      (Optimize.OPT->protection = CFALSE);
      { While * v15434;
        { { While * v10264 = ((While *) GC_OBJECT(While,new_object_class(Language._While)));
            (v10264->test = c_boolean_any(GC_OID(v9332->test)));
            (v10264->arg = (*Optimize.c_code)(GC_OID(v9332->arg),
              _oid_(Kernel._void)));
            (v10264->other = v9332->other);
            add_I_property(Kernel.instances,Language._While,11,_oid_(v10264));
            v15434 = v10264;
            } 
          GC_OBJECT(While,v15434);} 
        if ((Optimize.OPT->protection == CTRUE) && 
            (0 <= Optimize.OPT->loop_index))
         (Optimize.OPT->loop_gc = CTRUE);
        (Optimize.OPT->protection = ((Optimize.OPT->protection == CTRUE) ? CTRUE : ((v15418 == CTRUE) ? CTRUE : CFALSE)));
        if ((v15435 != Kernel._void) && 
            (v15435 != Kernel._any))
         { { Compile_to_C * v10264 = ((Compile_to_C *) GC_OBJECT(Compile_to_C,new_object_class(Optimize._to_C)));
            (v10264->arg = _oid_(v15434));
            (v10264->set_arg = v15435);
            add_I_property(Kernel.instances,Optimize._to_C,11,_oid_(v10264));
            Result = _oid_(v10264);
            } 
          } 
        else Result = _oid_(v15434);
          } 
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  Iterate_I_Iteration(Iteration *v9332)
{ GC_BIND;
  { OID Result = 0;
    Result = restriction_I_property(Language.Iterate,list::alloc(3,_oid_(set::alloc(1,GC_OID(v9332->set_arg))),
      _oid_(set::alloc(1,GC_OID(_oid_(v9332->var)))),
      _oid_(Kernel._any)),CTRUE);
    GC_UNBIND; return (Result);} 
  } 

OID  iterate_Interval(Interval *v15440,Variable *v15438,OID v15421)
{ GC_RESERVE(1);  // HOHO v3.0.55 optim !
  { OID Result = 0;
    { OID  v15438 = GC_OID(eval_any2(v15440->arg1,Core._Interval));
      Cint  v3143 = eval_any2(v15440->arg2,Core._Interval);
      { OID gc_local;
        Result= _oid_(CFALSE);
        while ((v15438 <= v3143))
        { GC_LOOP;
          ;GC__OID(v15438 = (*Core._plus)(v15438,
            1), 1);
          GC_UNLOOP;} 
        } 
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  iterate_array(OID *v15440,Variable *v15438,OID v15421)
{ { OID Result = 0;
    { Cint  v1037 = 1;
      OID * v1028 = v15440;
      Cint  v3143 = v1028[0];
      { Result= _oid_(CFALSE);
        while ((v1037 <= v3143))
        { { OID  v15438 = nth_array(v1028,v1037);
            ;++v1037;
            } 
          } 
        } 
      } 
    return (Result);} 
  } 

OID  Iterate_class(ClaireClass *v15440,Variable *v15438,OID v15421)
{ { OID Result = 0;
    { ITERATE(v11659);
      Result= Kernel.cfalse;
      for (START(v15440->descendents); NEXT(v11659);)
      { ClaireBoolean * v11660;
        { OID v7538;{ ITERATE(v15438);
            v7538= Kernel.cfalse;
            for (START(OBJECT(ClaireClass,v11659)->instances); NEXT(v15438);)
            ;} 
          
          v11660=OBJECT(ClaireBoolean,v7538);} 
        if (v11660 == CTRUE)
         { Result = _oid_(v11660);
          break;} 
        } 
      } 
    return (Result);} 
  } 

OID  Iterate_any1(OID v15440,Variable *v15438,OID v15421)
{ GC_RESERVE(1);  // HOHO v3.0.55 optim !
  { OID Result = 0;
    { OID  v15438 = GC_OID(OPT_EVAL((*(OBJECT(Call,v15440)->args))[1]));
      OID  v3143 = GC_OID(OPT_EVAL((*(OBJECT(Call,v15440)->args))[2]));
      { OID gc_local;
        Result= _oid_(CFALSE);
        while (((OBJECT(ClaireBoolean,(*Kernel._inf_equal)(v15438,
          v3143))) == CTRUE))
        { GC_LOOP;
          ;GC__OID(v15438 = (*Core._plus)(v15438,
            1), 1);
          GC_UNLOOP;} 
        } 
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  Iterate_Lselect(Lselect *v15440,Variable *v15438,OID v15421)
{ GC_BIND;
  { OID Result = 0;
    { OID gc_local;
      ITERATE(v15438);
      Result= Kernel.cfalse;
      bag *v15438_support;
      v15438_support = GC_OBJECT(bag,enumerate_any(GC_OID(eval_any(GC_OID(v15440->set_arg)))));
      for (START(v15438_support); NEXT(v15438);)
      { GC_LOOP;
        if (boolean_I_any(eval_any(GC_OID(substitution_any(v15440->arg,v15440->var,v15438)))) == CTRUE)
         ;GC_UNLOOP;} 
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  Iterate_Select(Select *v15440,Variable *v15438,OID v15421)
{ GC_BIND;
  { OID Result = 0;
    { OID gc_local;
      ITERATE(v15438);
      Result= Kernel.cfalse;
      bag *v15438_support;
      v15438_support = GC_OBJECT(bag,enumerate_any(GC_OID(eval_any(GC_OID(v15440->set_arg)))));
      for (START(v15438_support); NEXT(v15438);)
      { GC_LOOP;
        if (boolean_I_any(eval_any(GC_OID(substitution_any(v15440->arg,v15440->var,v15438)))) == CTRUE)
         ;GC_UNLOOP;} 
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  Iterate_Collect(Collect *v15440,Variable *v15438,OID v15421)
{ GC_RESERVE(1);  // HOHO v3.0.55 optim !
  { OID Result = 0;
    { OID gc_local;
      ITERATE(v9804);
      Result= Kernel.cfalse;
      bag *v9804_support;
      v9804_support = GC_OBJECT(bag,enumerate_any(GC_OID(eval_any(GC_OID(v15440->set_arg)))));
      for (START(v9804_support); NEXT(v9804);)
      { GC_LOOP;
        { OID  v15438 = GC_OID(eval_any(GC_OID(substitution_any(v15440->arg,v15440->var,v9804))));
          ;} 
        GC_UNLOOP;} 
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  Iterate_any2(OID v15440,Variable *v15438,OID v15421)
{ GC_BIND;
  { OID Result = 0;
    { OID gc_local;
      ITERATE(v15438);
      Result= Kernel.cfalse;
      bag *v15438_support;
      v15438_support = GC_OBJECT(bag,enumerate_any(GC_OID(OPT_EVAL((*(OBJECT(Call,v15440)->args))[1]))));
      for (START(v15438_support); NEXT(v15438);)
      { GC_LOOP;
        if (equal(v15438,OPT_EVAL((*(OBJECT(Call,v15440)->args))[2])) != CTRUE)
         ;GC_UNLOOP;} 
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  Iterate_any3(OID v15440,Variable *v15438,OID v15421)
{ GC_BIND;
  { OID gc_local;
    ITERATE(v15438);
    bag *v15438_support;
    v15438_support = GC_OBJECT(bag,enumerate_any(GC_OID(OPT_EVAL((*(OBJECT(Call,v15440)->args))[1]))));
    for (START(v15438_support); NEXT(v15438);)
    ;} 
  { OID Result = 0;
    { OID gc_local;
      ITERATE(v15438);
      Result= Kernel.cfalse;
      bag *v15438_support;
      v15438_support = GC_OBJECT(bag,enumerate_any(GC_OID(OPT_EVAL((*(OBJECT(Call,v15440)->args))[2]))));
      for (START(v15438_support); NEXT(v15438);)
      ;} 
    GC_UNBIND; return (Result);} 
  } 

