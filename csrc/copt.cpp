/***** CLAIRE Compilation of file e:\claire\v3.5\src\compile\copt.cl 
         [version 3.5.0 / safety 5] Sun May 28 08:26:01 2017 *****/

#include <claire.h>
#include <Kernel.h>
#include <Core.h>
#include <Language.h>
#include <Reader.h>
#include <Optimize.h>
#include <Generate.h>
void  inline_exp_c_producer1(Generate_c_producer *v5115,Call_method1 *v13492,OID v11276)
{ GC_BIND;
  { method * v5125 = v13492->arg;
    property * v5128 = v5125->selector;
    OID  v11096 = GC_OID(car_list(v13492->args));
    if ((v5128 == Kernel._dash) && 
        ((domain_I_restriction(v5125) == Kernel._integer) || 
            (domain_I_restriction(v5125) == Kernel._float)))
     { princ_string(CSTRING("(-"));
      bexpression_any(v11096,v11276);
      princ_string(CSTRING(")"));
      } 
    else if ((v5128 == Core.owner) && 
        (designated_ask_any(v11096) == CTRUE))
     { princ_string(CSTRING("OWNER("));
      (*Generate.expression)(v11096,
        v11276);
      princ_string(CSTRING(")"));
      } 
    else if ((v5128 == Core.sqrt) && 
        (domain_I_restriction(v5125) == Kernel._float))
     { princ_string(CSTRING("sqrt("));
      (*Generate.expression)(v11096,
        v11276);
      princ_string(CSTRING(")"));
      } 
    else if ((v5128 == Core.eval) && 
        (designated_ask_any(v11096) == CTRUE))
     { princ_string(CSTRING("OPT_EVAL("));
      (*Generate.expression)(v11096,
        v11276);
      princ_string(CSTRING(")"));
      } 
    else if (v5128 == Core.externC)
     (*Kernel.princ)(v11096);
    else if ((_oid_(v5125) == Generate._starlength_bag_star->value) && 
        (designated_ask_any(v11096) == CTRUE))
     { (*Generate.expression)(v11096,
        v11276);
      princ_string(CSTRING("->length"));
      } 
    else if ((v5128 == Kernel.integer_I) && 
        ((domain_I_restriction(v5125) == Kernel._char) && 
          (designated_ask_any(v11096) == CTRUE)))
     { (*Generate.expression)(v11096,
        v11276);
      princ_string(CSTRING("->ascii"));
      } 
    else if (_oid_(v5125) == Generate._starlength_array_star->value)
     { (*Generate.expression)(v11096,
        v11276);
      princ_string(CSTRING("[0]"));
      } 
    else if ((_oid_(v5125) == Generate._starnot_star->value) && 
        (_inf_equal_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(v11096))),Kernel._boolean) == CTRUE))
     { princ_string(CSTRING("(("));
      (*Generate.expression)(v11096,
        v11276);
      princ_string(CSTRING(" == Kernel.ctrue) ? CFALSE : CTRUE)"));
      } 
    else print_external_call_c_producer(v5115,v13492,v11276);
      } 
  GC_UNBIND;} 

void  inline_exp_c_producer2(Generate_c_producer *v5115,Call_method2 *v13492,OID v11276)
{ GC_BIND;
  { method * v5125 = v13492->arg;
    property * v5128 = v5125->selector;
    OID  v11096 = GC_OID((*(v13492->args))[1]);
    OID  v11098 = GC_OID((*(v13492->args))[2]);
    if ((_oid_(v5125) == Generate._starmin_integer_star->value) && 
        ((designated_ask_any(v11096) == CTRUE) && 
          (designated_ask_any(v11098) == CTRUE)))
     { princ_string(CSTRING("(("));
      (*Generate.expression)(v11096,
        v11276);
      princ_string(CSTRING(" <= "));
      (*Generate.expression)(v11098,
        v11276);
      princ_string(CSTRING(") ? "));
      (*Generate.expression)(v11096,
        v11276);
      princ_string(CSTRING(" : "));
      (*Generate.expression)(v11098,
        v11276);
      princ_string(CSTRING(")"));
      } 
    else if ((_oid_(v5125) == Generate._starmax_integer_star->value) && 
        ((designated_ask_any(v11096) == CTRUE) && 
          (designated_ask_any(v11098) == CTRUE)))
     { princ_string(CSTRING("(("));
      (*Generate.expression)(v11096,
        v11276);
      princ_string(CSTRING(" <= "));
      (*Generate.expression)(v11098,
        v11276);
      princ_string(CSTRING(") ? "));
      (*Generate.expression)(v11098,
        v11276);
      princ_string(CSTRING(" : "));
      (*Generate.expression)(v11096,
        v11276);
      princ_string(CSTRING(")"));
      } 
    else if ((v5128 == Core.class_I) && 
        (INHERIT(OWNER(v11096),Kernel._symbol)))
     { princ_string(CSTRING("("));
      ident_thing(defined_symbol(OBJECT(symbol,v11096)));
      princ_string(CSTRING("._"));
      c_princ_string(string_v((*Kernel.string_I)(v11096)));
      princ_string(CSTRING(" = ClaireClass::make("));
      print_any(GC_OID((*Kernel.string_I)(v11096)));
      princ_string(CSTRING(","));
      (*Generate.expression)(v11098,
        v11276);
      princ_string(CSTRING(","));
      ident_thing(OBJECT(thing,(*Kernel.module_I)(v11096)));
      princ_string(CSTRING(".it))"));
      } 
    else if ((v5115->open_operators->memq(_oid_(v5128)) == CTRUE) && 
        (((v5128 != Kernel._7) || 
            (5 <= Optimize.compiler->safety)) && 
          ((equal((*(v5125->domain))[1],(*(v5125->domain))[2]) == CTRUE) && 
            ((_inf_equal_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(v11096))),Kernel._integer) == CTRUE) || 
                (_inf_equal_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(v11096))),Kernel._float) == CTRUE)))))
     { if ((Optimize.compiler->safety < 2) && 
          (_inf_equal_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(v11096))),Kernel._integer) == CTRUE))
       princ_string(CSTRING("_integer_"));
      princ_string(CSTRING("("));
      bexpression_any(v11096,v11276);
      princ_string(string_I_symbol(v5128->name));
      bexpression_any(v11098,v11276);
      princ_string(CSTRING(")"));
      } 
    else if ((_oid_(v5125) == Generate._starcontain_star->value) && 
        (identifiable_ask_any(v11098) == CTRUE))
     { (*Generate.expression)(v11096,
        v11276);
      princ_string(CSTRING("->memq("));
      (*Generate.expression)(v11098,
        v11276);
      princ_string(CSTRING(")"));
      } 
    else if (((_oid_(v5125) == Generate._starnth_list_star->value) && 
          (2 <= Optimize.compiler->safety)) || 
        (_oid_(v5125) == Generate._starnth_1_bag_star->value))
     { princ_string(CSTRING("(*("));
      (*Generate.expression)(v11096,
        v11276);
      princ_string(CSTRING("))["));
      (*Generate.expression)(v11098,
        v11276);
      princ_string(CSTRING("]"));
      } 
    else if ((v5128 == Kernel.add_I) && 
        (_inf_equal_type(domain_I_restriction(v5125),Kernel._bag) == CTRUE))
     { (*Generate.expression)(v11096,
        v11276);
      princ_string(CSTRING("->addFast("));
      (*Generate.expression)(v11098,
        v11276);
      princ_string(CSTRING(")"));
      } 
    else if ((_oid_(v5125) == Generate._starnth_string_star->value) && 
        (2 <= Optimize.compiler->safety))
     { princ_string(CSTRING("_char_("));
      (*Generate.expression)(v11096,
        v11276);
      princ_string(CSTRING("["));
      (*Generate.expression)(v11098,
        v11276);
      princ_string(CSTRING(" - 1])"));
      } 
    else if (v5125->selector == Core.identical_ask)
     { princ_string(CSTRING("("));
      (*Optimize.bool_exp)(_oid_(v13492),
        Kernel.ctrue,
        v11276);
      princ_string(CSTRING(" ? CTRUE : CFALSE)"));
      } 
    else if (v5125->selector == Core.externC)
     (*Kernel.princ)(v11096);
    else if ((v5128 == Core.inlineok_ask) && 
        (Kernel._string == OWNER(v11098)))
     { (*Generate.expression)(v11096,
        v11276);
      princ_string(CSTRING("->inlineDef("));
      print_any(v11098);
      princ_string(CSTRING(")"));
      } 
    else print_external_call_c_producer(v5115,v13492,v11276);
      } 
  GC_UNBIND;} 

void  inline_exp_c_producer3(Generate_c_producer *v5115,Call_method *v13492,OID v11276)
{ GC_BIND;
  { method * v5125 = v13492->arg;
    ClaireBoolean * v5114 = Optimize.OPT->alloc_stack;
    OID  v11096 = GC_OID((*(v13492->args))[1]);
    OID  v11098 = GC_OID((*(v13492->args))[2]);
    OID  v11099 = GC_OID((*(v13492->args))[3]);
    (Optimize.OPT->alloc_stack = CFALSE);
    if ((_oid_(v5125) == Generate._starnth_equal_list_star->value) && 
        (3 <= Optimize.compiler->safety))
     { princ_string(CSTRING("((*("));
      (*Generate.expression)(v11096,
        v11276);
      princ_string(CSTRING("))["));
      (*Generate.expression)(v11098,
        v11276);
      princ_string(CSTRING("]="));
      (*Generate.expression)(v11099,
        v11276);
      princ_string(CSTRING(")"));
      } 
    else if ((domain_I_restriction(v5125) == Kernel._string) && 
        (((v5125->selector == Kernel.nth_equal) && 
              (2 <= Optimize.compiler->safety)) || 
            (v5125->selector == Kernel.nth_put)))
     { princ_string(CSTRING("("));
      (*Generate.expression)(v11096,
        v11276);
      princ_string(CSTRING("["));
      (*Generate.expression)(v11098,
        v11276);
      princ_string(CSTRING(" - 1] = (char) "));
      (*Generate.expression)(v11099,
        v11276);
      princ_string(CSTRING("->ascii)"));
      } 
    else if (_oid_(v5125) == Generate._starnth_1_string_star->value)
     { princ_string(CSTRING("_char_("));
      (*Generate.expression)(v11096,
        v11276);
      princ_string(CSTRING("["));
      (*Generate.expression)(v11098,
        v11276);
      princ_string(CSTRING(" - 1])"));
      } 
    else if ((v5125->selector == Kernel.store) && 
        ((_inf_equal_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(v11096))),Kernel._list) == CTRUE) && 
          (((v13492->args->length == 4) && 
                ((*(v13492->args))[4] == Kernel.ctrue)) || 
              (v13492->args->length == 3))))
     { princ_string(CSTRING("STOREI((*"));
      (*Generate.expression)(v11096,
        v11276);
      princ_string(CSTRING(")["));
      (*Generate.expression)(v11098,
        v11276);
      princ_string(CSTRING("],"));
      (*Generate.expression)(v11099,
        v11276);
      princ_string(CSTRING(")"));
      } 
    else if ((v5125->selector == Kernel.store) && 
        ((_inf_equal_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(v11096))),Kernel._array) == CTRUE) && 
          ((equal(_oid_(_exp_type(GC_OBJECT(ClaireType,member_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(v11096))))),Kernel._float)),_oid_(Kernel.emptySet)) == CTRUE) && 
            (((v13492->args->length == 4) && 
                  ((*(v13492->args))[4] == Kernel.ctrue)) || 
                (v13492->args->length == 3)))))
     { princ_string(CSTRING("STOREI("));
      (*Generate.expression)(v11096,
        v11276);
      princ_string(CSTRING("["));
      (*Generate.expression)(v11098,
        v11276);
      princ_string(CSTRING("],"));
      (*Generate.expression)(v11099,
        v11276);
      princ_string(CSTRING(")"));
      } 
    else if ((v5125->selector == Kernel.add_slot) && 
        (INHERIT(owner_any(getC_any(v11096)),Kernel._class)))
     { princ_string(CSTRING("CL_ADD_SLOT("));
      (*Generate.expression)(v11096,
        v11276);
      princ_string(CSTRING(","));
      class_princ_class(OBJECT(ClaireClass,getC_any(v11096)));
      princ_string(CSTRING(","));
      (*Generate.expression)(v11098,
        v11276);
      princ_string(CSTRING(","));
      ident_symbol(OBJECT(symbol,(*Kernel.name)(GC_OID(getC_any(v11098)))));
      princ_string(CSTRING(","));
      (*Generate.expression)(GC_OID(getC_any(v11099)),
        v11276);
      princ_string(CSTRING(","));
      (*Generate.expression)(GC_OID((*(v13492->args))[4]),
        v11276);
      princ_string(CSTRING(")"));
      } 
    else if (v5125->selector == Kernel.add_method)
     { if (INHERIT(OWNER(v11096),Kernel._property))
       { (*Generate.expression)(v11096,
          v11276);
        princ_string(CSTRING("->add"));
        if (v13492->args->length > 5)
         princ_string(CSTRING("Float"));
        princ_string(CSTRING("Method("));
        signature_I_c_producer(v5115,v11098);
        princ_string(CSTRING(","));
        (*Generate.expression)(v11099,
          v11276);
        princ_string(CSTRING(","));
        breakline_void();
        princ_string(CSTRING("\t"));
        bitvector_I_c_producer(v5115,GC_OID((*(v13492->args))[4]));
        princ_string(CSTRING(","));
        (*Generate.expression)(GC_OID((*(v13492->args))[5]),
          v11276);
        if (v13492->args->length > 5)
         { princ_string(CSTRING(","));
          (*Generate.expression)(GC_OID((*(v13492->args))[6]),
            v11276);
          } 
        princ_string(CSTRING(")"));
        } 
      else { princ_string(CSTRING("add_method_property("));
          args_list_bag(GC_OBJECT(list,v13492->args),v11276,CTRUE);
          princ_string(CSTRING(")"));
          } 
        } 
    else { (Optimize.OPT->alloc_stack = v5114);
        print_external_call_c_producer(v5115,v13492,v11276);
        } 
      (Optimize.OPT->alloc_stack = v5114);
    } 
  GC_UNBIND;} 

void  print_external_call_c_producer(Generate_c_producer *v5115,Call_method *v13492,OID v11276)
{ GC_BIND;
  { method * v5125 = v13492->arg;
    list * v5124 = GC_OBJECT(list,v13492->args);
    Cint  v5126 = 1;
    list * v11488 = v5125->domain;
    c_princ_function(OBJECT(ClaireFunction,(*Optimize.functional_I)(_oid_(v5125))));
    princ_string(CSTRING("("));
    if (v5124->length > 4)
     (Optimize.OPT->level = (Optimize.OPT->level+1));
    if ((v5124->length == 1) && 
        (domain_I_restriction(v5125) == Kernel._void))
     v5124= Kernel.nil;
    { ITERATE(v5136);
      for (START(v5124); NEXT(v5136);)
      { if (v5126 != 1)
         { princ_string(CSTRING(","));
          if (v5124->length > 4)
           breakline_void();
          } 
        { ClaireClass * v11654 = psort_any((*(v11488))[v5126]);
          ClaireClass * v11655 = stupid_t_any1(v5136);
          if ((_inf_equalt_class(v11654,Kernel._object) == CTRUE) && 
              (_inf_equalt_class(v11655,v11654) != CTRUE))
           { princ_string(CSTRING("("));
            class_princ_class(v11654);
            princ_string(CSTRING(" *) "));
            } 
          } 
        (*Generate.expression)(v5136,
          v11276);
        ++v5126;
        } 
      } 
    princ_string(CSTRING(")"));
    if ((INHERIT(v5125->range->isa,Kernel._tuple)) && 
        (Optimize.OPT->alloc_stack != CTRUE))
     princ_string(CSTRING("->copyIfNeeded()"));
    if (v5124->length > 4)
     (Optimize.OPT->level = (Optimize.OPT->level-1));
    } 
  GC_UNBIND;} 

void  inline_exp_c_producer5(Generate_c_producer *v5115,Call *v13492,OID v11276)
{ GC_BIND;
  { property * v5128 = v13492->selector;
    OID  v11096 = GC_OID(car_list(v13492->args));
    Cint  v5126 = v13492->args->length;
    if (v5128 == Core.get_stack)
     { princ_string(CSTRING("ClEnv->stack["));
      (*Generate.expression)(v11096,
        v11276);
      princ_string(CSTRING("]"));
      } 
    else if (v5128 == Optimize.safe)
     { Cint  v5137 = Optimize.compiler->safety;
      (Optimize.compiler->safety = 1);
      (*Generate.expression)((*(v13492->args))[1],
        v11276);
      (Optimize.compiler->safety = v5137);
      } 
    else if (v5128 == Core.base_I)
     princ_string(CSTRING("ClEnv->base"));
    else if ((v5128 == Core.index_I) && 
        (v5126 == 1))
     princ_string(CSTRING("ClEnv->index"));
    else if ((v5128 == Core.push_I) && 
        (v5126 == 1))
     { princ_string(CSTRING("PUSH("));
      (*Generate.expression)(v11096,
        v11276);
      princ_string(CSTRING(")"));
      } 
    else if (v5128 == Core.put_stack)
     { princ_string(CSTRING("(ClEnv->stack["));
      (*Generate.expression)(v11096,
        v11276);
      princ_string(CSTRING("]="));
      (*Generate.expression)((*(v13492->args))[2],
        v11276);
      princ_string(CSTRING(")"));
      } 
    else if (v5128 == Core.set_base)
     { princ_string(CSTRING("(ClEnv->base= "));
      (*Generate.expression)(v11096,
        v11276);
      princ_string(CSTRING(")"));
      } 
    else if (v5128 == Core.set_index)
     { princ_string(CSTRING("(ClEnv->index= "));
      (*Generate.expression)(v11096,
        v11276);
      princ_string(CSTRING(")"));
      } 
    else if (v5128 == Optimize.object_I)
     { OID  v11098 = (*(v13492->args))[2];
      princ_string(CSTRING("("));
      ident_thing(defined_symbol(OBJECT(symbol,v11096)));
      princ_string(CSTRING("."));
      if (_inf_equal_type(OBJECT(ClaireType,v11098),Reader._reserved_keyword) == CTRUE)
       { princ_string(CSTRING("_cl_"));
        c_princ_string(string_v((*Kernel.string_I)(v11096)));
        } 
      else (*Language.ident)(v11096);
        princ_string(CSTRING(" = "));
      if ((v11098 == _oid_(Kernel._property)) && 
          (INHERIT(owner_any((*Kernel.value)(v11096)),Kernel._property)))
       { princ_string(CSTRING("property::make("));
        print_any(GC_OID((*Kernel.string_I)(v11096)));
        princ_string(CSTRING(","));
        princ_integer((*Kernel.open)(GC_OID((*Kernel.value)(v11096))));
        princ_string(CSTRING(","));
        expression_thing(OBJECT(thing,(*Kernel.module_I)(v11096)),Core.nil->value);
        princ_string(CSTRING(","));
        (*Generate.expression)(GC_OID((*Kernel.domain)(GC_OID((*Kernel.value)(v11096)))),
          Core.nil->value);
        princ_string(CSTRING(","));
        (*Kernel.princ)(GC_OID((*Kernel.dispatcher)(GC_OID((*Kernel.value)(v11096)))));
        princ_string(CSTRING(")"));
        } 
      else { princ_string(CSTRING("("));
          class_princ_class(OBJECT(ClaireClass,v11098));
          princ_string(CSTRING(" *) "));
          (*Generate.expression)(v11098,
            v11276);
          princ_string(CSTRING("->instantiate("));
          print_any(GC_OID((*Kernel.string_I)(v11096)));
          princ_string(CSTRING(","));
          expression_thing(OBJECT(thing,(*Kernel.module_I)(v11096)),Core.nil->value);
          princ_string(CSTRING(")"));
          } 
        princ_string(CSTRING(")"));
      } 
    else if (v5128 == Optimize.anyObject_I)
     { princ_string(CSTRING("(("));
      class_princ_class(OBJECT(ClaireClass,v11096));
      princ_string(CSTRING(" *) (*"));
      (*Generate.expression)(v11096,
        v11276);
      princ_string(CSTRING(")("));
      args_list_bag(GC_OBJECT(list,cdr_list(GC_OBJECT(list,v13492->args))),v11276,_sup_integer(v13492->args->length,2));
      princ_string(CSTRING("))"));
      } 
    else if ((OBJECT(ClaireBoolean,(*Generate.fcall_ask)(_oid_(v13492)))) == CTRUE)
     (*Generate.fcall_exp)(_oid_(v13492),
      v11276);
    else if (v13492->args->length > 20)
     { if (v13492->selector == Kernel.store)
       { list * v5124 = GC_OBJECT(list,v13492->args);
        Cint  v5126 = v5124->length;
        Cint  v5125 = (v5126/10);
        princ_string(CSTRING("("));
        { Cint  v5121 = 0;
          Cint  v2720 = v5125;
          { OID gc_local;
            while ((v5121 <= v2720))
            { GC_LOOP;
              princ_string(CSTRING("(*"));
              expression_thing(Kernel.store,v11276);
              princ_string(CSTRING(")("));
              { list * v919;
                { list * v11851 = list::empty(Kernel.emptySet);
                  { Cint  v5122 = ((v5121*10)+1);
                    Cint  v2721 = ((v5121 == v5125) ?
                      v5126 :
                      ((v5121*10)+10) );
                    { OID gc_local;
                      while ((v5122 <= v2721))
                      { v11851->addFast((*(v5124))[v5122]);
                        ++v5122;
                        } 
                      } 
                    } 
                  v919 = GC_OBJECT(list,v11851);
                  } 
                args_list_bag(v919,v11276,CTRUE);
                } 
              princ_string(CSTRING(")"));
              if (v5121 != v5125)
               princ_string(CSTRING(","));
              ++v5121;
              GC_UNLOOP;} 
            } 
          } 
        princ_string(CSTRING(")"));
        } 
      else close_exception(((general_error *) (*Core._general_error)(_string_(CSTRING("[216] ~S has more than 10 parameters")),
          _oid_(list::alloc(1,_oid_(v13492))))));
        } 
    else { princ_string(CSTRING("(*"));
        expression_thing(v13492->selector,v11276);
        princ_string(CSTRING(")("));
        args_list_bag(GC_OBJECT(list,v13492->args),v11276,_sup_integer(v13492->args->length,1));
        princ_string(CSTRING(")"));
        } 
      } 
  GC_UNBIND;} 

ClaireBoolean * fcall_ask_Call2_Generate(Call *v5136)
{ GC_RESERVE(1);  // HOHO v3.0.55 optim !
  { ClaireBoolean *Result ;
    { property * v5128 = v5136->selector;
      OID  v11096 = GC_OID((*(v5136->args))[1]);
      Cint  v10217;
      { list * v1880;
        { bag * v6163 = v5136->args;
          list * v544 = ((list *) empty_bag(v6163));
          { OID gc_local;
            ITERATE(v5137);
            for (START(v6163); NEXT(v5137);)
            if ((OBJECT(ClaireBoolean,(*Optimize.c_gc_ask)(v5137))) == CTRUE)
             v544->addFast(v5137);
            } 
          v1880 = GC_OBJECT(list,v544);
          } 
        v10217 = v1880->length;
        } 
      { ClaireBoolean *v_and;
        { v_and = ((designated_ask_any(v11096) == CTRUE) ? CTRUE : ((v5128->dispatcher > 0) ? CTRUE : CFALSE));
          if (v_and == CFALSE) Result =CFALSE; 
          else { { list * v5124 = GC_OBJECT(list,cdr_list(GC_OBJECT(list,v5136->args)));
              ClaireType * v15479 = Kernel.emptySet;
              list * v11504;
              { { bag *v_list; OID v_val;
                  OID v5137,CLcount;
                  v_list = GC_OBJECT(list,v5136->args);
                   v11504 = v_list->clone();
                  for (CLcount= 1; CLcount <= v_list->length; CLcount++)
                  { v5137 = (*(v_list))[CLcount];
                    v_val = _oid_(ptype_type(OBJECT(ClaireType,(*Optimize.c_type)(v5137))));
                    
                    (*((list *) v11504))[CLcount] = v_val;} 
                  } 
                GC_OBJECT(list,v11504);} 
              list * v12610 = GC_OBJECT(list,cdr_list(v11504));
              list * v11502 = GC_OBJECT(list,get_restrictions_Call2(v5136,v11504));
              ClaireBoolean * v8014;
              { ClaireBoolean *v_and;
                { v_and = ((v11502->length > 0) ? CTRUE : CFALSE);
                  if (v_and == CFALSE) v8014 =CFALSE; 
                  else { { ClaireBoolean *v_or;
                      { v_or = ((v10217 == 0) ? CTRUE : CFALSE);
                        if (v_or == CTRUE) v_and =CTRUE; 
                        else { { OID  v2841;
                            { OID gc_local;
                              ITERATE(v5125);
                              v2841= Kernel.cfalse;
                              for (START(v11502); NEXT(v5125);)
                              if (not_any(_oid_(nth_integer(status_I_restriction(OBJECT(restriction,v5125)),1))) != CTRUE)
                               { v2841 = Kernel.ctrue;
                                break;} 
                              } 
                            v_or = not_any(v2841);
                            } 
                          if (v_or == CTRUE) v_and =CTRUE; 
                          else v_and = CFALSE;} 
                        } 
                      } 
                    if (v_and == CFALSE) v8014 =CFALSE; 
                    else { v_and = (((v5128->dispatcher > 0) && 
                          (v5124->length <= 4)) ? CTRUE : ((v11502->length < 3) ? CTRUE : CFALSE));
                      if (v_and == CFALSE) v8014 =CFALSE; 
                      else v8014 = CTRUE;} 
                    } 
                  } 
                } 
              ClaireClass * v5134 = ((v11502->length > 0) ?
                c_srange_method(OBJECT(method,(*(v11502))[1])) :
                Kernel._void );
              ClaireBoolean * v13130;
              { OID  v3802;
                { OID gc_local;
                  ITERATE(v5130);
                  v3802= Kernel.cfalse;
                  for (START(v11502); NEXT(v5130);)
                  { GC_LOOP;
                    { ClaireBoolean * g0084I;
                      { OID  v5724;
                        { GC__ANY(v15479 = U_type(v15479,domain_I_restriction(OBJECT(restriction,v5130))), 1);
                          v5724 = _oid_(((INHERIT(OWNER((*(OBJECT(restriction,v5130)->domain))[1]),Kernel._class)) ? ((last_list(OBJECT(restriction,v5130)->domain) != _oid_(Kernel._listargs)) ? ((tmatch_ask_list(v12610,GC_OBJECT(list,cdr_list(OBJECT(restriction,v5130)->domain))) == CTRUE) ? ((c_srange_method(OBJECT(method,v5130)) == v5134) ? CTRUE: CFALSE): CFALSE): CFALSE): CFALSE));
                          } 
                        g0084I = not_any(v5724);
                        } 
                      
                      if (g0084I == CTRUE) { v3802 = Kernel.ctrue;
                          break;} 
                        } 
                    GC_UNLOOP;} 
                  } 
                v13130 = not_any(v3802);
                } 
              ClaireBoolean * v4130 = (((v5134 == Kernel._integer) || 
                  ((v5134 == Kernel._object) || 
                    ((v5134 == Kernel._any) || 
                      (v5134 == Kernel._void)))) ? ((_inf_equal_type(v15479,Kernel._object) == CTRUE) ? ((_inf_equal_type(GC_OBJECT(ClaireType,ptype_type(OBJECT(ClaireType,(*Optimize.c_type)(v11096)))),v15479) == CTRUE) ? CTRUE: CFALSE): CFALSE): CFALSE);
              if (((OBJECT(ClaireBoolean,Generate.FCALLSTINKS->value)) == CTRUE) && 
                  ((((v8014 == CTRUE) ? ((v13130 == CTRUE) ? ((v4130 == CTRUE) ? CTRUE: CFALSE): CFALSE): CFALSE) != CTRUE) && 
                    (v5128->dispatcher > 0)))
               tformat_string(CSTRING("****> fcall(~S) fails (selectorOK = ~S , lrOK = ~S, callOK = ~S)\n"),0,GC_OBJECT(list,list::alloc(4,_oid_(v5136),
                _oid_(v8014),
                _oid_(v13130),
                _oid_(v4130))));
              v_and = ((v8014 == CTRUE) ? ((v13130 == CTRUE) ? ((v4130 == CTRUE) ? CTRUE: CFALSE): CFALSE): CFALSE);
              } 
            if (v_and == CFALSE) Result =CFALSE; 
            else Result = CTRUE;} 
          } 
        } 
      } 
    GC_UNBIND; return (Result);} 
  } 

list * get_restrictions_Call2(Call *v5136,list *v11504)
{ GC_RESERVE(1);  // HOHO v3.0.55 optim !
  { list *Result ;
    { property * v5128 = v5136->selector;
      ClaireBoolean * v6540 = ((class_I_type(OBJECT(ClaireType,(*(v11504))[1]))->open == ClEnv->open) ? CTRUE : CFALSE);
      list * v11502 = list::empty(Kernel._method);
      if ((v5128->dispatcher == 0) && 
          ((v6540 == CTRUE) || 
              (v5128->open == ClEnv->open)))
       ;else { OID gc_local;
          ITERATE(v5130);
          for (START(v5128->restrictions); NEXT(v5130);)
          { GC_LOOP;
            if (length_bag(_exp_list(OBJECT(restriction,v5130)->domain,v11504)) != 0)
             { if (Kernel._method == OBJECT(ClaireObject,v5130)->isa)
               GC__ANY(v11502 = v11502->addFast(v5130), 1);
              else { shrink_list(v11502,0);
                  break;} 
                } 
            GC_UNLOOP;} 
          } 
        Result = v11502;
      } 
    GC_UNBIND; return (Result);} 
  } 

void  fcall_exp_Call2_Generate(Call *v5136,OID v11276)
{ GC_RESERVE(1);  // HOHO v3.0.55 optim !
  { property * v5128 = v5136->selector;
    OID  v11096 = (*(v5136->args))[1];
    list * v11504;
    { { bag *v_list; OID v_val;
        OID v5137,CLcount;
        v_list = v5136->args;
         v11504 = v_list->clone();
        for (CLcount= 1; CLcount <= v_list->length; CLcount++)
        { v5137 = (*(v_list))[CLcount];
          v_val = _oid_(ptype_type(OBJECT(ClaireType,(*Optimize.c_type)(v5137))));
          
          (*((list *) v11504))[CLcount] = v_val;} 
        } 
      GC_OBJECT(list,v11504);} 
    list * v11502 = GC_OBJECT(list,get_restrictions_Call2(v5136,v11504));
    method * v5125 = OBJECT(method,(*(v11502))[1]);
    ClaireClass * v5134 = c_srange_method(v5125);
    if (v5134 == Kernel._void)
     princ_string(CSTRING("_void_("));
    else if (v5134 == Kernel._object)
     princ_string(CSTRING("_oid_("));
    else if ((v5134 == Kernel._integer) && 
        (Optimize.compiler->safety <= 2))
     princ_string(CSTRING("_integer_("));
    if ((v5128->dispatcher > 0) && 
        (v11504->length <= 4))
     { if (v5134 == Kernel._object)
       princ_string(CSTRING("(ClaireObject *) "));
      expression_thing(v5128,v11276);
      princ_string(CSTRING("->fcall("));
      c_sorted_args_Call(v5136,v5125->srange,v11276,CTRUE);
      princ_string(CSTRING(")"));
      } 
    else { list * v12548;
        { { bag * v9140 = v5128->definition;
            list * v10911 = ((list *) empty_bag(v9140));
            { OID gc_local;
              ITERATE(v5136);
              for (START(v9140); NEXT(v5136);)
              if (v11502->memq(v5136) == CTRUE)
               v10911->addFast(v5136);
              } 
            v12548 = GC_OBJECT(list,v10911);
            } 
          GC_OBJECT(list,v12548);} 
        { OID gc_local;
          ITERATE(v5125);
          for (START(v12548); NEXT(v5125);)
          { GC_LOOP;
            { list * v9894;
              { { bag *v_list; OID v_val;
                  OID v5136,CLcount;
                  v_list = OBJECT(restriction,v5125)->domain;
                   v9894 = v_list->clone();
                  for (CLcount= 1; CLcount <= v_list->length; CLcount++)
                  { v5136 = (*(v_list))[CLcount];
                    v_val = _oid_(psort_any(v5136));
                    
                    (*((list *) v9894))[CLcount] = v_val;} 
                  } 
                GC_OBJECT(list,v9894);} 
              if (v5125 != last_list(v12548))
               { princ_string(CSTRING("(INHERIT("));
                if (INHERIT(OWNER(v11096),Optimize._to_CL))
                 { (*Generate.expression)(GC_OID((*Kernel.arg)(v11096)),
                    v11276);
                  princ_string(CSTRING("->isa"));
                  } 
                else { princ_string(CSTRING("OWNER("));
                    (*Generate.expression)(v11096,
                      v11276);
                    princ_string(CSTRING(")"));
                    } 
                  princ_string(CSTRING(","));
                expression_any(_oid_(domain_I_restriction(OBJECT(restriction,v5125))),v11276);
                princ_string(CSTRING(") ? "));
                if (v5134 == Kernel._object)
                 princ_string(CSTRING("(ClaireObject *)"));
                princ_string(CSTRING(" "));
                c_princ_function(OBJECT(ClaireFunction,(*Optimize.functional_I)(v5125)));
                princ_string(CSTRING("(("));
                class_princ_class(domain_I_restriction(OBJECT(restriction,v5125)));
                princ_string(CSTRING(" *) "));
                c_sorted_args_Call(v5136,v9894,v11276,CFALSE);
                princ_string(CSTRING(") : "));
                ;princ_string(CSTRING(" "));
                } 
              else { if (v5134 == Kernel._object)
                   princ_string(CSTRING("(ClaireObject *) "));
                  princ_string(CSTRING(" "));
                  c_princ_function(OBJECT(ClaireFunction,(*Optimize.functional_I)(v5125)));
                  princ_string(CSTRING("(("));
                  (*Generate.interface_I)(Generate.PRODUCER->value,
                    _oid_(domain_I_restriction(OBJECT(restriction,v5125))));
                  princ_string(CSTRING(") "));
                  c_sorted_args_Call(v5136,v9894,v11276,CFALSE);
                  princ_string(CSTRING(")"));
                  { Cint  v5121 = 1;
                    Cint  v2751 = (v12548->length-1);
                    { OID gc_local;
                      while ((v5121 <= v2751))
                      { princ_string(CSTRING(")"));
                        ++v5121;
                        } 
                      } 
                    } 
                  } 
                } 
            GC_UNLOOP;} 
          } 
        } 
      if ((v5134 == Kernel._void) || 
        ((v5134 == Kernel._object) || 
          ((v5134 == Kernel._float) || 
            ((v5134 == Kernel._integer) && 
                (Optimize.compiler->safety <= 2)))))
     princ_string(CSTRING(")"));
    } 
  GC_UNBIND;} 

void  c_sorted_arg_any(OID v5136,ClaireClass *v5134,OID v11276,ClaireBoolean *v10364)
{ GC_BIND;
  if (v10364 == CTRUE)
   princ_string(CSTRING("((Cint) "));
  if ((INHERIT(OWNER(v5136),Optimize._to_CL)) && (osort_any(_oid_(OBJECT(Compile_to_CL,v5136)->set_arg)) == v5134))
   (*Generate.expression)(GC_OID((*Kernel.arg)(v5136)),
    v11276);
  else if (v5134 == Kernel._any)
   (*Generate.expression)(v5136,
    v11276);
  else (*Generate.to_c)(Generate.PRODUCER->value,
      v5136,
      _oid_(v5134),
      v11276);
    if (v10364 == CTRUE)
   princ_string(CSTRING(")"));
  GC_UNBIND;} 

void  c_sorted_args_Call(Call *v5136,list *v11503,OID v11276,ClaireBoolean *v10364)
{ GC_BIND;
  { Cint  v5121 = 0;
    { OID gc_local;
      ITERATE(v5137);
      for (START(v5136->args); NEXT(v5137);)
      { if (v5121 != 0)
         princ_string(CSTRING(","));
        ++v5121;
        c_sorted_arg_any(v5137,OBJECT(ClaireClass,(*(v11503))[v5121]),v11276,v10364);
        } 
      } 
    } 
  GC_UNBIND;} 

void  bitvector_I_c_producer(Generate_c_producer *v5115,OID v5136)
{ GC_BIND;
  if (INHERIT(OWNER(v5136),Kernel._integer))
   bitvectorSum_integer(v5136);
  else if (INHERIT(OWNER(v5136),Optimize._to_CL))
   bitvector_I_c_producer(v5115,GC_OID(OBJECT(Compile_to_CL,v5136)->arg));
  else if (INHERIT(OWNER(v5136),Optimize._to_protect))
   bitvector_I_c_producer(v5115,GC_OID(OBJECT(Compile_to_protect,v5136)->arg));
  else (*Generate.expression)(v5136,
      Core.nil->value);
    GC_UNBIND;} 

void  bitvectorSum_integer(Cint v5136)
{ if (v5136 == 0)
   princ_string(CSTRING("0"));
  else { ClaireBoolean * v5114 = CFALSE;
      Cint  v5121 = 1;
      Cint  v2752 = 7;
      { while ((v5121 <= v2752))
        { if (BCONTAIN(v5136,v5121))
           { if (v5114 == CTRUE)
             princ_string(CSTRING("+"));
            else v5114= CTRUE;
              princ_string(string_v((*(OBJECT(bag,Generate.bitvectorList->value)))[v5121]));
            } 
          ++v5121;
          } 
        } 
      } 
    } 

void  signature_I_c_producer(Generate_c_producer *v5115,OID v5136)
{ GC_BIND;
  if (INHERIT(OWNER(v5136),Kernel._list))
   { princ_string(CSTRING("list::domain("));
    princ_integer(OBJECT(bag,v5136)->length);
    princ_string(CSTRING(","));
    { list * v8607;
      { { bag *v_list; OID v_val;
          OID v5137,CLcount;
          v_list = OBJECT(bag,v5136);
           v8607 = v_list->clone();
          for (CLcount= 1; CLcount <= v_list->length; CLcount++)
          { v5137 = (*(v_list))[CLcount];
            v_val = getC_any(v5137);
            
            (*((list *) v8607))[CLcount] = v_val;} 
          } 
        GC_OBJECT(list,v8607);} 
      args_list_bag(v8607,Core.nil->value,_sup_integer(OBJECT(bag,v5136)->length,3));
      } 
    princ_string(CSTRING(")"));
    } 
  else if (INHERIT(OWNER(v5136),Optimize._to_C))
   signature_I_c_producer(v5115,GC_OID(OBJECT(Compile_to_C,v5136)->arg));
  else if (INHERIT(OWNER(v5136),Optimize._to_protect))
   signature_I_c_producer(v5115,GC_OID(OBJECT(Compile_to_protect,v5136)->arg));
  else if (INHERIT(OWNER(v5136),Language._List))
   signature_I_c_producer(v5115,GC_OID(_oid_(OBJECT(Construct,v5136)->args)));
  else if (INHERIT(OWNER(v5136),Language._Variable))
   expression_Variable(OBJECT(Variable,v5136),Core.nil->value);
  else { princ_string(CSTRING("<fucking "));
      print_any(_oid_(OWNER(v5136)));
      princ_string(CSTRING(":"));
      print_any(v5136);
      princ_string(CSTRING(">"));
      } 
    GC_UNBIND;} 

OID  getC_any(OID v5136)
{ GC_BIND;
  { OID Result = 0;
    if (INHERIT(OWNER(v5136),Optimize._to_CL))
     Result = getC_any(GC_OID(OBJECT(Compile_to_CL,v5136)->arg));
    else if (INHERIT(OWNER(v5136),Optimize._to_protect))
     Result = getC_any(GC_OID(OBJECT(Compile_to_protect,v5136)->arg));
    else if (INHERIT(OWNER(v5136),Core._global_variable))
     { if (nativeVar_ask_global_variable(OBJECT(global_variable,v5136)) == CTRUE)
       Result = v5136;
      else { Compile_to_C * v14361 = ((Compile_to_C *) GC_OBJECT(Compile_to_C,new_object_class(Optimize._to_C)));
          (v14361->arg = v5136);
          (v14361->set_arg = Kernel._type);
          add_I_property(Kernel.instances,Optimize._to_C,11,_oid_(v14361));
          Result = _oid_(v14361);
          } 
        } 
    else Result = v5136;
      GC_UNBIND; return (Result);} 
  } 

void  gassign_c_producer(Generate_c_producer *v5115,Gassign *v13492,OID v11276)
{ GC_BIND;
  if (v13492->var->store_ask == CTRUE)
   { princ_string(CSTRING("(STOREI("));
    expression_global_variable(v13492->var,v11276);
    princ_string(CSTRING(","));
    (*Generate.expression)(v13492->arg,
      v11276);
    princ_string(CSTRING("))"));
    } 
  else { princ_string(CSTRING("("));
      expression_global_variable(v13492->var,v11276);
      princ_string(CSTRING("= "));
      (*Generate.expression)(v13492->arg,
        v11276);
      princ_string(CSTRING(")"));
      } 
    GC_UNBIND;} 

void  call_slot_c_producer(Generate_c_producer *v5115,Call_slot *v13492,OID v11276)
{ GC_BIND;
  if (v13492->test == CTRUE)
   { princ_string((((INHERIT(v13492->selector->srange,Kernel._cl_import)) || 
        ((INHERIT(v13492->selector->srange,Kernel._string)) || 
          ((INHERIT(v13492->selector->srange,Kernel._array)) || 
            (INHERIT(v13492->selector->srange,Kernel._object))))) ?
      CSTRING("NOTNULL") :
      CSTRING("KNOWN") ));
    princ_string(CSTRING("("));
    expression_thing(v13492->selector->selector,v11276);
    princ_string(CSTRING(","));
    } 
  c_member_c_producer(v5115,
    GC_OID(v13492->arg),
    psort_any(_oid_(domain_I_restriction(v13492->selector))),
    v13492->selector->selector,
    v11276);
  if (v13492->test == CTRUE)
   princ_string(CSTRING(")"));
  GC_UNBIND;} 

void  call_table_c_producer(Generate_c_producer *v5115,Call_table *v13492,OID v11276)
{ GC_BIND;
  { table * v5113 = v13492->selector;
    OID  v5128 = v5113->params;
    OID  v5124 = v13492->arg;
    if (v13492->test == CTRUE)
     { princ_string(CSTRING("KNOWN("));
      expression_thing(v5113,v11276);
      princ_string(CSTRING(","));
      } 
    princ_string(CSTRING("(*("));
    expression_thing(v5113,v11276);
    princ_string(CSTRING("->graph))["));
    if (INHERIT(OWNER(v5128),Kernel._integer))
     { (*Generate.expression)(v5124,
        v11276);
      princ_string(CSTRING(" - "));
      princ_integer(v5128);
      princ_string(CSTRING(""));
      } 
    else if (INHERIT(OWNER(v5128),Kernel._list))
     { (*Generate.expression)((*(OBJECT(bag,(*Core.args)(v5124))))[1],
        v11276);
      princ_string(CSTRING(" * "));
      (*Kernel.princ)((*(OBJECT(bag,v5128)))[1]);
      princ_string(CSTRING(" + "));
      (*Generate.expression)((*(OBJECT(bag,(*Core.args)(v5124))))[2],
        v11276);
      princ_string(CSTRING(" - "));
      (*Kernel.princ)((*(OBJECT(bag,v5128)))[2]);
      princ_string(CSTRING(""));
      } 
    princ_string(CSTRING("]"));
    if (v13492->test == CTRUE)
     princ_string(CSTRING(")"));
    } 
  GC_UNBIND;} 

void  call_array_c_producer(Generate_c_producer *v5115,Call_array *v13492,OID v11276)
{ GC_BIND;
  if (v13492->test == _oid_(Kernel._float))
   { princ_string(CSTRING("((double *) "));
    (*Generate.expression)(v13492->selector,
      v11276);
    princ_string(CSTRING(")["));
    (*Generate.expression)(v13492->arg,
      v11276);
    princ_string(CSTRING("]"));
    } 
  else { princ_string(CSTRING("((OID *) "));
      (*Generate.expression)(v13492->selector,
        v11276);
      princ_string(CSTRING(")["));
      (*Generate.expression)(v13492->arg,
        v11276);
      princ_string(CSTRING("]"));
      } 
    GC_UNBIND;} 

void  update_c_producer(Generate_c_producer *v5115,Update *v13492,OID v11276)
{ GC_BIND;
  { OID  v5128 = v13492->selector;
    OID  v5113 = v13492->arg;
    OID  v5138 = v13492->value;
    OID  v5136 = v13492->var;
    ClaireClass * v5134 = OBJECT(ClaireClass,(*Optimize.c_sort)(v5138));
    if ((INHERIT(OWNER(v5128),Kernel._relation)) && ((OBJECT(ClaireRelation,v5128)->if_write != CNULL) && 
        ((v5113 != _oid_(Kernel.put)) && 
          (v5113 != _oid_(Core.put_store)))))
     { c_princ_string(string_I_symbol(OBJECT(symbol,(*Kernel.name)(v5128))));
      princ_string(CSTRING("_write("));
      (*Generate.expression)(GC_OID((*Kernel.arg)(v5136)),
        v11276);
      princ_string(CSTRING(","));
      (*Generate.expression)(v5138,
        v11276);
      princ_string(CSTRING(")"));
      } 
    else if ((INHERIT(OWNER(v5128),Kernel._relation)) && ((OBJECT(ClaireRelation,v5128)->store_ask == CTRUE) || 
        (v5113 == _oid_(Core.put_store))))
     { princ_string(CSTRING("STORE"));
      princ_string((((v5134 == Kernel._any) || 
          (v5134 == Kernel._integer)) ?
        CSTRING("I") :
        ((v5134 == Kernel._float) ?
          CSTRING("F") :
          CSTRING("O") ) ));
      princ_string(CSTRING("("));
      (*Generate.expression)(v5136,
        v11276);
      princ_string(CSTRING(","));
      (*Generate.expression)(v5138,
        v11276);
      princ_string(CSTRING(")"));
      } 
    else { princ_string(CSTRING("("));
        (*Generate.expression)(v5136,
          v11276);
        princ_string(CSTRING(" = "));
        (*Generate.expression)(v5138,
          v11276);
        princ_string(CSTRING(")"));
        } 
      } 
  GC_UNBIND;} 

void  object_test_c_producer(Generate_c_producer *v5115,OID v11096,ClaireBoolean *v15827,OID v11276)
{ princ_string(CSTRING("(CTAG("));
  (*Generate.expression)(v11096,
    v11276);
  princ_string(CSTRING(") "));
  sign_equal_boolean(v15827);
  princ_string(CSTRING(" OBJ_CODE)"));
  } 

void  exp_to_protect_c_producer(Generate_c_producer *v5115,Compile_to_protect *v13492,OID v11276)
{ GC_BIND;
  { OID  v11722 = GC_OID((*Optimize.c_type)(v13492->arg));
    if ((Optimize.OPT->protection == CTRUE) && 
        ((need_protect_any(v13492->arg) == CTRUE) && 
          (((Optimize.OPT->alloc_stack == CTRUE) ? ((_inf_equal_type(OBJECT(ClaireType,v11722),Kernel._tuple) == CTRUE) ? CTRUE: CFALSE): CFALSE) != CTRUE)))
     { OID  v5136 = v13492->arg;
      ClaireClass * v5134 = OBJECT(ClaireClass,(*Optimize.c_sort)(v5136));
      princ_string(gc_protect_class(v5134));
      princ_string(CSTRING("("));
      if (INHERIT(v5134,Kernel._object))
       { class_princ_class(psort_any((*Core.glb)(GC_OID((*Optimize.c_type)(v5136)),
          _oid_(v5134))));
        princ_string(CSTRING(","));
        (*Generate.expression)(v13492->arg,
          v11276);
        princ_string(CSTRING(""));
        } 
      else (*Generate.expression)(v13492->arg,
          v11276);
        princ_string(CSTRING(")"));
      } 
    else (*Generate.expression)(v13492->arg,
        v11276);
      } 
  GC_UNBIND;} 

char * gc_protect_class(ClaireClass *v5115)
{ { char *Result ;
    Result = ((v5115 == Kernel._any) ?
      CSTRING("GC_OID") :
      ((v5115 == Kernel._string) ?
        CSTRING("GC_STRING") :
        ((v5115 == Kernel._array) ?
          CSTRING("GC_ARRAY") :
          ((INHERIT(v5115,Kernel._object)) ?
            CSTRING("GC_OBJECT") :
            CSTRING("") ) ) ) );
    return (Result);} 
  } 

void  macro_c_producer(Generate_c_producer *v5115)
{ ;} 

void  init_var_c_producer(Generate_c_producer *v5115,ClaireClass *v5134)
{ ;} 

void  any_interface_c_producer(Generate_c_producer *v5115)
{ princ_string(CSTRING("OID"));
  } 

void  pointer_cast_c_producer(Generate_c_producer *v5115,ClaireClass *v5134)
{ princ_string(CSTRING("("));
  class_princ_c_producer(v5115,v5134);
  princ_string(CSTRING(" *)"));
  } 

void  exp_Assign_c_producer(Generate_c_producer *v5115,Assign *v13492,OID v11276)
{ GC_BIND;
  { OID  v5136 = v13492->arg;
    OID  v5138 = v13492->var;
    (*Language.ident)(Generate.PRODUCER->value,
      v5138);
    princ_string(CSTRING("= "));
    (*Generate.expression)(v5136,
      v11276);
    princ_string(CSTRING(""));
    } 
  GC_UNBIND;} 

void  stat_handle_c_producer(Generate_c_producer *v5115,ClaireHandle *v13492,OID v5134,OID v11276)
{ GC_BIND;
  new_block_void();
  princ_string(CSTRING("ClaireHandler c_handle = ClaireHandler();"));
  breakline_void();
  princ_string(CSTRING("if ERROR_IN "));
  breakline_void();
  new_block_void();
  statement_any(GC_OID(v13492->arg),v5134,v11276);
  princ_string(CSTRING("ClEnv->cHandle--;"));
  close_block_void();
  princ_string(CSTRING("else if (belong_to(_oid_(ClEnv->exception_I),"));
  (*Generate.expression)(GC_OID((*Optimize.c_code)(GC_OID(v13492->test),
      _oid_(Kernel._any))),
    _oid_(Kernel.emptySet));
  princ_string(CSTRING(") == CTRUE)"));
  breakline_void();
  new_block_void();
  princ_string(CSTRING("c_handle.catchIt();"));
  statement_any(GC_OID(v13492->other),v5134,v11276);
  close_block_void();
  princ_string(CSTRING("else PREVIOUS_HANDLER;"));
  close_block_void();
  GC_UNBIND;} 

void  stat_construct_c_producer(Generate_c_producer *v5115,Construct *v13492,OID v5134,OID v11276)
{ GC_BIND;
  if (boolean_I_any(v5134) != CTRUE)
   close_exception(((general_error *) (*Core._general_error)(_string_(CSTRING("[202] A do should have been used for ~S")),
    _oid_(list::alloc(1,_oid_(v13492))))));
  { char * v5138 = GC_STRING(check_var_string(CSTRING("v_bag"),v5134,v11276));
    bag * v13273;
    { ClaireObject *V_CC ;
      if (INHERIT(v13492->isa,Language._List))
       V_CC = list::empty();
      else if (INHERIT(v13492->isa,Language._Set))
       V_CC = set::empty();
      else if (INHERIT(v13492->isa,Language._Tuple))
       V_CC = tuple::empty();
      else close_exception(((general_error *) (*Core._general_error)(_string_(CSTRING("BUG: ~S")),
          _oid_(list::alloc(1,_oid_(v13492))))));
        v13273= (bag *) V_CC;} 
    new_block_void();
    if (get_property(Kernel.of,v13492) != CNULL)
     cast_I_bag(v13273,OBJECT(ClaireType,(*Kernel.of)(_oid_(v13492))));
    { ClaireBoolean * g0090I;
      { OID  v15287;
        { OID gc_local;
          ITERATE(v5136);
          v15287= Kernel.cfalse;
          bag *v5136_support;
          v5136_support = GC_OBJECT(list,v13492->args);
          for (START(v5136_support); NEXT(v5136);)
          if (c_func_any(v5136) != CTRUE)
           { v15287 = Kernel.ctrue;
            break;} 
          } 
        g0090I = boolean_I_any(v15287);
        } 
      
      if (g0090I == CTRUE) { princ_string(CSTRING("OID "));
          princ_string(v5138);
          princ_string(CSTRING(";"));
          breakline_void();
          princ_string(CSTRING(""));
          } 
        } 
    if (Optimize.OPT->protection == CTRUE)
     { (v5115->stat = (v5115->stat+1));
      princ_string(CSTRING("GC_ANY("));
      } 
    (*Kernel.c_princ)(v5134);
    princ_string(CSTRING("= "));
    (*Generate.bag_expression)(Generate.PRODUCER->value,
      _oid_(v13273->isa),
      _oid_(v13273),
      GC_OID(_oid_(of_bag(v13273))),
      v11276);
    if (Optimize.OPT->protection == CTRUE)
     princ_string(CSTRING(")"));
    princ_string(CSTRING(";"));
    { OID gc_local;
      ITERATE(v5136);
      bag *v5136_support;
      v5136_support = GC_OBJECT(list,v13492->args);
      for (START(v5136_support); NEXT(v5136);)
      { ClaireBoolean * v5118 = c_func_any(v5136);
        breakline_void();
        if (v5118 != CTRUE)
         statement_any(v5136,_string_(v5138),v11276);
        princ_string(CSTRING("(("));
        { OID  v16248;
          if (INHERIT(v13492->isa,Language._List))
           v16248 = _oid_(Kernel._list);
          else if (INHERIT(v13492->isa,Language._Set))
           v16248 = _oid_(Kernel._set);
          else v16248 = _oid_(Kernel._tuple);
            print_any(v16248);
          } 
        princ_string(CSTRING(" *) "));
        (*Kernel.c_princ)(v5134);
        princ_string(CSTRING(")"));
        addFast_c_producer(v5115);
        princ_string(CSTRING("("));
        if (v5118 == CTRUE)
         (*Generate.expression)(v5136,
          v11276);
        else c_princ_string(v5138);
          princ_string(CSTRING(");"));
        } 
      } 
    close_block_void();
    } 
  GC_UNBIND;} 

void  stat_while_c_producer(Generate_c_producer *v5115,While *v13492,OID v5134,OID v11276)
{ GC_BIND;
  new_block_void();
  { ClaireBoolean * v11265 = ((c_func_any(GC_OID(v13492->test)) == CTRUE) ? ((v13492->other != CTRUE) ? ((gc_usage_any(v13492->test,OBJECT(ClaireBoolean,v11276)) == Kernel.cfalse) ? CTRUE: CFALSE): CFALSE): CFALSE);
    char * v5138 = GC_STRING(check_var_string(CSTRING("v_while"),v5134,v11276));
    if (Optimize.OPT->loop_gc == CTRUE)
     { princ_string(CSTRING("OID gc_local;"));
      breakline_void();
      princ_string(CSTRING(""));
      } 
    if (v11265 != CTRUE)
     { interface_I_class(Kernel._boolean);
      princ_string(v5138);
      princ_string(CSTRING(";"));
      breakline_void();
      princ_string(CSTRING(""));
      } 
    if (Kernel._string == OWNER(v5134))
     { (*Kernel.c_princ)(v5134);
      princ_string(CSTRING("= _oid_("));
      expression_boolean(CFALSE,v11276);
      princ_string(CSTRING(");"));
      breakline_void();
      } 
    if (v11265 == CTRUE)
     { princ_string(CSTRING("while ("));
      (*Optimize.bool_exp)(GC_OID(v13492->test),
        _oid_(not_any(_oid_(v13492->other))),
        v11276);
      princ_string(CSTRING(")"));
      } 
    else { { OID  v825;
          { if (v13492->other == CTRUE)
             v825 = Kernel.cfalse;
            else v825 = v13492->test;
              GC_OID(v825);} 
          statement_any(v825,_string_(v5138),Kernel.ctrue);
          } 
        breakline_void();
        princ_string(CSTRING("while ("));
        princ_string(v5138);
        princ_string(CSTRING(" "));
        if (v13492->other == CTRUE)
         princ_string(CSTRING("!="));
        else princ_string(CSTRING("=="));
          princ_string(CSTRING(" CTRUE)"));
        } 
      breakline_void();
    new_block_void();
    { ClaireBoolean * v3486 = ((Optimize.OPT->loop_gc == CTRUE) ? ((gc_usage_any(v13492->arg,CTRUE) != Kernel.cfalse) ? CTRUE: CFALSE): CFALSE);
      if (v3486 == CTRUE)
       { princ_string(CSTRING("GC_LOOP;"));
        breakline_void();
        } 
      { OID  v1786;
        if (Kernel._string == OWNER(v5134))
         v1786 = v5134;
        else v1786 = CNULL;
          inner_statement_any(GC_OID(v13492->arg),_oid_(Kernel.emptySet),v1786);
        } 
      if (v11265 != CTRUE)
       statement_any(GC_OID(v13492->test),_string_(v5138),Kernel.ctrue);
      if (v3486 == CTRUE)
       princ_string(CSTRING("GC_UNLOOP;"));
      } 
    close_block_void();
    } 
  close_block_void();
  GC_UNBIND;} 

void  stat_gassign_c_producer(Generate_c_producer *v5115,Gassign *v13492,OID v5134,OID v11276)
{ GC_BIND;
  new_block_void();
  interface_I_c_producer(v5115,((nativeVar_ask_global_variable(v13492->var) == CTRUE) ?
    getRange_global_variable(v13492->var) :
    Kernel._any ));
  princ_string(CSTRING(" truc;"));
  statement_any(GC_OID(v13492->arg),_string_(CSTRING("truc")),v11276);
  princ_string(CSTRING(""));
  breakline_void();
  if (v13492->var->store_ask == CTRUE)
   { princ_string(CSTRING("STOREI("));
    expression_global_variable(v13492->var,v11276);
    princ_string(CSTRING(",truc);"));
    } 
  else { princ_string(CSTRING("("));
      expression_global_variable(v13492->var,v11276);
      princ_string(CSTRING(" = truc);"));
      } 
    close_block_void();
  GC_UNBIND;} 

void  stat_for_c_producer(Generate_c_producer *v5115,For *v13492,OID v5134,OID v11276)
{ GC_BIND;
  { char * v5138 = GC_STRING(c_string_c_producer1(v5115,GC_OBJECT(Variable,v13492->var)));
    new_block_void();
    if (Optimize.OPT->loop_gc == CTRUE)
     { princ_string(CSTRING("OID gc_local;"));
      breakline_void();
      princ_string(CSTRING(""));
      } 
    princ_string(CSTRING("ITERATE("));
    c_princ_string(v5138);
    princ_string(CSTRING(");"));
    if (Kernel._string == OWNER(v5134))
     { breakline_void();
      (*Kernel.c_princ)(v5134);
      princ_string(CSTRING("= Kernel.cfalse;"));
      } 
    breakline_void();
    if ((c_func_any(GC_OID(v13492->set_arg)) == CTRUE) && 
        (designated_ask_any(GC_OID(v13492->set_arg)) == CTRUE))
     { princ_string(CSTRING("for (START("));
      (*Generate.expression)(GC_OID(v13492->set_arg),
        v11276);
      princ_string(CSTRING("); NEXT("));
      c_princ_string(v5138);
      princ_string(CSTRING(");)"));
      } 
    else { char * v11748 = GC_STRING(append_string(v5138,CSTRING("_support")));
        princ_string(CSTRING("bag *"));
        c_princ_string(v11748);
        princ_string(CSTRING(";"));
        breakline_void();
        princ_string(CSTRING(""));
        statement_any(GC_OID(v13492->set_arg),_string_(v11748),v11276);
        princ_string(CSTRING("for (START("));
        c_princ_string(v11748);
        princ_string(CSTRING("); NEXT("));
        c_princ_string(v5138);
        princ_string(CSTRING(");)"));
        } 
      breakline_void();
    { ClaireBoolean * v3486 = ((Optimize.OPT->loop_gc == CTRUE) ? ((gc_usage_any(v13492->arg,CTRUE) != Kernel.cfalse) ? CTRUE: CFALSE): CFALSE);
      if (v3486 == CTRUE)
       { new_block_void();
        princ_string(CSTRING("GC_LOOP;"));
        breakline_void();
        } 
      if ((Optimize.OPT->profile_ask == CTRUE) && 
          (_Z_any1(Optimize.OPT->in_method,Kernel._object) == CTRUE))
       { if (v3486 != CTRUE)
         new_block_void();
        princ_string(CSTRING("PRloop(PR_x);"));
        breakline_void();
        } 
      { OID  v2755;
        if (Kernel._string == OWNER(v5134))
         v2755 = v5134;
        else v2755 = CNULL;
          statement_any(GC_OID(v13492->arg),_oid_(Kernel.emptySet),v2755);
        } 
      if (v3486 == CTRUE)
       { princ_string(CSTRING("GC_UNLOOP;"));
        close_block_void();
        } 
      if ((Optimize.OPT->profile_ask == CTRUE) && 
          ((_Z_any1(Optimize.OPT->in_method,Kernel._object) == CTRUE) && 
            (v3486 != CTRUE)))
       close_block_void();
      close_block_void();
      } 
    } 
  GC_UNBIND;} 

void  stat_iteration_c_producer(Generate_c_producer *v5115,Iteration *v13492,OID v5134,OID v11276)
{ GC_BIND;
  if (boolean_I_any(v5134) != CTRUE)
   close_exception(((general_error *) (*Core._general_error)(_string_(CSTRING("[203] you should have used a FOR here:~S")),
    _oid_(list::alloc(1,_oid_(v13492))))));
  { char * v5138 = GC_STRING(c_string_c_producer1(v5115,GC_OBJECT(Variable,v13492->var)));
    char * v9987 = GC_STRING(check_var_string(CSTRING("v_val"),v5134,v11276));
    char * v11039 = GC_STRING(check_var_string(CSTRING("v_list"),v5134,v11276));
    new_block_void();
    princ_string(CSTRING("bag *"));
    princ_string(v11039);
    princ_string(CSTRING("; OID "));
    princ_string(v9987);
    princ_string(CSTRING(";"));
    breakline_void();
    princ_string(CSTRING(""));
    princ_string(CSTRING("OID "));
    c_princ_string(v5138);
    princ_string(CSTRING(",CLcount;"));
    breakline_void();
    princ_string(CSTRING(""));
    statement_any(GC_OID(v13492->set_arg),_string_(v11039),v11276);
    princ_string(CSTRING(" "));
    (*Kernel.c_princ)(v5134);
    princ_string(CSTRING(" = "));
    princ_string(v11039);
    princ_string(CSTRING("->clone("));
    if (get_property(Kernel.of,v13492) != CNULL)
     (*Generate.expression)(GC_OID((*Optimize.c_code)(GC_OID((*Kernel.of)(_oid_(v13492))),
        _oid_(Kernel._type))),
      Core.nil->value);
    princ_string(CSTRING(")"));
    princ_string(CSTRING(";"));
    breakline_void();
    princ_string(CSTRING("for (CLcount= 1; CLcount <= "));
    princ_string(v11039);
    princ_string(CSTRING("->length; CLcount++)"));
    breakline_void();
    new_block_void();
    c_princ_string(v5138);
    princ_string(CSTRING(" = (*("));
    princ_string(v11039);
    princ_string(CSTRING("))[CLcount];"));
    breakline_void();
    statement_any(GC_OID(v13492->arg),_string_(v9987),Kernel.ctrue);
    breakline_void();
    princ_string(CSTRING("(*((list *) "));
    (*Kernel.princ)(v5134);
    princ_string(CSTRING("))[CLcount] = "));
    princ_string(v9987);
    princ_string(CSTRING(";"));
    close_block_void();
    close_block_void();
    } 
  GC_UNBIND;} 

void  stat_super_c_producer(Generate_c_producer *v5115,Super *v13492,OID v5134,OID v11276)
{ GC_BIND;
  { char * v1576 = GC_STRING(check_var_string(CSTRING("v_rec"),v5134,v11276));
    new_block_void();
    princ_string(CSTRING("OID "));
    princ_string(v1576);
    princ_string(CSTRING(";"));
    breakline_void();
    { OID gc_local;
      ITERATE(v5136);
      bag *v5136_support;
      v5136_support = GC_OBJECT(list,v13492->args);
      for (START(v5136_support); NEXT(v5136);)
      { statement_any(v5136,_string_(v1576),v11276);
        princ_string(CSTRING("PUSH("));
        princ_string(v1576);
        princ_string(CSTRING(");"));
        breakline_void();
        } 
      } 
    if (Kernel._string == OWNER(v5134))
     { c_princ_string(string_v(v5134));
      princ_string(CSTRING("="));
      } 
    expression_thing(v13492->selector,v11276);
    princ_string(CSTRING("->super("));
    (*Generate.expression)(GC_OID(_oid_(v13492->cast_to)),
      v11276);
    princ_string(CSTRING(","));
    princ_integer(v13492->args->length);
    princ_string(CSTRING(");"));
    close_block_void();
    } 
  GC_UNBIND;} 

void  stat_let_c_producer(Generate_c_producer *v5115,Let *v13492,OID v5134,OID v11276)
{ GC_RESERVE(8);  // v3.0.55 optim !
  { char * v11565 = GC_STRING(string_v((*Generate.c_string)(Generate.PRODUCER->value,
      _oid_(v13492->var->pname))));
    if ((v11565[1 - 1] == 'C') && 
        (v11565[2 - 1] == '%'))
     (v13492->var->pname = gensym_void());
    } 
  { OID  v5138 = GC_OID((*Generate.c_string)(Generate.PRODUCER->value,
      GC_OID(_oid_(v13492->var))));
    ClaireBoolean * v5114 = Optimize.OPT->alloc_stack;
    OID  v5136 = GC_OID(v13492->value);
    ClaireBoolean * v5118 = CTRUE;
    new_block_void();
    (Optimize.OPT->alloc_stack = CFALSE);
    { OID gc_local;
      while ((v5118 == CTRUE))
      { GC_LOOP;
        if (INHERIT(v13492->isa,Language._Let_star))
         (Optimize.OPT->alloc_stack = CTRUE);
        interface_I_class(sort_Variable(v13492->var));
        princ_string(CSTRING(" "));
        c_princ_string(string_v(v5138));
        princ_string(CSTRING(""));
        if (c_func_any(v5136) == CTRUE)
         { princ_string(CSTRING(" = "));
          if (bool_exp_ask_any(v5136) == CTRUE)
           (*Generate.bool_exp_I)(Generate.PRODUCER->value,
            v5136,
            v11276);
          else (*Generate.expression)(v5136,
              v11276);
            princ_string(CSTRING(";"));
          breakline_void();
          princ_string(CSTRING(""));
          } 
        else { (*Generate.init_var)(Generate.PRODUCER->value,
              _oid_(sort_Variable(v13492->var)));
            princ_string(CSTRING(";"));
            breakline_void();
            statement_any(v5136,v5138,v11276);
            princ_string(CSTRING(""));
            } 
          if (INHERIT(v13492->isa,Language._Let_star))
         (Optimize.OPT->alloc_stack = CFALSE);
        if (INHERIT(OWNER(v13492->arg),Language._Let))
         { GC__ANY(v13492 = OBJECT(Let,v13492->arg), 2);
          GC__OID(v5138 = (*Generate.c_string)(Generate.PRODUCER->value,
            GC_OID(_oid_(v13492->var))), 5);
          GC__OID(v5136 = v13492->value, 7);
          } 
        else v5118= CFALSE;
          GC_UNLOOP;} 
      } 
    (Optimize.OPT->alloc_stack = v5114);
    inner_statement_any(GC_OID(v13492->arg),v5134,v11276);
    princ_string(CSTRING(""));
    close_block_void();
    } 
  GC_UNBIND;} 

