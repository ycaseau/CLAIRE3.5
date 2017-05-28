/***** CLAIRE Compilation of file e:\claire\v3.5\src\compile\ocall.cl 
         [version 3.5.0 / safety 5] Sun May 28 08:25:59 2017 *****/

#include <claire.h>
#include <Kernel.h>
#include <Core.h>
#include <Language.h>
#include <Reader.h>
#include <Optimize.h>
OID  restriction_I_property(property *v9332,list *v15428,ClaireBoolean *v3787)
{ { Cint  v15425 = 1;
    Cint  v15039 = v15428->length;
    { while ((v15425 <= v15039))
      { ((*(v15428))[v15425]=_oid_(ptype_type(OBJECT(ClaireType,(*(v15428))[v15425]))));
        ++v15425;
        } 
      } 
    } 
  return (restriction_I_list(v9332->definition,v15428,v3787));} 

OID  restriction_I_list(list *v3246,list *v15428,ClaireBoolean *v3787)
{ GC_RESERVE(1);  // HOHO v3.0.55 optim !
  ;{ OID Result = 0;
    { ClaireBoolean * v8652 = ((class_I_type(OBJECT(ClaireType,(*(v15428))[1]))->open == 3) ? CTRUE : CFALSE);
      OID  v7797 = _oid_(Kernel.emptySet);
      { OID gc_local;
        ITERATE(v15434);
        for (START(v3246); NEXT(v15434);)
        { GC_LOOP;
          if ((boolean_I_any(v7797) != CTRUE) && 
              (tmatch_ask_list(v15428,OBJECT(restriction,v15434)->domain) == CTRUE))
           { if (v3787 == CTRUE)
             GC__OID(v7797 = v15434, 1);
            else v7797= _oid_(OBJECT(restriction,v15434)->range);
              { ;break;} 
            } 
          else if (length_bag(_exp_list(OBJECT(restriction,v15434)->domain,v15428)) != 0)
           { if (v3787 != CTRUE)
             { GC__OID(v7797 = _oid_(U_type(OBJECT(ClaireType,v7797),OBJECT(restriction,v15434)->range)), 1);
              } 
            else if ((Optimize.compiler->safety <= 3) || 
                ((equal(v7797,_oid_(Kernel.emptySet)) != CTRUE) || 
                  (v8652 == CTRUE)))
             { v7797= _oid_(Optimize.ambiguous);
              { ;break;} 
              } 
            else GC__OID(v7797 = v15434, 1);
              } 
          GC_UNLOOP;} 
        } 
      Result = v7797;
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  restriction_I_class(ClaireClass *v15419,list *v3246,list *v15428)
{ if (Optimize.compiler->safety > 3)
   ((*(v15428))[1]=_oid_(_exp_type(v15419,OBJECT(ClaireType,(*(v15428))[1]))));
  { OID Result = 0;
    { ITERATE(v15434);
      Result= Kernel.cfalse;
      for (START(v3246); NEXT(v15434);)
      if (_inf_equalt_class(v15419,OBJECT(ClaireType,(*(OBJECT(restriction,v15434)->domain))[1])) == CTRUE)
       { if (tmatch_ask_list(v15428,OBJECT(restriction,v15434)->domain) == CTRUE)
         { Result = v15434;
          break;} 
        else if (length_bag(_exp_list(OBJECT(restriction,v15434)->domain,v15428)) != 0)
         { Result = _oid_(Optimize.ambiguous);
          break;} 
        } 
      } 
    return (Result);} 
  } 

ClaireType * use_range_method(method *v9332,list *v1039)
{ GC_BIND;
  { ClaireType *Result ;
    if ((v9332->inline_ask == CTRUE) && 
        (v9332->typing == CNULL))
     { list * v3250 = GC_OBJECT(list,v9332->formula->vars);
      ClaireType * v1047 = Kernel._any;
      list * v15875;
      { { bag *v_list; OID v_val;
          OID v15438,CLcount;
          v_list = v3250;
           v15875 = v_list->clone();
          for (CLcount= 1; CLcount <= v_list->length; CLcount++)
          { v15438 = (*(v_list))[CLcount];
            v_val = (*Kernel.range)(v15438);
            
            (*((list *) v15875))[CLcount] = v_val;} 
          } 
        GC_OBJECT(list,v15875);} 
      { ITERATE(v15438);
        for (START(v3250); NEXT(v15438);)
        put_property2(Kernel.range,OBJECT(ClaireObject,v15438),(*(v1039))[(((*Kernel.index)(v15438))+1)]);
        } 
      v1047= GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(GC_OID(v9332->formula->body))));
      { ITERATE(v15438);
        for (START(v3250); NEXT(v15438);)
        put_property2(Kernel.range,OBJECT(ClaireObject,v15438),(*(v15875))[(((*Kernel.index)(v15438))+1)]);
        } 
      if (INHERIT(v9332->range->isa,Kernel._type))
       v1047= GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Kernel._exp)(_oid_(v1047),
        _oid_(v9332->range))));
      if (boolean_I_any(_oid_(v1047)) != CTRUE)
       (*Optimize.Cerror)(_string_(CSTRING("[207] inline ~S: range ~S is incompatible with ~S (inferred)")),
        _oid_(v9332),
        _oid_(v9332->range),
        GC_OID((*Optimize.c_type)(GC_OID(v9332->formula->body))));
      Result = v1047;
      } 
    else { { OID  v15422 = GC_OID(v9332->typing);
          list * v15875;
          { { bag *v_list; OID v_val;
              OID v15437,CLcount;
              v_list = v1039;
               v15875 = v_list->clone(Kernel._type);
              for (CLcount= 1; CLcount <= v_list->length; CLcount++)
              { v15437 = (*(v_list))[CLcount];
                v_val = _oid_(ptype_type(OBJECT(ClaireType,v15437)));
                
                (*((list *) v15875))[CLcount] = v_val;} 
              } 
            GC_OBJECT(list,v15875);} 
          ClaireType * v16122 = v9332->range;
          ClaireType * v16123;
          { { ClaireObject *V_CC ;
              { ClaireHandler c_handle = ClaireHandler();
                if ERROR_IN 
                { if (INHERIT(OWNER(v15422),Core._lambda))
                   V_CC = OBJECT(ClaireType,apply_lambda(OBJECT(lambda,v15422),v15875));
                  else if (INHERIT(OWNER(v15422),Kernel._property))
                   V_CC = OBJECT(ClaireType,apply_property(OBJECT(property,v15422),v15875));
                  else if (INHERIT(OWNER(v15422),Kernel._function))
                   { OID v7538;{ list * v5472;
                      { list * v5263 = list::empty(Kernel.emptySet);
                        { Cint  v15431 = 1;
                          Cint  v15040 = (v1039->length+1);
                          { while ((v15431 <= v15040))
                            { v5263->addFast(_oid_(Kernel._object));
                              ++v15431;
                              } 
                            } 
                          } 
                        v5472 = GC_OBJECT(list,v5263);
                        } 
                      v7538 = apply_function(OBJECT(ClaireFunction,v15422),v5472,v15875);
                      } 
                    
                    V_CC=OBJECT(ClaireType,v7538);} 
                  else V_CC = v16122;
                    ClEnv->cHandle--;} 
                else if (belong_to(_oid_(ClEnv->exception_I),_oid_(Kernel._any)) == CTRUE)
                { c_handle.catchIt();{ tformat_string(CSTRING("~S's 2nd-order type failed on ~S \n"),0,list::alloc(2,_oid_(v9332),_oid_(v1039)));
                    V_CC = v16122;
                    } 
                  } 
                else PREVIOUS_HANDLER;} 
              v16123= (ClaireType *) V_CC;} 
            GC_OBJECT(ClaireType,v16123);} 
          if ((boolean_I_any(sort_equal_class(osort_any(_oid_(v16122)),osort_any(_oid_(v16123)))) == CTRUE) || 
              (v9332->selector == Core.externC))
           Result = v16123;
          else if (boolean_I_any(sort_equal_class(Kernel._any,osort_any(_oid_(v16122)))) == CTRUE)
           { Union * v10264 = ((Union *) GC_OBJECT(Union,new_object_class(Core._Union)));
            (v10264->t1 = Kernel._any);
            (v10264->t2 = v16123);
            Result = v10264;
            } 
          else Result = v16122;
            } 
        } 
      GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_Call_Optimize(Call *v9332)
{ GC_BIND;
  { ClaireType *Result ;
    { ClaireObject *V_CC ;
      if (v9332->selector == Language.function_I)
       V_CC = Kernel._function;
      else { property * v15435 = v9332->selector;
          list * v15428 = GC_OBJECT(list,v9332->args);
          list * v1207;
          { { bag *v_list; OID v_val;
              OID v15440,CLcount;
              v_list = v15428;
               v1207 = v_list->clone();
              for (CLcount= 1; CLcount <= v_list->length; CLcount++)
              { v15440 = (*(v_list))[CLcount];
                v_val = (*Optimize.c_type)(v15440);
                
                (*((list *) v1207))[CLcount] = v_val;} 
              } 
            GC_OBJECT(list,v1207);} 
          if (v15435 == Optimize.safe)
           V_CC = OBJECT(ClaireType,(*(v1207))[1]);
          else if ((v15435 == Core.externC) && 
              ((v15428->length == 2) && 
                (INHERIT(OWNER((*(v15428))[2]),Kernel._class))))
           V_CC = OBJECT(ClaireClass,(*(v15428))[2]);
          else if ((v15435 == Core.NEW) && 
              (INHERIT(OWNER((*(v15428))[1]),Kernel._class)))
           V_CC = OBJECT(ClaireClass,(*(v15428))[1]);
          else if ((v15435 == Core.check_in) && 
              (INHERIT(OWNER((*(v15428))[2]),Kernel._type)))
           { V_CC = ((v15428->length == 2) ?
              sort_abstract_I_type(OBJECT(ClaireType,(*(v15428))[2])) :
              OBJECT(ClaireType,(*(v15428))[2]) );
            } 
          else if ((v15435 == Kernel.nth) && 
              (_inf_equal_type(OBJECT(ClaireType,(*(v1207))[1]),Kernel._array) == CTRUE))
           { if (_inf_equal_type(GC_OBJECT(ClaireType,member_type(OBJECT(ClaireType,(*(v1207))[1]))),Kernel._float) == CTRUE)
             V_CC = Kernel._float;
            else V_CC = member_type(OBJECT(ClaireType,(*(v1207))[1]));
              } 
          else if ((v15435 == Core._at) && 
              (INHERIT(OWNER((*(v15428))[1]),Kernel._property)))
           { property * v15432 = OBJECT(property,(*(v15428))[1]);
            OID  v15419 = (*(v15428))[2];
            if ((INHERIT(OWNER(v15419),Kernel._class)) && 
                (Kernel._method == owner_any((*Core._at)(_oid_(v15432),
                  v15419))))
             V_CC = set::alloc(1,GC_OID((*Core._at)(_oid_(v15432),
              v15419)));
            else V_CC = Kernel._any;
              } 
          else if ((v15435 == Kernel.get) && 
              (INHERIT(OWNER((*(v15428))[1]),Kernel._relation)))
           { ClaireRelation * v15434 = OBJECT(ClaireRelation,(*(v15428))[1]);
            if (INHERIT(v15434->isa,Kernel._property))
             { ClaireObject * v3619 = GC_OBJECT(ClaireObject,_at_property1(((property *) v15434),class_I_type(OBJECT(ClaireType,(*(v1207))[2]))));
              if (Kernel._slot == v3619->isa)
               { if ((_inf_equal_type(CLREAD(restriction,v3619,range),Kernel._bag) == CTRUE) && 
                    (Optimize.compiler->safety < 3))
                 V_CC = class_I_type(OBJECT(ClaireType,(*Kernel.range)((*(v15428))[2])));
                else V_CC = ((belong_to(CLREAD(slot,v3619,DEFAULT),_oid_(CLREAD(restriction,v3619,range))) == CTRUE) ?
                  CLREAD(restriction,v3619,range) :
                  extends_type(CLREAD(restriction,v3619,range)) );
                } 
              else V_CC = v15434->range;
                } 
            else if (INHERIT(v15434->isa,Kernel._table))
             { V_CC = ((belong_to(CLREAD(table,v15434,DEFAULT),_oid_(v15434->range)) == CTRUE) ?
                v15434->range :
                extends_type(v15434->range) );
              } 
            else V_CC = CFALSE;
              } 
          else { OID  v15434 = GC_OID(restriction_I_property(v15435,v1207,CTRUE));
              if (Kernel._slot == OWNER(v15434))
               { if ((v15435 == Kernel.instances) && 
                    (INHERIT(OWNER((*(v15428))[1]),Kernel._class)))
                 { Param * v10264 = ((Param *) GC_OBJECT(Param,new_object_class(Core._Param)));
                  (v10264->arg = Kernel._list);
                  (v10264->params = list::alloc(1,_oid_(Kernel.of)));
                  (v10264->args = list::alloc(1,_oid_(set::alloc(1,(*(v15428))[1]))));
                  V_CC = v10264;
                  } 
                else V_CC = OBJECT(restriction,v15434)->range;
                  } 
              else if (Kernel._method == OWNER(v15434))
               V_CC = use_range_method(OBJECT(method,v15434),v1207);
              else if (boolean_I_any(_oid_(v15435->restrictions)) != CTRUE)
               V_CC = selector_psort_Call(v9332);
              else V_CC = (((v15435->open == 3) || 
                  (v15434 != _oid_(Optimize.ambiguous))) ?
                sort_abstract_I_type(v15435->range) :
                sort_abstract_I_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,restriction_I_property(v15435,v1207,CFALSE)))) );
              } 
            } 
        Result= (ClaireType *) V_CC;} 
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_Call_Optimize(Call *v9332)
{ return (c_code_call_Call(v9332,Kernel._void));} 

OID  c_code_call_Call(Call *v9332,ClaireClass *v3469)
{ GC_BIND;
  ;{ OID Result = 0;
    { property * v15435 = v9332->selector;
      list * v15428 = GC_OBJECT(list,v9332->args);
      if ((INHERIT(OWNER((*(v15428))[1]),Core._global_variable)) && 
          ((equal((*Kernel.range)((*(v15428))[1]),_oid_(Kernel.emptySet)) == CTRUE) && 
            (designated_ask_any(GC_OID((*Kernel.value)((*(v15428))[1]))) == CTRUE)))
       ((*(v15428))[1]=(*Kernel.value)((*(v15428))[1]));
      { OID  v15429 = GC_OID(inline_optimize_ask_Call(v9332));
        ClaireBoolean * v15418 = inherit_ask_class(OWNER((*(v15428))[1]),Kernel._property);
        OID  v15420 = GC_OID(daccess_any(_oid_(v9332),_sup_integer(Optimize.compiler->safety,5)));
        if ((v15418 == CTRUE) && 
            (((v15435 == Kernel.put) || 
                (v15435 == Core.write)) && 
              (v15428->length == 3)))
         Result = c_code_write_Call(v9332);
        else if ((v15418 == CTRUE) && 
            ((v15435 == Core.put_store) && 
              ((v15428->length == 4) && 
                ((*(v15428))[4] == Kernel.ctrue))))
         Result = c_code_write_Call(v9332);
        else if ((v15418 == CTRUE) && 
            (v15435 == Core.unknown_ask))
         Result = c_code_hold_property(OBJECT(property,(*(v15428))[1]),(*(v15428))[2],CNULL,CTRUE);
        else if ((v15418 == CTRUE) && 
            (v15435 == Core.known_ask))
         Result = c_code_hold_property(OBJECT(property,(*(v15428))[1]),(*(v15428))[2],CNULL,CFALSE);
        else if ((v15418 == CTRUE) && 
            ((v15435 == Core.erase) && 
              (INHERIT(OWNER((*(v15428))[2]),Language._Variable))))
         Result = (*Optimize.c_code)(GC_OID(Produce_erase_property2(OBJECT(property,(*(v15428))[1]),OBJECT(Variable,(*(v15428))[2]))),
          _oid_(v3469));
        else if (v15435 == Optimize.safe)
         { Cint  v15441 = Optimize.compiler->safety;
          ClaireBoolean * v15418 = Optimize.compiler->overflow_ask;
          OID  v15440 = CNULL;
          (Optimize.compiler->safety = 1);
          (Optimize.compiler->overflow_ask = CTRUE);
          { { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
              (v10264->selector = Optimize.safe);
              (v10264->args = list::alloc(1,GC_OID((*Optimize.c_code)((*(v15428))[1],
                _oid_(v3469)))));
              add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
              v15440 = _oid_(v10264);
              } 
            GC_OID(v15440);} 
          (Optimize.compiler->safety = v15441);
          (Optimize.compiler->overflow_ask = v15418);
          Result = v15440;
          } 
        else if (((v15435 == Kernel.add) || 
              (v15435 == Kernel.add_I)) && 
            (v15418 == CTRUE))
         Result = c_code_add_Call(v9332);
        else if (((v15435 == Kernel.add) || 
              (v15435 == Kernel.add_I)) && 
            (_inf_equal_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)((*(v15428))[1]))),Kernel._bag) == CTRUE))
         Result = c_code_add_bag_Call(v9332);
        else if ((v15418 == CTRUE) && 
            (v15435 == Kernel._delete))
         Result = c_code_delete_Call(v9332);
        else if ((contain_ask_set(Optimize.OPT->to_remove,_oid_(v15435)) == CTRUE) || 
            ((v15435 == Optimize.c_interface) && 
                ((v15428->length == 2) && 
                  (contain_ask_set(Optimize.OPT->legal_modules,get_module_object(v15435)) != CTRUE))))
         Result = Core.nil->value;
        else if (v15420 != CNULL)
         Result = v15420;
        else if (Kernel._method == OWNER(v15429))
         Result = c_inline_method1(OBJECT(method,v15429),v15428,c_srange_method(OBJECT(method,v15429)));
        else if (((v15435 == Kernel._equal) || 
              (v15435 == Core._I_equal)) && 
            (daccess_any((*(v15428))[1],CTRUE) != CNULL))
         Result = c_code_hold_property(OBJECT(property,(*(OBJECT(bag,(*Core.args)((*(v15428))[1]))))[1]),GC_OID((*(OBJECT(bag,(*Core.args)((*(v15428))[1]))))[2]),(*(v15428))[2],equal(_oid_(v15435),_oid_(Kernel._equal)));
        else if (((v15435 == Kernel._equal) || 
              (v15435 == Core._I_equal)) && 
            (daccess_any((*(v15428))[2],CTRUE) != CNULL))
         Result = c_code_hold_property(OBJECT(property,(*(OBJECT(bag,(*Core.args)((*(v15428))[2]))))[1]),GC_OID((*(OBJECT(bag,(*Core.args)((*(v15428))[2]))))[2]),(*(v15428))[1],equal(_oid_(v15435),_oid_(Kernel._equal)));
        else if (((v15435 == Kernel.nth_equal) || 
              (v15435 == Kernel.put)) && 
            ((INHERIT(OWNER((*(v15428))[1]),Kernel._table)) && 
              (v15428->length == 3)))
         Result = c_code_table_Call(v9332);
        else if (((v15435 == Kernel.nth_put) || 
              (v15435 == Kernel.nth_equal)) && 
            ((_inf_equal_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)((*(v15428))[1]))),Kernel._array) == CTRUE) && 
              (v15428->length == 3)))
         Result = c_code_array_Call(v9332);
        else if ((v15435 == Kernel.nth) || 
            (((v15435 == Kernel.get) && 
                (INHERIT(OWNER((*(v15428))[1]),Kernel._table))) || 
              ((v15435 == Kernel.nth_get) && 
                  (Kernel._array == OWNER((*(v15428))[1])))))
         Result = c_code_nth_Call(v9332);
        else if (v15435 == Kernel._Z)
         Result = c_code_belong_Call(v9332);
        else if (v15435 == Core.Id)
         Result = (*Optimize.c_code)(GC_OID(OPT_EVAL((*(v15428))[1])));
        else if (v15435 == Language.function_I)
         Result = _oid_(make_function_string(string_I_symbol(extract_symbol_any((*(v15428))[1]))));
        else if ((v15435 == Core.NOT) && 
            (INHERIT(OWNER((*(v15428))[1]),Language._Select)))
         Result = c_code_not_Select(OBJECT(Select,(*(v15428))[1]));
        else if ((v15435 == Core.call) && 
            (INHERIT(OWNER((*(v15428))[1]),Kernel._property)))
         { OID  v10230;
          { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
            update_property(Kernel.selector,
              v10264,
              2,
              Kernel._object,
              (*(v15428))[1]);
            (v10264->args = cdr_list(v15428));
            add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
            v10230 = _oid_(v10264);
            } 
          Result = (*Optimize.c_code)(v10230);
          } 
        else if (v15435->open == 3)
         { list * v11191;
          { { bag *v_list; OID v_val;
              OID v15440,CLcount;
              v_list = v15428;
               v11191 = v_list->clone();
              for (CLcount= 1; CLcount <= v_list->length; CLcount++)
              { v15440 = (*(v_list))[CLcount];
                v_val = (*Optimize.c_type)(v15440);
                
                (*((list *) v11191))[CLcount] = v_val;} 
              } 
            GC_OBJECT(list,v11191);} 
          Result = c_warn_property(v15435,v15428,v11191);
          } 
        else { ClaireBoolean * g0092I;
          { ClaireBoolean *v_and;
            { v_and = ((v15435 == Language.bit_vector) ? CTRUE : CFALSE);
              if (v_and == CFALSE) g0092I =CFALSE; 
              else { { OID  v13114;
                  { OID gc_local;
                    ITERATE(v15441);
                    v13114= Kernel.cfalse;
                    bag *v15441_support;
                    v15441_support = GC_OBJECT(list,v9332->args);
                    for (START(v15441_support); NEXT(v15441);)
                    if (inherit_ask_class(OWNER(v15441),Kernel._integer) != CTRUE)
                     { v13114 = Kernel.ctrue;
                      break;} 
                    } 
                  v_and = not_any(v13114);
                  } 
                if (v_and == CFALSE) g0092I =CFALSE; 
                else g0092I = CTRUE;} 
              } 
            } 
          
          if (g0092I == CTRUE) Result = OPT_EVAL(_oid_(v9332));
            else if ((v15435 == Optimize.anyObject_I) || 
              ((v15435 == Optimize.object_I) || 
                ((v15435 == Kernel.add_method) && 
                    (v15418 == CTRUE))))
           Result = _oid_(v9332);
          else { list * v1207;
              { { bag *v_list; OID v_val;
                  OID v15440,CLcount;
                  v_list = v15428;
                   v1207 = v_list->clone();
                  for (CLcount= 1; CLcount <= v_list->length; CLcount++)
                  { v15440 = (*(v_list))[CLcount];
                    v_val = (*Optimize.c_type)(v15440);
                    
                    (*((list *) v1207))[CLcount] = v_val;} 
                  } 
                GC_OBJECT(list,v1207);} 
              OID  v15442 = GC_OID(restriction_I_property(v15435,v1207,CTRUE));
              if (Kernel._slot == OWNER(v15442))
               { ClaireBoolean * v10669 = ((belong_to(OBJECT(slot,v15442)->DEFAULT,_oid_(OBJECT(restriction,v15442)->range)) != CTRUE) ? ((contain_ask_set(Optimize.OPT->knowns,_oid_(v15435)) != CTRUE) ? ((Optimize.compiler->safety < 5) ? CTRUE: CFALSE): CFALSE): CFALSE);
                if ((v10669 != CTRUE) || 
                    (designated_ask_any((*(v15428))[1]) == CTRUE))
                 { Call_slot * v10264 = ((Call_slot *) GC_OBJECT(Call_slot,new_object_class(Language._Call_slot)));
                  (v10264->selector = OBJECT(slot,v15442));
                  (v10264->arg = (*Optimize.c_code)((*(v15428))[1],
                    _oid_(psort_any(_oid_(domain_I_restriction(OBJECT(restriction,v15442)))))));
                  (v10264->test = v10669);
                  add_I_property(Kernel.instances,Language._Call_slot,11,_oid_(v10264));
                  Result = _oid_(v10264);
                  } 
                else { if (Optimize.compiler->optimize_ask == CTRUE)
                     { notice_void();
                      ;} 
                    Result = c_warn_property(v15435,v15428,v1207);
                    } 
                  } 
              else if (Kernel._method == OWNER(v15442))
               { if (v15435 == Kernel.nth_equal)
                 (Optimize.OPT->use_nth_equal = CTRUE);
                if (v1207->memq(_oid_(Kernel._void)) == CTRUE)
                 (*Optimize.Cerror)(_string_(CSTRING("[205] call ~S uses a void argument [~S]")),
                  _oid_(v9332),
                  _oid_(v1207));
                if (((v15435 == Kernel.begin) || 
                      (v15435 == Kernel.end)) && 
                    (INHERIT(OWNER((*(v15428))[1]),Kernel._module)))
                 OPT_EVAL(_oid_(v9332));
                if ((last_list(OBJECT(restriction,v15442)->domain) == _oid_(Kernel._listargs)) || 
                    (((*(OBJECT(restriction,v15442)->domain))[1] == _oid_(Kernel._void)) && 
                        ((*(v15428))[1] != _oid_(ClEnv))))
                 Result = _oid_(open_message_property(v15435,v15428));
                else Result = c_code_method_method2(OBJECT(method,v15442),v15428,v1207,v3469);
                  } 
              else if (INHERIT(OWNER(v15442),Kernel._keyword))
               Result = c_warn_property(v15435,v15428,v1207);
              else Result = c_warn_Call(v9332,_oid_(v1207));
                } 
            } 
        } 
      } 
    GC_UNBIND; return (Result);} 
  } 

Call * open_message_property(property *v9332,list *v15428)
{ GC_BIND;
  selector_register_property(v9332);
  { Call *Result ;
    { list * v8505;
      { { bag *v_list; OID v_val;
          OID v15440,CLcount;
          v_list = v15428;
           v8505 = v_list->clone();
          for (CLcount= 1; CLcount <= v_list->length; CLcount++)
          { v15440 = (*(v_list))[CLcount];
            if ((*Optimize.c_type)(v15440) != _oid_(Kernel._void))
             v_val = (*Optimize.c_code)(v15440,
              _oid_(Kernel._any));
            else v_val = (*Optimize.Cerror)(_string_(CSTRING("[206] use of void ~S in ~S~S")),
                v15440,
                _oid_(v9332),
                _oid_(v15428));
              
            (*((list *) v8505))[CLcount] = v_val;} 
          } 
        GC_OBJECT(list,v8505);} 
      if (Optimize.OPT->allocation == CTRUE)
       { { bag *v_list; OID v_val;
          OID v15440,CLcount;
          v_list = v8505;
           v8505 = v_list->clone();
          for (CLcount= 1; CLcount <= v_list->length; CLcount++)
          { v15440 = (*(v_list))[CLcount];
            v_val = c_gc_I_any1(v15440);
            
            (*((list *) v8505))[CLcount] = v_val;} 
          } 
        GC_OBJECT(list,v8505);} 
      { ClaireBoolean * g0094I;
        { ClaireBoolean *v_and;
          { v_and = Optimize.compiler->diet_ask;
            if (v_and == CFALSE) g0094I =CFALSE; 
            else { { OID  v15042;
                { ITERATE(v15440);
                  v15042= Kernel.cfalse;
                  for (START(v15428); NEXT(v15440);)
                  if ((INHERIT(OWNER(v15440),Kernel._class)) || 
                      (INHERIT(OWNER(v15440),Kernel._property)))
                   { v15042 = Kernel.ctrue;
                    break;} 
                  } 
                v_and = boolean_I_any(v15042);
                } 
              if (v_and == CFALSE) g0094I =CFALSE; 
              else g0094I = CTRUE;} 
            } 
          } 
        
        if (g0094I == CTRUE) { warn_void();
            tformat_string(CSTRING("Non diet call ~S(~A) [254]\n"),2,list::alloc(2,_oid_(v9332),_oid_(v15428)));
            } 
          } 
      { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
        (v10264->selector = v9332);
        (v10264->args = v8505);
        add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
        Result = v10264;
        } 
      } 
    GC_UNBIND; return (Result);} 
  } 

ClaireBoolean * c_gc_ask_Call(Call *v9332)
{ GC_BIND;
  { ClaireBoolean *Result ;
    Result = ((v9332->selector == Language.function_I) ? CTRUE : (((v9332->selector == Optimize.safe) ? ((OBJECT(ClaireBoolean,(*Optimize.c_gc_ask)((*(v9332->args))[1]))) == CTRUE) : (((stable_ask_relation(v9332->selector) == CTRUE) ? (((OBJECT(ClaireBoolean,_oid_((INHERIT(v9332->selector->range->isa,Kernel._class) ? (ClaireObject *) gcsafe_ask_class((ClaireClass *) OBJECT(ClaireClass,_oid_(v9332->selector->range))) :  (ClaireObject *)  gcsafe_ask_type((ClaireType *) OBJECT(ClaireType,_oid_(v9332->selector->range))))))) == CTRUE) ? CTRUE: CFALSE): CFALSE) != CTRUE)) ? CTRUE : CFALSE));
    GC_UNBIND; return (Result);} 
  } 

OID  daccess_any(OID v9332,ClaireBoolean *v15418)
{ GC_BIND;
  { OID Result = 0;
    if (INHERIT(OWNER(v9332),Language._Call))
     { list * v15428 = GC_OBJECT(list,OBJECT(Call,v9332)->args);
      ClaireObject * v3619;
      { if ((OBJECT(Call,v9332)->selector == Kernel.get) && 
            (INHERIT(OWNER((*(v15428))[1]),Kernel._property)))
         v3619 = _at_property1(OBJECT(property,(*(v15428))[1]),class_I_type(OBJECT(ClaireType,(*Optimize.c_type)((*(v15428))[2]))));
        else v3619 = CFALSE;
          GC_OBJECT(ClaireObject,v3619);} 
      if ((Kernel._slot == v3619->isa) && ((v15418 == CTRUE) || 
          ((belong_to(CLREAD(slot,v3619,DEFAULT),_oid_(CLREAD(restriction,v3619,range))) == CTRUE) || 
            ((CLREAD(slot,v3619,srange) == Kernel._any) || 
              (CLREAD(slot,v3619,srange) == Kernel._integer)))))
       { Call_slot * v10264 = ((Call_slot *) GC_OBJECT(Call_slot,new_object_class(Language._Call_slot)));
        (v10264->selector = ((slot *) v3619));
        (v10264->arg = (*Optimize.c_code)((*(v15428))[2],
          _oid_(psort_any(_oid_(domain_I_restriction(((restriction *) v3619)))))));
        (v10264->test = CFALSE);
        add_I_property(Kernel.instances,Language._Call_slot,11,_oid_(v10264));
        Result = _oid_(v10264);
        } 
      else Result = CNULL;
        } 
    else Result = CNULL;
      GC_UNBIND; return (Result);} 
  } 

ClaireBoolean * c_gc_ask_Call_slot(Call_slot *v9332)
{ { ClaireBoolean *Result ;
    { slot * v15435 = v9332->selector;
      OID  v15440 = v9332->arg;
      Result = ((_oid_((INHERIT(v15435->range->isa,Kernel._class) ? (ClaireObject *) gcsafe_ask_class((ClaireClass *) OBJECT(ClaireClass,_oid_(v15435->range))) :  (ClaireObject *)  gcsafe_ask_type((ClaireType *) OBJECT(ClaireType,_oid_(v15435->range))))) != Kernel.ctrue) ? ((v15435->range != Kernel._float) ? (((1 <= v15435->selector->open) || 
          (gcsafe_ask_class(domain_I_restriction(v15435)) != CTRUE)) ? CTRUE: CFALSE): CFALSE): CFALSE);
      } 
    return (Result);} 
  } 

ClaireType * c_type_Call_slot_Optimize(Call_slot *v9332)
{ return (v9332->selector->range);} 

ClaireType * c_type_Call_table_Optimize(Call_table *v9332)
{ return (v9332->selector->range);} 

ClaireType * c_type_Call_array_Optimize(Call_array *v9332)
{ return (OBJECT(ClaireType,v9332->test));} 

OID  c_code_write_Call(Call *v9332)
{ GC_BIND;
  { OID Result = 0;
    { OID  v15432 = GC_OID((*(v9332->args))[1]);
      OID  v15440 = GC_OID((*(v9332->args))[2]);
      OID  v15441 = GC_OID((*(v9332->args))[3]);
      OID  v3651 = GC_OID((*Optimize.c_type)(v15441));
      property * v3464 = v9332->selector;
      OID  v15435 = GC_OID((*Optimize.restriction_I)(v15432,
        _oid_(list::alloc(1,GC_OID((*Optimize.c_type)(v15440)))),
        Kernel.ctrue));
      (Optimize.OPT->use_update = CTRUE);
      if (contain_ask_set(Optimize.OPT->to_remove,v15432) == CTRUE)
       Result = Core.nil->value;
      else if ((Kernel._slot == OWNER(v15435)) && ((_inf_equal_type(OBJECT(ClaireType,v3651),OBJECT(restriction,v15435)->range) == CTRUE) || 
          (4 <= Optimize.compiler->safety)))
       { if ((v15441 != CNULL) && 
            (boolean_I_any((*Kernel._exp)(v3651,
              GC_OID((*Kernel.srange)(v15435)))) != CTRUE))
         { warn_void();
          tformat_string(CSTRING("sort error in ~S: ~S is a ~S [253]\n"),2,list::alloc(3,_oid_(v9332),
            v15441,
            v3651));
          } 
        if (((_inf_equal_type(OBJECT(ClaireType,v3651),GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Kernel.range)(v15435)))) == CTRUE) || 
              ((_inf_equal_type(OBJECT(ClaireType,v3651),Kernel._object) == CTRUE) || 
                (((*Kernel.srange)(v15435) != _oid_(Kernel._object)) || 
                  (v15441 == CNULL)))) && 
            ((v3464 != Core.write) || 
                ((Update_ask_relation(OBJECT(ClaireRelation,v15432),v15440,v15441) == CTRUE) && 
                    ((OBJECT(ClaireRelation,v15432)->multivalued_ask == CFALSE) || 
                        (get_property(Kernel.if_write,OBJECT(ClaireObject,v15432)) == CNULL)))))
         { OID  v1051 = GC_OID((*Optimize.c_code)(v15440,
            _oid_(psort_any(_oid_(domain_I_restriction(OBJECT(restriction,v15435)))))));
          OID  v1052 = GC_OID(c_strict_code_any(v15441,psort_any((*Kernel.range)(v15435))));
          Update * v10264 = ((Update *) GC_OBJECT(Update,new_object_class(Language._Update)));
          (v10264->selector = v15432);
          (v10264->value = v1052);
          { Update * v15068 = v10264; 
            OID  v15070;
            if (v3464 != Core.write)
             v15070 = _oid_(v3464);
            else v15070 = (*Optimize.c_code)(v15440,
                _oid_(Kernel._any));
              (v15068->arg = v15070);} 
          { Update * v15071 = v10264; 
            OID  v15072;
            { Call_slot * v10264 = ((Call_slot *) GC_OBJECT(Call_slot,new_object_class(Language._Call_slot)));
              update_property(Kernel.selector,
                v10264,
                2,
                Kernel._object,
                v15435);
              (v10264->arg = v1051);
              (v10264->test = CFALSE);
              add_I_property(Kernel.instances,Language._Call_slot,11,_oid_(v10264));
              v15072 = _oid_(v10264);
              } 
            (v15071->var = v15072);} 
          add_I_property(Kernel.instances,Language._Update,11,_oid_(v10264));
          Result = _oid_(v10264);
          } 
        else if (v3464 == Kernel.put)
         { OID  v10272;
          { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
            (v10264->selector = Kernel.store);
            (v10264->args = list::alloc(5,v15440,
              (*Kernel.index)(v15435),
              GC_OID((*Kernel.srange)(v15435)),
              v15441,
              GC_OID((*Kernel.store_ask)(v15432))));
            add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
            v10272 = _oid_(v10264);
            } 
          Result = (*Optimize.c_code)(v10272);
          } 
        else { if (Optimize.compiler->diet_ask == CTRUE)
             { warn_void();
              tformat_string(CSTRING("~S is not a diet call [254]"),2,list::alloc(1,_oid_(v9332)));
              } 
            if ((Optimize.compiler->optimize_ask == CTRUE) && 
                (v15432 != _oid_(Kernel.instances)))
             { notice_void();
              ;} 
            { OID  v11233;
              { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                (v10264->selector = Core.update);
                (v10264->args = list::alloc(5,v15432,
                  v15440,
                  (*Kernel.index)(v15435),
                  GC_OID((*Kernel.srange)(v15435)),
                  v15441));
                add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
                v11233 = _oid_(v10264);
                } 
              Result = (*Optimize.c_code)(v11233);
              } 
            } 
          } 
      else { list * v1207;
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
          OID  v15442 = GC_OID(restriction_I_property(v3464,v1207,CTRUE));
          if (Kernel._method == OWNER(v15442))
           Result = c_code_method_method1(OBJECT(method,v15442),GC_OBJECT(list,v9332->args),v1207);
          else Result = c_warn_Call(v9332,_oid_(v1207));
            } 
        } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_hold_property(property *v15432,OID v15440,OID v15441,ClaireBoolean *v15418)
{ GC_BIND;
  { OID Result = 0;
    { OID  v15435 = GC_OID(restriction_I_property(v15432,list::alloc(1,GC_OID((*Optimize.c_type)(v15440))),CTRUE));
      if ((Kernel._slot == OWNER(v15435)) && ((v15441 == CNULL) || 
          ((_inf_equal_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(v15441))),OBJECT(slot,v15435)->srange) == CTRUE) && 
              (identifiable_ask_any(v15441) == CTRUE))))
       { Call_slot * v2968;
        { { Call_slot * v10264 = ((Call_slot *) GC_OBJECT(Call_slot,new_object_class(Language._Call_slot)));
            update_property(Kernel.selector,
              v10264,
              2,
              Kernel._object,
              v15435);
            (v10264->arg = (*Optimize.c_code)(v15440,
              _oid_(psort_any(_oid_(domain_I_restriction(OBJECT(restriction,v15435)))))));
            (v10264->test = CFALSE);
            add_I_property(Kernel.instances,Language._Call_slot,11,_oid_(v10264));
            v2968 = v10264;
            } 
          GC_OBJECT(Call_slot,v2968);} 
        Call_method2 * v2962;
        { { Call_method2 * v10264 = ((Call_method2 *) GC_OBJECT(Call_method2,new_object_class(Language._Call_method2)));
            (v10264->arg = ((method *) _at_property1(Core.identical_ask,Kernel._any)));
            (v10264->args = list::alloc(2,_oid_(v2968),GC_OID((*Optimize.c_code)(v15441,
              GC_OID((*Kernel.srange)(v15435))))));
            add_I_property(Kernel.instances,Language._Call_method2,11,_oid_(v10264));
            v2962 = v10264;
            } 
          GC_OBJECT(Call_method2,v2962);} 
        if (v15418 == CTRUE)
         Result = (*Optimize.c_code)(_oid_(v2962));
        else { OID  v12196;
            { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
              (v10264->selector = Core.NOT);
              (v10264->args = list::alloc(1,_oid_(v2962)));
              add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
              v12196 = _oid_(v10264);
              } 
            Result = (*Optimize.c_code)(v12196);
            } 
          } 
      else { list * v15428 = list::alloc(2,_oid_(Kernel._any),_oid_(Kernel._any));
          { list * v13155;
            { OID v_bag;
              GC_ANY(v13155= list::empty(Kernel.emptySet));
              { { OID  v14116;
                  { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                    (v10264->selector = Kernel.get);
                    (v10264->args = list::alloc(2,_oid_(v15432),v15440));
                    add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
                    v14116 = _oid_(v10264);
                    } 
                  v_bag = (*Optimize.c_code)(v14116,
                    _oid_(Kernel._any));
                  } 
                GC_OID(v_bag);} 
              ((list *) v13155)->addFast(v_bag);
              ((list *) v13155)->addFast(GC_OID((*Optimize.c_code)(v15441,
                _oid_(Kernel._any))));} 
            Result = c_code_method_method1(GC_OBJECT(method,((method *) _at_property2(((v15418 == CTRUE) ?
              Kernel._equal :
              Core._I_equal ),v15428))),v13155,v15428);
            } 
          } 
        } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_add_Call(Call *v9332)
{ GC_BIND;
  { OID Result = 0;
    { property * v15432 = OBJECT(property,(*(v9332->args))[1]);
      OID  v15440 = GC_OID((*(v9332->args))[2]);
      OID  v15441 = GC_OID((*(v9332->args))[3]);
      ClaireObject * v15435 = GC_OBJECT(ClaireObject,_at_property1(v15432,class_I_type(ptype_type(OBJECT(ClaireType,(*Optimize.c_type)(v15440))))));
      (Optimize.OPT->use_update = CTRUE);
      if ((Kernel._slot == v15435->isa) && ((_inf_equal_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(v15441))),GC_OBJECT(ClaireType,member_type(CLREAD(restriction,v15435,range)))) == CTRUE) || 
          (4 <= Optimize.compiler->safety)))
       { if (Update_ask_relation2(v15432,v9332->selector) == CTRUE)
         { OID  v3554 = GC_OID((*Optimize.c_code)(v15440,
            _oid_(psort_any(_oid_(domain_I_restriction(((restriction *) v15435)))))));
          Update * v10264 = ((Update *) GC_OBJECT(Update,new_object_class(Language._Update)));
          (v10264->selector = _oid_(v15432));
          (v10264->arg = _oid_(Kernel.add));
          { Update * v15749 = v10264; 
            OID  v15750;
            { Call_slot * v10264 = ((Call_slot *) GC_OBJECT(Call_slot,new_object_class(Language._Call_slot)));
              (v10264->selector = ((slot *) v15435));
              (v10264->arg = v3554);
              (v10264->test = CFALSE);
              add_I_property(Kernel.instances,Language._Call_slot,11,_oid_(v10264));
              v15750 = _oid_(v10264);
              } 
            (v15749->var = v15750);} 
          (v10264->value = (*Optimize.c_code)(v15441,
            _oid_(psort_any(_oid_(member_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Kernel.range)(_oid_(v15435))))))))));
          add_I_property(Kernel.instances,Language._Update,11,_oid_(v10264));
          Result = _oid_(v10264);
          } 
        else if ((designated_ask_any(v15440) == CTRUE) && 
            ((v15432->store_ask != CTRUE) && 
                ((v9332->selector == Kernel.add_I) || 
                    (v15432->inverse == (NULL)))))
         { OID  v3554 = GC_OID((*Optimize.c_code)(v15440,
            _oid_(psort_any(_oid_(domain_I_restriction(((restriction *) v15435)))))));
          { OID  v615;
            { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
              (v10264->selector = Kernel.add);
              { Call * v15753 = v10264; 
                list * v15754;
                { OID v_bag;
                  GC_ANY(v15754= list::empty(Kernel.emptySet));
                  { { Call_slot * v10264 = ((Call_slot *) GC_OBJECT(Call_slot,new_object_class(Language._Call_slot)));
                      (v10264->selector = ((slot *) v15435));
                      (v10264->arg = v3554);
                      (v10264->test = CFALSE);
                      add_I_property(Kernel.instances,Language._Call_slot,11,_oid_(v10264));
                      v_bag = _oid_(v10264);
                      } 
                    GC_OID(v_bag);} 
                  ((list *) v15754)->addFast(v_bag);
                  ((list *) v15754)->addFast(v15441);} 
                (v15753->args = v15754);} 
              add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
              v615 = _oid_(v10264);
              } 
            Result = (*Optimize.c_code)(v615);
            } 
          } 
        else { if (Optimize.compiler->optimize_ask == CTRUE)
             { notice_void();
              ;} 
            Result = c_code_method_method1(GC_OBJECT(method,((method *) _at_property1(Kernel.add_I,Kernel._property))),list::alloc(4,_oid_(v15432),
              v15440,
              (*Kernel.index)(_oid_(v15435)),
              v15441),list::alloc(4,_oid_(Kernel._property),
              GC_OID((*Optimize.c_type)(v15440)),
              _oid_(Kernel._integer),
              GC_OID((*Optimize.c_type)(v15441))));
            } 
          } 
      else { list * v7295;
          { { bag *v_list; OID v_val;
              OID v15440,CLcount;
              v_list = GC_OBJECT(list,v9332->args);
               v7295 = v_list->clone();
              for (CLcount= 1; CLcount <= v_list->length; CLcount++)
              { v15440 = (*(v_list))[CLcount];
                v_val = (*Optimize.c_type)(v15440);
                
                (*((list *) v7295))[CLcount] = v_val;} 
              } 
            GC_OBJECT(list,v7295);} 
          Result = c_code_method_method1(GC_OBJECT(method,((method *) _at_property1(Kernel.add,Kernel._property))),GC_OBJECT(list,v9332->args),v7295);
          } 
        } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_add_bag_Call(Call *v9332)
{ GC_BIND;
  { OID Result = 0;
    { OID  v16122 = GC_OID((*Optimize.c_type)(GC_OID((*(v9332->args))[1])));
      ClaireType * v16123 = GC_OBJECT(ClaireType,ptype_type(OBJECT(ClaireType,(*Optimize.c_type)(GC_OID((*(v9332->args))[2])))));
      property * v1043;
      if (((INHERIT(OBJECT(ClaireObject,v16122)->isa,Core._Param)) && 
            (_inf_equal_type(v16123,GC_OBJECT(ClaireType,member_type(OBJECT(ClaireType,v16122)))) == CTRUE)) || 
          (4 <= Optimize.compiler->safety))
       v1043 = Kernel.add_I;
      else v1043 = v9332->selector;
        list * v13257 = list::alloc(2,v16122,_oid_(v16123));
      OID  v15442 = GC_OID(restriction_I_property(v1043,v13257,CTRUE));
      if ((_inf_equal_type(v16123,GC_OBJECT(ClaireType,member_type(OBJECT(ClaireType,v16122)))) != CTRUE) && 
          (v9332->selector == Kernel.add))
       { warn_void();
        tformat_string(CSTRING("the bag addition ~S is poorly typed (~S) [251] \n"),2,list::alloc(2,_oid_(v9332),GC_OID(_oid_(member_type(OBJECT(ClaireType,v16122))))));
        } 
      if (Kernel._method == OWNER(v15442))
       Result = c_code_method_method1(OBJECT(method,v15442),GC_OBJECT(list,v9332->args),v13257);
      else Result = c_warn_Call(v9332,_oid_(v13257));
        } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_delete_Call(Call *v9332)
{ GC_BIND;
  { OID Result = 0;
    { OID  v15432 = GC_OID((*(v9332->args))[1]);
      OID  v15440 = GC_OID((*(v9332->args))[2]);
      OID  v15441 = GC_OID((*(v9332->args))[3]);
      ClaireObject * v15435 = GC_OBJECT(ClaireObject,_at_property1(OBJECT(property,v15432),class_I_type(OBJECT(ClaireType,(*Optimize.c_type)(v15440)))));
      (Optimize.OPT->use_update = CTRUE);
      if ((OBJECT(ClaireRelation,v15432)->inverse == (NULL)) && 
          ((designated_ask_any(v15440) == CTRUE) && 
            ((Kernel._slot == v15435->isa) && ((_inf_equal_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(v15441))),GC_OBJECT(ClaireType,member_type(CLREAD(restriction,v15435,range)))) == CTRUE) || 
                (4 <= Optimize.compiler->safety)))))
       { OID  v3554 = GC_OID((*Optimize.c_code)(v15440,
          _oid_(psort_any(_oid_(domain_I_restriction(((restriction *) v15435)))))));
        { OID  v8256;
          { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
            (v10264->selector = Kernel._delete);
            { Call * v15777 = v10264; 
              list * v15778;
              { OID v_bag;
                GC_ANY(v15778= list::empty(Kernel.emptySet));
                { { Call_slot * v10264 = ((Call_slot *) GC_OBJECT(Call_slot,new_object_class(Language._Call_slot)));
                    (v10264->selector = ((slot *) v15435));
                    (v10264->arg = v3554);
                    (v10264->test = CFALSE);
                    add_I_property(Kernel.instances,Language._Call_slot,11,_oid_(v10264));
                    v_bag = _oid_(v10264);
                    } 
                  GC_OID(v_bag);} 
                ((list *) v15778)->addFast(v_bag);
                ((list *) v15778)->addFast(v15441);} 
              (v15777->args = v15778);} 
            add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
            v8256 = _oid_(v10264);
            } 
          Result = (*Optimize.c_code)(v8256);
          } 
        } 
      else { list * v11139;
          { { bag *v_list; OID v_val;
              OID v15440,CLcount;
              v_list = GC_OBJECT(list,v9332->args);
               v11139 = v_list->clone();
              for (CLcount= 1; CLcount <= v_list->length; CLcount++)
              { v15440 = (*(v_list))[CLcount];
                v_val = (*Optimize.c_type)(v15440);
                
                (*((list *) v11139))[CLcount] = v_val;} 
              } 
            GC_OBJECT(list,v11139);} 
          Result = c_code_method_method1(GC_OBJECT(method,((method *) _at_property1(Kernel._delete,Kernel._property))),GC_OBJECT(list,v9332->args),v11139);
          } 
        } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_not_Select(Select *v15440)
{ GC_BIND;
  { OID Result = 0;
    { OID  v12100;
      { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
        (v10264->selector = Core.NOT);
        { Call * v15781 = v10264; 
          list * v15786;
          { OID v_bag;
            GC_ANY(v15786= list::empty(Kernel.emptySet));
            { { For * v10264 = ((For *) GC_OBJECT(For,new_object_class(Language._For)));
                (v10264->var = v15440->var);
                (v10264->set_arg = v15440->set_arg);
                { Iteration * v15787 = v10264; 
                  OID  v15788;
                  { If * v10264 = ((If *) GC_OBJECT(If,new_object_class(Language._If)));
                    (v10264->test = v15440->arg);
                    { If * v15806 = v10264; 
                      OID  v15807;
                      { Return * v10264 = ((Return *) GC_OBJECT(Return,new_object_class(Language._Return)));
                        (v10264->arg = Kernel.ctrue);
                        add_I_property(Kernel.instances,Language._Return,11,_oid_(v10264));
                        v15807 = _oid_(v10264);
                        } 
                      (v15806->arg = v15807);} 
                    (v10264->other = CNULL);
                    add_I_property(Kernel.instances,Language._If,11,_oid_(v10264));
                    v15788 = _oid_(v10264);
                    } 
                  (v15787->arg = v15788);} 
                add_I_property(Kernel.instances,Language._For,11,_oid_(v10264));
                v_bag = _oid_(v10264);
                } 
              GC_OID(v_bag);} 
            ((list *) v15786)->addFast(v_bag);} 
          (v15781->args = v15786);} 
        add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
        v12100 = _oid_(v10264);
        } 
      Result = (*Optimize.c_code)(v12100);
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_belong_Call(Call *v9332)
{ GC_BIND;
  { OID Result = 0;
    { OID  v15440 = GC_OID((*(v9332->args))[1]);
      OID  v15441 = GC_OID((*(v9332->args))[2]);
      list * v1207 = list::alloc(2,GC_OID((*Optimize.c_type)(v15441)),GC_OID((*Optimize.c_type)(v15440)));
      if (Kernel._set == OWNER(v15441))
       { Or * v10264 = ((Or *) GC_OBJECT(Or,new_object_class(Language._Or)));
        { Or * v15808 = v10264; 
          list * v15809;
          { list * v11931 = list::empty(Kernel.emptySet);
            { OID gc_local;
              ITERATE(v15442);
              bag *v15442_support;
              v15442_support = GC_OBJECT(bag,enumerate_any(v15441));
              for (START(v15442_support); NEXT(v15442);)
              { GC_LOOP;
                { OID  v8163;
                  { { OID  v9124;
                      { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                        (v10264->selector = Kernel._equal);
                        (v10264->args = list::alloc(2,v15440,v15442));
                        add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
                        v9124 = _oid_(v10264);
                        } 
                      v8163 = (*Optimize.c_code)(v9124,
                        _oid_(Kernel._any));
                      } 
                    GC_OID(v8163);} 
                  v11931->addFast(v8163);
                  } 
                GC_UNLOOP;} 
              } 
            v15809 = GC_OBJECT(list,v11931);
            } 
          (v15808->args = v15809);} 
        add_I_property(Kernel.instances,Language._Or,11,_oid_(v10264));
        Result = _oid_(v10264);
        } 
      else if (_inf_equal_type(OBJECT(ClaireType,(*(v1207))[1]),Kernel._list) == CTRUE)
       Result = c_code_method_method1(GC_OBJECT(method,((method *) _at_property2(Kernel.contain_ask,GC_OBJECT(list,list::alloc(2,_oid_(Kernel._list),_oid_(Kernel._any)))))),GC_OBJECT(list,list::alloc(2,v15441,v15440)),v1207);
      else if (_inf_equal_type(OBJECT(ClaireType,(*(v1207))[1]),Kernel._set) == CTRUE)
       Result = c_code_method_method1(GC_OBJECT(method,((method *) _at_property2(Kernel.contain_ask,GC_OBJECT(list,list::alloc(2,_oid_(Kernel._set),_oid_(Kernel._any)))))),GC_OBJECT(list,list::alloc(2,v15441,v15440)),v1207);
      else if (v15441 == _oid_(Kernel._object))
       Result = c_code_method_method1(GC_OBJECT(method,((method *) _at_property2(Kernel._Z,GC_OBJECT(list,list::alloc(2,_oid_(Kernel._any),_oid_(Kernel._class)))))),GC_OBJECT(list,list::alloc(2,v15440,v15441)),GC_OBJECT(list,list::alloc(2,_oid_(Kernel._any),_oid_(Kernel._class))));
      else Result = (*Optimize.member_code)(v15441,
          v15440);
        } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_nth_Call(Call *v9332)
{ GC_BIND;
  { OID Result = 0;
    { list * v15428 = GC_OBJECT(list,v9332->args);
      OID  v15440 = (*(v15428))[1];
      property * v15432 = v9332->selector;
      OID  v15436 = GC_OID((*Optimize.c_type)(v15440));
      ClaireType * v3279 = GC_OBJECT(ClaireType,member_type(OBJECT(ClaireType,v15436)));
      OID  v15434;
      { { list * v10085;
          { { bag *v_list; OID v_val;
              OID v15437,CLcount;
              v_list = v15428;
               v10085 = v_list->clone();
              for (CLcount= 1; CLcount <= v_list->length; CLcount++)
              { v15437 = (*(v_list))[CLcount];
                v_val = (*Optimize.c_type)(v15437);
                
                (*((list *) v10085))[CLcount] = v_val;} 
              } 
            GC_OBJECT(list,v10085);} 
          v15434 = restriction_I_property(v15432,v10085,CTRUE);
          } 
        GC_OID(v15434);} 
      if (contain_ask_set(Optimize.OPT->to_remove,v15440) == CTRUE)
       Result = Core.nil->value;
      else if (((INHERIT(OWNER(v15440),Kernel._table)) && (INHERIT(OWNER(OBJECT(table,v15440)->params),Kernel._integer))) && 
          ((_inf_equal_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)((*(v15428))[2]))),GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Kernel.domain)(v15440)))) == CTRUE) || 
              ((v15432 == Kernel.nth) && 
                  (Optimize.compiler->safety > 2))))
       { Call_table * v10264 = ((Call_table *) GC_OBJECT(Call_table,new_object_class(Language._Call_table)));
        update_property(Kernel.selector,
          v10264,
          2,
          Kernel._object,
          v15440);
        (v10264->arg = (*Optimize.c_code)((*(v15428))[2],
          _oid_(Kernel._integer)));
        (v10264->test = not_any(_oid_(((belong_to(GC_OID((*Kernel.DEFAULT)(v15440)),GC_OID((*Kernel.range)(v15440))) == CTRUE) ? CTRUE : (((*Kernel.DEFAULT)(v15440) == 0) ? CTRUE : ((v15432 == Kernel.get) ? CTRUE : CFALSE))))));
        add_I_property(Kernel.instances,Language._Call_table,11,_oid_(v10264));
        Result = _oid_(v10264);
        } 
      else if (((INHERIT(OWNER(v15440),Kernel._table)) && (INHERIT(OWNER(OBJECT(table,v15440)->params),Kernel._list))) && 
          ((v15428->length == 3) && 
            ((_inf_equal_type(GC_OBJECT(tuple,tuple_I_list(list::alloc(2,GC_OID((*Optimize.c_type)((*(v15428))[2])),GC_OID((*Optimize.c_type)((*(v15428))[3]))))),GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Kernel.domain)(v15440)))) == CTRUE) || 
                (Optimize.compiler->safety > 2))))
       { Call_table * v10264 = ((Call_table *) GC_OBJECT(Call_table,new_object_class(Language._Call_table)));
        update_property(Kernel.selector,
          v10264,
          2,
          Kernel._object,
          v15440);
        { Call_table * v15813 = v10264; 
          OID  v15815;
          { List * v10264 = ((List *) GC_OBJECT(List,new_object_class(Language._List)));
            (v10264->args = list::alloc(2,GC_OID((*Optimize.c_code)((*(v15428))[2],
              _oid_(Kernel._integer))),GC_OID((*Optimize.c_code)((*(v15428))[3],
              _oid_(Kernel._integer)))));
            add_I_property(Kernel.instances,Language._List,11,_oid_(v10264));
            v15815 = _oid_(v10264);
            } 
          (v15813->arg = v15815);} 
        (v10264->test = not_any(_oid_(((belong_to(GC_OID((*Kernel.DEFAULT)(v15440)),GC_OID((*Kernel.range)(v15440))) == CTRUE) ? CTRUE : (((*Kernel.DEFAULT)(v15440) == 0) ? CTRUE : ((v15432 == Kernel.get) ? CTRUE : CFALSE))))));
        add_I_property(Kernel.instances,Language._Call_table,11,_oid_(v10264));
        Result = _oid_(v10264);
        } 
      else if ((_inf_equal_type(OBJECT(ClaireType,v15436),Kernel._array) == CTRUE) && 
          (((v15432 == Kernel.nth_get) || 
              (Optimize.compiler->safety > 2)) && 
            ((_inf_equal_type(v3279,Kernel._float) == CTRUE) || 
                (equal(_oid_(_exp_type(v3279,Kernel._float)),_oid_(Kernel.emptySet)) == CTRUE))))
       { Call_array * v10264 = ((Call_array *) GC_OBJECT(Call_array,new_object_class(Language._Call_array)));
        (v10264->selector = (*Optimize.c_code)(v15440,
          _oid_(Kernel._array)));
        (v10264->arg = (*Optimize.c_code)((*(v15428))[2],
          _oid_(Kernel._integer)));
        (v10264->test = _oid_(v3279));
        add_I_property(Kernel.instances,Language._Call_array,11,_oid_(v10264));
        Result = _oid_(v10264);
        } 
      else if (Kernel._method == OWNER(v15434))
       { if ((Optimize.compiler->optimize_ask == CTRUE) && 
            ((_inf_equal_type(OBJECT(ClaireType,v15436),Kernel._array) == CTRUE) || 
                (_inf_equal_type(OBJECT(ClaireType,v15436),Kernel._table) == CTRUE)))
         { notice_void();
          ;} 
        { list * v12967;
          { { bag *v_list; OID v_val;
              OID v15440,CLcount;
              v_list = GC_OBJECT(list,v9332->args);
               v12967 = v_list->clone();
              for (CLcount= 1; CLcount <= v_list->length; CLcount++)
              { v15440 = (*(v_list))[CLcount];
                v_val = (*Optimize.c_type)(v15440);
                
                (*((list *) v12967))[CLcount] = v_val;} 
              } 
            GC_OBJECT(list,v12967);} 
          Result = c_code_method_method1(OBJECT(method,v15434),GC_OBJECT(list,v9332->args),v12967);
          } 
        } 
      else { list * v1341;
          { { bag *v_list; OID v_val;
              OID v15440,CLcount;
              v_list = GC_OBJECT(list,v9332->args);
               v1341 = v_list->clone();
              for (CLcount= 1; CLcount <= v_list->length; CLcount++)
              { v15440 = (*(v_list))[CLcount];
                v_val = (*Optimize.c_type)(v15440);
                
                (*((list *) v1341))[CLcount] = v_val;} 
              } 
            GC_OBJECT(list,v1341);} 
          Result = c_warn_property(v15432,GC_OBJECT(list,v9332->args),v1341);
          } 
        } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_table_Call(Call *v9332)
{ GC_BIND;
  { OID Result = 0;
    { property * v3461 = v9332->selector;
      table * v15432 = OBJECT(table,(*(v9332->args))[1]);
      OID  v15440 = GC_OID((*(v9332->args))[2]);
      OID  v15441 = GC_OID((*(v9332->args))[3]);
      if (contain_ask_set(Optimize.OPT->to_remove,_oid_(v15432)) == CTRUE)
       Result = Core.nil->value;
      else if ((v3461 == Kernel.put) || 
          (((_inf_equal_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(v15440))),v15432->domain) == CTRUE) || 
                (5 <= Optimize.compiler->safety)) && 
              ((_inf_equal_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(v15441))),v15432->range) == CTRUE) || 
                  (4 <= Optimize.compiler->safety))))
       { if ((Update_ask_relation(v15432,v15440,v15441) == CTRUE) && 
            ((INHERIT(OWNER(v15432->params),Kernel._list)) || 
                (INHERIT(OWNER(v15432->params),Kernel._integer))))
         { OID  v1051 = GC_OID((*Optimize.c_code)(v15440,
            _oid_(Kernel._any)));
          OID  v1052 = GC_OID((*Optimize.c_code)(v15441,
            _oid_(Kernel._any)));
          Update * v10264 = ((Update *) GC_OBJECT(Update,new_object_class(Language._Update)));
          (v10264->selector = _oid_(v15432));
          (v10264->value = v1052);
          { Update * v15838 = v10264; 
            OID  v15839;
            if (v3461 == Kernel.put)
             v15839 = _oid_(Kernel.put);
            else v15839 = v1051;
              (v15838->arg = v15839);} 
          { Update * v15840 = v10264; 
            OID  v15841;
            { Call_table * v10264 = ((Call_table *) GC_OBJECT(Call_table,new_object_class(Language._Call_table)));
              (v10264->selector = v15432);
              (v10264->arg = v1051);
              (v10264->test = CFALSE);
              add_I_property(Kernel.instances,Language._Call_table,11,_oid_(v10264));
              v15841 = _oid_(v10264);
              } 
            (v15840->var = v15841);} 
          add_I_property(Kernel.instances,Language._Update,11,_oid_(v10264));
          Result = _oid_(v10264);
          } 
        else if ((v3461 == Kernel.put) || 
            ((v15432->inverse == (NULL)) && 
                (v15432->if_write == CNULL)))
         { if (Optimize.compiler->optimize_ask == CTRUE)
           { notice_void();
            ;} 
          Result = c_code_method_method1(GC_OBJECT(method,((method *) _at_property1(Kernel.put,Kernel._table))),GC_OBJECT(list,v9332->args),list::alloc(3,_oid_(Kernel._table),
            _oid_(Kernel._any),
            _oid_(Kernel._any)));
          } 
        else Result = c_code_method_method1(GC_OBJECT(method,((method *) _at_property1(Kernel.nth_put,Kernel._table))),GC_OBJECT(list,v9332->args),list::alloc(3,_oid_(Kernel._table),
            _oid_(Kernel._any),
            _oid_(Kernel._any)));
          } 
      else Result = c_code_method_method1(GC_OBJECT(method,((method *) _at_property1(Kernel.nth_equal,Kernel._table))),GC_OBJECT(list,v9332->args),list::alloc(3,_oid_(Kernel._table),
          _oid_(Kernel._any),
          _oid_(Kernel._any)));
        } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_array_Call(Call *v9332)
{ GC_BIND;
  { OID Result = 0;
    { property * v3461 = v9332->selector;
      OID  v15432 = GC_OID((*(v9332->args))[1]);
      OID  v3493 = GC_OID((*Optimize.c_type)(v15432));
      ClaireType * v3279 = GC_OBJECT(ClaireType,member_type(OBJECT(ClaireType,v3493)));
      OID  v15440 = GC_OID((*(v9332->args))[2]);
      OID  v15441 = GC_OID((*(v9332->args))[3]);
      ClaireBoolean * v8638 = ((_inf_equal_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(v15441))),GC_OBJECT(ClaireType,member_type(OBJECT(ClaireType,v3493)))) == CTRUE) ? CTRUE : ((4 <= Optimize.compiler->safety) ? CTRUE : CFALSE));
      if (((v3461 == Kernel.nth_put) || 
            (v8638 == CTRUE)) && 
          ((_inf_equal_type(v3279,Kernel._float) == CTRUE) || 
              (equal(_oid_(_exp_type(v3279,Kernel._float)),_oid_(Kernel.emptySet)) == CTRUE)))
       { OID  v1051 = GC_OID((*Optimize.c_code)(v15440,
          _oid_(Kernel._integer)));
        OID  v1052;
        { { OID  v6146;
            if (_inf_equal_type(v3279,Kernel._float) == CTRUE)
             v6146 = _oid_(Kernel._float);
            else v6146 = _oid_(Kernel._any);
              v1052 = (*Optimize.c_code)(v15441,
              v6146);
            } 
          GC_OID(v1052);} 
        Update * v10264 = ((Update *) GC_OBJECT(Update,new_object_class(Language._Update)));
        (v10264->selector = v15432);
        (v10264->value = v1052);
        (v10264->arg = _oid_(Kernel.put));
        { Update * v15843 = v10264; 
          OID  v15844;
          { Call_array * v10264 = ((Call_array *) GC_OBJECT(Call_array,new_object_class(Language._Call_array)));
            (v10264->selector = (*Optimize.c_code)(v15432,
              _oid_(Kernel._array)));
            (v10264->arg = v1051);
            (v10264->test = _oid_(v3279));
            add_I_property(Kernel.instances,Language._Call_array,11,_oid_(v10264));
            v15844 = _oid_(v10264);
            } 
          (v15843->var = v15844);} 
        add_I_property(Kernel.instances,Language._Update,11,_oid_(v10264));
        Result = _oid_(v10264);
        } 
      else { if (Optimize.compiler->optimize_ask == CTRUE)
           { notice_void();
            ;} 
          Result = c_code_method_method1(GC_OBJECT(method,((method *) _at_property1(((v8638 == CTRUE) ?
            Kernel.nth_put :
            v3461 ),Kernel._array))),GC_OBJECT(list,v9332->args),list::alloc(3,v3493,
            _oid_(Kernel._any),
            _oid_(Kernel._any)));
          } 
        } 
    GC_UNBIND; return (Result);} 
  } 

ClaireBoolean * Update_ask_relation(ClaireRelation *v15432,OID v15440,OID v15441)
{ GC_BIND;
  { ClaireBoolean *Result ;
    Result = ((v15432 != Kernel.inverse) ? ((((((v15432->if_write == CNULL) ? CTRUE : CFALSE) != CTRUE) && 
          (inherit_ask_class(OWNER(v15432->if_write),Kernel._list) != CTRUE)) || 
        ((v15432->inverse == (NULL)) && 
            (((INHERIT(v15432->isa,Kernel._table)) ? (INHERIT(OWNER(CLREAD(table,v15432,params)),Kernel._integer)) : (CTRUE == CTRUE)) && 
              ((v15432->store_ask == CTRUE) ? ((designated_ask_any(v15440) == CTRUE) && 
                  ((designated_ask_any(v15441) == CTRUE) && 
                    ((multi_ask_any(_oid_(v15432)) != CTRUE) && 
                      ((identifiable_ask_any(v15441) == CTRUE) || 
                          (_inf_equal_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(v15441))),Kernel._float) == CTRUE))))) : (CTRUE == CTRUE))))) ? CTRUE: CFALSE): CFALSE);
    GC_UNBIND; return (Result);} 
  } 

ClaireBoolean * Update_ask_relation2(ClaireRelation *v15432,ClaireRelation *v15435)
{ return (((((v15432->if_write == CNULL) ? CTRUE : CFALSE) != CTRUE) ? ((inherit_ask_class(OWNER(v15432->if_write),Kernel._list) != CTRUE) ? ((v15435 == Kernel.add) ? CTRUE: CFALSE): CFALSE): CFALSE));} 

ClaireType * c_type_Update_Optimize(Update *v9332)
{ return (Kernel._void);} 

OID  c_code_method_method1(method *v9332,list *v15428,list *v1207)
{ return (c_code_method_method2(v9332,v15428,v1207,c_srange_method(v9332)));} 

OID  c_code_method_method2(method *v9332,list *v15428,list *v1207,ClaireClass *v3469)
{ GC_BIND;
  { OID Result = 0;
    if ((v9332->module_I != claire.it) || 
        ((Optimize.compiler->safety > 4) || 
          (((v9332->functional == (NULL)) ? CTRUE : CFALSE) != CTRUE)))
     { list * v3232 = v9332->domain;
      Cint  v15431 = v3232->length;
      if (v15431 != v15428->length)
       { { list * v15709;
          { list * v7946 = list::empty(Kernel.emptySet);
            { Cint  v15425 = 1;
              Cint  v15845 = (v15431-1);
              { OID gc_local;
                while ((v15425 <= v15845))
                { v7946->addFast((*(v15428))[v15425]);
                  ++v15425;
                  } 
                } 
              } 
            v15709 = GC_OBJECT(list,v7946);
            } 
          OID  v286;
          { list * v1114;{ list * v7946 = list::empty(Kernel.emptySet);
              { Cint  v15425 = v15431;
                Cint  v15849 = v15428->length;
                { OID gc_local;
                  while ((v15425 <= v15849))
                  { v7946->addFast((*(v15428))[v15425]);
                    ++v15425;
                    } 
                  } 
                } 
              v1114 = GC_OBJECT(list,v7946);
              } 
            
            v286=_oid_(v1114);} 
          v15428 = v15709->addFast(v286);
          } 
        GC_OBJECT(list,v15428);} 
      if ((v9332->inline_ask == CTRUE) && 
          (c_inline_ask_method(v9332,v15428) == CTRUE))
       Result = c_inline_method1(v9332,v15428,v3469);
      else { ClaireBoolean * v15418 = Optimize.OPT->allocation;
          OID  v15440 = Core.nil->value;
          (Optimize.OPT->allocation = CFALSE);
          { { list * v2208;
              { list * v7946 = list::empty(Kernel.emptySet);
                { Cint  v15425 = 1;
                  Cint  v15868 = v15431;
                  { OID gc_local;
                    while ((v15425 <= v15868))
                    { GC_LOOP;
                      v7946->addFast(GC_OID(c_strict_code_any((*(v15428))[v15425],psort_any((*(v3232))[v15425]))));
                      ++v15425;
                      GC_UNLOOP;} 
                    } 
                  } 
                v2208 = GC_OBJECT(list,v7946);
                } 
              v15440 = Call_method_I_method(v9332,v2208);
              } 
            GC_OID(v15440);} 
          if (Optimize.OPT->allocation != CTRUE)
           (Optimize.OPT->allocation = v15418);
          Result = v15440;
          } 
        } 
    else { if (Optimize.compiler->optimize_ask == CTRUE)
         { notice_void();
          ;} 
        Result = _oid_(open_message_property(v9332->selector,v15428));
        } 
      GC_UNBIND; return (Result);} 
  } 

OID  Call_method_I_method(method *v9332,list *v9066)
{ GC_BIND;
  if (BCONTAIN(status_I_restriction(v9332),1))
   { (Optimize.OPT->allocation = CTRUE);
    if (nth_integer(v9332->status,6) != CTRUE)
     { { bag *v_list; OID v_val;
        OID v15440,CLcount;
        v_list = v9066;
         v9066 = v_list->clone();
        for (CLcount= 1; CLcount <= v_list->length; CLcount++)
        { v15440 = (*(v_list))[CLcount];
          v_val = c_gc_I_any1(v15440);
          
          (*((list *) v9066))[CLcount] = v_val;} 
        } 
      GC_OBJECT(list,v9066);} 
    } 
  else { ClaireBoolean * g0145I;
    { ClaireBoolean *v_and;
      { v_and = Optimize.OPT->allocation;
        if (v_and == CFALSE) g0145I =CFALSE; 
        else { { Cint  v4130;
            { list * v5091;
              { bag * v4980 = v9066;
                list * v13024 = ((list *) empty_bag(v4980));
                { ITERATE(v15440);
                  for (START(v4980); NEXT(v15440);)
                  if ((OBJECT(ClaireBoolean,(*Optimize.c_gc_ask)(v15440))) == CTRUE)
                   v13024->addFast(v15440);
                  } 
                v5091 = GC_OBJECT(list,v13024);
                } 
              v4130 = v5091->length;
              } 
            v_and = ((v4130 > 1) ? CTRUE : CFALSE);
            } 
          if (v_and == CFALSE) g0145I =CFALSE; 
          else g0145I = CTRUE;} 
        } 
      } 
    
    if (g0145I == CTRUE) { { bag *v_list; OID v_val;
          OID v15440,CLcount;
          v_list = v9066;
           v9066 = v_list->clone();
          for (CLcount= 1; CLcount <= v_list->length; CLcount++)
          { v15440 = (*(v_list))[CLcount];
            v_val = c_gc_I_any1(v15440);
            
            (*((list *) v9066))[CLcount] = v_val;} 
          } 
        GC_OBJECT(list,v9066);} 
      } 
  if (BCONTAIN(v9332->status,2))
   (Optimize.OPT->use_nth_equal = CTRUE);
  if (BCONTAIN(v9332->status,7))
   (Optimize.OPT->use_string_update = CTRUE);
  if (BCONTAIN(v9332->status,3))
   (Optimize.OPT->use_update = CTRUE);
  if (legal_ask_module(v9332->module_I,_oid_(v9332)) != CTRUE)
   tformat_string(CSTRING("in call ~S~S\n"),0,list::alloc(2,_oid_(v9332->selector),_oid_(v9066)));
  { OID Result = 0;
    if (v9066->length == 1)
     { Call_method1 * v10264 = ((Call_method1 *) GC_OBJECT(Call_method1,new_object_class(Language._Call_method1)));
      (v10264->arg = v9332);
      (v10264->args = v9066);
      add_I_property(Kernel.instances,Language._Call_method1,11,_oid_(v10264));
      Result = _oid_(v10264);
      } 
    else if (v9066->length == 2)
     { Call_method2 * v10264 = ((Call_method2 *) GC_OBJECT(Call_method2,new_object_class(Language._Call_method2)));
      (v10264->arg = v9332);
      (v10264->args = v9066);
      add_I_property(Kernel.instances,Language._Call_method2,11,_oid_(v10264));
      Result = _oid_(v10264);
      } 
    else { Call_method * v10264 = ((Call_method *) GC_OBJECT(Call_method,new_object_class(Language._Call_method)));
        (v10264->arg = v9332);
        (v10264->args = v9066);
        add_I_property(Kernel.instances,Language._Call_method,11,_oid_(v10264));
        Result = _oid_(v10264);
        } 
      GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_Call_method_Optimize(Call_method *v9332)
{ GC_BIND;
  { ClaireType *Result ;
    { list * v6053;
      { { bag *v_list; OID v_val;
          OID v15440,CLcount;
          v_list = GC_OBJECT(list,v9332->args);
           v6053 = v_list->clone();
          for (CLcount= 1; CLcount <= v_list->length; CLcount++)
          { v15440 = (*(v_list))[CLcount];
            v_val = (*Optimize.c_type)(v15440);
            
            (*((list *) v6053))[CLcount] = v_val;} 
          } 
        GC_OBJECT(list,v6053);} 
      Result = use_range_method(v9332->arg,v6053);
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_Call_method_Optimize(Call_method *v9332)
{ return (_oid_(v9332));} 

ClaireBoolean * c_gc_ask_Call_method(Call_method *v9332)
{ GC_BIND;
  { ClaireBoolean *Result ;
    { method * v15429 = v9332->arg;
      { ClaireBoolean *v_and;
        { v_and = not_any(_oid_((INHERIT(v15429->range->isa,Kernel._class) ? (ClaireObject *) gcsafe_ask_class((ClaireClass *) OBJECT(ClaireClass,_oid_(v15429->range))) :  (ClaireObject *)  gcsafe_ask_type((ClaireType *) OBJECT(ClaireType,_oid_(v15429->range))))));
          if (v_and == CFALSE) Result =CFALSE; 
          else { v_and = ((v15429->range != Kernel._float) ? CTRUE : CFALSE);
            if (v_and == CFALSE) Result =CFALSE; 
            else { v_and = ((nth_integer(status_I_restriction(v15429),5) != CTRUE) ? CTRUE : ((((_inf_equal_type(v15429->range,Kernel._bag) == CTRUE) ? ((Optimize.OPT->loop_gc == CTRUE) ? CTRUE: CFALSE): CFALSE) != CTRUE) ? CTRUE : CFALSE));
              if (v_and == CFALSE) Result =CFALSE; 
              else { { ClaireBoolean *v_or;
                  { v_or = not_any(_oid_(nth_integer(status_I_restriction(v15429),4)));
                    if (v_or == CTRUE) v_and =CTRUE; 
                    else { { ClaireBoolean *v_or1;
                        { v_or1 = nth_integer(status_I_restriction(v15429),1);
                          if (v_or1 == CTRUE) v_or =CTRUE; 
                          else { { OID  v7013;
                              { OID gc_local;
                                ITERATE(v15440);
                                v7013= Kernel.cfalse;
                                bag *v15440_support;
                                v15440_support = GC_OBJECT(list,v9332->args);
                                for (START(v15440_support); NEXT(v15440);)
                                if ((OBJECT(ClaireBoolean,(*Optimize.c_gc_ask)(v15440))) == CTRUE)
                                 { v7013 = Kernel.ctrue;
                                  break;} 
                                } 
                              v_or1 = boolean_I_any(v7013);
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

ClaireFunction * functional_I_method_Optimize(method *v9332)
{ GC_BIND;
  { ClaireFunction *Result ;
    { OID  v15422 = GC_OID(get_property(Kernel.functional,v9332));
      property * v15432 = v9332->selector;
      Result = ((INHERIT(OWNER(v15422),Kernel._function)) ?
        OBJECT(ClaireFunction,v15422) :
        make_function_string(string_v((*Optimize.function_name)(_oid_(v15432),
          _oid_(v9332->domain),
          v15422))) );
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  nth_type_check_type(ClaireType *v3488,ClaireType *v3486,ClaireType *v3500)
{ GC_BIND;
  if (_inf_equal_type(v3500,GC_OBJECT(ClaireType,member_type(v3488))) != CTRUE)
   { warn_void();
    tformat_string(CSTRING("unsafe update on bag: type ~S into ~S [252]\n"),2,list::alloc(2,_oid_(v3500),_oid_(v3488)));
    } 
  { OID Result = 0;
    Result = _oid_(v3500);
    GC_UNBIND; return (Result);} 
  } 

ClaireBoolean * c_inline_ask_method(method *v9332,list *v15428)
{ GC_BIND;
  { ClaireBoolean *Result ;
    { lambda * v15422 = GC_OBJECT(lambda,v9332->formula);
      list * v3229 = GC_OBJECT(list,v15422->vars);
      OID  v15440 = GC_OID(v15422->body);
      Cint  v15431 = 1;
      { OID  v11771;
        { OID gc_local;
          ITERATE(v15438);
          v11771= Kernel.cfalse;
          bag *v15438_support;
          v15438_support = GC_OBJECT(list,v15422->vars);
          for (START(v15438_support); NEXT(v15438);)
          if ((occurrence_any(v15440,OBJECT(Variable,v15438)) > 1) && 
              ((designated_ask_any((*(v15428))[v15431]) != CTRUE) && 
                (inherit_ask_class(owner_any((*Kernel.range)(v15438)),Optimize._Pattern) != CTRUE)))
           { v11771 = Kernel.ctrue;
            break;} 
          else ++v15431;
            } 
        Result = not_any(v11771);
        } 
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  inline_optimize_ask_Call(Call *v9332)
{ GC_BIND;
  { OID Result = 0;
    { list * v15428 = GC_OBJECT(list,v9332->args);
      OID  v15429;
      { { list * v12732;
          { { bag *v_list; OID v_val;
              OID v15440,CLcount;
              v_list = v15428;
               v12732 = v_list->clone();
              for (CLcount= 1; CLcount <= v_list->length; CLcount++)
              { v15440 = (*(v_list))[CLcount];
                v_val = _oid_(set::alloc(1,v15440));
                
                (*((list *) v12732))[CLcount] = v_val;} 
              } 
            GC_OBJECT(list,v12732);} 
          v15429 = restriction_I_property(v9332->selector,v12732,CTRUE);
          } 
        GC_OID(v15429);} 
      if (Kernel._method == OWNER(v15429))
       { { ClaireBoolean * g0152I;
          { ClaireBoolean *v_and;
            { v_and = OBJECT(method,v15429)->inline_ask;
              if (v_and == CFALSE) g0152I =CFALSE; 
              else { { OID  v14654;
                  { ITERATE(v15435);
                    v14654= Kernel.cfalse;
                    for (START(OBJECT(restriction,v15429)->domain); NEXT(v15435);)
                    if (INHERIT(OBJECT(ClaireObject,v15435)->isa,Optimize._Pattern))
                     { v14654 = Kernel.ctrue;
                      break;} 
                    } 
                  v_and = boolean_I_any(v14654);
                  } 
                if (v_and == CFALSE) g0152I =CFALSE; 
                else { v_and = c_inline_ask_method(OBJECT(method,v15429),v15428);
                  if (v_and == CFALSE) g0152I =CFALSE; 
                  else g0152I = CTRUE;} 
                } 
              } 
            } 
          
          if (g0152I == CTRUE) Result = v15429;
            else Result = Kernel.cfalse;
          } 
        } 
      else Result = Kernel.cfalse;
        } 
    GC_UNBIND; return (Result);} 
  } 

