/***** CLAIRE Compilation of file e:\claire\v3.5\src\compile\gstat.cl 
         [version 3.5.0 / safety 5] Sun May 28 08:26:01 2017 *****/

#include <claire.h>
#include <Kernel.h>
#include <Core.h>
#include <Language.h>
#include <Reader.h>
#include <Optimize.h>
#include <Generate.h>
list * unfold_args_list(list *v5124)
{ GC_BIND;
  { list *Result ;
    { list * v14721;
      { { list * v2576 = list::empty(Kernel.emptySet);
          { Cint  v5121 = 1;
            Cint  v2570 = v5124->length;
            { OID gc_local;
              while ((v5121 <= v2570))
              { if (c_func_any((*(v5124))[v5121]) != CTRUE)
                 v2576->addFast(v5121);
                ++v5121;
                } 
              } 
            } 
          v14721 = GC_OBJECT(list,v2576);
          } 
        GC_OBJECT(list,v14721);} 
      { bag *v_list; OID v_val;
        OID v5121,CLcount;
        v_list = v14721;
         Result = v_list->clone();
        for (CLcount= 1; CLcount <= v_list->length; CLcount++)
        { v5121 = (*(v_list))[CLcount];
          { Let * v14361 = ((Let *) GC_OBJECT(Let,new_object_class(Language._Let)));
            (v14361->var = Variable_I_symbol(append_symbol(gensym_void(),_string_(CSTRING("UU"))),0,GC_OBJECT(ClaireType,c_type_sort_any((*(v5124))[v5121]))));
            (v14361->value = (*(v5124))[v5121]);
            add_I_property(Kernel.instances,Language._Let,11,_oid_(v14361));
            v_val = _oid_(v14361);
            } 
          
          (*((list *) Result))[CLcount] = v_val;} 
        } 
      } 
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_sort_any(OID v5136)
{ { ClaireType *Result ;
    { ClaireClass * v5134 = OBJECT(ClaireClass,(*Optimize.c_sort)(v5136));
      ClaireClass * v5133 = stupid_t_any1(v5136);
      Result = ((v5134 == Kernel._void) ?
        osort_any((*Optimize.c_type)(v5136)) :
        ((boolean_I_any(sort_equal_class(osort_any(_oid_(v5133)),v5134)) == CTRUE) ?
          v5133 :
          v5134 ) );
      } 
    return (Result);} 
  } 

OID  unfold_arg_list(list *v5124,list *v11488,OID v5136)
{ { OID Result = 0;
    { Cint  v5121 = 1;
      Cint  v5122 = 0;
      Cint  v5125 = v5124->length;
      { ClaireBoolean * g0030I;
        { OID v11634;{ v11634= _oid_(CFALSE);
            while ((v5121 <= v5125))
            { if (c_func_any((*(v5124))[v5121]) != CTRUE)
               { ++v5122;
                if (equal((*(v5124))[v5121],v5136) == CTRUE)
                 { v11634 = Kernel.ctrue;
                  break;} 
                } 
              else if (equal((*(v5124))[v5121],v5136) == CTRUE)
               { v11634 = Kernel.cfalse;
                break;} 
              ++v5121;
              } 
            } 
          
          g0030I=OBJECT(ClaireBoolean,v11634);} 
        
        if (g0030I == CTRUE) Result = (*Language.var)((*(v11488))[v5122]);
          else Result = (*(v5124))[v5121];
        } 
      } 
    return (Result);} 
  } 

void  unfold_use_list(list *v386,OID v5136,OID v5134,OID v11276)
{ { Cint  v5126 = v386->length;
    Cint  v5138 = ClEnv->verbose;
    (ClEnv->verbose = 0);
    if (boolean_I_any(_oid_(v386)) != CTRUE)
     close_exception(((general_error *) (*Core._general_error)(_string_(CSTRING("[internal] design bug c_func(~S) should be true")),
      _oid_(list::alloc(1,v5136)))));
    if (equal((*Optimize.c_type)(v5136),_oid_(Kernel.emptySet)) == CTRUE)
     v5134= _oid_(Kernel._void);
    { Cint  v5121 = 1;
      Cint  v2589 = (v5126-1);
      { while ((v5121 <= v2589))
        { write_property(Kernel.arg,OBJECT(ClaireObject,(*(v386))[v5121]),(*(v386))[(v5121+1)]);
          ++v5121;
          } 
        } 
      } 
    (OBJECT(Let,(*(v386))[v5126])->arg = v5136);
    (ClEnv->verbose = v5138);
    self_statement_Let(OBJECT(Let,(*(v386))[1]),v5134,v11276);
    } 
  } 

void  statement_any(OID v13492,OID v5134,OID v11276)
{ GC_BIND;
  { ClaireBoolean * v5114 = Optimize.OPT->alloc_stack;
    if ((((INHERIT(OWNER(v13492),Language._Tuple)) || 
        (INHERIT(OWNER(v13492),Language._Do))) ? CTRUE : ((INHERIT(OWNER(v13492),Language._Let)) ? CTRUE : CFALSE)) != CTRUE)
     (Optimize.OPT->alloc_stack = CFALSE);
    if (c_func_any(v13492) == CTRUE)
     { { ClaireBoolean * g0032I;
        { ClaireBoolean *v_and;
          { v_and = ((Kernel._string == OWNER(v5134)) ? CTRUE : CFALSE);
            if (v_and == CFALSE) g0032I =CFALSE; 
            else { { OID  v2303;
                { OID  v3264;
                  { if (INHERIT(OWNER(v13492),Optimize._to_CL))
                     v3264 = OBJECT(Compile_to_CL,v13492)->arg;
                    else v3264 = v13492;
                      GC_OID(v3264);} 
                  v2303 = (*Optimize.c_sort)(v3264);
                  } 
                v_and = ((v2303 != _oid_(Kernel._void)) ? CTRUE : CFALSE);
                } 
              if (v_and == CFALSE) g0032I =CFALSE; 
              else g0032I = CTRUE;} 
            } 
          } 
        
        if (g0032I == CTRUE) { (*Kernel.c_princ)(v5134);
            princ_string(CSTRING(" = "));
            if (bool_exp_ask_any(v13492) == CTRUE)
             (*Generate.bool_exp_I)(Generate.PRODUCER->value,
              v13492,
              v11276);
            else (*Generate.expression)(v13492,
                v11276);
              princ_string(CSTRING(";"));
            breakline_void();
            princ_string(CSTRING(""));
            } 
          else if (INHERIT(OWNER(v13492),Language._If))
         (*Generate.self_statement)(v13492,
          v5134,
          v11276);
        else if (INHERIT(OWNER(v13492),Reader._delimiter))
         close_exception(((general_error *) (*Core._general_error)(_string_(CSTRING("[201] Loose delimiter in program: ~S")),
          _oid_(list::alloc(1,v13492)))));
        else (*Generate.stat_exp)(Generate.PRODUCER->value,
            v13492,
            v11276);
          } 
      } 
    else if ((INHERIT(OWNER(v13492),Language._Call_method)) && 
        (((*Kernel.arg)(v13492) == Generate._starclose_exception_star->value) && 
          (c_func_any(GC_OID((*(OBJECT(bag,(*Core.args)(v13492))))[1])) == CTRUE)))
     { (*Generate.expression)(v13492,
        v11276);
      princ_string(CSTRING(";"));
      breakline_void();
      princ_string(CSTRING(""));
      } 
    else (*Generate.self_statement)(v13492,
        v5134,
        v11276);
      (Optimize.OPT->alloc_stack = v5114);
    } 
  GC_UNBIND;} 

void  self_statement_Construct(Construct *v13492,OID v5134,OID v11276)
{ (*Generate.stat_construct)(Generate.PRODUCER->value,
    _oid_(v13492),
    v5134,
    v11276);
  } 

void  self_statement_If(If *v13492,OID v5134,OID v11276)
{ GC_BIND;
  if (c_func_any(GC_OID(v13492->test)) == CTRUE)
   { princ_string(CSTRING("if "));
    (*Optimize.bool_exp)(GC_OID(v13492->test),
      Kernel.ctrue,
      v11276);
    princ_string(CSTRING(""));
    breakline_void();
    princ_string(CSTRING(" "));
    if (INHERIT(OWNER(v13492->arg),Language._If))
     new_block_void();
    statement_any(GC_OID(v13492->arg),v5134,v11276);
    if (INHERIT(OWNER(v13492->arg),Language._If))
     close_block_void();
    if ((Kernel._string == OWNER(v5134)) || 
        (boolean_I_any(v13492->other) == CTRUE))
     { OID  v11861 = GC_OID(v13492->other);
      if (inherit_ask_class(OWNER(v11861),Language._If) != CTRUE)
       (Optimize.OPT->level = (Optimize.OPT->level+1));
      princ_string(CSTRING("else "));
      statement_any(v11861,v5134,v11276);
      princ_string(CSTRING(""));
      if (inherit_ask_class(OWNER(v11861),Language._If) != CTRUE)
       (Optimize.OPT->level = (Optimize.OPT->level-1));
      } 
    } 
  else { OID  v5138 = GC_OID((*Generate.c_string)(Generate.PRODUCER->value,
        _oid_(append_symbol(gensym_void(),_string_(CSTRING("I"))))));
      new_block_void();
      interface_I_class(Kernel._boolean);
      princ_string(CSTRING(" "));
      princ_string(string_v(v5138));
      princ_string(CSTRING(";"));
      breakline_void();
      statement_any(GC_OID(v13492->test),v5138,v11276);
      princ_string(CSTRING(""));
      breakline_void();
      (Optimize.OPT->level = (Optimize.OPT->level+1));
      princ_string(CSTRING("if ("));
      princ_string(string_v(v5138));
      princ_string(CSTRING(" == "));
      (*Generate.produce)(Generate.PRODUCER->value,
        Kernel.ctrue);
      princ_string(CSTRING(") "));
      statement_any(GC_OID(v13492->arg),v5134,v11276);
      princ_string(CSTRING(""));
      (Optimize.OPT->level = (Optimize.OPT->level-1));
      if ((Kernel._string == OWNER(v5134)) || 
          (boolean_I_any(v13492->other) == CTRUE))
       { princ_string(CSTRING("else "));
        statement_any(GC_OID(v13492->other),v5134,v11276);
        princ_string(CSTRING(""));
        } 
      close_block_void();
      } 
    GC_UNBIND;} 

void  self_statement_Do(Do *v13492,OID v5134,OID v11276)
{ GC_BIND;
  if (v13492->args->length == 1)
   statement_any(GC_OID((*(v13492->args))[1]),v5134,v11276);
  else { list * v5124 = GC_OBJECT(list,v13492->args);
      Cint  v5125 = v5124->length;
      ClaireBoolean * v5114 = Optimize.OPT->alloc_stack;
      Cint  v5126 = 0;
      (Optimize.OPT->alloc_stack = CFALSE);
      new_block_void();
      inner_statement_any(_oid_(v13492),v5134,v11276);
      close_block_void();
      } 
    GC_UNBIND;} 

void  inner_statement_any(OID v13492,OID v5134,OID v11276)
{ GC_BIND;
  if (INHERIT(OWNER(v13492),Language._Do))
   { list * v5124 = GC_OBJECT(list,OBJECT(Do,v13492)->args);
    Cint  v5125 = v5124->length;
    ClaireBoolean * v5114 = Optimize.OPT->alloc_stack;
    Cint  v5126 = 0;
    (Optimize.OPT->alloc_stack = CFALSE);
    { ITERATE(v5136);
      for (START(v5124); NEXT(v5136);)
      { ++v5126;
        if (v5126 == v5125)
         { (Optimize.OPT->alloc_stack = v5114);
          inner_statement_any(v5136,v5134,v11276);
          } 
        else if (boolean_I_any(v5136) == CTRUE)
         inner_statement_any(v5136,_oid_(Kernel.emptySet),v11276);
        } 
      } 
    } 
  else statement_any(v13492,v5134,v11276);
    GC_UNBIND;} 

void  self_statement_Let(Let *v13492,OID v5134,OID v11276)
{ (*Generate.stat_let)(Generate.PRODUCER->value,
    _oid_(v13492),
    v5134,
    v11276);
  } 

void  self_statement_And(And *v13492,OID v5134,OID v11276)
{ GC_BIND;
  { char * v5138 = GC_STRING(check_var_string(CSTRING("v_and"),v5134,v11276));
    new_block_void();
    interface_I_class(Kernel._boolean);
    princ_string(v5138);
    princ_string(CSTRING(";"));
    breakline_void();
    { OID gc_local;
      ITERATE(v5136);
      bag *v5136_support;
      v5136_support = GC_OBJECT(list,v13492->args);
      for (START(v5136_support); NEXT(v5136);)
      { new_block_void();
        statement_any(v5136,_string_(v5138),v11276);
        princ_string(CSTRING("if ("));
        princ_string(v5138);
        princ_string(CSTRING(" == "));
        (*Generate.produce)(Generate.PRODUCER->value,
          Kernel.cfalse);
        princ_string(CSTRING(") "));
        if (Kernel._string == OWNER(v5134))
         { c_princ_string(string_v(v5134));
          princ_string(CSTRING(" ="));
          } 
        expression_boolean(CFALSE,v11276);
        princ_string(CSTRING("; "));
        breakline_void();
        princ_string(CSTRING("else "));
        } 
      } 
    if (Kernel._string == OWNER(v5134))
     { c_princ_string(string_v(v5134));
      princ_string(CSTRING(" = "));
      expression_boolean(CTRUE,v11276);
      princ_string(CSTRING(";"));
      } 
    else { expression_boolean(CTRUE,v11276);
        princ_string(CSTRING(";"));
        } 
      { OID gc_local;
      ITERATE(v5136);
      bag *v5136_support;
      v5136_support = GC_OBJECT(list,v13492->args);
      for (START(v5136_support); NEXT(v5136);)
      close_block_void();
      } 
    close_block_void();
    } 
  GC_UNBIND;} 

void  self_statement_Or(Or *v13492,OID v5134,OID v11276)
{ GC_BIND;
  { char * v5138 = GC_STRING(check_var_string(CSTRING("v_or"),v5134,v11276));
    new_block_void();
    interface_I_class(Kernel._boolean);
    princ_string(v5138);
    princ_string(CSTRING(";"));
    breakline_void();
    { OID gc_local;
      ITERATE(v5136);
      bag *v5136_support;
      v5136_support = GC_OBJECT(list,v13492->args);
      for (START(v5136_support); NEXT(v5136);)
      { new_block_void();
        statement_any(v5136,_string_(v5138),v11276);
        princ_string(CSTRING("if ("));
        princ_string(v5138);
        princ_string(CSTRING(" == "));
        (*Generate.produce)(Generate.PRODUCER->value,
          Kernel.ctrue);
        princ_string(CSTRING(") "));
        if (Kernel._string == OWNER(v5134))
         { c_princ_string(string_v(v5134));
          princ_string(CSTRING(" ="));
          } 
        expression_boolean(CTRUE,v11276);
        princ_string(CSTRING("; "));
        breakline_void();
        princ_string(CSTRING("else "));
        } 
      } 
    if (Kernel._string == OWNER(v5134))
     { c_princ_string(string_v(v5134));
      princ_string(CSTRING(" = "));
      expression_boolean(CFALSE,v11276);
      princ_string(CSTRING(";"));
      } 
    else { expression_boolean(CFALSE,v11276);
        princ_string(CSTRING(";"));
        } 
      { OID gc_local;
      ITERATE(v5136);
      bag *v5136_support;
      v5136_support = GC_OBJECT(list,v13492->args);
      for (START(v5136_support); NEXT(v5136);)
      close_block_void();
      } 
    close_block_void();
    } 
  GC_UNBIND;} 

void  self_statement_While(While *v13492,OID v5134,OID v11276)
{ (*Generate.stat_while)(Generate.PRODUCER->value,
    _oid_(v13492),
    v5134,
    v11276);
  } 

void  self_statement_Assign(Assign *v13492,OID v5134,OID v11276)
{ GC_BIND;
  { OID  v5138 = GC_OID(v13492->var);
    OID  v5136 = GC_OID(v13492->arg);
    ClaireBoolean * v9302 = ((boolean_I_any(v11276) == CTRUE) ? ((Optimize.OPT->loop_gc == CTRUE) ? ((inner2outer_ask_any(v5136) == CTRUE) ? CTRUE: CFALSE): CFALSE): CFALSE);
    OID  v5137;
    { if ((v9302 == CTRUE) && 
          (INHERIT(OWNER(v5136),Optimize._to_protect)))
       v5137 = (*Kernel.arg)(v5136);
      else v5137 = v5136;
        GC_OID(v5137);} 
    if (Kernel._string == OWNER(v5134))
     { new_block_void();
      statement_any(v5137,v5134,v11276);
      princ_string(CSTRING(" "));
      if (v9302 == CTRUE)
       (*Generate.gc_protection_exp)(Generate.PRODUCER->value,
        v5138,
        Kernel.cfalse,
        v5134,
        v11276);
      else { ident_symbol(OBJECT(Variable,v5138)->pname);
          princ_string(CSTRING(" = "));
          (*Kernel.c_princ)(v5134);
          princ_string(CSTRING(""));
          } 
        princ_string(CSTRING(";"));
      close_block_void();
      princ_string(CSTRING(""));
      } 
    else if (v9302 == CTRUE)
     { new_block_void();
      statement_any(v5137,GC_OID((*Generate.c_string)(Generate.PRODUCER->value,
        v5138)),v11276);
      princ_string(CSTRING(" "));
      (*Generate.gc_protection_exp)(Generate.PRODUCER->value,
        v5138,
        Kernel.ctrue,
        v5138,
        v11276);
      princ_string(CSTRING(";"));
      close_block_void();
      princ_string(CSTRING(""));
      } 
    else statement_any(v5136,GC_OID((*Generate.c_string)(Generate.PRODUCER->value,
        v5138)),v11276);
      } 
  GC_UNBIND;} 

void  self_statement_Gassign(Gassign *v13492,OID v5134,OID v11276)
{ (*Generate.stat_gassign)(Generate.PRODUCER->value,
    _oid_(v13492),
    v5134,
    v11276);
  } 

void  self_statement_to_protect(Compile_to_protect *v13492,OID v5134,OID v11276)
{ GC_BIND;
  if ((Optimize.OPT->protection == CTRUE) && 
      (Kernel._string == OWNER(v5134)))
   { ClaireClass * v5115 = OBJECT(ClaireClass,(*Optimize.c_sort)(GC_OID(v13492->arg)));
    new_block_void();
    (OBJECT(Generate_producer,Generate.PRODUCER->value)->stat = (OBJECT(Generate_producer,Generate.PRODUCER->value)->stat+1));
    statement_any(GC_OID(v13492->arg),v5134,v11276);
    princ_string(gc_protect_class(v5115));
    princ_string(CSTRING("("));
    if (INHERIT(v5115,Kernel._object))
     { class_princ_class(psort_any((*Optimize.c_type)(GC_OID(v13492->arg))));
      princ_string(CSTRING(","));
      } 
    (*Kernel.c_princ)(v5134);
    princ_string(CSTRING(");"));
    close_block_void();
    } 
  else statement_any(GC_OID(v13492->arg),v5134,v11276);
    GC_UNBIND;} 

void  self_statement_For(For *v13492,OID v5134,OID v11276)
{ (*Generate.stat_for)(Generate.PRODUCER->value,
    _oid_(v13492),
    v5134,
    v11276);
  } 

void  self_statement_Iteration(Iteration *v13492,OID v5134,OID v11276)
{ (*Generate.stat_iteration)(Generate.PRODUCER->value,
    _oid_(v13492),
    v5134,
    v11276);
  } 

void  self_statement_Return(Return *v13492,OID v5134,OID v11276)
{ GC_BIND;
  if (v11276 == CNULL)
   { new_block_void();
    statement_any(GC_OID(v13492->arg),_oid_(Kernel.emptySet),_oid_(Kernel.emptySet));
    princ_string(CSTRING("break;"));
    close_block_void();
    } 
  else if (Kernel._string == OWNER(v11276))
   { new_block_void();
    statement_any(GC_OID(v13492->arg),v11276,_oid_(Kernel.emptySet));
    princ_string(CSTRING("break;"));
    close_block_void();
    } 
  else close_exception(((general_error *) (*Core._general_error)(_string_(CSTRING("[204] break not inside a For or While:~S")),
      _oid_(list::alloc(1,_oid_(v13492))))));
    GC_UNBIND;} 

void  self_statement_Call(Call *v13492,OID v5134,OID v11276)
{ GC_BIND;
  { list * v5124 = GC_OBJECT(list,v13492->args);
    list * v11488 = GC_OBJECT(list,unfold_args_list(v5124));
    { OID  v12827;
      { Call * v14361 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
        (v14361->selector = v13492->selector);
        { Call * v2620 = v14361; 
          list * v2621;
          { bag *v_list; OID v_val;
            OID v5139,CLcount;
            v_list = v5124;
             v2621 = v_list->clone();
            for (CLcount= 1; CLcount <= v_list->length; CLcount++)
            { v5139 = (*(v_list))[CLcount];
              v_val = unfold_arg_list(v5124,v11488,v5139);
              
              (*((list *) v2621))[CLcount] = v_val;} 
            } 
          (v2620->args = v2621);} 
        add_I_property(Kernel.instances,Language._Call,11,_oid_(v14361));
        v12827 = _oid_(v14361);
        } 
      unfold_use_list(v11488,v12827,v5134,v11276);
      } 
    } 
  GC_UNBIND;} 

void  self_statement_Call_method(Call_method *v13492,OID v5134,OID v11276)
{ GC_BIND;
  { list * v5124 = GC_OBJECT(list,v13492->args);
    list * v11488 = GC_OBJECT(list,unfold_args_list(v5124));
    { OID  v15710;
      { Call_method * v14361 = ((Call_method *) GC_OBJECT(Call_method,new_object_class(Language._Call_method)));
        (v14361->arg = v13492->arg);
        { Call_method * v2624 = v14361; 
          list * v2625;
          { bag *v_list; OID v_val;
            OID v5139,CLcount;
            v_list = v5124;
             v2625 = v_list->clone();
            for (CLcount= 1; CLcount <= v_list->length; CLcount++)
            { v5139 = (*(v_list))[CLcount];
              v_val = unfold_arg_list(v5124,v11488,v5139);
              
              (*((list *) v2625))[CLcount] = v_val;} 
            } 
          (v2624->args = v2625);} 
        add_I_property(Kernel.instances,Language._Call_method,11,_oid_(v14361));
        v15710 = _oid_(v14361);
        } 
      unfold_use_list(v11488,v15710,v5134,v11276);
      } 
    } 
  GC_UNBIND;} 

void  self_statement_Call_method1(Call_method1 *v13492,OID v5134,OID v11276)
{ GC_BIND;
  { list * v5124 = GC_OBJECT(list,v13492->args);
    list * v11488 = GC_OBJECT(list,unfold_args_list(v5124));
    { OID  v2209;
      { Call_method1 * v14361 = ((Call_method1 *) GC_OBJECT(Call_method1,new_object_class(Language._Call_method1)));
        (v14361->arg = v13492->arg);
        { Call_method * v2627 = v14361; 
          list * v2628;
          { bag *v_list; OID v_val;
            OID v5139,CLcount;
            v_list = v5124;
             v2628 = v_list->clone();
            for (CLcount= 1; CLcount <= v_list->length; CLcount++)
            { v5139 = (*(v_list))[CLcount];
              v_val = unfold_arg_list(v5124,v11488,v5139);
              
              (*((list *) v2628))[CLcount] = v_val;} 
            } 
          (v2627->args = v2628);} 
        add_I_property(Kernel.instances,Language._Call_method1,11,_oid_(v14361));
        v2209 = _oid_(v14361);
        } 
      unfold_use_list(v11488,v2209,v5134,v11276);
      } 
    } 
  GC_UNBIND;} 

void  self_statement_Call_method2(Call_method2 *v13492,OID v5134,OID v11276)
{ GC_BIND;
  { list * v5124 = GC_OBJECT(list,v13492->args);
    list * v11488 = GC_OBJECT(list,unfold_args_list(v5124));
    { OID  v5092;
      { Call_method2 * v14361 = ((Call_method2 *) GC_OBJECT(Call_method2,new_object_class(Language._Call_method2)));
        (v14361->arg = v13492->arg);
        { Call_method * v2650 = v14361; 
          list * v2651;
          { bag *v_list; OID v_val;
            OID v5139,CLcount;
            v_list = v5124;
             v2651 = v_list->clone();
            for (CLcount= 1; CLcount <= v_list->length; CLcount++)
            { v5139 = (*(v_list))[CLcount];
              v_val = unfold_arg_list(v5124,v11488,v5139);
              
              (*((list *) v2651))[CLcount] = v_val;} 
            } 
          (v2650->args = v2651);} 
        add_I_property(Kernel.instances,Language._Call_method2,11,_oid_(v14361));
        v5092 = _oid_(v14361);
        } 
      unfold_use_list(v11488,v5092,v5134,v11276);
      } 
    } 
  GC_UNBIND;} 

void  self_statement_Super(Super *v13492,OID v5134,OID v11276)
{ (*Generate.stat_super)(Generate.PRODUCER->value,
    _oid_(v13492),
    v5134,
    v11276);
  } 

void  self_statement_Cast(Cast *v13492,OID v5134,OID v11276)
{ GC_BIND;
  statement_any(GC_OID(v13492->arg),v5134,v11276);
  GC_UNBIND;} 

void  self_statement_Handle(ClaireHandle *v13492,OID v5134,OID v11276)
{ (*Generate.stat_handle)(Generate.PRODUCER->value,
    _oid_(v13492),
    v5134,
    v11276);
  } 

void  self_statement_to_CL(Compile_to_CL *v13492,OID v5134,OID v11276)
{ GC_BIND;
  if (Kernel._string == OWNER(v5134))
   { Variable * v904 = GC_OBJECT(Variable,build_Variable_string(string_I_symbol(gensym_string(CSTRING("V_CL"))),_oid_(v13492->set_arg)));
    ClaireClass * v11655 = ((v13492->set_arg == Kernel._void) ?
      Kernel._any :
      v13492->set_arg );
    new_block_void();
    interface_I_class(v11655);
    princ_string(CSTRING(" "));
    expression_Variable(v904,v11276);
    princ_string(CSTRING(";"));
    statement_any(GC_OID(v13492->arg),GC_OID((*Generate.c_string)(Generate.PRODUCER->value,
      _oid_(v904))),v11276);
    breakline_void();
    princ_string(string_v(v5134));
    princ_string(CSTRING("="));
    (*Generate.to_cl)(Generate.PRODUCER->value,
      _oid_(v904),
      _oid_(v13492->set_arg),
      v11276);
    princ_string(CSTRING(";"));
    close_block_void();
    } 
  else statement_any(GC_OID(v13492->arg),v5134,v11276);
    GC_UNBIND;} 

void  self_statement_to_C(Compile_to_C *v13492,OID v5134,OID v11276)
{ GC_BIND;
  if (Kernel._string == OWNER(v5134))
   { Variable * v904 = GC_OBJECT(Variable,build_Variable_string(CSTRING("V_C"),_oid_(Kernel._any)));
    new_block_void();
    (*Generate.any_interface)(Generate.PRODUCER->value);
    princ_string(CSTRING(" "));
    (*Language.ident)(Generate.PRODUCER->value,
      _oid_(v904));
    princ_string(CSTRING(";"));
    statement_any(GC_OID(v13492->arg),GC_OID((*Generate.c_string)(Generate.PRODUCER->value,
      _oid_(v904))),v11276);
    breakline_void();
    princ_string(string_v(v5134));
    princ_string(CSTRING("="));
    (*Generate.to_c)(Generate.PRODUCER->value,
      _oid_(v904),
      _oid_(v13492->set_arg),
      v11276);
    princ_string(CSTRING(";"));
    close_block_void();
    } 
  else statement_any(GC_OID(v13492->arg),v5134,v11276);
    GC_UNBIND;} 

void  self_statement_C_cast(Compile_C_cast *v13492,OID v5134,OID v11276)
{ GC_BIND;
  if (Kernel._string == OWNER(v5134))
   { char * v904 = GC_STRING(check_var_string(CSTRING("V_CC"),v5134,v11276));
    ClaireClass * v11655 = v13492->set_arg;
    ClaireClass * v11656 = stupid_t_any1(GC_OID(v13492->arg));
    ClaireType * v11687 = GC_OBJECT(ClaireType,join_class(osort_any(_oid_(v11655)),v11656));
    new_block_void();
    (*Generate.define_variable)(Generate.PRODUCER->value,
      _oid_(v11687),
      _string_(v904));
    breakline_void();
    statement_any(GC_OID(v13492->arg),_string_(v904),v11276);
    princ_string(string_v(v5134));
    princ_string(CSTRING("= "));
    (*Generate.pointer_cast)(Generate.PRODUCER->value,
      _oid_(v11655));
    princ_string(CSTRING(" "));
    princ_string(v904);
    princ_string(CSTRING(";"));
    close_block_void();
    } 
  else statement_any(GC_OID(v13492->arg),v5134,v11276);
    GC_UNBIND;} 

void  self_statement_Call_slot(Call_slot *v13492,OID v5134,OID v11276)
{ GC_BIND;
  { char * v14364 = GC_STRING(string_I_symbol(gensym_void()));
    Variable * v904 = GC_OBJECT(Variable,build_Variable_string(v14364,(*Optimize.c_type)(GC_OID(v13492->arg))));
    new_block_void();
    interface_I_class(sort_Variable(v904));
    princ_string(CSTRING(" "));
    expression_Variable(v904,_oid_(Kernel.emptySet));
    princ_string(CSTRING(";"));
    breakline_void();
    statement_any(GC_OID(v13492->arg),_string_(v14364),v11276);
    breakline_void();
    if (Kernel._string == OWNER(v5134))
     { c_princ_string(string_v(v5134));
      princ_string(CSTRING(" = "));
      } 
    { Call_slot * v11772;
      { Call_slot * v14361 = ((Call_slot *) GC_OBJECT(Call_slot,new_object_class(Language._Call_slot)));
        (v14361->selector = v13492->selector);
        (v14361->arg = _oid_(v904));
        add_I_property(Kernel.instances,Language._Call_slot,11,_oid_(v14361));
        v11772 = v14361;
        } 
      expression_Call_slot(v11772,v11276);
      } 
    princ_string(CSTRING(";"));
    close_block_void();
    } 
  GC_UNBIND;} 

void  self_statement_Call_table(Call_table *v13492,OID v5134,OID v11276)
{ GC_BIND;
  { char * v14364 = GC_STRING(string_I_symbol(gensym_void()));
    Variable * v904 = GC_OBJECT(Variable,build_Variable_string(v14364,(*Optimize.c_type)(GC_OID(v13492->arg))));
    new_block_void();
    interface_I_class(sort_Variable(v904));
    princ_string(CSTRING(" "));
    expression_Variable(v904,_oid_(Kernel.emptySet));
    princ_string(CSTRING(";"));
    breakline_void();
    statement_any(GC_OID(v13492->arg),_string_(v14364),v11276);
    breakline_void();
    if (Kernel._string == OWNER(v5134))
     { c_princ_string(string_v(v5134));
      princ_string(CSTRING(" = "));
      } 
    { Call_table * v12733;
      { Call_table * v14361 = ((Call_table *) GC_OBJECT(Call_table,new_object_class(Language._Call_table)));
        (v14361->selector = v13492->selector);
        (v14361->arg = _oid_(v904));
        add_I_property(Kernel.instances,Language._Call_table,11,_oid_(v14361));
        v12733 = v14361;
        } 
      expression_Call_table(v12733,v11276);
      } 
    princ_string(CSTRING(";"));
    close_block_void();
    } 
  GC_UNBIND;} 

void  self_statement_Call_array(Call_array *v13492,OID v5134,OID v11276)
{ GC_BIND;
  { Variable * v11690 = GC_OBJECT(Variable,build_Variable_string(CSTRING("va_arg1"),_oid_(Kernel._array)));
    Variable * v11691 = GC_OBJECT(Variable,build_Variable_string(CSTRING("va_arg2"),_oid_(Kernel._integer)));
    new_block_void();
    interface_I_class(Kernel._array);
    princ_string(CSTRING(" "));
    expression_Variable(v11690,_oid_(Kernel.emptySet));
    princ_string(CSTRING(";"));
    breakline_void();
    interface_I_class(Kernel._integer);
    princ_string(CSTRING(" "));
    expression_Variable(v11691,_oid_(Kernel.emptySet));
    princ_string(CSTRING(";"));
    breakline_void();
    statement_any(GC_OID(v13492->selector),_string_(CSTRING("va_arg1")),v11276);
    statement_any(GC_OID(v13492->arg),_string_(CSTRING("va_arg2")),v11276);
    if (Kernel._string == OWNER(v5134))
     { c_princ_string(string_v(v5134));
      princ_string(CSTRING(" = "));
      } 
    { Call_array * v13694;
      { Call_array * v14361 = ((Call_array *) GC_OBJECT(Call_array,new_object_class(Language._Call_array)));
        (v14361->selector = _oid_(v11690));
        (v14361->arg = _oid_(v11691));
        (v14361->test = v13492->test);
        add_I_property(Kernel.instances,Language._Call_array,11,_oid_(v14361));
        v13694 = v14361;
        } 
      expression_Call_array(v13694,v11276);
      } 
    princ_string(CSTRING(";"));
    close_block_void();
    } 
  GC_UNBIND;} 

void  self_statement_Update(Update *v13492,OID v5134,OID v11276)
{ GC_BIND;
  { OID  v5104 = GC_OID(v13492->var);
    OID  v5128 = GC_OID(v13492->selector);
    ClaireType * v11654;
    { if (INHERIT(OWNER(v5104),Language._Call_slot))
       v11654 = domain_I_restriction(OBJECT(Call_slot,v5104)->selector);
      else if (INHERIT(OWNER(v5104),Language._Call_array))
       v11654 = Kernel._integer;
      else v11654 = U_type(Kernel._any,GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Kernel.domain)(v5128))));
        GC_OBJECT(ClaireType,v11654);} 
    ClaireType * v11655;
    { if (INHERIT(OWNER(v5104),Language._Call_slot))
       { v11655 = ((v13492->arg == _oid_(Kernel.add)) ?
          member_type(OBJECT(Call_slot,v5104)->selector->range) :
          OBJECT(Call_slot,v5104)->selector->range );
        } 
      else if (INHERIT(OWNER(v5104),Language._Call_array))
       { v11655 = (((OBJECT(ClaireBoolean,(*Core._inf_equalt)(GC_OID(OBJECT(Call_array,v5104)->test),
          _oid_(Kernel._float)))) == CTRUE) ?
          Kernel._float :
          Kernel._any );
        } 
      else v11655 = U_type(Kernel._any,GC_OBJECT(ClaireType,((v13492->arg == _oid_(Kernel.add)) ?
          member_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Kernel.range)(v5128)))) :
          OBJECT(ClaireType,(*Kernel.range)(v5128)) )));
        GC_OBJECT(ClaireType,v11655);} 
    ClaireClass * v2921 = stupid_t_any1(GC_OID((*Kernel.arg)(v13492->var)));
    ClaireClass * v2922 = stupid_t_any1(GC_OID(v13492->value));
    OID  v12665;
    { if ((_inf_equalt_class(v2921,psort_any(_oid_(v11654))) != CTRUE) && 
          (_inf_equalt_class(v2921,Kernel._object) == CTRUE))
       { Compile_C_cast * v14361 = ((Compile_C_cast *) GC_OBJECT(Compile_C_cast,new_object_class(Optimize._C_cast)));
        (v14361->arg = (*Kernel.arg)(GC_OID(v13492->var)));
        (v14361->set_arg = psort_any(_oid_(v11654)));
        add_I_property(Kernel.instances,Optimize._C_cast,11,_oid_(v14361));
        v12665 = _oid_(v14361);
        } 
      else v12665 = (*Kernel.arg)(GC_OID(v13492->var));
        GC_OID(v12665);} 
    OID  v3028;
    { if ((_inf_equalt_class(v2922,psort_any(_oid_(v11655))) != CTRUE) && 
          (_inf_equalt_class(v2922,Kernel._object) == CTRUE))
       { Compile_C_cast * v14361 = ((Compile_C_cast *) GC_OBJECT(Compile_C_cast,new_object_class(Optimize._C_cast)));
        (v14361->arg = v13492->value);
        (v14361->set_arg = psort_any(_oid_(v11655)));
        add_I_property(Kernel.instances,Optimize._C_cast,11,_oid_(v14361));
        v3028 = _oid_(v14361);
        } 
      else v3028 = v13492->value;
        GC_OID(v3028);} 
    Variable * v11690 = GC_OBJECT(Variable,Variable_I_symbol(gensym_void(),0,v11654));
    Variable * v11691 = GC_OBJECT(Variable,Variable_I_symbol(gensym_void(),0,v11655));
    ClaireBoolean * v11127 = c_func_any(v12665);
    new_block_void();
    interface_I_class(psort_any(_oid_(v11654)));
    princ_string(CSTRING(" "));
    expression_Variable(v11690,_oid_(Kernel.emptySet));
    princ_string(CSTRING(" "));
    if (v11127 == CTRUE)
     { princ_string(CSTRING("= "));
      (*Generate.expression)(v12665,
        _oid_(Kernel.emptySet));
      princ_string(CSTRING(""));
      } 
    princ_string(CSTRING("; "));
    breakline_void();
    interface_I_class(psort_any(_oid_(v11655)));
    princ_string(CSTRING(" "));
    expression_Variable(v11691,_oid_(Kernel.emptySet));
    princ_string(CSTRING(";"));
    breakline_void();
    if (v11127 != CTRUE)
     statement_any(v12665,GC_OID((*Generate.c_string)(Generate.PRODUCER->value,
      _oid_(v11690))),v11276);
    statement_any(v3028,GC_OID((*Generate.c_string)(Generate.PRODUCER->value,
      _oid_(v11691))),v11276);
    if (Kernel._string == OWNER(v5134))
     { c_princ_string(string_v(v5134));
      princ_string(CSTRING(" = "));
      } 
    { Update * v14655;
      { Update * v14361 = ((Update *) GC_OBJECT(Update,new_object_class(Language._Update)));
        (v14361->selector = v5128);
        { Update * v2656 = v14361; 
          OID  v2657;
          if (v13492->arg == _oid_(Kernel.add))
           v2657 = _oid_(Kernel.add);
          else if (sort_Variable(v11690) == Kernel._any)
           v2657 = _oid_(v11690);
          else { Compile_to_CL * v14361 = ((Compile_to_CL *) GC_OBJECT(Compile_to_CL,new_object_class(Optimize._to_CL)));
              (v14361->arg = _oid_(v11690));
              (v14361->set_arg = sort_Variable(v11690));
              add_I_property(Kernel.instances,Optimize._to_CL,11,_oid_(v14361));
              v2657 = _oid_(v14361);
              } 
            (v2656->arg = v2657);} 
        (v14361->value = _oid_(v11691));
        { Update * v2658 = v14361; 
          OID  v2659;
          { OID  v11880 = GC_OID((*Kernel.copy)(v5104));
            put_property2(Kernel.arg,OBJECT(ClaireObject,v11880),_oid_(v11690));
            v2659 = v11880;
            } 
          (v2658->var = v2659);} 
        add_I_property(Kernel.instances,Language._Update,11,_oid_(v14361));
        v14655 = v14361;
        } 
      expression_Update(v14655,v11276);
      } 
    princ_string(CSTRING(";"));
    close_block_void();
    } 
  GC_UNBIND;} 

