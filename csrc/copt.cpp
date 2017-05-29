/***** CLAIRE Compilation of file /Users/ycaseau/claire/v3.5/src/compile/copt.cl 
         [version 3.5.01 / safety 5] Sun Jul 24 08:43:47 2016 *****/

#include <claire.h>
#include <Kernel.h>
#include <Core.h>
#include <Language.h>
#include <Reader.h>
#include <Optimize.h>
#include <Generate.h>
void  inline_exp_c_producer1(Generate_c_producer *v106827,Call_method1 *v107876,OID v40124)
{ GC_BIND;
  { method * v106837 = v107876->arg;
    property * v106840 = v106837->selector;
    OID  v34825 = GC_OID(car_list(v107876->args));
    if ((v106840 == Kernel._dash) && 
        ((domain_I_restriction(v106837) == Kernel._integer) || 
            (domain_I_restriction(v106837) == Kernel._float)))
     { princ_string(CSTRING("(-"));
      bexpression_any(v34825,v40124);
      princ_string(CSTRING(")"));
      } 
    else if ((v106840 == Core.owner) && 
        (designated_ask_any(v34825) == CTRUE))
     { princ_string(CSTRING("OWNER("));
      (*Generate.expression)(v34825,
        v40124);
      princ_string(CSTRING(")"));
      } 
    else if ((v106840 == Core.sqrt) && 
        (domain_I_restriction(v106837) == Kernel._float))
     { princ_string(CSTRING("sqrt("));
      (*Generate.expression)(v34825,
        v40124);
      princ_string(CSTRING(")"));
      } 
    else if ((v106840 == Core.eval) && 
        (designated_ask_any(v34825) == CTRUE))
     { princ_string(CSTRING("OPT_EVAL("));
      (*Generate.expression)(v34825,
        v40124);
      princ_string(CSTRING(")"));
      } 
    else if (v106840 == Core.externC)
     (*Kernel.princ)(v34825);
    else if ((_oid_(v106837) == Generate._starlength_bag_star->value) && 
        (designated_ask_any(v34825) == CTRUE))
     { (*Generate.expression)(v34825,
        v40124);
      princ_string(CSTRING("->length"));
      } 
    else if ((v106840 == Kernel.integer_I) && 
        ((domain_I_restriction(v106837) == Kernel._char) && 
          (designated_ask_any(v34825) == CTRUE)))
     { (*Generate.expression)(v34825,
        v40124);
      princ_string(CSTRING("->ascii"));
      } 
    else if (_oid_(v106837) == Generate._starlength_array_star->value)
     { (*Generate.expression)(v34825,
        v40124);
      princ_string(CSTRING("[0]"));
      } 
    else if ((_oid_(v106837) == Generate._starnot_star->value) && 
        (_inf_equal_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(v34825))),Kernel._boolean) == CTRUE))
     { princ_string(CSTRING("(("));
      (*Generate.expression)(v34825,
        v40124);
      princ_string(CSTRING(" == Kernel.ctrue) ? CFALSE : CTRUE)"));
      } 
    else print_external_call_c_producer(v106827,v107876,v40124);
      } 
  GC_UNBIND;} 

void  inline_exp_c_producer2(Generate_c_producer *v106827,Call_method2 *v107876,OID v40124)
{ GC_BIND;
  { method * v106837 = v107876->arg;
    property * v106840 = v106837->selector;
    OID  v34825 = GC_OID((*(v107876->args))[1]);
    OID  v34826 = GC_OID((*(v107876->args))[2]);
    if ((_oid_(v106837) == Generate._starmin_integer_star->value) && 
        ((designated_ask_any(v34825) == CTRUE) && 
          (designated_ask_any(v34826) == CTRUE)))
     { princ_string(CSTRING("(("));
      (*Generate.expression)(v34825,
        v40124);
      princ_string(CSTRING(" <= "));
      (*Generate.expression)(v34826,
        v40124);
      princ_string(CSTRING(") ? "));
      (*Generate.expression)(v34825,
        v40124);
      princ_string(CSTRING(" : "));
      (*Generate.expression)(v34826,
        v40124);
      princ_string(CSTRING(")"));
      } 
    else if ((_oid_(v106837) == Generate._starmax_integer_star->value) && 
        ((designated_ask_any(v34825) == CTRUE) && 
          (designated_ask_any(v34826) == CTRUE)))
     { princ_string(CSTRING("(("));
      (*Generate.expression)(v34825,
        v40124);
      princ_string(CSTRING(" <= "));
      (*Generate.expression)(v34826,
        v40124);
      princ_string(CSTRING(") ? "));
      (*Generate.expression)(v34826,
        v40124);
      princ_string(CSTRING(" : "));
      (*Generate.expression)(v34825,
        v40124);
      princ_string(CSTRING(")"));
      } 
    else if ((v106840 == Core.class_I) && 
        (INHERIT(OWNER(v34825),Kernel._symbol)))
     { princ_string(CSTRING("("));
      ident_thing(defined_symbol(OBJECT(symbol,v34825)));
      princ_string(CSTRING("._"));
      c_princ_string(string_v((*Kernel.string_I)(v34825)));
      princ_string(CSTRING(" = ClaireClass::make("));
      print_any(GC_OID((*Kernel.string_I)(v34825)));
      princ_string(CSTRING(","));
      (*Generate.expression)(v34826,
        v40124);
      princ_string(CSTRING(","));
      ident_thing(OBJECT(thing,(*Kernel.module_I)(v34825)));
      princ_string(CSTRING(".it))"));
      } 
    else if ((v106827->open_operators->memq(_oid_(v106840)) == CTRUE) && 
        (((v106840 != Kernel._7) || 
            (5 <= Optimize.compiler->safety)) && 
          ((equal((*(v106837->domain))[1],(*(v106837->domain))[2]) == CTRUE) && 
            ((_inf_equal_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(v34825))),Kernel._integer) == CTRUE) || 
                (_inf_equal_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(v34825))),Kernel._float) == CTRUE)))))
     { if ((Optimize.compiler->safety < 2) && 
          (_inf_equal_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(v34825))),Kernel._integer) == CTRUE))
       princ_string(CSTRING("_integer_"));
      princ_string(CSTRING("("));
      bexpression_any(v34825,v40124);
      princ_string(string_I_symbol(v106840->name));
      bexpression_any(v34826,v40124);
      princ_string(CSTRING(")"));
      } 
    else if ((_oid_(v106837) == Generate._starcontain_star->value) && 
        (identifiable_ask_any(v34826) == CTRUE))
     { (*Generate.expression)(v34825,
        v40124);
      princ_string(CSTRING("->memq("));
      (*Generate.expression)(v34826,
        v40124);
      princ_string(CSTRING(")"));
      } 
    else if (((_oid_(v106837) == Generate._starnth_list_star->value) && 
          (2 <= Optimize.compiler->safety)) || 
        (_oid_(v106837) == Generate._starnth_1_bag_star->value))
     { princ_string(CSTRING("(*("));
      (*Generate.expression)(v34825,
        v40124);
      princ_string(CSTRING("))["));
      (*Generate.expression)(v34826,
        v40124);
      princ_string(CSTRING("]"));
      } 
    else if ((v106840 == Kernel.add_I) && 
        (_inf_equal_type(domain_I_restriction(v106837),Kernel._bag) == CTRUE))
     { (*Generate.expression)(v34825,
        v40124);
      princ_string(CSTRING("->addFast("));
      (*Generate.expression)(v34826,
        v40124);
      princ_string(CSTRING(")"));
      } 
    else if ((_oid_(v106837) == Generate._starnth_string_star->value) && 
        (2 <= Optimize.compiler->safety))
     { princ_string(CSTRING("_char_("));
      (*Generate.expression)(v34825,
        v40124);
      princ_string(CSTRING("["));
      (*Generate.expression)(v34826,
        v40124);
      princ_string(CSTRING(" - 1])"));
      } 
    else if (v106837->selector == Core.identical_ask)
     { princ_string(CSTRING("("));
      (*Optimize.bool_exp)(_oid_(v107876),
        Kernel.ctrue,
        v40124);
      princ_string(CSTRING(" ? CTRUE : CFALSE)"));
      } 
    else if (v106837->selector == Core.externC)
     (*Kernel.princ)(v34825);
    else if ((v106840 == Core.inlineok_ask) && 
        (Kernel._string == OWNER(v34826)))
     { (*Generate.expression)(v34825,
        v40124);
      princ_string(CSTRING("->inlineDef("));
      print_any(v34826);
      princ_string(CSTRING(")"));
      } 
    else print_external_call_c_producer(v106827,v107876,v40124);
      } 
  GC_UNBIND;} 

void  inline_exp_c_producer3(Generate_c_producer *v106827,Call_method *v107876,OID v40124)
{ GC_BIND;
  { method * v106837 = v107876->arg;
    ClaireBoolean * v106826 = Optimize.OPT->alloc_stack;
    OID  v34825 = GC_OID((*(v107876->args))[1]);
    OID  v34826 = GC_OID((*(v107876->args))[2]);
    OID  v34827 = GC_OID((*(v107876->args))[3]);
    (Optimize.OPT->alloc_stack = CFALSE);
    if ((_oid_(v106837) == Generate._starnth_equal_list_star->value) && 
        (3 <= Optimize.compiler->safety))
     { princ_string(CSTRING("((*("));
      (*Generate.expression)(v34825,
        v40124);
      princ_string(CSTRING("))["));
      (*Generate.expression)(v34826,
        v40124);
      princ_string(CSTRING("]="));
      (*Generate.expression)(v34827,
        v40124);
      princ_string(CSTRING(")"));
      } 
    else if ((domain_I_restriction(v106837) == Kernel._string) && 
        (((v106837->selector == Kernel.nth_equal) && 
              (2 <= Optimize.compiler->safety)) || 
            (v106837->selector == Kernel.nth_put)))
     { princ_string(CSTRING("("));
      (*Generate.expression)(v34825,
        v40124);
      princ_string(CSTRING("["));
      (*Generate.expression)(v34826,
        v40124);
      princ_string(CSTRING(" - 1] = (char) "));
      (*Generate.expression)(v34827,
        v40124);
      princ_string(CSTRING("->ascii)"));
      } 
    else if (_oid_(v106837) == Generate._starnth_1_string_star->value)
     { princ_string(CSTRING("_char_("));
      (*Generate.expression)(v34825,
        v40124);
      princ_string(CSTRING("["));
      (*Generate.expression)(v34826,
        v40124);
      princ_string(CSTRING(" - 1])"));
      } 
    else if ((v106837->selector == Kernel.store) && 
        ((_inf_equal_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(v34825))),Kernel._list) == CTRUE) && 
          (((v107876->args->length == 4) && 
                ((*(v107876->args))[4] == Kernel.ctrue)) || 
              (v107876->args->length == 3))))
     { princ_string(CSTRING("STOREI((*"));
      (*Generate.expression)(v34825,
        v40124);
      princ_string(CSTRING(")["));
      (*Generate.expression)(v34826,
        v40124);
      princ_string(CSTRING("],"));
      (*Generate.expression)(v34827,
        v40124);
      princ_string(CSTRING(")"));
      } 
    else if ((v106837->selector == Kernel.store) && 
        ((_inf_equal_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(v34825))),Kernel._array) == CTRUE) && 
          ((equal(_oid_(_exp_type(GC_OBJECT(ClaireType,member_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(v34825))))),Kernel._float)),_oid_(Kernel.emptySet)) == CTRUE) && 
            (((v107876->args->length == 4) && 
                  ((*(v107876->args))[4] == Kernel.ctrue)) || 
                (v107876->args->length == 3)))))
     { princ_string(CSTRING("STOREI("));
      (*Generate.expression)(v34825,
        v40124);
      princ_string(CSTRING("["));
      (*Generate.expression)(v34826,
        v40124);
      princ_string(CSTRING("],"));
      (*Generate.expression)(v34827,
        v40124);
      princ_string(CSTRING(")"));
      } 
    else if ((v106837->selector == Kernel.add_slot) && 
        (INHERIT(owner_any(getC_any(v34825)),Kernel._class)))
     { princ_string(CSTRING("CL_ADD_SLOT("));
      (*Generate.expression)(v34825,
        v40124);
      princ_string(CSTRING(","));
      class_princ_class(OBJECT(ClaireClass,getC_any(v34825)));
      princ_string(CSTRING(","));
      (*Generate.expression)(v34826,
        v40124);
      princ_string(CSTRING(","));
      ident_symbol(OBJECT(symbol,(*Kernel.name)(GC_OID(getC_any(v34826)))));
      princ_string(CSTRING(","));
      (*Generate.expression)(GC_OID(getC_any(v34827)),
        v40124);
      princ_string(CSTRING(","));
      (*Generate.expression)(GC_OID((*(v107876->args))[4]),
        v40124);
      princ_string(CSTRING(")"));
      } 
    else if (v106837->selector == Kernel.add_method)
     { if (INHERIT(OWNER(v34825),Kernel._property))
       { (*Generate.expression)(v34825,
          v40124);
        princ_string(CSTRING("->add"));
        if (v107876->args->length > 5)
         princ_string(CSTRING("Float"));
        princ_string(CSTRING("Method("));
        signature_I_c_producer(v106827,v34826);
        princ_string(CSTRING(","));
        (*Generate.expression)(v34827,
          v40124);
        princ_string(CSTRING(","));
        breakline_void();
        princ_string(CSTRING("\t"));
        bitvector_I_c_producer(v106827,GC_OID((*(v107876->args))[4]));
        princ_string(CSTRING(","));
        (*Generate.expression)(GC_OID((*(v107876->args))[5]),
          v40124);
        if (v107876->args->length > 5)
         { princ_string(CSTRING(","));
          (*Generate.expression)(GC_OID((*(v107876->args))[6]),
            v40124);
          } 
        princ_string(CSTRING(")"));
        } 
      else { princ_string(CSTRING("add_method_property("));
          args_list_bag(GC_OBJECT(list,v107876->args),v40124,CTRUE);
          princ_string(CSTRING(")"));
          } 
        } 
    else { (Optimize.OPT->alloc_stack = v106826);
        print_external_call_c_producer(v106827,v107876,v40124);
        } 
      (Optimize.OPT->alloc_stack = v106826);
    } 
  GC_UNBIND;} 

void  print_external_call_c_producer(Generate_c_producer *v106827,Call_method *v107876,OID v40124)
{ GC_BIND;
  { method * v106837 = v107876->arg;
    list * v106836 = GC_OBJECT(list,v107876->args);
    Cint  v106838 = 1;
    list * v35216 = v106837->domain;
    c_princ_function(OBJECT(ClaireFunction,(*Optimize.functional_I)(_oid_(v106837))));
    princ_string(CSTRING("("));
    if (v106836->length > 4)
     (Optimize.OPT->level = (Optimize.OPT->level+1));
    if ((v106836->length == 1) && 
        (domain_I_restriction(v106837) == Kernel._void))
     v106836= Kernel.nil;
    { ITERATE(v106848);
      for (START(v106836); NEXT(v106848);)
      { if (v106838 != 1)
         { princ_string(CSTRING(","));
          if (v106836->length > 4)
           breakline_void();
          } 
        { ClaireClass * v35382 = psort_any((*(v35216))[v106838]);
          ClaireClass * v35383 = stupid_t_any1(v106848);
          if ((_inf_equalt_class(v35382,Kernel._object) == CTRUE) && 
              (_inf_equalt_class(v35383,v35382) != CTRUE))
           { princ_string(CSTRING("("));
            class_princ_class(v35382);
            princ_string(CSTRING(" *) "));
            } 
          } 
        (*Generate.expression)(v106848,
          v40124);
        ++v106838;
        } 
      } 
    princ_string(CSTRING(")"));
    if ((INHERIT(v106837->range->isa,Kernel._tuple)) && 
        (Optimize.OPT->alloc_stack != CTRUE))
     princ_string(CSTRING("->copyIfNeeded()"));
    if (v106836->length > 4)
     (Optimize.OPT->level = (Optimize.OPT->level-1));
    } 
  GC_UNBIND;} 

void  inline_exp_c_producer5(Generate_c_producer *v106827,Call *v107876,OID v40124)
{ GC_BIND;
  { property * v106840 = v107876->selector;
    OID  v34825 = GC_OID(car_list(v107876->args));
    Cint  v106838 = v107876->args->length;
    if (v106840 == Core.get_stack)
     { princ_string(CSTRING("ClEnv->stack["));
      (*Generate.expression)(v34825,
        v40124);
      princ_string(CSTRING("]"));
      } 
    else if (v106840 == Optimize.safe)
     { Cint  v106849 = Optimize.compiler->safety;
      (Optimize.compiler->safety = 1);
      (*Generate.expression)((*(v107876->args))[1],
        v40124);
      (Optimize.compiler->safety = v106849);
      } 
    else if (v106840 == Core.base_I)
     princ_string(CSTRING("ClEnv->base"));
    else if ((v106840 == Core.index_I) && 
        (v106838 == 1))
     princ_string(CSTRING("ClEnv->index"));
    else if ((v106840 == Core.push_I) && 
        (v106838 == 1))
     { princ_string(CSTRING("PUSH("));
      (*Generate.expression)(v34825,
        v40124);
      princ_string(CSTRING(")"));
      } 
    else if (v106840 == Core.put_stack)
     { princ_string(CSTRING("(ClEnv->stack["));
      (*Generate.expression)(v34825,
        v40124);
      princ_string(CSTRING("]="));
      (*Generate.expression)((*(v107876->args))[2],
        v40124);
      princ_string(CSTRING(")"));
      } 
    else if (v106840 == Core.set_base)
     { princ_string(CSTRING("(ClEnv->base= "));
      (*Generate.expression)(v34825,
        v40124);
      princ_string(CSTRING(")"));
      } 
    else if (v106840 == Core.set_index)
     { princ_string(CSTRING("(ClEnv->index= "));
      (*Generate.expression)(v34825,
        v40124);
      princ_string(CSTRING(")"));
      } 
    else if (v106840 == Optimize.object_I)
     { OID  v34826 = (*(v107876->args))[2];
      princ_string(CSTRING("("));
      ident_thing(defined_symbol(OBJECT(symbol,v34825)));
      princ_string(CSTRING("."));
      if (_inf_equal_type(OBJECT(ClaireType,v34826),Reader._reserved_keyword) == CTRUE)
       { princ_string(CSTRING("_cl_"));
        c_princ_string(string_v((*Kernel.string_I)(v34825)));
        } 
      else (*Language.ident)(v34825);
        princ_string(CSTRING(" = "));
      if ((v34826 == _oid_(Kernel._property)) && 
          (INHERIT(owner_any((*Kernel.value)(v34825)),Kernel._property)))
       { princ_string(CSTRING("property::make("));
        print_any(GC_OID((*Kernel.string_I)(v34825)));
        princ_string(CSTRING(","));
        princ_integer((*Kernel.open)(GC_OID((*Kernel.value)(v34825))));
        princ_string(CSTRING(","));
        expression_thing(OBJECT(thing,(*Kernel.module_I)(v34825)),Core.nil->value);
        princ_string(CSTRING(","));
        (*Generate.expression)(GC_OID((*Kernel.domain)(GC_OID((*Kernel.value)(v34825)))),
          Core.nil->value);
        princ_string(CSTRING(","));
        (*Kernel.princ)(GC_OID((*Kernel.dispatcher)(GC_OID((*Kernel.value)(v34825)))));
        princ_string(CSTRING(")"));
        } 
      else { princ_string(CSTRING("("));
          class_princ_class(OBJECT(ClaireClass,v34826));
          princ_string(CSTRING(" *) "));
          (*Generate.expression)(v34826,
            v40124);
          princ_string(CSTRING("->instantiate("));
          print_any(GC_OID((*Kernel.string_I)(v34825)));
          princ_string(CSTRING(","));
          expression_thing(OBJECT(thing,(*Kernel.module_I)(v34825)),Core.nil->value);
          princ_string(CSTRING(")"));
          } 
        princ_string(CSTRING(")"));
      } 
    else if (v106840 == Optimize.anyObject_I)
     { princ_string(CSTRING("(("));
      class_princ_class(OBJECT(ClaireClass,v34825));
      princ_string(CSTRING(" *) (*"));
      (*Generate.expression)(v34825,
        v40124);
      princ_string(CSTRING(")("));
      args_list_bag(GC_OBJECT(list,cdr_list(GC_OBJECT(list,v107876->args))),v40124,_sup_integer(v107876->args->length,2));
      princ_string(CSTRING("))"));
      } 
    else if ((OBJECT(ClaireBoolean,(*Generate.fcall_ask)(_oid_(v107876)))) == CTRUE)
     (*Generate.fcall_exp)(_oid_(v107876),
      v40124);
    else if (v107876->args->length > 20)
     { if (v107876->selector == Kernel.store)
       { list * v106836 = GC_OBJECT(list,v107876->args);
        Cint  v106838 = v106836->length;
        Cint  v106837 = (v106838/10);
        princ_string(CSTRING("("));
        { Cint  v106833 = 0;
          Cint  v82096 = v106837;
          { OID gc_local;
            while ((v106833 <= v82096))
            { GC_LOOP;
              princ_string(CSTRING("(*"));
              expression_thing(Kernel.store,v40124);
              princ_string(CSTRING(")("));
              { list * v13735;
                { list * v86939 = list::empty(Kernel.emptySet);
                  { Cint  v106834 = ((v106833*10)+1);
                    Cint  v82097 = ((v106833 == v106837) ?
                      v106838 :
                      ((v106833*10)+10) );
                    { OID gc_local;
                      while ((v106834 <= v82097))
                      { v86939->addFast((*(v106836))[v106834]);
                        ++v106834;
                        } 
                      } 
                    } 
                  v13735 = GC_OBJECT(list,v86939);
                  } 
                args_list_bag(v13735,v40124,CTRUE);
                } 
              princ_string(CSTRING(")"));
              if (v106833 != v106837)
               princ_string(CSTRING(","));
              ++v106833;
              GC_UNLOOP;} 
            } 
          } 
        princ_string(CSTRING(")"));
        } 
      else close_exception(((general_error *) (*Core._general_error)(_string_(CSTRING("[216] ~S has more than 10 parameters")),
          _oid_(list::alloc(1,_oid_(v107876))))));
        } 
    else { princ_string(CSTRING("(*"));
        expression_thing(v107876->selector,v40124);
        princ_string(CSTRING(")("));
        args_list_bag(GC_OBJECT(list,v107876->args),v40124,_sup_integer(v107876->args->length,1));
        princ_string(CSTRING(")"));
        } 
      } 
  GC_UNBIND;} 

ClaireBoolean * fcall_ask_Call2_Generate(Call *v106848)
{ GC_RESERVE(1);  // HOHO v3.0.55 optim !
  { ClaireBoolean *Result ;
    { property * v106840 = v106848->selector;
      OID  v34825 = GC_OID((*(v106848->args))[1]);
      Cint  v114841;
      { list * v14696;
        { bag * v18627 = v106848->args;
          list * v59248 = ((list *) empty_bag(v18627));
          { OID gc_local;
            ITERATE(v106849);
            for (START(v18627); NEXT(v106849);)
            if ((OBJECT(ClaireBoolean,(*Optimize.c_gc_ask)(v106849))) == CTRUE)
             v59248->addFast(v106849);
            } 
          v14696 = GC_OBJECT(list,v59248);
          } 
        v114841 = v14696->length;
        } 
      { ClaireBoolean *v_and;
        { v_and = ((designated_ask_any(v34825) == CTRUE) ? CTRUE : ((v106840->dispatcher > 0) ? CTRUE : CFALSE));
          if (v_and == CFALSE) Result =CFALSE; 
          else { { list * v106836 = GC_OBJECT(list,cdr_list(GC_OBJECT(list,v106848->args)));
              ClaireType * v57799 = Kernel.emptySet;
              list * v35232;
              { { bag *v_list; OID v_val;
                  OID v106849,CLcount;
                  v_list = GC_OBJECT(list,v106848->args);
                   v35232 = v_list->clone();
                  for (CLcount= 1; CLcount <= v_list->length; CLcount++)
                  { v106849 = (*(v_list))[CLcount];
                    v_val = _oid_(ptype_type(OBJECT(ClaireType,(*Optimize.c_type)(v106849))));
                    
                    (*((list *) v35232))[CLcount] = v_val;} 
                  } 
                GC_OBJECT(list,v35232);} 
              list * v43666 = GC_OBJECT(list,cdr_list(v35232));
              list * v35230 = GC_OBJECT(list,get_restrictions_Call2(v106848,v35232));
              ClaireBoolean * v66718;
              { ClaireBoolean *v_and;
                { v_and = ((v35230->length > 0) ? CTRUE : CFALSE);
                  if (v_and == CFALSE) v66718 =CFALSE; 
                  else { { ClaireBoolean *v_or;
                      { v_or = ((v114841 == 0) ? CTRUE : CFALSE);
                        if (v_or == CTRUE) v_and =CTRUE; 
                        else { { OID  v15657;
                            { OID gc_local;
                              ITERATE(v106837);
                              v15657= Kernel.cfalse;
                              for (START(v35230); NEXT(v106837);)
                              if (not_any(_oid_(nth_integer(status_I_restriction(OBJECT(restriction,v106837)),1))) != CTRUE)
                               { v15657 = Kernel.ctrue;
                                break;} 
                              } 
                            v_or = not_any(v15657);
                            } 
                          if (v_or == CTRUE) v_and =CTRUE; 
                          else v_and = CFALSE;} 
                        } 
                      } 
                    if (v_and == CFALSE) v66718 =CFALSE; 
                    else { v_and = (((v106840->dispatcher > 0) && 
                          (v106836->length <= 4)) ? CTRUE : ((v35230->length < 3) ? CTRUE : CFALSE));
                      if (v_and == CFALSE) v66718 =CFALSE; 
                      else v66718 = CTRUE;} 
                    } 
                  } 
                } 
              ClaireClass * v106843 = ((v35230->length > 0) ?
                c_srange_method(OBJECT(method,(*(v35230))[1])) :
                Kernel._void );
              ClaireBoolean * v41978;
              { OID  v16618;
                { OID gc_local;
                  ITERATE(v106842);
                  v16618= Kernel.cfalse;
                  for (START(v35230); NEXT(v106842);)
                  { GC_LOOP;
                    { ClaireBoolean * g0084I;
                      { OID  v18540;
                        { GC__ANY(v57799 = U_type(v57799,domain_I_restriction(OBJECT(restriction,v106842))), 1);
                          v18540 = _oid_(((INHERIT(OWNER((*(OBJECT(restriction,v106842)->domain))[1]),Kernel._class)) ? ((last_list(OBJECT(restriction,v106842)->domain) != _oid_(Kernel._listargs)) ? ((tmatch_ask_list(v43666,GC_OBJECT(list,cdr_list(OBJECT(restriction,v106842)->domain))) == CTRUE) ? ((c_srange_method(OBJECT(method,v106842)) == v106843) ? CTRUE: CFALSE): CFALSE): CFALSE): CFALSE));
                          } 
                        g0084I = not_any(v18540);
                        } 
                      
                      if (g0084I == CTRUE) { v16618 = Kernel.ctrue;
                          break;} 
                        } 
                    GC_UNLOOP;} 
                  } 
                v41978 = not_any(v16618);
                } 
              ClaireBoolean * v5330 = (((v106843 == Kernel._integer) || 
                  ((v106843 == Kernel._object) || 
                    ((v106843 == Kernel._any) || 
                      (v106843 == Kernel._void)))) ? ((_inf_equal_type(v57799,Kernel._object) == CTRUE) ? ((_inf_equal_type(GC_OBJECT(ClaireType,ptype_type(OBJECT(ClaireType,(*Optimize.c_type)(v34825)))),v57799) == CTRUE) ? CTRUE: CFALSE): CFALSE): CFALSE);
              if (((OBJECT(ClaireBoolean,Generate.FCALLSTINKS->value)) == CTRUE) && 
                  ((((v66718 == CTRUE) ? ((v41978 == CTRUE) ? ((v5330 == CTRUE) ? CTRUE: CFALSE): CFALSE): CFALSE) != CTRUE) && 
                    (v106840->dispatcher > 0)))
               tformat_string(CSTRING("****> fcall(~S) fails (selectorOK = ~S , lrOK = ~S, callOK = ~S)\n"),0,GC_OBJECT(list,list::alloc(4,_oid_(v106848),
                _oid_(v66718),
                _oid_(v41978),
                _oid_(v5330))));
              v_and = ((v66718 == CTRUE) ? ((v41978 == CTRUE) ? ((v5330 == CTRUE) ? CTRUE: CFALSE): CFALSE): CFALSE);
              } 
            if (v_and == CFALSE) Result =CFALSE; 
            else Result = CTRUE;} 
          } 
        } 
      } 
    GC_UNBIND; return (Result);} 
  } 

list * get_restrictions_Call2(Call *v106848,list *v35232)
{ GC_RESERVE(1);  // HOHO v3.0.55 optim !
  { list *Result ;
    { property * v106840 = v106848->selector;
      ClaireBoolean * v77532 = ((class_I_type(OBJECT(ClaireType,(*(v35232))[1]))->open == ClEnv->open) ? CTRUE : CFALSE);
      list * v35230 = list::empty(Kernel._method);
      if ((v106840->dispatcher == 0) && 
          ((v77532 == CTRUE) || 
              (v106840->open == ClEnv->open)))
       ;else { OID gc_local;
          ITERATE(v106842);
          for (START(v106840->restrictions); NEXT(v106842);)
          { GC_LOOP;
            if (length_bag(_exp_list(OBJECT(restriction,v106842)->domain,v35232)) != 0)
             { if (Kernel._method == OBJECT(ClaireObject,v106842)->isa)
               GC__ANY(v35230 = v35230->addFast(v106842), 1);
              else { shrink_list(v35230,0);
                  break;} 
                } 
            GC_UNLOOP;} 
          } 
        Result = v35230;
      } 
    GC_UNBIND; return (Result);} 
  } 

void  fcall_exp_Call2_Generate(Call *v106848,OID v40124)
{ GC_RESERVE(1);  // HOHO v3.0.55 optim !
  { property * v106840 = v106848->selector;
    OID  v34825 = (*(v106848->args))[1];
    list * v35232;
    { { bag *v_list; OID v_val;
        OID v106849,CLcount;
        v_list = v106848->args;
         v35232 = v_list->clone();
        for (CLcount= 1; CLcount <= v_list->length; CLcount++)
        { v106849 = (*(v_list))[CLcount];
          v_val = _oid_(ptype_type(OBJECT(ClaireType,(*Optimize.c_type)(v106849))));
          
          (*((list *) v35232))[CLcount] = v_val;} 
        } 
      GC_OBJECT(list,v35232);} 
    list * v35230 = GC_OBJECT(list,get_restrictions_Call2(v106848,v35232));
    method * v106837 = OBJECT(method,(*(v35230))[1]);
    ClaireClass * v106843 = c_srange_method(v106837);
    if (v106843 == Kernel._void)
     princ_string(CSTRING("_void_("));
    else if (v106843 == Kernel._object)
     princ_string(CSTRING("_oid_("));
    else if ((v106843 == Kernel._integer) && 
        (Optimize.compiler->safety <= 2))
     princ_string(CSTRING("_integer_("));
    if ((v106840->dispatcher > 0) && 
        (v35232->length <= 4))
     { if (v106843 == Kernel._object)
       princ_string(CSTRING("(ClaireObject *) "));
      expression_thing(v106840,v40124);
      princ_string(CSTRING("->fcall("));
      c_sorted_args_Call(v106848,v106837->srange,v40124,CTRUE);
      princ_string(CSTRING(")"));
      } 
    else { list * v43604;
        { { bag * v119908 = v106840->definition;
            list * v53231 = ((list *) empty_bag(v119908));
            { OID gc_local;
              ITERATE(v106848);
              for (START(v119908); NEXT(v106848);)
              if (v35230->memq(v106848) == CTRUE)
               v53231->addFast(v106848);
              } 
            v43604 = GC_OBJECT(list,v53231);
            } 
          GC_OBJECT(list,v43604);} 
        { OID gc_local;
          ITERATE(v106837);
          for (START(v43604); NEXT(v106837);)
          { GC_LOOP;
            { list * v126198;
              { { bag *v_list; OID v_val;
                  OID v106848,CLcount;
                  v_list = OBJECT(restriction,v106837)->domain;
                   v126198 = v_list->clone();
                  for (CLcount= 1; CLcount <= v_list->length; CLcount++)
                  { v106848 = (*(v_list))[CLcount];
                    v_val = _oid_(psort_any(v106848));
                    
                    (*((list *) v126198))[CLcount] = v_val;} 
                  } 
                GC_OBJECT(list,v126198);} 
              if (v106837 != last_list(v43604))
               { princ_string(CSTRING("(INHERIT("));
                if (INHERIT(OWNER(v34825),Optimize._to_CL))
                 { (*Generate.expression)(GC_OID((*Kernel.arg)(v34825)),
                    v40124);
                  princ_string(CSTRING("->isa"));
                  } 
                else { princ_string(CSTRING("OWNER("));
                    (*Generate.expression)(v34825,
                      v40124);
                    princ_string(CSTRING(")"));
                    } 
                  princ_string(CSTRING(","));
                expression_any(_oid_(domain_I_restriction(OBJECT(restriction,v106837))),v40124);
                princ_string(CSTRING(") ? "));
                if (v106843 == Kernel._object)
                 princ_string(CSTRING("(ClaireObject *)"));
                princ_string(CSTRING(" "));
                c_princ_function(OBJECT(ClaireFunction,(*Optimize.functional_I)(v106837)));
                princ_string(CSTRING("(("));
                class_princ_class(domain_I_restriction(OBJECT(restriction,v106837)));
                princ_string(CSTRING(" *) "));
                c_sorted_args_Call(v106848,v126198,v40124,CFALSE);
                princ_string(CSTRING(") : "));
                ;princ_string(CSTRING(" "));
                } 
              else { if (v106843 == Kernel._object)
                   princ_string(CSTRING("(ClaireObject *) "));
                  princ_string(CSTRING(" "));
                  c_princ_function(OBJECT(ClaireFunction,(*Optimize.functional_I)(v106837)));
                  princ_string(CSTRING("(("));
                  (*Generate.interface_I)(Generate.PRODUCER->value,
                    _oid_(domain_I_restriction(OBJECT(restriction,v106837))));
                  princ_string(CSTRING(") "));
                  c_sorted_args_Call(v106848,v126198,v40124,CFALSE);
                  princ_string(CSTRING(")"));
                  { Cint  v106833 = 1;
                    Cint  v82126 = (v43604->length-1);
                    { OID gc_local;
                      while ((v106833 <= v82126))
                      { princ_string(CSTRING(")"));
                        ++v106833;
                        } 
                      } 
                    } 
                  } 
                } 
            GC_UNLOOP;} 
          } 
        } 
      if ((v106843 == Kernel._void) || 
        ((v106843 == Kernel._object) || 
          ((v106843 == Kernel._float) || 
            ((v106843 == Kernel._integer) && 
                (Optimize.compiler->safety <= 2)))))
     princ_string(CSTRING(")"));
    } 
  GC_UNBIND;} 

void  c_sorted_arg_any(OID v106848,ClaireClass *v106843,OID v40124,ClaireBoolean *v52684)
{ GC_BIND;
  if (v52684 == CTRUE)
   princ_string(CSTRING("((Cint) "));
  if ((INHERIT(OWNER(v106848),Optimize._to_CL)) && (osort_any(_oid_(OBJECT(Compile_to_CL,v106848)->set_arg)) == v106843))
   (*Generate.expression)(GC_OID((*Kernel.arg)(v106848)),
    v40124);
  else if (v106843 == Kernel._any)
   (*Generate.expression)(v106848,
    v40124);
  else (*Generate.to_c)(Generate.PRODUCER->value,
      v106848,
      _oid_(v106843),
      v40124);
    if (v52684 == CTRUE)
   princ_string(CSTRING(")"));
  GC_UNBIND;} 

void  c_sorted_args_Call(Call *v106848,list *v35231,OID v40124,ClaireBoolean *v52684)
{ GC_BIND;
  { Cint  v106833 = 0;
    { OID gc_local;
      ITERATE(v106849);
      for (START(v106848->args); NEXT(v106849);)
      { if (v106833 != 0)
         princ_string(CSTRING(","));
        ++v106833;
        c_sorted_arg_any(v106849,OBJECT(ClaireClass,(*(v35231))[v106833]),v40124,v52684);
        } 
      } 
    } 
  GC_UNBIND;} 

void  bitvector_I_c_producer(Generate_c_producer *v106827,OID v106848)
{ GC_BIND;
  if (INHERIT(OWNER(v106848),Kernel._integer))
   bitvectorSum_integer(v106848);
  else if (INHERIT(OWNER(v106848),Optimize._to_CL))
   bitvector_I_c_producer(v106827,GC_OID(OBJECT(Compile_to_CL,v106848)->arg));
  else if (INHERIT(OWNER(v106848),Optimize._to_protect))
   bitvector_I_c_producer(v106827,GC_OID(OBJECT(Compile_to_protect,v106848)->arg));
  else (*Generate.expression)(v106848,
      Core.nil->value);
    GC_UNBIND;} 

void  bitvectorSum_integer(Cint v106848)
{ if (v106848 == 0)
   princ_string(CSTRING("0"));
  else { ClaireBoolean * v106826 = CFALSE;
      Cint  v106833 = 1;
      Cint  v82127 = 7;
      { while ((v106833 <= v82127))
        { if (BCONTAIN(v106848,v106833))
           { if (v106826 == CTRUE)
             princ_string(CSTRING("+"));
            else v106826= CTRUE;
              princ_string(string_v((*(OBJECT(bag,Generate.bitvectorList->value)))[v106833]));
            } 
          ++v106833;
          } 
        } 
      } 
    } 

void  signature_I_c_producer(Generate_c_producer *v106827,OID v106848)
{ GC_BIND;
  if (INHERIT(OWNER(v106848),Kernel._list))
   { princ_string(CSTRING("list::domain("));
    princ_integer(OBJECT(bag,v106848)->length);
    princ_string(CSTRING(","));
    { list * v21423;
      { { bag *v_list; OID v_val;
          OID v106849,CLcount;
          v_list = OBJECT(bag,v106848);
           v21423 = v_list->clone();
          for (CLcount= 1; CLcount <= v_list->length; CLcount++)
          { v106849 = (*(v_list))[CLcount];
            v_val = getC_any(v106849);
            
            (*((list *) v21423))[CLcount] = v_val;} 
          } 
        GC_OBJECT(list,v21423);} 
      args_list_bag(v21423,Core.nil->value,_sup_integer(OBJECT(bag,v106848)->length,3));
      } 
    princ_string(CSTRING(")"));
    } 
  else if (INHERIT(OWNER(v106848),Optimize._to_C))
   signature_I_c_producer(v106827,GC_OID(OBJECT(Compile_to_C,v106848)->arg));
  else if (INHERIT(OWNER(v106848),Optimize._to_protect))
   signature_I_c_producer(v106827,GC_OID(OBJECT(Compile_to_protect,v106848)->arg));
  else if (INHERIT(OWNER(v106848),Language._List))
   signature_I_c_producer(v106827,GC_OID(_oid_(OBJECT(Construct,v106848)->args)));
  else if (INHERIT(OWNER(v106848),Language._Variable))
   expression_Variable(OBJECT(Variable,v106848),Core.nil->value);
  else { princ_string(CSTRING("<fucking "));
      print_any(_oid_(OWNER(v106848)));
      princ_string(CSTRING(":"));
      print_any(v106848);
      princ_string(CSTRING(">"));
      } 
    GC_UNBIND;} 

OID  getC_any(OID v106848)
{ GC_BIND;
  { OID Result = 0;
    if (INHERIT(OWNER(v106848),Optimize._to_CL))
     Result = getC_any(GC_OID(OBJECT(Compile_to_CL,v106848)->arg));
    else if (INHERIT(OWNER(v106848),Optimize._to_protect))
     Result = getC_any(GC_OID(OBJECT(Compile_to_protect,v106848)->arg));
    else if (INHERIT(OWNER(v106848),Core._global_variable))
     { if (nativeVar_ask_global_variable(OBJECT(global_variable,v106848)) == CTRUE)
       Result = v106848;
      else { Compile_to_C * v109096 = ((Compile_to_C *) GC_OBJECT(Compile_to_C,new_object_class(Optimize._to_C)));
          (v109096->arg = v106848);
          (v109096->set_arg = Kernel._type);
          add_I_property(Kernel.instances,Optimize._to_C,11,_oid_(v109096));
          Result = _oid_(v109096);
          } 
        } 
    else Result = v106848;
      GC_UNBIND; return (Result);} 
  } 

void  gassign_c_producer(Generate_c_producer *v106827,Gassign *v107876,OID v40124)
{ GC_BIND;
  if (v107876->var->store_ask == CTRUE)
   { princ_string(CSTRING("(STOREI("));
    expression_global_variable(v107876->var,v40124);
    princ_string(CSTRING(","));
    (*Generate.expression)(v107876->arg,
      v40124);
    princ_string(CSTRING("))"));
    } 
  else { princ_string(CSTRING("("));
      expression_global_variable(v107876->var,v40124);
      princ_string(CSTRING("= "));
      (*Generate.expression)(v107876->arg,
        v40124);
      princ_string(CSTRING(")"));
      } 
    GC_UNBIND;} 

void  call_slot_c_producer(Generate_c_producer *v106827,Call_slot *v107876,OID v40124)
{ GC_BIND;
  if (v107876->test == CTRUE)
   { princ_string((((INHERIT(v107876->selector->srange,Kernel._cl_import)) || 
        ((INHERIT(v107876->selector->srange,Kernel._string)) || 
          ((INHERIT(v107876->selector->srange,Kernel._array)) || 
            (INHERIT(v107876->selector->srange,Kernel._object))))) ?
      CSTRING("NOTNULL") :
      CSTRING("KNOWN") ));
    princ_string(CSTRING("("));
    expression_thing(v107876->selector->selector,v40124);
    princ_string(CSTRING(","));
    } 
  c_member_c_producer(v106827,
    GC_OID(v107876->arg),
    psort_any(_oid_(domain_I_restriction(v107876->selector))),
    v107876->selector->selector,
    v40124);
  if (v107876->test == CTRUE)
   princ_string(CSTRING(")"));
  GC_UNBIND;} 

void  call_table_c_producer(Generate_c_producer *v106827,Call_table *v107876,OID v40124)
{ GC_BIND;
  { table * v106825 = v107876->selector;
    OID  v106840 = v106825->params;
    OID  v106836 = v107876->arg;
    if (v107876->test == CTRUE)
     { princ_string(CSTRING("KNOWN("));
      expression_thing(v106825,v40124);
      princ_string(CSTRING(","));
      } 
    princ_string(CSTRING("(*("));
    expression_thing(v106825,v40124);
    princ_string(CSTRING("->graph))["));
    if (INHERIT(OWNER(v106840),Kernel._integer))
     { (*Generate.expression)(v106836,
        v40124);
      princ_string(CSTRING(" - "));
      princ_integer(v106840);
      princ_string(CSTRING(""));
      } 
    else if (INHERIT(OWNER(v106840),Kernel._list))
     { (*Generate.expression)((*(OBJECT(bag,(*Core.args)(v106836))))[1],
        v40124);
      princ_string(CSTRING(" * "));
      (*Kernel.princ)((*(OBJECT(bag,v106840)))[1]);
      princ_string(CSTRING(" + "));
      (*Generate.expression)((*(OBJECT(bag,(*Core.args)(v106836))))[2],
        v40124);
      princ_string(CSTRING(" - "));
      (*Kernel.princ)((*(OBJECT(bag,v106840)))[2]);
      princ_string(CSTRING(""));
      } 
    princ_string(CSTRING("]"));
    if (v107876->test == CTRUE)
     princ_string(CSTRING(")"));
    } 
  GC_UNBIND;} 

void  call_array_c_producer(Generate_c_producer *v106827,Call_array *v107876,OID v40124)
{ GC_BIND;
  if (v107876->test == _oid_(Kernel._float))
   { princ_string(CSTRING("((double *) "));
    (*Generate.expression)(v107876->selector,
      v40124);
    princ_string(CSTRING(")["));
    (*Generate.expression)(v107876->arg,
      v40124);
    princ_string(CSTRING("]"));
    } 
  else { princ_string(CSTRING("((OID *) "));
      (*Generate.expression)(v107876->selector,
        v40124);
      princ_string(CSTRING(")["));
      (*Generate.expression)(v107876->arg,
        v40124);
      princ_string(CSTRING("]"));
      } 
    GC_UNBIND;} 

void  update_c_producer(Generate_c_producer *v106827,Update *v107876,OID v40124)
{ GC_BIND;
  { OID  v106840 = v107876->selector;
    OID  v106825 = v107876->arg;
    OID  v106846 = v107876->value;
    OID  v106848 = v107876->var;
    ClaireClass * v106843 = OBJECT(ClaireClass,(*Optimize.c_sort)(v106846));
    if ((INHERIT(OWNER(v106840),Kernel._relation)) && ((OBJECT(ClaireRelation,v106840)->if_write != CNULL) && 
        ((v106825 != _oid_(Kernel.put)) && 
          (v106825 != _oid_(Core.put_store)))))
     { c_princ_string(string_I_symbol(OBJECT(symbol,(*Kernel.name)(v106840))));
      princ_string(CSTRING("_write("));
      (*Generate.expression)(GC_OID((*Kernel.arg)(v106848)),
        v40124);
      princ_string(CSTRING(","));
      (*Generate.expression)(v106846,
        v40124);
      princ_string(CSTRING(")"));
      } 
    else if ((INHERIT(OWNER(v106840),Kernel._relation)) && ((OBJECT(ClaireRelation,v106840)->store_ask == CTRUE) || 
        (v106825 == _oid_(Core.put_store))))
     { princ_string(CSTRING("STORE"));
      princ_string((((v106843 == Kernel._any) || 
          (v106843 == Kernel._integer)) ?
        CSTRING("I") :
        ((v106843 == Kernel._float) ?
          CSTRING("F") :
          CSTRING("O") ) ));
      princ_string(CSTRING("("));
      (*Generate.expression)(v106848,
        v40124);
      princ_string(CSTRING(","));
      (*Generate.expression)(v106846,
        v40124);
      princ_string(CSTRING(")"));
      } 
    else { princ_string(CSTRING("("));
        (*Generate.expression)(v106848,
          v40124);
        princ_string(CSTRING(" = "));
        (*Generate.expression)(v106846,
          v40124);
        princ_string(CSTRING(")"));
        } 
      } 
  GC_UNBIND;} 

void  object_test_c_producer(Generate_c_producer *v106827,OID v34825,ClaireBoolean *v28291,OID v40124)
{ princ_string(CSTRING("(CTAG("));
  (*Generate.expression)(v34825,
    v40124);
  princ_string(CSTRING(") "));
  sign_equal_boolean(v28291);
  princ_string(CSTRING(" OBJ_CODE)"));
  } 

void  exp_to_protect_c_producer(Generate_c_producer *v106827,Compile_to_protect *v107876,OID v40124)
{ GC_BIND;
  { OID  v35449 = GC_OID((*Optimize.c_type)(v107876->arg));
    if ((Optimize.OPT->protection == CTRUE) && 
        ((need_protect_any(v107876->arg) == CTRUE) && 
          (((Optimize.OPT->alloc_stack == CTRUE) ? ((_inf_equal_type(OBJECT(ClaireType,v35449),Kernel._tuple) == CTRUE) ? CTRUE: CFALSE): CFALSE) != CTRUE)))
     { OID  v106848 = v107876->arg;
      ClaireClass * v106843 = OBJECT(ClaireClass,(*Optimize.c_sort)(v106848));
      princ_string(gc_protect_class(v106843));
      princ_string(CSTRING("("));
      if (INHERIT(v106843,Kernel._object))
       { class_princ_class(psort_any((*Core.glb)(GC_OID((*Optimize.c_type)(v106848)),
          _oid_(v106843))));
        princ_string(CSTRING(","));
        (*Generate.expression)(v107876->arg,
          v40124);
        princ_string(CSTRING(""));
        } 
      else (*Generate.expression)(v107876->arg,
          v40124);
        princ_string(CSTRING(")"));
      } 
    else (*Generate.expression)(v107876->arg,
        v40124);
      } 
  GC_UNBIND;} 

char * gc_protect_class(ClaireClass *v106827)
{ { char *Result ;
    Result = ((v106827 == Kernel._any) ?
      CSTRING("GC_OID") :
      ((v106827 == Kernel._string) ?
        CSTRING("GC_STRING") :
        ((v106827 == Kernel._array) ?
          CSTRING("GC_ARRAY") :
          ((INHERIT(v106827,Kernel._object)) ?
            CSTRING("GC_OBJECT") :
            CSTRING("") ) ) ) );
    return (Result);} 
  } 

void  macro_c_producer(Generate_c_producer *v106827)
{ ;} 

void  init_var_c_producer(Generate_c_producer *v106827,ClaireClass *v106843)
{ ;} 

void  any_interface_c_producer(Generate_c_producer *v106827)
{ princ_string(CSTRING("OID"));
  } 

void  pointer_cast_c_producer(Generate_c_producer *v106827,ClaireClass *v106843)
{ princ_string(CSTRING("("));
  class_princ_c_producer(v106827,v106843);
  princ_string(CSTRING(" *)"));
  } 

void  exp_Assign_c_producer(Generate_c_producer *v106827,Assign *v107876,OID v40124)
{ GC_BIND;
  { OID  v106848 = v107876->arg;
    OID  v106846 = v107876->var;
    (*Language.ident)(Generate.PRODUCER->value,
      v106846);
    princ_string(CSTRING("= "));
    (*Generate.expression)(v106848,
      v40124);
    princ_string(CSTRING(""));
    } 
  GC_UNBIND;} 

void  stat_handle_c_producer(Generate_c_producer *v106827,ClaireHandle *v107876,OID v106843,OID v40124)
{ GC_BIND;
  new_block_void();
  princ_string(CSTRING("ClaireHandler c_handle = ClaireHandler();"));
  breakline_void();
  princ_string(CSTRING("if ERROR_IN "));
  breakline_void();
  new_block_void();
  statement_any(GC_OID(v107876->arg),v106843,v40124);
  princ_string(CSTRING("ClEnv->cHandle--;"));
  close_block_void();
  princ_string(CSTRING("else if (belong_to(_oid_(ClEnv->exception_I),"));
  (*Generate.expression)(GC_OID((*Optimize.c_code)(GC_OID(v107876->test),
      _oid_(Kernel._any))),
    _oid_(Kernel.emptySet));
  princ_string(CSTRING(") == CTRUE)"));
  breakline_void();
  new_block_void();
  princ_string(CSTRING("c_handle.catchIt();"));
  statement_any(GC_OID(v107876->other),v106843,v40124);
  close_block_void();
  princ_string(CSTRING("else PREVIOUS_HANDLER;"));
  close_block_void();
  GC_UNBIND;} 

void  stat_construct_c_producer(Generate_c_producer *v106827,Construct *v107876,OID v106843,OID v40124)
{ GC_BIND;
  if (boolean_I_any(v106843) != CTRUE)
   close_exception(((general_error *) (*Core._general_error)(_string_(CSTRING("[202] A do should have been used for ~S")),
    _oid_(list::alloc(1,_oid_(v107876))))));
  { char * v106846 = GC_STRING(check_var_string(CSTRING("v_bag"),v106843,v40124));
    bag * v107657;
    { ClaireObject *V_CC ;
      if (INHERIT(v107876->isa,Language._List))
       V_CC = list::empty();
      else if (INHERIT(v107876->isa,Language._Set))
       V_CC = set::empty();
      else if (INHERIT(v107876->isa,Language._Tuple))
       V_CC = tuple::empty();
      else close_exception(((general_error *) (*Core._general_error)(_string_(CSTRING("BUG: ~S")),
          _oid_(list::alloc(1,_oid_(v107876))))));
        v107657= (bag *) V_CC;} 
    new_block_void();
    if (get_property(Kernel.of,v107876) != CNULL)
     cast_I_bag(v107657,OBJECT(ClaireType,(*Kernel.of)(_oid_(v107876))));
    { ClaireBoolean * g0090I;
      { OID  v44487;
        { OID gc_local;
          ITERATE(v106848);
          v44487= Kernel.cfalse;
          bag *v106848_support;
          v106848_support = GC_OBJECT(list,v107876->args);
          for (START(v106848_support); NEXT(v106848);)
          if (c_func_any(v106848) != CTRUE)
           { v44487 = Kernel.ctrue;
            break;} 
          } 
        g0090I = boolean_I_any(v44487);
        } 
      
      if (g0090I == CTRUE) { princ_string(CSTRING("OID "));
          princ_string(v106846);
          princ_string(CSTRING(";"));
          breakline_void();
          princ_string(CSTRING(""));
          } 
        } 
    if (Optimize.OPT->protection == CTRUE)
     { (v106827->stat = (v106827->stat+1));
      princ_string(CSTRING("GC_ANY("));
      } 
    (*Kernel.c_princ)(v106843);
    princ_string(CSTRING("= "));
    (*Generate.bag_expression)(Generate.PRODUCER->value,
      _oid_(v107657->isa),
      _oid_(v107657),
      GC_OID(_oid_(of_bag(v107657))),
      v40124);
    if (Optimize.OPT->protection == CTRUE)
     princ_string(CSTRING(")"));
    princ_string(CSTRING(";"));
    { OID gc_local;
      ITERATE(v106848);
      bag *v106848_support;
      v106848_support = GC_OBJECT(list,v107876->args);
      for (START(v106848_support); NEXT(v106848);)
      { ClaireBoolean * v106830 = c_func_any(v106848);
        breakline_void();
        if (v106830 != CTRUE)
         statement_any(v106848,_string_(v106846),v40124);
        princ_string(CSTRING("(("));
        { OID  v45448;
          if (INHERIT(v107876->isa,Language._List))
           v45448 = _oid_(Kernel._list);
          else if (INHERIT(v107876->isa,Language._Set))
           v45448 = _oid_(Kernel._set);
          else v45448 = _oid_(Kernel._tuple);
            print_any(v45448);
          } 
        princ_string(CSTRING(" *) "));
        (*Kernel.c_princ)(v106843);
        princ_string(CSTRING(")"));
        addFast_c_producer(v106827);
        princ_string(CSTRING("("));
        if (v106830 == CTRUE)
         (*Generate.expression)(v106848,
          v40124);
        else c_princ_string(v106846);
          princ_string(CSTRING(");"));
        } 
      } 
    close_block_void();
    } 
  GC_UNBIND;} 

void  stat_while_c_producer(Generate_c_producer *v106827,While *v107876,OID v106843,OID v40124)
{ GC_BIND;
  new_block_void();
  { ClaireBoolean * v34993 = ((c_func_any(GC_OID(v107876->test)) == CTRUE) ? ((v107876->other != CTRUE) ? ((gc_usage_any(v107876->test,OBJECT(ClaireBoolean,v40124)) == Kernel.cfalse) ? CTRUE: CFALSE): CFALSE): CFALSE);
    char * v106846 = GC_STRING(check_var_string(CSTRING("v_while"),v106843,v40124));
    if (Optimize.OPT->loop_gc == CTRUE)
     { princ_string(CSTRING("OID gc_local;"));
      breakline_void();
      princ_string(CSTRING(""));
      } 
    if (v34993 != CTRUE)
     { interface_I_class(Kernel._boolean);
      princ_string(v106846);
      princ_string(CSTRING(";"));
      breakline_void();
      princ_string(CSTRING(""));
      } 
    if (Kernel._string == OWNER(v106843))
     { (*Kernel.c_princ)(v106843);
      princ_string(CSTRING("= _oid_("));
      expression_boolean(CFALSE,v40124);
      princ_string(CSTRING(");"));
      breakline_void();
      } 
    if (v34993 == CTRUE)
     { princ_string(CSTRING("while ("));
      (*Optimize.bool_exp)(GC_OID(v107876->test),
        _oid_(not_any(_oid_(v107876->other))),
        v40124);
      princ_string(CSTRING(")"));
      } 
    else { { OID  v46409;
          { if (v107876->other == CTRUE)
             v46409 = Kernel.cfalse;
            else v46409 = v107876->test;
              GC_OID(v46409);} 
          statement_any(v46409,_string_(v106846),Kernel.ctrue);
          } 
        breakline_void();
        princ_string(CSTRING("while ("));
        princ_string(v106846);
        princ_string(CSTRING(" "));
        if (v107876->other == CTRUE)
         princ_string(CSTRING("!="));
        else princ_string(CSTRING("=="));
          princ_string(CSTRING(" CTRUE)"));
        } 
      breakline_void();
    new_block_void();
    { ClaireBoolean * v45806 = ((Optimize.OPT->loop_gc == CTRUE) ? ((gc_usage_any(v107876->arg,CTRUE) != Kernel.cfalse) ? CTRUE: CFALSE): CFALSE);
      if (v45806 == CTRUE)
       { princ_string(CSTRING("GC_LOOP;"));
        breakline_void();
        } 
      { OID  v47370;
        if (Kernel._string == OWNER(v106843))
         v47370 = v106843;
        else v47370 = CNULL;
          inner_statement_any(GC_OID(v107876->arg),_oid_(Kernel.emptySet),v47370);
        } 
      if (v34993 != CTRUE)
       statement_any(GC_OID(v107876->test),_string_(v106846),Kernel.ctrue);
      if (v45806 == CTRUE)
       princ_string(CSTRING("GC_UNLOOP;"));
      } 
    close_block_void();
    } 
  close_block_void();
  GC_UNBIND;} 

void  stat_gassign_c_producer(Generate_c_producer *v106827,Gassign *v107876,OID v106843,OID v40124)
{ GC_BIND;
  new_block_void();
  interface_I_c_producer(v106827,((nativeVar_ask_global_variable(v107876->var) == CTRUE) ?
    getRange_global_variable(v107876->var) :
    Kernel._any ));
  princ_string(CSTRING(" truc;"));
  statement_any(GC_OID(v107876->arg),_string_(CSTRING("truc")),v40124);
  princ_string(CSTRING(""));
  breakline_void();
  if (v107876->var->store_ask == CTRUE)
   { princ_string(CSTRING("STOREI("));
    expression_global_variable(v107876->var,v40124);
    princ_string(CSTRING(",truc);"));
    } 
  else { princ_string(CSTRING("("));
      expression_global_variable(v107876->var,v40124);
      princ_string(CSTRING(" = truc);"));
      } 
    close_block_void();
  GC_UNBIND;} 

void  stat_for_c_producer(Generate_c_producer *v106827,For *v107876,OID v106843,OID v40124)
{ GC_BIND;
  { char * v106846 = GC_STRING(c_string_c_producer1(v106827,GC_OBJECT(Variable,v107876->var)));
    new_block_void();
    if (Optimize.OPT->loop_gc == CTRUE)
     { princ_string(CSTRING("OID gc_local;"));
      breakline_void();
      princ_string(CSTRING(""));
      } 
    princ_string(CSTRING("ITERATE("));
    c_princ_string(v106846);
    princ_string(CSTRING(");"));
    if (Kernel._string == OWNER(v106843))
     { breakline_void();
      (*Kernel.c_princ)(v106843);
      princ_string(CSTRING("= Kernel.cfalse;"));
      } 
    breakline_void();
    if ((c_func_any(GC_OID(v107876->set_arg)) == CTRUE) && 
        (designated_ask_any(GC_OID(v107876->set_arg)) == CTRUE))
     { princ_string(CSTRING("for (START("));
      (*Generate.expression)(GC_OID(v107876->set_arg),
        v40124);
      princ_string(CSTRING("); NEXT("));
      c_princ_string(v106846);
      princ_string(CSTRING(");)"));
      } 
    else { char * v35476 = GC_STRING(append_string(v106846,CSTRING("_support")));
        princ_string(CSTRING("bag *"));
        c_princ_string(v35476);
        princ_string(CSTRING(";"));
        breakline_void();
        princ_string(CSTRING(""));
        statement_any(GC_OID(v107876->set_arg),_string_(v35476),v40124);
        princ_string(CSTRING("for (START("));
        c_princ_string(v35476);
        princ_string(CSTRING("); NEXT("));
        c_princ_string(v106846);
        princ_string(CSTRING(");)"));
        } 
      breakline_void();
    { ClaireBoolean * v45806 = ((Optimize.OPT->loop_gc == CTRUE) ? ((gc_usage_any(v107876->arg,CTRUE) != Kernel.cfalse) ? CTRUE: CFALSE): CFALSE);
      if (v45806 == CTRUE)
       { new_block_void();
        princ_string(CSTRING("GC_LOOP;"));
        breakline_void();
        } 
      if ((Optimize.OPT->profile_ask == CTRUE) && 
          (_Z_any1(Optimize.OPT->in_method,Kernel._object) == CTRUE))
       { if (v45806 != CTRUE)
         new_block_void();
        princ_string(CSTRING("PRloop(PR_x);"));
        breakline_void();
        } 
      { OID  v48333;
        if (Kernel._string == OWNER(v106843))
         v48333 = v106843;
        else v48333 = CNULL;
          statement_any(GC_OID(v107876->arg),_oid_(Kernel.emptySet),v48333);
        } 
      if (v45806 == CTRUE)
       { princ_string(CSTRING("GC_UNLOOP;"));
        close_block_void();
        } 
      if ((Optimize.OPT->profile_ask == CTRUE) && 
          ((_Z_any1(Optimize.OPT->in_method,Kernel._object) == CTRUE) && 
            (v45806 != CTRUE)))
       close_block_void();
      close_block_void();
      } 
    } 
  GC_UNBIND;} 

void  stat_iteration_c_producer(Generate_c_producer *v106827,Iteration *v107876,OID v106843,OID v40124)
{ GC_BIND;
  if (boolean_I_any(v106843) != CTRUE)
   close_exception(((general_error *) (*Core._general_error)(_string_(CSTRING("[203] you should have used a FOR here:~S")),
    _oid_(list::alloc(1,_oid_(v107876))))));
  { char * v106846 = GC_STRING(c_string_c_producer1(v106827,GC_OBJECT(Variable,v107876->var)));
    char * v52307 = GC_STRING(check_var_string(CSTRING("v_val"),v106843,v40124));
    char * v20591 = GC_STRING(check_var_string(CSTRING("v_list"),v106843,v40124));
    new_block_void();
    princ_string(CSTRING("bag *"));
    princ_string(v20591);
    princ_string(CSTRING("; OID "));
    princ_string(v52307);
    princ_string(CSTRING(";"));
    breakline_void();
    princ_string(CSTRING(""));
    princ_string(CSTRING("OID "));
    c_princ_string(v106846);
    princ_string(CSTRING(",CLcount;"));
    breakline_void();
    princ_string(CSTRING(""));
    statement_any(GC_OID(v107876->set_arg),_string_(v20591),v40124);
    princ_string(CSTRING(" "));
    (*Kernel.c_princ)(v106843);
    princ_string(CSTRING(" = "));
    princ_string(v20591);
    princ_string(CSTRING("->clone("));
    if (get_property(Kernel.of,v107876) != CNULL)
     (*Generate.expression)(GC_OID((*Optimize.c_code)(GC_OID((*Kernel.of)(_oid_(v107876))),
        _oid_(Kernel._type))),
      Core.nil->value);
    princ_string(CSTRING(")"));
    princ_string(CSTRING(";"));
    breakline_void();
    princ_string(CSTRING("for (CLcount= 1; CLcount <= "));
    princ_string(v20591);
    princ_string(CSTRING("->length; CLcount++)"));
    breakline_void();
    new_block_void();
    c_princ_string(v106846);
    princ_string(CSTRING(" = (*("));
    princ_string(v20591);
    princ_string(CSTRING("))[CLcount];"));
    breakline_void();
    statement_any(GC_OID(v107876->arg),_string_(v52307),Kernel.ctrue);
    breakline_void();
    princ_string(CSTRING("(*((list *) "));
    (*Kernel.princ)(v106843);
    princ_string(CSTRING("))[CLcount] = "));
    princ_string(v52307);
    princ_string(CSTRING(";"));
    close_block_void();
    close_block_void();
    } 
  GC_UNBIND;} 

void  stat_super_c_producer(Generate_c_producer *v106827,Super *v107876,OID v106843,OID v40124)
{ GC_BIND;
  { char * v49016 = GC_STRING(check_var_string(CSTRING("v_rec"),v106843,v40124));
    new_block_void();
    princ_string(CSTRING("OID "));
    princ_string(v49016);
    princ_string(CSTRING(";"));
    breakline_void();
    { OID gc_local;
      ITERATE(v106848);
      bag *v106848_support;
      v106848_support = GC_OBJECT(list,v107876->args);
      for (START(v106848_support); NEXT(v106848);)
      { statement_any(v106848,_string_(v49016),v40124);
        princ_string(CSTRING("PUSH("));
        princ_string(v49016);
        princ_string(CSTRING(");"));
        breakline_void();
        } 
      } 
    if (Kernel._string == OWNER(v106843))
     { c_princ_string(string_v(v106843));
      princ_string(CSTRING("="));
      } 
    expression_thing(v107876->selector,v40124);
    princ_string(CSTRING("->super("));
    (*Generate.expression)(GC_OID(_oid_(v107876->cast_to)),
      v40124);
    princ_string(CSTRING(","));
    princ_integer(v107876->args->length);
    princ_string(CSTRING(");"));
    close_block_void();
    } 
  GC_UNBIND;} 

void  stat_let_c_producer(Generate_c_producer *v106827,Let *v107876,OID v106843,OID v40124)
{ GC_RESERVE(8);  // v3.0.55 optim !
  { char * v35293 = GC_STRING(string_v((*Generate.c_string)(Generate.PRODUCER->value,
      _oid_(v107876->var->pname))));
    if ((v35293[1 - 1] == 'C') && 
        (v35293[2 - 1] == '%'))
     (v107876->var->pname = gensym_void());
    } 
  { OID  v106846 = GC_OID((*Generate.c_string)(Generate.PRODUCER->value,
      GC_OID(_oid_(v107876->var))));
    ClaireBoolean * v106826 = Optimize.OPT->alloc_stack;
    OID  v106848 = GC_OID(v107876->value);
    ClaireBoolean * v106830 = CTRUE;
    new_block_void();
    (Optimize.OPT->alloc_stack = CFALSE);
    { OID gc_local;
      while ((v106830 == CTRUE))
      { GC_LOOP;
        if (INHERIT(v107876->isa,Language._Let_star))
         (Optimize.OPT->alloc_stack = CTRUE);
        interface_I_class(sort_Variable(v107876->var));
        princ_string(CSTRING(" "));
        c_princ_string(string_v(v106846));
        princ_string(CSTRING(""));
        if (c_func_any(v106848) == CTRUE)
         { princ_string(CSTRING(" = "));
          if (bool_exp_ask_any(v106848) == CTRUE)
           (*Generate.bool_exp_I)(Generate.PRODUCER->value,
            v106848,
            v40124);
          else (*Generate.expression)(v106848,
              v40124);
            princ_string(CSTRING(";"));
          breakline_void();
          princ_string(CSTRING(""));
          } 
        else { (*Generate.init_var)(Generate.PRODUCER->value,
              _oid_(sort_Variable(v107876->var)));
            princ_string(CSTRING(";"));
            breakline_void();
            statement_any(v106848,v106846,v40124);
            princ_string(CSTRING(""));
            } 
          if (INHERIT(v107876->isa,Language._Let_star))
         (Optimize.OPT->alloc_stack = CFALSE);
        if (INHERIT(OWNER(v107876->arg),Language._Let))
         { GC__ANY(v107876 = OBJECT(Let,v107876->arg), 2);
          GC__OID(v106846 = (*Generate.c_string)(Generate.PRODUCER->value,
            GC_OID(_oid_(v107876->var))), 5);
          GC__OID(v106848 = v107876->value, 7);
          } 
        else v106830= CFALSE;
          GC_UNLOOP;} 
      } 
    (Optimize.OPT->alloc_stack = v106826);
    inner_statement_any(GC_OID(v107876->arg),v106843,v40124);
    princ_string(CSTRING(""));
    close_block_void();
    } 
  GC_UNBIND;} 

