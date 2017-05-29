/***** CLAIRE Compilation of file /Users/ycaseau/claire/v3.5/src/compile/ocall.cl 
         [version 3.5.01 / safety 5] Sun Jul 24 08:43:46 2016 *****/

#include <claire.h>
#include <Kernel.h>
#include <Core.h>
#include <Language.h>
#include <Reader.h>
#include <Optimize.h>
OID  restriction_I_property(property *v13540,list *v82388,ClaireBoolean *v106299)
{ { Cint  v82385 = 1;
    Cint  v61647 = v82388->length;
    { while ((v82385 <= v61647))
      { ((*(v82388))[v82385]=_oid_(ptype_type(OBJECT(ClaireType,(*(v82388))[v82385]))));
        ++v82385;
        } 
      } 
    } 
  return (restriction_I_list(v13540->definition,v82388,v106299));} 

OID  restriction_I_list(list *v63774,list *v82388,ClaireBoolean *v106299)
{ GC_RESERVE(1);  // HOHO v3.0.55 optim !
  ;{ OID Result = 0;
    { ClaireBoolean * v3932 = ((class_I_type(OBJECT(ClaireType,(*(v82388))[1]))->open == 3) ? CTRUE : CFALSE);
      OID  v16389 = _oid_(Kernel.emptySet);
      { OID gc_local;
        ITERATE(v82394);
        for (START(v63774); NEXT(v82394);)
        { GC_LOOP;
          if ((boolean_I_any(v16389) != CTRUE) && 
              (tmatch_ask_list(v82388,OBJECT(restriction,v82394)->domain) == CTRUE))
           { if (v106299 == CTRUE)
             GC__OID(v16389 = v82394, 1);
            else v16389= _oid_(OBJECT(restriction,v82394)->range);
              { ;break;} 
            } 
          else if (length_bag(_exp_list(OBJECT(restriction,v82394)->domain,v82388)) != 0)
           { if (v106299 != CTRUE)
             { GC__OID(v16389 = _oid_(U_type(OBJECT(ClaireType,v16389),OBJECT(restriction,v82394)->range)), 1);
              } 
            else if ((Optimize.compiler->safety <= 3) || 
                ((equal(v16389,_oid_(Kernel.emptySet)) != CTRUE) || 
                  (v3932 == CTRUE)))
             { v16389= _oid_(Optimize.ambiguous);
              { ;break;} 
              } 
            else GC__OID(v16389 = v82394, 1);
              } 
          GC_UNLOOP;} 
        } 
      Result = v16389;
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  restriction_I_class(ClaireClass *v82379,list *v63774,list *v82388)
{ if (Optimize.compiler->safety > 3)
   ((*(v82388))[1]=_oid_(_exp_type(v82379,OBJECT(ClaireType,(*(v82388))[1]))));
  { OID Result = 0;
    { ITERATE(v82394);
      Result= Kernel.cfalse;
      for (START(v63774); NEXT(v82394);)
      if (_inf_equalt_class(v82379,OBJECT(ClaireType,(*(OBJECT(restriction,v82394)->domain))[1])) == CTRUE)
       { if (tmatch_ask_list(v82388,OBJECT(restriction,v82394)->domain) == CTRUE)
         { Result = v82394;
          break;} 
        else if (length_bag(_exp_list(OBJECT(restriction,v82394)->domain,v82388)) != 0)
         { Result = _oid_(Optimize.ambiguous);
          break;} 
        } 
      } 
    return (Result);} 
  } 

ClaireType * use_range_method(method *v13540,list *v61567)
{ GC_BIND;
  { ClaireType *Result ;
    if ((v13540->inline_ask == CTRUE) && 
        (v13540->typing == CNULL))
     { list * v63778 = GC_OBJECT(list,v13540->formula->vars);
      ClaireType * v61575 = Kernel._any;
      list * v73619;
      { { bag *v_list; OID v_val;
          OID v82398,CLcount;
          v_list = v63778;
           v73619 = v_list->clone();
          for (CLcount= 1; CLcount <= v_list->length; CLcount++)
          { v82398 = (*(v_list))[CLcount];
            v_val = (*Kernel.range)(v82398);
            
            (*((list *) v73619))[CLcount] = v_val;} 
          } 
        GC_OBJECT(list,v73619);} 
      { ITERATE(v82398);
        for (START(v63778); NEXT(v82398);)
        put_property2(Kernel.range,OBJECT(ClaireObject,v82398),(*(v61567))[(((*Kernel.index)(v82398))+1)]);
        } 
      v61575= GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(GC_OID(v13540->formula->body))));
      { ITERATE(v82398);
        for (START(v63778); NEXT(v82398);)
        put_property2(Kernel.range,OBJECT(ClaireObject,v82398),(*(v73619))[(((*Kernel.index)(v82398))+1)]);
        } 
      if (INHERIT(v13540->range->isa,Kernel._type))
       v61575= GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Kernel._exp)(_oid_(v61575),
        _oid_(v13540->range))));
      if (boolean_I_any(_oid_(v61575)) != CTRUE)
       (*Optimize.Cerror)(_string_(CSTRING("[207] inline ~S: range ~S is incompatible with ~S (inferred)")),
        _oid_(v13540),
        _oid_(v13540->range),
        GC_OID((*Optimize.c_type)(GC_OID(v13540->formula->body))));
      Result = v61575;
      } 
    else { { OID  v82382 = GC_OID(v13540->typing);
          list * v73619;
          { { bag *v_list; OID v_val;
              OID v82397,CLcount;
              v_list = v61567;
               v73619 = v_list->clone(Kernel._type);
              for (CLcount= 1; CLcount <= v_list->length; CLcount++)
              { v82397 = (*(v_list))[CLcount];
                v_val = _oid_(ptype_type(OBJECT(ClaireType,v82397)));
                
                (*((list *) v73619))[CLcount] = v_val;} 
              } 
            GC_OBJECT(list,v73619);} 
          ClaireType * v73866 = v13540->range;
          ClaireType * v73867;
          { { ClaireObject *V_CC ;
              { ClaireHandler c_handle = ClaireHandler();
                if ERROR_IN 
                { if (INHERIT(OWNER(v82382),Core._lambda))
                   V_CC = OBJECT(ClaireType,apply_lambda(OBJECT(lambda,v82382),v73619));
                  else if (INHERIT(OWNER(v82382),Kernel._property))
                   V_CC = OBJECT(ClaireType,apply_property(OBJECT(property,v82382),v73619));
                  else if (INHERIT(OWNER(v82382),Kernel._function))
                   { OID v55170;{ list * v1904;
                      { list * v70175 = list::empty(Kernel.emptySet);
                        { Cint  v82390 = 1;
                          Cint  v61648 = (v61567->length+1);
                          { while ((v82390 <= v61648))
                            { v70175->addFast(_oid_(Kernel._object));
                              ++v82390;
                              } 
                            } 
                          } 
                        v1904 = GC_OBJECT(list,v70175);
                        } 
                      v55170 = apply_function(OBJECT(ClaireFunction,v82382),v1904,v73619);
                      } 
                    
                    V_CC=OBJECT(ClaireType,v55170);} 
                  else V_CC = v73866;
                    ClEnv->cHandle--;} 
                else if (belong_to(_oid_(ClEnv->exception_I),_oid_(Kernel._any)) == CTRUE)
                { c_handle.catchIt();{ tformat_string(CSTRING("~S's 2nd-order type failed on ~S \n"),0,list::alloc(2,_oid_(v13540),_oid_(v61567)));
                    V_CC = v73866;
                    } 
                  } 
                else PREVIOUS_HANDLER;} 
              v73867= (ClaireType *) V_CC;} 
            GC_OBJECT(ClaireType,v73867);} 
          if ((boolean_I_any(sort_equal_class(osort_any(_oid_(v73866)),osort_any(_oid_(v73867)))) == CTRUE) || 
              (v13540->selector == Core.externC))
           Result = v73867;
          else if (boolean_I_any(sort_equal_class(Kernel._any,osort_any(_oid_(v73866)))) == CTRUE)
           { Union * v88616 = ((Union *) GC_OBJECT(Union,new_object_class(Core._Union)));
            (v88616->t1 = Kernel._any);
            (v88616->t2 = v73867);
            Result = v88616;
            } 
          else Result = v73866;
            } 
        } 
      GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_Call_Optimize(Call *v13540)
{ GC_BIND;
  { ClaireType *Result ;
    { ClaireObject *V_CC ;
      if (v13540->selector == Language.function_I)
       V_CC = Kernel._function;
      else { property * v82395 = v13540->selector;
          list * v82388 = GC_OBJECT(list,v13540->args);
          list * v16967;
          { { bag *v_list; OID v_val;
              OID v82400,CLcount;
              v_list = v82388;
               v16967 = v_list->clone();
              for (CLcount= 1; CLcount <= v_list->length; CLcount++)
              { v82400 = (*(v_list))[CLcount];
                v_val = (*Optimize.c_type)(v82400);
                
                (*((list *) v16967))[CLcount] = v_val;} 
              } 
            GC_OBJECT(list,v16967);} 
          if (v82395 == Optimize.safe)
           V_CC = OBJECT(ClaireType,(*(v16967))[1]);
          else if ((v82395 == Core.externC) && 
              ((v82388->length == 2) && 
                (INHERIT(OWNER((*(v82388))[2]),Kernel._class))))
           V_CC = OBJECT(ClaireClass,(*(v82388))[2]);
          else if ((v82395 == Core.NEW) && 
              (INHERIT(OWNER((*(v82388))[1]),Kernel._class)))
           V_CC = OBJECT(ClaireClass,(*(v82388))[1]);
          else if ((v82395 == Core.check_in) && 
              (INHERIT(OWNER((*(v82388))[2]),Kernel._type)))
           { V_CC = ((v82388->length == 2) ?
              sort_abstract_I_type(OBJECT(ClaireType,(*(v82388))[2])) :
              OBJECT(ClaireType,(*(v82388))[2]) );
            } 
          else if ((v82395 == Kernel.nth) && 
              (_inf_equal_type(OBJECT(ClaireType,(*(v16967))[1]),Kernel._array) == CTRUE))
           { if (_inf_equal_type(GC_OBJECT(ClaireType,member_type(OBJECT(ClaireType,(*(v16967))[1]))),Kernel._float) == CTRUE)
             V_CC = Kernel._float;
            else V_CC = member_type(OBJECT(ClaireType,(*(v16967))[1]));
              } 
          else if ((v82395 == Core._at) && 
              (INHERIT(OWNER((*(v82388))[1]),Kernel._property)))
           { property * v82392 = OBJECT(property,(*(v82388))[1]);
            OID  v82379 = (*(v82388))[2];
            if ((INHERIT(OWNER(v82379),Kernel._class)) && 
                (Kernel._method == owner_any((*Core._at)(_oid_(v82392),
                  v82379))))
             V_CC = set::alloc(1,GC_OID((*Core._at)(_oid_(v82392),
              v82379)));
            else V_CC = Kernel._any;
              } 
          else if ((v82395 == Kernel.get) && 
              (INHERIT(OWNER((*(v82388))[1]),Kernel._relation)))
           { ClaireRelation * v82394 = OBJECT(ClaireRelation,(*(v82388))[1]);
            if (INHERIT(v82394->isa,Kernel._property))
             { ClaireObject * v64147 = GC_OBJECT(ClaireObject,_at_property1(((property *) v82394),class_I_type(OBJECT(ClaireType,(*(v16967))[2]))));
              if (Kernel._slot == v64147->isa)
               { if ((_inf_equal_type(CLREAD(restriction,v64147,range),Kernel._bag) == CTRUE) && 
                    (Optimize.compiler->safety < 3))
                 V_CC = class_I_type(OBJECT(ClaireType,(*Kernel.range)((*(v82388))[2])));
                else V_CC = ((belong_to(CLREAD(slot,v64147,DEFAULT),_oid_(CLREAD(restriction,v64147,range))) == CTRUE) ?
                  CLREAD(restriction,v64147,range) :
                  extends_type(CLREAD(restriction,v64147,range)) );
                } 
              else V_CC = v82394->range;
                } 
            else if (INHERIT(v82394->isa,Kernel._table))
             { V_CC = ((belong_to(CLREAD(table,v82394,DEFAULT),_oid_(v82394->range)) == CTRUE) ?
                v82394->range :
                extends_type(v82394->range) );
              } 
            else V_CC = CFALSE;
              } 
          else { OID  v82394 = GC_OID(restriction_I_property(v82395,v16967,CTRUE));
              if (Kernel._slot == OWNER(v82394))
               { if ((v82395 == Kernel.instances) && 
                    (INHERIT(OWNER((*(v82388))[1]),Kernel._class)))
                 { Param * v88616 = ((Param *) GC_OBJECT(Param,new_object_class(Core._Param)));
                  (v88616->arg = Kernel._list);
                  (v88616->params = list::alloc(1,_oid_(Kernel.of)));
                  (v88616->args = list::alloc(1,_oid_(set::alloc(1,(*(v82388))[1]))));
                  V_CC = v88616;
                  } 
                else V_CC = OBJECT(restriction,v82394)->range;
                  } 
              else if (Kernel._method == OWNER(v82394))
               V_CC = use_range_method(OBJECT(method,v82394),v16967);
              else if (boolean_I_any(_oid_(v82395->restrictions)) != CTRUE)
               V_CC = selector_psort_Call(v13540);
              else V_CC = (((v82395->open == 3) || 
                  (v82394 != _oid_(Optimize.ambiguous))) ?
                sort_abstract_I_type(v82395->range) :
                sort_abstract_I_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,restriction_I_property(v82395,v16967,CFALSE)))) );
              } 
            } 
        Result= (ClaireType *) V_CC;} 
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_Call_Optimize(Call *v13540)
{ return (c_code_call_Call(v13540,Kernel._void));} 

OID  c_code_call_Call(Call *v13540,ClaireClass *v63997)
{ GC_BIND;
  ;{ OID Result = 0;
    { property * v82395 = v13540->selector;
      list * v82388 = GC_OBJECT(list,v13540->args);
      if ((INHERIT(OWNER((*(v82388))[1]),Core._global_variable)) && 
          ((equal((*Kernel.range)((*(v82388))[1]),_oid_(Kernel.emptySet)) == CTRUE) && 
            (designated_ask_any(GC_OID((*Kernel.value)((*(v82388))[1]))) == CTRUE)))
       ((*(v82388))[1]=(*Kernel.value)((*(v82388))[1]));
      { OID  v82389 = GC_OID(inline_optimize_ask_Call(v13540));
        ClaireBoolean * v82378 = inherit_ask_class(OWNER((*(v82388))[1]),Kernel._property);
        OID  v82380 = GC_OID(daccess_any(_oid_(v13540),_sup_integer(Optimize.compiler->safety,5)));
        if ((v82378 == CTRUE) && 
            (((v82395 == Kernel.put) || 
                (v82395 == Core.write)) && 
              (v82388->length == 3)))
         Result = c_code_write_Call(v13540);
        else if ((v82378 == CTRUE) && 
            ((v82395 == Core.put_store) && 
              ((v82388->length == 4) && 
                ((*(v82388))[4] == Kernel.ctrue))))
         Result = c_code_write_Call(v13540);
        else if ((v82378 == CTRUE) && 
            (v82395 == Core.unknown_ask))
         Result = c_code_hold_property(OBJECT(property,(*(v82388))[1]),(*(v82388))[2],CNULL,CTRUE);
        else if ((v82378 == CTRUE) && 
            (v82395 == Core.known_ask))
         Result = c_code_hold_property(OBJECT(property,(*(v82388))[1]),(*(v82388))[2],CNULL,CFALSE);
        else if ((v82378 == CTRUE) && 
            ((v82395 == Core.erase) && 
              (INHERIT(OWNER((*(v82388))[2]),Language._Variable))))
         Result = (*Optimize.c_code)(GC_OID(Produce_erase_property2(OBJECT(property,(*(v82388))[1]),OBJECT(Variable,(*(v82388))[2]))),
          _oid_(v63997));
        else if (v82395 == Optimize.safe)
         { Cint  v82401 = Optimize.compiler->safety;
          ClaireBoolean * v82378 = Optimize.compiler->overflow_ask;
          OID  v82400 = CNULL;
          (Optimize.compiler->safety = 1);
          (Optimize.compiler->overflow_ask = CTRUE);
          { { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
              (v88616->selector = Optimize.safe);
              (v88616->args = list::alloc(1,GC_OID((*Optimize.c_code)((*(v82388))[1],
                _oid_(v63997)))));
              add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
              v82400 = _oid_(v88616);
              } 
            GC_OID(v82400);} 
          (Optimize.compiler->safety = v82401);
          (Optimize.compiler->overflow_ask = v82378);
          Result = v82400;
          } 
        else if (((v82395 == Kernel.add) || 
              (v82395 == Kernel.add_I)) && 
            (v82378 == CTRUE))
         Result = c_code_add_Call(v13540);
        else if (((v82395 == Kernel.add) || 
              (v82395 == Kernel.add_I)) && 
            (_inf_equal_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)((*(v82388))[1]))),Kernel._bag) == CTRUE))
         Result = c_code_add_bag_Call(v13540);
        else if ((v82378 == CTRUE) && 
            (v82395 == Kernel._delete))
         Result = c_code_delete_Call(v13540);
        else if ((contain_ask_set(Optimize.OPT->to_remove,_oid_(v82395)) == CTRUE) || 
            ((v82395 == Optimize.c_interface) && 
                ((v82388->length == 2) && 
                  (contain_ask_set(Optimize.OPT->legal_modules,get_module_object(v82395)) != CTRUE))))
         Result = Core.nil->value;
        else if (v82380 != CNULL)
         Result = v82380;
        else if (Kernel._method == OWNER(v82389))
         Result = c_inline_method1(OBJECT(method,v82389),v82388,c_srange_method(OBJECT(method,v82389)));
        else if (((v82395 == Kernel._equal) || 
              (v82395 == Core._I_equal)) && 
            (daccess_any((*(v82388))[1],CTRUE) != CNULL))
         Result = c_code_hold_property(OBJECT(property,(*(OBJECT(bag,(*Core.args)((*(v82388))[1]))))[1]),GC_OID((*(OBJECT(bag,(*Core.args)((*(v82388))[1]))))[2]),(*(v82388))[2],equal(_oid_(v82395),_oid_(Kernel._equal)));
        else if (((v82395 == Kernel._equal) || 
              (v82395 == Core._I_equal)) && 
            (daccess_any((*(v82388))[2],CTRUE) != CNULL))
         Result = c_code_hold_property(OBJECT(property,(*(OBJECT(bag,(*Core.args)((*(v82388))[2]))))[1]),GC_OID((*(OBJECT(bag,(*Core.args)((*(v82388))[2]))))[2]),(*(v82388))[1],equal(_oid_(v82395),_oid_(Kernel._equal)));
        else if (((v82395 == Kernel.nth_equal) || 
              (v82395 == Kernel.put)) && 
            ((INHERIT(OWNER((*(v82388))[1]),Kernel._table)) && 
              (v82388->length == 3)))
         Result = c_code_table_Call(v13540);
        else if (((v82395 == Kernel.nth_put) || 
              (v82395 == Kernel.nth_equal)) && 
            ((_inf_equal_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)((*(v82388))[1]))),Kernel._array) == CTRUE) && 
              (v82388->length == 3)))
         Result = c_code_array_Call(v13540);
        else if ((v82395 == Kernel.nth) || 
            (((v82395 == Kernel.get) && 
                (INHERIT(OWNER((*(v82388))[1]),Kernel._table))) || 
              ((v82395 == Kernel.nth_get) && 
                  (Kernel._array == OWNER((*(v82388))[1])))))
         Result = c_code_nth_Call(v13540);
        else if (v82395 == Kernel._Z)
         Result = c_code_belong_Call(v13540);
        else if (v82395 == Core.Id)
         Result = (*Optimize.c_code)(GC_OID(OPT_EVAL((*(v82388))[1])));
        else if (v82395 == Language.function_I)
         Result = _oid_(make_function_string(string_I_symbol(extract_symbol_any((*(v82388))[1]))));
        else if ((v82395 == Core.NOT) && 
            (INHERIT(OWNER((*(v82388))[1]),Language._Select)))
         Result = c_code_not_Select(OBJECT(Select,(*(v82388))[1]));
        else if ((v82395 == Core.call) && 
            (INHERIT(OWNER((*(v82388))[1]),Kernel._property)))
         { OID  v23046;
          { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
            update_property(Kernel.selector,
              v88616,
              2,
              Kernel._object,
              (*(v82388))[1]);
            (v88616->args = cdr_list(v82388));
            add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
            v23046 = _oid_(v88616);
            } 
          Result = (*Optimize.c_code)(v23046);
          } 
        else if (v82395->open == 3)
         { list * v24007;
          { { bag *v_list; OID v_val;
              OID v82400,CLcount;
              v_list = v82388;
               v24007 = v_list->clone();
              for (CLcount= 1; CLcount <= v_list->length; CLcount++)
              { v82400 = (*(v_list))[CLcount];
                v_val = (*Optimize.c_type)(v82400);
                
                (*((list *) v24007))[CLcount] = v_val;} 
              } 
            GC_OBJECT(list,v24007);} 
          Result = c_warn_property(v82395,v82388,v24007);
          } 
        else { ClaireBoolean * g0092I;
          { ClaireBoolean *v_and;
            { v_and = ((v82395 == Language.bit_vector) ? CTRUE : CFALSE);
              if (v_and == CFALSE) g0092I =CFALSE; 
              else { { OID  v25929;
                  { OID gc_local;
                    ITERATE(v82401);
                    v25929= Kernel.cfalse;
                    bag *v82401_support;
                    v82401_support = GC_OBJECT(list,v13540->args);
                    for (START(v82401_support); NEXT(v82401);)
                    if (inherit_ask_class(OWNER(v82401),Kernel._integer) != CTRUE)
                     { v25929 = Kernel.ctrue;
                      break;} 
                    } 
                  v_and = not_any(v25929);
                  } 
                if (v_and == CFALSE) g0092I =CFALSE; 
                else g0092I = CTRUE;} 
              } 
            } 
          
          if (g0092I == CTRUE) Result = OPT_EVAL(_oid_(v13540));
            else if ((v82395 == Optimize.anyObject_I) || 
              ((v82395 == Optimize.object_I) || 
                ((v82395 == Kernel.add_method) && 
                    (v82378 == CTRUE))))
           Result = _oid_(v13540);
          else { list * v16967;
              { { bag *v_list; OID v_val;
                  OID v82400,CLcount;
                  v_list = v82388;
                   v16967 = v_list->clone();
                  for (CLcount= 1; CLcount <= v_list->length; CLcount++)
                  { v82400 = (*(v_list))[CLcount];
                    v_val = (*Optimize.c_type)(v82400);
                    
                    (*((list *) v16967))[CLcount] = v_val;} 
                  } 
                GC_OBJECT(list,v16967);} 
              OID  v82402 = GC_OID(restriction_I_property(v82395,v16967,CTRUE));
              if (Kernel._slot == OWNER(v82402))
               { ClaireBoolean * v66077 = ((belong_to(OBJECT(slot,v82402)->DEFAULT,_oid_(OBJECT(restriction,v82402)->range)) != CTRUE) ? ((contain_ask_set(Optimize.OPT->knowns,_oid_(v82395)) != CTRUE) ? ((Optimize.compiler->safety < 5) ? CTRUE: CFALSE): CFALSE): CFALSE);
                if ((v66077 != CTRUE) || 
                    (designated_ask_any((*(v82388))[1]) == CTRUE))
                 { Call_slot * v88616 = ((Call_slot *) GC_OBJECT(Call_slot,new_object_class(Language._Call_slot)));
                  (v88616->selector = OBJECT(slot,v82402));
                  (v88616->arg = (*Optimize.c_code)((*(v82388))[1],
                    _oid_(psort_any(_oid_(domain_I_restriction(OBJECT(restriction,v82402)))))));
                  (v88616->test = v66077);
                  add_I_property(Kernel.instances,Language._Call_slot,11,_oid_(v88616));
                  Result = _oid_(v88616);
                  } 
                else { if (Optimize.compiler->optimize_ask == CTRUE)
                     { notice_void();
                      ;} 
                    Result = c_warn_property(v82395,v82388,v16967);
                    } 
                  } 
              else if (Kernel._method == OWNER(v82402))
               { if (v82395 == Kernel.nth_equal)
                 (Optimize.OPT->use_nth_equal = CTRUE);
                if (v16967->memq(_oid_(Kernel._void)) == CTRUE)
                 (*Optimize.Cerror)(_string_(CSTRING("[205] call ~S uses a void argument [~S]")),
                  _oid_(v13540),
                  _oid_(v16967));
                if (((v82395 == Kernel.begin) || 
                      (v82395 == Kernel.end)) && 
                    (INHERIT(OWNER((*(v82388))[1]),Kernel._module)))
                 OPT_EVAL(_oid_(v13540));
                if ((last_list(OBJECT(restriction,v82402)->domain) == _oid_(Kernel._listargs)) || 
                    (((*(OBJECT(restriction,v82402)->domain))[1] == _oid_(Kernel._void)) && 
                        ((*(v82388))[1] != _oid_(ClEnv))))
                 Result = _oid_(open_message_property(v82395,v82388));
                else Result = c_code_method_method2(OBJECT(method,v82402),v82388,v16967,v63997);
                  } 
              else if (INHERIT(OWNER(v82402),Kernel._keyword))
               Result = c_warn_property(v82395,v82388,v16967);
              else Result = c_warn_Call(v13540,_oid_(v16967));
                } 
            } 
        } 
      } 
    GC_UNBIND; return (Result);} 
  } 

Call * open_message_property(property *v13540,list *v82388)
{ GC_BIND;
  selector_register_property(v13540);
  { Call *Result ;
    { list * v45481;
      { { bag *v_list; OID v_val;
          OID v82400,CLcount;
          v_list = v82388;
           v45481 = v_list->clone();
          for (CLcount= 1; CLcount <= v_list->length; CLcount++)
          { v82400 = (*(v_list))[CLcount];
            if ((*Optimize.c_type)(v82400) != _oid_(Kernel._void))
             v_val = (*Optimize.c_code)(v82400,
              _oid_(Kernel._any));
            else v_val = (*Optimize.Cerror)(_string_(CSTRING("[206] use of void ~S in ~S~S")),
                v82400,
                _oid_(v13540),
                _oid_(v82388));
              
            (*((list *) v45481))[CLcount] = v_val;} 
          } 
        GC_OBJECT(list,v45481);} 
      if (Optimize.OPT->allocation == CTRUE)
       { { bag *v_list; OID v_val;
          OID v82400,CLcount;
          v_list = v45481;
           v45481 = v_list->clone();
          for (CLcount= 1; CLcount <= v_list->length; CLcount++)
          { v82400 = (*(v_list))[CLcount];
            v_val = c_gc_I_any1(v82400);
            
            (*((list *) v45481))[CLcount] = v_val;} 
          } 
        GC_OBJECT(list,v45481);} 
      { ClaireBoolean * g0094I;
        { ClaireBoolean *v_and;
          { v_and = Optimize.compiler->diet_ask;
            if (v_and == CFALSE) g0094I =CFALSE; 
            else { { OID  v27851;
                { ITERATE(v82400);
                  v27851= Kernel.cfalse;
                  for (START(v82388); NEXT(v82400);)
                  if ((INHERIT(OWNER(v82400),Kernel._class)) || 
                      (INHERIT(OWNER(v82400),Kernel._property)))
                   { v27851 = Kernel.ctrue;
                    break;} 
                  } 
                v_and = boolean_I_any(v27851);
                } 
              if (v_and == CFALSE) g0094I =CFALSE; 
              else g0094I = CTRUE;} 
            } 
          } 
        
        if (g0094I == CTRUE) { warn_void();
            tformat_string(CSTRING("Non diet call ~S(~A) [254]\n"),2,list::alloc(2,_oid_(v13540),_oid_(v82388)));
            } 
          } 
      { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
        (v88616->selector = v13540);
        (v88616->args = v45481);
        add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
        Result = v88616;
        } 
      } 
    GC_UNBIND; return (Result);} 
  } 

ClaireBoolean * c_gc_ask_Call(Call *v13540)
{ GC_BIND;
  { ClaireBoolean *Result ;
    Result = ((v13540->selector == Language.function_I) ? CTRUE : (((v13540->selector == Optimize.safe) ? ((OBJECT(ClaireBoolean,(*Optimize.c_gc_ask)((*(v13540->args))[1]))) == CTRUE) : (((stable_ask_relation(v13540->selector) == CTRUE) ? (((OBJECT(ClaireBoolean,_oid_((INHERIT(v13540->selector->range->isa,Kernel._class) ? (ClaireObject *) gcsafe_ask_class((ClaireClass *) OBJECT(ClaireClass,_oid_(v13540->selector->range))) :  (ClaireObject *)  gcsafe_ask_type((ClaireType *) OBJECT(ClaireType,_oid_(v13540->selector->range))))))) == CTRUE) ? CTRUE: CFALSE): CFALSE) != CTRUE)) ? CTRUE : CFALSE));
    GC_UNBIND; return (Result);} 
  } 

OID  daccess_any(OID v13540,ClaireBoolean *v82378)
{ GC_BIND;
  { OID Result = 0;
    if (INHERIT(OWNER(v13540),Language._Call))
     { list * v82388 = GC_OBJECT(list,OBJECT(Call,v13540)->args);
      ClaireObject * v64147;
      { if ((OBJECT(Call,v13540)->selector == Kernel.get) && 
            (INHERIT(OWNER((*(v82388))[1]),Kernel._property)))
         v64147 = _at_property1(OBJECT(property,(*(v82388))[1]),class_I_type(OBJECT(ClaireType,(*Optimize.c_type)((*(v82388))[2]))));
        else v64147 = CFALSE;
          GC_OBJECT(ClaireObject,v64147);} 
      if ((Kernel._slot == v64147->isa) && ((v82378 == CTRUE) || 
          ((belong_to(CLREAD(slot,v64147,DEFAULT),_oid_(CLREAD(restriction,v64147,range))) == CTRUE) || 
            ((CLREAD(slot,v64147,srange) == Kernel._any) || 
              (CLREAD(slot,v64147,srange) == Kernel._integer)))))
       { Call_slot * v88616 = ((Call_slot *) GC_OBJECT(Call_slot,new_object_class(Language._Call_slot)));
        (v88616->selector = ((slot *) v64147));
        (v88616->arg = (*Optimize.c_code)((*(v82388))[2],
          _oid_(psort_any(_oid_(domain_I_restriction(((restriction *) v64147)))))));
        (v88616->test = CFALSE);
        add_I_property(Kernel.instances,Language._Call_slot,11,_oid_(v88616));
        Result = _oid_(v88616);
        } 
      else Result = CNULL;
        } 
    else Result = CNULL;
      GC_UNBIND; return (Result);} 
  } 

ClaireBoolean * c_gc_ask_Call_slot(Call_slot *v13540)
{ { ClaireBoolean *Result ;
    { slot * v82395 = v13540->selector;
      OID  v82400 = v13540->arg;
      Result = ((_oid_((INHERIT(v82395->range->isa,Kernel._class) ? (ClaireObject *) gcsafe_ask_class((ClaireClass *) OBJECT(ClaireClass,_oid_(v82395->range))) :  (ClaireObject *)  gcsafe_ask_type((ClaireType *) OBJECT(ClaireType,_oid_(v82395->range))))) != Kernel.ctrue) ? ((v82395->range != Kernel._float) ? (((1 <= v82395->selector->open) || 
          (gcsafe_ask_class(domain_I_restriction(v82395)) != CTRUE)) ? CTRUE: CFALSE): CFALSE): CFALSE);
      } 
    return (Result);} 
  } 

ClaireType * c_type_Call_slot_Optimize(Call_slot *v13540)
{ return (v13540->selector->range);} 

ClaireType * c_type_Call_table_Optimize(Call_table *v13540)
{ return (v13540->selector->range);} 

ClaireType * c_type_Call_array_Optimize(Call_array *v13540)
{ return (OBJECT(ClaireType,v13540->test));} 

OID  c_code_write_Call(Call *v13540)
{ GC_BIND;
  { OID Result = 0;
    { OID  v82392 = GC_OID((*(v13540->args))[1]);
      OID  v82400 = GC_OID((*(v13540->args))[2]);
      OID  v82401 = GC_OID((*(v13540->args))[3]);
      OID  v64179 = GC_OID((*Optimize.c_type)(v82401));
      property * v63992 = v13540->selector;
      OID  v82395 = GC_OID((*Optimize.restriction_I)(v82392,
        _oid_(list::alloc(1,GC_OID((*Optimize.c_type)(v82400)))),
        Kernel.ctrue));
      (Optimize.OPT->use_update = CTRUE);
      if (contain_ask_set(Optimize.OPT->to_remove,v82392) == CTRUE)
       Result = Core.nil->value;
      else if ((Kernel._slot == OWNER(v82395)) && ((_inf_equal_type(OBJECT(ClaireType,v64179),OBJECT(restriction,v82395)->range) == CTRUE) || 
          (4 <= Optimize.compiler->safety)))
       { if ((v82401 != CNULL) && 
            (boolean_I_any((*Kernel._exp)(v64179,
              GC_OID((*Kernel.srange)(v82395)))) != CTRUE))
         { warn_void();
          tformat_string(CSTRING("sort error in ~S: ~S is a ~S [253]\n"),2,list::alloc(3,_oid_(v13540),
            v82401,
            v64179));
          } 
        if (((_inf_equal_type(OBJECT(ClaireType,v64179),GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Kernel.range)(v82395)))) == CTRUE) || 
              ((_inf_equal_type(OBJECT(ClaireType,v64179),Kernel._object) == CTRUE) || 
                (((*Kernel.srange)(v82395) != _oid_(Kernel._object)) || 
                  (v82401 == CNULL)))) && 
            ((v63992 != Core.write) || 
                ((Update_ask_relation(OBJECT(ClaireRelation,v82392),v82400,v82401) == CTRUE) && 
                    ((OBJECT(ClaireRelation,v82392)->multivalued_ask == CFALSE) || 
                        (get_property(Kernel.if_write,OBJECT(ClaireObject,v82392)) == CNULL)))))
         { OID  v61579 = GC_OID((*Optimize.c_code)(v82400,
            _oid_(psort_any(_oid_(domain_I_restriction(OBJECT(restriction,v82395)))))));
          OID  v61588 = GC_OID(c_strict_code_any(v82401,psort_any((*Kernel.range)(v82395))));
          Update * v88616 = ((Update *) GC_OBJECT(Update,new_object_class(Language._Update)));
          (v88616->selector = v82392);
          (v88616->value = v61588);
          { Update * v61676 = v88616; 
            OID  v61677;
            if (v63992 != Core.write)
             v61677 = _oid_(v63992);
            else v61677 = (*Optimize.c_code)(v82400,
                _oid_(Kernel._any));
              (v61676->arg = v61677);} 
          { Update * v61678 = v88616; 
            OID  v61679;
            { Call_slot * v88616 = ((Call_slot *) GC_OBJECT(Call_slot,new_object_class(Language._Call_slot)));
              update_property(Kernel.selector,
                v88616,
                2,
                Kernel._object,
                v82395);
              (v88616->arg = v61579);
              (v88616->test = CFALSE);
              add_I_property(Kernel.instances,Language._Call_slot,11,_oid_(v88616));
              v61679 = _oid_(v88616);
              } 
            (v61678->var = v61679);} 
          add_I_property(Kernel.instances,Language._Update,11,_oid_(v88616));
          Result = _oid_(v88616);
          } 
        else if (v63992 == Kernel.put)
         { OID  v23088;
          { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
            (v88616->selector = Kernel.store);
            (v88616->args = list::alloc(5,v82400,
              (*Kernel.index)(v82395),
              GC_OID((*Kernel.srange)(v82395)),
              v82401,
              GC_OID((*Kernel.store_ask)(v82392))));
            add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
            v23088 = _oid_(v88616);
            } 
          Result = (*Optimize.c_code)(v23088);
          } 
        else { if (Optimize.compiler->diet_ask == CTRUE)
             { warn_void();
              tformat_string(CSTRING("~S is not a diet call [254]"),2,list::alloc(1,_oid_(v13540)));
              } 
            if ((Optimize.compiler->optimize_ask == CTRUE) && 
                (v82392 != _oid_(Kernel.instances)))
             { notice_void();
              ;} 
            { OID  v24049;
              { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                (v88616->selector = Core.update);
                (v88616->args = list::alloc(5,v82392,
                  v82400,
                  (*Kernel.index)(v82395),
                  GC_OID((*Kernel.srange)(v82395)),
                  v82401));
                add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
                v24049 = _oid_(v88616);
                } 
              Result = (*Optimize.c_code)(v24049);
              } 
            } 
          } 
      else { list * v16967;
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
          OID  v82402 = GC_OID(restriction_I_property(v63992,v16967,CTRUE));
          if (Kernel._method == OWNER(v82402))
           Result = c_code_method_method1(OBJECT(method,v82402),GC_OBJECT(list,v13540->args),v16967);
          else Result = c_warn_Call(v13540,_oid_(v16967));
            } 
        } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_hold_property(property *v82392,OID v82400,OID v82401,ClaireBoolean *v82378)
{ GC_BIND;
  { OID Result = 0;
    { OID  v82395 = GC_OID(restriction_I_property(v82392,list::alloc(1,GC_OID((*Optimize.c_type)(v82400))),CTRUE));
      if ((Kernel._slot == OWNER(v82395)) && ((v82401 == CNULL) || 
          ((_inf_equal_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(v82401))),OBJECT(slot,v82395)->srange) == CTRUE) && 
              (identifiable_ask_any(v82401) == CTRUE))))
       { Call_slot * v63496;
        { { Call_slot * v88616 = ((Call_slot *) GC_OBJECT(Call_slot,new_object_class(Language._Call_slot)));
            update_property(Kernel.selector,
              v88616,
              2,
              Kernel._object,
              v82395);
            (v88616->arg = (*Optimize.c_code)(v82400,
              _oid_(psort_any(_oid_(domain_I_restriction(OBJECT(restriction,v82395)))))));
            (v88616->test = CFALSE);
            add_I_property(Kernel.instances,Language._Call_slot,11,_oid_(v88616));
            v63496 = v88616;
            } 
          GC_OBJECT(Call_slot,v63496);} 
        Call_method2 * v63490;
        { { Call_method2 * v88616 = ((Call_method2 *) GC_OBJECT(Call_method2,new_object_class(Language._Call_method2)));
            (v88616->arg = ((method *) _at_property1(Core.identical_ask,Kernel._any)));
            (v88616->args = list::alloc(2,_oid_(v63496),GC_OID((*Optimize.c_code)(v82401,
              GC_OID((*Kernel.srange)(v82395))))));
            add_I_property(Kernel.instances,Language._Call_method2,11,_oid_(v88616));
            v63490 = v88616;
            } 
          GC_OBJECT(Call_method2,v63490);} 
        if (v82378 == CTRUE)
         Result = (*Optimize.c_code)(_oid_(v63490));
        else { OID  v25010;
            { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
              (v88616->selector = Core.NOT);
              (v88616->args = list::alloc(1,_oid_(v63490)));
              add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
              v25010 = _oid_(v88616);
              } 
            Result = (*Optimize.c_code)(v25010);
            } 
          } 
      else { list * v82388 = list::alloc(2,_oid_(Kernel._any),_oid_(Kernel._any));
          { list * v25971;
            { OID v_bag;
              GC_ANY(v25971= list::empty(Kernel.emptySet));
              { { OID  v26932;
                  { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                    (v88616->selector = Kernel.get);
                    (v88616->args = list::alloc(2,_oid_(v82392),v82400));
                    add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
                    v26932 = _oid_(v88616);
                    } 
                  v_bag = (*Optimize.c_code)(v26932,
                    _oid_(Kernel._any));
                  } 
                GC_OID(v_bag);} 
              ((list *) v25971)->addFast(v_bag);
              ((list *) v25971)->addFast(GC_OID((*Optimize.c_code)(v82401,
                _oid_(Kernel._any))));} 
            Result = c_code_method_method1(GC_OBJECT(method,((method *) _at_property2(((v82378 == CTRUE) ?
              Kernel._equal :
              Core._I_equal ),v82388))),v25971,v82388);
            } 
          } 
        } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_add_Call(Call *v13540)
{ GC_BIND;
  { OID Result = 0;
    { property * v82392 = OBJECT(property,(*(v13540->args))[1]);
      OID  v82400 = GC_OID((*(v13540->args))[2]);
      OID  v82401 = GC_OID((*(v13540->args))[3]);
      ClaireObject * v82395 = GC_OBJECT(ClaireObject,_at_property1(v82392,class_I_type(ptype_type(OBJECT(ClaireType,(*Optimize.c_type)(v82400))))));
      (Optimize.OPT->use_update = CTRUE);
      if ((Kernel._slot == v82395->isa) && ((_inf_equal_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(v82401))),GC_OBJECT(ClaireType,member_type(CLREAD(restriction,v82395,range)))) == CTRUE) || 
          (4 <= Optimize.compiler->safety)))
       { if (Update_ask_relation2(v82392,v13540->selector) == CTRUE)
         { OID  v64082 = GC_OID((*Optimize.c_code)(v82400,
            _oid_(psort_any(_oid_(domain_I_restriction(((restriction *) v82395)))))));
          Update * v88616 = ((Update *) GC_OBJECT(Update,new_object_class(Language._Update)));
          (v88616->selector = _oid_(v82392));
          (v88616->arg = _oid_(Kernel.add));
          { Update * v62357 = v88616; 
            OID  v62358;
            { Call_slot * v88616 = ((Call_slot *) GC_OBJECT(Call_slot,new_object_class(Language._Call_slot)));
              (v88616->selector = ((slot *) v82395));
              (v88616->arg = v64082);
              (v88616->test = CFALSE);
              add_I_property(Kernel.instances,Language._Call_slot,11,_oid_(v88616));
              v62358 = _oid_(v88616);
              } 
            (v62357->var = v62358);} 
          (v88616->value = (*Optimize.c_code)(v82401,
            _oid_(psort_any(_oid_(member_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Kernel.range)(_oid_(v82395))))))))));
          add_I_property(Kernel.instances,Language._Update,11,_oid_(v88616));
          Result = _oid_(v88616);
          } 
        else if ((designated_ask_any(v82400) == CTRUE) && 
            ((v82392->store_ask != CTRUE) && 
                ((v13540->selector == Kernel.add_I) || 
                    (v82392->inverse == (NULL)))))
         { OID  v64082 = GC_OID((*Optimize.c_code)(v82400,
            _oid_(psort_any(_oid_(domain_I_restriction(((restriction *) v82395)))))));
          { OID  v29815;
            { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
              (v88616->selector = Kernel.add);
              { Call * v62360 = v88616; 
                list * v62361;
                { OID v_bag;
                  GC_ANY(v62361= list::empty(Kernel.emptySet));
                  { { Call_slot * v88616 = ((Call_slot *) GC_OBJECT(Call_slot,new_object_class(Language._Call_slot)));
                      (v88616->selector = ((slot *) v82395));
                      (v88616->arg = v64082);
                      (v88616->test = CFALSE);
                      add_I_property(Kernel.instances,Language._Call_slot,11,_oid_(v88616));
                      v_bag = _oid_(v88616);
                      } 
                    GC_OID(v_bag);} 
                  ((list *) v62361)->addFast(v_bag);
                  ((list *) v62361)->addFast(v82401);} 
                (v62360->args = v62361);} 
              add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
              v29815 = _oid_(v88616);
              } 
            Result = (*Optimize.c_code)(v29815);
            } 
          } 
        else { if (Optimize.compiler->optimize_ask == CTRUE)
             { notice_void();
              ;} 
            Result = c_code_method_method1(GC_OBJECT(method,((method *) _at_property1(Kernel.add_I,Kernel._property))),list::alloc(4,_oid_(v82392),
              v82400,
              (*Kernel.index)(_oid_(v82395)),
              v82401),list::alloc(4,_oid_(Kernel._property),
              GC_OID((*Optimize.c_type)(v82400)),
              _oid_(Kernel._integer),
              GC_OID((*Optimize.c_type)(v82401))));
            } 
          } 
      else { list * v52879;
          { { bag *v_list; OID v_val;
              OID v82400,CLcount;
              v_list = GC_OBJECT(list,v13540->args);
               v52879 = v_list->clone();
              for (CLcount= 1; CLcount <= v_list->length; CLcount++)
              { v82400 = (*(v_list))[CLcount];
                v_val = (*Optimize.c_type)(v82400);
                
                (*((list *) v52879))[CLcount] = v_val;} 
              } 
            GC_OBJECT(list,v52879);} 
          Result = c_code_method_method1(GC_OBJECT(method,((method *) _at_property1(Kernel.add,Kernel._property))),GC_OBJECT(list,v13540->args),v52879);
          } 
        } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_add_bag_Call(Call *v13540)
{ GC_BIND;
  { OID Result = 0;
    { OID  v73866 = GC_OID((*Optimize.c_type)(GC_OID((*(v13540->args))[1])));
      ClaireType * v73867 = GC_OBJECT(ClaireType,ptype_type(OBJECT(ClaireType,(*Optimize.c_type)(GC_OID((*(v13540->args))[2])))));
      property * v61571;
      if (((INHERIT(OBJECT(ClaireObject,v73866)->isa,Core._Param)) && 
            (_inf_equal_type(v73867,GC_OBJECT(ClaireType,member_type(OBJECT(ClaireType,v73866)))) == CTRUE)) || 
          (4 <= Optimize.compiler->safety))
       v61571 = Kernel.add_I;
      else v61571 = v13540->selector;
        list * v75833 = list::alloc(2,v73866,_oid_(v73867));
      OID  v82402 = GC_OID(restriction_I_property(v61571,v75833,CTRUE));
      if ((_inf_equal_type(v73867,GC_OBJECT(ClaireType,member_type(OBJECT(ClaireType,v73866)))) != CTRUE) && 
          (v13540->selector == Kernel.add))
       { warn_void();
        tformat_string(CSTRING("the bag addition ~S is poorly typed (~S) [251] \n"),2,list::alloc(2,_oid_(v13540),GC_OID(_oid_(member_type(OBJECT(ClaireType,v73866))))));
        } 
      if (Kernel._method == OWNER(v82402))
       Result = c_code_method_method1(OBJECT(method,v82402),GC_OBJECT(list,v13540->args),v75833);
      else Result = c_warn_Call(v13540,_oid_(v75833));
        } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_delete_Call(Call *v13540)
{ GC_BIND;
  { OID Result = 0;
    { OID  v82392 = GC_OID((*(v13540->args))[1]);
      OID  v82400 = GC_OID((*(v13540->args))[2]);
      OID  v82401 = GC_OID((*(v13540->args))[3]);
      ClaireObject * v82395 = GC_OBJECT(ClaireObject,_at_property1(OBJECT(property,v82392),class_I_type(OBJECT(ClaireType,(*Optimize.c_type)(v82400)))));
      (Optimize.OPT->use_update = CTRUE);
      if ((OBJECT(ClaireRelation,v82392)->inverse == (NULL)) && 
          ((designated_ask_any(v82400) == CTRUE) && 
            ((Kernel._slot == v82395->isa) && ((_inf_equal_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(v82401))),GC_OBJECT(ClaireType,member_type(CLREAD(restriction,v82395,range)))) == CTRUE) || 
                (4 <= Optimize.compiler->safety)))))
       { OID  v64082 = GC_OID((*Optimize.c_code)(v82400,
          _oid_(psort_any(_oid_(domain_I_restriction(((restriction *) v82395)))))));
        { OID  v53840;
          { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
            (v88616->selector = Kernel._delete);
            { Call * v62385 = v88616; 
              list * v62386;
              { OID v_bag;
                GC_ANY(v62386= list::empty(Kernel.emptySet));
                { { Call_slot * v88616 = ((Call_slot *) GC_OBJECT(Call_slot,new_object_class(Language._Call_slot)));
                    (v88616->selector = ((slot *) v82395));
                    (v88616->arg = v64082);
                    (v88616->test = CFALSE);
                    add_I_property(Kernel.instances,Language._Call_slot,11,_oid_(v88616));
                    v_bag = _oid_(v88616);
                    } 
                  GC_OID(v_bag);} 
                ((list *) v62386)->addFast(v_bag);
                ((list *) v62386)->addFast(v82401);} 
              (v62385->args = v62386);} 
            add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
            v53840 = _oid_(v88616);
            } 
          Result = (*Optimize.c_code)(v53840);
          } 
        } 
      else { list * v56723;
          { { bag *v_list; OID v_val;
              OID v82400,CLcount;
              v_list = GC_OBJECT(list,v13540->args);
               v56723 = v_list->clone();
              for (CLcount= 1; CLcount <= v_list->length; CLcount++)
              { v82400 = (*(v_list))[CLcount];
                v_val = (*Optimize.c_type)(v82400);
                
                (*((list *) v56723))[CLcount] = v_val;} 
              } 
            GC_OBJECT(list,v56723);} 
          Result = c_code_method_method1(GC_OBJECT(method,((method *) _at_property1(Kernel._delete,Kernel._property))),GC_OBJECT(list,v13540->args),v56723);
          } 
        } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_not_Select(Select *v82400)
{ GC_BIND;
  { OID Result = 0;
    { OID  v57684;
      { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
        (v88616->selector = Core.NOT);
        { Call * v62389 = v88616; 
          list * v62390;
          { OID v_bag;
            GC_ANY(v62390= list::empty(Kernel.emptySet));
            { { For * v88616 = ((For *) GC_OBJECT(For,new_object_class(Language._For)));
                (v88616->var = v82400->var);
                (v88616->set_arg = v82400->set_arg);
                { Iteration * v62391 = v88616; 
                  OID  v62392;
                  { If * v88616 = ((If *) GC_OBJECT(If,new_object_class(Language._If)));
                    (v88616->test = v82400->arg);
                    { If * v62414 = v88616; 
                      OID  v62415;
                      { Return * v88616 = ((Return *) GC_OBJECT(Return,new_object_class(Language._Return)));
                        (v88616->arg = Kernel.ctrue);
                        add_I_property(Kernel.instances,Language._Return,11,_oid_(v88616));
                        v62415 = _oid_(v88616);
                        } 
                      (v62414->arg = v62415);} 
                    (v88616->other = CNULL);
                    add_I_property(Kernel.instances,Language._If,11,_oid_(v88616));
                    v62392 = _oid_(v88616);
                    } 
                  (v62391->arg = v62392);} 
                add_I_property(Kernel.instances,Language._For,11,_oid_(v88616));
                v_bag = _oid_(v88616);
                } 
              GC_OID(v_bag);} 
            ((list *) v62390)->addFast(v_bag);} 
          (v62389->args = v62390);} 
        add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
        v57684 = _oid_(v88616);
        } 
      Result = (*Optimize.c_code)(v57684);
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_belong_Call(Call *v13540)
{ GC_BIND;
  { OID Result = 0;
    { OID  v82400 = GC_OID((*(v13540->args))[1]);
      OID  v82401 = GC_OID((*(v13540->args))[2]);
      list * v16967 = list::alloc(2,GC_OID((*Optimize.c_type)(v82401)),GC_OID((*Optimize.c_type)(v82400)));
      if (Kernel._set == OWNER(v82401))
       { Or * v88616 = ((Or *) GC_OBJECT(Or,new_object_class(Language._Or)));
        { Or * v62416 = v88616; 
          list * v62417;
          { list * v11307 = list::empty(Kernel.emptySet);
            { OID gc_local;
              ITERATE(v82402);
              bag *v82402_support;
              v82402_support = GC_OBJECT(bag,enumerate_any(v82401));
              for (START(v82402_support); NEXT(v82402);)
              { GC_LOOP;
                { OID  v86514;
                  { { OID  v87475;
                      { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                        (v88616->selector = Kernel._equal);
                        (v88616->args = list::alloc(2,v82400,v82402));
                        add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
                        v87475 = _oid_(v88616);
                        } 
                      v86514 = (*Optimize.c_code)(v87475,
                        _oid_(Kernel._any));
                      } 
                    GC_OID(v86514);} 
                  v11307->addFast(v86514);
                  } 
                GC_UNLOOP;} 
              } 
            v62417 = GC_OBJECT(list,v11307);
            } 
          (v62416->args = v62417);} 
        add_I_property(Kernel.instances,Language._Or,11,_oid_(v88616));
        Result = _oid_(v88616);
        } 
      else if (_inf_equal_type(OBJECT(ClaireType,(*(v16967))[1]),Kernel._list) == CTRUE)
       Result = c_code_method_method1(GC_OBJECT(method,((method *) _at_property2(Kernel.contain_ask,GC_OBJECT(list,list::alloc(2,_oid_(Kernel._list),_oid_(Kernel._any)))))),GC_OBJECT(list,list::alloc(2,v82401,v82400)),v16967);
      else if (_inf_equal_type(OBJECT(ClaireType,(*(v16967))[1]),Kernel._set) == CTRUE)
       Result = c_code_method_method1(GC_OBJECT(method,((method *) _at_property2(Kernel.contain_ask,GC_OBJECT(list,list::alloc(2,_oid_(Kernel._set),_oid_(Kernel._any)))))),GC_OBJECT(list,list::alloc(2,v82401,v82400)),v16967);
      else if (v82401 == _oid_(Kernel._object))
       Result = c_code_method_method1(GC_OBJECT(method,((method *) _at_property2(Kernel._Z,GC_OBJECT(list,list::alloc(2,_oid_(Kernel._any),_oid_(Kernel._class)))))),GC_OBJECT(list,list::alloc(2,v82400,v82401)),GC_OBJECT(list,list::alloc(2,_oid_(Kernel._any),_oid_(Kernel._class))));
      else Result = (*Optimize.member_code)(v82401,
          v82400);
        } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_nth_Call(Call *v13540)
{ GC_BIND;
  { OID Result = 0;
    { list * v82388 = GC_OBJECT(list,v13540->args);
      OID  v82400 = (*(v82388))[1];
      property * v82392 = v13540->selector;
      OID  v82396 = GC_OID((*Optimize.c_type)(v82400));
      ClaireType * v63807 = GC_OBJECT(ClaireType,member_type(OBJECT(ClaireType,v82396)));
      OID  v82394;
      { { list * v88436;
          { { bag *v_list; OID v_val;
              OID v82397,CLcount;
              v_list = v82388;
               v88436 = v_list->clone();
              for (CLcount= 1; CLcount <= v_list->length; CLcount++)
              { v82397 = (*(v_list))[CLcount];
                v_val = (*Optimize.c_type)(v82397);
                
                (*((list *) v88436))[CLcount] = v_val;} 
              } 
            GC_OBJECT(list,v88436);} 
          v82394 = restriction_I_property(v82392,v88436,CTRUE);
          } 
        GC_OID(v82394);} 
      if (contain_ask_set(Optimize.OPT->to_remove,v82400) == CTRUE)
       Result = Core.nil->value;
      else if (((INHERIT(OWNER(v82400),Kernel._table)) && (INHERIT(OWNER(OBJECT(table,v82400)->params),Kernel._integer))) && 
          ((_inf_equal_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)((*(v82388))[2]))),GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Kernel.domain)(v82400)))) == CTRUE) || 
              ((v82392 == Kernel.nth) && 
                  (Optimize.compiler->safety > 2))))
       { Call_table * v88616 = ((Call_table *) GC_OBJECT(Call_table,new_object_class(Language._Call_table)));
        update_property(Kernel.selector,
          v88616,
          2,
          Kernel._object,
          v82400);
        (v88616->arg = (*Optimize.c_code)((*(v82388))[2],
          _oid_(Kernel._integer)));
        (v88616->test = not_any(_oid_(((belong_to(GC_OID((*Kernel.DEFAULT)(v82400)),GC_OID((*Kernel.range)(v82400))) == CTRUE) ? CTRUE : (((*Kernel.DEFAULT)(v82400) == 0) ? CTRUE : ((v82392 == Kernel.get) ? CTRUE : CFALSE))))));
        add_I_property(Kernel.instances,Language._Call_table,11,_oid_(v88616));
        Result = _oid_(v88616);
        } 
      else if (((INHERIT(OWNER(v82400),Kernel._table)) && (INHERIT(OWNER(OBJECT(table,v82400)->params),Kernel._list))) && 
          ((v82388->length == 3) && 
            ((_inf_equal_type(GC_OBJECT(tuple,tuple_I_list(list::alloc(2,GC_OID((*Optimize.c_type)((*(v82388))[2])),GC_OID((*Optimize.c_type)((*(v82388))[3]))))),GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Kernel.domain)(v82400)))) == CTRUE) || 
                (Optimize.compiler->safety > 2))))
       { Call_table * v88616 = ((Call_table *) GC_OBJECT(Call_table,new_object_class(Language._Call_table)));
        update_property(Kernel.selector,
          v88616,
          2,
          Kernel._object,
          v82400);
        { Call_table * v62421 = v88616; 
          OID  v62422;
          { List * v88616 = ((List *) GC_OBJECT(List,new_object_class(Language._List)));
            (v88616->args = list::alloc(2,GC_OID((*Optimize.c_code)((*(v82388))[2],
              _oid_(Kernel._integer))),GC_OID((*Optimize.c_code)((*(v82388))[3],
              _oid_(Kernel._integer)))));
            add_I_property(Kernel.instances,Language._List,11,_oid_(v88616));
            v62422 = _oid_(v88616);
            } 
          (v62421->arg = v62422);} 
        (v88616->test = not_any(_oid_(((belong_to(GC_OID((*Kernel.DEFAULT)(v82400)),GC_OID((*Kernel.range)(v82400))) == CTRUE) ? CTRUE : (((*Kernel.DEFAULT)(v82400) == 0) ? CTRUE : ((v82392 == Kernel.get) ? CTRUE : CFALSE))))));
        add_I_property(Kernel.instances,Language._Call_table,11,_oid_(v88616));
        Result = _oid_(v88616);
        } 
      else if ((_inf_equal_type(OBJECT(ClaireType,v82396),Kernel._array) == CTRUE) && 
          (((v82392 == Kernel.nth_get) || 
              (Optimize.compiler->safety > 2)) && 
            ((_inf_equal_type(v63807,Kernel._float) == CTRUE) || 
                (equal(_oid_(_exp_type(v63807,Kernel._float)),_oid_(Kernel.emptySet)) == CTRUE))))
       { Call_array * v88616 = ((Call_array *) GC_OBJECT(Call_array,new_object_class(Language._Call_array)));
        (v88616->selector = (*Optimize.c_code)(v82400,
          _oid_(Kernel._array)));
        (v88616->arg = (*Optimize.c_code)((*(v82388))[2],
          _oid_(Kernel._integer)));
        (v88616->test = _oid_(v63807));
        add_I_property(Kernel.instances,Language._Call_array,11,_oid_(v88616));
        Result = _oid_(v88616);
        } 
      else if (Kernel._method == OWNER(v82394))
       { if ((Optimize.compiler->optimize_ask == CTRUE) && 
            ((_inf_equal_type(OBJECT(ClaireType,v82396),Kernel._array) == CTRUE) || 
                (_inf_equal_type(OBJECT(ClaireType,v82396),Kernel._table) == CTRUE)))
         { notice_void();
          ;} 
        { list * v91319;
          { { bag *v_list; OID v_val;
              OID v82400,CLcount;
              v_list = GC_OBJECT(list,v13540->args);
               v91319 = v_list->clone();
              for (CLcount= 1; CLcount <= v_list->length; CLcount++)
              { v82400 = (*(v_list))[CLcount];
                v_val = (*Optimize.c_type)(v82400);
                
                (*((list *) v91319))[CLcount] = v_val;} 
              } 
            GC_OBJECT(list,v91319);} 
          Result = c_code_method_method1(OBJECT(method,v82394),GC_OBJECT(list,v13540->args),v91319);
          } 
        } 
      else { list * v112461;
          { { bag *v_list; OID v_val;
              OID v82400,CLcount;
              v_list = GC_OBJECT(list,v13540->args);
               v112461 = v_list->clone();
              for (CLcount= 1; CLcount <= v_list->length; CLcount++)
              { v82400 = (*(v_list))[CLcount];
                v_val = (*Optimize.c_type)(v82400);
                
                (*((list *) v112461))[CLcount] = v_val;} 
              } 
            GC_OBJECT(list,v112461);} 
          Result = c_warn_property(v82392,GC_OBJECT(list,v13540->args),v112461);
          } 
        } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_table_Call(Call *v13540)
{ GC_BIND;
  { OID Result = 0;
    { property * v63989 = v13540->selector;
      table * v82392 = OBJECT(table,(*(v13540->args))[1]);
      OID  v82400 = GC_OID((*(v13540->args))[2]);
      OID  v82401 = GC_OID((*(v13540->args))[3]);
      if (contain_ask_set(Optimize.OPT->to_remove,_oid_(v82392)) == CTRUE)
       Result = Core.nil->value;
      else if ((v63989 == Kernel.put) || 
          (((_inf_equal_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(v82400))),v82392->domain) == CTRUE) || 
                (5 <= Optimize.compiler->safety)) && 
              ((_inf_equal_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(v82401))),v82392->range) == CTRUE) || 
                  (4 <= Optimize.compiler->safety))))
       { if ((Update_ask_relation(v82392,v82400,v82401) == CTRUE) && 
            ((INHERIT(OWNER(v82392->params),Kernel._list)) || 
                (INHERIT(OWNER(v82392->params),Kernel._integer))))
         { OID  v61579 = GC_OID((*Optimize.c_code)(v82400,
            _oid_(Kernel._any)));
          OID  v61588 = GC_OID((*Optimize.c_code)(v82401,
            _oid_(Kernel._any)));
          Update * v88616 = ((Update *) GC_OBJECT(Update,new_object_class(Language._Update)));
          (v88616->selector = _oid_(v82392));
          (v88616->value = v61588);
          { Update * v62446 = v88616; 
            OID  v62447;
            if (v63989 == Kernel.put)
             v62447 = _oid_(Kernel.put);
            else v62447 = v61579;
              (v62446->arg = v62447);} 
          { Update * v62448 = v88616; 
            OID  v62449;
            { Call_table * v88616 = ((Call_table *) GC_OBJECT(Call_table,new_object_class(Language._Call_table)));
              (v88616->selector = v82392);
              (v88616->arg = v61579);
              (v88616->test = CFALSE);
              add_I_property(Kernel.instances,Language._Call_table,11,_oid_(v88616));
              v62449 = _oid_(v88616);
              } 
            (v62448->var = v62449);} 
          add_I_property(Kernel.instances,Language._Update,11,_oid_(v88616));
          Result = _oid_(v88616);
          } 
        else if ((v63989 == Kernel.put) || 
            ((v82392->inverse == (NULL)) && 
                (v82392->if_write == CNULL)))
         { if (Optimize.compiler->optimize_ask == CTRUE)
           { notice_void();
            ;} 
          Result = c_code_method_method1(GC_OBJECT(method,((method *) _at_property1(Kernel.put,Kernel._table))),GC_OBJECT(list,v13540->args),list::alloc(3,_oid_(Kernel._table),
            _oid_(Kernel._any),
            _oid_(Kernel._any)));
          } 
        else Result = c_code_method_method1(GC_OBJECT(method,((method *) _at_property1(Kernel.nth_put,Kernel._table))),GC_OBJECT(list,v13540->args),list::alloc(3,_oid_(Kernel._table),
            _oid_(Kernel._any),
            _oid_(Kernel._any)));
          } 
      else Result = c_code_method_method1(GC_OBJECT(method,((method *) _at_property1(Kernel.nth_equal,Kernel._table))),GC_OBJECT(list,v13540->args),list::alloc(3,_oid_(Kernel._table),
          _oid_(Kernel._any),
          _oid_(Kernel._any)));
        } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_array_Call(Call *v13540)
{ GC_BIND;
  { OID Result = 0;
    { property * v63989 = v13540->selector;
      OID  v82392 = GC_OID((*(v13540->args))[1]);
      OID  v64021 = GC_OID((*Optimize.c_type)(v82392));
      ClaireType * v63807 = GC_OBJECT(ClaireType,member_type(OBJECT(ClaireType,v64021)));
      OID  v82400 = GC_OID((*(v13540->args))[2]);
      OID  v82401 = GC_OID((*(v13540->args))[3]);
      ClaireBoolean * v71214 = ((_inf_equal_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(v82401))),GC_OBJECT(ClaireType,member_type(OBJECT(ClaireType,v64021)))) == CTRUE) ? CTRUE : ((4 <= Optimize.compiler->safety) ? CTRUE : CFALSE));
      if (((v63989 == Kernel.nth_put) || 
            (v71214 == CTRUE)) && 
          ((_inf_equal_type(v63807,Kernel._float) == CTRUE) || 
              (equal(_oid_(_exp_type(v63807,Kernel._float)),_oid_(Kernel.emptySet)) == CTRUE)))
       { OID  v61579 = GC_OID((*Optimize.c_code)(v82400,
          _oid_(Kernel._integer)));
        OID  v61588;
        { { OID  v117266;
            if (_inf_equal_type(v63807,Kernel._float) == CTRUE)
             v117266 = _oid_(Kernel._float);
            else v117266 = _oid_(Kernel._any);
              v61588 = (*Optimize.c_code)(v82401,
              v117266);
            } 
          GC_OID(v61588);} 
        Update * v88616 = ((Update *) GC_OBJECT(Update,new_object_class(Language._Update)));
        (v88616->selector = v82392);
        (v88616->value = v61588);
        (v88616->arg = _oid_(Kernel.put));
        { Update * v62451 = v88616; 
          OID  v62452;
          { Call_array * v88616 = ((Call_array *) GC_OBJECT(Call_array,new_object_class(Language._Call_array)));
            (v88616->selector = (*Optimize.c_code)(v82392,
              _oid_(Kernel._array)));
            (v88616->arg = v61579);
            (v88616->test = _oid_(v63807));
            add_I_property(Kernel.instances,Language._Call_array,11,_oid_(v88616));
            v62452 = _oid_(v88616);
            } 
          (v62451->var = v62452);} 
        add_I_property(Kernel.instances,Language._Update,11,_oid_(v88616));
        Result = _oid_(v88616);
        } 
      else { if (Optimize.compiler->optimize_ask == CTRUE)
           { notice_void();
            ;} 
          Result = c_code_method_method1(GC_OBJECT(method,((method *) _at_property1(((v71214 == CTRUE) ?
            Kernel.nth_put :
            v63989 ),Kernel._array))),GC_OBJECT(list,v13540->args),list::alloc(3,v64021,
            _oid_(Kernel._any),
            _oid_(Kernel._any)));
          } 
        } 
    GC_UNBIND; return (Result);} 
  } 

ClaireBoolean * Update_ask_relation(ClaireRelation *v82392,OID v82400,OID v82401)
{ GC_BIND;
  { ClaireBoolean *Result ;
    Result = ((v82392 != Kernel.inverse) ? ((((((v82392->if_write == CNULL) ? CTRUE : CFALSE) != CTRUE) && 
          (inherit_ask_class(OWNER(v82392->if_write),Kernel._list) != CTRUE)) || 
        ((v82392->inverse == (NULL)) && 
            (((INHERIT(v82392->isa,Kernel._table)) ? (INHERIT(OWNER(CLREAD(table,v82392,params)),Kernel._integer)) : (CTRUE == CTRUE)) && 
              ((v82392->store_ask == CTRUE) ? ((designated_ask_any(v82400) == CTRUE) && 
                  ((designated_ask_any(v82401) == CTRUE) && 
                    ((multi_ask_any(_oid_(v82392)) != CTRUE) && 
                      ((identifiable_ask_any(v82401) == CTRUE) || 
                          (_inf_equal_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(v82401))),Kernel._float) == CTRUE))))) : (CTRUE == CTRUE))))) ? CTRUE: CFALSE): CFALSE);
    GC_UNBIND; return (Result);} 
  } 

ClaireBoolean * Update_ask_relation2(ClaireRelation *v82392,ClaireRelation *v82395)
{ return (((((v82392->if_write == CNULL) ? CTRUE : CFALSE) != CTRUE) ? ((inherit_ask_class(OWNER(v82392->if_write),Kernel._list) != CTRUE) ? ((v82395 == Kernel.add) ? CTRUE: CFALSE): CFALSE): CFALSE));} 

ClaireType * c_type_Update_Optimize(Update *v13540)
{ return (Kernel._void);} 

OID  c_code_method_method1(method *v13540,list *v82388,list *v16967)
{ return (c_code_method_method2(v13540,v82388,v16967,c_srange_method(v13540)));} 

OID  c_code_method_method2(method *v13540,list *v82388,list *v16967,ClaireClass *v63997)
{ GC_BIND;
  { OID Result = 0;
    if ((v13540->module_I != claire.it) || 
        ((Optimize.compiler->safety > 4) || 
          (((v13540->functional == (NULL)) ? CTRUE : CFALSE) != CTRUE)))
     { list * v63760 = v13540->domain;
      Cint  v82390 = v63760->length;
      if (v82390 != v82388->length)
       { { list * v12141;
          { list * v40090 = list::empty(Kernel.emptySet);
            { Cint  v82385 = 1;
              Cint  v62453 = (v82390-1);
              { OID gc_local;
                while ((v82385 <= v62453))
                { v40090->addFast((*(v82388))[v82385]);
                  ++v82385;
                  } 
                } 
              } 
            v12141 = GC_OBJECT(list,v40090);
            } 
          OID  v13102;
          { list * v70730;{ list * v40090 = list::empty(Kernel.emptySet);
              { Cint  v82385 = v82390;
                Cint  v62454 = v82388->length;
                { OID gc_local;
                  while ((v82385 <= v62454))
                  { v40090->addFast((*(v82388))[v82385]);
                    ++v82385;
                    } 
                  } 
                } 
              v70730 = GC_OBJECT(list,v40090);
              } 
            
            v13102=_oid_(v70730);} 
          v82388 = v12141->addFast(v13102);
          } 
        GC_OBJECT(list,v82388);} 
      if ((v13540->inline_ask == CTRUE) && 
          (c_inline_ask_method(v13540,v82388) == CTRUE))
       Result = c_inline_method1(v13540,v82388,v63997);
      else { ClaireBoolean * v82378 = Optimize.OPT->allocation;
          OID  v82400 = Core.nil->value;
          (Optimize.OPT->allocation = CFALSE);
          { { list * v15024;
              { list * v40090 = list::empty(Kernel.emptySet);
                { Cint  v82385 = 1;
                  Cint  v62476 = v82390;
                  { OID gc_local;
                    while ((v82385 <= v62476))
                    { GC_LOOP;
                      v40090->addFast(GC_OID(c_strict_code_any((*(v82388))[v82385],psort_any((*(v63760))[v82385]))));
                      ++v82385;
                      GC_UNLOOP;} 
                    } 
                  } 
                v15024 = GC_OBJECT(list,v40090);
                } 
              v82400 = Call_method_I_method(v13540,v15024);
              } 
            GC_OID(v82400);} 
          if (Optimize.OPT->allocation != CTRUE)
           (Optimize.OPT->allocation = v82378);
          Result = v82400;
          } 
        } 
    else { if (Optimize.compiler->optimize_ask == CTRUE)
         { notice_void();
          ;} 
        Result = _oid_(open_message_property(v13540->selector,v82388));
        } 
      GC_UNBIND; return (Result);} 
  } 

OID  Call_method_I_method(method *v13540,list *v24826)
{ GC_BIND;
  if (BCONTAIN(status_I_restriction(v13540),1))
   { (Optimize.OPT->allocation = CTRUE);
    if (nth_integer(v13540->status,6) != CTRUE)
     { { bag *v_list; OID v_val;
        OID v82400,CLcount;
        v_list = v24826;
         v24826 = v_list->clone();
        for (CLcount= 1; CLcount <= v_list->length; CLcount++)
        { v82400 = (*(v_list))[CLcount];
          v_val = c_gc_I_any1(v82400);
          
          (*((list *) v24826))[CLcount] = v_val;} 
        } 
      GC_OBJECT(list,v24826);} 
    } 
  else { ClaireBoolean * g0145I;
    { ClaireBoolean *v_and;
      { v_and = Optimize.OPT->allocation;
        if (v_and == CFALSE) g0145I =CFALSE; 
        else { { Cint  v16946;
            { list * v17907;
              { bag * v25572 = v24826;
                list * v12399 = ((list *) empty_bag(v25572));
                { ITERATE(v82400);
                  for (START(v25572); NEXT(v82400);)
                  if ((OBJECT(ClaireBoolean,(*Optimize.c_gc_ask)(v82400))) == CTRUE)
                   v12399->addFast(v82400);
                  } 
                v17907 = GC_OBJECT(list,v12399);
                } 
              v16946 = v17907->length;
              } 
            v_and = ((v16946 > 1) ? CTRUE : CFALSE);
            } 
          if (v_and == CFALSE) g0145I =CFALSE; 
          else g0145I = CTRUE;} 
        } 
      } 
    
    if (g0145I == CTRUE) { { bag *v_list; OID v_val;
          OID v82400,CLcount;
          v_list = v24826;
           v24826 = v_list->clone();
          for (CLcount= 1; CLcount <= v_list->length; CLcount++)
          { v82400 = (*(v_list))[CLcount];
            v_val = c_gc_I_any1(v82400);
            
            (*((list *) v24826))[CLcount] = v_val;} 
          } 
        GC_OBJECT(list,v24826);} 
      } 
  if (BCONTAIN(v13540->status,2))
   (Optimize.OPT->use_nth_equal = CTRUE);
  if (BCONTAIN(v13540->status,7))
   (Optimize.OPT->use_string_update = CTRUE);
  if (BCONTAIN(v13540->status,3))
   (Optimize.OPT->use_update = CTRUE);
  if (legal_ask_module(v13540->module_I,_oid_(v13540)) != CTRUE)
   tformat_string(CSTRING("in call ~S~S\n"),0,list::alloc(2,_oid_(v13540->selector),_oid_(v24826)));
  { OID Result = 0;
    if (v24826->length == 1)
     { Call_method1 * v88616 = ((Call_method1 *) GC_OBJECT(Call_method1,new_object_class(Language._Call_method1)));
      (v88616->arg = v13540);
      (v88616->args = v24826);
      add_I_property(Kernel.instances,Language._Call_method1,11,_oid_(v88616));
      Result = _oid_(v88616);
      } 
    else if (v24826->length == 2)
     { Call_method2 * v88616 = ((Call_method2 *) GC_OBJECT(Call_method2,new_object_class(Language._Call_method2)));
      (v88616->arg = v13540);
      (v88616->args = v24826);
      add_I_property(Kernel.instances,Language._Call_method2,11,_oid_(v88616));
      Result = _oid_(v88616);
      } 
    else { Call_method * v88616 = ((Call_method *) GC_OBJECT(Call_method,new_object_class(Language._Call_method)));
        (v88616->arg = v13540);
        (v88616->args = v24826);
        add_I_property(Kernel.instances,Language._Call_method,11,_oid_(v88616));
        Result = _oid_(v88616);
        } 
      GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_Call_method_Optimize(Call_method *v13540)
{ GC_BIND;
  { ClaireType *Result ;
    { list * v18868;
      { { bag *v_list; OID v_val;
          OID v82400,CLcount;
          v_list = GC_OBJECT(list,v13540->args);
           v18868 = v_list->clone();
          for (CLcount= 1; CLcount <= v_list->length; CLcount++)
          { v82400 = (*(v_list))[CLcount];
            v_val = (*Optimize.c_type)(v82400);
            
            (*((list *) v18868))[CLcount] = v_val;} 
          } 
        GC_OBJECT(list,v18868);} 
      Result = use_range_method(v13540->arg,v18868);
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_Call_method_Optimize(Call_method *v13540)
{ return (_oid_(v13540));} 

ClaireBoolean * c_gc_ask_Call_method(Call_method *v13540)
{ GC_BIND;
  { ClaireBoolean *Result ;
    { method * v82389 = v13540->arg;
      { ClaireBoolean *v_and;
        { v_and = not_any(_oid_((INHERIT(v82389->range->isa,Kernel._class) ? (ClaireObject *) gcsafe_ask_class((ClaireClass *) OBJECT(ClaireClass,_oid_(v82389->range))) :  (ClaireObject *)  gcsafe_ask_type((ClaireType *) OBJECT(ClaireType,_oid_(v82389->range))))));
          if (v_and == CFALSE) Result =CFALSE; 
          else { v_and = ((v82389->range != Kernel._float) ? CTRUE : CFALSE);
            if (v_and == CFALSE) Result =CFALSE; 
            else { v_and = ((nth_integer(status_I_restriction(v82389),5) != CTRUE) ? CTRUE : ((((_inf_equal_type(v82389->range,Kernel._bag) == CTRUE) ? ((Optimize.OPT->loop_gc == CTRUE) ? CTRUE: CFALSE): CFALSE) != CTRUE) ? CTRUE : CFALSE));
              if (v_and == CFALSE) Result =CFALSE; 
              else { { ClaireBoolean *v_or;
                  { v_or = not_any(_oid_(nth_integer(status_I_restriction(v82389),4)));
                    if (v_or == CTRUE) v_and =CTRUE; 
                    else { { ClaireBoolean *v_or1;
                        { v_or1 = nth_integer(status_I_restriction(v82389),1);
                          if (v_or1 == CTRUE) v_or =CTRUE; 
                          else { { OID  v19829;
                              { OID gc_local;
                                ITERATE(v82400);
                                v19829= Kernel.cfalse;
                                bag *v82400_support;
                                v82400_support = GC_OBJECT(list,v13540->args);
                                for (START(v82400_support); NEXT(v82400);)
                                if ((OBJECT(ClaireBoolean,(*Optimize.c_gc_ask)(v82400))) == CTRUE)
                                 { v19829 = Kernel.ctrue;
                                  break;} 
                                } 
                              v_or1 = boolean_I_any(v19829);
                              } 
                            if (v_or1 == CTRUE) v_or =CTRUE; 
                            else v_or = CFALSE;} 
                          } 
                        } 
                      if (v_or == CTRUE) v_and =CTRUE; 
                      else v_and = CFALSE;} 
                    } 
                  } 
                if (v_and == CFALSE) Result =CFALSE; 
                else Result = CTRUE;} 
              } 
            } 
          } 
        } 
      } 
    GC_UNBIND; return (Result);} 
  } 

ClaireFunction * functional_I_method_Optimize(method *v13540)
{ GC_BIND;
  { ClaireFunction *Result ;
    { OID  v82382 = GC_OID(get_property(Kernel.functional,v13540));
      property * v82392 = v13540->selector;
      Result = ((INHERIT(OWNER(v82382),Kernel._function)) ?
        OBJECT(ClaireFunction,v82382) :
        make_function_string(string_v((*Optimize.function_name)(_oid_(v82392),
          _oid_(v13540->domain),
          v82382))) );
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  nth_type_check_type(ClaireType *v64016,ClaireType *v64013,ClaireType *v64028)
{ GC_BIND;
  if (_inf_equal_type(v64028,GC_OBJECT(ClaireType,member_type(v64016))) != CTRUE)
   { warn_void();
    tformat_string(CSTRING("unsafe update on bag: type ~S into ~S [252]\n"),2,list::alloc(2,_oid_(v64028),_oid_(v64016)));
    } 
  { OID Result = 0;
    Result = _oid_(v64028);
    GC_UNBIND; return (Result);} 
  } 

ClaireBoolean * c_inline_ask_method(method *v13540,list *v82388)
{ GC_BIND;
  { ClaireBoolean *Result ;
    { lambda * v82382 = GC_OBJECT(lambda,v13540->formula);
      list * v63757 = GC_OBJECT(list,v82382->vars);
      OID  v82400 = GC_OID(v82382->body);
      Cint  v82390 = 1;
      { OID  v40971;
        { OID gc_local;
          ITERATE(v82398);
          v40971= Kernel.cfalse;
          bag *v82398_support;
          v82398_support = GC_OBJECT(list,v82382->vars);
          for (START(v82398_support); NEXT(v82398);)
          if ((occurrence_any(v82400,OBJECT(Variable,v82398)) > 1) && 
              ((designated_ask_any((*(v82388))[v82390]) != CTRUE) && 
                (inherit_ask_class(owner_any((*Kernel.range)(v82398)),Optimize._Pattern) != CTRUE)))
           { v40971 = Kernel.ctrue;
            break;} 
          else ++v82390;
            } 
        Result = not_any(v40971);
        } 
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  inline_optimize_ask_Call(Call *v13540)
{ GC_BIND;
  { OID Result = 0;
    { list * v82388 = GC_OBJECT(list,v13540->args);
      OID  v82389;
      { { list * v41932;
          { { bag *v_list; OID v_val;
              OID v82400,CLcount;
              v_list = v82388;
               v41932 = v_list->clone();
              for (CLcount= 1; CLcount <= v_list->length; CLcount++)
              { v82400 = (*(v_list))[CLcount];
                v_val = _oid_(set::alloc(1,v82400));
                
                (*((list *) v41932))[CLcount] = v_val;} 
              } 
            GC_OBJECT(list,v41932);} 
          v82389 = restriction_I_property(v13540->selector,v41932,CTRUE);
          } 
        GC_OID(v82389);} 
      if (Kernel._method == OWNER(v82389))
       { { ClaireBoolean * g0152I;
          { ClaireBoolean *v_and;
            { v_and = OBJECT(method,v82389)->inline_ask;
              if (v_and == CFALSE) g0152I =CFALSE; 
              else { { OID  v43854;
                  { ITERATE(v82395);
                    v43854= Kernel.cfalse;
                    for (START(OBJECT(restriction,v82389)->domain); NEXT(v82395);)
                    if (INHERIT(OBJECT(ClaireObject,v82395)->isa,Optimize._Pattern))
                     { v43854 = Kernel.ctrue;
                      break;} 
                    } 
                  v_and = boolean_I_any(v43854);
                  } 
                if (v_and == CFALSE) g0152I =CFALSE; 
                else { v_and = c_inline_ask_method(OBJECT(method,v82389),v82388);
                  if (v_and == CFALSE) g0152I =CFALSE; 
                  else g0152I = CTRUE;} 
                } 
              } 
            } 
          
          if (g0152I == CTRUE) Result = v82389;
            else Result = Kernel.cfalse;
          } 
        } 
      else Result = Kernel.cfalse;
        } 
    GC_UNBIND; return (Result);} 
  } 

