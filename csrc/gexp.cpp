/***** CLAIRE Compilation of file /Users/ycaseau/claire/v3.5/src/compile/gexp.cl 
         [version 3.5.01 / safety 5] Sun Jul 24 08:43:47 2016 *****/

#include <claire.h>
#include <Kernel.h>
#include <Core.h>
#include <Language.h>
#include <Reader.h>
#include <Optimize.h>
#include <Generate.h>
ClaireBoolean * c_func_any(OID v107876)
{ GC_RESERVE(1);  // HOHO v3.0.55 optim !
  { ClaireBoolean *Result ;
    if (INHERIT(OWNER(v107876),Kernel._bag))
     { OID  v46200;
      { OID gc_local;
        ITERATE(v106848);
        v46200= Kernel.cfalse;
        for (START(OBJECT(bag,v107876)); NEXT(v106848);)
        if (c_func_any(v106848) != CTRUE)
         { v46200 = Kernel.ctrue;
          break;} 
        else ;} 
      Result = not_any(v46200);
      } 
    else if (INHERIT(OWNER(v107876),Language._Construct))
     { if (((INHERIT(OBJECT(ClaireObject,v107876)->isa,Language._Set)) || 
            (INHERIT(OBJECT(ClaireObject,v107876)->isa,Language._List))) || 
          (INHERIT(OBJECT(ClaireObject,v107876)->isa,Language._Tuple)))
       { ClaireBoolean *v_and;
        { v_and = ((OBJECT(Construct,v107876)->args->length < 15) ? CTRUE : CFALSE);
          if (v_and == CFALSE) Result =CFALSE; 
          else { { OID  v67342;
              { ClaireBoolean * v49194;{ OID  v69264;
                  { set * v49196;{ set * v53231 = set::empty(Kernel.emptySet);
                      { OID gc_local;
                        ITERATE(v106848);
                        bag *v106848_support;
                        v106848_support = GC_OBJECT(list,OBJECT(Construct,v107876)->args);
                        for (START(v106848_support); NEXT(v106848);)
                        if (c_func_any(v106848) != CTRUE)
                         v53231->addFast(v106848);
                        } 
                      v49196 = GC_OBJECT(set,v53231);
                      } 
                    
                    v69264=_oid_(v49196);} 
                  v49194 = boolean_I_any(v69264);
                  } 
                
                v67342=_oid_(v49194);} 
              v_and = ((v67342 != Kernel.ctrue) ? CTRUE : CFALSE);
              } 
            if (v_and == CFALSE) Result =CFALSE; 
            else Result = CTRUE;} 
          } 
        } 
      else Result = CFALSE;
        } 
    else if (INHERIT(OWNER(v107876),Language._If))
     { ClaireBoolean *v_and;
      { v_and = c_func_any(GC_OID(OBJECT(If,v107876)->test));
        if (v_and == CFALSE) Result =CFALSE; 
        else { v_and = c_func_any(GC_OID(OBJECT(If,v107876)->arg));
          if (v_and == CFALSE) Result =CFALSE; 
          else { v_and = c_func_any(GC_OID(OBJECT(If,v107876)->other));
            if (v_and == CFALSE) Result =CFALSE; 
            else { v_and = stupid_t_any2(GC_OID(OBJECT(If,v107876)->arg),GC_OID(OBJECT(If,v107876)->other));
              if (v_and == CFALSE) Result =CFALSE; 
              else { { Cint  v106838 = 4;
                  OID  v106848 = GC_OID(OBJECT(If,v107876)->other);
                  { OID v75650;{ OID gc_local;
                      v75650= _oid_(CFALSE);
                      while ((v106838 > 0))
                      { GC_LOOP;
                        if (INHERIT(OWNER(v106848),Language._If))
                         { GC__OID(v106848 = OBJECT(If,v106848)->other, 1);
                          v106838= (v106838-1);
                          } 
                        else { v75650 = Kernel.ctrue;
                            break;} 
                          GC_UNLOOP;} 
                      } 
                    
                    v_and=OBJECT(ClaireBoolean,v75650);} 
                  } 
                if (v_and == CFALSE) Result =CFALSE; 
                else Result = CTRUE;} 
              } 
            } 
          } 
        } 
      } 
    else if (INHERIT(OWNER(v107876),Language._Assign))
     Result = c_func_any(GC_OID(OBJECT(Assign,v107876)->arg));
    else if (INHERIT(OWNER(v107876),Language._Gassign))
     Result = c_func_any(GC_OID(OBJECT(Gassign,v107876)->arg));
    else if (INHERIT(OWNER(v107876),Optimize._to_protect))
     Result = c_func_any(GC_OID(OBJECT(Compile_to_protect,v107876)->arg));
    else if (INHERIT(OWNER(v107876),Language._And))
     Result = c_func_any(GC_OID(_oid_(OBJECT(And,v107876)->args)));
    else if (INHERIT(OWNER(v107876),Language._Or))
     Result = c_func_any(GC_OID(_oid_(OBJECT(Or,v107876)->args)));
    else if (INHERIT(OWNER(v107876),Language._Call))
     Result = c_func_any(GC_OID(_oid_(OBJECT(Call,v107876)->args)));
    else if (INHERIT(OWNER(v107876),Language._Call_method))
     Result = ((c_func_any(GC_OID(_oid_(OBJECT(Call_method,v107876)->args))) == CTRUE) ? ((_oid_(OBJECT(Call_method,v107876)->arg) != Generate._starclose_exception_star->value) ? CTRUE: CFALSE): CFALSE);
    else if (INHERIT(OWNER(v107876),Language._Call_slot))
     Result = c_func_any(GC_OID(OBJECT(Call_slot,v107876)->arg));
    else if (INHERIT(OWNER(v107876),Language._Call_table))
     Result = c_func_any(GC_OID(OBJECT(Call_table,v107876)->arg));
    else if (INHERIT(OWNER(v107876),Language._Call_array))
     Result = c_func_any(GC_OID(OBJECT(Call_array,v107876)->arg));
    else Result = ((INHERIT(OWNER(v107876),Language._Update)) ?
      ((c_func_any(GC_OID(OBJECT(Update,v107876)->value)) == CTRUE) ? ((c_func_any(GC_OID(OBJECT(Update,v107876)->arg)) == CTRUE) ? CTRUE: CFALSE): CFALSE) :
      ((INHERIT(OWNER(v107876),Language._Cast)) ?
        c_func_any(GC_OID(OBJECT(Cast,v107876)->arg)) :
        ((INHERIT(OWNER(v107876),Optimize._to_C)) ?
          c_func_any(GC_OID(OBJECT(Compile_to_C,v107876)->arg)) :
          ((INHERIT(OWNER(v107876),Optimize._to_CL)) ?
            c_func_any(GC_OID(OBJECT(Compile_to_CL,v107876)->arg)) :
            ((INHERIT(OWNER(v107876),Kernel._thing)) ? CTRUE : 
            ((INHERIT(OWNER(v107876),Kernel._integer)) ? CTRUE : 
            ((Kernel._string == OWNER(v107876)) ? CTRUE : 
            ((INHERIT(OWNER(v107876),Kernel._char)) ? CTRUE : 
            ((Kernel._float == OWNER(v107876)) ? CTRUE : 
            ((INHERIT(OWNER(v107876),Language._Variable)) ? CTRUE : 
            ((INHERIT(OWNER(v107876),Core._global_variable)) ? CTRUE : 
            ((INHERIT(OWNER(v107876),Kernel._function)) ? CTRUE : 
            ((INHERIT(OWNER(v107876),Kernel._symbol)) ? CTRUE : 
            ((v107876 == CNULL) ? CTRUE : 
            ((Kernel._boolean == OWNER(v107876)) ? CTRUE : 
            ((INHERIT(OWNER(v107876),Kernel._class)) ? CTRUE : 
            ((INHERIT(OWNER(v107876),Kernel._environment)) ? CTRUE : 
            CFALSE))))))))))))) ) ) ) );
    GC_UNBIND; return (Result);} 
  } 

void  expression_thing(thing *v107876,OID v40124)
{ (*Generate.produce)(Generate.PRODUCER->value,
    _oid_(v107876));
  } 

void  expression_integer(Cint v107876,OID v40124)
{ princ_integer(v107876);
  } 

void  expression_any(OID v107876,OID v40124)
{ (*Generate.produce)(Generate.PRODUCER->value,
    v107876);
  } 

void  expression_string(char *v107876,OID v40124)
{ (*Generate.produce)(Generate.PRODUCER->value,
    _string_(v107876));
  } 

void  expression_float_(OID v81906,OID v81907)
{ expression_float(float_v(v81906),v81907);} 

void  expression_float(double v107876,OID v40124)
{ princ_float(v107876);
  } 

void  expression_boolean(ClaireBoolean *v107876,OID v40124)
{ (*Generate.produce)(Generate.PRODUCER->value,
    _oid_(v107876));
  } 

void  expression_environment(ClaireEnvironment *v107876,OID v40124)
{ (*Generate.produce)(Generate.PRODUCER->value,
    _oid_(v107876));
  } 

void  expression_Variable(Variable *v107876,OID v40124)
{ (*Language.ident)(Generate.PRODUCER->value,
    _oid_(v107876));
  } 

void  expression_global_variable(global_variable *v107876,OID v40124)
{ (*Generate.produce)(Generate.PRODUCER->value,
    _oid_(v107876));
  } 

void  expression_Set(Set *v107876,OID v40124)
{ GC_BIND;
  { OID  v73108;
    { if (((v107876->of == (NULL)) ? CTRUE : CFALSE) != CTRUE)
       v73108 = _oid_(v107876->of);
      else v73108 = _oid_(Kernel._void);
        GC_OID(v73108);} 
    (*Generate.bag_expression)(Generate.PRODUCER->value,
      _oid_(Kernel._set),
      GC_OID(_oid_(v107876->args)),
      v73108,
      v40124);
    } 
  GC_UNBIND;} 

void  expression_set2(set *v107876,OID v40124)
{ GC_BIND;
  if ((v107876->length == 0) && 
      (equal(_oid_(of_bag(v107876)),_oid_(Kernel.emptySet)) == CTRUE))
   princ_string(CSTRING("Kernel.emptySet"));
  else (*Generate.bag_expression)(Generate.PRODUCER->value,
      _oid_(Kernel._set),
      _oid_(v107876),
      GC_OID(_oid_(of_bag(v107876))),
      v40124);
    GC_UNBIND;} 

void  expression_Tuple(Tuple *v107876,OID v40124)
{ GC_BIND;
  (*Generate.bag_expression)(Generate.PRODUCER->value,
    _oid_(Kernel._tuple),
    GC_OID(_oid_(v107876->args)),
    _oid_(Kernel._void),
    v40124);
  GC_UNBIND;} 

void  expression_tuple(tuple *v107876,OID v40124)
{ (*Generate.bag_expression)(Generate.PRODUCER->value,
    _oid_(Kernel._tuple),
    _oid_(v107876),
    _oid_(Kernel._void),
    v40124);
  } 

void  expression_List(List *v107876,OID v40124)
{ GC_BIND;
  { OID  v74069;
    { if (((v107876->of == (NULL)) ? CTRUE : CFALSE) != CTRUE)
       v74069 = _oid_(v107876->of);
      else v74069 = _oid_(Kernel._void);
        GC_OID(v74069);} 
    (*Generate.bag_expression)(Generate.PRODUCER->value,
      _oid_(Kernel._list),
      GC_OID(_oid_(v107876->args)),
      v74069,
      v40124);
    } 
  GC_UNBIND;} 

void  expression_list(list *v107876,OID v40124)
{ GC_BIND;
  if ((v107876->length == 0) && 
      (equal(_oid_(of_bag(v107876)),_oid_(Kernel.emptySet)) == CTRUE))
   princ_string(CSTRING("Kernel.nil"));
  else (*Generate.bag_expression)(Generate.PRODUCER->value,
      _oid_(Kernel._list),
      _oid_(v107876),
      GC_OID(_oid_(of_bag(v107876))),
      v40124);
    GC_UNBIND;} 

void  expression_Call2(Call *v107876,OID v40124)
{ (*Generate.inline_exp)(Generate.PRODUCER->value,
    _oid_(v107876),
    v40124);
  } 

void  expression_Call_method12(Call_method1 *v107876,OID v40124)
{ (*Generate.inline_exp)(Generate.PRODUCER->value,
    _oid_(v107876),
    v40124);
  } 

void  expression_Call_method22(Call_method2 *v107876,OID v40124)
{ (*Generate.inline_exp)(Generate.PRODUCER->value,
    _oid_(v107876),
    v40124);
  } 

void  expression_Call_method2(Call_method *v107876,OID v40124)
{ (*Generate.inline_exp)(Generate.PRODUCER->value,
    _oid_(v107876),
    v40124);
  } 

void  bexpression_any(OID v107876,OID v40124)
{ if (INHERIT(OWNER(v107876),Language._Assign))
   { princ_string(CSTRING("("));
    expression_Assign(OBJECT(Assign,v107876),v40124);
    princ_string(CSTRING(")"));
    } 
  else if (INHERIT(OWNER(v107876),Optimize._to_C))
   { princ_string(CSTRING("("));
    (*Generate.expression)(v107876,
      v40124);
    princ_string(CSTRING(")"));
    } 
  else if (INHERIT(OWNER(v107876),Kernel._integer))
   { if (v107876 < 0)
     { princ_string(CSTRING("("));
      expression_integer(v107876,v40124);
      princ_string(CSTRING(")"));
      } 
    else expression_integer(v107876,v40124);
      } 
  else if (Kernel._float == OWNER(v107876))
   { if (float_v(v107876) < 0.0)
     { princ_string(CSTRING("("));
      expression_float(float_v(v107876),v40124);
      princ_string(CSTRING(")"));
      } 
    else expression_float(float_v(v107876),v40124);
      } 
  else (*Generate.expression)(v107876,
      v40124);
    } 

void  expression_If(If *v107876,OID v40124)
{ GC_BIND;
  princ_string(CSTRING("("));
  (*Optimize.bool_exp)(GC_OID(v107876->test),
    Kernel.ctrue,
    v40124);
  princ_string(CSTRING(" ?"));
  (Optimize.OPT->level = (Optimize.OPT->level+1));
  breakline_void();
  (*Generate.expression)(GC_OID(v107876->arg),
    v40124);
  princ_string(CSTRING(" :"));
  breakline_void();
  (*Generate.expression)(GC_OID(v107876->other),
    v40124);
  princ_string(CSTRING(" )"));
  (Optimize.OPT->level = (Optimize.OPT->level-1));
  GC_UNBIND;} 

void  expression_Assign(Assign *v107876,OID v40124)
{ GC_BIND;
  { OID  v106848 = v107876->arg;
    OID  v106846 = v107876->var;
    if ((INHERIT(OWNER(v106848),Language._Call_method2)) && ((_oid_(OBJECT(Call_method,v106848)->arg) == Generate._star_plus_integer_star->value) && 
        ((equal((*(OBJECT(Call_method,v106848)->args))[1],v107876->var) == CTRUE) && 
          ((*(OBJECT(Call_method,v106848)->args))[2] == 1))))
     { princ_string(CSTRING("++"));
      (*Generate.expression)(v106846,
        v40124);
      princ_string(CSTRING(""));
      } 
    else if ((boolean_I_any(v40124) == CTRUE) && 
        ((Optimize.OPT->loop_gc == CTRUE) && 
          (inner2outer_ask_any(v106848) == CTRUE)))
     { OID  v97133;
      { if (INHERIT(OWNER(v106848),Optimize._to_protect))
         v97133 = OBJECT(Compile_to_protect,v106848)->arg;
        else v97133 = v106848;
          GC_OID(v97133);} 
      (*Generate.gc_protection_exp)(Generate.PRODUCER->value,
        v106846,
        Kernel.ctrue,
        v97133,
        v40124);
      } 
    else (*Generate.exp_Assign)(Generate.PRODUCER->value,
        _oid_(v107876),
        v40124);
      } 
  GC_UNBIND;} 

void  expression_to_protect(Compile_to_protect *v107876,OID v40124)
{ (*Generate.exp_to_protect)(Generate.PRODUCER->value,
    _oid_(v107876),
    v40124);
  } 

void  expression_Gassign(Gassign *v107876,OID v40124)
{ (*Generate.gassign)(Generate.PRODUCER->value,
    _oid_(v107876),
    v40124);
  } 

void  expression_And(And *v107876,OID v40124)
{ GC_BIND;
  { ClaireBoolean * v106826 = ((v107876->args->length > 5) ? CTRUE : CFALSE);
    { OID gc_local;
      ITERATE(v106848);
      for (START(v107876->args); NEXT(v106848);)
      { princ_string(CSTRING("("));
        (*Optimize.bool_exp)(v106848,
          Kernel.ctrue,
          v40124);
        princ_string(CSTRING(" ? "));
        if (v106826 == CTRUE)
         breakline_void();
        } 
      } 
    expression_boolean(CTRUE,v40124);
    { OID gc_local;
      ITERATE(v106848);
      for (START(v107876->args); NEXT(v106848);)
      { princ_string(CSTRING(": "));
        expression_boolean(CFALSE,v40124);
        princ_string(CSTRING(")"));
        } 
      } 
    } 
  GC_UNBIND;} 

void  expression_Or(Or *v107876,OID v40124)
{ GC_BIND;
  { ClaireBoolean * v106826 = ((v107876->args->length > 5) ? CTRUE : CFALSE);
    { OID gc_local;
      ITERATE(v106848);
      for (START(v107876->args); NEXT(v106848);)
      { princ_string(CSTRING("("));
        (*Optimize.bool_exp)(v106848,
          Kernel.ctrue,
          v40124);
        princ_string(CSTRING(" ? "));
        expression_boolean(CTRUE,v40124);
        princ_string(CSTRING(" : "));
        if (v106826 == CTRUE)
         breakline_void();
        } 
      } 
    expression_boolean(CFALSE,v40124);
    { OID gc_local;
      ITERATE(v106848);
      for (START(v107876->args); NEXT(v106848);)
      princ_string(CSTRING(")"));
      } 
    } 
  GC_UNBIND;} 

void  expression_to_CL(Compile_to_CL *v107876,OID v40124)
{ GC_BIND;
  (*Generate.to_cl)(Generate.PRODUCER->value,
    v107876->arg,
    _oid_(v107876->set_arg),
    v40124);
  GC_UNBIND;} 

void  expression_to_C(Compile_to_C *v107876,OID v40124)
{ GC_BIND;
  (*Generate.to_c)(Generate.PRODUCER->value,
    v107876->arg,
    _oid_(v107876->set_arg),
    v40124);
  GC_UNBIND;} 

void  expression_C_cast(Compile_C_cast *v107876,OID v40124)
{ (*Kernel.cast_I)(Generate.PRODUCER->value,
    _oid_(v107876),
    v40124);
  } 

void  expression_Call_slot(Call_slot *v107876,OID v40124)
{ (*Generate.call_slot)(Generate.PRODUCER->value,
    _oid_(v107876),
    v40124);
  } 

void  expression_Call_table(Call_table *v107876,OID v40124)
{ (*Generate.call_table)(Generate.PRODUCER->value,
    _oid_(v107876),
    v40124);
  } 

void  expression_Call_array(Call_array *v107876,OID v40124)
{ (*Generate.call_array)(Generate.PRODUCER->value,
    _oid_(v107876),
    v40124);
  } 

void  expression_Update(Update *v107876,OID v40124)
{ (*Generate.update)(Generate.PRODUCER->value,
    _oid_(v107876),
    v40124);
  } 

void  sign_equal_boolean(ClaireBoolean *v107876)
{ if (v107876 == CTRUE)
   princ_string(CSTRING("=="));
  else princ_string(CSTRING("!="));
    } 

void  sign_or_boolean(ClaireBoolean *v107876)
{ if (v107876 == CTRUE)
   princ_string(CSTRING("||"));
  else princ_string(CSTRING("&&"));
    } 

void  bool_exp_any_Generate(OID v107876,ClaireBoolean *v28291,OID v40124)
{ any_bool_exp_any(v107876,v28291,v40124,not_any(_oid_(((INHERIT(OWNER(v107876),Core._global_variable)) ? ((nativeVar_ask_global_variable(OBJECT(global_variable,v107876)) != CTRUE) ? CTRUE: CFALSE): CFALSE))));
  } 

void  any_bool_exp_any(OID v107876,ClaireBoolean *v28291,OID v40124,ClaireBoolean *v86358)
{ princ_string(CSTRING("("));
  bexpression_any(v107876,v40124);
  princ_string(CSTRING(" "));
  if (v28291 != CTRUE)
   princ_string(CSTRING("!="));
  else princ_string(CSTRING("=="));
    princ_string(CSTRING(" "));
  if (v86358 != CTRUE)
   (*Generate.to_cl)(Generate.PRODUCER->value,
    Kernel.ctrue,
    _oid_(Kernel._boolean),
    v40124);
  else expression_boolean(CTRUE,v40124);
    princ_string(CSTRING(")"));
  } 

void  bool_exp_to_CL_Generate(Compile_to_CL *v107876,ClaireBoolean *v28291,OID v40124)
{ GC_BIND;
  (*Optimize.bool_exp)(v107876->arg,
    _oid_(v28291),
    v40124);
  GC_UNBIND;} 

void  bool_exp_If_Generate(If *v107876,ClaireBoolean *v28291,OID v40124)
{ GC_BIND;
  if (boolean_I_any(v107876->other) == CTRUE)
   { princ_string(CSTRING("("));
    (*Optimize.bool_exp)(v107876->test,
      Kernel.ctrue,
      v40124);
    princ_string(CSTRING(" ? "));
    (*Optimize.bool_exp)(v107876->arg,
      _oid_(v28291),
      v40124);
    princ_string(CSTRING(" : "));
    (*Optimize.bool_exp)(v107876->other,
      _oid_(v28291),
      v40124);
    princ_string(CSTRING(")"));
    } 
  else { princ_string(CSTRING("("));
      (*Optimize.bool_exp)(v107876->test,
        _oid_(v28291),
        v40124);
      princ_string(CSTRING(" "));
      sign_or_boolean(not_any(_oid_(v28291)));
      princ_string(CSTRING(" "));
      (*Optimize.bool_exp)(v107876->arg,
        _oid_(v28291),
        v40124);
      princ_string(CSTRING(")"));
      } 
    GC_UNBIND;} 

void  bool_exp_And_Generate(And *v107876,ClaireBoolean *v28291,OID v40124)
{ GC_BIND;
  { list * v106836 = GC_OBJECT(list,v107876->args);
    Cint  v106837 = v106836->length;
    Cint  v106838 = 0;
    Cint  v33023 = Optimize.OPT->level;
    (Optimize.OPT->level = (Optimize.OPT->level+1));
    { OID gc_local;
      ITERATE(v106848);
      for (START(v106836); NEXT(v106848);)
      { ++v106838;
        if (v106838 == v106837)
         (*Optimize.bool_exp)(v106848,
          _oid_(v28291),
          v40124);
        else { princ_string(CSTRING("("));
            (*Optimize.bool_exp)(v106848,
              _oid_(v28291),
              v40124);
            princ_string(CSTRING(" "));
            sign_or_boolean(not_any(_oid_(v28291)));
            princ_string(CSTRING(" "));
            (Optimize.OPT->level = (Optimize.OPT->level+1));
            breakline_void();
            } 
          } 
      } 
    { Cint  v106848 = 2;
      Cint  v81936 = v106837;
      { OID gc_local;
        while ((v106848 <= v81936))
        { princ_string(CSTRING(")"));
          ++v106848;
          } 
        } 
      } 
    (Optimize.OPT->level = v33023);
    } 
  GC_UNBIND;} 

void  bool_exp_Or_Generate(Or *v107876,ClaireBoolean *v28291,OID v40124)
{ GC_BIND;
  { list * v106836 = GC_OBJECT(list,v107876->args);
    Cint  v106837 = v106836->length;
    Cint  v106838 = 0;
    Cint  v33023 = Optimize.OPT->level;
    (Optimize.OPT->level = (Optimize.OPT->level+1));
    { OID gc_local;
      ITERATE(v106848);
      for (START(v106836); NEXT(v106848);)
      { ++v106838;
        if (v106838 == v106837)
         (*Optimize.bool_exp)(v106848,
          _oid_(v28291),
          v40124);
        else { princ_string(CSTRING("("));
            (*Optimize.bool_exp)(v106848,
              _oid_(v28291),
              v40124);
            princ_string(CSTRING(" "));
            sign_or_boolean(v28291);
            princ_string(CSTRING(" "));
            (Optimize.OPT->level = (Optimize.OPT->level+1));
            breakline_void();
            } 
          } 
      } 
    { Cint  v106848 = 2;
      Cint  v81939 = v106837;
      { OID gc_local;
        while ((v106848 <= v81939))
        { princ_string(CSTRING(")"));
          ++v106848;
          } 
        } 
      } 
    (Optimize.OPT->level = v33023);
    } 
  GC_UNBIND;} 

void  bool_exp_Call_method1_Generate(Call_method1 *v107876,ClaireBoolean *v28291,OID v40124)
{ GC_BIND;
  { method * v106837 = v107876->arg;
    OID  v34825 = (*(v107876->args))[1];
    if (_oid_(v106837) == Generate._starnot_star->value)
     { if (INHERIT(OWNER(v34825),Optimize._to_CL))
       any_bool_exp_any(GC_OID((*Kernel.arg)(v34825)),not_any(_oid_(v28291)),v40124,CTRUE);
      else any_bool_exp_any(v34825,not_any(_oid_(v28291)),v40124,CFALSE);
        } 
    else if (_oid_(v106837) == Generate._starknown_star->value)
     (*Generate.equal_exp)(Generate.PRODUCER->value,
      v34825,
      _oid_(not_any(_oid_(v28291))),
      CNULL,
      v40124);
    else if (_oid_(v106837) == Generate._starunknown_star->value)
     (*Generate.equal_exp)(Generate.PRODUCER->value,
      v34825,
      _oid_(v28291),
      CNULL,
      v40124);
    else if (_inf_equal_type(v106837->range,Kernel._boolean) == CTRUE)
     { princ_string(CSTRING("("));
      expression_Call_method12(v107876,v40124);
      princ_string(CSTRING(" "));
      sign_equal_boolean(v28291);
      princ_string(CSTRING(" "));
      expression_boolean(CTRUE,v40124);
      princ_string(CSTRING(")"));
      } 
    else { OID v_rec;
        v_rec = _oid_(v107876);
        PUSH(v_rec);
        v_rec = _oid_(v28291);
        PUSH(v_rec);
        v_rec = v40124;
        PUSH(v_rec);
        Optimize.bool_exp->super(Kernel._any,3);} 
      } 
  GC_UNBIND;} 

void  bool_exp_Call_method2_Generate(Call_method2 *v107876,ClaireBoolean *v28291,OID v40124)
{ GC_BIND;
  { method * v106837 = v107876->arg;
    property * v106840 = v106837->selector;
    list * v43573 = GC_OBJECT(list,OBJECT(Generate_producer,Generate.PRODUCER->value)->open_comparators);
    OID  v34825 = (*(v107876->args))[1];
    OID  v34826 = (*(v107876->args))[2];
    if (v106840 == Core._I_equal)
     (*Generate.equal_exp)(Generate.PRODUCER->value,
      v34825,
      _oid_(not_any(_oid_(v28291))),
      v34826,
      Core.nil->value);
    else if (v106840 == Core.identical_ask)
     (*Generate.equal_exp)(Generate.PRODUCER->value,
      v34825,
      _oid_(v28291),
      v34826,
      Kernel.ctrue);
    else if (v106840 == Kernel._equal)
     (*Generate.equal_exp)(Generate.PRODUCER->value,
      v34825,
      _oid_(v28291),
      v34826,
      Core.nil->value);
    else if ((v43573->memq(_oid_(v106840)) == CTRUE) && 
        ((domain_I_restriction(v106837) == Kernel._integer) || 
            (domain_I_restriction(v106837) == Kernel._float)))
     { princ_string(CSTRING("("));
      (*Generate.expression)(v34825,
        v40124);
      princ_string(CSTRING(" "));
      if (v28291 == CTRUE)
       print_any(_oid_(v106840));
      else print_any((*(v43573))[(mod_integer((index_list(v43573,_oid_(v106840))+1),4)+1)]);
        princ_string(CSTRING(" "));
      (*Generate.expression)(v34826,
        v40124);
      princ_string(CSTRING(")"));
      } 
    else if (_oid_(v106837) == Generate._starnth_integer_star->value)
     { princ_string(CSTRING("("));
      if (v28291 != CTRUE)
       princ_string(CSTRING("!"));
      (*Generate.bitvector_exp)(Generate.PRODUCER->value,
        v34825,
        v34826,
        v40124);
      princ_string(CSTRING(")"));
      } 
    else if ((v106840 == Core.inherit_ask) && 
        (domain_I_restriction(v106837) == Kernel._class))
     { princ_string(CSTRING("("));
      if (v28291 != CTRUE)
       princ_string(CSTRING("!"));
      (*Generate.inherit_exp)(Generate.PRODUCER->value,
        v34825,
        v34826,
        v40124);
      princ_string(CSTRING(")"));
      } 
    else if (_inf_equal_type(v106837->range,Kernel._boolean) == CTRUE)
     { princ_string(CSTRING("("));
      expression_Call_method22(v107876,v40124);
      princ_string(CSTRING(" "));
      sign_equal_boolean(v28291);
      princ_string(CSTRING(" "));
      expression_boolean(CTRUE,v40124);
      princ_string(CSTRING(")"));
      } 
    else { OID v_rec;
        v_rec = _oid_(v107876);
        PUSH(v_rec);
        v_rec = _oid_(v28291);
        PUSH(v_rec);
        v_rec = v40124;
        PUSH(v_rec);
        Optimize.bool_exp->super(Kernel._any,3);} 
      } 
  GC_UNBIND;} 

ClaireBoolean * bool_exp_ask_any(OID v106848)
{ { ClaireBoolean *Result ;
    if (INHERIT(OWNER(v106848),Optimize._to_CL))
     Result = bool_exp_ask_any(OBJECT(Compile_to_CL,v106848)->arg);
    else if (INHERIT(OWNER(v106848),Language._Call_method))
     { property * v106840 = OBJECT(Call_method,v106848)->arg->selector;
      Result = (((OBJECT(Call_method,v106848)->arg->range == Kernel._boolean) && 
          ((v106840 == Kernel._equal) || 
              ((v106840 == Core._I_equal) || 
                ((v106840 == Kernel._sup) || 
                  ((v106840 == Kernel._sup_equal) || 
                    ((v106840 == Kernel._inf) || 
                      (v106840 == Kernel._inf_equal))))))) ? CTRUE : (((v106840 == Core.NOT) && 
          (bool_exp_ask_any((*(OBJECT(Call_method,v106848)->args))[1]) == CTRUE)) ? CTRUE : CFALSE));
      } 
    else Result = CFALSE;
      return (Result);} 
  } 

void  args_list_bag(bag *v107876,OID v40124,ClaireBoolean *v33790)
{ { ClaireBoolean * v53699 = CTRUE;
    if (v33790 == CTRUE)
     (Optimize.OPT->level = (Optimize.OPT->level+1));
    { ITERATE(v106848);
      for (START(v107876); NEXT(v106848);)
      if (v53699 == CTRUE)
       { (*Generate.expression)(v106848,
          v40124);
        v53699= CFALSE;
        } 
      else { princ_string(CSTRING(","));
          if (v33790 == CTRUE)
           breakline_void();
          (*Generate.expression)(v106848,
            v40124);
          princ_string(CSTRING(""));
          } 
        } 
    if (v33790 == CTRUE)
     (Optimize.OPT->level = (Optimize.OPT->level-1));
    } 
  } 

char * check_var_string(char *v107876,OID v106843,OID v40124)
{ { char *Result ;
    Result = (((equal(_string_(v107876),v106843) == CTRUE) || 
        (equal(_string_(v107876),v40124) == CTRUE)) ?
      append_string(v107876,CSTRING("1")) :
      v107876 );
    return (Result);} 
  } 

Variable * build_Variable_string(char *v106843,OID v106844)
{ return (Variable_I_symbol(symbol_I_string2(v106843),0,OBJECT(ClaireType,v106844)));} 

