/***** CLAIRE Compilation of file e:\claire\v3.5\src\compile\gexp.cl 
         [version 3.5.0 / safety 5] Sun May 28 08:26:01 2017 *****/

#include <claire.h>
#include <Kernel.h>
#include <Core.h>
#include <Language.h>
#include <Reader.h>
#include <Optimize.h>
#include <Generate.h>
ClaireBoolean * c_func_any(OID v13492)
{ GC_RESERVE(1);  // HOHO v3.0.55 optim !
  { ClaireBoolean *Result ;
    if (INHERIT(OWNER(v13492),Kernel._bag))
     { OID  v616;
      { OID gc_local;
        ITERATE(v5136);
        v616= Kernel.cfalse;
        for (START(OBJECT(bag,v13492)); NEXT(v5136);)
        if (c_func_any(v5136) != CTRUE)
         { v616 = Kernel.ctrue;
          break;} 
        else ;} 
      Result = not_any(v616);
      } 
    else if (INHERIT(OWNER(v13492),Language._Construct))
     { if (((INHERIT(OBJECT(ClaireObject,v13492)->isa,Language._Set)) || 
            (INHERIT(OBJECT(ClaireObject,v13492)->isa,Language._List))) || 
          (INHERIT(OBJECT(ClaireObject,v13492)->isa,Language._Tuple)))
       { ClaireBoolean *v_and;
        { v_and = ((OBJECT(Construct,v13492)->args->length < 15) ? CTRUE : CFALSE);
          if (v_and == CFALSE) Result =CFALSE; 
          else { { OID  v5374;
              { ClaireBoolean * v12346;{ OID  v7296;
                  { set * v12348;{ set * v10911 = set::empty(Kernel.emptySet);
                      { OID gc_local;
                        ITERATE(v5136);
                        bag *v5136_support;
                        v5136_support = GC_OBJECT(list,OBJECT(Construct,v13492)->args);
                        for (START(v5136_support); NEXT(v5136);)
                        if (c_func_any(v5136) != CTRUE)
                         v10911->addFast(v5136);
                        } 
                      v12348 = GC_OBJECT(set,v10911);
                      } 
                    
                    v7296=_oid_(v12348);} 
                  v12346 = boolean_I_any(v7296);
                  } 
                
                v5374=_oid_(v12346);} 
              v_and = ((v5374 != Kernel.ctrue) ? CTRUE : CFALSE);
              } 
            if (v_and == CFALSE) Result =CFALSE; 
            else Result = CTRUE;} 
          } 
        } 
      else Result = CFALSE;
        } 
    else if (INHERIT(OWNER(v13492),Language._If))
     { ClaireBoolean *v_and;
      { v_and = c_func_any(GC_OID(OBJECT(If,v13492)->test));
        if (v_and == CFALSE) Result =CFALSE; 
        else { v_and = c_func_any(GC_OID(OBJECT(If,v13492)->arg));
          if (v_and == CFALSE) Result =CFALSE; 
          else { v_and = c_func_any(GC_OID(OBJECT(If,v13492)->other));
            if (v_and == CFALSE) Result =CFALSE; 
            else { v_and = stupid_t_any2(GC_OID(OBJECT(If,v13492)->arg),GC_OID(OBJECT(If,v13492)->other));
              if (v_and == CFALSE) Result =CFALSE; 
              else { { Cint  v5126 = 4;
                  OID  v5136 = GC_OID(OBJECT(If,v13492)->other);
                  { OID v11634;{ OID gc_local;
                      v11634= _oid_(CFALSE);
                      while ((v5126 > 0))
                      { GC_LOOP;
                        if (INHERIT(OWNER(v5136),Language._If))
                         { GC__OID(v5136 = OBJECT(If,v5136)->other, 1);
                          v5126= (v5126-1);
                          } 
                        else { v11634 = Kernel.ctrue;
                            break;} 
                          GC_UNLOOP;} 
                      } 
                    
                    v_and=OBJECT(ClaireBoolean,v11634);} 
                  } 
                if (v_and == CFALSE) Result =CFALSE; 
                else Result = CTRUE;} 
              } 
            } 
          } 
        } 
      } 
    else if (INHERIT(OWNER(v13492),Language._Assign))
     Result = c_func_any(GC_OID(OBJECT(Assign,v13492)->arg));
    else if (INHERIT(OWNER(v13492),Language._Gassign))
     Result = c_func_any(GC_OID(OBJECT(Gassign,v13492)->arg));
    else if (INHERIT(OWNER(v13492),Optimize._to_protect))
     Result = c_func_any(GC_OID(OBJECT(Compile_to_protect,v13492)->arg));
    else if (INHERIT(OWNER(v13492),Language._And))
     Result = c_func_any(GC_OID(_oid_(OBJECT(And,v13492)->args)));
    else if (INHERIT(OWNER(v13492),Language._Or))
     Result = c_func_any(GC_OID(_oid_(OBJECT(Or,v13492)->args)));
    else if (INHERIT(OWNER(v13492),Language._Call))
     Result = c_func_any(GC_OID(_oid_(OBJECT(Call,v13492)->args)));
    else if (INHERIT(OWNER(v13492),Language._Call_method))
     Result = ((c_func_any(GC_OID(_oid_(OBJECT(Call_method,v13492)->args))) == CTRUE) ? ((_oid_(OBJECT(Call_method,v13492)->arg) != Generate._starclose_exception_star->value) ? CTRUE: CFALSE): CFALSE);
    else if (INHERIT(OWNER(v13492),Language._Call_slot))
     Result = c_func_any(GC_OID(OBJECT(Call_slot,v13492)->arg));
    else if (INHERIT(OWNER(v13492),Language._Call_table))
     Result = c_func_any(GC_OID(OBJECT(Call_table,v13492)->arg));
    else if (INHERIT(OWNER(v13492),Language._Call_array))
     Result = c_func_any(GC_OID(OBJECT(Call_array,v13492)->arg));
    else Result = ((INHERIT(OWNER(v13492),Language._Update)) ?
      ((c_func_any(GC_OID(OBJECT(Update,v13492)->value)) == CTRUE) ? ((c_func_any(GC_OID(OBJECT(Update,v13492)->arg)) == CTRUE) ? CTRUE: CFALSE): CFALSE) :
      ((INHERIT(OWNER(v13492),Language._Cast)) ?
        c_func_any(GC_OID(OBJECT(Cast,v13492)->arg)) :
        ((INHERIT(OWNER(v13492),Optimize._to_C)) ?
          c_func_any(GC_OID(OBJECT(Compile_to_C,v13492)->arg)) :
          ((INHERIT(OWNER(v13492),Optimize._to_CL)) ?
            c_func_any(GC_OID(OBJECT(Compile_to_CL,v13492)->arg)) :
            ((INHERIT(OWNER(v13492),Kernel._thing)) ? CTRUE : 
            ((INHERIT(OWNER(v13492),Kernel._integer)) ? CTRUE : 
            ((Kernel._string == OWNER(v13492)) ? CTRUE : 
            ((INHERIT(OWNER(v13492),Kernel._char)) ? CTRUE : 
            ((Kernel._float == OWNER(v13492)) ? CTRUE : 
            ((INHERIT(OWNER(v13492),Language._Variable)) ? CTRUE : 
            ((INHERIT(OWNER(v13492),Core._global_variable)) ? CTRUE : 
            ((INHERIT(OWNER(v13492),Kernel._function)) ? CTRUE : 
            ((INHERIT(OWNER(v13492),Kernel._symbol)) ? CTRUE : 
            ((v13492 == CNULL) ? CTRUE : 
            ((Kernel._boolean == OWNER(v13492)) ? CTRUE : 
            ((INHERIT(OWNER(v13492),Kernel._class)) ? CTRUE : 
            ((INHERIT(OWNER(v13492),Kernel._environment)) ? CTRUE : 
            CFALSE))))))))))))) ) ) ) );
    GC_UNBIND; return (Result);} 
  } 

void  expression_thing(thing *v13492,OID v11276)
{ (*Generate.produce)(Generate.PRODUCER->value,
    _oid_(v13492));
  } 

void  expression_integer(Cint v13492,OID v11276)
{ princ_integer(v13492);
  } 

void  expression_any(OID v13492,OID v11276)
{ (*Generate.produce)(Generate.PRODUCER->value,
    v13492);
  } 

void  expression_string(char *v13492,OID v11276)
{ (*Generate.produce)(Generate.PRODUCER->value,
    _string_(v13492));
  } 

void  expression_float_(OID v2530,OID v2531)
{ expression_float(float_v(v2530),v2531);} 

void  expression_float(double v13492,OID v11276)
{ princ_float(v13492);
  } 

void  expression_boolean(ClaireBoolean *v13492,OID v11276)
{ (*Generate.produce)(Generate.PRODUCER->value,
    _oid_(v13492));
  } 

void  expression_environment(ClaireEnvironment *v13492,OID v11276)
{ (*Generate.produce)(Generate.PRODUCER->value,
    _oid_(v13492));
  } 

void  expression_Variable(Variable *v13492,OID v11276)
{ (*Language.ident)(Generate.PRODUCER->value,
    _oid_(v13492));
  } 

void  expression_global_variable(global_variable *v13492,OID v11276)
{ (*Generate.produce)(Generate.PRODUCER->value,
    _oid_(v13492));
  } 

void  expression_Set(Set *v13492,OID v11276)
{ GC_BIND;
  { OID  v11140;
    { if (((v13492->of == (NULL)) ? CTRUE : CFALSE) != CTRUE)
       v11140 = _oid_(v13492->of);
      else v11140 = _oid_(Kernel._void);
        GC_OID(v11140);} 
    (*Generate.bag_expression)(Generate.PRODUCER->value,
      _oid_(Kernel._set),
      GC_OID(_oid_(v13492->args)),
      v11140,
      v11276);
    } 
  GC_UNBIND;} 

void  expression_set2(set *v13492,OID v11276)
{ GC_BIND;
  if ((v13492->length == 0) && 
      (equal(_oid_(of_bag(v13492)),_oid_(Kernel.emptySet)) == CTRUE))
   princ_string(CSTRING("Kernel.emptySet"));
  else (*Generate.bag_expression)(Generate.PRODUCER->value,
      _oid_(Kernel._set),
      _oid_(v13492),
      GC_OID(_oid_(of_bag(v13492))),
      v11276);
    GC_UNBIND;} 

void  expression_Tuple(Tuple *v13492,OID v11276)
{ GC_BIND;
  (*Generate.bag_expression)(Generate.PRODUCER->value,
    _oid_(Kernel._tuple),
    GC_OID(_oid_(v13492->args)),
    _oid_(Kernel._void),
    v11276);
  GC_UNBIND;} 

void  expression_tuple(tuple *v13492,OID v11276)
{ (*Generate.bag_expression)(Generate.PRODUCER->value,
    _oid_(Kernel._tuple),
    _oid_(v13492),
    _oid_(Kernel._void),
    v11276);
  } 

void  expression_List(List *v13492,OID v11276)
{ GC_BIND;
  { OID  v12102;
    { if (((v13492->of == (NULL)) ? CTRUE : CFALSE) != CTRUE)
       v12102 = _oid_(v13492->of);
      else v12102 = _oid_(Kernel._void);
        GC_OID(v12102);} 
    (*Generate.bag_expression)(Generate.PRODUCER->value,
      _oid_(Kernel._list),
      GC_OID(_oid_(v13492->args)),
      v12102,
      v11276);
    } 
  GC_UNBIND;} 

void  expression_list(list *v13492,OID v11276)
{ GC_BIND;
  if ((v13492->length == 0) && 
      (equal(_oid_(of_bag(v13492)),_oid_(Kernel.emptySet)) == CTRUE))
   princ_string(CSTRING("Kernel.nil"));
  else (*Generate.bag_expression)(Generate.PRODUCER->value,
      _oid_(Kernel._list),
      _oid_(v13492),
      GC_OID(_oid_(of_bag(v13492))),
      v11276);
    GC_UNBIND;} 

void  expression_Call2(Call *v13492,OID v11276)
{ (*Generate.inline_exp)(Generate.PRODUCER->value,
    _oid_(v13492),
    v11276);
  } 

void  expression_Call_method12(Call_method1 *v13492,OID v11276)
{ (*Generate.inline_exp)(Generate.PRODUCER->value,
    _oid_(v13492),
    v11276);
  } 

void  expression_Call_method22(Call_method2 *v13492,OID v11276)
{ (*Generate.inline_exp)(Generate.PRODUCER->value,
    _oid_(v13492),
    v11276);
  } 

void  expression_Call_method2(Call_method *v13492,OID v11276)
{ (*Generate.inline_exp)(Generate.PRODUCER->value,
    _oid_(v13492),
    v11276);
  } 

void  bexpression_any(OID v13492,OID v11276)
{ if (INHERIT(OWNER(v13492),Language._Assign))
   { princ_string(CSTRING("("));
    expression_Assign(OBJECT(Assign,v13492),v11276);
    princ_string(CSTRING(")"));
    } 
  else if (INHERIT(OWNER(v13492),Optimize._to_C))
   { princ_string(CSTRING("("));
    (*Generate.expression)(v13492,
      v11276);
    princ_string(CSTRING(")"));
    } 
  else if (INHERIT(OWNER(v13492),Kernel._integer))
   { if (v13492 < 0)
     { princ_string(CSTRING("("));
      expression_integer(v13492,v11276);
      princ_string(CSTRING(")"));
      } 
    else expression_integer(v13492,v11276);
      } 
  else if (Kernel._float == OWNER(v13492))
   { if (float_v(v13492) < 0.0)
     { princ_string(CSTRING("("));
      expression_float(float_v(v13492),v11276);
      princ_string(CSTRING(")"));
      } 
    else expression_float(float_v(v13492),v11276);
      } 
  else (*Generate.expression)(v13492,
      v11276);
    } 

void  expression_If(If *v13492,OID v11276)
{ GC_BIND;
  princ_string(CSTRING("("));
  (*Optimize.bool_exp)(GC_OID(v13492->test),
    Kernel.ctrue,
    v11276);
  princ_string(CSTRING(" ?"));
  (Optimize.OPT->level = (Optimize.OPT->level+1));
  breakline_void();
  (*Generate.expression)(GC_OID(v13492->arg),
    v11276);
  princ_string(CSTRING(" :"));
  breakline_void();
  (*Generate.expression)(GC_OID(v13492->other),
    v11276);
  princ_string(CSTRING(" )"));
  (Optimize.OPT->level = (Optimize.OPT->level-1));
  GC_UNBIND;} 

void  expression_Assign(Assign *v13492,OID v11276)
{ GC_BIND;
  { OID  v5136 = v13492->arg;
    OID  v5138 = v13492->var;
    if ((INHERIT(OWNER(v5136),Language._Call_method2)) && ((_oid_(OBJECT(Call_method,v5136)->arg) == Generate._star_plus_integer_star->value) && 
        ((equal((*(OBJECT(Call_method,v5136)->args))[1],v13492->var) == CTRUE) && 
          ((*(OBJECT(Call_method,v5136)->args))[2] == 1))))
     { princ_string(CSTRING("++"));
      (*Generate.expression)(v5138,
        v11276);
      princ_string(CSTRING(""));
      } 
    else if ((boolean_I_any(v11276) == CTRUE) && 
        ((Optimize.OPT->loop_gc == CTRUE) && 
          (inner2outer_ask_any(v5136) == CTRUE)))
     { OID  v2397;
      { if (INHERIT(OWNER(v5136),Optimize._to_protect))
         v2397 = OBJECT(Compile_to_protect,v5136)->arg;
        else v2397 = v5136;
          GC_OID(v2397);} 
      (*Generate.gc_protection_exp)(Generate.PRODUCER->value,
        v5138,
        Kernel.ctrue,
        v2397,
        v11276);
      } 
    else (*Generate.exp_Assign)(Generate.PRODUCER->value,
        _oid_(v13492),
        v11276);
      } 
  GC_UNBIND;} 

void  expression_to_protect(Compile_to_protect *v13492,OID v11276)
{ (*Generate.exp_to_protect)(Generate.PRODUCER->value,
    _oid_(v13492),
    v11276);
  } 

void  expression_Gassign(Gassign *v13492,OID v11276)
{ (*Generate.gassign)(Generate.PRODUCER->value,
    _oid_(v13492),
    v11276);
  } 

void  expression_And(And *v13492,OID v11276)
{ GC_BIND;
  { ClaireBoolean * v5114 = ((v13492->args->length > 5) ? CTRUE : CFALSE);
    { OID gc_local;
      ITERATE(v5136);
      for (START(v13492->args); NEXT(v5136);)
      { princ_string(CSTRING("("));
        (*Optimize.bool_exp)(v5136,
          Kernel.ctrue,
          v11276);
        princ_string(CSTRING(" ? "));
        if (v5114 == CTRUE)
         breakline_void();
        } 
      } 
    expression_boolean(CTRUE,v11276);
    { OID gc_local;
      ITERATE(v5136);
      for (START(v13492->args); NEXT(v5136);)
      { princ_string(CSTRING(": "));
        expression_boolean(CFALSE,v11276);
        princ_string(CSTRING(")"));
        } 
      } 
    } 
  GC_UNBIND;} 

void  expression_Or(Or *v13492,OID v11276)
{ GC_BIND;
  { ClaireBoolean * v5114 = ((v13492->args->length > 5) ? CTRUE : CFALSE);
    { OID gc_local;
      ITERATE(v5136);
      for (START(v13492->args); NEXT(v5136);)
      { princ_string(CSTRING("("));
        (*Optimize.bool_exp)(v5136,
          Kernel.ctrue,
          v11276);
        princ_string(CSTRING(" ? "));
        expression_boolean(CTRUE,v11276);
        princ_string(CSTRING(" : "));
        if (v5114 == CTRUE)
         breakline_void();
        } 
      } 
    expression_boolean(CFALSE,v11276);
    { OID gc_local;
      ITERATE(v5136);
      for (START(v13492->args); NEXT(v5136);)
      princ_string(CSTRING(")"));
      } 
    } 
  GC_UNBIND;} 

void  expression_to_CL(Compile_to_CL *v13492,OID v11276)
{ GC_BIND;
  (*Generate.to_cl)(Generate.PRODUCER->value,
    v13492->arg,
    _oid_(v13492->set_arg),
    v11276);
  GC_UNBIND;} 

void  expression_to_C(Compile_to_C *v13492,OID v11276)
{ GC_BIND;
  (*Generate.to_c)(Generate.PRODUCER->value,
    v13492->arg,
    _oid_(v13492->set_arg),
    v11276);
  GC_UNBIND;} 

void  expression_C_cast(Compile_C_cast *v13492,OID v11276)
{ (*Kernel.cast_I)(Generate.PRODUCER->value,
    _oid_(v13492),
    v11276);
  } 

void  expression_Call_slot(Call_slot *v13492,OID v11276)
{ (*Generate.call_slot)(Generate.PRODUCER->value,
    _oid_(v13492),
    v11276);
  } 

void  expression_Call_table(Call_table *v13492,OID v11276)
{ (*Generate.call_table)(Generate.PRODUCER->value,
    _oid_(v13492),
    v11276);
  } 

void  expression_Call_array(Call_array *v13492,OID v11276)
{ (*Generate.call_array)(Generate.PRODUCER->value,
    _oid_(v13492),
    v11276);
  } 

void  expression_Update(Update *v13492,OID v11276)
{ (*Generate.update)(Generate.PRODUCER->value,
    _oid_(v13492),
    v11276);
  } 

void  sign_equal_boolean(ClaireBoolean *v13492)
{ if (v13492 == CTRUE)
   princ_string(CSTRING("=="));
  else princ_string(CSTRING("!="));
    } 

void  sign_or_boolean(ClaireBoolean *v13492)
{ if (v13492 == CTRUE)
   princ_string(CSTRING("||"));
  else princ_string(CSTRING("&&"));
    } 

void  bool_exp_any_Generate(OID v13492,ClaireBoolean *v15827,OID v11276)
{ any_bool_exp_any(v13492,v15827,v11276,not_any(_oid_(((INHERIT(OWNER(v13492),Core._global_variable)) ? ((nativeVar_ask_global_variable(OBJECT(global_variable,v13492)) != CTRUE) ? CTRUE: CFALSE): CFALSE))));
  } 

void  any_bool_exp_any(OID v13492,ClaireBoolean *v15827,OID v11276,ClaireBoolean *v8358)
{ princ_string(CSTRING("("));
  bexpression_any(v13492,v11276);
  princ_string(CSTRING(" "));
  if (v15827 != CTRUE)
   princ_string(CSTRING("!="));
  else princ_string(CSTRING("=="));
    princ_string(CSTRING(" "));
  if (v8358 != CTRUE)
   (*Generate.to_cl)(Generate.PRODUCER->value,
    Kernel.ctrue,
    _oid_(Kernel._boolean),
    v11276);
  else expression_boolean(CTRUE,v11276);
    princ_string(CSTRING(")"));
  } 

void  bool_exp_to_CL_Generate(Compile_to_CL *v13492,ClaireBoolean *v15827,OID v11276)
{ GC_BIND;
  (*Optimize.bool_exp)(v13492->arg,
    _oid_(v15827),
    v11276);
  GC_UNBIND;} 

void  bool_exp_If_Generate(If *v13492,ClaireBoolean *v15827,OID v11276)
{ GC_BIND;
  if (boolean_I_any(v13492->other) == CTRUE)
   { princ_string(CSTRING("("));
    (*Optimize.bool_exp)(v13492->test,
      Kernel.ctrue,
      v11276);
    princ_string(CSTRING(" ? "));
    (*Optimize.bool_exp)(v13492->arg,
      _oid_(v15827),
      v11276);
    princ_string(CSTRING(" : "));
    (*Optimize.bool_exp)(v13492->other,
      _oid_(v15827),
      v11276);
    princ_string(CSTRING(")"));
    } 
  else { princ_string(CSTRING("("));
      (*Optimize.bool_exp)(v13492->test,
        _oid_(v15827),
        v11276);
      princ_string(CSTRING(" "));
      sign_or_boolean(not_any(_oid_(v15827)));
      princ_string(CSTRING(" "));
      (*Optimize.bool_exp)(v13492->arg,
        _oid_(v15827),
        v11276);
      princ_string(CSTRING(")"));
      } 
    GC_UNBIND;} 

void  bool_exp_And_Generate(And *v13492,ClaireBoolean *v15827,OID v11276)
{ GC_BIND;
  { list * v5124 = GC_OBJECT(list,v13492->args);
    Cint  v5125 = v5124->length;
    Cint  v5126 = 0;
    Cint  v9295 = Optimize.OPT->level;
    (Optimize.OPT->level = (Optimize.OPT->level+1));
    { OID gc_local;
      ITERATE(v5136);
      for (START(v5124); NEXT(v5136);)
      { ++v5126;
        if (v5126 == v5125)
         (*Optimize.bool_exp)(v5136,
          _oid_(v15827),
          v11276);
        else { princ_string(CSTRING("("));
            (*Optimize.bool_exp)(v5136,
              _oid_(v15827),
              v11276);
            princ_string(CSTRING(" "));
            sign_or_boolean(not_any(_oid_(v15827)));
            princ_string(CSTRING(" "));
            (Optimize.OPT->level = (Optimize.OPT->level+1));
            breakline_void();
            } 
          } 
      } 
    { Cint  v5136 = 2;
      Cint  v2562 = v5125;
      { OID gc_local;
        while ((v5136 <= v2562))
        { princ_string(CSTRING(")"));
          ++v5136;
          } 
        } 
      } 
    (Optimize.OPT->level = v9295);
    } 
  GC_UNBIND;} 

void  bool_exp_Or_Generate(Or *v13492,ClaireBoolean *v15827,OID v11276)
{ GC_BIND;
  { list * v5124 = GC_OBJECT(list,v13492->args);
    Cint  v5125 = v5124->length;
    Cint  v5126 = 0;
    Cint  v9295 = Optimize.OPT->level;
    (Optimize.OPT->level = (Optimize.OPT->level+1));
    { OID gc_local;
      ITERATE(v5136);
      for (START(v5124); NEXT(v5136);)
      { ++v5126;
        if (v5126 == v5125)
         (*Optimize.bool_exp)(v5136,
          _oid_(v15827),
          v11276);
        else { princ_string(CSTRING("("));
            (*Optimize.bool_exp)(v5136,
              _oid_(v15827),
              v11276);
            princ_string(CSTRING(" "));
            sign_or_boolean(v15827);
            princ_string(CSTRING(" "));
            (Optimize.OPT->level = (Optimize.OPT->level+1));
            breakline_void();
            } 
          } 
      } 
    { Cint  v5136 = 2;
      Cint  v2567 = v5125;
      { OID gc_local;
        while ((v5136 <= v2567))
        { princ_string(CSTRING(")"));
          ++v5136;
          } 
        } 
      } 
    (Optimize.OPT->level = v9295);
    } 
  GC_UNBIND;} 

void  bool_exp_Call_method1_Generate(Call_method1 *v13492,ClaireBoolean *v15827,OID v11276)
{ GC_BIND;
  { method * v5125 = v13492->arg;
    OID  v11096 = (*(v13492->args))[1];
    if (_oid_(v5125) == Generate._starnot_star->value)
     { if (INHERIT(OWNER(v11096),Optimize._to_CL))
       any_bool_exp_any(GC_OID((*Kernel.arg)(v11096)),not_any(_oid_(v15827)),v11276,CTRUE);
      else any_bool_exp_any(v11096,not_any(_oid_(v15827)),v11276,CFALSE);
        } 
    else if (_oid_(v5125) == Generate._starknown_star->value)
     (*Generate.equal_exp)(Generate.PRODUCER->value,
      v11096,
      _oid_(not_any(_oid_(v15827))),
      CNULL,
      v11276);
    else if (_oid_(v5125) == Generate._starunknown_star->value)
     (*Generate.equal_exp)(Generate.PRODUCER->value,
      v11096,
      _oid_(v15827),
      CNULL,
      v11276);
    else if (_inf_equal_type(v5125->range,Kernel._boolean) == CTRUE)
     { princ_string(CSTRING("("));
      expression_Call_method12(v13492,v11276);
      princ_string(CSTRING(" "));
      sign_equal_boolean(v15827);
      princ_string(CSTRING(" "));
      expression_boolean(CTRUE,v11276);
      princ_string(CSTRING(")"));
      } 
    else { OID v_rec;
        v_rec = _oid_(v13492);
        PUSH(v_rec);
        v_rec = _oid_(v15827);
        PUSH(v_rec);
        v_rec = v11276;
        PUSH(v_rec);
        Optimize.bool_exp->super(Kernel._any,3);} 
      } 
  GC_UNBIND;} 

void  bool_exp_Call_method2_Generate(Call_method2 *v13492,ClaireBoolean *v15827,OID v11276)
{ GC_BIND;
  { method * v5125 = v13492->arg;
    property * v5128 = v5125->selector;
    list * v12517 = GC_OBJECT(list,OBJECT(Generate_producer,Generate.PRODUCER->value)->open_comparators);
    OID  v11096 = (*(v13492->args))[1];
    OID  v11098 = (*(v13492->args))[2];
    if (v5128 == Core._I_equal)
     (*Generate.equal_exp)(Generate.PRODUCER->value,
      v11096,
      _oid_(not_any(_oid_(v15827))),
      v11098,
      Core.nil->value);
    else if (v5128 == Core.identical_ask)
     (*Generate.equal_exp)(Generate.PRODUCER->value,
      v11096,
      _oid_(v15827),
      v11098,
      Kernel.ctrue);
    else if (v5128 == Kernel._equal)
     (*Generate.equal_exp)(Generate.PRODUCER->value,
      v11096,
      _oid_(v15827),
      v11098,
      Core.nil->value);
    else if ((v12517->memq(_oid_(v5128)) == CTRUE) && 
        ((domain_I_restriction(v5125) == Kernel._integer) || 
            (domain_I_restriction(v5125) == Kernel._float)))
     { princ_string(CSTRING("("));
      (*Generate.expression)(v11096,
        v11276);
      princ_string(CSTRING(" "));
      if (v15827 == CTRUE)
       print_any(_oid_(v5128));
      else print_any((*(v12517))[(mod_integer((index_list(v12517,_oid_(v5128))+1),4)+1)]);
        princ_string(CSTRING(" "));
      (*Generate.expression)(v11098,
        v11276);
      princ_string(CSTRING(")"));
      } 
    else if (_oid_(v5125) == Generate._starnth_integer_star->value)
     { princ_string(CSTRING("("));
      if (v15827 != CTRUE)
       princ_string(CSTRING("!"));
      (*Generate.bitvector_exp)(Generate.PRODUCER->value,
        v11096,
        v11098,
        v11276);
      princ_string(CSTRING(")"));
      } 
    else if ((v5128 == Core.inherit_ask) && 
        (domain_I_restriction(v5125) == Kernel._class))
     { princ_string(CSTRING("("));
      if (v15827 != CTRUE)
       princ_string(CSTRING("!"));
      (*Generate.inherit_exp)(Generate.PRODUCER->value,
        v11096,
        v11098,
        v11276);
      princ_string(CSTRING(")"));
      } 
    else if (_inf_equal_type(v5125->range,Kernel._boolean) == CTRUE)
     { princ_string(CSTRING("("));
      expression_Call_method22(v13492,v11276);
      princ_string(CSTRING(" "));
      sign_equal_boolean(v15827);
      princ_string(CSTRING(" "));
      expression_boolean(CTRUE,v11276);
      princ_string(CSTRING(")"));
      } 
    else { OID v_rec;
        v_rec = _oid_(v13492);
        PUSH(v_rec);
        v_rec = _oid_(v15827);
        PUSH(v_rec);
        v_rec = v11276;
        PUSH(v_rec);
        Optimize.bool_exp->super(Kernel._any,3);} 
      } 
  GC_UNBIND;} 

ClaireBoolean * bool_exp_ask_any(OID v5136)
{ { ClaireBoolean *Result ;
    if (INHERIT(OWNER(v5136),Optimize._to_CL))
     Result = bool_exp_ask_any(OBJECT(Compile_to_CL,v5136)->arg);
    else if (INHERIT(OWNER(v5136),Language._Call_method))
     { property * v5128 = OBJECT(Call_method,v5136)->arg->selector;
      Result = (((OBJECT(Call_method,v5136)->arg->range == Kernel._boolean) && 
          ((v5128 == Kernel._equal) || 
              ((v5128 == Core._I_equal) || 
                ((v5128 == Kernel._sup) || 
                  ((v5128 == Kernel._sup_equal) || 
                    ((v5128 == Kernel._inf) || 
                      (v5128 == Kernel._inf_equal))))))) ? CTRUE : (((v5128 == Core.NOT) && 
          (bool_exp_ask_any((*(OBJECT(Call_method,v5136)->args))[1]) == CTRUE)) ? CTRUE : CFALSE));
      } 
    else Result = CFALSE;
      return (Result);} 
  } 

void  args_list_bag(bag *v13492,OID v11276,ClaireBoolean *v2734)
{ { ClaireBoolean * v3347 = CTRUE;
    if (v2734 == CTRUE)
     (Optimize.OPT->level = (Optimize.OPT->level+1));
    { ITERATE(v5136);
      for (START(v13492); NEXT(v5136);)
      if (v3347 == CTRUE)
       { (*Generate.expression)(v5136,
          v11276);
        v3347= CFALSE;
        } 
      else { princ_string(CSTRING(","));
          if (v2734 == CTRUE)
           breakline_void();
          (*Generate.expression)(v5136,
            v11276);
          princ_string(CSTRING(""));
          } 
        } 
    if (v2734 == CTRUE)
     (Optimize.OPT->level = (Optimize.OPT->level-1));
    } 
  } 

char * check_var_string(char *v13492,OID v5134,OID v11276)
{ { char *Result ;
    Result = (((equal(_string_(v13492),v5134) == CTRUE) || 
        (equal(_string_(v13492),v11276) == CTRUE)) ?
      append_string(v13492,CSTRING("1")) :
      v13492 );
    return (Result);} 
  } 

Variable * build_Variable_string(char *v5134,OID v5133)
{ return (Variable_I_symbol(symbol_I_string2(v5134),0,OBJECT(ClaireType,v5133)));} 

