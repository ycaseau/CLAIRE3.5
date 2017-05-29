/***** CLAIRE Compilation of file /Users/ycaseau/claire/v3.5/src/compile/gstat.cl 
         [version 3.5.01 / safety 5] Sun Jul 24 08:43:47 2016 *****/

#include <claire.h>
#include <Kernel.h>
#include <Core.h>
#include <Language.h>
#include <Reader.h>
#include <Optimize.h>
#include <Generate.h>
list * unfold_args_list(list *v106836)
{ GC_BIND;
  { list *Result ;
    { list * v27185;
      { { list * v94048 = list::empty(Kernel.emptySet);
          { Cint  v106833 = 1;
            Cint  v81942 = v106836->length;
            { OID gc_local;
              while ((v106833 <= v81942))
              { if (c_func_any((*(v106836))[v106833]) != CTRUE)
                 v94048->addFast(v106833);
                ++v106833;
                } 
              } 
            } 
          v27185 = GC_OBJECT(list,v94048);
          } 
        GC_OBJECT(list,v27185);} 
      { bag *v_list; OID v_val;
        OID v106833,CLcount;
        v_list = v27185;
         Result = v_list->clone();
        for (CLcount= 1; CLcount <= v_list->length; CLcount++)
        { v106833 = (*(v_list))[CLcount];
          { Let * v109096 = ((Let *) GC_OBJECT(Let,new_object_class(Language._Let)));
            (v109096->var = Variable_I_symbol(append_symbol(gensym_void(),_string_(CSTRING("UU"))),0,GC_OBJECT(ClaireType,c_type_sort_any((*(v106836))[v106833]))));
            (v109096->value = (*(v106836))[v106833]);
            add_I_property(Kernel.instances,Language._Let,11,_oid_(v109096));
            v_val = _oid_(v109096);
            } 
          
          (*((list *) Result))[CLcount] = v_val;} 
        } 
      } 
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_sort_any(OID v106848)
{ { ClaireType *Result ;
    { ClaireClass * v106843 = OBJECT(ClaireClass,(*Optimize.c_sort)(v106848));
      ClaireClass * v106844 = stupid_t_any1(v106848);
      Result = ((v106843 == Kernel._void) ?
        osort_any((*Optimize.c_type)(v106848)) :
        ((boolean_I_any(sort_equal_class(osort_any(_oid_(v106844)),v106843)) == CTRUE) ?
          v106844 :
          v106843 ) );
      } 
    return (Result);} 
  } 

OID  unfold_arg_list(list *v106836,list *v35216,OID v106848)
{ { OID Result = 0;
    { Cint  v106833 = 1;
      Cint  v106834 = 0;
      Cint  v106837 = v106836->length;
      { ClaireBoolean * g0030I;
        { OID v75650;{ v75650= _oid_(CFALSE);
            while ((v106833 <= v106837))
            { if (c_func_any((*(v106836))[v106833]) != CTRUE)
               { ++v106834;
                if (equal((*(v106836))[v106833],v106848) == CTRUE)
                 { v75650 = Kernel.ctrue;
                  break;} 
                } 
              else if (equal((*(v106836))[v106833],v106848) == CTRUE)
               { v75650 = Kernel.cfalse;
                break;} 
              ++v106833;
              } 
            } 
          
          g0030I=OBJECT(ClaireBoolean,v75650);} 
        
        if (g0030I == CTRUE) Result = (*Language.var)((*(v35216))[v106834]);
          else Result = (*(v106836))[v106833];
        } 
      } 
    return (Result);} 
  } 

void  unfold_use_list(list *v29233,OID v106848,OID v106843,OID v40124)
{ { Cint  v106838 = v29233->length;
    Cint  v106846 = ClEnv->verbose;
    (ClEnv->verbose = 0);
    if (boolean_I_any(_oid_(v29233)) != CTRUE)
     close_exception(((general_error *) (*Core._general_error)(_string_(CSTRING("[internal] design bug c_func(~S) should be true")),
      _oid_(list::alloc(1,v106848)))));
    if (equal((*Optimize.c_type)(v106848),_oid_(Kernel.emptySet)) == CTRUE)
     v106843= _oid_(Kernel._void);
    { Cint  v106833 = 1;
      Cint  v81965 = (v106838-1);
      { while ((v106833 <= v81965))
        { write_property(Kernel.arg,OBJECT(ClaireObject,(*(v29233))[v106833]),(*(v29233))[(v106833+1)]);
          ++v106833;
          } 
        } 
      } 
    (OBJECT(Let,(*(v29233))[v106838])->arg = v106848);
    (ClEnv->verbose = v106846);
    self_statement_Let(OBJECT(Let,(*(v29233))[1]),v106843,v40124);
    } 
  } 

void  statement_any(OID v107876,OID v106843,OID v40124)
{ GC_BIND;
  { ClaireBoolean * v106826 = Optimize.OPT->alloc_stack;
    if ((((INHERIT(OWNER(v107876),Language._Tuple)) || 
        (INHERIT(OWNER(v107876),Language._Do))) ? CTRUE : ((INHERIT(OWNER(v107876),Language._Let)) ? CTRUE : CFALSE)) != CTRUE)
     (Optimize.OPT->alloc_stack = CFALSE);
    if (c_func_any(v107876) == CTRUE)
     { { ClaireBoolean * g0032I;
        { ClaireBoolean *v_and;
          { v_and = ((Kernel._string == OWNER(v106843)) ? CTRUE : CFALSE);
            if (v_and == CFALSE) g0032I =CFALSE; 
            else { { OID  v129807;
                { OID  v130768;
                  { if (INHERIT(OWNER(v107876),Optimize._to_CL))
                     v130768 = OBJECT(Compile_to_CL,v107876)->arg;
                    else v130768 = v107876;
                      GC_OID(v130768);} 
                  v129807 = (*Optimize.c_sort)(v130768);
                  } 
                v_and = ((v129807 != _oid_(Kernel._void)) ? CTRUE : CFALSE);
                } 
              if (v_and == CFALSE) g0032I =CFALSE; 
              else g0032I = CTRUE;} 
            } 
          } 
        
        if (g0032I == CTRUE) { (*Kernel.c_princ)(v106843);
            princ_string(CSTRING(" = "));
            if (bool_exp_ask_any(v107876) == CTRUE)
             (*Generate.bool_exp_I)(Generate.PRODUCER->value,
              v107876,
              v40124);
            else (*Generate.expression)(v107876,
                v40124);
              princ_string(CSTRING(";"));
            breakline_void();
            princ_string(CSTRING(""));
            } 
          else if (INHERIT(OWNER(v107876),Language._If))
         (*Generate.self_statement)(v107876,
          v106843,
          v40124);
        else if (INHERIT(OWNER(v107876),Reader._delimiter))
         close_exception(((general_error *) (*Core._general_error)(_string_(CSTRING("[201] Loose delimiter in program: ~S")),
          _oid_(list::alloc(1,v107876)))));
        else (*Generate.stat_exp)(Generate.PRODUCER->value,
            v107876,
            v40124);
          } 
      } 
    else if ((INHERIT(OWNER(v107876),Language._Call_method)) && 
        (((*Kernel.arg)(v107876) == Generate._starclose_exception_star->value) && 
          (c_func_any(GC_OID((*(OBJECT(bag,(*Core.args)(v107876))))[1])) == CTRUE)))
     { (*Generate.expression)(v107876,
        v40124);
      princ_string(CSTRING(";"));
      breakline_void();
      princ_string(CSTRING(""));
      } 
    else (*Generate.self_statement)(v107876,
        v106843,
        v40124);
      (Optimize.OPT->alloc_stack = v106826);
    } 
  GC_UNBIND;} 

void  self_statement_Construct(Construct *v107876,OID v106843,OID v40124)
{ (*Generate.stat_construct)(Generate.PRODUCER->value,
    _oid_(v107876),
    v106843,
    v40124);
  } 

void  self_statement_If(If *v107876,OID v106843,OID v40124)
{ GC_BIND;
  if (c_func_any(GC_OID(v107876->test)) == CTRUE)
   { princ_string(CSTRING("if "));
    (*Optimize.bool_exp)(GC_OID(v107876->test),
      Kernel.ctrue,
      v40124);
    princ_string(CSTRING(""));
    breakline_void();
    princ_string(CSTRING(" "));
    if (INHERIT(OWNER(v107876->arg),Language._If))
     new_block_void();
    statement_any(GC_OID(v107876->arg),v106843,v40124);
    if (INHERIT(OWNER(v107876->arg),Language._If))
     close_block_void();
    if ((Kernel._string == OWNER(v106843)) || 
        (boolean_I_any(v107876->other) == CTRUE))
     { OID  v35589 = GC_OID(v107876->other);
      if (inherit_ask_class(OWNER(v35589),Language._If) != CTRUE)
       (Optimize.OPT->level = (Optimize.OPT->level+1));
      princ_string(CSTRING("else "));
      statement_any(v35589,v106843,v40124);
      princ_string(CSTRING(""));
      if (inherit_ask_class(OWNER(v35589),Language._If) != CTRUE)
       (Optimize.OPT->level = (Optimize.OPT->level-1));
      } 
    } 
  else { OID  v106846 = GC_OID((*Generate.c_string)(Generate.PRODUCER->value,
        _oid_(append_symbol(gensym_void(),_string_(CSTRING("I"))))));
      new_block_void();
      interface_I_class(Kernel._boolean);
      princ_string(CSTRING(" "));
      princ_string(string_v(v106846));
      princ_string(CSTRING(";"));
      breakline_void();
      statement_any(GC_OID(v107876->test),v106846,v40124);
      princ_string(CSTRING(""));
      breakline_void();
      (Optimize.OPT->level = (Optimize.OPT->level+1));
      princ_string(CSTRING("if ("));
      princ_string(string_v(v106846));
      princ_string(CSTRING(" == "));
      (*Generate.produce)(Generate.PRODUCER->value,
        Kernel.ctrue);
      princ_string(CSTRING(") "));
      statement_any(GC_OID(v107876->arg),v106843,v40124);
      princ_string(CSTRING(""));
      (Optimize.OPT->level = (Optimize.OPT->level-1));
      if ((Kernel._string == OWNER(v106843)) || 
          (boolean_I_any(v107876->other) == CTRUE))
       { princ_string(CSTRING("else "));
        statement_any(GC_OID(v107876->other),v106843,v40124);
        princ_string(CSTRING(""));
        } 
      close_block_void();
      } 
    GC_UNBIND;} 

void  self_statement_Do(Do *v107876,OID v106843,OID v40124)
{ GC_BIND;
  if (v107876->args->length == 1)
   statement_any(GC_OID((*(v107876->args))[1]),v106843,v40124);
  else { list * v106836 = GC_OBJECT(list,v107876->args);
      Cint  v106837 = v106836->length;
      ClaireBoolean * v106826 = Optimize.OPT->alloc_stack;
      Cint  v106838 = 0;
      (Optimize.OPT->alloc_stack = CFALSE);
      new_block_void();
      inner_statement_any(_oid_(v107876),v106843,v40124);
      close_block_void();
      } 
    GC_UNBIND;} 

void  inner_statement_any(OID v107876,OID v106843,OID v40124)
{ GC_BIND;
  if (INHERIT(OWNER(v107876),Language._Do))
   { list * v106836 = GC_OBJECT(list,OBJECT(Do,v107876)->args);
    Cint  v106837 = v106836->length;
    ClaireBoolean * v106826 = Optimize.OPT->alloc_stack;
    Cint  v106838 = 0;
    (Optimize.OPT->alloc_stack = CFALSE);
    { ITERATE(v106848);
      for (START(v106836); NEXT(v106848);)
      { ++v106838;
        if (v106838 == v106837)
         { (Optimize.OPT->alloc_stack = v106826);
          inner_statement_any(v106848,v106843,v40124);
          } 
        else if (boolean_I_any(v106848) == CTRUE)
         inner_statement_any(v106848,_oid_(Kernel.emptySet),v40124);
        } 
      } 
    } 
  else statement_any(v107876,v106843,v40124);
    GC_UNBIND;} 

void  self_statement_Let(Let *v107876,OID v106843,OID v40124)
{ (*Generate.stat_let)(Generate.PRODUCER->value,
    _oid_(v107876),
    v106843,
    v40124);
  } 

void  self_statement_And(And *v107876,OID v106843,OID v40124)
{ GC_BIND;
  { char * v106846 = GC_STRING(check_var_string(CSTRING("v_and"),v106843,v40124));
    new_block_void();
    interface_I_class(Kernel._boolean);
    princ_string(v106846);
    princ_string(CSTRING(";"));
    breakline_void();
    { OID gc_local;
      ITERATE(v106848);
      bag *v106848_support;
      v106848_support = GC_OBJECT(list,v107876->args);
      for (START(v106848_support); NEXT(v106848);)
      { new_block_void();
        statement_any(v106848,_string_(v106846),v40124);
        princ_string(CSTRING("if ("));
        princ_string(v106846);
        princ_string(CSTRING(" == "));
        (*Generate.produce)(Generate.PRODUCER->value,
          Kernel.cfalse);
        princ_string(CSTRING(") "));
        if (Kernel._string == OWNER(v106843))
         { c_princ_string(string_v(v106843));
          princ_string(CSTRING(" ="));
          } 
        expression_boolean(CFALSE,v40124);
        princ_string(CSTRING("; "));
        breakline_void();
        princ_string(CSTRING("else "));
        } 
      } 
    if (Kernel._string == OWNER(v106843))
     { c_princ_string(string_v(v106843));
      princ_string(CSTRING(" = "));
      expression_boolean(CTRUE,v40124);
      princ_string(CSTRING(";"));
      } 
    else { expression_boolean(CTRUE,v40124);
        princ_string(CSTRING(";"));
        } 
      { OID gc_local;
      ITERATE(v106848);
      bag *v106848_support;
      v106848_support = GC_OBJECT(list,v107876->args);
      for (START(v106848_support); NEXT(v106848);)
      close_block_void();
      } 
    close_block_void();
    } 
  GC_UNBIND;} 

void  self_statement_Or(Or *v107876,OID v106843,OID v40124)
{ GC_BIND;
  { char * v106846 = GC_STRING(check_var_string(CSTRING("v_or"),v106843,v40124));
    new_block_void();
    interface_I_class(Kernel._boolean);
    princ_string(v106846);
    princ_string(CSTRING(";"));
    breakline_void();
    { OID gc_local;
      ITERATE(v106848);
      bag *v106848_support;
      v106848_support = GC_OBJECT(list,v107876->args);
      for (START(v106848_support); NEXT(v106848);)
      { new_block_void();
        statement_any(v106848,_string_(v106846),v40124);
        princ_string(CSTRING("if ("));
        princ_string(v106846);
        princ_string(CSTRING(" == "));
        (*Generate.produce)(Generate.PRODUCER->value,
          Kernel.ctrue);
        princ_string(CSTRING(") "));
        if (Kernel._string == OWNER(v106843))
         { c_princ_string(string_v(v106843));
          princ_string(CSTRING(" ="));
          } 
        expression_boolean(CTRUE,v40124);
        princ_string(CSTRING("; "));
        breakline_void();
        princ_string(CSTRING("else "));
        } 
      } 
    if (Kernel._string == OWNER(v106843))
     { c_princ_string(string_v(v106843));
      princ_string(CSTRING(" = "));
      expression_boolean(CFALSE,v40124);
      princ_string(CSTRING(";"));
      } 
    else { expression_boolean(CFALSE,v40124);
        princ_string(CSTRING(";"));
        } 
      { OID gc_local;
      ITERATE(v106848);
      bag *v106848_support;
      v106848_support = GC_OBJECT(list,v107876->args);
      for (START(v106848_support); NEXT(v106848);)
      close_block_void();
      } 
    close_block_void();
    } 
  GC_UNBIND;} 

void  self_statement_While(While *v107876,OID v106843,OID v40124)
{ (*Generate.stat_while)(Generate.PRODUCER->value,
    _oid_(v107876),
    v106843,
    v40124);
  } 

void  self_statement_Assign(Assign *v107876,OID v106843,OID v40124)
{ GC_BIND;
  { OID  v106846 = GC_OID(v107876->var);
    OID  v106848 = GC_OID(v107876->arg);
    ClaireBoolean * v33030 = ((boolean_I_any(v40124) == CTRUE) ? ((Optimize.OPT->loop_gc == CTRUE) ? ((inner2outer_ask_any(v106848) == CTRUE) ? CTRUE: CFALSE): CFALSE): CFALSE);
    OID  v106849;
    { if ((v33030 == CTRUE) && 
          (INHERIT(OWNER(v106848),Optimize._to_protect)))
       v106849 = (*Kernel.arg)(v106848);
      else v106849 = v106848;
        GC_OID(v106849);} 
    if (Kernel._string == OWNER(v106843))
     { new_block_void();
      statement_any(v106849,v106843,v40124);
      princ_string(CSTRING(" "));
      if (v33030 == CTRUE)
       (*Generate.gc_protection_exp)(Generate.PRODUCER->value,
        v106846,
        Kernel.cfalse,
        v106843,
        v40124);
      else { ident_symbol(OBJECT(Variable,v106846)->pname);
          princ_string(CSTRING(" = "));
          (*Kernel.c_princ)(v106843);
          princ_string(CSTRING(""));
          } 
        princ_string(CSTRING(";"));
      close_block_void();
      princ_string(CSTRING(""));
      } 
    else if (v33030 == CTRUE)
     { new_block_void();
      statement_any(v106849,GC_OID((*Generate.c_string)(Generate.PRODUCER->value,
        v106846)),v40124);
      princ_string(CSTRING(" "));
      (*Generate.gc_protection_exp)(Generate.PRODUCER->value,
        v106846,
        Kernel.ctrue,
        v106846,
        v40124);
      princ_string(CSTRING(";"));
      close_block_void();
      princ_string(CSTRING(""));
      } 
    else statement_any(v106848,GC_OID((*Generate.c_string)(Generate.PRODUCER->value,
        v106846)),v40124);
      } 
  GC_UNBIND;} 

void  self_statement_Gassign(Gassign *v107876,OID v106843,OID v40124)
{ (*Generate.stat_gassign)(Generate.PRODUCER->value,
    _oid_(v107876),
    v106843,
    v40124);
  } 

void  self_statement_to_protect(Compile_to_protect *v107876,OID v106843,OID v40124)
{ GC_BIND;
  if ((Optimize.OPT->protection == CTRUE) && 
      (Kernel._string == OWNER(v106843)))
   { ClaireClass * v106827 = OBJECT(ClaireClass,(*Optimize.c_sort)(GC_OID(v107876->arg)));
    new_block_void();
    (OBJECT(Generate_producer,Generate.PRODUCER->value)->stat = (OBJECT(Generate_producer,Generate.PRODUCER->value)->stat+1));
    statement_any(GC_OID(v107876->arg),v106843,v40124);
    princ_string(gc_protect_class(v106827));
    princ_string(CSTRING("("));
    if (INHERIT(v106827,Kernel._object))
     { class_princ_class(psort_any((*Optimize.c_type)(GC_OID(v107876->arg))));
      princ_string(CSTRING(","));
      } 
    (*Kernel.c_princ)(v106843);
    princ_string(CSTRING(");"));
    close_block_void();
    } 
  else statement_any(GC_OID(v107876->arg),v106843,v40124);
    GC_UNBIND;} 

void  self_statement_For(For *v107876,OID v106843,OID v40124)
{ (*Generate.stat_for)(Generate.PRODUCER->value,
    _oid_(v107876),
    v106843,
    v40124);
  } 

void  self_statement_Iteration(Iteration *v107876,OID v106843,OID v40124)
{ (*Generate.stat_iteration)(Generate.PRODUCER->value,
    _oid_(v107876),
    v106843,
    v40124);
  } 

void  self_statement_Return(Return *v107876,OID v106843,OID v40124)
{ GC_BIND;
  if (v40124 == CNULL)
   { new_block_void();
    statement_any(GC_OID(v107876->arg),_oid_(Kernel.emptySet),_oid_(Kernel.emptySet));
    princ_string(CSTRING("break;"));
    close_block_void();
    } 
  else if (Kernel._string == OWNER(v40124))
   { new_block_void();
    statement_any(GC_OID(v107876->arg),v40124,_oid_(Kernel.emptySet));
    princ_string(CSTRING("break;"));
    close_block_void();
    } 
  else close_exception(((general_error *) (*Core._general_error)(_string_(CSTRING("[204] break not inside a For or While:~S")),
      _oid_(list::alloc(1,_oid_(v107876))))));
    GC_UNBIND;} 

void  self_statement_Call(Call *v107876,OID v106843,OID v40124)
{ GC_BIND;
  { list * v106836 = GC_OBJECT(list,v107876->args);
    list * v35216 = GC_OBJECT(list,unfold_args_list(v106836));
    { OID  v25643;
      { Call * v109096 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
        (v109096->selector = v107876->selector);
        { Call * v81996 = v109096; 
          list * v81997;
          { bag *v_list; OID v_val;
            OID v106850,CLcount;
            v_list = v106836;
             v81997 = v_list->clone();
            for (CLcount= 1; CLcount <= v_list->length; CLcount++)
            { v106850 = (*(v_list))[CLcount];
              v_val = unfold_arg_list(v106836,v35216,v106850);
              
              (*((list *) v81997))[CLcount] = v_val;} 
            } 
          (v81996->args = v81997);} 
        add_I_property(Kernel.instances,Language._Call,11,_oid_(v109096));
        v25643 = _oid_(v109096);
        } 
      unfold_use_list(v35216,v25643,v106843,v40124);
      } 
    } 
  GC_UNBIND;} 

void  self_statement_Call_method(Call_method *v107876,OID v106843,OID v40124)
{ GC_BIND;
  { list * v106836 = GC_OBJECT(list,v107876->args);
    list * v35216 = GC_OBJECT(list,unfold_args_list(v106836));
    { OID  v28526;
      { Call_method * v109096 = ((Call_method *) GC_OBJECT(Call_method,new_object_class(Language._Call_method)));
        (v109096->arg = v107876->arg);
        { Call_method * v81999 = v109096; 
          list * v82000;
          { bag *v_list; OID v_val;
            OID v106850,CLcount;
            v_list = v106836;
             v82000 = v_list->clone();
            for (CLcount= 1; CLcount <= v_list->length; CLcount++)
            { v106850 = (*(v_list))[CLcount];
              v_val = unfold_arg_list(v106836,v35216,v106850);
              
              (*((list *) v82000))[CLcount] = v_val;} 
            } 
          (v81999->args = v82000);} 
        add_I_property(Kernel.instances,Language._Call_method,11,_oid_(v109096));
        v28526 = _oid_(v109096);
        } 
      unfold_use_list(v35216,v28526,v106843,v40124);
      } 
    } 
  GC_UNBIND;} 

void  self_statement_Call_method1(Call_method1 *v107876,OID v106843,OID v40124)
{ GC_BIND;
  { list * v106836 = GC_OBJECT(list,v107876->args);
    list * v35216 = GC_OBJECT(list,unfold_args_list(v106836));
    { OID  v31409;
      { Call_method1 * v109096 = ((Call_method1 *) GC_OBJECT(Call_method1,new_object_class(Language._Call_method1)));
        (v109096->arg = v107876->arg);
        { Call_method * v82002 = v109096; 
          list * v82003;
          { bag *v_list; OID v_val;
            OID v106850,CLcount;
            v_list = v106836;
             v82003 = v_list->clone();
            for (CLcount= 1; CLcount <= v_list->length; CLcount++)
            { v106850 = (*(v_list))[CLcount];
              v_val = unfold_arg_list(v106836,v35216,v106850);
              
              (*((list *) v82003))[CLcount] = v_val;} 
            } 
          (v82002->args = v82003);} 
        add_I_property(Kernel.instances,Language._Call_method1,11,_oid_(v109096));
        v31409 = _oid_(v109096);
        } 
      unfold_use_list(v35216,v31409,v106843,v40124);
      } 
    } 
  GC_UNBIND;} 

void  self_statement_Call_method2(Call_method2 *v107876,OID v106843,OID v40124)
{ GC_BIND;
  { list * v106836 = GC_OBJECT(list,v107876->args);
    list * v35216 = GC_OBJECT(list,unfold_args_list(v106836));
    { OID  v34292;
      { Call_method2 * v109096 = ((Call_method2 *) GC_OBJECT(Call_method2,new_object_class(Language._Call_method2)));
        (v109096->arg = v107876->arg);
        { Call_method * v82026 = v109096; 
          list * v82027;
          { bag *v_list; OID v_val;
            OID v106850,CLcount;
            v_list = v106836;
             v82027 = v_list->clone();
            for (CLcount= 1; CLcount <= v_list->length; CLcount++)
            { v106850 = (*(v_list))[CLcount];
              v_val = unfold_arg_list(v106836,v35216,v106850);
              
              (*((list *) v82027))[CLcount] = v_val;} 
            } 
          (v82026->args = v82027);} 
        add_I_property(Kernel.instances,Language._Call_method2,11,_oid_(v109096));
        v34292 = _oid_(v109096);
        } 
      unfold_use_list(v35216,v34292,v106843,v40124);
      } 
    } 
  GC_UNBIND;} 

void  self_statement_Super(Super *v107876,OID v106843,OID v40124)
{ (*Generate.stat_super)(Generate.PRODUCER->value,
    _oid_(v107876),
    v106843,
    v40124);
  } 

void  self_statement_Cast(Cast *v107876,OID v106843,OID v40124)
{ GC_BIND;
  statement_any(GC_OID(v107876->arg),v106843,v40124);
  GC_UNBIND;} 

void  self_statement_Handle(ClaireHandle *v107876,OID v106843,OID v40124)
{ (*Generate.stat_handle)(Generate.PRODUCER->value,
    _oid_(v107876),
    v106843,
    v40124);
  } 

void  self_statement_to_CL(Compile_to_CL *v107876,OID v106843,OID v40124)
{ GC_BIND;
  if (Kernel._string == OWNER(v106843))
   { Variable * v62520 = GC_OBJECT(Variable,build_Variable_string(string_I_symbol(gensym_string(CSTRING("V_CL"))),_oid_(v107876->set_arg)));
    ClaireClass * v35383 = ((v107876->set_arg == Kernel._void) ?
      Kernel._any :
      v107876->set_arg );
    new_block_void();
    interface_I_class(v35383);
    princ_string(CSTRING(" "));
    expression_Variable(v62520,v40124);
    princ_string(CSTRING(";"));
    statement_any(GC_OID(v107876->arg),GC_OID((*Generate.c_string)(Generate.PRODUCER->value,
      _oid_(v62520))),v40124);
    breakline_void();
    princ_string(string_v(v106843));
    princ_string(CSTRING("="));
    (*Generate.to_cl)(Generate.PRODUCER->value,
      _oid_(v62520),
      _oid_(v107876->set_arg),
      v40124);
    princ_string(CSTRING(";"));
    close_block_void();
    } 
  else statement_any(GC_OID(v107876->arg),v106843,v40124);
    GC_UNBIND;} 

void  self_statement_to_C(Compile_to_C *v107876,OID v106843,OID v40124)
{ GC_BIND;
  if (Kernel._string == OWNER(v106843))
   { Variable * v62520 = GC_OBJECT(Variable,build_Variable_string(CSTRING("V_C"),_oid_(Kernel._any)));
    new_block_void();
    (*Generate.any_interface)(Generate.PRODUCER->value);
    princ_string(CSTRING(" "));
    (*Language.ident)(Generate.PRODUCER->value,
      _oid_(v62520));
    princ_string(CSTRING(";"));
    statement_any(GC_OID(v107876->arg),GC_OID((*Generate.c_string)(Generate.PRODUCER->value,
      _oid_(v62520))),v40124);
    breakline_void();
    princ_string(string_v(v106843));
    princ_string(CSTRING("="));
    (*Generate.to_c)(Generate.PRODUCER->value,
      _oid_(v62520),
      _oid_(v107876->set_arg),
      v40124);
    princ_string(CSTRING(";"));
    close_block_void();
    } 
  else statement_any(GC_OID(v107876->arg),v106843,v40124);
    GC_UNBIND;} 

void  self_statement_C_cast(Compile_C_cast *v107876,OID v106843,OID v40124)
{ GC_BIND;
  if (Kernel._string == OWNER(v106843))
   { char * v62520 = GC_STRING(check_var_string(CSTRING("V_CC"),v106843,v40124));
    ClaireClass * v35383 = v107876->set_arg;
    ClaireClass * v35384 = stupid_t_any1(GC_OID(v107876->arg));
    ClaireType * v35414 = GC_OBJECT(ClaireType,join_class(osort_any(_oid_(v35383)),v35384));
    new_block_void();
    (*Generate.define_variable)(Generate.PRODUCER->value,
      _oid_(v35414),
      _string_(v62520));
    breakline_void();
    statement_any(GC_OID(v107876->arg),_string_(v62520),v40124);
    princ_string(string_v(v106843));
    princ_string(CSTRING("= "));
    (*Generate.pointer_cast)(Generate.PRODUCER->value,
      _oid_(v35383));
    princ_string(CSTRING(" "));
    princ_string(v62520);
    princ_string(CSTRING(";"));
    close_block_void();
    } 
  else statement_any(GC_OID(v107876->arg),v106843,v40124);
    GC_UNBIND;} 

void  self_statement_Call_slot(Call_slot *v107876,OID v106843,OID v40124)
{ GC_BIND;
  { char * v48332 = GC_STRING(string_I_symbol(gensym_void()));
    Variable * v62520 = GC_OBJECT(Variable,build_Variable_string(v48332,(*Optimize.c_type)(GC_OID(v107876->arg))));
    new_block_void();
    interface_I_class(sort_Variable(v62520));
    princ_string(CSTRING(" "));
    expression_Variable(v62520,_oid_(Kernel.emptySet));
    princ_string(CSTRING(";"));
    breakline_void();
    statement_any(GC_OID(v107876->arg),_string_(v48332),v40124);
    breakline_void();
    if (Kernel._string == OWNER(v106843))
     { c_princ_string(string_v(v106843));
      princ_string(CSTRING(" = "));
      } 
    { Call_slot * v57356;
      { Call_slot * v109096 = ((Call_slot *) GC_OBJECT(Call_slot,new_object_class(Language._Call_slot)));
        (v109096->selector = v107876->selector);
        (v109096->arg = _oid_(v62520));
        add_I_property(Kernel.instances,Language._Call_slot,11,_oid_(v109096));
        v57356 = v109096;
        } 
      expression_Call_slot(v57356,v40124);
      } 
    princ_string(CSTRING(";"));
    close_block_void();
    } 
  GC_UNBIND;} 

void  self_statement_Call_table(Call_table *v107876,OID v106843,OID v40124)
{ GC_BIND;
  { char * v48332 = GC_STRING(string_I_symbol(gensym_void()));
    Variable * v62520 = GC_OBJECT(Variable,build_Variable_string(v48332,(*Optimize.c_type)(GC_OID(v107876->arg))));
    new_block_void();
    interface_I_class(sort_Variable(v62520));
    princ_string(CSTRING(" "));
    expression_Variable(v62520,_oid_(Kernel.emptySet));
    princ_string(CSTRING(";"));
    breakline_void();
    statement_any(GC_OID(v107876->arg),_string_(v48332),v40124);
    breakline_void();
    if (Kernel._string == OWNER(v106843))
     { c_princ_string(string_v(v106843));
      princ_string(CSTRING(" = "));
      } 
    { Call_table * v58317;
      { Call_table * v109096 = ((Call_table *) GC_OBJECT(Call_table,new_object_class(Language._Call_table)));
        (v109096->selector = v107876->selector);
        (v109096->arg = _oid_(v62520));
        add_I_property(Kernel.instances,Language._Call_table,11,_oid_(v109096));
        v58317 = v109096;
        } 
      expression_Call_table(v58317,v40124);
      } 
    princ_string(CSTRING(";"));
    close_block_void();
    } 
  GC_UNBIND;} 

void  self_statement_Call_array(Call_array *v107876,OID v106843,OID v40124)
{ GC_BIND;
  { Variable * v103161 = GC_OBJECT(Variable,build_Variable_string(CSTRING("va_arg1"),_oid_(Kernel._array)));
    Variable * v103162 = GC_OBJECT(Variable,build_Variable_string(CSTRING("va_arg2"),_oid_(Kernel._integer)));
    new_block_void();
    interface_I_class(Kernel._array);
    princ_string(CSTRING(" "));
    expression_Variable(v103161,_oid_(Kernel.emptySet));
    princ_string(CSTRING(";"));
    breakline_void();
    interface_I_class(Kernel._integer);
    princ_string(CSTRING(" "));
    expression_Variable(v103162,_oid_(Kernel.emptySet));
    princ_string(CSTRING(";"));
    breakline_void();
    statement_any(GC_OID(v107876->selector),_string_(CSTRING("va_arg1")),v40124);
    statement_any(GC_OID(v107876->arg),_string_(CSTRING("va_arg2")),v40124);
    if (Kernel._string == OWNER(v106843))
     { c_princ_string(string_v(v106843));
      princ_string(CSTRING(" = "));
      } 
    { Call_array * v59278;
      { Call_array * v109096 = ((Call_array *) GC_OBJECT(Call_array,new_object_class(Language._Call_array)));
        (v109096->selector = _oid_(v103161));
        (v109096->arg = _oid_(v103162));
        (v109096->test = v107876->test);
        add_I_property(Kernel.instances,Language._Call_array,11,_oid_(v109096));
        v59278 = v109096;
        } 
      expression_Call_array(v59278,v40124);
      } 
    princ_string(CSTRING(";"));
    close_block_void();
    } 
  GC_UNBIND;} 

void  self_statement_Update(Update *v107876,OID v106843,OID v40124)
{ GC_BIND;
  { OID  v106816 = GC_OID(v107876->var);
    OID  v106840 = GC_OID(v107876->selector);
    ClaireType * v35382;
    { if (INHERIT(OWNER(v106816),Language._Call_slot))
       v35382 = domain_I_restriction(OBJECT(Call_slot,v106816)->selector);
      else if (INHERIT(OWNER(v106816),Language._Call_array))
       v35382 = Kernel._integer;
      else v35382 = U_type(Kernel._any,GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Kernel.domain)(v106840))));
        GC_OBJECT(ClaireType,v35382);} 
    ClaireType * v35383;
    { if (INHERIT(OWNER(v106816),Language._Call_slot))
       { v35383 = ((v107876->arg == _oid_(Kernel.add)) ?
          member_type(OBJECT(Call_slot,v106816)->selector->range) :
          OBJECT(Call_slot,v106816)->selector->range );
        } 
      else if (INHERIT(OWNER(v106816),Language._Call_array))
       { v35383 = (((OBJECT(ClaireBoolean,(*Core._inf_equalt)(GC_OID(OBJECT(Call_array,v106816)->test),
          _oid_(Kernel._float)))) == CTRUE) ?
          Kernel._float :
          Kernel._any );
        } 
      else v35383 = U_type(Kernel._any,GC_OBJECT(ClaireType,((v107876->arg == _oid_(Kernel.add)) ?
          member_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Kernel.range)(v106840)))) :
          OBJECT(ClaireType,(*Kernel.range)(v106840)) )));
        GC_OBJECT(ClaireType,v35383);} 
    ClaireClass * v50361 = stupid_t_any1(GC_OID((*Kernel.arg)(v107876->var)));
    ClaireClass * v50362 = stupid_t_any1(GC_OID(v107876->value));
    OID  v8745;
    { if ((_inf_equalt_class(v50361,psort_any(_oid_(v35382))) != CTRUE) && 
          (_inf_equalt_class(v50361,Kernel._object) == CTRUE))
       { Compile_C_cast * v109096 = ((Compile_C_cast *) GC_OBJECT(Compile_C_cast,new_object_class(Optimize._C_cast)));
        (v109096->arg = (*Kernel.arg)(GC_OID(v107876->var)));
        (v109096->set_arg = psort_any(_oid_(v35382)));
        add_I_property(Kernel.instances,Optimize._C_cast,11,_oid_(v109096));
        v8745 = _oid_(v109096);
        } 
      else v8745 = (*Kernel.arg)(GC_OID(v107876->var));
        GC_OID(v8745);} 
    OID  v36996;
    { if ((_inf_equalt_class(v50362,psort_any(_oid_(v35383))) != CTRUE) && 
          (_inf_equalt_class(v50362,Kernel._object) == CTRUE))
       { Compile_C_cast * v109096 = ((Compile_C_cast *) GC_OBJECT(Compile_C_cast,new_object_class(Optimize._C_cast)));
        (v109096->arg = v107876->value);
        (v109096->set_arg = psort_any(_oid_(v35383)));
        add_I_property(Kernel.instances,Optimize._C_cast,11,_oid_(v109096));
        v36996 = _oid_(v109096);
        } 
      else v36996 = v107876->value;
        GC_OID(v36996);} 
    Variable * v103161 = GC_OBJECT(Variable,Variable_I_symbol(gensym_void(),0,v35382));
    Variable * v103162 = GC_OBJECT(Variable,Variable_I_symbol(gensym_void(),0,v35383));
    ClaireBoolean * v34855 = c_func_any(v8745);
    new_block_void();
    interface_I_class(psort_any(_oid_(v35382)));
    princ_string(CSTRING(" "));
    expression_Variable(v103161,_oid_(Kernel.emptySet));
    princ_string(CSTRING(" "));
    if (v34855 == CTRUE)
     { princ_string(CSTRING("= "));
      (*Generate.expression)(v8745,
        _oid_(Kernel.emptySet));
      princ_string(CSTRING(""));
      } 
    princ_string(CSTRING("; "));
    breakline_void();
    interface_I_class(psort_any(_oid_(v35383)));
    princ_string(CSTRING(" "));
    expression_Variable(v103162,_oid_(Kernel.emptySet));
    princ_string(CSTRING(";"));
    breakline_void();
    if (v34855 != CTRUE)
     statement_any(v8745,GC_OID((*Generate.c_string)(Generate.PRODUCER->value,
      _oid_(v103161))),v40124);
    statement_any(v36996,GC_OID((*Generate.c_string)(Generate.PRODUCER->value,
      _oid_(v103162))),v40124);
    if (Kernel._string == OWNER(v106843))
     { c_princ_string(string_v(v106843));
      princ_string(CSTRING(" = "));
      } 
    { Update * v60239;
      { Update * v109096 = ((Update *) GC_OBJECT(Update,new_object_class(Language._Update)));
        (v109096->selector = v106840);
        { Update * v82032 = v109096; 
          OID  v82033;
          if (v107876->arg == _oid_(Kernel.add))
           v82033 = _oid_(Kernel.add);
          else if (sort_Variable(v103161) == Kernel._any)
           v82033 = _oid_(v103161);
          else { Compile_to_CL * v109096 = ((Compile_to_CL *) GC_OBJECT(Compile_to_CL,new_object_class(Optimize._to_CL)));
              (v109096->arg = _oid_(v103161));
              (v109096->set_arg = sort_Variable(v103161));
              add_I_property(Kernel.instances,Optimize._to_CL,11,_oid_(v109096));
              v82033 = _oid_(v109096);
              } 
            (v82032->arg = v82033);} 
        (v109096->value = _oid_(v103162));
        { Update * v82034 = v109096; 
          OID  v82035;
          { OID  v35608 = GC_OID((*Kernel.copy)(v106816));
            put_property2(Kernel.arg,OBJECT(ClaireObject,v35608),_oid_(v103161));
            v82035 = v35608;
            } 
          (v82034->var = v82035);} 
        add_I_property(Kernel.instances,Language._Update,11,_oid_(v109096));
        v60239 = v109096;
        } 
      expression_Update(v60239,v40124);
      } 
    princ_string(CSTRING(";"));
    close_block_void();
    } 
  GC_UNBIND;} 

