/***** CLAIRE Compilation of file e:\claire\v3.5\src\compile\odefine.cl 
         [version 3.5.0 / safety 5] Sun May 28 08:25:59 2017 *****/

#include <claire.h>
#include <Kernel.h>
#include <Core.h>
#include <Language.h>
#include <Reader.h>
#include <Optimize.h>
ClaireType * c_type_List_Optimize(List *v9332)
{ GC_BIND;
  ;{ ClaireType *Result ;
    if (((v9332->of == (NULL)) ? CTRUE : CFALSE) != CTRUE)
     Result = param_I_class(Kernel._list,v9332->of);
    else { OID  v8067 = _oid_(Kernel.emptySet);
        { OID gc_local;
          ITERATE(v1051);
          for (START(v9332->args); NEXT(v1051);)
          if (boolean_I_any(v8067) == CTRUE)
           v8067= _oid_(meet_class(OBJECT(ClaireClass,v8067),class_I_type(ptype_type(OBJECT(ClaireType,(*Optimize.c_type)(v1051))))));
          else v8067= _oid_(class_I_type(ptype_type(OBJECT(ClaireType,(*Optimize.c_type)(v1051)))));
            } 
        Result = nth_class1(Kernel._list,OBJECT(ClaireType,v8067));
        } 
      GC_UNBIND; return (Result);} 
  } 

OID  c_code_List_Optimize(List *v9332)
{ GC_BIND;
  (Optimize.OPT->allocation = CTRUE);
  { OID Result = 0;
    { List * v15440;
      { { List * v10264 = ((List *) GC_OBJECT(List,new_object_class(Language._List)));
          { Construct * v1287 = v10264; 
            list * v1289;
            { bag *v_list; OID v_val;
              OID v1051,CLcount;
              v_list = GC_OBJECT(list,v9332->args);
               v1289 = v_list->clone();
              for (CLcount= 1; CLcount <= v_list->length; CLcount++)
              { v1051 = (*(v_list))[CLcount];
                v_val = c_gc_I_any2(GC_OID((*Optimize.c_code)(v1051,
                  _oid_(Kernel._any))),GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(v1051))));
                
                (*((list *) v1289))[CLcount] = v_val;} 
              } 
            (v1287->args = v1289);} 
          add_I_property(Kernel.instances,Language._List,11,_oid_(v10264));
          v15440 = v10264;
          } 
        GC_OBJECT(List,v15440);} 
      if (((v9332->of == (NULL)) ? CTRUE : CFALSE) != CTRUE)
       { { ClaireBoolean * g0307I;
          { ClaireBoolean *v_or;
            { v_or = ((Optimize.compiler->safety > 4) ? CTRUE : CFALSE);
              if (v_or == CTRUE) g0307I =CTRUE; 
              else { v_or = ((equal(_oid_(v9332->of),_oid_(Kernel.emptySet)) == CTRUE) ? CTRUE : CFALSE);
                if (v_or == CTRUE) g0307I =CTRUE; 
                else { { OID  v13612;
                    { OID gc_local;
                      ITERATE(v1051);
                      v13612= Kernel.cfalse;
                      bag *v1051_support;
                      v1051_support = GC_OBJECT(list,v9332->args);
                      for (START(v1051_support); NEXT(v1051);)
                      { GC_LOOP;
                        if (_inf_equal_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(v1051))),GC_OBJECT(ClaireType,v9332->of)) != CTRUE)
                         { v13612 = Kernel.ctrue;
                          break;} 
                        GC_UNLOOP;} 
                      } 
                    v_or = not_any(v13612);
                    } 
                  if (v_or == CTRUE) g0307I =CTRUE; 
                  else g0307I = CFALSE;} 
                } 
              } 
            } 
          
          if (g0307I == CTRUE) { (v15440->of = v9332->of);
              Result = _oid_(v15440);
              } 
            else { warn_void();
            { list * v14571;
              { { OID v_bag;
                  GC_ANY(v14571= list::empty(Kernel.emptySet));
                  { { list * v2940;{ bag *v_list; OID v_val;
                        OID v1051,CLcount;
                        v_list = GC_OBJECT(list,v9332->args);
                         v2940 = v_list->clone();
                        for (CLcount= 1; CLcount <= v_list->length; CLcount++)
                        { v1051 = (*(v_list))[CLcount];
                          v_val = (*Optimize.c_type)(v1051);
                          
                          (*((list *) v2940))[CLcount] = v_val;} 
                        } 
                      
                      v_bag=_oid_(v2940);} 
                    GC_OID(v_bag);} 
                  ((list *) v14571)->addFast(v_bag);
                  ((list *) v14571)->addFast(GC_OID(_oid_(v9332->of)));} 
                GC_OBJECT(list,v14571);} 
              tformat_string(CSTRING("unsafe typed list: ~S not in ~S [262]\n"),2,v14571);
              } 
            { OID  v3906;
              { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                (v10264->selector = Core.check_in);
                (v10264->args = list::alloc(3,_oid_(v15440),
                  _oid_(Kernel._list),
                  GC_OID(_oid_(v9332->of))));
                add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
                v3906 = _oid_(v10264);
                } 
              Result = (*Optimize.c_code)(v3906,
                _oid_(Kernel._list));
              } 
            } 
          } 
        } 
      else Result = _oid_(v15440);
        } 
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_Set_Optimize(Set *v9332)
{ GC_BIND;
  ;{ ClaireType *Result ;
    if (((v9332->of == (NULL)) ? CTRUE : CFALSE) != CTRUE)
     Result = param_I_class(Kernel._set,v9332->of);
    else { OID  v8067 = _oid_(Kernel.emptySet);
        { OID gc_local;
          ITERATE(v1051);
          for (START(v9332->args); NEXT(v1051);)
          if (boolean_I_any(v8067) == CTRUE)
           v8067= _oid_(meet_class(OBJECT(ClaireClass,v8067),class_I_type(OBJECT(ClaireType,(*Optimize.c_type)(v1051)))));
          else v8067= _oid_(class_I_type(OBJECT(ClaireType,(*Optimize.c_type)(v1051))));
            } 
        Result = nth_class1(Kernel._set,OBJECT(ClaireType,v8067));
        } 
      GC_UNBIND; return (Result);} 
  } 

OID  c_code_Set_Optimize(Set *v9332)
{ GC_BIND;
  (Optimize.OPT->allocation = CTRUE);
  { OID Result = 0;
    { Set * v15440;
      { { Set * v10264 = ((Set *) GC_OBJECT(Set,new_object_class(Language._Set)));
          { Construct * v1315 = v10264; 
            list * v1316;
            { bag *v_list; OID v_val;
              OID v1051,CLcount;
              v_list = GC_OBJECT(list,v9332->args);
               v1316 = v_list->clone();
              for (CLcount= 1; CLcount <= v_list->length; CLcount++)
              { v1051 = (*(v_list))[CLcount];
                v_val = c_gc_I_any2(GC_OID((*Optimize.c_code)(v1051,
                  _oid_(Kernel._any))),GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(v1051))));
                
                (*((list *) v1316))[CLcount] = v_val;} 
              } 
            (v1315->args = v1316);} 
          add_I_property(Kernel.instances,Language._Set,11,_oid_(v10264));
          v15440 = v10264;
          } 
        GC_OBJECT(Set,v15440);} 
      if (((v9332->of == (NULL)) ? CTRUE : CFALSE) != CTRUE)
       { { ClaireBoolean * g0314I;
          { ClaireBoolean *v_or;
            { v_or = ((Optimize.compiler->safety > 4) ? CTRUE : CFALSE);
              if (v_or == CTRUE) g0314I =CTRUE; 
              else { v_or = ((equal(_oid_(v9332->of),_oid_(Kernel.emptySet)) == CTRUE) ? CTRUE : CFALSE);
                if (v_or == CTRUE) g0314I =CTRUE; 
                else { { OID  v7750;
                    { OID gc_local;
                      ITERATE(v1051);
                      v7750= Kernel.cfalse;
                      bag *v1051_support;
                      v1051_support = GC_OBJECT(list,v9332->args);
                      for (START(v1051_support); NEXT(v1051);)
                      { GC_LOOP;
                        if (_inf_equal_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(v1051))),GC_OBJECT(ClaireType,v9332->of)) != CTRUE)
                         { v7750 = Kernel.ctrue;
                          break;} 
                        GC_UNLOOP;} 
                      } 
                    v_or = not_any(v7750);
                    } 
                  if (v_or == CTRUE) g0314I =CTRUE; 
                  else g0314I = CFALSE;} 
                } 
              } 
            } 
          
          if (g0314I == CTRUE) { (v15440->of = v9332->of);
              Result = _oid_(v15440);
              } 
            else { warn_void();
            { list * v8711;
              { { OID v_bag;
                  GC_ANY(v8711= list::empty(Kernel.emptySet));
                  { { list * v2947;{ bag *v_list; OID v_val;
                        OID v1051,CLcount;
                        v_list = GC_OBJECT(list,v9332->args);
                         v2947 = v_list->clone();
                        for (CLcount= 1; CLcount <= v_list->length; CLcount++)
                        { v1051 = (*(v_list))[CLcount];
                          v_val = (*Optimize.c_type)(v1051);
                          
                          (*((list *) v2947))[CLcount] = v_val;} 
                        } 
                      
                      v_bag=_oid_(v2947);} 
                    GC_OID(v_bag);} 
                  ((list *) v8711)->addFast(v_bag);
                  ((list *) v8711)->addFast(GC_OID(_oid_(v9332->of)));} 
                GC_OBJECT(list,v8711);} 
              tformat_string(CSTRING("unsafe typed set: ~S not in ~S [262]\n"),2,v8711);
              } 
            { OID  v10633;
              { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                (v10264->selector = Core.check_in);
                (v10264->args = list::alloc(3,_oid_(v15440),
                  _oid_(Kernel._set),
                  GC_OID(_oid_(v9332->of))));
                add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
                v10633 = _oid_(v10264);
                } 
              Result = (*Optimize.c_code)(v10633,
                _oid_(Kernel._set));
              } 
            } 
          } 
        } 
      else Result = _oid_(v15440);
        } 
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_Tuple_Optimize(Tuple *v9332)
{ GC_BIND;
  { ClaireType *Result ;
    { list * v11594;
      { { bag *v_list; OID v_val;
          OID v15440,CLcount;
          v_list = v9332->args;
           v11594 = v_list->clone();
          for (CLcount= 1; CLcount <= v_list->length; CLcount++)
          { v15440 = (*(v_list))[CLcount];
            v_val = (*Optimize.c_type)(v15440);
            
            (*((list *) v11594))[CLcount] = v_val;} 
          } 
        GC_OBJECT(list,v11594);} 
      Result = tuple_I_list(v11594);
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_Tuple_Optimize(Tuple *v9332)
{ GC_BIND;
  (Optimize.OPT->allocation = CTRUE);
  { OID Result = 0;
    { Tuple * v10264 = ((Tuple *) GC_OBJECT(Tuple,new_object_class(Language._Tuple)));
      { Construct * v1344 = v10264; 
        list * v1345;
        { bag *v_list; OID v_val;
          OID v1051,CLcount;
          v_list = GC_OBJECT(list,v9332->args);
           v1345 = v_list->clone();
          for (CLcount= 1; CLcount <= v_list->length; CLcount++)
          { v1051 = (*(v_list))[CLcount];
            v_val = c_gc_I_any2(GC_OID((*Optimize.c_code)(v1051,
              _oid_(Kernel._any))),GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(v1051))));
            
            (*((list *) v1345))[CLcount] = v_val;} 
          } 
        (v1344->args = v1345);} 
      add_I_property(Kernel.instances,Language._Tuple,11,_oid_(v10264));
      Result = _oid_(v10264);
      } 
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_Definition_Optimize(Definition *v9332)
{ { ClaireType *Result ;
    if (_inf_equalt_class(v9332->arg,Kernel._exception) == CTRUE)
     Result = Kernel.emptySet;
    else Result = v9332->arg;
      return (Result);} 
  } 

OID  c_code_Definition_Optimize(Definition *v9332,ClaireClass *v15435)
{ GC_BIND;
  { OID Result = 0;
    { ClaireClass * v1030 = v9332->arg;
      Variable * v1049;
      { { Cint  v2851;
          { (Optimize.OPT->max_vars = (Optimize.OPT->max_vars+1));
            v2851 = 0;
            } 
          v1049 = Variable_I_symbol(OBJECT(symbol,Optimize._starname_star->value),v2851,v1030);
          } 
        GC_OBJECT(Variable,v1049);} 
      OID  v1051 = GC_OID(total_ask_class(v1030,GC_OBJECT(list,v9332->args)));
      if (v1030->open <= 0)
       close_exception(((general_error *) (*Core._general_error)(_string_(CSTRING("[105] cannot instantiate ~S")),
        _oid_(list::alloc(1,_oid_(v1030))))));
      if (boolean_I_any(v1051) == CTRUE)
       Result = (*Optimize.c_code)(v1051,
        _oid_(v15435));
      else { OID  v3812;
          { Let * v10264 = ((Let *) GC_OBJECT(Let,new_object_class(Language._Let)));
            (v10264->var = v1049);
            { Let * v1349 = v10264; 
              OID  v1351;
              { Cast * v10264 = ((Cast *) GC_OBJECT(Cast,new_object_class(Language._Cast)));
                { Cast * v1352 = v10264; 
                  OID  v1353;
                  { OID  v8617;
                    { { OID  v13375;
                        { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                          (v10264->selector = Core.new_I);
                          (v10264->args = list::alloc(1,_oid_(v1030)));
                          add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
                          v13375 = _oid_(v10264);
                          } 
                        v8617 = (*Optimize.c_code)(v13375,
                          _oid_(Kernel._object));
                        } 
                      GC_OID(v8617);} 
                    v1353 = c_gc_I_any1(v8617);
                    } 
                  (v1352->arg = v1353);} 
                (v10264->set_arg = v1030);
                add_I_property(Kernel.instances,Language._Cast,11,_oid_(v10264));
                v1351 = _oid_(v10264);
                } 
              (v1349->value = v1351);} 
            { Let * v1376 = v10264; 
              OID  v1377;
              { Do * v10264 = ((Do *) GC_OBJECT(Do,new_object_class(Language._Do)));
                store_object(v10264,
                  2,
                  Kernel._object,
                  analyze_I_class(v1030,_oid_(v1049),GC_OBJECT(list,v9332->args),list::empty()),
                  CFALSE);
                add_I_property(Kernel.instances,Language._Do,11,_oid_(v10264));
                v1377 = _oid_(v10264);
                } 
              (v1376->arg = v1377);} 
            add_I_property(Kernel.instances,Language._Let,11,_oid_(v10264));
            v3812 = _oid_(v10264);
            } 
          Result = (*Optimize.c_code)(v3812,
            _oid_(v15435));
          } 
        } 
    GC_UNBIND; return (Result);} 
  } 

OID  total_ask_class(ClaireClass *v9332,list *v15428)
{ GC_BIND;
  { OID Result = 0;
    { list * v3245 = GC_OBJECT(list,OBJECT(list,(*Optimize.get_indexed)(_oid_(v9332))));
      Cint  v15431 = v3245->length;
      { ClaireBoolean * g0334I;
        { ClaireBoolean *v_and;
          { v_and = not_any(_oid_(Optimize.compiler->diet_ask));
            if (v_and == CFALSE) g0334I =CFALSE; 
            else { v_and = ((v15428->length == (v15431-1)) ? CTRUE : CFALSE);
              if (v_and == CFALSE) g0334I =CFALSE; 
              else { v_and = ((v9332->open == ClEnv->ephemeral) ? CTRUE : ((_inf_equalt_class(v9332,Kernel._exception) == CTRUE) ? CTRUE : CFALSE));
                if (v_and == CFALSE) g0334I =CFALSE; 
                else { v_and = ((v15431 <= 4) ? CTRUE : CFALSE);
                  if (v_and == CFALSE) g0334I =CFALSE; 
                  else { { OID  v1796;
                      { Cint  v15425 = 2;
                        Cint  v1378 = v15431;
                        { v1796= _oid_(CFALSE);
                          while ((v15425 <= v1378))
                          { if ((((*Kernel.srange)((*(v3245))[v15425]) == _oid_(Kernel._integer)) ? CTRUE : (((*Kernel.srange)((*(v3245))[v15425]) == _oid_(Kernel._any)) ? CTRUE : CFALSE)) != CTRUE)
                             { v1796 = Kernel.ctrue;
                              break;} 
                            ++v15425;
                            } 
                          } 
                        } 
                      v_and = not_any(v1796);
                      } 
                    if (v_and == CFALSE) g0334I =CFALSE; 
                    else g0334I = CTRUE;} 
                  } 
                } 
              } 
            } 
          } 
        
        if (g0334I == CTRUE) { OID  v1030;
            { { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                (v10264->selector = ((v15428->length == 0) ?
                  Core.new_I :
                  Optimize.anyObject_I ));
                { Call * v1381 = v10264; 
                  list * v1382;
                  { list * v4679;
                    { { bag *v_list; OID v_val;
                        OID v15440,CLcount;
                        v_list = v15428;
                         v4679 = v_list->clone();
                        for (CLcount= 1; CLcount <= v_list->length; CLcount++)
                        { v15440 = (*(v_list))[CLcount];
                          v_val = c_gc_I_any1(GC_OID((*Optimize.c_code)(GC_OID((*(OBJECT(bag,(*Core.args)(v15440))))[2]),
                            _oid_(Kernel._any))));
                          
                          (*((list *) v4679))[CLcount] = v_val;} 
                        } 
                      GC_OBJECT(list,v4679);} 
                    v1382 = cons_any(_oid_(v9332),v4679);
                    } 
                  (v1381->args = v1382);} 
                add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
                v1030 = _oid_(v10264);
                } 
              GC_OID(v1030);} 
            OID  v15429 = GC_OID(_oid_(_at_property1(Kernel.close,v9332)));
            if (_inf_equal_type(v9332,Kernel._exception) != CTRUE)
             (Optimize.OPT->allocation = CTRUE);
            if (v15428->length == 0)
             v1030= GC_OID((*Optimize.c_code)(v1030));
            if (boolean_I_any(v15429) == CTRUE)
             { Call_method1 * v10264 = ((Call_method1 *) GC_OBJECT(Call_method1,new_object_class(Language._Call_method1)));
              update_property(Kernel.arg,
                v10264,
                2,
                Kernel._object,
                v15429);
              (v10264->args = list::alloc(1,v1030));
              add_I_property(Kernel.instances,Language._Call_method1,11,_oid_(v10264));
              Result = _oid_(v10264);
              } 
            else Result = v1030;
              } 
          else Result = Kernel.cfalse;
        } 
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  analyze_I_class(ClaireClass *v15419,OID v9332,list *v1039,list *v3245)
{ GC_RESERVE(15);  // v3.0.55 optim !
  { OID Result = 0;
    { ClaireBoolean * v15161 = ((v15419->open != 4) ? ((boolean_I_any(_oid_(v3245)) != CTRUE) ? ((Optimize.compiler->class2file_ask != CTRUE) ? CTRUE: CFALSE): CFALSE): CFALSE);
      list * v15434;
      { { bag *v_list; OID v_val;
          OID v15440,CLcount;
          v_list = v1039;
           v15434 = v_list->clone(Kernel._any);
          for (CLcount= 1; CLcount <= v_list->length; CLcount++)
          { v15440 = (*(v_list))[CLcount];
            { OID  v15432 = GC_OID((*(OBJECT(Call,v15440)->args))[1]);
              OID  v15441 = GC_OID((*(OBJECT(Call,v15440)->args))[2]);
              ClaireObject * v15435 = GC_OBJECT(ClaireObject,_at_property1(OBJECT(property,v15432),v15419));
              ClaireBoolean * v6094 = (((*Kernel.open)(v15432) == 0) ? ((Kernel._slot == v15435->isa) ? CTRUE: CFALSE): CFALSE);
              GC__ANY(v3245 = v3245->addFast(v15432), 4);
              { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                (v10264->selector = ((v6094 == CTRUE) ?
                  Kernel.put :
                  Core.write ));
                { Call * v1385 = v10264; 
                  list * v1406;
                  { OID v_bag;
                    GC_ANY(v1406= list::empty(Kernel.emptySet));
                    ((list *) v1406)->addFast(v15432);
                    ((list *) v1406)->addFast(v9332);
                    { if ((v6094 != CTRUE) || 
                          (_inf_equal_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(v15441))),GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Kernel.range)(_oid_(v15435))))) == CTRUE))
                       v_bag = v15441;
                      else v_bag = c_check_any(GC_OID((*Optimize.c_code)(v15441,
                          _oid_(Kernel._any))),GC_OID((*Optimize.c_code)(GC_OID((*Kernel.range)(_oid_(v15435))),
                          _oid_(Kernel._type))));
                        GC_OID(v_bag);} 
                    ((list *) v1406)->addFast(v_bag);} 
                  (v1385->args = v1406);} 
                add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
                v_val = _oid_(v10264);
                } 
              } 
            
            (*((list *) v15434))[CLcount] = v_val;} 
          } 
        GC_OBJECT(list,v15434);} 
      if (v15161 == CTRUE)
       { { OID  v11359;
          { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
            (v10264->selector = Kernel.add);
            (v10264->args = list::alloc(3,_oid_(Kernel.instances),
              _oid_(v15419),
              v9332));
            add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
            v11359 = _oid_(v10264);
            } 
          v15434 = v15434->addFast(v11359);
          } 
        GC_OBJECT(list,v15434);} 
      if (Optimize.compiler->class2file_ask != CTRUE)
       { OID gc_local;
        ITERATE(v15435);
        bag *v15435_support;
        v15435_support = GC_OBJECT(list,OBJECT(bag,(*Optimize.get_indexed)(_oid_(v15419))));
        for (START(v15435_support); NEXT(v15435);)
        { GC_LOOP;
          { property * v15432 = OBJECT(restriction,v15435)->selector;
            OID  v15438 = GC_OID(OBJECT(slot,v15435)->DEFAULT);
            { ClaireBoolean * g0342I;
              { ClaireBoolean *v_and;
                { v_and = known_ask_any(v15438);
                  if (v_and == CFALSE) g0342I =CFALSE; 
                  else { { OID  v13281;
                      if (multi_ask_any(_oid_(v15432)) == CTRUE)
                       v13281 = v15438;
                      else v13281 = Kernel.ctrue;
                        v_and = boolean_I_any(v13281);
                      } 
                    if (v_and == CFALSE) g0342I =CFALSE; 
                    else { v_and = not_any(_oid_(v3245->memq(_oid_(v15432))));
                      if (v_and == CFALSE) g0342I =CFALSE; 
                      else { v_and = ((((v15432->inverse == (NULL)) ? CTRUE : CFALSE) != CTRUE) ? CTRUE : ((((v15432->if_write == CNULL) ? CTRUE : CFALSE) != CTRUE) ? CTRUE : (((OBJECT(slot,v15435)->srange != Kernel._object) && 
                            ((OBJECT(slot,v15435)->srange != Kernel._float) && 
                              (inherit_ask_class(OWNER(v15438),Kernel._integer) != CTRUE))) ? CTRUE : CFALSE)));
                        if (v_and == CFALSE) g0342I =CFALSE; 
                        else g0342I = CTRUE;} 
                      } 
                    } 
                  } 
                } 
              
              if (g0342I == CTRUE) { OID  v16128;
                  if (designated_ask_any(v15438) == CTRUE)
                   v16128 = v15438;
                  else { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                      (v10264->selector = Kernel.DEFAULT);
                      { Call * v1411 = v10264; 
                        list * v1412;
                        { OID v_bag;
                          GC_ANY(v1412= list::empty(Kernel.emptySet));
                          { { Cast * v10264 = ((Cast *) GC_OBJECT(Cast,new_object_class(Language._Cast)));
                              { Cast * v1413 = v10264; 
                                OID  v1414;
                                { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                                  (v10264->selector = Core._at);
                                  (v10264->args = list::alloc(2,_oid_(v15432),_oid_(v15419)));
                                  add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
                                  v1414 = _oid_(v10264);
                                  } 
                                (v1413->arg = v1414);} 
                              (v10264->set_arg = Kernel._slot);
                              add_I_property(Kernel.instances,Language._Cast,11,_oid_(v10264));
                              v_bag = _oid_(v10264);
                              } 
                            GC_OID(v_bag);} 
                          ((list *) v1412)->addFast(v_bag);} 
                        (v1411->args = v1412);} 
                      add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
                      v16128 = _oid_(v10264);
                      } 
                    { { OID  v1702;
                      { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                        (v10264->selector = Core.write);
                        (v10264->args = list::alloc(3,_oid_(v15432),
                          v9332,
                          v16128));
                        add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
                        v1702 = _oid_(v10264);
                        } 
                      v15434 = v15434->addFast(v1702);
                      } 
                     GC__ANY(v15434, 7);} 
                  } 
                } 
            } 
          GC_UNLOOP;} 
        } 
      { OID  v15429 = GC_OID(_oid_(_at_property1(Kernel.close,v15419)));
        { OID  v2663;
          if (boolean_I_any(v15429) == CTRUE)
           { Call_method1 * v10264 = ((Call_method1 *) GC_OBJECT(Call_method1,new_object_class(Language._Call_method1)));
            update_property(Kernel.arg,
              v10264,
              2,
              Kernel._object,
              v15429);
            (v10264->args = list::alloc(1,v9332));
            add_I_property(Kernel.instances,Language._Call_method1,11,_oid_(v10264));
            v2663 = _oid_(v10264);
            } 
          else v2663 = v9332;
            v15434 = v15434->addFast(v2663);
          } 
        } 
      Result = _oid_(v15434);
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_Defobj_Optimize(Defobj *v9332,ClaireClass *v15435)
{ GC_BIND;
  { OID Result = 0;
    { ClaireBoolean * v1028 = Optimize.OPT->allocation;
      ClaireClass * v1030 = v9332->arg;
      OID  v15439 = GC_OID(get_symbol(v9332->ident));
      OID  v1049;
      { if ((v15439 != CNULL) && 
            (inherit_ask_class(OWNER(v15439),Core._global_variable) != CTRUE))
         v1049 = v15439;
        else { Variable * v3066;{ Cint  v10304;
              { (Optimize.OPT->max_vars = (Optimize.OPT->max_vars+1));
                v10304 = 0;
                } 
              v3066 = Variable_I_symbol(OBJECT(symbol,Optimize._starname_star->value),v10304,v1030);
              } 
            
            v1049=_oid_(v3066);} 
          GC_OID(v1049);} 
      Call * v16277;
      { { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
          (v10264->selector = Optimize.object_I);
          (v10264->args = list::alloc(2,_oid_(v9332->ident),_oid_(v1030)));
          add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
          v16277 = v10264;
          } 
        GC_OBJECT(Call,v16277);} 
      OID  v16278 = GC_OID(analyze_I_class(v1030,v1049,GC_OBJECT(list,v9332->args),list::alloc(1,_oid_(Kernel.name))));
      OID  v1051;
      if (inherit_ask_class(OWNER(v1049),Language._Variable) != CTRUE)
       { Do * v10264 = ((Do *) GC_OBJECT(Do,new_object_class(Language._Do)));
        store_object(v10264,
          2,
          Kernel._object,
          (*Kernel.cons)(_oid_(v16277),
            v16278),
          CFALSE);
        add_I_property(Kernel.instances,Language._Do,11,_oid_(v10264));
        v1051 = _oid_(v10264);
        } 
      else { Let * v10264 = ((Let *) GC_OBJECT(Let,new_object_class(Language._Let)));
          store_object(v10264,
            2,
            Kernel._object,
            v1049,
            CFALSE);
          (v10264->value = _oid_(v16277));
          { Let * v1441 = v10264; 
            OID  v1442;
            { Do * v10264 = ((Do *) GC_OBJECT(Do,new_object_class(Language._Do)));
              store_object(v10264,
                2,
                Kernel._object,
                v16278,
                CFALSE);
              add_I_property(Kernel.instances,Language._Do,11,_oid_(v10264));
              v1442 = _oid_(v10264);
              } 
            (v1441->arg = v1442);} 
          add_I_property(Kernel.instances,Language._Let,11,_oid_(v10264));
          v1051 = _oid_(v10264);
          } 
        if (v1030->open <= 0)
       close_exception(((general_error *) (*Core._general_error)(_string_(CSTRING("[105] cannot instantiate ~S")),
        _oid_(list::alloc(1,_oid_(v1030))))));
      if (v15439 != CNULL)
       { if (contain_ask_list(Optimize.OPT->objects,v15439) != CTRUE)
         { GC_OBJECT(list,Optimize.OPT->objects)->addFast(v15439);
          (*Optimize.c_register)(v15439);
          } 
        } 
      else { warn_void();
          tformat_string(CSTRING("~S is unknown [265]\n"),2,list::alloc(1,_oid_(v9332->ident)));
          } 
        v1051= GC_OID((*Optimize.c_code)(v1051,
        _oid_(v15435)));
      if (_inf_equal_type(v9332->arg,Kernel._exception) == CTRUE)
       (Optimize.OPT->allocation = v1028);
      Result = v1051;
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_Defclass_Optimize(Defclass *v9332,ClaireClass *v15435)
{ GC_BIND;
  { OID Result = 0;
    { symbol * v12296 = v9332->ident;
      OID  v15439 = GC_OID(get_symbol(v12296));
      Call * v11065;
      { ClaireObject *V_CC ;
        if (v15439 != CNULL)
         { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
          (v10264->selector = Core.class_I);
          (v10264->args = list::alloc(2,_oid_(v12296),_oid_(v9332->arg)));
          add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
          V_CC = v10264;
          } 
        else close_exception(((general_error *) (*Core._general_error)(_string_(CSTRING("[internal] cannot compile unknown class ~S")),
            _oid_(list::alloc(1,_oid_(v12296))))));
          v11065= (Call *) V_CC;} 
      Do * v1051;
      { { Do * v10264 = ((Do *) GC_OBJECT(Do,new_object_class(Language._Do)));
          { Do * v1444 = v10264; 
            list * v1445;
            { list * v16070;
              { { list * v4444;
                  { { bag *v_list; OID v_val;
                      OID v15440,CLcount;
                      v_list = GC_OBJECT(list,v9332->args);
                       v4444 = v_list->clone();
                      for (CLcount= 1; CLcount <= v_list->length; CLcount++)
                      { v15440 = (*(v_list))[CLcount];
                        { OID  v15438 = CNULL;
                          if (INHERIT(OWNER(v15440),Language._Call))
                           { v15438= GC_OID((*(OBJECT(Call,v15440)->args))[2]);
                            v15440= GC_OID((*(OBJECT(Call,v15440)->args))[1]);
                            } 
                          { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                            (v10264->selector = Kernel.add_slot);
                            (v10264->args = list::alloc(5,v15439,
                              _oid_(make_a_property_any(_oid_(OBJECT(Variable,v15440)->pname))),
                              GC_OID((*Kernel.range)(v15440)),
                              v15438,
                              0));
                            add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
                            v_val = _oid_(v10264);
                            } 
                          } 
                        
                        (*((list *) v4444))[CLcount] = v_val;} 
                      } 
                    GC_OBJECT(list,v4444);} 
                  list * v5405;
                  if (v9332->params->length != 0)
                   { OID v_bag;
                    GC_ANY(v5405= list::empty(Kernel.emptySet));
                    { { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                        (v10264->selector = Kernel.put);
                        (v10264->args = list::alloc(3,_oid_(Kernel.params),
                          v15439,
                          GC_OID(_oid_(v9332->params))));
                        add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
                        v_bag = _oid_(v10264);
                        } 
                      GC_OID(v_bag);} 
                    ((list *) v5405)->addFast(v_bag);} 
                  else v5405 = list::empty();
                    v16070 = append_list(v4444,v5405);
                  } 
                GC_OBJECT(list,v16070);} 
              v1445 = cons_any(_oid_(v11065),v16070);
              } 
            (v1444->args = v1445);} 
          add_I_property(Kernel.instances,Language._Do,11,_oid_(v10264));
          v1051 = v10264;
          } 
        GC_OBJECT(Do,v1051);} 
      if (contain_ask_list(Optimize.OPT->objects,v15439) != CTRUE)
       { GC_OBJECT(list,Optimize.OPT->objects)->addFast(v15439);
        (*Optimize.c_register)(v15439);
        } 
      Result = (*Optimize.c_code)(_oid_(v1051),
        _oid_(v15435));
      } 
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_Defmethod_Optimize(Defmethod *v9332)
{ return (Kernel._any);} 

OID  c_code_Defmethod_Optimize(Defmethod *v9332)
{ GC_BIND;
  { OID Result = 0;
    { property * v3376 = v9332->arg->selector;
      list * v15428 = GC_OBJECT(list,v9332->arg->args);
      list * v3250 = (((v15428->length == 1) && 
          ((*(v15428))[1] == _oid_(ClEnv))) ?
        list::alloc(1,GC_OID(_oid_(Variable_I_symbol(OBJECT(symbol,Optimize._starname_star->value),0,Kernel._void)))) :
        v15428 );
      list * v3247 = GC_OBJECT(list,extract_signature_I_list(v3250));
      list * v1914 = GC_OBJECT(list,extract_range_any(GC_OID(v9332->set_arg),v3250,GC_OBJECT(list,OBJECT(list,Language.LDEF->value))));
      OID  v8154;
      { if ((boolean_I_any(v9332->inline_ask) == CTRUE) && 
            (Optimize.compiler->inline_ask == CTRUE))
         { print_in_string_void();
          princ_string(CSTRING("lambda[("));
          ppvariable_list(v3250);
          princ_string(CSTRING("),"));
          print_any(GC_OID(v9332->body));
          princ_string(CSTRING("]"));
          v8154 = _string_(end_of_print_void());
          } 
        else v8154 = Kernel.cfalse;
          GC_OID(v8154);} 
      list * v13286 = GC_OBJECT(list,extract_status_new_any(GC_OID(v9332->body)));
      OID  v12543 = GC_OID((*Core._at)(_oid_(v3376),
        (*(v3247))[2]));
      method * v15429;
      { ClaireObject *V_CC ;
        if (Kernel._method == OBJECT(ClaireObject,v12543)->isa)
         V_CC = OBJECT(method,v12543);
        else close_exception(((general_error *) (*Core._general_error)(_string_(CSTRING("[internal] the method ~S @ ~S is not known")),
            _oid_(list::alloc(2,_oid_(v3376),(*(v3247))[2])))));
          v15429= (method *) V_CC;} 
      OID  v11348 = v15429->status;
      ((*(v13286))[2]=get_property(Kernel.functional,v15429));
      if ((Optimize.compiler->inline_ask != CTRUE) && 
          ((v3376 == Language.Iterate) || 
              (v3376 == Language.iterate)))
       Result = Core.nil->value;
      else if (((*(v1914))[1] == _oid_(Kernel._void)) && 
          (sort_pattern_ask_list(v3250,GC_OID(v9332->body)) == CTRUE))
       Result = sort_code_Defmethod(v9332,v3250);
      else { if ((*(v13286))[3] != _oid_(Kernel.body))
           { char * v3291 = GC_STRING(string_v((*Optimize.function_name)(_oid_(v3376),
              (*(v3247))[2],
              (*(v13286))[2])));
            lambda * v3229 = GC_OBJECT(lambda,lambda_I_list(v3250,(*(v13286))[3]));
            Cint  v8187 = ((Optimize.OPT->recompute == CTRUE) ?
              c_status_any(GC_OID(v3229->body),GC_OBJECT(list,v3229->vars)) :
              status_I_restriction(v15429) );
            compile_lambda_string(v3291,v3229,_oid_(v15429));
            if (((*(v13286))[1] == CNULL) || 
                (Optimize.OPT->recompute == CTRUE))
             { if ((Optimize.OPT->use_nth_equal != CTRUE) && 
                  (BCONTAIN(v8187,2)))
               v8187= (v8187-exp2_integer(2));
              if ((Optimize.OPT->use_update != CTRUE) && 
                  (BCONTAIN(v8187,3)))
               v8187= (v8187-exp2_integer(3));
              if ((Optimize.OPT->use_string_update != CTRUE) && 
                  (BCONTAIN(v8187,7)))
               v8187= (v8187-exp2_integer(7));
              if ((Optimize.OPT->allocation != CTRUE) && 
                  (BCONTAIN(v8187,1)))
               v8187= (v8187-exp2_integer(1));
              ((*(v13286))[1]=v8187);
              } 
            ((*(v13286))[2]=_oid_(make_function_string(v3291)));
            } 
          if (INHERIT(OWNER(v9332->set_arg),Core._global_variable))
           ((*(v1914))[1]=v9332->set_arg);
          else if ((INHERIT(v15429->range->isa,Kernel._class)) && 
              (inherit_ask_class(OWNER((*(v1914))[1]),Kernel._class) != CTRUE))
           ((*(v1914))[1]=_oid_(v15429->range));
          { OID  v1040 = GC_OID(add_method_I_method(v15429,
              OBJECT(list,(*(v3247))[1]),
              (*(v1914))[1],
              (*(v13286))[1],
              OBJECT(ClaireFunction,(*(v13286))[2])));
            { OID  v6366;
              if ((boolean_I_any(v9332->inline_ask) == CTRUE) && 
                  ((Optimize.compiler->inline_ask == CTRUE) && 
                    (Optimize.compiler->diet_ask != CTRUE)))
               { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                (v10264->selector = Core.inlineok_ask);
                (v10264->args = list::alloc(2,v1040,v8154));
                add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
                v6366 = _oid_(v10264);
                } 
              else if ((boolean_I_any((*(v1914))[2]) == CTRUE) && 
                  (Optimize.compiler->diet_ask != CTRUE))
               { char * v3291 = GC_STRING(append_string(GC_STRING(string_v((*Optimize.function_name)(_oid_(v3376),
                  (*(v3247))[2],
                  (*(v13286))[2]))),CSTRING("_type")));
                compile_lambda_string(v3291,OBJECT(lambda,(*(v1914))[2]),_oid_(Kernel._type));
                { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                  (v10264->selector = Core.write);
                  (v10264->args = list::alloc(3,Language.typing->value,
                    v1040,
                    _oid_(make_function_string(v3291))));
                  add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
                  v6366 = _oid_(v10264);
                  } 
                } 
              else v6366 = v1040;
                Result = (*Optimize.c_code)(v6366);
              } 
            } 
          } 
        } 
    GC_UNBIND; return (Result);} 
  } 

ClaireBoolean * sort_pattern_ask_list(list *v3250,OID v12063)
{ GC_BIND;
  { ClaireBoolean *Result ;
    { ClaireBoolean *v_and;
      { v_and = ((v3250->length == 1) ? CTRUE : CFALSE);
        if (v_and == CFALSE) Result =CFALSE; 
        else { if (INHERIT(OWNER(v12063),Language._Call))
           { ClaireBoolean *v_and1;
            { v_and1 = ((OBJECT(Call,v12063)->selector == Core.sort) ? CTRUE : CFALSE);
              if (v_and1 == CFALSE) v_and =CFALSE; 
              else { { OID  v2841 = GC_OID((*(OBJECT(Call,v12063)->args))[1]);
                  v_and1 = ((INHERIT(OWNER(v2841),Language._Call)) ?
                    ((OBJECT(Call,v2841)->selector == Core._at) ? ((INHERIT(OWNER((*(OBJECT(Call,v2841)->args))[1]),Kernel._property)) ? CTRUE: CFALSE): CFALSE) :
                    CFALSE );
                  } 
                if (v_and1 == CFALSE) v_and =CFALSE; 
                else { v_and1 = ((equal(lexical_build_any(GC_OID((*(OBJECT(Call,v12063)->args))[2]),v3250,0),(*(v3250))[1]) == CTRUE) ? CTRUE : CFALSE);
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

OID  sort_code_Defmethod(Defmethod *v9332,list *v3250)
{ GC_BIND;
  { OID Result = 0;
    { OID  v15428 = (*(v3250))[1];
      OID  v15422 = GC_OID((*(OBJECT(bag,(*Core.args)(GC_OID((*(OBJECT(bag,(*Core.args)(GC_OID(v9332->body)))))[1])))))[1]);
      Variable * v15429 = GC_OBJECT(Variable,Variable_I_symbol(symbol_I_string2(CSTRING("m")),0,Kernel._integer));
      Variable * v15431 = GC_OBJECT(Variable,Variable_I_symbol(symbol_I_string2(CSTRING("n")),0,Kernel._integer));
      Variable * v15440 = GC_OBJECT(Variable,Variable_I_symbol(symbol_I_string2(CSTRING("x")),0,GC_OBJECT(ClaireType,member_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Kernel.range)(v15428)))))));
      Variable * v15432 = GC_OBJECT(Variable,Variable_I_symbol(symbol_I_string2(CSTRING("p")),0,Kernel._integer));
      Variable * v9545 = GC_OBJECT(Variable,Variable_I_symbol(symbol_I_string2(CSTRING("q")),0,Kernel._integer));
      Defmethod * v4596;
      { { Defmethod * v10264 = ((Defmethod *) GC_OBJECT(Defmethod,new_object_class(Language._Defmethod)));
          (v10264->arg = v9332->arg);
          (v10264->inline_ask = Kernel.cfalse);
          (v10264->set_arg = v9332->set_arg);
          { Defmethod * v1472 = v10264; 
            OID  v1473;
            { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
              (v10264->selector = v9332->arg->selector);
              { Call * v1474 = v10264; 
                list * v1475;
                { OID v_bag;
                  GC_ANY(v1475= list::empty(Kernel.emptySet));
                  ((list *) v1475)->addFast(1);
                  { { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                      (v10264->selector = Kernel.length);
                      (v10264->args = list::alloc(1,(*(v3250))[1]));
                      add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
                      v_bag = _oid_(v10264);
                      } 
                    GC_OID(v_bag);} 
                  ((list *) v1475)->addFast(v_bag);
                  ((list *) v1475)->addFast(v15428);} 
                (v1474->args = v1475);} 
              add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
              v1473 = _oid_(v10264);
              } 
            (v1472->body = v1473);} 
          add_I_property(Kernel.instances,Language._Defmethod,11,_oid_(v10264));
          v4596 = v10264;
          } 
        GC_OBJECT(Defmethod,v4596);} 
      If * v15615;
      { { If * v10264 = ((If *) GC_OBJECT(If,new_object_class(Language._If)));
          { If * v1476 = v10264; 
            OID  v1477;
            { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
              (v10264->selector = Kernel._sup);
              (v10264->args = list::alloc(2,_oid_(v15429),_oid_(v15431)));
              add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
              v1477 = _oid_(v10264);
              } 
            (v1476->test = v1477);} 
          { If * v1478 = v10264; 
            OID  v1499;
            { Let * v10264 = ((Let *) GC_OBJECT(Let,new_object_class(Language._Let)));
              (v10264->var = v15440);
              { Let * v1500 = v10264; 
                OID  v1501;
                { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                  (v10264->selector = Kernel.nth);
                  (v10264->args = list::alloc(2,v15428,_oid_(v15431)));
                  add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
                  v1501 = _oid_(v10264);
                  } 
                (v1500->value = v1501);} 
              { Let * v1502 = v10264; 
                OID  v1503;
                { If * v10264 = ((If *) GC_OBJECT(If,new_object_class(Language._If)));
                  { If * v1504 = v10264; 
                    OID  v1505;
                    { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                      (v10264->selector = Kernel._equal);
                      { Call * v1506 = v10264; 
                        list * v1507;
                        { OID v_bag;
                          GC_ANY(v1507= list::empty(Kernel.emptySet));
                          ((list *) v1507)->addFast(_oid_(v15429));
                          { { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                              (v10264->selector = Core._plus);
                              (v10264->args = list::alloc(2,_oid_(v15431),1));
                              add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
                              v_bag = _oid_(v10264);
                              } 
                            GC_OID(v_bag);} 
                          ((list *) v1507)->addFast(v_bag);} 
                        (v1506->args = v1507);} 
                      add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
                      v1505 = _oid_(v10264);
                      } 
                    (v1504->test = v1505);} 
                  { If * v1508 = v10264; 
                    OID  v1530;
                    { If * v10264 = ((If *) GC_OBJECT(If,new_object_class(Language._If)));
                      { If * v1531 = v10264; 
                        OID  v1532;
                        { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                          update_property(Kernel.selector,
                            v10264,
                            2,
                            Kernel._object,
                            v15422);
                          { Call * v1533 = v10264; 
                            list * v1534;
                            { OID v_bag;
                              GC_ANY(v1534= list::empty(Kernel.emptySet));
                              { { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                                  (v10264->selector = Kernel.nth);
                                  (v10264->args = list::alloc(2,v15428,_oid_(v15429)));
                                  add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
                                  v_bag = _oid_(v10264);
                                  } 
                                GC_OID(v_bag);} 
                              ((list *) v1534)->addFast(v_bag);
                              ((list *) v1534)->addFast(_oid_(v15440));} 
                            (v1533->args = v1534);} 
                          add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
                          v1532 = _oid_(v10264);
                          } 
                        (v1531->test = v1532);} 
                      { If * v1535 = v10264; 
                        OID  v1536;
                        { Do * v10264 = ((Do *) GC_OBJECT(Do,new_object_class(Language._Do)));
                          { Do * v1537 = v10264; 
                            list * v1538;
                            { OID v_bag;
                              GC_ANY(v1538= list::empty(Kernel.emptySet));
                              { { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                                  (v10264->selector = Kernel.nth_equal);
                                  { Call * v1539 = v10264; 
                                    list * v1561;
                                    { OID v_bag;
                                      GC_ANY(v1561= list::empty(Kernel.emptySet));
                                      ((list *) v1561)->addFast(v15428);
                                      ((list *) v1561)->addFast(_oid_(v15431));
                                      { { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                                          (v10264->selector = Kernel.nth);
                                          (v10264->args = list::alloc(2,v15428,_oid_(v15429)));
                                          add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
                                          v_bag = _oid_(v10264);
                                          } 
                                        GC_OID(v_bag);} 
                                      ((list *) v1561)->addFast(v_bag);} 
                                    (v1539->args = v1561);} 
                                  add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
                                  v_bag = _oid_(v10264);
                                  } 
                                GC_OID(v_bag);} 
                              ((list *) v1538)->addFast(v_bag);
                              { { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                                  (v10264->selector = Kernel.nth_equal);
                                  (v10264->args = list::alloc(3,v15428,
                                    _oid_(v15429),
                                    _oid_(v15440)));
                                  add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
                                  v_bag = _oid_(v10264);
                                  } 
                                GC_OID(v_bag);} 
                              ((list *) v1538)->addFast(v_bag);} 
                            (v1537->args = v1538);} 
                          add_I_property(Kernel.instances,Language._Do,11,_oid_(v10264));
                          v1536 = _oid_(v10264);
                          } 
                        (v1535->arg = v1536);} 
                      add_I_property(Kernel.instances,Language._If,11,_oid_(v10264));
                      (v10264->other = Kernel.cfalse);
                      v1530 = _oid_(v10264);
                      } 
                    (v1508->arg = v1530);} 
                  { If * v1562 = v10264; 
                    OID  v1563;
                    { Let * v10264 = ((Let *) GC_OBJECT(Let,new_object_class(Language._Let)));
                      (v10264->var = v15432);
                      { Let * v1564 = v10264; 
                        OID  v1565;
                        { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                          (v10264->selector = Core._sup_sup);
                          { Call * v1566 = v10264; 
                            list * v1567;
                            { OID v_bag;
                              GC_ANY(v1567= list::empty(Kernel.emptySet));
                              { { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                                  (v10264->selector = Core._plus);
                                  (v10264->args = list::alloc(2,_oid_(v15431),_oid_(v15429)));
                                  add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
                                  v_bag = _oid_(v10264);
                                  } 
                                GC_OID(v_bag);} 
                              ((list *) v1567)->addFast(v_bag);
                              ((list *) v1567)->addFast(1);} 
                            (v1566->args = v1567);} 
                          add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
                          v1565 = _oid_(v10264);
                          } 
                        (v1564->value = v1565);} 
                      { Let * v1568 = v10264; 
                        OID  v1569;
                        { Let * v10264 = ((Let *) GC_OBJECT(Let,new_object_class(Language._Let)));
                          (v10264->var = v9545);
                          (v10264->value = _oid_(v15431));
                          { Let * v1570 = v10264; 
                            OID  v2243;
                            { Do * v10264 = ((Do *) GC_OBJECT(Do,new_object_class(Language._Do)));
                              { Do * v2246 = v10264; 
                                list * v2247;
                                { OID v_bag;
                                  GC_ANY(v2247= list::empty(Kernel.emptySet));
                                  { { Assign * v10264 = ((Assign *) GC_OBJECT(Assign,new_object_class(Language._Assign)));
                                      (v10264->var = _oid_(v15440));
                                      { Assign * v2248 = v10264; 
                                        OID  v2249;
                                        { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                                          (v10264->selector = Kernel.nth);
                                          (v10264->args = list::alloc(2,v15428,_oid_(v15432)));
                                          add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
                                          v2249 = _oid_(v10264);
                                          } 
                                        (v2248->arg = v2249);} 
                                      add_I_property(Kernel.instances,Language._Assign,11,_oid_(v10264));
                                      v_bag = _oid_(v10264);
                                      } 
                                    GC_OID(v_bag);} 
                                  ((list *) v2247)->addFast(v_bag);
                                  { { If * v10264 = ((If *) GC_OBJECT(If,new_object_class(Language._If)));
                                      { If * v2250 = v10264; 
                                        OID  v2251;
                                        { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                                          (v10264->selector = Core._I_equal);
                                          (v10264->args = list::alloc(2,_oid_(v15432),_oid_(v15431)));
                                          add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
                                          v2251 = _oid_(v10264);
                                          } 
                                        (v2250->test = v2251);} 
                                      { If * v2252 = v10264; 
                                        OID  v2253;
                                        { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                                          (v10264->selector = Kernel.nth_equal);
                                          { Call * v2255 = v10264; 
                                            list * v2274;
                                            { OID v_bag;
                                              GC_ANY(v2274= list::empty(Kernel.emptySet));
                                              ((list *) v2274)->addFast(v15428);
                                              ((list *) v2274)->addFast(_oid_(v15432));
                                              { { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                                                  (v10264->selector = Kernel.nth);
                                                  (v10264->args = list::alloc(2,v15428,_oid_(v15431)));
                                                  add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
                                                  v_bag = _oid_(v10264);
                                                  } 
                                                GC_OID(v_bag);} 
                                              ((list *) v2274)->addFast(v_bag);} 
                                            (v2255->args = v2274);} 
                                          add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
                                          v2253 = _oid_(v10264);
                                          } 
                                        (v2252->arg = v2253);} 
                                      add_I_property(Kernel.instances,Language._If,11,_oid_(v10264));
                                      (v10264->other = Kernel.cfalse);
                                      v_bag = _oid_(v10264);
                                      } 
                                    GC_OID(v_bag);} 
                                  ((list *) v2247)->addFast(v_bag);
                                  { { For * v10264 = ((For *) GC_OBJECT(For,new_object_class(Language._For)));
                                      (v10264->var = v15432);
                                      { Iteration * v2275 = v10264; 
                                        OID  v2276;
                                        { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                                          (v10264->selector = Kernel._dot_dot);
                                          { Call * v2277 = v10264; 
                                            list * v2278;
                                            { OID v_bag;
                                              GC_ANY(v2278= list::empty(Kernel.emptySet));
                                              { { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                                                  (v10264->selector = Core._plus);
                                                  (v10264->args = list::alloc(2,_oid_(v15431),1));
                                                  add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
                                                  v_bag = _oid_(v10264);
                                                  } 
                                                GC_OID(v_bag);} 
                                              ((list *) v2278)->addFast(v_bag);
                                              ((list *) v2278)->addFast(_oid_(v15429));} 
                                            (v2277->args = v2278);} 
                                          add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
                                          v2276 = _oid_(v10264);
                                          } 
                                        (v2275->set_arg = v2276);} 
                                      { Iteration * v2279 = v10264; 
                                        OID  v2280;
                                        { If * v10264 = ((If *) GC_OBJECT(If,new_object_class(Language._If)));
                                          { If * v2281 = v10264; 
                                            OID  v2282;
                                            { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                                              update_property(Kernel.selector,
                                                v10264,
                                                2,
                                                Kernel._object,
                                                v15422);
                                              { Call * v2283 = v10264; 
                                                list * v2305;
                                                { OID v_bag;
                                                  GC_ANY(v2305= list::empty(Kernel.emptySet));
                                                  { { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                                                      (v10264->selector = Kernel.nth);
                                                      (v10264->args = list::alloc(2,v15428,_oid_(v15432)));
                                                      add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
                                                      v_bag = _oid_(v10264);
                                                      } 
                                                    GC_OID(v_bag);} 
                                                  ((list *) v2305)->addFast(v_bag);
                                                  ((list *) v2305)->addFast(_oid_(v15440));} 
                                                (v2283->args = v2305);} 
                                              add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
                                              v2282 = _oid_(v10264);
                                              } 
                                            (v2281->test = v2282);} 
                                          { If * v2306 = v10264; 
                                            OID  v2308;
                                            { Do * v10264 = ((Do *) GC_OBJECT(Do,new_object_class(Language._Do)));
                                              { Do * v2309 = v10264; 
                                                list * v2310;
                                                { OID v_bag;
                                                  GC_ANY(v2310= list::empty(Kernel.emptySet));
                                                  { { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                                                      (v10264->selector = Kernel.nth_equal);
                                                      { Call * v2312 = v10264; 
                                                        list * v2313;
                                                        { OID v_bag;
                                                          GC_ANY(v2313= list::empty(Kernel.emptySet));
                                                          ((list *) v2313)->addFast(v15428);
                                                          ((list *) v2313)->addFast(_oid_(v15431));
                                                          { { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                                                              (v10264->selector = Kernel.nth);
                                                              (v10264->args = list::alloc(2,v15428,_oid_(v15432)));
                                                              add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
                                                              v_bag = _oid_(v10264);
                                                              } 
                                                            GC_OID(v_bag);} 
                                                          ((list *) v2313)->addFast(v_bag);} 
                                                        (v2312->args = v2313);} 
                                                      add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
                                                      v_bag = _oid_(v10264);
                                                      } 
                                                    GC_OID(v_bag);} 
                                                  ((list *) v2310)->addFast(v_bag);
                                                  { { Assign * v10264 = ((Assign *) GC_OBJECT(Assign,new_object_class(Language._Assign)));
                                                      (v10264->var = _oid_(v15431));
                                                      { Assign * v2314 = v10264; 
                                                        OID  v2315;
                                                        { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                                                          (v10264->selector = Core._plus);
                                                          (v10264->args = list::alloc(2,_oid_(v15431),1));
                                                          add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
                                                          v2315 = _oid_(v10264);
                                                          } 
                                                        (v2314->arg = v2315);} 
                                                      add_I_property(Kernel.instances,Language._Assign,11,_oid_(v10264));
                                                      v_bag = _oid_(v10264);
                                                      } 
                                                    GC_OID(v_bag);} 
                                                  ((list *) v2310)->addFast(v_bag);
                                                  { { If * v10264 = ((If *) GC_OBJECT(If,new_object_class(Language._If)));
                                                      { If * v2316 = v10264; 
                                                        OID  v2336;
                                                        { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                                                          (v10264->selector = Kernel._sup);
                                                          (v10264->args = list::alloc(2,_oid_(v15432),_oid_(v15431)));
                                                          add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
                                                          v2336 = _oid_(v10264);
                                                          } 
                                                        (v2316->test = v2336);} 
                                                      { If * v2337 = v10264; 
                                                        OID  v2338;
                                                        { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                                                          (v10264->selector = Kernel.nth_equal);
                                                          { Call * v2339 = v10264; 
                                                            list * v2340;
                                                            { OID v_bag;
                                                              GC_ANY(v2340= list::empty(Kernel.emptySet));
                                                              ((list *) v2340)->addFast(v15428);
                                                              ((list *) v2340)->addFast(_oid_(v15432));
                                                              { { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                                                                  (v10264->selector = Kernel.nth);
                                                                  (v10264->args = list::alloc(2,v15428,_oid_(v15431)));
                                                                  add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
                                                                  v_bag = _oid_(v10264);
                                                                  } 
                                                                GC_OID(v_bag);} 
                                                              ((list *) v2340)->addFast(v_bag);} 
                                                            (v2339->args = v2340);} 
                                                          add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
                                                          v2338 = _oid_(v10264);
                                                          } 
                                                        (v2337->arg = v2338);} 
                                                      add_I_property(Kernel.instances,Language._If,11,_oid_(v10264));
                                                      (v10264->other = Kernel.cfalse);
                                                      v_bag = _oid_(v10264);
                                                      } 
                                                    GC_OID(v_bag);} 
                                                  ((list *) v2310)->addFast(v_bag);} 
                                                (v2309->args = v2310);} 
                                              add_I_property(Kernel.instances,Language._Do,11,_oid_(v10264));
                                              v2308 = _oid_(v10264);
                                              } 
                                            (v2306->arg = v2308);} 
                                          add_I_property(Kernel.instances,Language._If,11,_oid_(v10264));
                                          (v10264->other = Kernel.cfalse);
                                          v2280 = _oid_(v10264);
                                          } 
                                        (v2279->arg = v2280);} 
                                      add_I_property(Kernel.instances,Language._For,11,_oid_(v10264));
                                      v_bag = _oid_(v10264);
                                      } 
                                    GC_OID(v_bag);} 
                                  ((list *) v2247)->addFast(v_bag);
                                  { { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                                      (v10264->selector = Kernel.nth_equal);
                                      (v10264->args = list::alloc(3,v15428,
                                        _oid_(v15431),
                                        _oid_(v15440)));
                                      add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
                                      v_bag = _oid_(v10264);
                                      } 
                                    GC_OID(v_bag);} 
                                  ((list *) v2247)->addFast(v_bag);
                                  { { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                                      (v10264->selector = v9332->arg->selector);
                                      { Call * v2341 = v10264; 
                                        list * v2342;
                                        { OID v_bag;
                                          GC_ANY(v2342= list::empty(Kernel.emptySet));
                                          ((list *) v2342)->addFast(_oid_(v9545));
                                          { { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                                              (v10264->selector = Kernel._dash);
                                              (v10264->args = list::alloc(2,_oid_(v15431),1));
                                              add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
                                              v_bag = _oid_(v10264);
                                              } 
                                            GC_OID(v_bag);} 
                                          ((list *) v2342)->addFast(v_bag);
                                          ((list *) v2342)->addFast(v15428);} 
                                        (v2341->args = v2342);} 
                                      add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
                                      v_bag = _oid_(v10264);
                                      } 
                                    GC_OID(v_bag);} 
                                  ((list *) v2247)->addFast(v_bag);
                                  { { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                                      (v10264->selector = v9332->arg->selector);
                                      { Call * v2343 = v10264; 
                                        list * v2344;
                                        { OID v_bag;
                                          GC_ANY(v2344= list::empty(Kernel.emptySet));
                                          { { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                                              (v10264->selector = Core._plus);
                                              (v10264->args = list::alloc(2,_oid_(v15431),1));
                                              add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
                                              v_bag = _oid_(v10264);
                                              } 
                                            GC_OID(v_bag);} 
                                          ((list *) v2344)->addFast(v_bag);
                                          ((list *) v2344)->addFast(_oid_(v15429));
                                          ((list *) v2344)->addFast(v15428);} 
                                        (v2343->args = v2344);} 
                                      add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
                                      v_bag = _oid_(v10264);
                                      } 
                                    GC_OID(v_bag);} 
                                  ((list *) v2247)->addFast(v_bag);} 
                                (v2246->args = v2247);} 
                              add_I_property(Kernel.instances,Language._Do,11,_oid_(v10264));
                              v2243 = _oid_(v10264);
                              } 
                            (v1570->arg = v2243);} 
                          add_I_property(Kernel.instances,Language._Let,11,_oid_(v10264));
                          v1569 = _oid_(v10264);
                          } 
                        (v1568->arg = v1569);} 
                      add_I_property(Kernel.instances,Language._Let,11,_oid_(v10264));
                      v1563 = _oid_(v10264);
                      } 
                    (v1562->other = v1563);} 
                  add_I_property(Kernel.instances,Language._If,11,_oid_(v10264));
                  v1503 = _oid_(v10264);
                  } 
                (v1502->arg = v1503);} 
              add_I_property(Kernel.instances,Language._Let,11,_oid_(v10264));
              v1499 = _oid_(v10264);
              } 
            (v1478->arg = v1499);} 
          add_I_property(Kernel.instances,Language._If,11,_oid_(v10264));
          (v10264->other = Kernel.cfalse);
          v15615 = v10264;
          } 
        GC_OBJECT(If,v15615);} 
      Defmethod * v4597;
      { { Defmethod * v10264 = ((Defmethod *) GC_OBJECT(Defmethod,new_object_class(Language._Defmethod)));
          { Defmethod * v2345 = v10264; 
            Call * v2367;
            { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
              (v10264->selector = v9332->arg->selector);
              (v10264->args = list::alloc(3,_oid_(v15431),
                _oid_(v15429),
                v15428));
              add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
              v2367 = v10264;
              } 
            (v2345->arg = v2367);} 
          (v10264->inline_ask = Kernel.cfalse);
          (v10264->set_arg = v9332->set_arg);
          (v10264->body = _oid_(v15615));
          add_I_property(Kernel.instances,Language._Defmethod,11,_oid_(v10264));
          v4597 = v10264;
          } 
        GC_OBJECT(Defmethod,v4597);} 
      tformat_string(CSTRING("---- note: quick sort optimisation for ~S ---- \n"),2,list::alloc(1,_oid_(v9332->arg->selector)));
      OPT_EVAL(_oid_(v4597));
      { Do * v10264 = ((Do *) GC_OBJECT(Do,new_object_class(Language._Do)));
        (v10264->args = list::alloc(2,GC_OID((*Optimize.c_code)(_oid_(v4596))),GC_OID((*Optimize.c_code)(_oid_(v4597)))));
        add_I_property(Kernel.instances,Language._Do,11,_oid_(v10264));
        Result = _oid_(v10264);
        } 
      } 
    GC_UNBIND; return (Result);} 
  } 

method * add_method_property2(property *v15432,list *v3247,ClaireType *v3421,Cint v3465,ClaireFunction *v2995,ClaireFunction *v2996)
{ return (add_method_property(v15432,
    v3247,
    v3421,
    v3465,
    _oid_(v2995)));} 

OID  add_method_I_method(method *v15429,list *v3247,OID v3421,OID v4732,ClaireFunction *v3063)
{ GC_BIND;
  { OID Result = 0;
    { Call_method * v1030;
      { { Call_method * v10264 = ((Call_method *) GC_OBJECT(Call_method,new_object_class(Language._Call_method)));
          (v10264->arg = ((method *) _at_property1(Kernel.add_method,Kernel._property)));
          (v10264->args = list::alloc(5,GC_OID((*Optimize.c_code)(_oid_(v15429->selector),
              _oid_(Kernel._property))),
            GC_OID((*Optimize.c_code)(_oid_(v3247),
              _oid_(Kernel._list))),
            GC_OID((*Optimize.c_code)(v3421,
              _oid_(Kernel._type))),
            v4732,
            _oid_(v3063)));
          add_I_property(Kernel.instances,Language._Call_method,11,_oid_(v10264));
          v1030 = v10264;
          } 
        GC_OBJECT(Call_method,v1030);} 
      if ((v15429->range == Kernel._float) || 
          ((v15429->domain->memq(_oid_(Kernel._float)) == CTRUE) || 
            (INHERIT(v15429->range->isa,Kernel._tuple))))
       GC_OBJECT(list,v1030->args)->addFast(_oid_(make_function_string(append_string(GC_STRING(string_I_function(v3063)),CSTRING("_")))));
      Result = _oid_(v1030);
      } 
    GC_UNBIND; return (Result);} 
  } 

list * extract_status_new_any(OID v15440)
{ GC_BIND;
  { list *Result ;
    { OID  v15435 = CNULL;
      OID  v15422;
      if ((INHERIT(OWNER(v15440),Language._Call)) && (OBJECT(Call,v15440)->selector == Language.function_I))
       v15422 = v15440;
      else v15422 = CNULL;
        if (INHERIT(OWNER(v15440),Language._And))
       { OID  v15441 = (*(OBJECT(And,v15440)->args))[1];
        if ((INHERIT(OWNER(v15441),Language._Call)) && (OBJECT(Call,v15441)->selector == Language.function_I))
         { v15422= v15441;
          v15440= (*(OBJECT(And,v15440)->args))[2];
          } 
        } 
      else if (INHERIT(OWNER(v15440),Language._Call))
       { if (OBJECT(Call,v15440)->selector == Language.function_I)
         v15440= _oid_(Kernel.body);
        } 
      if (v15422 != CNULL)
       { v15440= _oid_(Kernel.body);
        if (length_bag(OBJECT(bag,(*Core.args)(v15422))) > 1)
         { ClaireHandler c_handle = ClaireHandler();
          if ERROR_IN 
          { { Cint  v3996;{ set * v2914;
                { set * v14614 = set::empty(Kernel.emptySet);
                  { OID gc_local;
                    ITERATE(v15437);
                    bag *v15437_support;
                    v15437_support = GC_OBJECT(list,cdr_list(GC_OBJECT(list,OBJECT(list,(*Core.args)(v15422)))));
                    for (START(v15437_support); NEXT(v15437);)
                    { GC_LOOP;
                      v14614->addFast(GC_OID(OPT_EVAL(v15437)));
                      GC_UNLOOP;} 
                    } 
                  v2914 = GC_OBJECT(set,v14614);
                  } 
                v3996 = integer_I_set(v2914);
                } 
              
              v15435=v3996;} 
            ClEnv->cHandle--;} 
          else if (belong_to(_oid_(ClEnv->exception_I),_oid_(Kernel._any)) == CTRUE)
          { c_handle.catchIt();{ warn_void();
              (Optimize.SHIT->value= _oid_(cdr_list(GC_OBJECT(list,OBJECT(list,(*Core.args)(v15422))))));
              tformat_string(CSTRING("wrong status ~S -> ~S [266]\n"),2,GC_OBJECT(list,list::alloc(2,v15422,_oid_(set_I_bag(cdr_list(GC_OBJECT(list,OBJECT(list,(*Core.args)(v15422)))))))));
              v15435= 0;
              } 
            } 
          else PREVIOUS_HANDLER;} 
        else v15435= 0;
          v15422= _oid_(make_function_string(string_I_symbol(extract_symbol_any((*(OBJECT(bag,(*Core.args)(v15422))))[1]))));
        } 
      Result = list::alloc(3,v15435,
        v15422,
        v15440);
      } 
    GC_UNBIND; return (Result);} 
  } 

list * extract_signature_I_list(list *v15428)
{ GC_BIND;
  (Language.LDEF->value= _oid_(list::empty(Kernel._any)));
  { list *Result ;
    { Cint  v15431 = 0;
      list * v3181 = list::empty(Kernel._type);
      list * v3182;
      { { bag *v_list; OID v_val;
          OID v15438,CLcount;
          v_list = v15428;
           v3182 = v_list->clone(Kernel._any);
          for (CLcount= 1; CLcount <= v_list->length; CLcount++)
          { v15438 = (*(v_list))[CLcount];
            { OID  v15432 = GC_OID(extract_pattern_any(GC_OID(_oid_(OBJECT(Variable,v15438)->range)),list::alloc(1,v15431)));
              ++v15431;
              { { OID  v3875;
                  { if (INHERIT(OBJECT(Variable,v15438)->range->isa,Core._global_variable))
                     v3875 = _oid_(OBJECT(Variable,v15438)->range);
                    else v3875 = v15432;
                      GC_OID(v3875);} 
                  v3181 = v3181->addFast(v3875);
                  } 
                GC_OBJECT(list,v3181);} 
              (OBJECT(Variable,v15438)->range = type_I_any(v15432));
              v_val = v15432;
              } 
            
            (*((list *) v3182))[CLcount] = v_val;} 
          } 
        GC_OBJECT(list,v3182);} 
      Result = list::alloc(2,_oid_(v3181),_oid_(v3182));
      } 
    GC_UNBIND; return (Result);} 
  } 

ClaireBoolean * _equalsig_ask_list(list *v15440,list *v15441)
{ return (((tmatch_ask_list(v15440,v15441) == CTRUE) ? ((tmatch_ask_list(v15441,v15440) == CTRUE) ? CTRUE: CFALSE): CFALSE));} 

char * function_name_property_Optimize(property *v15432,list *v15428,OID v15440)
{ GC_BIND;
  { char *Result ;
    if (INHERIT(OWNER(v15440),Kernel._function))
     Result = string_I_function(OBJECT(ClaireFunction,v15440));
    else { Cint  v15431 = 0;
        Cint  v15429 = 0;
        module * v3263 = v15432->name->module_I;
        ClaireClass * v15419 = class_I_type(OBJECT(ClaireType,(*(v15428))[1]));
        char * v15434 = GC_STRING(append_string(GC_STRING(append_string(GC_STRING(string_I_symbol(v15432->name)),CSTRING("_"))),GC_STRING(string_I_symbol(v15419->name))));
        if ((Optimize.compiler->naming == 0) && 
            (v15432 != Core.main))
         v15434= GC_STRING(append_string(GC_STRING(append_string(GC_STRING(string_I_symbol(v3263->name)),CSTRING("_"))),v15434));
        { ITERATE(v15434);
          for (START(v15432->restrictions); NEXT(v15434);)
          { if (v15419 == domain_I_restriction(OBJECT(restriction,v15434)))
             ++v15431;
            if (_equalsig_ask_list(v15428,OBJECT(restriction,v15434)->domain) == CTRUE)
             v15429= v15431;
            } 
          } 
        v15434= GC_STRING(((v15431 <= 1) ?
          v15434 :
          append_string(v15434,GC_STRING(string_I_integer (v15429))) ));
        Result = (((stable_ask_relation(v15432) == CTRUE) || 
            (v15432 == Core.main)) ?
          v15434 :
          append_string(GC_STRING(append_string(v15434,CSTRING("_"))),GC_STRING(string_I_symbol(ClEnv->module_I->name))) );
        } 
      GC_UNBIND; return (Result);} 
  } 

OID  compile_lambda_string(char *v9332,lambda *v15428,OID v15429)
{ { OID Result = 0;
    { Cint  v15440 = Optimize.compiler->safety;
      lambda * v15441 = v15428;
      if (Kernel._method == OWNER(v15429))
       (Optimize.OPT->in_method = v15429);
      (Optimize.OPT->protection = CFALSE);
      (Optimize.OPT->allocation = CFALSE);
      if (Optimize.OPT->loop_index > 0)
       (Optimize.OPT->loop_index = 0);
      (Optimize.OPT->loop_gc = CFALSE);
      (Optimize.OPT->use_update = CFALSE);
      (Optimize.OPT->use_nth_equal = CFALSE);
      (Optimize.OPT->use_string_update = CFALSE);
      (Optimize.OPT->max_vars = 0);
      if (contain_ask_list(Optimize.OPT->unsure,v15429) == CTRUE)
       (Optimize.compiler->safety = 1);
      (*Optimize.make_c_function)(_oid_(v15428),
        _string_(v9332),
        v15429);
      (Optimize.OPT->in_method = CNULL);
      (Optimize.compiler->safety = v15440);
      Result = Kernel.ctrue;
      } 
    return (Result);} 
  } 

OID  c_code_Defarray_Optimize(Defarray *v9332)
{ GC_BIND;
  { OID Result = 0;
    { list * v15417 = GC_OBJECT(list,v9332->arg->args);
      OID  v1028 = GC_OID(get_symbol(extract_symbol_any((*(v15417))[1])));
      table * v1049;
      { ClaireObject *V_CC ;
        if (INHERIT(OWNER(v1028),Kernel._table))
         V_CC = OBJECT(table,v1028);
        else close_exception(((general_error *) (*Core._general_error)(_string_(CSTRING("[internal] the table ~S is unknown")),
            _oid_(list::alloc(1,(*(v15417))[1])))));
          v1049= (table *) V_CC;} 
      OID  v15435 = GC_OID((*Kernel.domain)(v1028));
      OID  v15421;
      { { list * v15428 = GC_OBJECT(list,cdr_list(v15417));
          OID  v15418 = GC_OID(lexical_build_any(GC_OID(v9332->body),v15428,0));
          { ClaireBoolean * g0446I;
            { OID  v6758;
              { ITERATE(v3539);
                v6758= Kernel.cfalse;
                for (START(v15428); NEXT(v3539);)
                if (occurrence_any(v15418,OBJECT(Variable,v3539)) > 0)
                 { v6758 = Kernel.ctrue;
                  break;} 
                } 
              g0446I = boolean_I_any(v6758);
              } 
            
            if (g0446I == CTRUE) v15421 = _oid_(lambda_I_list(v15428,v15418));
              else v15421 = v9332->body;
            } 
          } 
        GC_OID(v15421);} 
      OID  v15420;
      { if (INHERIT(OWNER(v15421),Core._lambda))
         v15420 = CNULL;
        else v15420 = v9332->body;
          GC_OID(v15420);} 
      list * v15879;
      if (boolean_I_any(_oid_(OBJECT(ClaireRelation,v1028)->multivalued_ask)) == CTRUE)
       { OID v_bag;
        GC_ANY(v15879= list::empty(Kernel._any));
        { { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
            (v10264->selector = Kernel.put);
            (v10264->args = list::alloc(3,_oid_(Kernel.multivalued_ask),
              _oid_(v1049),
              GC_OID(_oid_(OBJECT(ClaireRelation,v1028)->multivalued_ask))));
            add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
            v_bag = _oid_(v10264);
            } 
          GC_OID(v_bag);} 
        ((list *) v15879)->addFast(v_bag);} 
      else v15879 = list::empty(Kernel._any);
        list * v15875;
      { OID v_bag;
        GC_ANY(v15875= list::empty(Kernel._any));
        { { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
            (v10264->selector = Kernel.put);
            (v10264->args = list::alloc(3,_oid_(Kernel.range),
              _oid_(v1049),
              GC_OID((*Kernel.range)(v1028))));
            add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
            v_bag = _oid_(v10264);
            } 
          GC_OID(v_bag);} 
        ((list *) v15875)->addFast(v_bag);
        { { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
            (v10264->selector = Kernel.put);
            (v10264->args = list::alloc(3,_oid_(Kernel.params),
              _oid_(v1049),
              GC_OID((*Kernel.params)(v1028))));
            add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
            v_bag = _oid_(v10264);
            } 
          GC_OID(v_bag);} 
        ((list *) v15875)->addFast(v_bag);
        { { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
            (v10264->selector = Kernel.put);
            (v10264->args = list::alloc(3,_oid_(Kernel.domain),
              _oid_(v1049),
              v15435));
            add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
            v_bag = _oid_(v10264);
            } 
          GC_OID(v_bag);} 
        ((list *) v15875)->addFast(v_bag);} 
      (OBJECT(Variable,(*(v15417))[2])->range = extract_type_any(GC_OID(_oid_(OBJECT(Variable,(*(v15417))[2])->range))));
      if (v15417->length == 2)
       { { { OID  v7719;
            { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
              (v10264->selector = Kernel.put);
              { Call * v2377 = v10264; 
                list * v2398;
                { OID v_bag;
                  GC_ANY(v2398= list::empty(Kernel.emptySet));
                  ((list *) v2398)->addFast(_oid_(Kernel.graph));
                  ((list *) v2398)->addFast(_oid_(v1049));
                  if (INHERIT(OBJECT(ClaireObject,v15435)->isa,Core._Interval))
                   { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                    (v10264->selector = Core.make_copy_list);
                    (v10264->args = list::alloc(2,size_Interval(OBJECT(Interval,v15435)),v15420));
                    add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
                    v_bag = _oid_(v10264);
                    } 
                  else { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                      (v10264->selector = Kernel.make_list);
                      (v10264->args = list::alloc(2,29,CNULL));
                      add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
                      v_bag = _oid_(v10264);
                      } 
                    ((list *) v2398)->addFast(v_bag);} 
                (v2377->args = v2398);} 
              add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
              v7719 = _oid_(v10264);
              } 
            v15875 = v15875->addFast(v7719);
            } 
          GC_OBJECT(list,v15875);} 
        { { OID  v14399;
            if (INHERIT(OWNER(v15421),Core._lambda))
             { For * v10264 = ((For *) GC_OBJECT(For,new_object_class(Language._For)));
              store_object(v10264,
                2,
                Kernel._object,
                (*(v15417))[2],
                CFALSE);
              (v10264->set_arg = v15435);
              { Iteration * v2400 = v10264; 
                OID  v2401;
                { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                  (v10264->selector = Kernel.nth_equal);
                  (v10264->args = list::alloc(3,_oid_(v1049),
                    (*(v15417))[2],
                    GC_OID(OBJECT(lambda,v15421)->body)));
                  add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
                  v2401 = _oid_(v10264);
                  } 
                (v2400->arg = v2401);} 
              add_I_property(Kernel.instances,Language._For,11,_oid_(v10264));
              v14399 = _oid_(v10264);
              } 
            else { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                (v10264->selector = Kernel.put);
                (v10264->args = list::alloc(3,_oid_(Kernel.DEFAULT),
                  _oid_(v1049),
                  v15420));
                add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
                v14399 = _oid_(v10264);
                } 
              v15875 = v15875->addFast(v14399);
            } 
          GC_OBJECT(list,v15875);} 
        } 
      else { ClaireType * v3399 = GC_OBJECT(ClaireType,extract_type_any(GC_OID(_oid_(OBJECT(Variable,(*(v15417))[3])->range))));
          (OBJECT(Variable,(*(v15417))[3])->range = v3399);
          { { OID  v898;
              { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                (v10264->selector = Kernel.put);
                { Call * v2403 = v10264; 
                  list * v2404;
                  { OID v_bag;
                    GC_ANY(v2404= list::empty(Kernel.emptySet));
                    ((list *) v2404)->addFast(_oid_(Kernel.graph));
                    ((list *) v2404)->addFast(_oid_(v1049));
                    { { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                        (v10264->selector = Core.make_copy_list);
                        { Call * v2405 = v10264; 
                          list * v2406;
                          { OID v_bag;
                            GC_ANY(v2406= list::empty(Kernel.emptySet));
                            ((list *) v2406)->addFast(OBJECT(table,v1028)->graph->length);
                            { if ((*Kernel.params)(v1028) == _oid_(Kernel._any))
                               v_bag = CNULL;
                              else v_bag = (*Kernel.DEFAULT)(v1028);
                                GC_OID(v_bag);} 
                            ((list *) v2406)->addFast(v_bag);} 
                          (v2405->args = v2406);} 
                        add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
                        v_bag = _oid_(v10264);
                        } 
                      GC_OID(v_bag);} 
                    ((list *) v2404)->addFast(v_bag);} 
                  (v2403->args = v2404);} 
                add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
                v898 = _oid_(v10264);
                } 
              v15875 = v15875->addFast(v898);
              } 
            GC_OBJECT(list,v15875);} 
          { { OID  v5703;
              if (INHERIT(OWNER(v15421),Core._lambda))
               { For * v10264 = ((For *) GC_OBJECT(For,new_object_class(Language._For)));
                store_object(v10264,
                  2,
                  Kernel._object,
                  (*(v15417))[2],
                  CFALSE);
                (v10264->set_arg = (*(OBJECT(bag,v15435)))[1]);
                { Iteration * v2429 = v10264; 
                  OID  v2430;
                  { For * v10264 = ((For *) GC_OBJECT(For,new_object_class(Language._For)));
                    store_object(v10264,
                      2,
                      Kernel._object,
                      (*(v15417))[3],
                      CFALSE);
                    (v10264->set_arg = _oid_(v3399));
                    { Iteration * v2431 = v10264; 
                      OID  v2432;
                      { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                        (v10264->selector = Kernel.nth_equal);
                        (v10264->args = list::alloc(4,_oid_(v1049),
                          (*(v15417))[2],
                          (*(v15417))[3],
                          GC_OID(OBJECT(lambda,v15421)->body)));
                        add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
                        v2432 = _oid_(v10264);
                        } 
                      (v2431->arg = v2432);} 
                    add_I_property(Kernel.instances,Language._For,11,_oid_(v10264));
                    v2430 = _oid_(v10264);
                    } 
                  (v2429->arg = v2430);} 
                add_I_property(Kernel.instances,Language._For,11,_oid_(v10264));
                v5703 = _oid_(v10264);
                } 
              else { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                  (v10264->selector = Kernel.put);
                  (v10264->args = list::alloc(3,_oid_(Kernel.DEFAULT),
                    _oid_(v1049),
                    v15420));
                  add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
                  v5703 = _oid_(v10264);
                  } 
                v15875 = v15875->addFast(v5703);
              } 
            GC_OBJECT(list,v15875);} 
          } 
        GC_OBJECT(list,Optimize.OPT->objects)->addFast(v1028);
      (*Optimize.c_register)(v1028);
      { OID  v14305;
        { Do * v10264 = ((Do *) GC_OBJECT(Do,new_object_class(Language._Do)));
          { Do * v2434 = v10264; 
            list * v2435;
            { OID  v804;
              { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                (v10264->selector = Optimize.object_I);
                (v10264->args = list::alloc(2,GC_OID((*Kernel.name)(v1028)),_oid_(Kernel._table)));
                add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
                v804 = _oid_(v10264);
                } 
              v2435 = cons_any(v804,GC_OBJECT(list,add_star_list(v15879,v15875)));
              } 
            (v2434->args = v2435);} 
          add_I_property(Kernel.instances,Language._Do,11,_oid_(v10264));
          v14305 = _oid_(v10264);
          } 
        Result = (*Optimize.c_code)(v14305,
          _oid_(Kernel._any));
        } 
      } 
    GC_UNBIND; return (Result);} 
  } 

void  compute_if_write_inverse_relation2(ClaireRelation *v15402)
{ GC_BIND;
  { Variable * v15440;
    { { Variable * v10264 = ((Variable *) GC_OBJECT(Variable,new_object_class(Language._Variable)));
        (v10264->pname = symbol_I_string2(CSTRING("XX")));
        (v10264->range = v15402->domain);
        add_I_property(Kernel.instances,Language._Variable,11,_oid_(v10264));
        v15440 = v10264;
        } 
      GC_OBJECT(Variable,v15440);} 
    Variable * v15441;
    { { Variable * v10264 = ((Variable *) GC_OBJECT(Variable,new_object_class(Language._Variable)));
        (v10264->pname = symbol_I_string2(CSTRING("YY")));
        (v10264->range = ((multi_ask_any(_oid_(v15402)) == CTRUE) ?
          member_type(v15402->range) :
          v15402->range ));
        add_I_property(Kernel.instances,Language._Variable,11,_oid_(v10264));
        v15441 = v10264;
        } 
      GC_OBJECT(Variable,v15441);} 
    Variable * v15442;
    { { Variable * v10264 = ((Variable *) GC_OBJECT(Variable,new_object_class(Language._Variable)));
        (v10264->pname = symbol_I_string2(CSTRING("ZZ")));
        (v10264->range = v15402->range);
        add_I_property(Kernel.instances,Language._Variable,11,_oid_(v10264));
        v15442 = v10264;
        } 
      GC_OBJECT(Variable,v15442);} 
    list * v3181 = list::empty(Kernel._any);
    if (multi_ask_any(_oid_(v15402)) == CTRUE)
     { v3181= list::alloc(Kernel._any,1,GC_OID((INHERIT(v15402->isa,Kernel._property) ?  Produce_put_property2((property *) OBJECT(property,_oid_(v15402)),OBJECT(Variable,_oid_(v15440)),_oid_(v15441)) :   Produce_put_table2((table *) OBJECT(table,_oid_(v15402)),OBJECT(Variable,_oid_(v15440)),_oid_(v15441)))));
      if (((v15402->inverse == (NULL)) ? CTRUE : CFALSE) != CTRUE)
       v3181= GC_OBJECT(list,v3181->addFast(GC_OID((INHERIT(v15402->inverse->isa,Kernel._property) ?  Produce_put_property2((property *) OBJECT(property,_oid_(v15402->inverse)),OBJECT(Variable,_oid_(v15441)),_oid_(v15440)) :   Produce_put_table2((table *) OBJECT(table,_oid_(v15402->inverse)),OBJECT(Variable,_oid_(v15441)),_oid_(v15440))))));
      { ClaireRelation * v2437 = v15402; 
        OID  v2438;
        { lambda * v4087;{ OID  v8445;
            { If * v10264 = ((If *) GC_OBJECT(If,new_object_class(Language._If)));
              { If * v2462 = v10264; 
                OID  v2463;
                { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                  (v10264->selector = Core.NOT);
                  { Call * v2464 = v10264; 
                    list * v2466;
                    { OID v_bag;
                      GC_ANY(v2466= list::empty(Kernel.emptySet));
                      { { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                          (v10264->selector = Kernel._Z);
                          (v10264->args = list::alloc(2,_oid_(v15441),GC_OID(Produce_get_relation2(v15402,v15440))));
                          add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
                          v_bag = _oid_(v10264);
                          } 
                        GC_OID(v_bag);} 
                      ((list *) v2466)->addFast(v_bag);} 
                    (v2464->args = v2466);} 
                  add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
                  v2463 = _oid_(v10264);
                  } 
                (v2462->test = v2463);} 
              { If * v2467 = v10264; 
                OID  v2468;
                { Do * v10264 = ((Do *) GC_OBJECT(Do,new_object_class(Language._Do)));
                  (v10264->args = v3181);
                  add_I_property(Kernel.instances,Language._Do,11,_oid_(v10264));
                  v2468 = _oid_(v10264);
                  } 
                (v2467->arg = v2468);} 
              add_I_property(Kernel.instances,Language._If,11,_oid_(v10264));
              (v10264->other = Kernel.cfalse);
              v8445 = _oid_(v10264);
              } 
            v4087 = lambda_I_list(list::alloc(2,_oid_(v15440),_oid_(v15441)),v8445);
            } 
          
          v2438=_oid_(v4087);} 
        (v2437->if_write = v2438);} 
      } 
    else { v3181= list::alloc(Kernel._any,1,GC_OID((INHERIT(v15402->isa,Kernel._property) ?  Produce_put_property2((property *) OBJECT(property,_oid_(v15402)),OBJECT(Variable,_oid_(v15440)),_oid_(v15441)) :   Produce_put_table2((table *) OBJECT(table,_oid_(v15402)),OBJECT(Variable,_oid_(v15440)),_oid_(v15441)))));
        if (((v15402->inverse == (NULL)) ? CTRUE : CFALSE) != CTRUE)
         { { { OID  v15172;
              { If * v10264 = ((If *) GC_OBJECT(If,new_object_class(Language._If)));
                { If * v2470 = v10264; 
                  OID  v2491;
                  { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                    (v10264->selector = Core.known_ask);
                    (v10264->args = list::alloc(1,_oid_(v15442)));
                    add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
                    v2491 = _oid_(v10264);
                    } 
                  (v2470->test = v2491);} 
                (v10264->arg = (INHERIT(v15402->inverse->isa,Kernel._property) ?  Produce_remove_property2((property *) OBJECT(property,_oid_(v15402->inverse)),OBJECT(Variable,_oid_(v15442)),_oid_(v15440)) :   Produce_remove_table2((table *) OBJECT(table,_oid_(v15402->inverse)),OBJECT(Variable,_oid_(v15442)),_oid_(v15440))));
                add_I_property(Kernel.instances,Language._If,11,_oid_(v10264));
                (v10264->other = Kernel.cfalse);
                v15172 = _oid_(v10264);
                } 
              v3181 = v3181->addFast(v15172);
              } 
            GC_OBJECT(list,v3181);} 
          v3181= GC_OBJECT(list,v3181->addFast(GC_OID((INHERIT(v15402->inverse->isa,Kernel._property) ?  Produce_put_property2((property *) OBJECT(property,_oid_(v15402->inverse)),OBJECT(Variable,_oid_(v15441)),_oid_(v15440)) :   Produce_put_table2((table *) OBJECT(table,_oid_(v15402->inverse)),OBJECT(Variable,_oid_(v15441)),_oid_(v15440))))));
          } 
        { ClaireRelation * v2492 = v15402; 
          OID  v2493;
          { lambda * v4121;{ OID  v8351;
              { Let * v10264 = ((Let *) GC_OBJECT(Let,new_object_class(Language._Let)));
                (v10264->var = v15442);
                (v10264->value = Produce_get_relation2(v15402,v15440));
                { Let * v2496 = v10264; 
                  OID  v2497;
                  { If * v10264 = ((If *) GC_OBJECT(If,new_object_class(Language._If)));
                    { If * v2498 = v10264; 
                      OID  v2499;
                      { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                        (v10264->selector = Core._I_equal);
                        (v10264->args = list::alloc(2,_oid_(v15441),_oid_(v15442)));
                        add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
                        v2499 = _oid_(v10264);
                        } 
                      (v2498->test = v2499);} 
                    { If * v2500 = v10264; 
                      OID  v2522;
                      { Do * v10264 = ((Do *) GC_OBJECT(Do,new_object_class(Language._Do)));
                        (v10264->args = v3181);
                        add_I_property(Kernel.instances,Language._Do,11,_oid_(v10264));
                        v2522 = _oid_(v10264);
                        } 
                      (v2500->arg = v2522);} 
                    add_I_property(Kernel.instances,Language._If,11,_oid_(v10264));
                    (v10264->other = Kernel.cfalse);
                    v2497 = _oid_(v10264);
                    } 
                  (v2496->arg = v2497);} 
                add_I_property(Kernel.instances,Language._Let,11,_oid_(v10264));
                v8351 = _oid_(v10264);
                } 
              v4121 = lambda_I_list(list::alloc(2,_oid_(v15440),_oid_(v15441)),v8351);
              } 
            
            v2493=_oid_(v4121);} 
          (v2492->if_write = v2493);} 
        } 
      { char * v690 = GC_STRING(append_string(GC_STRING(string_I_symbol(v15402->name)),CSTRING("_write")));
      compile_lambda_string(v690,GC_OBJECT(lambda,OBJECT(lambda,v15402->if_write)),_oid_(Kernel._void));
      } 
    } 
  GC_UNBIND;} 

OID  compute_set_write_relation2(ClaireRelation *v15402)
{ GC_BIND;
  { OID Result = 0;
    { Variable * v15440;
      { { Variable * v10264 = ((Variable *) GC_OBJECT(Variable,new_object_class(Language._Variable)));
          (v10264->pname = symbol_I_string2(CSTRING("XX")));
          (v10264->range = v15402->domain);
          add_I_property(Kernel.instances,Language._Variable,11,_oid_(v10264));
          v15440 = v10264;
          } 
        GC_OBJECT(Variable,v15440);} 
      Variable * v15441;
      { { Variable * v10264 = ((Variable *) GC_OBJECT(Variable,new_object_class(Language._Variable)));
          (v10264->pname = symbol_I_string2(CSTRING("YY")));
          (v10264->range = Kernel._bag);
          add_I_property(Kernel.instances,Language._Variable,11,_oid_(v10264));
          v15441 = v10264;
          } 
        GC_OBJECT(Variable,v15441);} 
      Variable * v15442;
      { { Variable * v10264 = ((Variable *) GC_OBJECT(Variable,new_object_class(Language._Variable)));
          (v10264->pname = symbol_I_string2(CSTRING("ZZ")));
          (v10264->range = member_type(v15402->range));
          add_I_property(Kernel.instances,Language._Variable,11,_oid_(v10264));
          v15442 = v10264;
          } 
        GC_OBJECT(Variable,v15442);} 
      list * v3181 = list::empty(Kernel._any);
      tformat_string(CSTRING("compute set_write for ~S \n"),0,list::alloc(1,_oid_(v15402)));
      if (((v15402->inverse == (NULL)) ? CTRUE : CFALSE) != CTRUE)
       { { OID  v2494;
          { For * v10264 = ((For *) GC_OBJECT(For,new_object_class(Language._For)));
            (v10264->var = v15442);
            (v10264->set_arg = Produce_get_relation2(v15402,v15440));
            (v10264->arg = (INHERIT(v15402->inverse->isa,Kernel._property) ?  Produce_remove_property2((property *) OBJECT(property,_oid_(v15402->inverse)),OBJECT(Variable,_oid_(v15442)),_oid_(v15440)) :   Produce_remove_table2((table *) OBJECT(table,_oid_(v15402->inverse)),OBJECT(Variable,_oid_(v15442)),_oid_(v15440))));
            add_I_property(Kernel.instances,Language._For,11,_oid_(v10264));
            v2494 = _oid_(v10264);
            } 
          v3181 = v3181->addFast(v2494);
          } 
        GC_OBJECT(list,v3181);} 
      v3181= GC_OBJECT(list,v3181->addFast(GC_OID(Produce_erase_property2(((property *) v15402),v15440))));
      { { OID  v3452;
          { For * v10264 = ((For *) GC_OBJECT(For,new_object_class(Language._For)));
            (v10264->var = v15442);
            (v10264->set_arg = _oid_(v15441));
            (v10264->arg = (INHERIT(v15402->isa,Kernel._property) ?  Produce_put_property2((property *) OBJECT(property,_oid_(v15402)),OBJECT(Variable,_oid_(v15440)),_oid_(v15442)) :   Produce_put_table2((table *) OBJECT(table,_oid_(v15402)),OBJECT(Variable,_oid_(v15440)),_oid_(v15442))));
            add_I_property(Kernel.instances,Language._For,11,_oid_(v10264));
            v3452 = _oid_(v10264);
            } 
          v3181 = v3181->addFast(v3452);
          } 
        GC_OBJECT(list,v3181);} 
      { char * v690 = GC_STRING(append_string(GC_STRING(string_I_symbol(v15402->name)),CSTRING("_set_write")));
        { lambda * v4414;
          { { OID  v5374;
              { Do * v10264 = ((Do *) GC_OBJECT(Do,new_object_class(Language._Do)));
                (v10264->args = v3181);
                add_I_property(Kernel.instances,Language._Do,11,_oid_(v10264));
                v5374 = _oid_(v10264);
                } 
              v4414 = lambda_I_list(list::alloc(2,_oid_(v15440),_oid_(v15441)),v5374);
              } 
            GC_OBJECT(lambda,v4414);} 
          Result = compile_lambda_string(v690,v4414,_oid_(Kernel._void));
          } 
        } 
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  Produce_put_property2(property *v15434,Variable *v15440,OID v15441)
{ GC_BIND;
  { OID Result = 0;
    { list * v15428 = list::empty(Kernel._any);
      { OID gc_local;
        ITERATE(v3619);
        for (START(v15434->restrictions); NEXT(v3619);)
        { GC_LOOP;
          if ((Kernel._slot == OBJECT(ClaireObject,v3619)->isa) && 
              (boolean_I_any(_oid_(_exp_type(GC_OBJECT(ClaireType,ptype_type(v15440->range)),domain_I_restriction(OBJECT(restriction,v3619))))) == CTRUE))
           { list * v6336;
            { { OID v_bag;
                GC_ANY(v6336= list::empty(Kernel.emptySet));
                ((list *) v6336)->addFast(_oid_(domain_I_restriction(OBJECT(restriction,v3619))));
                if (boolean_I_any(_oid_(v15434->multivalued_ask)) == CTRUE)
                 { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                  (v10264->selector = Kernel.add_I);
                  { Call * v2528 = v10264; 
                    list * v2529;
                    { OID v_bag;
                      GC_ANY(v2529= list::empty(Kernel.emptySet));
                      { { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                          (v10264->selector = v15434);
                          { Call * v2531 = v10264; 
                            list * v2532;
                            { OID v_bag;
                              GC_ANY(v2532= list::empty(Kernel.emptySet));
                              { { Cast * v10264 = ((Cast *) GC_OBJECT(Cast,new_object_class(Language._Cast)));
                                  (v10264->arg = _oid_(v15440));
                                  (v10264->set_arg = domain_I_restriction(OBJECT(restriction,v3619)));
                                  add_I_property(Kernel.instances,Language._Cast,11,_oid_(v10264));
                                  v_bag = _oid_(v10264);
                                  } 
                                GC_OID(v_bag);} 
                              ((list *) v2532)->addFast(v_bag);} 
                            (v2531->args = v2532);} 
                          add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
                          v_bag = _oid_(v10264);
                          } 
                        GC_OID(v_bag);} 
                      ((list *) v2529)->addFast(v_bag);
                      ((list *) v2529)->addFast(v15441);} 
                    (v2528->args = v2529);} 
                  add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
                  v_bag = _oid_(v10264);
                  } 
                else { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                    (v10264->selector = Kernel.put);
                    { Call * v3204 = v10264; 
                      list * v3205;
                      { OID v_bag;
                        GC_ANY(v3205= list::empty(Kernel.emptySet));
                        ((list *) v3205)->addFast(_oid_(v15434));
                        { { Cast * v10264 = ((Cast *) GC_OBJECT(Cast,new_object_class(Language._Cast)));
                            (v10264->arg = _oid_(v15440));
                            (v10264->set_arg = domain_I_restriction(OBJECT(restriction,v3619)));
                            add_I_property(Kernel.instances,Language._Cast,11,_oid_(v10264));
                            v_bag = _oid_(v10264);
                            } 
                          GC_OID(v_bag);} 
                        ((list *) v3205)->addFast(v_bag);
                        ((list *) v3205)->addFast(v15441);} 
                      (v3204->args = v3205);} 
                    add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
                    v_bag = _oid_(v10264);
                    } 
                  ((list *) v6336)->addFast(v_bag);} 
              GC_OBJECT(list,v6336);} 
            v15428 = add_star_list(v15428,v6336);
            } 
          GC_UNLOOP;} 
        } 
      if (v15428->length == 2)
       Result = (*(v15428))[2];
      else { Case * v10264 = ((Case *) GC_OBJECT(Case,new_object_class(Language._Case)));
          (v10264->var = _oid_(v15440));
          (v10264->args = v15428);
          add_I_property(Kernel.instances,Language._Case,11,_oid_(v10264));
          Result = _oid_(v10264);
          } 
        } 
    GC_UNBIND; return (Result);} 
  } 

OID  Produce_erase_property2(property *v15434,Variable *v15440)
{ GC_BIND;
  { OID Result = 0;
    { list * v15428 = list::empty(Kernel._any);
      bag * v11513;
      if (v15434->multivalued_ask == Kernel._list)
       v11513 = list::empty(Kernel._any);
      else v11513 = set::empty(Kernel._any);
        cast_I_bag(v11513,member_type(v15434->range));
      { OID gc_local;
        ITERATE(v3619);
        for (START(v15434->restrictions); NEXT(v3619);)
        { GC_LOOP;
          if ((Kernel._slot == OBJECT(ClaireObject,v3619)->isa) && 
              (boolean_I_any(_oid_(_exp_type(GC_OBJECT(ClaireType,ptype_type(v15440->range)),domain_I_restriction(OBJECT(restriction,v3619))))) == CTRUE))
           { list * v3494;
            { { OID v_bag;
                GC_ANY(v3494= list::empty(Kernel.emptySet));
                ((list *) v3494)->addFast(_oid_(domain_I_restriction(OBJECT(restriction,v3619))));
                { { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                    (v10264->selector = Kernel.put);
                    { Call * v3207 = v10264; 
                      list * v3208;
                      { OID v_bag;
                        GC_ANY(v3208= list::empty(Kernel.emptySet));
                        ((list *) v3208)->addFast(_oid_(v15434));
                        { { Cast * v10264 = ((Cast *) GC_OBJECT(Cast,new_object_class(Language._Cast)));
                            (v10264->arg = _oid_(v15440));
                            (v10264->set_arg = domain_I_restriction(OBJECT(restriction,v3619)));
                            add_I_property(Kernel.instances,Language._Cast,11,_oid_(v10264));
                            v_bag = _oid_(v10264);
                            } 
                          GC_OID(v_bag);} 
                        ((list *) v3208)->addFast(v_bag);
                        { if (boolean_I_any(_oid_(v15434->multivalued_ask)) == CTRUE)
                           v_bag = _oid_(v11513);
                          else v_bag = OBJECT(slot,v3619)->DEFAULT;
                            GC_OID(v_bag);} 
                        ((list *) v3208)->addFast(v_bag);} 
                      (v3207->args = v3208);} 
                    add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
                    v_bag = _oid_(v10264);
                    } 
                  GC_OID(v_bag);} 
                ((list *) v3494)->addFast(v_bag);} 
              GC_OBJECT(list,v3494);} 
            v15428 = add_star_list(v15428,v3494);
            } 
          GC_UNLOOP;} 
        } 
      if (v15428->length == 2)
       Result = (*(v15428))[2];
      else { Case * v10264 = ((Case *) GC_OBJECT(Case,new_object_class(Language._Case)));
          (v10264->var = _oid_(v15440));
          (v10264->args = v15428);
          add_I_property(Kernel.instances,Language._Case,11,_oid_(v10264));
          Result = _oid_(v10264);
          } 
        } 
    GC_UNBIND; return (Result);} 
  } 

OID  Produce_put_table2(table *v15434,Variable *v15440,OID v15441)
{ GC_BIND;
  { OID Result = 0;
    { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
      (v10264->selector = Kernel.put);
      { Call * v3209 = v10264; 
        list * v3210;
        { OID v_bag;
          GC_ANY(v3210= list::empty(Kernel.emptySet));
          ((list *) v3210)->addFast(_oid_(v15434));
          ((list *) v3210)->addFast(_oid_(v15440));
          if (boolean_I_any(_oid_(v15434->multivalued_ask)) == CTRUE)
           { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
            (v10264->selector = Kernel.add);
            (v10264->args = list::alloc(2,_oid_(list::alloc(2,_oid_(Kernel.nth),_oid_(list::alloc(2,_oid_(v15434),_oid_(v15440))))),v15441));
            add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
            v_bag = _oid_(v10264);
            } 
          else v_bag = v15441;
            ((list *) v3210)->addFast(v_bag);} 
        (v3209->args = v3210);} 
      add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
      Result = _oid_(v10264);
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  Produce_get_relation2(ClaireRelation *v15434,Variable *v15440)
{ GC_BIND;
  { OID Result = 0;
    if (INHERIT(v15434->isa,Kernel._table))
     { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
      (v10264->selector = Kernel.nth);
      (v10264->args = list::alloc(2,_oid_(v15434),_oid_(v15440)));
      add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
      Result = _oid_(v10264);
      } 
    else if (INHERIT(v15434->isa,Kernel._property))
     { list * v15428 = list::empty(Kernel._any);
      { OID gc_local;
        ITERATE(v3619);
        for (START(CLREAD(property,v15434,restrictions)); NEXT(v3619);)
        { GC_LOOP;
          if ((Kernel._slot == OBJECT(ClaireObject,v3619)->isa) && 
              (boolean_I_any(_oid_(_exp_type(GC_OBJECT(ClaireType,ptype_type(v15440->range)),domain_I_restriction(OBJECT(restriction,v3619))))) == CTRUE))
           { list * v8299;
            { { OID v_bag;
                GC_ANY(v8299= list::empty(Kernel.emptySet));
                ((list *) v8299)->addFast(_oid_(domain_I_restriction(OBJECT(restriction,v3619))));
                { { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                    (v10264->selector = ((property *) v15434));
                    { Call * v3212 = v10264; 
                      list * v3214;
                      { OID v_bag;
                        GC_ANY(v3214= list::empty(Kernel.emptySet));
                        { { Cast * v10264 = ((Cast *) GC_OBJECT(Cast,new_object_class(Language._Cast)));
                            (v10264->arg = _oid_(v15440));
                            (v10264->set_arg = domain_I_restriction(OBJECT(restriction,v3619)));
                            add_I_property(Kernel.instances,Language._Cast,11,_oid_(v10264));
                            v_bag = _oid_(v10264);
                            } 
                          GC_OID(v_bag);} 
                        ((list *) v3214)->addFast(v_bag);} 
                      (v3212->args = v3214);} 
                    add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
                    v_bag = _oid_(v10264);
                    } 
                  GC_OID(v_bag);} 
                ((list *) v8299)->addFast(v_bag);} 
              GC_OBJECT(list,v8299);} 
            v15428 = add_star_list(v15428,v8299);
            } 
          GC_UNLOOP;} 
        } 
      if (v15428->length == 2)
       Result = (*(v15428))[2];
      else { Case * v10264 = ((Case *) GC_OBJECT(Case,new_object_class(Language._Case)));
          (v10264->var = _oid_(v15440));
          (v10264->args = v15428);
          add_I_property(Kernel.instances,Language._Case,11,_oid_(v10264));
          Result = _oid_(v10264);
          } 
        } 
    else Result = Kernel.cfalse;
      GC_UNBIND; return (Result);} 
  } 

OID  Produce_remove_property2(property *v15434,Variable *v15440,OID v15441)
{ GC_BIND;
  { OID Result = 0;
    { list * v15428 = list::empty(Kernel._any);
      { OID gc_local;
        ITERATE(v3619);
        for (START(v15434->restrictions); NEXT(v3619);)
        { GC_LOOP;
          if (Kernel._slot == OBJECT(ClaireObject,v3619)->isa)
           { list * v14979;
            { { OID v_bag;
                GC_ANY(v14979= list::empty(Kernel.emptySet));
                ((list *) v14979)->addFast(_oid_(domain_I_restriction(OBJECT(restriction,v3619))));
                if (boolean_I_any(_oid_(v15434->multivalued_ask)) == CTRUE)
                 { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                  (v10264->selector = Kernel._delete);
                  { Call * v3236 = v10264; 
                    list * v3237;
                    { OID v_bag;
                      GC_ANY(v3237= list::empty(Kernel.emptySet));
                      { { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                          (v10264->selector = v15434);
                          (v10264->args = list::alloc(1,_oid_(v15440)));
                          add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
                          v_bag = _oid_(v10264);
                          } 
                        GC_OID(v_bag);} 
                      ((list *) v3237)->addFast(v_bag);
                      ((list *) v3237)->addFast(v15441);} 
                    (v3236->args = v3237);} 
                  add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
                  v_bag = _oid_(v10264);
                  } 
                else { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                    (v10264->selector = Kernel.put);
                    (v10264->args = list::alloc(3,_oid_(v15434),
                      _oid_(v15440),
                      CNULL));
                    add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
                    v_bag = _oid_(v10264);
                    } 
                  ((list *) v14979)->addFast(v_bag);} 
              GC_OBJECT(list,v14979);} 
            v15428 = add_star_list(v15428,v14979);
            } 
          GC_UNLOOP;} 
        } 
      if (v15428->length == 2)
       Result = (*(v15428))[2];
      else { Case * v10264 = ((Case *) GC_OBJECT(Case,new_object_class(Language._Case)));
          (v10264->var = _oid_(v15440));
          (v10264->args = v15428);
          add_I_property(Kernel.instances,Language._Case,11,_oid_(v10264));
          Result = _oid_(v10264);
          } 
        } 
    GC_UNBIND; return (Result);} 
  } 

OID  Produce_remove_table2(table *v15434,Variable *v15440,OID v15441)
{ GC_BIND;
  { OID Result = 0;
    { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
      (v10264->selector = Kernel.put);
      { Call * v3238 = v10264; 
        list * v3239;
        { OID v_bag;
          GC_ANY(v3239= list::empty(Kernel.emptySet));
          ((list *) v3239)->addFast(_oid_(v15434));
          ((list *) v3239)->addFast(_oid_(v15440));
          if (boolean_I_any(_oid_(v15434->multivalued_ask)) == CTRUE)
           { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
            (v10264->selector = Kernel._delete);
            (v10264->args = list::alloc(2,_oid_(list::alloc(2,_oid_(Kernel.nth),_oid_(list::alloc(2,_oid_(v15434),_oid_(v15440))))),v15441));
            add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
            v_bag = _oid_(v10264);
            } 
          else v_bag = CNULL;
            ((list *) v3239)->addFast(v_bag);} 
        (v3238->args = v3239);} 
      add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
      Result = _oid_(v10264);
      } 
    GC_UNBIND; return (Result);} 
  } 

void  Tighten_relation2(ClaireRelation *v15434)
{ GC_RESERVE(6);  // v3.0.55 optim !
  if (INHERIT(v15434->isa,Kernel._property))
   { ClaireType * v2892 = set::empty();
    ClaireType * v2905 = set::empty();
    { OID gc_local;
      ITERATE(v15435);
      for (START(CLREAD(property,v15434,restrictions)); NEXT(v15435);)
      { GC_LOOP;
        if (Kernel._slot == OBJECT(ClaireObject,v15435)->isa)
         { GC__ANY(v2892 = U_type(v2892,domain_I_restriction(OBJECT(restriction,v15435))), 3);
          GC__ANY(v2905 = U_type(v2905,GC_OBJECT(ClaireType,((multi_ask_any(_oid_(v15434)) == CTRUE) ?
            member_type(OBJECT(restriction,v15435)->range) :
            OBJECT(restriction,v15435)->range ))), 4);
          } 
        GC_UNLOOP;} 
      } 
    (v15434->open = 1);
    (v15434->domain = class_I_type(v2892));
    (v15434->range = ((v15434->multivalued_ask == Kernel._list) ?
      param_I_class(Kernel._list,class_I_type(v2905)) :
      ((v15434->multivalued_ask == Kernel._set) ?
        param_I_class(Kernel._set,class_I_type(v2905)) :
        v2905 ) ));
    ;} 
  GC_UNBIND;} 

void  lexical_num_any2(OID v9332,Cint v15431)
{ GC_BIND;
  if (INHERIT(OWNER(v9332),Language._Call))
   lexical_num_any2(GC_OID(_oid_(OBJECT(Call,v9332)->args)),v15431);
  else if (INHERIT(OWNER(v9332),Language._Instruction))
   { ClaireClass * v1207 = OBJECT(ClaireObject,v9332)->isa;
    if (contain_ask_set(Language._Instruction_with_var->descendents,_oid_(v1207)) == CTRUE)
     { put_property2(Kernel.index,GC_OBJECT(ClaireObject,OBJECT(ClaireObject,(*Language.var)(v9332))),v15431);
      ++v15431;
      if (v15431 > Language._starvariable_index_star->value)
       (Language._starvariable_index_star->value= v15431);
      } 
    { OID gc_local;
      ITERATE(v15435);
      for (START(v1207->slots); NEXT(v15435);)
      { GC_LOOP;
        lexical_num_any2(GC_OID(get_slot(OBJECT(slot,v15435),OBJECT(ClaireObject,v9332))),v15431);
        GC_UNLOOP;} 
      } 
    } 
  else if (INHERIT(OWNER(v9332),Kernel._bag))
   { OID gc_local;
    ITERATE(v15440);
    for (START(OBJECT(bag,v9332)); NEXT(v15440);)
    lexical_num_any2(v15440,v15431);
    } 
  else ;GC_UNBIND;} 

ClaireType * c_type_Defrule2_Optimize(Defrule *v9332)
{ return (Kernel._any);} 

OID  c_code_Defrule_Optimize(Defrule *v9332,ClaireClass *v15435)
{ GC_RESERVE(11);  // v3.0.55 optim !
  { OID Result = 0;
    { OID  v3435 = GC_OID(get_symbol(v9332->ident));
      list * v15428 = list::empty(Kernel._any);
      tformat_string(CSTRING("compile a rule ~S \n"),0,list::alloc(1,v3435));
      { OID gc_local;
        ITERATE(v15434);
        bag *v15434_support;
        v15434_support = GC_OBJECT(set,OBJECT(bag,nth_table1(Language.relations,v3435)));
        for (START(v15434_support); NEXT(v15434);)
        if (eventMethod_ask_relation2(OBJECT(ClaireRelation,v15434)) != CTRUE)
         Tighten_relation2(OBJECT(ClaireRelation,v15434));
        } 
      { OID gc_local;
        ITERATE(v15434);
        bag *v15434_support;
        v15434_support = GC_OBJECT(set,OBJECT(bag,nth_table1(Language.relations,v3435)));
        for (START(v15434_support); NEXT(v15434);)
        { GC_LOOP;
          { if ((*Kernel.open)(v15434) < 2)
             { OID  v3400;
              { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                (v10264->selector = Kernel.FINAL);
                (v10264->args = list::alloc(1,v15434));
                add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
                v3400 = _oid_(v10264);
                } 
              v15428 = v15428->addFast(v3400);
              } 
            compile_if_write_relation(OBJECT(ClaireRelation,v15434));
            { OID  v690 = GC_OID((*Kernel._7_plus)(GC_OID((*Kernel.name)(v15434)),
                _string_(CSTRING("_write"))));
              char * v15435 = GC_STRING(string_I_symbol(OBJECT(symbol,v690)));
              OID  v3230 = GC_OID((*Kernel.if_write)(v15434));
              compile_lambda_string(v15435,OBJECT(lambda,v3230),_oid_(Kernel._void));
              { OID  v4361;
                { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                  (v10264->selector = Kernel.put);
                  (v10264->args = list::alloc(3,Optimize.if_write->value,
                    v15434,
                    _oid_(make_function_string(v15435))));
                  add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
                  v4361 = _oid_(v10264);
                  } 
                v15428->addFast(v4361);
                } 
              } 
            } 
          GC_UNLOOP;} 
        } 
      { OID gc_local;
        ITERATE(v15434);
        bag *v15434_support;
        v15434_support = GC_OBJECT(set,OBJECT(bag,nth_table1(Language.relations,v3435)));
        for (START(v15434_support); NEXT(v15434);)
        { GC_LOOP;
          if (eventMethod_ask_relation2(OBJECT(ClaireRelation,v15434)) == CTRUE)
           v15428= v15428->addFast(GC_OID(compileEventMethod_property(OBJECT(property,v15434))));
          GC_UNLOOP;} 
        } 
      { OID  v5322;
        { Do * v10264 = ((Do *) GC_OBJECT(Do,new_object_class(Language._Do)));
          (v10264->args = v15428);
          add_I_property(Kernel.instances,Language._Do,11,_oid_(v10264));
          v5322 = _oid_(v10264);
          } 
        Result = (*Optimize.c_code)(v5322,
          _oid_(v15435));
        } 
      } 
    GC_UNBIND; return (Result);} 
  } 

void  compile_if_write_relation(ClaireRelation *v15402)
{ GC_BIND;
  { OID  v15428 = GC_OID(nth_table1(Language.demons,_oid_(v15402)));
    list * v13411 = GC_OBJECT(list,OBJECT(Language_demon,(*(OBJECT(bag,v15428)))[1])->formula->vars);
    list * v3181 = list::alloc(Kernel._any,1,GC_OID((*Optimize.Produce_put)(_oid_(v15402),
      (*(v13411))[1],
      (*(v13411))[2])));
    list * v3182;
    { { bag *v_list; OID v_val;
        OID v15440,CLcount;
        v_list = OBJECT(bag,v15428);
         v3182 = v_list->clone(Kernel._any);
        for (CLcount= 1; CLcount <= v_list->length; CLcount++)
        { v15440 = (*(v_list))[CLcount];
          v_val = substitution_any(substitution_any(substitution_any(OBJECT(Language_demon,v15440)->formula->body,OBJECT(Variable,(*(OBJECT(Language_demon,v15440)->formula->vars))[3]),(*(v13411))[3]),OBJECT(Variable,(*(OBJECT(Language_demon,v15440)->formula->vars))[1]),(*(v13411))[1]),OBJECT(Variable,(*(OBJECT(Language_demon,v15440)->formula->vars))[2]),(*(v13411))[2]);
          
          (*((list *) v3182))[CLcount] = v_val;} 
        } 
      GC_OBJECT(list,v3182);} 
    put_property2(Kernel.range,OBJECT(ClaireObject,(*(v13411))[1]),_oid_(v15402->domain));
    put_property2(Kernel.range,OBJECT(ClaireObject,(*(v13411))[2]),_oid_(v15402->range));
    { ITERATE(v15438);
      for (START(v13411); NEXT(v15438);)
      put_property2(Kernel.range,OBJECT(ClaireObject,v15438),_oid_(class_I_type(OBJECT(ClaireType,(*Kernel.range)(v15438)))));
      } 
    if ((INHERIT(OWNER((*(v3182))[1]),Language._If)) && 
        (eventMethod_ask_relation2(v15402) != CTRUE))
     { if (INHERIT(OWNER(OBJECT(If,(*(v3182))[1])->test),Language._And))
       { If * v3243 = OBJECT(If,(*(v3182))[1]); 
        OID  v3248;
        { And * v10264 = ((And *) GC_OBJECT(And,new_object_class(Language._And)));
          (v10264->args = cdr_list(GC_OBJECT(list,OBJECT(list,(*Core.args)(GC_OID(OBJECT(If,(*(v3182))[1])->test))))));
          add_I_property(Kernel.instances,Language._And,11,_oid_(v10264));
          v3248 = _oid_(v10264);
          } 
        (v3243->test = v3248);} 
      else ((*(v3182))[1]=OBJECT(If,(*(v3182))[1])->arg);
        } 
    if (((v15402->inverse == (NULL)) ? CTRUE : CFALSE) != CTRUE)
     { if (multi_ask_any(_oid_(v15402)) != CTRUE)
       v3181= GC_OBJECT(list,v3181->addFast(GC_OID((*Optimize.Produce_remove)(_oid_(v15402->inverse),
        (*(v13411))[3],
        (*(v13411))[1]))));
      v3181= GC_OBJECT(list,v3181->addFast(GC_OID((*Optimize.Produce_put)(_oid_(v15402->inverse),
        (*(v13411))[2],
        (*(v13411))[1]))));
      } 
    { ClaireRelation * v3266 = v15402; 
      OID  v3267;
      { lambda * v4895;{ OID  v14887;
          if (eventMethod_ask_relation2(v15402) == CTRUE)
           { Do * v10264 = ((Do *) GC_OBJECT(Do,new_object_class(Language._Do)));
            (v10264->args = v3182);
            add_I_property(Kernel.instances,Language._Do,11,_oid_(v10264));
            v14887 = _oid_(v10264);
            } 
          else if (multi_ask_any(_oid_(v15402)) == CTRUE)
           { If * v10264 = ((If *) GC_OBJECT(If,new_object_class(Language._If)));
            { If * v3270 = v10264; 
              OID  v3271;
              { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                (v10264->selector = Core.NOT);
                { Call * v3272 = v10264; 
                  list * v3273;
                  { OID v_bag;
                    GC_ANY(v3273= list::empty(Kernel.emptySet));
                    { { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                        (v10264->selector = Kernel._Z);
                        (v10264->args = list::alloc(2,(*(v13411))[2],GC_OID(_oid_(readCall_relation(v15402,(*(v13411))[1])))));
                        add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
                        v_bag = _oid_(v10264);
                        } 
                      GC_OID(v_bag);} 
                    ((list *) v3273)->addFast(v_bag);} 
                  (v3272->args = v3273);} 
                add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
                v3271 = _oid_(v10264);
                } 
              (v3270->test = v3271);} 
            { If * v3274 = v10264; 
              OID  v3275;
              { Do * v10264 = ((Do *) GC_OBJECT(Do,new_object_class(Language._Do)));
                (v10264->args = append_list(v3181,v3182));
                add_I_property(Kernel.instances,Language._Do,11,_oid_(v10264));
                v3275 = _oid_(v10264);
                } 
              (v3274->arg = v3275);} 
            add_I_property(Kernel.instances,Language._If,11,_oid_(v10264));
            (v10264->other = Kernel.cfalse);
            v14887 = _oid_(v10264);
            } 
          else { Let * v10264 = ((Let *) GC_OBJECT(Let,new_object_class(Language._Let)));
              store_object(v10264,
                2,
                Kernel._object,
                (*(v13411))[3],
                CFALSE);
              (v10264->value = _oid_(readCall_relation(v15402,(*(v13411))[1])));
              { Let * v3297 = v10264; 
                OID  v3298;
                { If * v10264 = ((If *) GC_OBJECT(If,new_object_class(Language._If)));
                  { If * v3299 = v10264; 
                    OID  v3300;
                    { Call * v10264 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                      (v10264->selector = Core._I_equal);
                      (v10264->args = list::alloc(2,(*(v13411))[2],(*(v13411))[3]));
                      add_I_property(Kernel.instances,Language._Call,11,_oid_(v10264));
                      v3300 = _oid_(v10264);
                      } 
                    (v3299->test = v3300);} 
                  { If * v3301 = v10264; 
                    OID  v3302;
                    { Do * v10264 = ((Do *) GC_OBJECT(Do,new_object_class(Language._Do)));
                      (v10264->args = append_list(v3181,v3182));
                      add_I_property(Kernel.instances,Language._Do,11,_oid_(v10264));
                      v3302 = _oid_(v10264);
                      } 
                    (v3301->arg = v3302);} 
                  add_I_property(Kernel.instances,Language._If,11,_oid_(v10264));
                  (v10264->other = Kernel.cfalse);
                  v3298 = _oid_(v10264);
                  } 
                (v3297->arg = v3298);} 
              add_I_property(Kernel.instances,Language._Let,11,_oid_(v10264));
              v14887 = _oid_(v10264);
              } 
            v4895 = lambda_I_list(list::alloc(2,(*(v13411))[1],(*(v13411))[2]),v14887);
          } 
        
        v3267=_oid_(v4895);} 
      (v3266->if_write = v3267);} 
    } 
  GC_UNBIND;} 

OID  compileEventMethod_property(property *v15432)
{ GC_BIND;
  { OID Result = 0;
    { method * v15429 = OBJECT(method,(*(v15432->restrictions))[1]);
      char * v3291 = GC_STRING(append_string(GC_STRING(string_I_symbol(v15432->name)),CSTRING("_write")));
      Result = add_method_I_method(v15429,
        list::alloc(2,_oid_(v15432->domain),_oid_(v15432->range)),
        _oid_(Kernel._void),
        0,
        make_function_string(v3291));
      } 
    GC_UNBIND; return (Result);} 
  } 

