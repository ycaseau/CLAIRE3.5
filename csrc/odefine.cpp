/***** CLAIRE Compilation of file /Users/ycaseau/claire/v3.5/src/compile/odefine.cl 
         [version 3.5.01 / safety 5] Sun Jul 24 08:43:46 2016 *****/

#include <claire.h>
#include <Kernel.h>
#include <Core.h>
#include <Language.h>
#include <Reader.h>
#include <Optimize.h>
ClaireType * c_type_List_Optimize(List *v13540)
{ GC_BIND;
  ;{ ClaireType *Result ;
    if (((v13540->of == (NULL)) ? CTRUE : CFALSE) != CTRUE)
     Result = param_I_class(Kernel._list,v13540->of);
    else { OID  v61427 = _oid_(Kernel.emptySet);
        { OID gc_local;
          ITERATE(v61579);
          for (START(v13540->args); NEXT(v61579);)
          if (boolean_I_any(v61427) == CTRUE)
           v61427= _oid_(meet_class(OBJECT(ClaireClass,v61427),class_I_type(ptype_type(OBJECT(ClaireType,(*Optimize.c_type)(v61579))))));
          else v61427= _oid_(class_I_type(ptype_type(OBJECT(ClaireType,(*Optimize.c_type)(v61579)))));
            } 
        Result = nth_class1(Kernel._list,OBJECT(ClaireType,v61427));
        } 
      GC_UNBIND; return (Result);} 
  } 

OID  c_code_List_Optimize(List *v13540)
{ GC_BIND;
  (Optimize.OPT->allocation = CTRUE);
  { OID Result = 0;
    { List * v82400;
      { { List * v88616 = ((List *) GC_OBJECT(List,new_object_class(Language._List)));
          { Construct * v64279 = v88616; 
            list * v64280;
            { bag *v_list; OID v_val;
              OID v61579,CLcount;
              v_list = GC_OBJECT(list,v13540->args);
               v64280 = v_list->clone();
              for (CLcount= 1; CLcount <= v_list->length; CLcount++)
              { v61579 = (*(v_list))[CLcount];
                v_val = c_gc_I_any2(GC_OID((*Optimize.c_code)(v61579,
                  _oid_(Kernel._any))),GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(v61579))));
                
                (*((list *) v64280))[CLcount] = v_val;} 
              } 
            (v64279->args = v64280);} 
          add_I_property(Kernel.instances,Language._List,11,_oid_(v88616));
          v82400 = v88616;
          } 
        GC_OBJECT(List,v82400);} 
      if (((v13540->of == (NULL)) ? CTRUE : CFALSE) != CTRUE)
       { { ClaireBoolean * g0307I;
          { ClaireBoolean *v_or;
            { v_or = ((Optimize.compiler->safety > 4) ? CTRUE : CFALSE);
              if (v_or == CTRUE) g0307I =CTRUE; 
              else { v_or = ((equal(_oid_(v13540->of),_oid_(Kernel.emptySet)) == CTRUE) ? CTRUE : CFALSE);
                if (v_or == CTRUE) g0307I =CTRUE; 
                else { { OID  v42810;
                    { OID gc_local;
                      ITERATE(v61579);
                      v42810= Kernel.cfalse;
                      bag *v61579_support;
                      v61579_support = GC_OBJECT(list,v13540->args);
                      for (START(v61579_support); NEXT(v61579);)
                      { GC_LOOP;
                        if (_inf_equal_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(v61579))),GC_OBJECT(ClaireType,v13540->of)) != CTRUE)
                         { v42810 = Kernel.ctrue;
                          break;} 
                        GC_UNLOOP;} 
                      } 
                    v_or = not_any(v42810);
                    } 
                  if (v_or == CTRUE) g0307I =CTRUE; 
                  else g0307I = CFALSE;} 
                } 
              } 
            } 
          
          if (g0307I == CTRUE) { (v82400->of = v13540->of);
              Result = _oid_(v82400);
              } 
            else { warn_void();
            { list * v43771;
              { { OID v_bag;
                  GC_ANY(v43771= list::empty(Kernel.emptySet));
                  { { list * v72556;{ bag *v_list; OID v_val;
                        OID v61579,CLcount;
                        v_list = GC_OBJECT(list,v13540->args);
                         v72556 = v_list->clone();
                        for (CLcount= 1; CLcount <= v_list->length; CLcount++)
                        { v61579 = (*(v_list))[CLcount];
                          v_val = (*Optimize.c_type)(v61579);
                          
                          (*((list *) v72556))[CLcount] = v_val;} 
                        } 
                      
                      v_bag=_oid_(v72556);} 
                    GC_OID(v_bag);} 
                  ((list *) v43771)->addFast(v_bag);
                  ((list *) v43771)->addFast(GC_OID(_oid_(v13540->of)));} 
                GC_OBJECT(list,v43771);} 
              tformat_string(CSTRING("unsafe typed list: ~S not in ~S [262]\n"),2,v43771);
              } 
            { OID  v65874;
              { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                (v88616->selector = Core.check_in);
                (v88616->args = list::alloc(3,_oid_(v82400),
                  _oid_(Kernel._list),
                  GC_OID(_oid_(v13540->of))));
                add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
                v65874 = _oid_(v88616);
                } 
              Result = (*Optimize.c_code)(v65874,
                _oid_(Kernel._list));
              } 
            } 
          } 
        } 
      else Result = _oid_(v82400);
        } 
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_Set_Optimize(Set *v13540)
{ GC_BIND;
  ;{ ClaireType *Result ;
    if (((v13540->of == (NULL)) ? CTRUE : CFALSE) != CTRUE)
     Result = param_I_class(Kernel._set,v13540->of);
    else { OID  v61427 = _oid_(Kernel.emptySet);
        { OID gc_local;
          ITERATE(v61579);
          for (START(v13540->args); NEXT(v61579);)
          if (boolean_I_any(v61427) == CTRUE)
           v61427= _oid_(meet_class(OBJECT(ClaireClass,v61427),class_I_type(OBJECT(ClaireType,(*Optimize.c_type)(v61579)))));
          else v61427= _oid_(class_I_type(OBJECT(ClaireType,(*Optimize.c_type)(v61579))));
            } 
        Result = nth_class1(Kernel._set,OBJECT(ClaireType,v61427));
        } 
      GC_UNBIND; return (Result);} 
  } 

OID  c_code_Set_Optimize(Set *v13540)
{ GC_BIND;
  (Optimize.OPT->allocation = CTRUE);
  { OID Result = 0;
    { Set * v82400;
      { { Set * v88616 = ((Set *) GC_OBJECT(Set,new_object_class(Language._Set)));
          { Construct * v64307 = v88616; 
            list * v64308;
            { bag *v_list; OID v_val;
              OID v61579,CLcount;
              v_list = GC_OBJECT(list,v13540->args);
               v64308 = v_list->clone();
              for (CLcount= 1; CLcount <= v_list->length; CLcount++)
              { v61579 = (*(v_list))[CLcount];
                v_val = c_gc_I_any2(GC_OID((*Optimize.c_code)(v61579,
                  _oid_(Kernel._any))),GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(v61579))));
                
                (*((list *) v64308))[CLcount] = v_val;} 
              } 
            (v64307->args = v64308);} 
          add_I_property(Kernel.instances,Language._Set,11,_oid_(v88616));
          v82400 = v88616;
          } 
        GC_OBJECT(Set,v82400);} 
      if (((v13540->of == (NULL)) ? CTRUE : CFALSE) != CTRUE)
       { { ClaireBoolean * g0314I;
          { ClaireBoolean *v_or;
            { v_or = ((Optimize.compiler->safety > 4) ? CTRUE : CFALSE);
              if (v_or == CTRUE) g0314I =CTRUE; 
              else { v_or = ((equal(_oid_(v13540->of),_oid_(Kernel.emptySet)) == CTRUE) ? CTRUE : CFALSE);
                if (v_or == CTRUE) g0314I =CTRUE; 
                else { { OID  v69718;
                    { OID gc_local;
                      ITERATE(v61579);
                      v69718= Kernel.cfalse;
                      bag *v61579_support;
                      v61579_support = GC_OBJECT(list,v13540->args);
                      for (START(v61579_support); NEXT(v61579);)
                      { GC_LOOP;
                        if (_inf_equal_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(v61579))),GC_OBJECT(ClaireType,v13540->of)) != CTRUE)
                         { v69718 = Kernel.ctrue;
                          break;} 
                        GC_UNLOOP;} 
                      } 
                    v_or = not_any(v69718);
                    } 
                  if (v_or == CTRUE) g0314I =CTRUE; 
                  else g0314I = CFALSE;} 
                } 
              } 
            } 
          
          if (g0314I == CTRUE) { (v82400->of = v13540->of);
              Result = _oid_(v82400);
              } 
            else { warn_void();
            { list * v70679;
              { { OID v_bag;
                  GC_ANY(v70679= list::empty(Kernel.emptySet));
                  { { list * v72563;{ bag *v_list; OID v_val;
                        OID v61579,CLcount;
                        v_list = GC_OBJECT(list,v13540->args);
                         v72563 = v_list->clone();
                        for (CLcount= 1; CLcount <= v_list->length; CLcount++)
                        { v61579 = (*(v_list))[CLcount];
                          v_val = (*Optimize.c_type)(v61579);
                          
                          (*((list *) v72563))[CLcount] = v_val;} 
                        } 
                      
                      v_bag=_oid_(v72563);} 
                    GC_OID(v_bag);} 
                  ((list *) v70679)->addFast(v_bag);
                  ((list *) v70679)->addFast(GC_OID(_oid_(v13540->of)));} 
                GC_OBJECT(list,v70679);} 
              tformat_string(CSTRING("unsafe typed set: ~S not in ~S [262]\n"),2,v70679);
              } 
            { OID  v72601;
              { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                (v88616->selector = Core.check_in);
                (v88616->args = list::alloc(3,_oid_(v82400),
                  _oid_(Kernel._set),
                  GC_OID(_oid_(v13540->of))));
                add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
                v72601 = _oid_(v88616);
                } 
              Result = (*Optimize.c_code)(v72601,
                _oid_(Kernel._set));
              } 
            } 
          } 
        } 
      else Result = _oid_(v82400);
        } 
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_Tuple_Optimize(Tuple *v13540)
{ GC_BIND;
  { ClaireType *Result ;
    { list * v73562;
      { { bag *v_list; OID v_val;
          OID v82400,CLcount;
          v_list = v13540->args;
           v73562 = v_list->clone();
          for (CLcount= 1; CLcount <= v_list->length; CLcount++)
          { v82400 = (*(v_list))[CLcount];
            v_val = (*Optimize.c_type)(v82400);
            
            (*((list *) v73562))[CLcount] = v_val;} 
          } 
        GC_OBJECT(list,v73562);} 
      Result = tuple_I_list(v73562);
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_Tuple_Optimize(Tuple *v13540)
{ GC_BIND;
  (Optimize.OPT->allocation = CTRUE);
  { OID Result = 0;
    { Tuple * v88616 = ((Tuple *) GC_OBJECT(Tuple,new_object_class(Language._Tuple)));
      { Construct * v64336 = v88616; 
        list * v64337;
        { bag *v_list; OID v_val;
          OID v61579,CLcount;
          v_list = GC_OBJECT(list,v13540->args);
           v64337 = v_list->clone();
          for (CLcount= 1; CLcount <= v_list->length; CLcount++)
          { v61579 = (*(v_list))[CLcount];
            v_val = c_gc_I_any2(GC_OID((*Optimize.c_code)(v61579,
              _oid_(Kernel._any))),GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(v61579))));
            
            (*((list *) v64337))[CLcount] = v_val;} 
          } 
        (v64336->args = v64337);} 
      add_I_property(Kernel.instances,Language._Tuple,11,_oid_(v88616));
      Result = _oid_(v88616);
      } 
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_Definition_Optimize(Definition *v13540)
{ { ClaireType *Result ;
    if (_inf_equalt_class(v13540->arg,Kernel._exception) == CTRUE)
     Result = Kernel.emptySet;
    else Result = v13540->arg;
      return (Result);} 
  } 

OID  c_code_Definition_Optimize(Definition *v13540,ClaireClass *v82395)
{ GC_BIND;
  { OID Result = 0;
    { ClaireClass * v61558 = v13540->arg;
      Variable * v61589;
      { { Cint  v97587;
          { (Optimize.OPT->max_vars = (Optimize.OPT->max_vars+1));
            v97587 = 0;
            } 
          v61589 = Variable_I_symbol(OBJECT(symbol,Optimize._starname_star->value),v97587,v61558);
          } 
        GC_OBJECT(Variable,v61589);} 
      OID  v61579 = GC_OID(total_ask_class(v61558,GC_OBJECT(list,v13540->args)));
      if (v61558->open <= 0)
       close_exception(((general_error *) (*Core._general_error)(_string_(CSTRING("[105] cannot instantiate ~S")),
        _oid_(list::alloc(1,_oid_(v61558))))));
      if (boolean_I_any(v61579) == CTRUE)
       Result = (*Optimize.c_code)(v61579,
        _oid_(v82395));
      else { OID  v98548;
          { Let * v88616 = ((Let *) GC_OBJECT(Let,new_object_class(Language._Let)));
            (v88616->var = v61589);
            { Let * v64341 = v88616; 
              OID  v64342;
              { Cast * v88616 = ((Cast *) GC_OBJECT(Cast,new_object_class(Language._Cast)));
                { Cast * v64343 = v88616; 
                  OID  v64344;
                  { OID  v103353;
                    { { OID  v124495;
                        { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                          (v88616->selector = Core.new_I);
                          (v88616->args = list::alloc(1,_oid_(v61558)));
                          add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
                          v124495 = _oid_(v88616);
                          } 
                        v103353 = (*Optimize.c_code)(v124495,
                          _oid_(Kernel._object));
                        } 
                      GC_OID(v103353);} 
                    v64344 = c_gc_I_any1(v103353);
                    } 
                  (v64343->arg = v64344);} 
                (v88616->set_arg = v61558);
                add_I_property(Kernel.instances,Language._Cast,11,_oid_(v88616));
                v64342 = _oid_(v88616);
                } 
              (v64341->value = v64342);} 
            { Let * v64368 = v88616; 
              OID  v64369;
              { Do * v88616 = ((Do *) GC_OBJECT(Do,new_object_class(Language._Do)));
                store_object(v88616,
                  2,
                  Kernel._object,
                  analyze_I_class(v61558,_oid_(v61589),GC_OBJECT(list,v13540->args),list::empty()),
                  CFALSE);
                add_I_property(Kernel.instances,Language._Do,11,_oid_(v88616));
                v64369 = _oid_(v88616);
                } 
              (v64368->arg = v64369);} 
            add_I_property(Kernel.instances,Language._Let,11,_oid_(v88616));
            v98548 = _oid_(v88616);
            } 
          Result = (*Optimize.c_code)(v98548,
            _oid_(v82395));
          } 
        } 
    GC_UNBIND; return (Result);} 
  } 

OID  total_ask_class(ClaireClass *v13540,list *v82388)
{ GC_BIND;
  { OID Result = 0;
    { list * v63772 = GC_OBJECT(list,OBJECT(list,(*Optimize.get_indexed)(_oid_(v13540))));
      Cint  v82390 = v63772->length;
      { ClaireBoolean * g0334I;
        { ClaireBoolean *v_and;
          { v_and = not_any(_oid_(Optimize.compiler->diet_ask));
            if (v_and == CFALSE) g0334I =CFALSE; 
            else { v_and = ((v82388->length == (v82390-1)) ? CTRUE : CFALSE);
              if (v_and == CFALSE) g0334I =CFALSE; 
              else { v_and = ((v13540->open == ClEnv->ephemeral) ? CTRUE : ((_inf_equalt_class(v13540,Kernel._exception) == CTRUE) ? CTRUE : CFALSE));
                if (v_and == CFALSE) g0334I =CFALSE; 
                else { v_and = ((v82390 <= 4) ? CTRUE : CFALSE);
                  if (v_and == CFALSE) g0334I =CFALSE; 
                  else { { OID  v129300;
                      { Cint  v82385 = 2;
                        Cint  v64370 = v82390;
                        { v129300= _oid_(CFALSE);
                          while ((v82385 <= v64370))
                          { if ((((*Kernel.srange)((*(v63772))[v82385]) == _oid_(Kernel._integer)) ? CTRUE : (((*Kernel.srange)((*(v63772))[v82385]) == _oid_(Kernel._any)) ? CTRUE : CFALSE)) != CTRUE)
                             { v129300 = Kernel.ctrue;
                              break;} 
                            ++v82385;
                            } 
                          } 
                        } 
                      v_and = not_any(v129300);
                      } 
                    if (v_and == CFALSE) g0334I =CFALSE; 
                    else g0334I = CTRUE;} 
                  } 
                } 
              } 
            } 
          } 
        
        if (g0334I == CTRUE) { OID  v61558;
            { { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                (v88616->selector = ((v82388->length == 0) ?
                  Core.new_I :
                  Optimize.anyObject_I ));
                { Call * v64373 = v88616; 
                  list * v64374;
                  { list * v1111;
                    { { bag *v_list; OID v_val;
                        OID v82400,CLcount;
                        v_list = v82388;
                         v1111 = v_list->clone();
                        for (CLcount= 1; CLcount <= v_list->length; CLcount++)
                        { v82400 = (*(v_list))[CLcount];
                          v_val = c_gc_I_any1(GC_OID((*Optimize.c_code)(GC_OID((*(OBJECT(bag,(*Core.args)(v82400))))[2]),
                            _oid_(Kernel._any))));
                          
                          (*((list *) v1111))[CLcount] = v_val;} 
                        } 
                      GC_OBJECT(list,v1111);} 
                    v64374 = cons_any(_oid_(v13540),v1111);
                    } 
                  (v64373->args = v64374);} 
                add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
                v61558 = _oid_(v88616);
                } 
              GC_OID(v61558);} 
            OID  v82389 = GC_OID(_oid_(_at_property1(Kernel.close,v13540)));
            if (_inf_equal_type(v13540,Kernel._exception) != CTRUE)
             (Optimize.OPT->allocation = CTRUE);
            if (v82388->length == 0)
             v61558= GC_OID((*Optimize.c_code)(v61558));
            if (boolean_I_any(v82389) == CTRUE)
             { Call_method1 * v88616 = ((Call_method1 *) GC_OBJECT(Call_method1,new_object_class(Language._Call_method1)));
              update_property(Kernel.arg,
                v88616,
                2,
                Kernel._object,
                v82389);
              (v88616->args = list::alloc(1,v61558));
              add_I_property(Kernel.instances,Language._Call_method1,11,_oid_(v88616));
              Result = _oid_(v88616);
              } 
            else Result = v61558;
              } 
          else Result = Kernel.cfalse;
        } 
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  analyze_I_class(ClaireClass *v82379,OID v13540,list *v61567,list *v63772)
{ GC_RESERVE(15);  // v3.0.55 optim !
  { OID Result = 0;
    { ClaireBoolean * v117673 = ((v82379->open != 4) ? ((boolean_I_any(_oid_(v63772)) != CTRUE) ? ((Optimize.compiler->class2file_ask != CTRUE) ? CTRUE: CFALSE): CFALSE): CFALSE);
      list * v82394;
      { { bag *v_list; OID v_val;
          OID v82400,CLcount;
          v_list = v61567;
           v82394 = v_list->clone(Kernel._any);
          for (CLcount= 1; CLcount <= v_list->length; CLcount++)
          { v82400 = (*(v_list))[CLcount];
            { OID  v82392 = GC_OID((*(OBJECT(Call,v82400)->args))[1]);
              OID  v82401 = GC_OID((*(OBJECT(Call,v82400)->args))[2]);
              ClaireObject * v82395 = GC_OBJECT(ClaireObject,_at_property1(OBJECT(property,v82392),v82379));
              ClaireBoolean * v45118 = (((*Kernel.open)(v82392) == 0) ? ((Kernel._slot == v82395->isa) ? CTRUE: CFALSE): CFALSE);
              GC__ANY(v63772 = v63772->addFast(v82392), 4);
              { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                (v88616->selector = ((v45118 == CTRUE) ?
                  Kernel.put :
                  Core.write ));
                { Call * v64376 = v88616; 
                  list * v64398;
                  { OID v_bag;
                    GC_ANY(v64398= list::empty(Kernel.emptySet));
                    ((list *) v64398)->addFast(v82392);
                    ((list *) v64398)->addFast(v13540);
                    { if ((v45118 != CTRUE) || 
                          (_inf_equal_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(v82401))),GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Kernel.range)(_oid_(v82395))))) == CTRUE))
                       v_bag = v82401;
                      else v_bag = c_check_any(GC_OID((*Optimize.c_code)(v82401,
                          _oid_(Kernel._any))),GC_OID((*Optimize.c_code)(GC_OID((*Kernel.range)(_oid_(v82395))),
                          _oid_(Kernel._type))));
                        GC_OID(v_bag);} 
                    ((list *) v64398)->addFast(v_bag);} 
                  (v64376->args = v64398);} 
                add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
                v_val = _oid_(v88616);
                } 
              } 
            
            (*((list *) v82394))[CLcount] = v_val;} 
          } 
        GC_OBJECT(list,v82394);} 
      if (v117673 == CTRUE)
       { { OID  v24175;
          { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
            (v88616->selector = Kernel.add);
            (v88616->args = list::alloc(3,_oid_(Kernel.instances),
              _oid_(v82379),
              v13540));
            add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
            v24175 = _oid_(v88616);
            } 
          v82394 = v82394->addFast(v24175);
          } 
        GC_OBJECT(list,v82394);} 
      if (Optimize.compiler->class2file_ask != CTRUE)
       { OID gc_local;
        ITERATE(v82395);
        bag *v82395_support;
        v82395_support = GC_OBJECT(list,OBJECT(bag,(*Optimize.get_indexed)(_oid_(v82379))));
        for (START(v82395_support); NEXT(v82395);)
        { GC_LOOP;
          { property * v82392 = OBJECT(restriction,v82395)->selector;
            OID  v82398 = GC_OID(OBJECT(slot,v82395)->DEFAULT);
            { ClaireBoolean * g0342I;
              { ClaireBoolean *v_and;
                { v_and = known_ask_any(v82398);
                  if (v_and == CFALSE) g0342I =CFALSE; 
                  else { { OID  v26097;
                      if (multi_ask_any(_oid_(v82392)) == CTRUE)
                       v26097 = v82398;
                      else v26097 = Kernel.ctrue;
                        v_and = boolean_I_any(v26097);
                      } 
                    if (v_and == CFALSE) g0342I =CFALSE; 
                    else { v_and = not_any(_oid_(v63772->memq(_oid_(v82392))));
                      if (v_and == CFALSE) g0342I =CFALSE; 
                      else { v_and = ((((v82392->inverse == (NULL)) ? CTRUE : CFALSE) != CTRUE) ? CTRUE : ((((v82392->if_write == CNULL) ? CTRUE : CFALSE) != CTRUE) ? CTRUE : (((OBJECT(slot,v82395)->srange != Kernel._object) && 
                            ((OBJECT(slot,v82395)->srange != Kernel._float) && 
                              (inherit_ask_class(OWNER(v82398),Kernel._integer) != CTRUE))) ? CTRUE : CFALSE)));
                        if (v_and == CFALSE) g0342I =CFALSE; 
                        else g0342I = CTRUE;} 
                      } 
                    } 
                  } 
                } 
              
              if (g0342I == CTRUE) { OID  v45936;
                  if (designated_ask_any(v82398) == CTRUE)
                   v45936 = v82398;
                  else { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                      (v88616->selector = Kernel.DEFAULT);
                      { Call * v64402 = v88616; 
                        list * v64403;
                        { OID v_bag;
                          GC_ANY(v64403= list::empty(Kernel.emptySet));
                          { { Cast * v88616 = ((Cast *) GC_OBJECT(Cast,new_object_class(Language._Cast)));
                              { Cast * v64404 = v88616; 
                                OID  v64405;
                                { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                                  (v88616->selector = Core._at);
                                  (v88616->args = list::alloc(2,_oid_(v82392),_oid_(v82379)));
                                  add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
                                  v64405 = _oid_(v88616);
                                  } 
                                (v64404->arg = v64405);} 
                              (v88616->set_arg = Kernel._slot);
                              add_I_property(Kernel.instances,Language._Cast,11,_oid_(v88616));
                              v_bag = _oid_(v88616);
                              } 
                            GC_OID(v_bag);} 
                          ((list *) v64403)->addFast(v_bag);} 
                        (v64402->args = v64403);} 
                      add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
                      v45936 = _oid_(v88616);
                      } 
                    { { OID  v30902;
                      { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                        (v88616->selector = Core.write);
                        (v88616->args = list::alloc(3,_oid_(v82392),
                          v13540,
                          v45936));
                        add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
                        v30902 = _oid_(v88616);
                        } 
                      v82394 = v82394->addFast(v30902);
                      } 
                     GC__ANY(v82394, 7);} 
                  } 
                } 
            } 
          GC_UNLOOP;} 
        } 
      { OID  v82389 = GC_OID(_oid_(_at_property1(Kernel.close,v82379)));
        { OID  v31863;
          if (boolean_I_any(v82389) == CTRUE)
           { Call_method1 * v88616 = ((Call_method1 *) GC_OBJECT(Call_method1,new_object_class(Language._Call_method1)));
            update_property(Kernel.arg,
              v88616,
              2,
              Kernel._object,
              v82389);
            (v88616->args = list::alloc(1,v13540));
            add_I_property(Kernel.instances,Language._Call_method1,11,_oid_(v88616));
            v31863 = _oid_(v88616);
            } 
          else v31863 = v13540;
            v82394 = v82394->addFast(v31863);
          } 
        } 
      Result = _oid_(v82394);
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_Defobj_Optimize(Defobj *v13540,ClaireClass *v82395)
{ GC_BIND;
  { OID Result = 0;
    { ClaireBoolean * v61556 = Optimize.OPT->allocation;
      ClaireClass * v61558 = v13540->arg;
      OID  v82391 = GC_OID(get_symbol(v13540->ident));
      OID  v61589;
      { if ((v82391 != CNULL) && 
            (inherit_ask_class(OWNER(v82391),Core._global_variable) != CTRUE))
         v61589 = v82391;
        else { Variable * v72682;{ Cint  v55888;
              { (Optimize.OPT->max_vars = (Optimize.OPT->max_vars+1));
                v55888 = 0;
                } 
              v72682 = Variable_I_symbol(OBJECT(symbol,Optimize._starname_star->value),v55888,v61558);
              } 
            
            v61589=_oid_(v72682);} 
          GC_OID(v61589);} 
      Call * v74021;
      { { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
          (v88616->selector = Optimize.object_I);
          (v88616->args = list::alloc(2,_oid_(v13540->ident),_oid_(v61558)));
          add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
          v74021 = v88616;
          } 
        GC_OBJECT(Call,v74021);} 
      OID  v74022 = GC_OID(analyze_I_class(v61558,v61589,GC_OBJECT(list,v13540->args),list::alloc(1,_oid_(Kernel.name))));
      OID  v61579;
      if (inherit_ask_class(OWNER(v61589),Language._Variable) != CTRUE)
       { Do * v88616 = ((Do *) GC_OBJECT(Do,new_object_class(Language._Do)));
        store_object(v88616,
          2,
          Kernel._object,
          (*Kernel.cons)(_oid_(v74021),
            v74022),
          CFALSE);
        add_I_property(Kernel.instances,Language._Do,11,_oid_(v88616));
        v61579 = _oid_(v88616);
        } 
      else { Let * v88616 = ((Let *) GC_OBJECT(Let,new_object_class(Language._Let)));
          store_object(v88616,
            2,
            Kernel._object,
            v61589,
            CFALSE);
          (v88616->value = _oid_(v74021));
          { Let * v64433 = v88616; 
            OID  v64434;
            { Do * v88616 = ((Do *) GC_OBJECT(Do,new_object_class(Language._Do)));
              store_object(v88616,
                2,
                Kernel._object,
                v74022,
                CFALSE);
              add_I_property(Kernel.instances,Language._Do,11,_oid_(v88616));
              v64434 = _oid_(v88616);
              } 
            (v64433->arg = v64434);} 
          add_I_property(Kernel.instances,Language._Let,11,_oid_(v88616));
          v61579 = _oid_(v88616);
          } 
        if (v61558->open <= 0)
       close_exception(((general_error *) (*Core._general_error)(_string_(CSTRING("[105] cannot instantiate ~S")),
        _oid_(list::alloc(1,_oid_(v61558))))));
      if (v82391 != CNULL)
       { if (contain_ask_list(Optimize.OPT->objects,v82391) != CTRUE)
         { GC_OBJECT(list,Optimize.OPT->objects)->addFast(v82391);
          (*Optimize.c_register)(v82391);
          } 
        } 
      else { warn_void();
          tformat_string(CSTRING("~S is unknown [265]\n"),2,list::alloc(1,_oid_(v13540->ident)));
          } 
        v61579= GC_OID((*Optimize.c_code)(v61579,
        _oid_(v82395)));
      if (_inf_equal_type(v13540->arg,Kernel._exception) == CTRUE)
       (Optimize.OPT->allocation = v61556);
      Result = v61579;
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_Defclass_Optimize(Defclass *v13540,ClaireClass *v82395)
{ GC_BIND;
  { OID Result = 0;
    { symbol * v77208 = v13540->ident;
      OID  v82391 = GC_OID(get_symbol(v77208));
      Call * v50377;
      { ClaireObject *V_CC ;
        if (v82391 != CNULL)
         { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
          (v88616->selector = Core.class_I);
          (v88616->args = list::alloc(2,_oid_(v77208),_oid_(v13540->arg)));
          add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
          V_CC = v88616;
          } 
        else close_exception(((general_error *) (*Core._general_error)(_string_(CSTRING("[internal] cannot compile unknown class ~S")),
            _oid_(list::alloc(1,_oid_(v77208))))));
          v50377= (Call *) V_CC;} 
      Do * v61579;
      { { Do * v88616 = ((Do *) GC_OBJECT(Do,new_object_class(Language._Do)));
          { Do * v64436 = v88616; 
            list * v64437;
            { list * v61654;
              { { list * v82796;
                  { { bag *v_list; OID v_val;
                      OID v82400,CLcount;
                      v_list = GC_OBJECT(list,v13540->args);
                       v82796 = v_list->clone();
                      for (CLcount= 1; CLcount <= v_list->length; CLcount++)
                      { v82400 = (*(v_list))[CLcount];
                        { OID  v82398 = CNULL;
                          if (INHERIT(OWNER(v82400),Language._Call))
                           { v82398= GC_OID((*(OBJECT(Call,v82400)->args))[2]);
                            v82400= GC_OID((*(OBJECT(Call,v82400)->args))[1]);
                            } 
                          { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                            (v88616->selector = Kernel.add_slot);
                            (v88616->args = list::alloc(5,v82391,
                              _oid_(make_a_property_any(_oid_(OBJECT(Variable,v82400)->pname))),
                              GC_OID((*Kernel.range)(v82400)),
                              v82398,
                              0));
                            add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
                            v_val = _oid_(v88616);
                            } 
                          } 
                        
                        (*((list *) v82796))[CLcount] = v_val;} 
                      } 
                    GC_OBJECT(list,v82796);} 
                  list * v83757;
                  if (v13540->params->length != 0)
                   { OID v_bag;
                    GC_ANY(v83757= list::empty(Kernel.emptySet));
                    { { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                        (v88616->selector = Kernel.put);
                        (v88616->args = list::alloc(3,_oid_(Kernel.params),
                          v82391,
                          GC_OID(_oid_(v13540->params))));
                        add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
                        v_bag = _oid_(v88616);
                        } 
                      GC_OID(v_bag);} 
                    ((list *) v83757)->addFast(v_bag);} 
                  else v83757 = list::empty();
                    v61654 = append_list(v82796,v83757);
                  } 
                GC_OBJECT(list,v61654);} 
              v64437 = cons_any(_oid_(v50377),v61654);
              } 
            (v64436->args = v64437);} 
          add_I_property(Kernel.instances,Language._Do,11,_oid_(v88616));
          v61579 = v88616;
          } 
        GC_OBJECT(Do,v61579);} 
      if (contain_ask_list(Optimize.OPT->objects,v82391) != CTRUE)
       { GC_OBJECT(list,Optimize.OPT->objects)->addFast(v82391);
        (*Optimize.c_register)(v82391);
        } 
      Result = (*Optimize.c_code)(_oid_(v61579),
        _oid_(v82395));
      } 
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_Defmethod_Optimize(Defmethod *v13540)
{ return (Kernel._any);} 

OID  c_code_Defmethod_Optimize(Defmethod *v13540)
{ GC_BIND;
  { OID Result = 0;
    { property * v63904 = v13540->arg->selector;
      list * v82388 = GC_OBJECT(list,v13540->arg->args);
      list * v63778 = (((v82388->length == 1) && 
          ((*(v82388))[1] == _oid_(ClEnv))) ?
        list::alloc(1,GC_OID(_oid_(Variable_I_symbol(OBJECT(symbol,Optimize._starname_star->value),0,Kernel._void)))) :
        v82388 );
      list * v63775 = GC_OBJECT(list,extract_signature_I_list(v63778));
      list * v64489 = GC_OBJECT(list,extract_range_any(GC_OID(v13540->set_arg),v63778,GC_OBJECT(list,OBJECT(list,Language.LDEF->value))));
      OID  v12362;
      { if ((boolean_I_any(v13540->inline_ask) == CTRUE) && 
            (Optimize.compiler->inline_ask == CTRUE))
         { print_in_string_void();
          princ_string(CSTRING("lambda[("));
          ppvariable_list(v63778);
          princ_string(CSTRING("),"));
          print_any(GC_OID(v13540->body));
          princ_string(CSTRING("]"));
          v12362 = _string_(end_of_print_void());
          } 
        else v12362 = Kernel.cfalse;
          GC_OID(v12362);} 
      list * v29046 = GC_OBJECT(list,extract_status_new_any(GC_OID(v13540->body)));
      OID  v49519 = GC_OID((*Core._at)(_oid_(v63904),
        (*(v63775))[2]));
      method * v82389;
      { ClaireObject *V_CC ;
        if (Kernel._method == OBJECT(ClaireObject,v49519)->isa)
         V_CC = OBJECT(method,v49519);
        else close_exception(((general_error *) (*Core._general_error)(_string_(CSTRING("[internal] the method ~S @ ~S is not known")),
            _oid_(list::alloc(2,_oid_(v63904),(*(v63775))[2])))));
          v82389= (method *) V_CC;} 
      OID  v31940 = v82389->status;
      ((*(v29046))[2]=get_property(Kernel.functional,v82389));
      if ((Optimize.compiler->inline_ask != CTRUE) && 
          ((v63904 == Language.Iterate) || 
              (v63904 == Language.iterate)))
       Result = Core.nil->value;
      else if (((*(v64489))[1] == _oid_(Kernel._void)) && 
          (sort_pattern_ask_list(v63778,GC_OID(v13540->body)) == CTRUE))
       Result = sort_code_Defmethod(v13540,v63778);
      else { if ((*(v29046))[3] != _oid_(Kernel.body))
           { char * v63819 = GC_STRING(string_v((*Optimize.function_name)(_oid_(v63904),
              (*(v63775))[2],
              (*(v29046))[2])));
            lambda * v63757 = GC_OBJECT(lambda,lambda_I_list(v63778,(*(v29046))[3]));
            Cint  v127083 = ((Optimize.OPT->recompute == CTRUE) ?
              c_status_any(GC_OID(v63757->body),GC_OBJECT(list,v63757->vars)) :
              status_I_restriction(v82389) );
            compile_lambda_string(v63819,v63757,_oid_(v82389));
            if (((*(v29046))[1] == CNULL) || 
                (Optimize.OPT->recompute == CTRUE))
             { if ((Optimize.OPT->use_nth_equal != CTRUE) && 
                  (BCONTAIN(v127083,2)))
               v127083= (v127083-exp2_integer(2));
              if ((Optimize.OPT->use_update != CTRUE) && 
                  (BCONTAIN(v127083,3)))
               v127083= (v127083-exp2_integer(3));
              if ((Optimize.OPT->use_string_update != CTRUE) && 
                  (BCONTAIN(v127083,7)))
               v127083= (v127083-exp2_integer(7));
              if ((Optimize.OPT->allocation != CTRUE) && 
                  (BCONTAIN(v127083,1)))
               v127083= (v127083-exp2_integer(1));
              ((*(v29046))[1]=v127083);
              } 
            ((*(v29046))[2]=_oid_(make_function_string(v63819)));
            } 
          if (INHERIT(OWNER(v13540->set_arg),Core._global_variable))
           ((*(v64489))[1]=v13540->set_arg);
          else if ((INHERIT(v82389->range->isa,Kernel._class)) && 
              (inherit_ask_class(OWNER((*(v64489))[1]),Kernel._class) != CTRUE))
           ((*(v64489))[1]=_oid_(v82389->range));
          { OID  v61568 = GC_OID(add_method_I_method(v82389,
              OBJECT(list,(*(v63775))[1]),
              (*(v64489))[1],
              (*(v29046))[1],
              OBJECT(ClaireFunction,(*(v29046))[2])));
            { OID  v84718;
              if ((boolean_I_any(v13540->inline_ask) == CTRUE) && 
                  ((Optimize.compiler->inline_ask == CTRUE) && 
                    (Optimize.compiler->diet_ask != CTRUE)))
               { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                (v88616->selector = Core.inlineok_ask);
                (v88616->args = list::alloc(2,v61568,v12362));
                add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
                v84718 = _oid_(v88616);
                } 
              else if ((boolean_I_any((*(v64489))[2]) == CTRUE) && 
                  (Optimize.compiler->diet_ask != CTRUE))
               { char * v63819 = GC_STRING(append_string(GC_STRING(string_v((*Optimize.function_name)(_oid_(v63904),
                  (*(v63775))[2],
                  (*(v29046))[2]))),CSTRING("_type")));
                compile_lambda_string(v63819,OBJECT(lambda,(*(v64489))[2]),_oid_(Kernel._type));
                { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                  (v88616->selector = Core.write);
                  (v88616->args = list::alloc(3,Language.typing->value,
                    v61568,
                    _oid_(make_function_string(v63819))));
                  add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
                  v84718 = _oid_(v88616);
                  } 
                } 
              else v84718 = v61568;
                Result = (*Optimize.c_code)(v84718);
              } 
            } 
          } 
        } 
    GC_UNBIND; return (Result);} 
  } 

ClaireBoolean * sort_pattern_ask_list(list *v63778,OID v126127)
{ GC_BIND;
  { ClaireBoolean *Result ;
    { ClaireBoolean *v_and;
      { v_and = ((v63778->length == 1) ? CTRUE : CFALSE);
        if (v_and == CFALSE) Result =CFALSE; 
        else { if (INHERIT(OWNER(v126127),Language._Call))
           { ClaireBoolean *v_and1;
            { v_and1 = ((OBJECT(Call,v126127)->selector == Core.sort) ? CTRUE : CFALSE);
              if (v_and1 == CFALSE) v_and =CFALSE; 
              else { { OID  v63368 = GC_OID((*(OBJECT(Call,v126127)->args))[1]);
                  v_and1 = ((INHERIT(OWNER(v63368),Language._Call)) ?
                    ((OBJECT(Call,v63368)->selector == Core._at) ? ((INHERIT(OWNER((*(OBJECT(Call,v63368)->args))[1]),Kernel._property)) ? CTRUE: CFALSE): CFALSE) :
                    CFALSE );
                  } 
                if (v_and1 == CFALSE) v_and =CFALSE; 
                else { v_and1 = ((equal(lexical_build_any(GC_OID((*(OBJECT(Call,v126127)->args))[2]),v63778,0),(*(v63778))[1]) == CTRUE) ? CTRUE : CFALSE);
                  if (v_and1 == CFALSE) v_and =CFALSE; 
                  else v_and = CTRUE;} 
                } 
              } 
            } 
          else v_and = CFALSE;
            if (v_and == CFALSE) Result =CFALSE; 
          else Result = CTRUE;} 
        } 
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  sort_code_Defmethod(Defmethod *v13540,list *v63778)
{ GC_BIND;
  { OID Result = 0;
    { OID  v82388 = (*(v63778))[1];
      OID  v82382 = GC_OID((*(OBJECT(bag,(*Core.args)(GC_OID((*(OBJECT(bag,(*Core.args)(GC_OID(v13540->body)))))[1])))))[1]);
      Variable * v82389 = GC_OBJECT(Variable,Variable_I_symbol(symbol_I_string2(CSTRING("m")),0,Kernel._integer));
      Variable * v82390 = GC_OBJECT(Variable,Variable_I_symbol(symbol_I_string2(CSTRING("n")),0,Kernel._integer));
      Variable * v82400 = GC_OBJECT(Variable,Variable_I_symbol(symbol_I_string2(CSTRING("x")),0,GC_OBJECT(ClaireType,member_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Kernel.range)(v82388)))))));
      Variable * v82392 = GC_OBJECT(Variable,Variable_I_symbol(symbol_I_string2(CSTRING("p")),0,Kernel._integer));
      Variable * v41817 = GC_OBJECT(Variable,Variable_I_symbol(symbol_I_string2(CSTRING("q")),0,Kernel._integer));
      Defmethod * v90724;
      { { Defmethod * v88616 = ((Defmethod *) GC_OBJECT(Defmethod,new_object_class(Language._Defmethod)));
          (v88616->arg = v13540->arg);
          (v88616->inline_ask = Kernel.cfalse);
          (v88616->set_arg = v13540->set_arg);
          { Defmethod * v64463 = v88616; 
            OID  v64464;
            { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
              (v88616->selector = v13540->arg->selector);
              { Call * v64465 = v88616; 
                list * v64466;
                { OID v_bag;
                  GC_ANY(v64466= list::empty(Kernel.emptySet));
                  ((list *) v64466)->addFast(1);
                  { { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                      (v88616->selector = Kernel.length);
                      (v88616->args = list::alloc(1,(*(v63778))[1]));
                      add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
                      v_bag = _oid_(v88616);
                      } 
                    GC_OID(v_bag);} 
                  ((list *) v64466)->addFast(v_bag);
                  ((list *) v64466)->addFast(v82388);} 
                (v64465->args = v64466);} 
              add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
              v64464 = _oid_(v88616);
              } 
            (v64463->body = v64464);} 
          add_I_property(Kernel.instances,Language._Defmethod,11,_oid_(v88616));
          v90724 = v88616;
          } 
        GC_OBJECT(Defmethod,v90724);} 
      If * v73359;
      { { If * v88616 = ((If *) GC_OBJECT(If,new_object_class(Language._If)));
          { If * v64467 = v88616; 
            OID  v64468;
            { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
              (v88616->selector = Kernel._sup);
              (v88616->args = list::alloc(2,_oid_(v82389),_oid_(v82390)));
              add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
              v64468 = _oid_(v88616);
              } 
            (v64467->test = v64468);} 
          { If * v64469 = v88616; 
            OID  v64491;
            { Let * v88616 = ((Let *) GC_OBJECT(Let,new_object_class(Language._Let)));
              (v88616->var = v82400);
              { Let * v64492 = v88616; 
                OID  v64493;
                { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                  (v88616->selector = Kernel.nth);
                  (v88616->args = list::alloc(2,v82388,_oid_(v82390)));
                  add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
                  v64493 = _oid_(v88616);
                  } 
                (v64492->value = v64493);} 
              { Let * v64494 = v88616; 
                OID  v64495;
                { If * v88616 = ((If *) GC_OBJECT(If,new_object_class(Language._If)));
                  { If * v64496 = v88616; 
                    OID  v64497;
                    { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                      (v88616->selector = Kernel._equal);
                      { Call * v64498 = v88616; 
                        list * v64499;
                        { OID v_bag;
                          GC_ANY(v64499= list::empty(Kernel.emptySet));
                          ((list *) v64499)->addFast(_oid_(v82389));
                          { { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                              (v88616->selector = Core._plus);
                              (v88616->args = list::alloc(2,_oid_(v82390),1));
                              add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
                              v_bag = _oid_(v88616);
                              } 
                            GC_OID(v_bag);} 
                          ((list *) v64499)->addFast(v_bag);} 
                        (v64498->args = v64499);} 
                      add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
                      v64497 = _oid_(v88616);
                      } 
                    (v64496->test = v64497);} 
                  { If * v64500 = v88616; 
                    OID  v64522;
                    { If * v88616 = ((If *) GC_OBJECT(If,new_object_class(Language._If)));
                      { If * v64523 = v88616; 
                        OID  v64524;
                        { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                          update_property(Kernel.selector,
                            v88616,
                            2,
                            Kernel._object,
                            v82382);
                          { Call * v64525 = v88616; 
                            list * v64526;
                            { OID v_bag;
                              GC_ANY(v64526= list::empty(Kernel.emptySet));
                              { { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                                  (v88616->selector = Kernel.nth);
                                  (v88616->args = list::alloc(2,v82388,_oid_(v82389)));
                                  add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
                                  v_bag = _oid_(v88616);
                                  } 
                                GC_OID(v_bag);} 
                              ((list *) v64526)->addFast(v_bag);
                              ((list *) v64526)->addFast(_oid_(v82400));} 
                            (v64525->args = v64526);} 
                          add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
                          v64524 = _oid_(v88616);
                          } 
                        (v64523->test = v64524);} 
                      { If * v64527 = v88616; 
                        OID  v64528;
                        { Do * v88616 = ((Do *) GC_OBJECT(Do,new_object_class(Language._Do)));
                          { Do * v64529 = v88616; 
                            list * v64530;
                            { OID v_bag;
                              GC_ANY(v64530= list::empty(Kernel.emptySet));
                              { { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                                  (v88616->selector = Kernel.nth_equal);
                                  { Call * v64531 = v88616; 
                                    list * v64553;
                                    { OID v_bag;
                                      GC_ANY(v64553= list::empty(Kernel.emptySet));
                                      ((list *) v64553)->addFast(v82388);
                                      ((list *) v64553)->addFast(_oid_(v82390));
                                      { { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                                          (v88616->selector = Kernel.nth);
                                          (v88616->args = list::alloc(2,v82388,_oid_(v82389)));
                                          add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
                                          v_bag = _oid_(v88616);
                                          } 
                                        GC_OID(v_bag);} 
                                      ((list *) v64553)->addFast(v_bag);} 
                                    (v64531->args = v64553);} 
                                  add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
                                  v_bag = _oid_(v88616);
                                  } 
                                GC_OID(v_bag);} 
                              ((list *) v64530)->addFast(v_bag);
                              { { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                                  (v88616->selector = Kernel.nth_equal);
                                  (v88616->args = list::alloc(3,v82388,
                                    _oid_(v82389),
                                    _oid_(v82400)));
                                  add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
                                  v_bag = _oid_(v88616);
                                  } 
                                GC_OID(v_bag);} 
                              ((list *) v64530)->addFast(v_bag);} 
                            (v64529->args = v64530);} 
                          add_I_property(Kernel.instances,Language._Do,11,_oid_(v88616));
                          v64528 = _oid_(v88616);
                          } 
                        (v64527->arg = v64528);} 
                      add_I_property(Kernel.instances,Language._If,11,_oid_(v88616));
                      (v88616->other = Kernel.cfalse);
                      v64522 = _oid_(v88616);
                      } 
                    (v64500->arg = v64522);} 
                  { If * v64554 = v88616; 
                    OID  v64555;
                    { Let * v88616 = ((Let *) GC_OBJECT(Let,new_object_class(Language._Let)));
                      (v88616->var = v82392);
                      { Let * v64556 = v88616; 
                        OID  v64557;
                        { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                          (v88616->selector = Core._sup_sup);
                          { Call * v64558 = v88616; 
                            list * v64559;
                            { OID v_bag;
                              GC_ANY(v64559= list::empty(Kernel.emptySet));
                              { { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                                  (v88616->selector = Core._plus);
                                  (v88616->args = list::alloc(2,_oid_(v82390),_oid_(v82389)));
                                  add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
                                  v_bag = _oid_(v88616);
                                  } 
                                GC_OID(v_bag);} 
                              ((list *) v64559)->addFast(v_bag);
                              ((list *) v64559)->addFast(1);} 
                            (v64558->args = v64559);} 
                          add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
                          v64557 = _oid_(v88616);
                          } 
                        (v64556->value = v64557);} 
                      { Let * v64560 = v88616; 
                        OID  v64561;
                        { Let * v88616 = ((Let *) GC_OBJECT(Let,new_object_class(Language._Let)));
                          (v88616->var = v41817);
                          (v88616->value = _oid_(v82390));
                          { Let * v64562 = v88616; 
                            OID  v65235;
                            { Do * v88616 = ((Do *) GC_OBJECT(Do,new_object_class(Language._Do)));
                              { Do * v65236 = v88616; 
                                list * v65237;
                                { OID v_bag;
                                  GC_ANY(v65237= list::empty(Kernel.emptySet));
                                  { { Assign * v88616 = ((Assign *) GC_OBJECT(Assign,new_object_class(Language._Assign)));
                                      (v88616->var = _oid_(v82400));
                                      { Assign * v65238 = v88616; 
                                        OID  v65239;
                                        { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                                          (v88616->selector = Kernel.nth);
                                          (v88616->args = list::alloc(2,v82388,_oid_(v82392)));
                                          add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
                                          v65239 = _oid_(v88616);
                                          } 
                                        (v65238->arg = v65239);} 
                                      add_I_property(Kernel.instances,Language._Assign,11,_oid_(v88616));
                                      v_bag = _oid_(v88616);
                                      } 
                                    GC_OID(v_bag);} 
                                  ((list *) v65237)->addFast(v_bag);
                                  { { If * v88616 = ((If *) GC_OBJECT(If,new_object_class(Language._If)));
                                      { If * v65240 = v88616; 
                                        OID  v65241;
                                        { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                                          (v88616->selector = Core._I_equal);
                                          (v88616->args = list::alloc(2,_oid_(v82392),_oid_(v82390)));
                                          add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
                                          v65241 = _oid_(v88616);
                                          } 
                                        (v65240->test = v65241);} 
                                      { If * v65242 = v88616; 
                                        OID  v65243;
                                        { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                                          (v88616->selector = Kernel.nth_equal);
                                          { Call * v65244 = v88616; 
                                            list * v65266;
                                            { OID v_bag;
                                              GC_ANY(v65266= list::empty(Kernel.emptySet));
                                              ((list *) v65266)->addFast(v82388);
                                              ((list *) v65266)->addFast(_oid_(v82392));
                                              { { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                                                  (v88616->selector = Kernel.nth);
                                                  (v88616->args = list::alloc(2,v82388,_oid_(v82390)));
                                                  add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
                                                  v_bag = _oid_(v88616);
                                                  } 
                                                GC_OID(v_bag);} 
                                              ((list *) v65266)->addFast(v_bag);} 
                                            (v65244->args = v65266);} 
                                          add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
                                          v65243 = _oid_(v88616);
                                          } 
                                        (v65242->arg = v65243);} 
                                      add_I_property(Kernel.instances,Language._If,11,_oid_(v88616));
                                      (v88616->other = Kernel.cfalse);
                                      v_bag = _oid_(v88616);
                                      } 
                                    GC_OID(v_bag);} 
                                  ((list *) v65237)->addFast(v_bag);
                                  { { For * v88616 = ((For *) GC_OBJECT(For,new_object_class(Language._For)));
                                      (v88616->var = v82392);
                                      { Iteration * v65267 = v88616; 
                                        OID  v65268;
                                        { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                                          (v88616->selector = Kernel._dot_dot);
                                          { Call * v65269 = v88616; 
                                            list * v65270;
                                            { OID v_bag;
                                              GC_ANY(v65270= list::empty(Kernel.emptySet));
                                              { { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                                                  (v88616->selector = Core._plus);
                                                  (v88616->args = list::alloc(2,_oid_(v82390),1));
                                                  add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
                                                  v_bag = _oid_(v88616);
                                                  } 
                                                GC_OID(v_bag);} 
                                              ((list *) v65270)->addFast(v_bag);
                                              ((list *) v65270)->addFast(_oid_(v82389));} 
                                            (v65269->args = v65270);} 
                                          add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
                                          v65268 = _oid_(v88616);
                                          } 
                                        (v65267->set_arg = v65268);} 
                                      { Iteration * v65271 = v88616; 
                                        OID  v65272;
                                        { If * v88616 = ((If *) GC_OBJECT(If,new_object_class(Language._If)));
                                          { If * v65273 = v88616; 
                                            OID  v65274;
                                            { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                                              update_property(Kernel.selector,
                                                v88616,
                                                2,
                                                Kernel._object,
                                                v82382);
                                              { Call * v65275 = v88616; 
                                                list * v65297;
                                                { OID v_bag;
                                                  GC_ANY(v65297= list::empty(Kernel.emptySet));
                                                  { { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                                                      (v88616->selector = Kernel.nth);
                                                      (v88616->args = list::alloc(2,v82388,_oid_(v82392)));
                                                      add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
                                                      v_bag = _oid_(v88616);
                                                      } 
                                                    GC_OID(v_bag);} 
                                                  ((list *) v65297)->addFast(v_bag);
                                                  ((list *) v65297)->addFast(_oid_(v82400));} 
                                                (v65275->args = v65297);} 
                                              add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
                                              v65274 = _oid_(v88616);
                                              } 
                                            (v65273->test = v65274);} 
                                          { If * v65298 = v88616; 
                                            OID  v65299;
                                            { Do * v88616 = ((Do *) GC_OBJECT(Do,new_object_class(Language._Do)));
                                              { Do * v65300 = v88616; 
                                                list * v65301;
                                                { OID v_bag;
                                                  GC_ANY(v65301= list::empty(Kernel.emptySet));
                                                  { { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                                                      (v88616->selector = Kernel.nth_equal);
                                                      { Call * v65302 = v88616; 
                                                        list * v65303;
                                                        { OID v_bag;
                                                          GC_ANY(v65303= list::empty(Kernel.emptySet));
                                                          ((list *) v65303)->addFast(v82388);
                                                          ((list *) v65303)->addFast(_oid_(v82390));
                                                          { { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                                                              (v88616->selector = Kernel.nth);
                                                              (v88616->args = list::alloc(2,v82388,_oid_(v82392)));
                                                              add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
                                                              v_bag = _oid_(v88616);
                                                              } 
                                                            GC_OID(v_bag);} 
                                                          ((list *) v65303)->addFast(v_bag);} 
                                                        (v65302->args = v65303);} 
                                                      add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
                                                      v_bag = _oid_(v88616);
                                                      } 
                                                    GC_OID(v_bag);} 
                                                  ((list *) v65301)->addFast(v_bag);
                                                  { { Assign * v88616 = ((Assign *) GC_OBJECT(Assign,new_object_class(Language._Assign)));
                                                      (v88616->var = _oid_(v82390));
                                                      { Assign * v65304 = v88616; 
                                                        OID  v65305;
                                                        { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                                                          (v88616->selector = Core._plus);
                                                          (v88616->args = list::alloc(2,_oid_(v82390),1));
                                                          add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
                                                          v65305 = _oid_(v88616);
                                                          } 
                                                        (v65304->arg = v65305);} 
                                                      add_I_property(Kernel.instances,Language._Assign,11,_oid_(v88616));
                                                      v_bag = _oid_(v88616);
                                                      } 
                                                    GC_OID(v_bag);} 
                                                  ((list *) v65301)->addFast(v_bag);
                                                  { { If * v88616 = ((If *) GC_OBJECT(If,new_object_class(Language._If)));
                                                      { If * v65306 = v88616; 
                                                        OID  v65328;
                                                        { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                                                          (v88616->selector = Kernel._sup);
                                                          (v88616->args = list::alloc(2,_oid_(v82392),_oid_(v82390)));
                                                          add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
                                                          v65328 = _oid_(v88616);
                                                          } 
                                                        (v65306->test = v65328);} 
                                                      { If * v65329 = v88616; 
                                                        OID  v65330;
                                                        { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                                                          (v88616->selector = Kernel.nth_equal);
                                                          { Call * v65331 = v88616; 
                                                            list * v65332;
                                                            { OID v_bag;
                                                              GC_ANY(v65332= list::empty(Kernel.emptySet));
                                                              ((list *) v65332)->addFast(v82388);
                                                              ((list *) v65332)->addFast(_oid_(v82392));
                                                              { { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                                                                  (v88616->selector = Kernel.nth);
                                                                  (v88616->args = list::alloc(2,v82388,_oid_(v82390)));
                                                                  add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
                                                                  v_bag = _oid_(v88616);
                                                                  } 
                                                                GC_OID(v_bag);} 
                                                              ((list *) v65332)->addFast(v_bag);} 
                                                            (v65331->args = v65332);} 
                                                          add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
                                                          v65330 = _oid_(v88616);
                                                          } 
                                                        (v65329->arg = v65330);} 
                                                      add_I_property(Kernel.instances,Language._If,11,_oid_(v88616));
                                                      (v88616->other = Kernel.cfalse);
                                                      v_bag = _oid_(v88616);
                                                      } 
                                                    GC_OID(v_bag);} 
                                                  ((list *) v65301)->addFast(v_bag);} 
                                                (v65300->args = v65301);} 
                                              add_I_property(Kernel.instances,Language._Do,11,_oid_(v88616));
                                              v65299 = _oid_(v88616);
                                              } 
                                            (v65298->arg = v65299);} 
                                          add_I_property(Kernel.instances,Language._If,11,_oid_(v88616));
                                          (v88616->other = Kernel.cfalse);
                                          v65272 = _oid_(v88616);
                                          } 
                                        (v65271->arg = v65272);} 
                                      add_I_property(Kernel.instances,Language._For,11,_oid_(v88616));
                                      v_bag = _oid_(v88616);
                                      } 
                                    GC_OID(v_bag);} 
                                  ((list *) v65237)->addFast(v_bag);
                                  { { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                                      (v88616->selector = Kernel.nth_equal);
                                      (v88616->args = list::alloc(3,v82388,
                                        _oid_(v82390),
                                        _oid_(v82400)));
                                      add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
                                      v_bag = _oid_(v88616);
                                      } 
                                    GC_OID(v_bag);} 
                                  ((list *) v65237)->addFast(v_bag);
                                  { { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                                      (v88616->selector = v13540->arg->selector);
                                      { Call * v65333 = v88616; 
                                        list * v65334;
                                        { OID v_bag;
                                          GC_ANY(v65334= list::empty(Kernel.emptySet));
                                          ((list *) v65334)->addFast(_oid_(v41817));
                                          { { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                                              (v88616->selector = Kernel._dash);
                                              (v88616->args = list::alloc(2,_oid_(v82390),1));
                                              add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
                                              v_bag = _oid_(v88616);
                                              } 
                                            GC_OID(v_bag);} 
                                          ((list *) v65334)->addFast(v_bag);
                                          ((list *) v65334)->addFast(v82388);} 
                                        (v65333->args = v65334);} 
                                      add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
                                      v_bag = _oid_(v88616);
                                      } 
                                    GC_OID(v_bag);} 
                                  ((list *) v65237)->addFast(v_bag);
                                  { { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                                      (v88616->selector = v13540->arg->selector);
                                      { Call * v65335 = v88616; 
                                        list * v65336;
                                        { OID v_bag;
                                          GC_ANY(v65336= list::empty(Kernel.emptySet));
                                          { { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                                              (v88616->selector = Core._plus);
                                              (v88616->args = list::alloc(2,_oid_(v82390),1));
                                              add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
                                              v_bag = _oid_(v88616);
                                              } 
                                            GC_OID(v_bag);} 
                                          ((list *) v65336)->addFast(v_bag);
                                          ((list *) v65336)->addFast(_oid_(v82389));
                                          ((list *) v65336)->addFast(v82388);} 
                                        (v65335->args = v65336);} 
                                      add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
                                      v_bag = _oid_(v88616);
                                      } 
                                    GC_OID(v_bag);} 
                                  ((list *) v65237)->addFast(v_bag);} 
                                (v65236->args = v65237);} 
                              add_I_property(Kernel.instances,Language._Do,11,_oid_(v88616));
                              v65235 = _oid_(v88616);
                              } 
                            (v64562->arg = v65235);} 
                          add_I_property(Kernel.instances,Language._Let,11,_oid_(v88616));
                          v64561 = _oid_(v88616);
                          } 
                        (v64560->arg = v64561);} 
                      add_I_property(Kernel.instances,Language._Let,11,_oid_(v88616));
                      v64555 = _oid_(v88616);
                      } 
                    (v64554->other = v64555);} 
                  add_I_property(Kernel.instances,Language._If,11,_oid_(v88616));
                  v64495 = _oid_(v88616);
                  } 
                (v64494->arg = v64495);} 
              add_I_property(Kernel.instances,Language._Let,11,_oid_(v88616));
              v64491 = _oid_(v88616);
              } 
            (v64469->arg = v64491);} 
          add_I_property(Kernel.instances,Language._If,11,_oid_(v88616));
          (v88616->other = Kernel.cfalse);
          v73359 = v88616;
          } 
        GC_OBJECT(If,v73359);} 
      Defmethod * v90725;
      { { Defmethod * v88616 = ((Defmethod *) GC_OBJECT(Defmethod,new_object_class(Language._Defmethod)));
          { Defmethod * v65337 = v88616; 
            Call * v65359;
            { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
              (v88616->selector = v13540->arg->selector);
              (v88616->args = list::alloc(3,_oid_(v82390),
                _oid_(v82389),
                v82388));
              add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
              v65359 = v88616;
              } 
            (v65337->arg = v65359);} 
          (v88616->inline_ask = Kernel.cfalse);
          (v88616->set_arg = v13540->set_arg);
          (v88616->body = _oid_(v73359));
          add_I_property(Kernel.instances,Language._Defmethod,11,_oid_(v88616));
          v90725 = v88616;
          } 
        GC_OBJECT(Defmethod,v90725);} 
      tformat_string(CSTRING("---- note: quick sort optimisation for ~S ---- \n"),2,list::alloc(1,_oid_(v13540->arg->selector)));
      OPT_EVAL(_oid_(v90725));
      { Do * v88616 = ((Do *) GC_OBJECT(Do,new_object_class(Language._Do)));
        (v88616->args = list::alloc(2,GC_OID((*Optimize.c_code)(_oid_(v90724))),GC_OID((*Optimize.c_code)(_oid_(v90725)))));
        add_I_property(Kernel.instances,Language._Do,11,_oid_(v88616));
        Result = _oid_(v88616);
        } 
      } 
    GC_UNBIND; return (Result);} 
  } 

method * add_method_property2(property *v82392,list *v63775,ClaireType *v63949,Cint v63993,ClaireFunction *v63523,ClaireFunction *v63524)
{ return (add_method_property(v82392,
    v63775,
    v63949,
    v63993,
    _oid_(v63523)));} 

OID  add_method_I_method(method *v82389,list *v63775,OID v63949,OID v105068,ClaireFunction *v63591)
{ GC_BIND;
  { OID Result = 0;
    { Call_method * v61558;
      { { Call_method * v88616 = ((Call_method *) GC_OBJECT(Call_method,new_object_class(Language._Call_method)));
          (v88616->arg = ((method *) _at_property1(Kernel.add_method,Kernel._property)));
          (v88616->args = list::alloc(5,GC_OID((*Optimize.c_code)(_oid_(v82389->selector),
              _oid_(Kernel._property))),
            GC_OID((*Optimize.c_code)(_oid_(v63775),
              _oid_(Kernel._list))),
            GC_OID((*Optimize.c_code)(v63949,
              _oid_(Kernel._type))),
            v105068,
            _oid_(v63591)));
          add_I_property(Kernel.instances,Language._Call_method,11,_oid_(v88616));
          v61558 = v88616;
          } 
        GC_OBJECT(Call_method,v61558);} 
      if ((v82389->range == Kernel._float) || 
          ((v82389->domain->memq(_oid_(Kernel._float)) == CTRUE) || 
            (INHERIT(v82389->range->isa,Kernel._tuple))))
       GC_OBJECT(list,v61558->args)->addFast(_oid_(make_function_string(append_string(GC_STRING(string_I_function(v63591)),CSTRING("_")))));
      Result = _oid_(v61558);
      } 
    GC_UNBIND; return (Result);} 
  } 

list * extract_status_new_any(OID v82400)
{ GC_BIND;
  { list *Result ;
    { OID  v82395 = CNULL;
      OID  v82382;
      if ((INHERIT(OWNER(v82400),Language._Call)) && (OBJECT(Call,v82400)->selector == Language.function_I))
       v82382 = v82400;
      else v82382 = CNULL;
        if (INHERIT(OWNER(v82400),Language._And))
       { OID  v82401 = (*(OBJECT(And,v82400)->args))[1];
        if ((INHERIT(OWNER(v82401),Language._Call)) && (OBJECT(Call,v82401)->selector == Language.function_I))
         { v82382= v82401;
          v82400= (*(OBJECT(And,v82400)->args))[2];
          } 
        } 
      else if (INHERIT(OWNER(v82400),Language._Call))
       { if (OBJECT(Call,v82400)->selector == Language.function_I)
         v82400= _oid_(Kernel.body);
        } 
      if (v82382 != CNULL)
       { v82400= _oid_(Kernel.body);
        if (length_bag(OBJECT(bag,(*Core.args)(v82382))) > 1)
         { ClaireHandler c_handle = ClaireHandler();
          if ERROR_IN 
          { { Cint  v73612;{ set * v32114;
                { set * v112294 = set::empty(Kernel.emptySet);
                  { OID gc_local;
                    ITERATE(v82397);
                    bag *v82397_support;
                    v82397_support = GC_OBJECT(list,cdr_list(GC_OBJECT(list,OBJECT(list,(*Core.args)(v82382)))));
                    for (START(v82397_support); NEXT(v82397);)
                    { GC_LOOP;
                      v112294->addFast(GC_OID(OPT_EVAL(v82397)));
                      GC_UNLOOP;} 
                    } 
                  v32114 = GC_OBJECT(set,v112294);
                  } 
                v73612 = integer_I_set(v32114);
                } 
              
              v82395=v73612;} 
            ClEnv->cHandle--;} 
          else if (belong_to(_oid_(ClEnv->exception_I),_oid_(Kernel._any)) == CTRUE)
          { c_handle.catchIt();{ warn_void();
              (Optimize.SHIT->value= _oid_(cdr_list(GC_OBJECT(list,OBJECT(list,(*Core.args)(v82382))))));
              tformat_string(CSTRING("wrong status ~S -> ~S [266]\n"),2,GC_OBJECT(list,list::alloc(2,v82382,_oid_(set_I_bag(cdr_list(GC_OBJECT(list,OBJECT(list,(*Core.args)(v82382)))))))));
              v82395= 0;
              } 
            } 
          else PREVIOUS_HANDLER;} 
        else v82395= 0;
          v82382= _oid_(make_function_string(string_I_symbol(extract_symbol_any((*(OBJECT(bag,(*Core.args)(v82382))))[1]))));
        } 
      Result = list::alloc(3,v82395,
        v82382,
        v82400);
      } 
    GC_UNBIND; return (Result);} 
  } 

list * extract_signature_I_list(list *v82388)
{ GC_BIND;
  (Language.LDEF->value= _oid_(list::empty(Kernel._any)));
  { list *Result ;
    { Cint  v82390 = 0;
      list * v63709 = list::empty(Kernel._type);
      list * v63710;
      { { bag *v_list; OID v_val;
          OID v82398,CLcount;
          v_list = v82388;
           v63710 = v_list->clone(Kernel._any);
          for (CLcount= 1; CLcount <= v_list->length; CLcount++)
          { v82398 = (*(v_list))[CLcount];
            { OID  v82392 = GC_OID(extract_pattern_any(GC_OID(_oid_(OBJECT(Variable,v82398)->range)),list::alloc(1,v82390)));
              ++v82390;
              { { OID  v33075;
                  { if (INHERIT(OBJECT(Variable,v82398)->range->isa,Core._global_variable))
                     v33075 = _oid_(OBJECT(Variable,v82398)->range);
                    else v33075 = v82392;
                      GC_OID(v33075);} 
                  v63709 = v63709->addFast(v33075);
                  } 
                GC_OBJECT(list,v63709);} 
              (OBJECT(Variable,v82398)->range = type_I_any(v82392));
              v_val = v82392;
              } 
            
            (*((list *) v63710))[CLcount] = v_val;} 
          } 
        GC_OBJECT(list,v63710);} 
      Result = list::alloc(2,_oid_(v63709),_oid_(v63710));
      } 
    GC_UNBIND; return (Result);} 
  } 

ClaireBoolean * _equalsig_ask_list(list *v82400,list *v82401)
{ return (((tmatch_ask_list(v82400,v82401) == CTRUE) ? ((tmatch_ask_list(v82401,v82400) == CTRUE) ? CTRUE: CFALSE): CFALSE));} 

char * function_name_property_Optimize(property *v82392,list *v82388,OID v82400)
{ GC_BIND;
  { char *Result ;
    if (INHERIT(OWNER(v82400),Kernel._function))
     Result = string_I_function(OBJECT(ClaireFunction,v82400));
    else { Cint  v82390 = 0;
        Cint  v82389 = 0;
        module * v63791 = v82392->name->module_I;
        ClaireClass * v82379 = class_I_type(OBJECT(ClaireType,(*(v82388))[1]));
        char * v82394 = GC_STRING(append_string(GC_STRING(append_string(GC_STRING(string_I_symbol(v82392->name)),CSTRING("_"))),GC_STRING(string_I_symbol(v82379->name))));
        if ((Optimize.compiler->naming == 0) && 
            (v82392 != Core.main))
         v82394= GC_STRING(append_string(GC_STRING(append_string(GC_STRING(string_I_symbol(v63791->name)),CSTRING("_"))),v82394));
        { ITERATE(v82394);
          for (START(v82392->restrictions); NEXT(v82394);)
          { if (v82379 == domain_I_restriction(OBJECT(restriction,v82394)))
             ++v82390;
            if (_equalsig_ask_list(v82388,OBJECT(restriction,v82394)->domain) == CTRUE)
             v82389= v82390;
            } 
          } 
        v82394= GC_STRING(((v82390 <= 1) ?
          v82394 :
          append_string(v82394,GC_STRING(string_I_integer (v82389))) ));
        Result = (((stable_ask_relation(v82392) == CTRUE) || 
            (v82392 == Core.main)) ?
          v82394 :
          append_string(GC_STRING(append_string(v82394,CSTRING("_"))),GC_STRING(string_I_symbol(ClEnv->module_I->name))) );
        } 
      GC_UNBIND; return (Result);} 
  } 

OID  compile_lambda_string(char *v13540,lambda *v82388,OID v82389)
{ { OID Result = 0;
    { Cint  v82400 = Optimize.compiler->safety;
      lambda * v82401 = v82388;
      if (Kernel._method == OWNER(v82389))
       (Optimize.OPT->in_method = v82389);
      (Optimize.OPT->protection = CFALSE);
      (Optimize.OPT->allocation = CFALSE);
      if (Optimize.OPT->loop_index > 0)
       (Optimize.OPT->loop_index = 0);
      (Optimize.OPT->loop_gc = CFALSE);
      (Optimize.OPT->use_update = CFALSE);
      (Optimize.OPT->use_nth_equal = CFALSE);
      (Optimize.OPT->use_string_update = CFALSE);
      (Optimize.OPT->max_vars = 0);
      if (contain_ask_list(Optimize.OPT->unsure,v82389) == CTRUE)
       (Optimize.compiler->safety = 1);
      (*Optimize.make_c_function)(_oid_(v82388),
        _string_(v13540),
        v82389);
      (Optimize.OPT->in_method = CNULL);
      (Optimize.compiler->safety = v82400);
      Result = Kernel.ctrue;
      } 
    return (Result);} 
  } 

OID  c_code_Defarray_Optimize(Defarray *v13540)
{ GC_BIND;
  { OID Result = 0;
    { list * v82377 = GC_OBJECT(list,v13540->arg->args);
      OID  v61556 = GC_OID(get_symbol(extract_symbol_any((*(v82377))[1])));
      table * v61589;
      { ClaireObject *V_CC ;
        if (INHERIT(OWNER(v61556),Kernel._table))
         V_CC = OBJECT(table,v61556);
        else close_exception(((general_error *) (*Core._general_error)(_string_(CSTRING("[internal] the table ~S is unknown")),
            _oid_(list::alloc(1,(*(v82377))[1])))));
          v61589= (table *) V_CC;} 
      OID  v82395 = GC_OID((*Kernel.domain)(v61556));
      OID  v82381;
      { { list * v82388 = GC_OBJECT(list,cdr_list(v82377));
          OID  v82378 = GC_OID(lexical_build_any(GC_OID(v13540->body),v82388,0));
          { ClaireBoolean * g0446I;
            { OID  v35958;
              { ITERATE(v64067);
                v35958= Kernel.cfalse;
                for (START(v82388); NEXT(v64067);)
                if (occurrence_any(v82378,OBJECT(Variable,v64067)) > 0)
                 { v35958 = Kernel.ctrue;
                  break;} 
                } 
              g0446I = boolean_I_any(v35958);
              } 
            
            if (g0446I == CTRUE) v82381 = _oid_(lambda_I_list(v82388,v82378));
              else v82381 = v13540->body;
            } 
          } 
        GC_OID(v82381);} 
      OID  v82380;
      { if (INHERIT(OWNER(v82381),Core._lambda))
         v82380 = CNULL;
        else v82380 = v13540->body;
          GC_OID(v82380);} 
      list * v73618;
      if (boolean_I_any(_oid_(OBJECT(ClaireRelation,v61556)->multivalued_ask)) == CTRUE)
       { OID v_bag;
        GC_ANY(v73618= list::empty(Kernel._any));
        { { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
            (v88616->selector = Kernel.put);
            (v88616->args = list::alloc(3,_oid_(Kernel.multivalued_ask),
              _oid_(v61589),
              GC_OID(_oid_(OBJECT(ClaireRelation,v61556)->multivalued_ask))));
            add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
            v_bag = _oid_(v88616);
            } 
          GC_OID(v_bag);} 
        ((list *) v73618)->addFast(v_bag);} 
      else v73618 = list::empty(Kernel._any);
        list * v73619;
      { OID v_bag;
        GC_ANY(v73619= list::empty(Kernel._any));
        { { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
            (v88616->selector = Kernel.put);
            (v88616->args = list::alloc(3,_oid_(Kernel.range),
              _oid_(v61589),
              GC_OID((*Kernel.range)(v61556))));
            add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
            v_bag = _oid_(v88616);
            } 
          GC_OID(v_bag);} 
        ((list *) v73619)->addFast(v_bag);
        { { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
            (v88616->selector = Kernel.put);
            (v88616->args = list::alloc(3,_oid_(Kernel.params),
              _oid_(v61589),
              GC_OID((*Kernel.params)(v61556))));
            add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
            v_bag = _oid_(v88616);
            } 
          GC_OID(v_bag);} 
        ((list *) v73619)->addFast(v_bag);
        { { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
            (v88616->selector = Kernel.put);
            (v88616->args = list::alloc(3,_oid_(Kernel.domain),
              _oid_(v61589),
              v82395));
            add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
            v_bag = _oid_(v88616);
            } 
          GC_OID(v_bag);} 
        ((list *) v73619)->addFast(v_bag);} 
      (OBJECT(Variable,(*(v82377))[2])->range = extract_type_any(GC_OID(_oid_(OBJECT(Variable,(*(v82377))[2])->range))));
      if (v82377->length == 2)
       { { { OID  v36919;
            { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
              (v88616->selector = Kernel.put);
              { Call * v65368 = v88616; 
                list * v65390;
                { OID v_bag;
                  GC_ANY(v65390= list::empty(Kernel.emptySet));
                  ((list *) v65390)->addFast(_oid_(Kernel.graph));
                  ((list *) v65390)->addFast(_oid_(v61589));
                  if (INHERIT(OBJECT(ClaireObject,v82395)->isa,Core._Interval))
                   { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                    (v88616->selector = Core.make_copy_list);
                    (v88616->args = list::alloc(2,size_Interval(OBJECT(Interval,v82395)),v82380));
                    add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
                    v_bag = _oid_(v88616);
                    } 
                  else { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                      (v88616->selector = Kernel.make_list);
                      (v88616->args = list::alloc(2,29,CNULL));
                      add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
                      v_bag = _oid_(v88616);
                      } 
                    ((list *) v65390)->addFast(v_bag);} 
                (v65368->args = v65390);} 
              add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
              v36919 = _oid_(v88616);
              } 
            v73619 = v73619->addFast(v36919);
            } 
          GC_OBJECT(list,v73619);} 
        { { OID  v59983;
            if (INHERIT(OWNER(v82381),Core._lambda))
             { For * v88616 = ((For *) GC_OBJECT(For,new_object_class(Language._For)));
              store_object(v88616,
                2,
                Kernel._object,
                (*(v82377))[2],
                CFALSE);
              (v88616->set_arg = v82395);
              { Iteration * v65392 = v88616; 
                OID  v65393;
                { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                  (v88616->selector = Kernel.nth_equal);
                  (v88616->args = list::alloc(3,_oid_(v61589),
                    (*(v82377))[2],
                    GC_OID(OBJECT(lambda,v82381)->body)));
                  add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
                  v65393 = _oid_(v88616);
                  } 
                (v65392->arg = v65393);} 
              add_I_property(Kernel.instances,Language._For,11,_oid_(v88616));
              v59983 = _oid_(v88616);
              } 
            else { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                (v88616->selector = Kernel.put);
                (v88616->args = list::alloc(3,_oid_(Kernel.DEFAULT),
                  _oid_(v61589),
                  v82380));
                add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
                v59983 = _oid_(v88616);
                } 
              v73619 = v73619->addFast(v59983);
            } 
          GC_OBJECT(list,v73619);} 
        } 
      else { ClaireType * v63927 = GC_OBJECT(ClaireType,extract_type_any(GC_OID(_oid_(OBJECT(Variable,(*(v82377))[3])->range))));
          (OBJECT(Variable,(*(v82377))[3])->range = v63927);
          { { OID  v62866;
              { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                (v88616->selector = Kernel.put);
                { Call * v65395 = v88616; 
                  list * v65396;
                  { OID v_bag;
                    GC_ANY(v65396= list::empty(Kernel.emptySet));
                    ((list *) v65396)->addFast(_oid_(Kernel.graph));
                    ((list *) v65396)->addFast(_oid_(v61589));
                    { { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                        (v88616->selector = Core.make_copy_list);
                        { Call * v65397 = v88616; 
                          list * v65398;
                          { OID v_bag;
                            GC_ANY(v65398= list::empty(Kernel.emptySet));
                            ((list *) v65398)->addFast(OBJECT(table,v61556)->graph->length);
                            { if ((*Kernel.params)(v61556) == _oid_(Kernel._any))
                               v_bag = CNULL;
                              else v_bag = (*Kernel.DEFAULT)(v61556);
                                GC_OID(v_bag);} 
                            ((list *) v65398)->addFast(v_bag);} 
                          (v65397->args = v65398);} 
                        add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
                        v_bag = _oid_(v88616);
                        } 
                      GC_OID(v_bag);} 
                    ((list *) v65396)->addFast(v_bag);} 
                  (v65395->args = v65396);} 
                add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
                v62866 = _oid_(v88616);
                } 
              v73619 = v73619->addFast(v62866);
              } 
            GC_OBJECT(list,v73619);} 
          { { OID  v67671;
              if (INHERIT(OWNER(v82381),Core._lambda))
               { For * v88616 = ((For *) GC_OBJECT(For,new_object_class(Language._For)));
                store_object(v88616,
                  2,
                  Kernel._object,
                  (*(v82377))[2],
                  CFALSE);
                (v88616->set_arg = (*(OBJECT(bag,v82395)))[1]);
                { Iteration * v65421 = v88616; 
                  OID  v65422;
                  { For * v88616 = ((For *) GC_OBJECT(For,new_object_class(Language._For)));
                    store_object(v88616,
                      2,
                      Kernel._object,
                      (*(v82377))[3],
                      CFALSE);
                    (v88616->set_arg = _oid_(v63927));
                    { Iteration * v65423 = v88616; 
                      OID  v65424;
                      { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                        (v88616->selector = Kernel.nth_equal);
                        (v88616->args = list::alloc(4,_oid_(v61589),
                          (*(v82377))[2],
                          (*(v82377))[3],
                          GC_OID(OBJECT(lambda,v82381)->body)));
                        add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
                        v65424 = _oid_(v88616);
                        } 
                      (v65423->arg = v65424);} 
                    add_I_property(Kernel.instances,Language._For,11,_oid_(v88616));
                    v65422 = _oid_(v88616);
                    } 
                  (v65421->arg = v65422);} 
                add_I_property(Kernel.instances,Language._For,11,_oid_(v88616));
                v67671 = _oid_(v88616);
                } 
              else { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                  (v88616->selector = Kernel.put);
                  (v88616->args = list::alloc(3,_oid_(Kernel.DEFAULT),
                    _oid_(v61589),
                    v82380));
                  add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
                  v67671 = _oid_(v88616);
                  } 
                v73619 = v73619->addFast(v67671);
              } 
            GC_OBJECT(list,v73619);} 
          } 
        GC_OBJECT(list,Optimize.OPT->objects)->addFast(v61556);
      (*Optimize.c_register)(v61556);
      { OID  v92657;
        { Do * v88616 = ((Do *) GC_OBJECT(Do,new_object_class(Language._Do)));
          { Do * v65426 = v88616; 
            list * v65427;
            { OID  v95540;
              { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                (v88616->selector = Optimize.object_I);
                (v88616->args = list::alloc(2,GC_OID((*Kernel.name)(v61556)),_oid_(Kernel._table)));
                add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
                v95540 = _oid_(v88616);
                } 
              v65427 = cons_any(v95540,GC_OBJECT(list,add_star_list(v73618,v73619)));
              } 
            (v65426->args = v65427);} 
          add_I_property(Kernel.instances,Language._Do,11,_oid_(v88616));
          v92657 = _oid_(v88616);
          } 
        Result = (*Optimize.c_code)(v92657,
          _oid_(Kernel._any));
        } 
      } 
    GC_UNBIND; return (Result);} 
  } 

void  compute_if_write_inverse_relation2(ClaireRelation *v82362)
{ GC_BIND;
  { Variable * v82400;
    { { Variable * v88616 = ((Variable *) GC_OBJECT(Variable,new_object_class(Language._Variable)));
        (v88616->pname = symbol_I_string2(CSTRING("XX")));
        (v88616->range = v82362->domain);
        add_I_property(Kernel.instances,Language._Variable,11,_oid_(v88616));
        v82400 = v88616;
        } 
      GC_OBJECT(Variable,v82400);} 
    Variable * v82401;
    { { Variable * v88616 = ((Variable *) GC_OBJECT(Variable,new_object_class(Language._Variable)));
        (v88616->pname = symbol_I_string2(CSTRING("YY")));
        (v88616->range = ((multi_ask_any(_oid_(v82362)) == CTRUE) ?
          member_type(v82362->range) :
          v82362->range ));
        add_I_property(Kernel.instances,Language._Variable,11,_oid_(v88616));
        v82401 = v88616;
        } 
      GC_OBJECT(Variable,v82401);} 
    Variable * v82402;
    { { Variable * v88616 = ((Variable *) GC_OBJECT(Variable,new_object_class(Language._Variable)));
        (v88616->pname = symbol_I_string2(CSTRING("ZZ")));
        (v88616->range = v82362->range);
        add_I_property(Kernel.instances,Language._Variable,11,_oid_(v88616));
        v82402 = v88616;
        } 
      GC_OBJECT(Variable,v82402);} 
    list * v63709 = list::empty(Kernel._any);
    if (multi_ask_any(_oid_(v82362)) == CTRUE)
     { v63709= list::alloc(Kernel._any,1,GC_OID((INHERIT(v82362->isa,Kernel._property) ?  Produce_put_property2((property *) OBJECT(property,_oid_(v82362)),OBJECT(Variable,_oid_(v82400)),_oid_(v82401)) :   Produce_put_table2((table *) OBJECT(table,_oid_(v82362)),OBJECT(Variable,_oid_(v82400)),_oid_(v82401)))));
      if (((v82362->inverse == (NULL)) ? CTRUE : CFALSE) != CTRUE)
       v63709= GC_OBJECT(list,v63709->addFast(GC_OID((INHERIT(v82362->inverse->isa,Kernel._property) ?  Produce_put_property2((property *) OBJECT(property,_oid_(v82362->inverse)),OBJECT(Variable,_oid_(v82401)),_oid_(v82400)) :   Produce_put_table2((table *) OBJECT(table,_oid_(v82362->inverse)),OBJECT(Variable,_oid_(v82401)),_oid_(v82400))))));
      { ClaireRelation * v65429 = v82362; 
        OID  v65430;
        { lambda * v73703;{ OID  v119565;
            { If * v88616 = ((If *) GC_OBJECT(If,new_object_class(Language._If)));
              { If * v65454 = v88616; 
                OID  v65455;
                { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                  (v88616->selector = Core.NOT);
                  { Call * v65456 = v88616; 
                    list * v65457;
                    { OID v_bag;
                      GC_ANY(v65457= list::empty(Kernel.emptySet));
                      { { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                          (v88616->selector = Kernel._Z);
                          (v88616->args = list::alloc(2,_oid_(v82401),GC_OID(Produce_get_relation2(v82362,v82400))));
                          add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
                          v_bag = _oid_(v88616);
                          } 
                        GC_OID(v_bag);} 
                      ((list *) v65457)->addFast(v_bag);} 
                    (v65456->args = v65457);} 
                  add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
                  v65455 = _oid_(v88616);
                  } 
                (v65454->test = v65455);} 
              { If * v65458 = v88616; 
                OID  v65459;
                { Do * v88616 = ((Do *) GC_OBJECT(Do,new_object_class(Language._Do)));
                  (v88616->args = v63709);
                  add_I_property(Kernel.instances,Language._Do,11,_oid_(v88616));
                  v65459 = _oid_(v88616);
                  } 
                (v65458->arg = v65459);} 
              add_I_property(Kernel.instances,Language._If,11,_oid_(v88616));
              (v88616->other = Kernel.cfalse);
              v119565 = _oid_(v88616);
              } 
            v73703 = lambda_I_list(list::alloc(2,_oid_(v82400),_oid_(v82401)),v119565);
            } 
          
          v65430=_oid_(v73703);} 
        (v65429->if_write = v65430);} 
      } 
    else { v63709= list::alloc(Kernel._any,1,GC_OID((INHERIT(v82362->isa,Kernel._property) ?  Produce_put_property2((property *) OBJECT(property,_oid_(v82362)),OBJECT(Variable,_oid_(v82400)),_oid_(v82401)) :   Produce_put_table2((table *) OBJECT(table,_oid_(v82362)),OBJECT(Variable,_oid_(v82400)),_oid_(v82401)))));
        if (((v82362->inverse == (NULL)) ? CTRUE : CFALSE) != CTRUE)
         { { { OID  v126292;
              { If * v88616 = ((If *) GC_OBJECT(If,new_object_class(Language._If)));
                { If * v65461 = v88616; 
                  OID  v65483;
                  { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                    (v88616->selector = Core.known_ask);
                    (v88616->args = list::alloc(1,_oid_(v82402)));
                    add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
                    v65483 = _oid_(v88616);
                    } 
                  (v65461->test = v65483);} 
                (v88616->arg = (INHERIT(v82362->inverse->isa,Kernel._property) ?  Produce_remove_property2((property *) OBJECT(property,_oid_(v82362->inverse)),OBJECT(Variable,_oid_(v82402)),_oid_(v82400)) :   Produce_remove_table2((table *) OBJECT(table,_oid_(v82362->inverse)),OBJECT(Variable,_oid_(v82402)),_oid_(v82400))));
                add_I_property(Kernel.instances,Language._If,11,_oid_(v88616));
                (v88616->other = Kernel.cfalse);
                v126292 = _oid_(v88616);
                } 
              v63709 = v63709->addFast(v126292);
              } 
            GC_OBJECT(list,v63709);} 
          v63709= GC_OBJECT(list,v63709->addFast(GC_OID((INHERIT(v82362->inverse->isa,Kernel._property) ?  Produce_put_property2((property *) OBJECT(property,_oid_(v82362->inverse)),OBJECT(Variable,_oid_(v82401)),_oid_(v82400)) :   Produce_put_table2((table *) OBJECT(table,_oid_(v82362->inverse)),OBJECT(Variable,_oid_(v82401)),_oid_(v82400))))));
          } 
        { ClaireRelation * v65484 = v82362; 
          OID  v65485;
          { lambda * v73737;{ OID  v21167;
              { Let * v88616 = ((Let *) GC_OBJECT(Let,new_object_class(Language._Let)));
                (v88616->var = v82402);
                (v88616->value = Produce_get_relation2(v82362,v82400));
                { Let * v65488 = v88616; 
                  OID  v65489;
                  { If * v88616 = ((If *) GC_OBJECT(If,new_object_class(Language._If)));
                    { If * v65490 = v88616; 
                      OID  v65491;
                      { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                        (v88616->selector = Core._I_equal);
                        (v88616->args = list::alloc(2,_oid_(v82401),_oid_(v82402)));
                        add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
                        v65491 = _oid_(v88616);
                        } 
                      (v65490->test = v65491);} 
                    { If * v65492 = v88616; 
                      OID  v65514;
                      { Do * v88616 = ((Do *) GC_OBJECT(Do,new_object_class(Language._Do)));
                        (v88616->args = v63709);
                        add_I_property(Kernel.instances,Language._Do,11,_oid_(v88616));
                        v65514 = _oid_(v88616);
                        } 
                      (v65492->arg = v65514);} 
                    add_I_property(Kernel.instances,Language._If,11,_oid_(v88616));
                    (v88616->other = Kernel.cfalse);
                    v65489 = _oid_(v88616);
                    } 
                  (v65488->arg = v65489);} 
                add_I_property(Kernel.instances,Language._Let,11,_oid_(v88616));
                v21167 = _oid_(v88616);
                } 
              v73737 = lambda_I_list(list::alloc(2,_oid_(v82400),_oid_(v82401)),v21167);
              } 
            
            v65485=_oid_(v73737);} 
          (v65484->if_write = v65485);} 
        } 
      { char * v116386 = GC_STRING(append_string(GC_STRING(string_I_symbol(v82362->name)),CSTRING("_write")));
      compile_lambda_string(v116386,GC_OBJECT(lambda,OBJECT(lambda,v82362->if_write)),_oid_(Kernel._void));
      } 
    } 
  GC_UNBIND;} 

OID  compute_set_write_relation2(ClaireRelation *v82362)
{ GC_BIND;
  { OID Result = 0;
    { Variable * v82400;
      { { Variable * v88616 = ((Variable *) GC_OBJECT(Variable,new_object_class(Language._Variable)));
          (v88616->pname = symbol_I_string2(CSTRING("XX")));
          (v88616->range = v82362->domain);
          add_I_property(Kernel.instances,Language._Variable,11,_oid_(v88616));
          v82400 = v88616;
          } 
        GC_OBJECT(Variable,v82400);} 
      Variable * v82401;
      { { Variable * v88616 = ((Variable *) GC_OBJECT(Variable,new_object_class(Language._Variable)));
          (v88616->pname = symbol_I_string2(CSTRING("YY")));
          (v88616->range = Kernel._bag);
          add_I_property(Kernel.instances,Language._Variable,11,_oid_(v88616));
          v82401 = v88616;
          } 
        GC_OBJECT(Variable,v82401);} 
      Variable * v82402;
      { { Variable * v88616 = ((Variable *) GC_OBJECT(Variable,new_object_class(Language._Variable)));
          (v88616->pname = symbol_I_string2(CSTRING("ZZ")));
          (v88616->range = member_type(v82362->range));
          add_I_property(Kernel.instances,Language._Variable,11,_oid_(v88616));
          v82402 = v88616;
          } 
        GC_OBJECT(Variable,v82402);} 
      list * v63709 = list::empty(Kernel._any);
      tformat_string(CSTRING("compute set_write for ~S \n"),0,list::alloc(1,_oid_(v82362)));
      if (((v82362->inverse == (NULL)) ? CTRUE : CFALSE) != CTRUE)
       { { OID  v48075;
          { For * v88616 = ((For *) GC_OBJECT(For,new_object_class(Language._For)));
            (v88616->var = v82402);
            (v88616->set_arg = Produce_get_relation2(v82362,v82400));
            (v88616->arg = (INHERIT(v82362->inverse->isa,Kernel._property) ?  Produce_remove_property2((property *) OBJECT(property,_oid_(v82362->inverse)),OBJECT(Variable,_oid_(v82402)),_oid_(v82400)) :   Produce_remove_table2((table *) OBJECT(table,_oid_(v82362->inverse)),OBJECT(Variable,_oid_(v82402)),_oid_(v82400))));
            add_I_property(Kernel.instances,Language._For,11,_oid_(v88616));
            v48075 = _oid_(v88616);
            } 
          v63709 = v63709->addFast(v48075);
          } 
        GC_OBJECT(list,v63709);} 
      v63709= GC_OBJECT(list,v63709->addFast(GC_OID(Produce_erase_property2(((property *) v82362),v82400))));
      { { OID  v49036;
          { For * v88616 = ((For *) GC_OBJECT(For,new_object_class(Language._For)));
            (v88616->var = v82402);
            (v88616->set_arg = _oid_(v82401));
            (v88616->arg = (INHERIT(v82362->isa,Kernel._property) ?  Produce_put_property2((property *) OBJECT(property,_oid_(v82362)),OBJECT(Variable,_oid_(v82400)),_oid_(v82402)) :   Produce_put_table2((table *) OBJECT(table,_oid_(v82362)),OBJECT(Variable,_oid_(v82400)),_oid_(v82402))));
            add_I_property(Kernel.instances,Language._For,11,_oid_(v88616));
            v49036 = _oid_(v88616);
            } 
          v63709 = v63709->addFast(v49036);
          } 
        GC_OBJECT(list,v63709);} 
      { char * v116386 = GC_STRING(append_string(GC_STRING(string_I_symbol(v82362->name)),CSTRING("_set_write")));
        { lambda * v49997;
          { { OID  v50958;
              { Do * v88616 = ((Do *) GC_OBJECT(Do,new_object_class(Language._Do)));
                (v88616->args = v63709);
                add_I_property(Kernel.instances,Language._Do,11,_oid_(v88616));
                v50958 = _oid_(v88616);
                } 
              v49997 = lambda_I_list(list::alloc(2,_oid_(v82400),_oid_(v82401)),v50958);
              } 
            GC_OBJECT(lambda,v49997);} 
          Result = compile_lambda_string(v116386,v49997,_oid_(Kernel._void));
          } 
        } 
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  Produce_put_property2(property *v82394,Variable *v82400,OID v82401)
{ GC_BIND;
  { OID Result = 0;
    { list * v82388 = list::empty(Kernel._any);
      { OID gc_local;
        ITERATE(v64147);
        for (START(v82394->restrictions); NEXT(v64147);)
        { GC_LOOP;
          if ((Kernel._slot == OBJECT(ClaireObject,v64147)->isa) && 
              (boolean_I_any(_oid_(_exp_type(GC_OBJECT(ClaireType,ptype_type(v82400->range)),domain_I_restriction(OBJECT(restriction,v64147))))) == CTRUE))
           { list * v51919;
            { { OID v_bag;
                GC_ANY(v51919= list::empty(Kernel.emptySet));
                ((list *) v51919)->addFast(_oid_(domain_I_restriction(OBJECT(restriction,v64147))));
                if (boolean_I_any(_oid_(v82394->multivalued_ask)) == CTRUE)
                 { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                  (v88616->selector = Kernel.add_I);
                  { Call * v65520 = v88616; 
                    list * v65521;
                    { OID v_bag;
                      GC_ANY(v65521= list::empty(Kernel.emptySet));
                      { { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                          (v88616->selector = v82394);
                          { Call * v65522 = v88616; 
                            list * v65523;
                            { OID v_bag;
                              GC_ANY(v65523= list::empty(Kernel.emptySet));
                              { { Cast * v88616 = ((Cast *) GC_OBJECT(Cast,new_object_class(Language._Cast)));
                                  (v88616->arg = _oid_(v82400));
                                  (v88616->set_arg = domain_I_restriction(OBJECT(restriction,v64147)));
                                  add_I_property(Kernel.instances,Language._Cast,11,_oid_(v88616));
                                  v_bag = _oid_(v88616);
                                  } 
                                GC_OID(v_bag);} 
                              ((list *) v65523)->addFast(v_bag);} 
                            (v65522->args = v65523);} 
                          add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
                          v_bag = _oid_(v88616);
                          } 
                        GC_OID(v_bag);} 
                      ((list *) v65521)->addFast(v_bag);
                      ((list *) v65521)->addFast(v82401);} 
                    (v65520->args = v65521);} 
                  add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
                  v_bag = _oid_(v88616);
                  } 
                else { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                    (v88616->selector = Kernel.put);
                    { Call * v66196 = v88616; 
                      list * v66197;
                      { OID v_bag;
                        GC_ANY(v66197= list::empty(Kernel.emptySet));
                        ((list *) v66197)->addFast(_oid_(v82394));
                        { { Cast * v88616 = ((Cast *) GC_OBJECT(Cast,new_object_class(Language._Cast)));
                            (v88616->arg = _oid_(v82400));
                            (v88616->set_arg = domain_I_restriction(OBJECT(restriction,v64147)));
                            add_I_property(Kernel.instances,Language._Cast,11,_oid_(v88616));
                            v_bag = _oid_(v88616);
                            } 
                          GC_OID(v_bag);} 
                        ((list *) v66197)->addFast(v_bag);
                        ((list *) v66197)->addFast(v82401);} 
                      (v66196->args = v66197);} 
                    add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
                    v_bag = _oid_(v88616);
                    } 
                  ((list *) v51919)->addFast(v_bag);} 
              GC_OBJECT(list,v51919);} 
            v82388 = add_star_list(v82388,v51919);
            } 
          GC_UNLOOP;} 
        } 
      if (v82388->length == 2)
       Result = (*(v82388))[2];
      else { Case * v88616 = ((Case *) GC_OBJECT(Case,new_object_class(Language._Case)));
          (v88616->var = _oid_(v82400));
          (v88616->args = v82388);
          add_I_property(Kernel.instances,Language._Case,11,_oid_(v88616));
          Result = _oid_(v88616);
          } 
        } 
    GC_UNBIND; return (Result);} 
  } 

OID  Produce_erase_property2(property *v82394,Variable *v82400)
{ GC_BIND;
  { OID Result = 0;
    { list * v82388 = list::empty(Kernel._any);
      bag * v20105;
      if (v82394->multivalued_ask == Kernel._list)
       v20105 = list::empty(Kernel._any);
      else v20105 = set::empty(Kernel._any);
        cast_I_bag(v20105,member_type(v82394->range));
      { OID gc_local;
        ITERATE(v64147);
        for (START(v82394->restrictions); NEXT(v64147);)
        { GC_LOOP;
          if ((Kernel._slot == OBJECT(ClaireObject,v64147)->isa) && 
              (boolean_I_any(_oid_(_exp_type(GC_OBJECT(ClaireType,ptype_type(v82400->range)),domain_I_restriction(OBJECT(restriction,v64147))))) == CTRUE))
           { list * v49078;
            { { OID v_bag;
                GC_ANY(v49078= list::empty(Kernel.emptySet));
                ((list *) v49078)->addFast(_oid_(domain_I_restriction(OBJECT(restriction,v64147))));
                { { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                    (v88616->selector = Kernel.put);
                    { Call * v66199 = v88616; 
                      list * v66200;
                      { OID v_bag;
                        GC_ANY(v66200= list::empty(Kernel.emptySet));
                        ((list *) v66200)->addFast(_oid_(v82394));
                        { { Cast * v88616 = ((Cast *) GC_OBJECT(Cast,new_object_class(Language._Cast)));
                            (v88616->arg = _oid_(v82400));
                            (v88616->set_arg = domain_I_restriction(OBJECT(restriction,v64147)));
                            add_I_property(Kernel.instances,Language._Cast,11,_oid_(v88616));
                            v_bag = _oid_(v88616);
                            } 
                          GC_OID(v_bag);} 
                        ((list *) v66200)->addFast(v_bag);
                        { if (boolean_I_any(_oid_(v82394->multivalued_ask)) == CTRUE)
                           v_bag = _oid_(v20105);
                          else v_bag = OBJECT(slot,v64147)->DEFAULT;
                            GC_OID(v_bag);} 
                        ((list *) v66200)->addFast(v_bag);} 
                      (v66199->args = v66200);} 
                    add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
                    v_bag = _oid_(v88616);
                    } 
                  GC_OID(v_bag);} 
                ((list *) v49078)->addFast(v_bag);} 
              GC_OBJECT(list,v49078);} 
            v82388 = add_star_list(v82388,v49078);
            } 
          GC_UNLOOP;} 
        } 
      if (v82388->length == 2)
       Result = (*(v82388))[2];
      else { Case * v88616 = ((Case *) GC_OBJECT(Case,new_object_class(Language._Case)));
          (v88616->var = _oid_(v82400));
          (v88616->args = v82388);
          add_I_property(Kernel.instances,Language._Case,11,_oid_(v88616));
          Result = _oid_(v88616);
          } 
        } 
    GC_UNBIND; return (Result);} 
  } 

OID  Produce_put_table2(table *v82394,Variable *v82400,OID v82401)
{ GC_BIND;
  { OID Result = 0;
    { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
      (v88616->selector = Kernel.put);
      { Call * v66201 = v88616; 
        list * v66202;
        { OID v_bag;
          GC_ANY(v66202= list::empty(Kernel.emptySet));
          ((list *) v66202)->addFast(_oid_(v82394));
          ((list *) v66202)->addFast(_oid_(v82400));
          if (boolean_I_any(_oid_(v82394->multivalued_ask)) == CTRUE)
           { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
            (v88616->selector = Kernel.add);
            (v88616->args = list::alloc(2,_oid_(list::alloc(2,_oid_(Kernel.nth),_oid_(list::alloc(2,_oid_(v82394),_oid_(v82400))))),v82401));
            add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
            v_bag = _oid_(v88616);
            } 
          else v_bag = v82401;
            ((list *) v66202)->addFast(v_bag);} 
        (v66201->args = v66202);} 
      add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
      Result = _oid_(v88616);
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  Produce_get_relation2(ClaireRelation *v82394,Variable *v82400)
{ GC_BIND;
  { OID Result = 0;
    if (INHERIT(v82394->isa,Kernel._table))
     { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
      (v88616->selector = Kernel.nth);
      (v88616->args = list::alloc(2,_oid_(v82394),_oid_(v82400)));
      add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
      Result = _oid_(v88616);
      } 
    else if (INHERIT(v82394->isa,Kernel._property))
     { list * v82388 = list::empty(Kernel._any);
      { OID gc_local;
        ITERATE(v64147);
        for (START(CLREAD(property,v82394,restrictions)); NEXT(v64147);)
        { GC_LOOP;
          if ((Kernel._slot == OBJECT(ClaireObject,v64147)->isa) && 
              (boolean_I_any(_oid_(_exp_type(GC_OBJECT(ClaireType,ptype_type(v82400->range)),domain_I_restriction(OBJECT(restriction,v64147))))) == CTRUE))
           { list * v53883;
            { { OID v_bag;
                GC_ANY(v53883= list::empty(Kernel.emptySet));
                ((list *) v53883)->addFast(_oid_(domain_I_restriction(OBJECT(restriction,v64147))));
                { { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                    (v88616->selector = ((property *) v82394));
                    { Call * v66204 = v88616; 
                      list * v66205;
                      { OID v_bag;
                        GC_ANY(v66205= list::empty(Kernel.emptySet));
                        { { Cast * v88616 = ((Cast *) GC_OBJECT(Cast,new_object_class(Language._Cast)));
                            (v88616->arg = _oid_(v82400));
                            (v88616->set_arg = domain_I_restriction(OBJECT(restriction,v64147)));
                            add_I_property(Kernel.instances,Language._Cast,11,_oid_(v88616));
                            v_bag = _oid_(v88616);
                            } 
                          GC_OID(v_bag);} 
                        ((list *) v66205)->addFast(v_bag);} 
                      (v66204->args = v66205);} 
                    add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
                    v_bag = _oid_(v88616);
                    } 
                  GC_OID(v_bag);} 
                ((list *) v53883)->addFast(v_bag);} 
              GC_OBJECT(list,v53883);} 
            v82388 = add_star_list(v82388,v53883);
            } 
          GC_UNLOOP;} 
        } 
      if (v82388->length == 2)
       Result = (*(v82388))[2];
      else { Case * v88616 = ((Case *) GC_OBJECT(Case,new_object_class(Language._Case)));
          (v88616->var = _oid_(v82400));
          (v88616->args = v82388);
          add_I_property(Kernel.instances,Language._Case,11,_oid_(v88616));
          Result = _oid_(v88616);
          } 
        } 
    else Result = Kernel.cfalse;
      GC_UNBIND; return (Result);} 
  } 

OID  Produce_remove_property2(property *v82394,Variable *v82400,OID v82401)
{ GC_BIND;
  { OID Result = 0;
    { list * v82388 = list::empty(Kernel._any);
      { OID gc_local;
        ITERATE(v64147);
        for (START(v82394->restrictions); NEXT(v64147);)
        { GC_LOOP;
          if (Kernel._slot == OBJECT(ClaireObject,v64147)->isa)
           { list * v76947;
            { { OID v_bag;
                GC_ANY(v76947= list::empty(Kernel.emptySet));
                ((list *) v76947)->addFast(_oid_(domain_I_restriction(OBJECT(restriction,v64147))));
                if (boolean_I_any(_oid_(v82394->multivalued_ask)) == CTRUE)
                 { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                  (v88616->selector = Kernel._delete);
                  { Call * v66228 = v88616; 
                    list * v66229;
                    { OID v_bag;
                      GC_ANY(v66229= list::empty(Kernel.emptySet));
                      { { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                          (v88616->selector = v82394);
                          (v88616->args = list::alloc(1,_oid_(v82400)));
                          add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
                          v_bag = _oid_(v88616);
                          } 
                        GC_OID(v_bag);} 
                      ((list *) v66229)->addFast(v_bag);
                      ((list *) v66229)->addFast(v82401);} 
                    (v66228->args = v66229);} 
                  add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
                  v_bag = _oid_(v88616);
                  } 
                else { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                    (v88616->selector = Kernel.put);
                    (v88616->args = list::alloc(3,_oid_(v82394),
                      _oid_(v82400),
                      CNULL));
                    add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
                    v_bag = _oid_(v88616);
                    } 
                  ((list *) v76947)->addFast(v_bag);} 
              GC_OBJECT(list,v76947);} 
            v82388 = add_star_list(v82388,v76947);
            } 
          GC_UNLOOP;} 
        } 
      if (v82388->length == 2)
       Result = (*(v82388))[2];
      else { Case * v88616 = ((Case *) GC_OBJECT(Case,new_object_class(Language._Case)));
          (v88616->var = _oid_(v82400));
          (v88616->args = v82388);
          add_I_property(Kernel.instances,Language._Case,11,_oid_(v88616));
          Result = _oid_(v88616);
          } 
        } 
    GC_UNBIND; return (Result);} 
  } 

OID  Produce_remove_table2(table *v82394,Variable *v82400,OID v82401)
{ GC_BIND;
  { OID Result = 0;
    { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
      (v88616->selector = Kernel.put);
      { Call * v66230 = v88616; 
        list * v66231;
        { OID v_bag;
          GC_ANY(v66231= list::empty(Kernel.emptySet));
          ((list *) v66231)->addFast(_oid_(v82394));
          ((list *) v66231)->addFast(_oid_(v82400));
          if (boolean_I_any(_oid_(v82394->multivalued_ask)) == CTRUE)
           { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
            (v88616->selector = Kernel._delete);
            (v88616->args = list::alloc(2,_oid_(list::alloc(2,_oid_(Kernel.nth),_oid_(list::alloc(2,_oid_(v82394),_oid_(v82400))))),v82401));
            add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
            v_bag = _oid_(v88616);
            } 
          else v_bag = CNULL;
            ((list *) v66231)->addFast(v_bag);} 
        (v66230->args = v66231);} 
      add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
      Result = _oid_(v88616);
      } 
    GC_UNBIND; return (Result);} 
  } 

void  Tighten_relation2(ClaireRelation *v82394)
{ GC_RESERVE(6);  // v3.0.55 optim !
  if (INHERIT(v82394->isa,Kernel._property))
   { ClaireType * v63419 = set::empty();
    ClaireType * v63433 = set::empty();
    { OID gc_local;
      ITERATE(v82395);
      for (START(CLREAD(property,v82394,restrictions)); NEXT(v82395);)
      { GC_LOOP;
        if (Kernel._slot == OBJECT(ClaireObject,v82395)->isa)
         { GC__ANY(v63419 = U_type(v63419,domain_I_restriction(OBJECT(restriction,v82395))), 3);
          GC__ANY(v63433 = U_type(v63433,GC_OBJECT(ClaireType,((multi_ask_any(_oid_(v82394)) == CTRUE) ?
            member_type(OBJECT(restriction,v82395)->range) :
            OBJECT(restriction,v82395)->range ))), 4);
          } 
        GC_UNLOOP;} 
      } 
    (v82394->open = 1);
    (v82394->domain = class_I_type(v63419));
    (v82394->range = ((v82394->multivalued_ask == Kernel._list) ?
      param_I_class(Kernel._list,class_I_type(v63433)) :
      ((v82394->multivalued_ask == Kernel._set) ?
        param_I_class(Kernel._set,class_I_type(v63433)) :
        v63433 ) ));
    ;} 
  GC_UNBIND;} 

void  lexical_num_any2(OID v13540,Cint v82390)
{ GC_BIND;
  if (INHERIT(OWNER(v13540),Language._Call))
   lexical_num_any2(GC_OID(_oid_(OBJECT(Call,v13540)->args)),v82390);
  else if (INHERIT(OWNER(v13540),Language._Instruction))
   { ClaireClass * v16967 = OBJECT(ClaireObject,v13540)->isa;
    if (contain_ask_set(Language._Instruction_with_var->descendents,_oid_(v16967)) == CTRUE)
     { put_property2(Kernel.index,GC_OBJECT(ClaireObject,OBJECT(ClaireObject,(*Language.var)(v13540))),v82390);
      ++v82390;
      if (v82390 > Language._starvariable_index_star->value)
       (Language._starvariable_index_star->value= v82390);
      } 
    { OID gc_local;
      ITERATE(v82395);
      for (START(v16967->slots); NEXT(v82395);)
      { GC_LOOP;
        lexical_num_any2(GC_OID(get_slot(OBJECT(slot,v82395),OBJECT(ClaireObject,v13540))),v82390);
        GC_UNLOOP;} 
      } 
    } 
  else if (INHERIT(OWNER(v13540),Kernel._bag))
   { OID gc_local;
    ITERATE(v82400);
    for (START(OBJECT(bag,v13540)); NEXT(v82400);)
    lexical_num_any2(v82400,v82390);
    } 
  else ;GC_UNBIND;} 

ClaireType * c_type_Defrule2_Optimize(Defrule *v13540)
{ return (Kernel._any);} 

OID  c_code_Defrule_Optimize(Defrule *v13540,ClaireClass *v82395)
{ GC_RESERVE(11);  // v3.0.55 optim !
  { OID Result = 0;
    { OID  v63963 = GC_OID(get_symbol(v13540->ident));
      list * v82388 = list::empty(Kernel._any);
      tformat_string(CSTRING("compile a rule ~S \n"),0,list::alloc(1,v63963));
      { OID gc_local;
        ITERATE(v82394);
        bag *v82394_support;
        v82394_support = GC_OBJECT(set,OBJECT(bag,nth_table1(Language.relations,v63963)));
        for (START(v82394_support); NEXT(v82394);)
        if (eventMethod_ask_relation2(OBJECT(ClaireRelation,v82394)) != CTRUE)
         Tighten_relation2(OBJECT(ClaireRelation,v82394));
        } 
      { OID gc_local;
        ITERATE(v82394);
        bag *v82394_support;
        v82394_support = GC_OBJECT(set,OBJECT(bag,nth_table1(Language.relations,v63963)));
        for (START(v82394_support); NEXT(v82394);)
        { GC_LOOP;
          { if ((*Kernel.open)(v82394) < 2)
             { OID  v81752;
              { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                (v88616->selector = Kernel.FINAL);
                (v88616->args = list::alloc(1,v82394));
                add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
                v81752 = _oid_(v88616);
                } 
              v82388 = v82388->addFast(v81752);
              } 
            compile_if_write_relation(OBJECT(ClaireRelation,v82394));
            { OID  v116386 = GC_OID((*Kernel._7_plus)(GC_OID((*Kernel.name)(v82394)),
                _string_(CSTRING("_write"))));
              char * v82395 = GC_STRING(string_I_symbol(OBJECT(symbol,v116386)));
              OID  v63758 = GC_OID((*Kernel.if_write)(v82394));
              compile_lambda_string(v82395,OBJECT(lambda,v63758),_oid_(Kernel._void));
              { OID  v82713;
                { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                  (v88616->selector = Kernel.put);
                  (v88616->args = list::alloc(3,Optimize.if_write->value,
                    v82394,
                    _oid_(make_function_string(v82395))));
                  add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
                  v82713 = _oid_(v88616);
                  } 
                v82388->addFast(v82713);
                } 
              } 
            } 
          GC_UNLOOP;} 
        } 
      { OID gc_local;
        ITERATE(v82394);
        bag *v82394_support;
        v82394_support = GC_OBJECT(set,OBJECT(bag,nth_table1(Language.relations,v63963)));
        for (START(v82394_support); NEXT(v82394);)
        { GC_LOOP;
          if (eventMethod_ask_relation2(OBJECT(ClaireRelation,v82394)) == CTRUE)
           v82388= v82388->addFast(GC_OID(compileEventMethod_property(OBJECT(property,v82394))));
          GC_UNLOOP;} 
        } 
      { OID  v83674;
        { Do * v88616 = ((Do *) GC_OBJECT(Do,new_object_class(Language._Do)));
          (v88616->args = v82388);
          add_I_property(Kernel.instances,Language._Do,11,_oid_(v88616));
          v83674 = _oid_(v88616);
          } 
        Result = (*Optimize.c_code)(v83674,
          _oid_(v82395));
        } 
      } 
    GC_UNBIND; return (Result);} 
  } 

void  compile_if_write_relation(ClaireRelation *v82362)
{ GC_BIND;
  { OID  v82388 = GC_OID(nth_table1(Language.demons,_oid_(v82362)));
    list * v83155 = GC_OBJECT(list,OBJECT(Language_demon,(*(OBJECT(bag,v82388)))[1])->formula->vars);
    list * v63709 = list::alloc(Kernel._any,1,GC_OID((*Optimize.Produce_put)(_oid_(v82362),
      (*(v83155))[1],
      (*(v83155))[2])));
    list * v63710;
    { { bag *v_list; OID v_val;
        OID v82400,CLcount;
        v_list = OBJECT(bag,v82388);
         v63710 = v_list->clone(Kernel._any);
        for (CLcount= 1; CLcount <= v_list->length; CLcount++)
        { v82400 = (*(v_list))[CLcount];
          v_val = substitution_any(substitution_any(substitution_any(OBJECT(Language_demon,v82400)->formula->body,OBJECT(Variable,(*(OBJECT(Language_demon,v82400)->formula->vars))[3]),(*(v83155))[3]),OBJECT(Variable,(*(OBJECT(Language_demon,v82400)->formula->vars))[1]),(*(v83155))[1]),OBJECT(Variable,(*(OBJECT(Language_demon,v82400)->formula->vars))[2]),(*(v83155))[2]);
          
          (*((list *) v63710))[CLcount] = v_val;} 
        } 
      GC_OBJECT(list,v63710);} 
    put_property2(Kernel.range,OBJECT(ClaireObject,(*(v83155))[1]),_oid_(v82362->domain));
    put_property2(Kernel.range,OBJECT(ClaireObject,(*(v83155))[2]),_oid_(v82362->range));
    { ITERATE(v82398);
      for (START(v83155); NEXT(v82398);)
      put_property2(Kernel.range,OBJECT(ClaireObject,v82398),_oid_(class_I_type(OBJECT(ClaireType,(*Kernel.range)(v82398)))));
      } 
    if ((INHERIT(OWNER((*(v63710))[1]),Language._If)) && 
        (eventMethod_ask_relation2(v82362) != CTRUE))
     { if (INHERIT(OWNER(OBJECT(If,(*(v63710))[1])->test),Language._And))
       { If * v66235 = OBJECT(If,(*(v63710))[1]); 
        OID  v66236;
        { And * v88616 = ((And *) GC_OBJECT(And,new_object_class(Language._And)));
          (v88616->args = cdr_list(GC_OBJECT(list,OBJECT(list,(*Core.args)(GC_OID(OBJECT(If,(*(v63710))[1])->test))))));
          add_I_property(Kernel.instances,Language._And,11,_oid_(v88616));
          v66236 = _oid_(v88616);
          } 
        (v66235->test = v66236);} 
      else ((*(v63710))[1]=OBJECT(If,(*(v63710))[1])->arg);
        } 
    if (((v82362->inverse == (NULL)) ? CTRUE : CFALSE) != CTRUE)
     { if (multi_ask_any(_oid_(v82362)) != CTRUE)
       v63709= GC_OBJECT(list,v63709->addFast(GC_OID((*Optimize.Produce_remove)(_oid_(v82362->inverse),
        (*(v83155))[3],
        (*(v83155))[1]))));
      v63709= GC_OBJECT(list,v63709->addFast(GC_OID((*Optimize.Produce_put)(_oid_(v82362->inverse),
        (*(v83155))[2],
        (*(v83155))[1]))));
      } 
    { ClaireRelation * v66258 = v82362; 
      OID  v66259;
      { lambda * v74511;{ OID  v109621;
          if (eventMethod_ask_relation2(v82362) == CTRUE)
           { Do * v88616 = ((Do *) GC_OBJECT(Do,new_object_class(Language._Do)));
            (v88616->args = v63710);
            add_I_property(Kernel.instances,Language._Do,11,_oid_(v88616));
            v109621 = _oid_(v88616);
            } 
          else if (multi_ask_any(_oid_(v82362)) == CTRUE)
           { If * v88616 = ((If *) GC_OBJECT(If,new_object_class(Language._If)));
            { If * v66262 = v88616; 
              OID  v66263;
              { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                (v88616->selector = Core.NOT);
                { Call * v66264 = v88616; 
                  list * v66265;
                  { OID v_bag;
                    GC_ANY(v66265= list::empty(Kernel.emptySet));
                    { { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                        (v88616->selector = Kernel._Z);
                        (v88616->args = list::alloc(2,(*(v83155))[2],GC_OID(_oid_(readCall_relation(v82362,(*(v83155))[1])))));
                        add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
                        v_bag = _oid_(v88616);
                        } 
                      GC_OID(v_bag);} 
                    ((list *) v66265)->addFast(v_bag);} 
                  (v66264->args = v66265);} 
                add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
                v66263 = _oid_(v88616);
                } 
              (v66262->test = v66263);} 
            { If * v66266 = v88616; 
              OID  v66267;
              { Do * v88616 = ((Do *) GC_OBJECT(Do,new_object_class(Language._Do)));
                (v88616->args = append_list(v63709,v63710));
                add_I_property(Kernel.instances,Language._Do,11,_oid_(v88616));
                v66267 = _oid_(v88616);
                } 
              (v66266->arg = v66267);} 
            add_I_property(Kernel.instances,Language._If,11,_oid_(v88616));
            (v88616->other = Kernel.cfalse);
            v109621 = _oid_(v88616);
            } 
          else { Let * v88616 = ((Let *) GC_OBJECT(Let,new_object_class(Language._Let)));
              store_object(v88616,
                2,
                Kernel._object,
                (*(v83155))[3],
                CFALSE);
              (v88616->value = _oid_(readCall_relation(v82362,(*(v83155))[1])));
              { Let * v66289 = v88616; 
                OID  v66290;
                { If * v88616 = ((If *) GC_OBJECT(If,new_object_class(Language._If)));
                  { If * v66291 = v88616; 
                    OID  v66292;
                    { Call * v88616 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                      (v88616->selector = Core._I_equal);
                      (v88616->args = list::alloc(2,(*(v83155))[2],(*(v83155))[3]));
                      add_I_property(Kernel.instances,Language._Call,11,_oid_(v88616));
                      v66292 = _oid_(v88616);
                      } 
                    (v66291->test = v66292);} 
                  { If * v66293 = v88616; 
                    OID  v66294;
                    { Do * v88616 = ((Do *) GC_OBJECT(Do,new_object_class(Language._Do)));
                      (v88616->args = append_list(v63709,v63710));
                      add_I_property(Kernel.instances,Language._Do,11,_oid_(v88616));
                      v66294 = _oid_(v88616);
                      } 
                    (v66293->arg = v66294);} 
                  add_I_property(Kernel.instances,Language._If,11,_oid_(v88616));
                  (v88616->other = Kernel.cfalse);
                  v66290 = _oid_(v88616);
                  } 
                (v66289->arg = v66290);} 
              add_I_property(Kernel.instances,Language._Let,11,_oid_(v88616));
              v109621 = _oid_(v88616);
              } 
            v74511 = lambda_I_list(list::alloc(2,(*(v83155))[1],(*(v83155))[2]),v109621);
          } 
        
        v66259=_oid_(v74511);} 
      (v66258->if_write = v66259);} 
    } 
  GC_UNBIND;} 

OID  compileEventMethod_property(property *v82392)
{ GC_BIND;
  { OID Result = 0;
    { method * v82389 = OBJECT(method,(*(v82392->restrictions))[1]);
      char * v63819 = GC_STRING(append_string(GC_STRING(string_I_symbol(v82392->name)),CSTRING("_write")));
      Result = add_method_I_method(v82389,
        list::alloc(2,_oid_(v82392->domain),_oid_(v82392->range)),
        _oid_(Kernel._void),
        0,
        make_function_string(v63819));
      } 
    GC_UNBIND; return (Result);} 
  } 

