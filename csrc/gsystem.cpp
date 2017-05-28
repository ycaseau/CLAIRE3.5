/***** CLAIRE Compilation of file e:\claire\v3.5\src\compile\gsystem.cl 
         [version 3.5.0 / safety 5] Sun May 28 08:26:01 2017 *****/

#include <claire.h>
#include <Kernel.h>
#include <Core.h>
#include <Language.h>
#include <Reader.h>
#include <Optimize.h>
#include <Generate.h>
void  ident_symbol(symbol *v13492)
{ (*Language.ident)(Generate.PRODUCER->value,
    _oid_(v13492));
  } 

void  ident_thing(thing *v13492)
{ (*Language.ident)(Generate.PRODUCER->value,
    _oid_(v13492->name));
  } 

void  ident_class(ClaireClass *v13492)
{ (*Language.ident)(Generate.PRODUCER->value,
    _oid_(v13492->name));
  } 

void  interface_I_class(ClaireClass *v5115)
{ (*Generate.interface_I)(Generate.PRODUCER->value,
    _oid_(v5115));
  } 

void  class_princ_class(ClaireClass *v5115)
{ (*Generate.class_princ)(Generate.PRODUCER->value,
    _oid_(v5115));
  } 

OID  indent_c_void()
{ { OID Result = 0;
    { Cint  v5136 = Optimize.OPT->level;
      { Result= _oid_(CFALSE);
        while ((v5136 > 0))
        { princ_string(CSTRING("  "));
          v5136= (v5136-1);
          } 
        } 
      } 
    return (Result);} 
  } 

OID  breakline_void()
{ princ_string(CSTRING("\n"));
  return (indent_c_void());} 

void  new_block_void()
{ (Optimize.OPT->level = (Optimize.OPT->level+1));
  princ_string(CSTRING("{ "));
  } 

void  close_block_void()
{ (Optimize.OPT->level = (Optimize.OPT->level-1));
  princ_string(CSTRING("} "));
  breakline_void();
  } 

void  c_test_any(OID v5136)
{ GC_BIND;
  { OID  v5133 = GC_OID((*Optimize.c_type)(v5136));
    ClaireClass * v5134 = osort_any(v5133);
    OID  v5135 = GC_OID((*Optimize.c_code)(v5136,
      _oid_(v5134)));
    ClaireBoolean * v5118 = c_func_any(v5135);
    princ_string(CSTRING("type -> "));
    print_any(v5133);
    princ_string(CSTRING(" [sort "));
    print_any(_oid_(v5134));
    princ_string(CSTRING("]\n"));
    princ_string(CSTRING("opt["));
    print_any(_oid_(OWNER(v5135)));
    princ_string(CSTRING("] -> "));
    print_any(v5135);
    princ_string(CSTRING(" \n"));
    if (v5118 == CTRUE)
     { princ_string(CSTRING("exp  -> "));
      (*Generate.expression)(v5135,
        Core.nil->value);
      princ_string(CSTRING("\n"));
      } 
    else { princ_string(CSTRING("stat -> "));
        statement_any(v5135,_string_(CSTRING("result")),Core.nil->value);
        princ_string(CSTRING("\n"));
        } 
      } 
  GC_UNBIND;} 

void  c_test_method(method *v5125)
{ GC_BIND;
  { lambda * v5124 = GC_OBJECT(lambda,v5125->formula);
    if (v5124 == (NULL))
     ;else { tformat_string(CSTRING("---- Compiling ~S ---- \n"),0,list::alloc(1,_oid_(v5125)));
        (Optimize.OPT->in_method = _oid_(v5125));
        (Optimize.OPT->protection = CFALSE);
        (Optimize.OPT->allocation = CFALSE);
        if (Optimize.OPT->loop_index > 0)
         (Optimize.OPT->loop_index = 0);
        (Optimize.OPT->loop_gc = CFALSE);
        (Optimize.OPT->use_update = CFALSE);
        (Optimize.OPT->use_nth_equal = CFALSE);
        (Optimize.OPT->use_string_update = CFALSE);
        (Optimize.OPT->max_vars = 0);
        (Optimize.OPT->online_ask = CFALSE);
        (Optimize.OPT->legal_modules = ((set *) Kernel._module->instances));
        (OBJECT(Generate_producer,Generate.PRODUCER->value)->body = v5124->body);
        { ClaireClass * v5134 = Kernel._void;
          OID  v9951;
          { { v5134= check_sort_method(v5125);
              v9951 = OBJECT(Generate_producer,Generate.PRODUCER->value)->body;
              } 
            GC_OID(v9951);} 
          char * v16382 = GC_STRING(string_v((*Generate.protect_result)(Generate.PRODUCER->value,
            _oid_(v5134),
            _oid_(Optimize.OPT->protection),
            _oid_(v5125))));
          princ_string(CSTRING("Opt => "));
          print_any(v9951);
          princ_string(CSTRING(" \n\n"));
          new_block_void();
          (*Generate.print_body)(v9951,
            _string_(v16382),
            _oid_(v5134),
            GC_OID(v5124->body),
            Kernel.ctrue);
          } 
        (Optimize.OPT->in_method = CNULL);
        } 
      } 
  GC_UNBIND;} 

void  compile_module(module *v13492)
{ GC_BIND;
  (Optimize.OPT->need_modules = Kernel.emptySet);
  { bag * v11437 = GC_OBJECT(list,parents_list(GC_OBJECT(list,add_modules_list(list::alloc(1,_oid_(v13492))))));
    update_property(Optimize.legal_modules,
      Optimize.OPT,
      9,
      Kernel._object,
      GC_OID((*Kernel.set_I)(_oid_(v11437))));
    if (Optimize.compiler->class2file_ask == CTRUE)
     { tformat_string(CSTRING("**** Compiling the module ~A [v. 3.~A - verbose:~A opt:~S] \n"),2,list::alloc(4,GC_OID(_string_(string_I_symbol(v13492->name))),
        GC_OID(Optimize.compiler->version),
        ClEnv->verbose,
        _oid_(Optimize.compiler->optimize_ask)));
      write_property(Generate.outmodule,Optimize.OPT,GC_OID(ClAlloc->import(Kernel._port,(int *) fopen_string(append_string(GC_STRING(append_string(GC_STRING(append_string(GC_STRING(Optimize.compiler->source),GC_STRING(string_v(Reader._starfs_star->value)))),GC_STRING(string_v((*Generate.c_string)(Generate.PRODUCER->value,
        _oid_(v13492->name)))))),GC_STRING(OBJECT(Generate_producer,Generate.PRODUCER->value)->extension)),CSTRING("w")))));
      generate_files_module(v13492);
      begin_module(v13492);
      generate_classes_module(v13492);
      generate_c2f_module(v13492);
      end_module(v13492);
      } 
    else { generate_files_module(v13492);
        generate_f2f_module(v13492);
        generate_interface_module(v13492,GC_OBJECT(set,Optimize.OPT->legal_modules));
        } 
      v11437= GC_OBJECT(set,difference_set(GC_OBJECT(set,set_I_set(Optimize.OPT->need_modules)),GC_OBJECT(set,Optimize.OPT->legal_modules)));
    if (v11437->length != 0)
     tformat_string(CSTRING("---- WARNING: ~S should be declared for ~S\n"),2,list::alloc(2,_oid_(v11437),_oid_(v13492)));
    } 
  GC_UNBIND;} 

void  generate_files_module(module *v13492)
{ GC_BIND;
  tformat_string(CSTRING("==== Generate ~A files for module ~S [verbose = ~A, Opt? = ~S] \n"),0,list::alloc(4,GC_OID(_string_(OBJECT(Generate_producer,Generate.PRODUCER->value)->comment)),
    _oid_(v13492),
    ClEnv->verbose,
    _oid_(Optimize.compiler->optimize_ask)));
  (Optimize.OPT->instructions = list::empty(Kernel._any));
  (Optimize.OPT->properties = set::empty(Kernel._property));
  (Optimize.OPT->objects = list::empty(Kernel._object));
  (Optimize.OPT->functions = list::empty(Kernel._any));
  (Optimize.OPT->need_to_close = set::empty(Kernel._any));
  (*Generate.start_module_interface)(Generate.PRODUCER->value,
    _oid_(v13492));
  begin_module(v13492);
  { OID gc_local;
    ITERATE(v5136);
    bag *v5136_support;
    v5136_support = GC_OBJECT(list,v13492->made_of);
    for (START(v5136_support); NEXT(v5136);)
    { GC_LOOP;
      { tformat_string(CSTRING("++++ Compiling the file ~A.cl [v. 3.~A - safety:~A] \n"),2,list::alloc(3,v5136,
          GC_OID(Optimize.compiler->version),
          Optimize.compiler->safety));
        if (equal(v5136,_string_(string_I_symbol(v13492->name))) == CTRUE)
         (*Optimize.Cerror)(_string_(CSTRING("[211]  ~S cannot be used both as a file and module name")),
          v5136);
        generate_file_string2(GC_STRING(append_string(GC_STRING(append_string(GC_STRING(v13492->source),GC_STRING(string_v(Reader._starfs_star->value)))),string_v(v5136))),GC_STRING(append_string(GC_STRING(append_string(GC_STRING(Optimize.compiler->source),GC_STRING(string_v(Reader._starfs_star->value)))),string_v(v5136))));
        if (CFALSE == CTRUE)
         claire_gc();
        } 
      GC_UNLOOP;} 
    } 
  end_module(v13492);
  GC_UNBIND;} 

void  generate_f2f_module(module *v5125)
{ GC_BIND;
  { ClairePort * v5128 = (fopen_string(append_string(GC_STRING(append_string(GC_STRING(append_string(GC_STRING(Optimize.compiler->source),GC_STRING(string_v(Reader._starfs_star->value)))),GC_STRING(string_I_symbol(v5125->name)))),GC_STRING(OBJECT(Generate_producer,Generate.PRODUCER->value)->extension)),CSTRING("w")));
    tformat_string(CSTRING("==== generate file for module ~S [~A GC protections inserted] ==== \n"),0,list::alloc(2,_oid_(v5125),OBJECT(Generate_producer,Generate.PRODUCER->value)->stat));
    (Optimize.OPT->outfile = v5128);
    generate_file_string1(GC_STRING(string_I_symbol(v5125->name)),v5125);
    } 
  GC_UNBIND;} 

void  generate_file_string1(char *v5134,module *v5125)
{ GC_BIND;
  start_file_string(v5134,v5125);
  use_as_output_port(Optimize.OPT->outfile);
  (*Generate.generate_classes)(Generate.PRODUCER->value,
    _string_(v5134),
    _oid_(v5125));
  { OID gc_local;
    ITERATE(v5115);
    bag *v5115_support;
    v5115_support = GC_OBJECT(list,Optimize.OPT->objects);
    for (START(v5115_support); NEXT(v5115);)
    if (INHERIT(OWNER(v5115),Kernel._class))
     (*Generate.methods_bodies)(Generate.PRODUCER->value,
      v5115);
    } 
  generate_meta_load_module(v5125);
  breakline_void();
  princ_string(CSTRING("GC_UNBIND;"));
  close_block_void();
  breakline_void();
  fclose_port(Optimize.OPT->outfile);
  GC_UNBIND;} 

void  generate_classes_module(module *v13492)
{ GC_BIND;
  erase_table(Generate.classFile);
  { OID gc_local;
    ITERATE(v5115);
    bag *v5115_support;
    v5115_support = GC_OBJECT(list,Optimize.OPT->objects);
    for (START(v5115_support); NEXT(v5115);)
    { GC_LOOP;
      if (INHERIT(OWNER(v5115),Kernel._class))
       { put_table(Generate.classFile,v5115,ClAlloc->import(Kernel._port,(int *) fopen_string(append_string(GC_STRING(append_string(GC_STRING(append_string(GC_STRING(Optimize.compiler->source),GC_STRING(string_v(Reader._starfs_star->value)))),GC_STRING(string_v((*Generate.c_string)(Generate.PRODUCER->value,
          GC_OID((*Kernel.name)(v5115))))))),GC_STRING(OBJECT(Generate_producer,Generate.PRODUCER->value)->extension)),CSTRING("w"))));
        use_as_output_port(EXPORT((ClairePort *),nth_table1(Generate.classFile,v5115)));
        tformat_string(CSTRING("++++ Creating the file ~A.java\n"),2,GC_OBJECT(list,list::alloc(1,GC_OID((*Generate.c_string)(Generate.PRODUCER->value,
          GC_OID((*Kernel.name)(v5115)))))));
        (Optimize.OPT->level = 0);
        princ_string(CSTRING("// class file for "));
        print_any(v5115);
        princ_string(CSTRING(" in module "));
        print_any(_oid_(v13492));
        princ_string(CSTRING(" "));
        breakline_void();
        breakline_void();
        breakline_void();
        princ_string(CSTRING("public class "));
        ident_symbol(OBJECT(symbol,(*Kernel.name)(v5115)));
        princ_string(CSTRING(" extends "));
        ident_symbol(OBJECT(ClaireClass,v5115)->superclass->name);
        new_block_void();
        breakline_void();
        breakline_void();
        princ_string(CSTRING("/* empty constructor by default */"));
        breakline_void();
        princ_string(CSTRING("public "));
        ident_symbol(OBJECT(symbol,(*Kernel.name)(v5115)));
        princ_string(CSTRING("() {}"));
        breakline_void();
        breakline_void();
        breakline_void();
        princ_string(CSTRING("/* declaration of fields */"));
        { OID gc_local;
          ITERATE(v5137);
          bag *v5137_support;
          v5137_support = GC_OBJECT(list,OBJECT(bag,(*Optimize.get_indexed)(v5115)));
          for (START(v5137_support); NEXT(v5137);)
          if (_oid_(domain_I_restriction(OBJECT(restriction,v5137))) == v5115)
           { breakline_void();
            princ_string(CSTRING("public  "));
            interface_I_class(psort_any(_oid_(OBJECT(restriction,v5137)->range)));
            princ_string(CSTRING(" "));
            ident_symbol(OBJECT(restriction,v5137)->selector->name);
            princ_string(CSTRING(";"));
            } 
          } 
        breakline_void();
        princ_string(CSTRING(""));
        fclose_port(EXPORT((ClairePort *),nth_table1(Generate.classFile,v5115)));
        } 
      GC_UNLOOP;} 
    } 
  GC_UNBIND;} 

void  generate_c2f_module(module *v13492)
{ GC_BIND;
  { ClairePort * v5237 = (fopen_string(append_string(GC_STRING(append_string(GC_STRING(append_string(GC_STRING(Optimize.compiler->source),GC_STRING(string_v(Reader._starfs_star->value)))),GC_STRING(string_v((*Generate.c_string)(Generate.PRODUCER->value,
      _oid_(v13492->name)))))),GC_STRING(OBJECT(Generate_producer,Generate.PRODUCER->value)->extension)),CSTRING("w")));
    (Optimize.OPT->outfile = v5237);
    use_as_output_port(v5237);
    (*Generate.generate_start_file)(Generate.PRODUCER->value,
      _oid_(v13492));
    fclose_port(v5237);
    claire_gc();
    generate_functions_module(v13492);
    claire_gc();
    v5237= (fopen_string(append_string(GC_STRING(append_string(GC_STRING(append_string(GC_STRING(Optimize.compiler->source),GC_STRING(string_v(Reader._starfs_star->value)))),GC_STRING(string_v((*Generate.c_string)(Generate.PRODUCER->value,
      _oid_(v13492->name)))))),GC_STRING(OBJECT(Generate_producer,Generate.PRODUCER->value)->extension)),CSTRING("a")));
    use_as_output_port(v5237);
    (Optimize.OPT->outfile = v5237);
    (Optimize.OPT->level = 2);
    generate_objects_module(v13492);
    use_as_output_port(EXPORT((ClairePort *),Reader.STDOUT->value));
    claire_gc();
    use_as_output_port(v5237);
    generate_meta_load_module(v13492);
    (*Generate.generate_end_file)(Generate.PRODUCER->value,
      _oid_(v13492));
    } 
  GC_UNBIND;} 

void  generate_interface_module(module *v13492,bag *v5124)
{ tformat_string(CSTRING("==== Generate inteface (.h) files for module ~S \n"),0,list::alloc(1,_oid_(v13492)));
  use_as_output_port(Optimize.OPT->cinterface);
  breakline_void();
  (*Generate.generate_interface)(Generate.PRODUCER->value,
    _oid_(v13492));
  (*Generate.namespace_I)(Generate.PRODUCER->value,
    _oid_(v13492));
  generate_objects_module(v13492);
  (*Kernel.module_I)(Generate.PRODUCER->value,
    _oid_(v13492));
  (*Generate.end_module_interface)(Generate.PRODUCER->value,
    _oid_(v13492));
  fclose_port(Optimize.OPT->cinterface);
  use_as_output_port(EXPORT((ClairePort *),Reader.STDOUT->value));
  } 

void  generate_objects_module(module *v13492)
{ GC_RESERVE(1);  // HOHO v3.0.55 optim !
  { OID gc_local;
    ITERATE(v5136);
    bag *v5136_support;
    v5136_support = GC_OBJECT(list,Optimize.OPT->objects);
    for (START(v5136_support); NEXT(v5136);)
    { breakline_void();
      (*Generate.public_static)(Generate.PRODUCER->value);
      if (INHERIT(OWNER(v5136),Core._global_variable))
       { { OID  v12195;
          if (nativeVar_ask_global_variable(OBJECT(global_variable,v5136)) == CTRUE)
           v12195 = _oid_(getRange_global_variable(OBJECT(global_variable,v5136)));
          else v12195 = _oid_(Core._global_variable);
            (*Generate.interface_I)(Generate.PRODUCER->value,
            v12195);
          } 
        princ_string(CSTRING(" "));
        ident_symbol(OBJECT(thing,v5136)->name);
        princ_string(CSTRING(";"));
        } 
      else { (*Generate.interface_I)(Generate.PRODUCER->value,
            _oid_(psort_any(_oid_(OWNER(v5136)))));
          princ_string(CSTRING(" "));
          if (INHERIT(OWNER(v5136),Kernel._class))
           { princ_string(CSTRING("_"));
            c_princ_string(string_I_symbol(OBJECT(symbol,(*Kernel.name)(v5136))));
            } 
          else if (INHERIT(OWNER(v5136),Reader._reserved_keyword))
           { princ_string(CSTRING("_cl_"));
            c_princ_string(string_I_symbol(OBJECT(symbol,(*Kernel.name)(v5136))));
            } 
          else ident_symbol(OBJECT(symbol,(*Kernel.name)(v5136)));
            princ_string(CSTRING(";"));
          } 
        } 
    } 
  { OID gc_local;
    ITERATE(v5136);
    bag *v5136_support;
    v5136_support = GC_OBJECT(set,Optimize.OPT->properties);
    for (START(v5136_support); NEXT(v5136);)
    { GC_LOOP;
      if (Optimize.OPT->objects->memq(v5136) != CTRUE)
       { { OID  v3260;
          { { OID  v10985 = CNULL;
              { OID gc_local;
                ITERATE(v11562);
                bag *v11562_support;
                v11562_support = GC_OBJECT(set,Optimize.OPT->properties);
                for (START(v11562_support); NEXT(v11562);)
                { GC_LOOP;
                  if (v11562 != v5136)
                   { if (equal_string(string_I_symbol(OBJECT(thing,v11562)->name),string_I_symbol(OBJECT(thing,v5136)->name)) == CTRUE)
                     { v10985= v11562;
                      break;} 
                    } 
                  GC_UNLOOP;} 
                } 
              v3260 = v10985;
              } 
            GC_OID(v3260);} 
          if (v3260 != CNULL)
           { property * v11562 = OBJECT(property,v3260);
            close_exception(((general_error *) (*Core._general_error)(_string_(CSTRING("[217] ~S and ~S cannot be defined in the same module")),
              _oid_(list::alloc(2,_oid_(v11562),v5136)))));
            } 
          else ;} 
        princ_string(CSTRING("\n"));
        (*Generate.public_static)(Generate.PRODUCER->value);
        (*Generate.interface_I)(Generate.PRODUCER->value,
          _oid_(psort_any(_oid_(OWNER(v5136)))));
        princ_string(CSTRING(" "));
        ident_symbol(OBJECT(thing,v5136)->name);
        princ_string(CSTRING(";// "));
        print_any(_oid_(OBJECT(thing,v5136)->name));
        princ_string(CSTRING(""));
        } 
      GC_UNLOOP;} 
    } 
  GC_UNBIND;} 

void  generate_meta_load_module(module *v13492)
{ GC_RESERVE(1);  // HOHO v3.0.55 optim !
  princ_string(CSTRING("// definition of the meta-model for "));
  print_any(_oid_(v13492));
  princ_string(CSTRING(" \n"));
  breakline_void();
  princ_string(CSTRING(""));
  (*Generate.generate_meta_load)(Generate.PRODUCER->value,
    _oid_(v13492));
  princ_string(CSTRING("// definition of the properties "));
  { OID gc_local;
    ITERATE(v5136);
    bag *v5136_support;
    v5136_support = GC_OBJECT(set,Optimize.OPT->properties);
    for (START(v5136_support); NEXT(v5136);)
    if (Optimize.OPT->objects->memq(v5136) != CTRUE)
     (*Generate.declare)(Generate.PRODUCER->value,
      v5136);
    } 
  breakline_void();
  breakline_void();
  princ_string(CSTRING("// instructions from module sources"));
  { OID  v5122 = CNULL;
    { OID gc_local;
      ITERATE(v5121);
      bag *v5121_support;
      v5121_support = GC_OBJECT(list,Optimize.OPT->instructions);
      for (START(v5121_support); NEXT(v5121);)
      { GC_LOOP;
        { breakline_void();
          if (Kernel._string == OWNER(v5121))
           { if (equal(_oid_(Kernel._string),_oid_(OWNER(v5122))) != CTRUE)
             breakline_void();
            princ_string(CSTRING("// "));
            (*Kernel.princ)(v5121);
            princ_string(CSTRING(""));
            } 
          else if (global_var_def_ask_any(v5121) == CTRUE)
           (*Generate.global_var_def_I)(Generate.PRODUCER->value,
            _oid_(v13492),
            v5121);
          else statement_any(v5121,_oid_(Kernel.emptySet),_oid_(Kernel.emptySet));
            GC__OID(v5122 = v5121, 1);
          } 
        GC_UNLOOP;} 
      } 
    } 
  GC_UNBIND;} 

ClaireBoolean * global_var_def_ask_any(OID v5136)
{ GC_BIND;
  { ClaireBoolean *Result ;
    Result = ((INHERIT(OWNER(v5136),Language._Let)) ?
      ((INHERIT(OWNER(OBJECT(Let,v5136)->value),Language._Call)) ? (((*Kernel.selector)(OBJECT(Let,v5136)->value) == _oid_(Optimize.object_I)) ? (((*(OBJECT(bag,(*Core.args)(OBJECT(Let,v5136)->value))))[2] == _oid_(Core._global_variable)) ? CTRUE: CFALSE): CFALSE): CFALSE) :
      CFALSE );
    GC_UNBIND; return (Result);} 
  } 

ClaireClass * getRange_global_variable(global_variable *v5136)
{ { ClaireClass *Result ;
    Result = ((equal(_oid_(v5136->range),_oid_(Kernel.emptySet)) == CTRUE) ?
      OWNER(v5136->value) :
      class_I_type(v5136->range) );
    return (Result);} 
  } 

void  generate_functions_module(module *v13492)
{ GC_BIND;
  princ_string(CSTRING("// definition of class methods "));
  { ClairePort * v5128 = (Optimize.OPT->outfile);
    { OID gc_local;
      ITERATE(v5118);
      bag *v5118_support;
      v5118_support = GC_OBJECT(list,Optimize.OPT->functions);
      for (START(v5118_support); NEXT(v5118);)
      { GC_LOOP;
        { (Optimize.OPT->level = 2);
          (Optimize.OPT->outfile = v5128);
          print_c_function_lambda2(GC_OBJECT(lambda,OBJECT(lambda,(*Kernel.nth)(v5118,
            1))),GC_STRING(string_v((*Kernel.nth)(v5118,
            2))),GC_OID((*Kernel.nth)(v5118,
            3)));
          } 
        GC_UNLOOP;} 
      } 
    } 
  GC_UNBIND;} 

list * parents_module(module *v13492,list *v5124)
{ if (v5124->memq(_oid_(v13492)) == CTRUE) 
  { { list *Result ;
      Result = v5124;
      return (Result);} 
     } 
  else{ GC_BIND;
    if (((v13492->part_of == (NULL)) ? CTRUE : CFALSE) != CTRUE)
     v5124= GC_OBJECT(list,parents_module(v13492->part_of,v5124));
    v5124= GC_OBJECT(list,v5124->addFast(_oid_(v13492)));
    { list *Result ;
      Result = v5124;
      GC_UNBIND; return (Result);} 
    } 
  } 

list * parents_list(list *v13492)
{ GC_RESERVE(1);  // HOHO v3.0.55 optim !
  { list *Result ;
    { list * v5124 = list::empty(Kernel._module);
      { OID gc_local;
        ITERATE(v5136);
        for (START(v13492); NEXT(v5136);)
        { GC_LOOP;
          GC__ANY(v5124 = parents_module(OBJECT(module,v5136),v5124), 1);
          GC_UNLOOP;} 
        } 
      Result = v5124;
      } 
    GC_UNBIND; return (Result);} 
  } 

void  get_module2(module *v5125)
{ load_module(v5125);
  begin_module(v5125);
  } 

void  generate_file_string2(char *v13492,char *v11252)
{ GC_RESERVE(7);  // v3.0.55 optim !
  { ClairePort * v11563 = (fopen_string(append_string(v13492,CSTRING(".cl")),CSTRING("r")));
    ClaireBoolean * v5114 = Reader.reader->toplevel;
    ClairePort * v11560 = (Reader.reader->fromp);
    if (Optimize.compiler->class2file_ask != CTRUE)
     (Optimize.OPT->outfile = fopen_string(append_string(v11252,GC_STRING(OBJECT(Generate_producer,Generate.PRODUCER->value)->extension)),CSTRING("w")));
    (Reader.reader->toplevel = CFALSE);
    (Optimize.compiler->loading_ask = CTRUE);
    (Reader.reader->nb_line = 1);
    (Reader.reader->external = v13492);
    (Reader.reader->fromp = v11563);
    if (Optimize.compiler->class2file_ask != CTRUE)
     start_file_string(v13492,ClEnv->module_I);
    { OID  v4273 = GC_OID(readblock_port(v11563));
      { OID gc_local;
        while ((equal(v4273,_oid_(Reader.eof)) != CTRUE))
        { GC_LOOP;
          if (ClEnv->verbose > 5)
           { princ_string(CSTRING("["));
            princ_integer(Reader.reader->nb_line);
            princ_string(CSTRING("] "));
            print_any(_oid_(OWNER(v4273)));
            princ_string(CSTRING(" ("));
            print_any(GC_OID(_oid_(Optimize.OPT->need_modules)));
            princ_string(CSTRING("%)\n"));
            } 
          if ((Kernel._string == OWNER(v4273)) && 
              (Optimize.compiler->class2file_ask != CTRUE))
           { if (Optimize.compiler->naming < 2)
             { ClairePort * v11625 = (use_as_output_port(Optimize.OPT->outfile));
              princ_string(CSTRING("\n//"));
              (*Kernel.princ)(v4273);
              princ_string(CSTRING(""));
              use_as_output_port(v11625);
              } 
            } 
          else GC_OBJECT(list,Optimize.OPT->instructions)->addFast(GC_OID((*Optimize.c_code)(v4273,
              _oid_(Kernel._void))));
            GC__OID(v4273 = readblock_port(v11563), 6);
          GC_UNLOOP;} 
        } 
      } 
    fclose_port(v11563);
    (Optimize.compiler->loading_ask = CFALSE);
    (Reader.reader->toplevel = v5114);
    (Reader.reader->external = CSTRING("toplevel"));
    (Reader.reader->fromp = v11560);
    if (Optimize.compiler->class2file_ask != CTRUE)
     fclose_port(Optimize.OPT->outfile);
    } 
  GC_UNBIND;} 

OID  make_c_function_lambda_Generate(lambda *v13492,char *v8687,OID v5125)
{ { OID Result = 0;
    if (Optimize.compiler->class2file_ask == CTRUE)
     Result = (*Generate.create_function_entry)(Generate.PRODUCER->value,
      _oid_(v13492),
      _string_(v8687),
      v5125);
    else Result = print_c_function_lambda2(v13492,v8687,v5125);
      return (Result);} 
  } 

OID  print_c_function_lambda2(lambda *v13492,char *v8687,OID v5125)
{ GC_BIND;
  (OBJECT(Generate_producer,Generate.PRODUCER->value)->body = v13492->body);
  { OID Result = 0;
    { ClaireClass * v5134 = Kernel._void;
      OID  v9951;
      { if (boolean_I_any(v5125) != CTRUE)
         v9951 = (*Optimize.c_code)(GC_OID(v13492->body),
          _oid_(Kernel._void));
        else if (Kernel._method == OWNER(v5125))
         { v5134= check_sort_method(OBJECT(method,v5125));
          v9951 = OBJECT(Generate_producer,Generate.PRODUCER->value)->body;
          } 
        else if (INHERIT(OWNER(v5125),Kernel._class))
         { v5134= OBJECT(ClaireClass,v5125);
          v9951 = (*Optimize.c_code)(GC_OID(v13492->body),
            v5125);
          } 
        else { v5134= Kernel._any;
            v9951 = (*Optimize.c_code)(GC_OID(v13492->body),
              _oid_(Kernel._any));
            } 
          GC_OID(v9951);} 
      OID  v16382 = GC_OID((*Generate.protect_result)(Generate.PRODUCER->value,
        _oid_(v5134),
        _oid_(Optimize.OPT->protection),
        v5125));
      ClaireBoolean * v4278 = need_debug_ask_any(v5125);
      ClaireBoolean * v14156 = ((Optimize.OPT->profile_ask == CTRUE) ? (((Kernel._method == OWNER(v5125)) || 
          (v5125 == CNULL)) ? CTRUE: CFALSE): CFALSE);
      (*Generate.generate_function_start)(Generate.PRODUCER->value,
        _oid_(v13492),
        _oid_(v5134),
        v5125,
        _string_(v8687));
      if (Optimize.OPT->max_vars > 0)
       { (Language._starvariable_index_star->value= 0);
        lexical_num_any2(v9951,(v13492->vars->length+1));
        (Optimize.OPT->loop_index = Language._starvariable_index_star->value);
        } 
      new_block_void();
      if (v14156 == CTRUE)
       (*Generate.generate_profile)(Generate.PRODUCER->value,
        v5125);
      if (v4278 == CTRUE)
       (*Generate.debug_intro)(Generate.PRODUCER->value,
        _oid_(v13492),
        v5125);
      (*Generate.print_body)(v9951,
        v16382,
        _oid_(v5134),
        GC_OID(v13492->body),
        _oid_(not_any(_oid_(((Optimize.OPT->protection == CTRUE) ? CTRUE : ((v14156 == CTRUE) ? CTRUE : ((v4278 == CTRUE) ? CTRUE : ((Optimize.OPT->alloc_stack == CTRUE) ? CTRUE : CFALSE))))))));
      close_block_void();
      breakline_void();
      (Optimize.OPT->alloc_stack = CFALSE);
      Result = ClAlloc->import(Kernel._port,(int *) use_as_output_port(EXPORT((ClairePort *),Reader.STDOUT->value)));
      } 
    GC_UNBIND; return (Result);} 
  } 

void  print_body_If(If *v9951,char *v16382,ClaireClass *v5134,If *v4238,ClaireBoolean *v4415)
{ GC_BIND;
  if ((c_func_any(GC_OID(v9951->test)) == CTRUE) && 
      ((Optimize.OPT->protection == CTRUE) && 
        ((c_safe_any(GC_OID(v4238->arg)) == CTRUE) && 
          (Optimize.compiler->debug_ask->memq(_oid_(ClEnv->module_I)) != CTRUE))))
   { char * v16372 = ((v5134 != Kernel._void) ?
      CSTRING("return ") :
      CSTRING("") );
    princ_string(CSTRING("if "));
    (*Optimize.bool_exp)(GC_OID(v9951->test),
      Kernel.ctrue,
      Core.nil->value);
    princ_string(CSTRING(" "));
    breakline_void();
    new_block_void();
    outer_statement_any(GC_OID(v9951->arg),v16372,v5134,v4415);
    princ_string(CSTRING(" "));
    close_block_void();
    princ_string(CSTRING("else"));
    new_block_void();
    (*Generate.print_body)(GC_OID(v9951->other),
      _string_(v16382),
      _oid_(v5134),
      GC_OID(v4238->other),
      _oid_(v4415));
    close_block_void();
    } 
  else print_body_any(_oid_(v9951),
      v16382,
      v5134,
      _oid_(v4238),
      v4415);
    GC_UNBIND;} 

void  print_body_any(OID v9951,char *v16382,ClaireClass *v5134,OID v4238,ClaireBoolean *v4415)
{ (*Generate.gc_introduction)(Generate.PRODUCER->value,
    v9951);
  outer_statement_any(v9951,v16382,v5134,v4415);
  } 

OID  print_body_Do(Do *v9951,char *v16382,ClaireClass *v5134,OID v4238,ClaireBoolean *v4415)
{ GC_BIND;
  { OID Result = 0;
    { list * v5124 = GC_OBJECT(list,v9951->args);
      Cint  v3299 = v5124->length;
      Cint  v5125 = 0;
      (*Generate.gc_introduction)(Generate.PRODUCER->value,
        _oid_(v9951));
      { ITERATE(v5136);
        Result= Kernel.cfalse;
        for (START(v5124); NEXT(v5136);)
        { ++v5125;
          if (v5125 == v3299)
           outer_statement_any(v5136,v16382,v5134,v4415);
          else inner_statement_any(v5136,_oid_(Kernel.emptySet),_oid_(Kernel.emptySet));
            } 
        } 
      } 
    GC_UNBIND; return (Result);} 
  } 

void  outer_statement_any(OID v9951,char *v16382,ClaireClass *v5134,ClaireBoolean *v4415)
{ if ((c_func_any(v9951) == CTRUE) && 
      ((v4415 == CTRUE) && 
        ((v5134 != Kernel._void) && 
          (inherit_ask_class(OWNER(v9951),Language._If) != CTRUE))))
   { if (equal_string(v16382,CSTRING("")) != CTRUE)
     { princ_string(v16382);
      princ_string(CSTRING("("));
      (*Generate.expression)(v9951,
        Core.nil->value);
      princ_string(CSTRING(");"));
      } 
    else { (*Generate.expression)(v9951,
          Core.nil->value);
        princ_string(CSTRING(";"));
        } 
      } 
  else if (v5134 != Kernel._void)
   { new_block_void();
    (*Generate.define_variable)(Generate.PRODUCER->value,
      _oid_(v5134),
      _string_(CSTRING("Result")));
    breakline_void();
    statement_any(v9951,_string_(CSTRING("Result")),_oid_(Kernel.emptySet));
    if (equal_string(v16382,CSTRING("")) != CTRUE)
     { princ_string(v16382);
      princ_string(CSTRING("(Result);"));
      close_block_void();
      princ_string(CSTRING(""));
      } 
    } 
  else { statement_any(v9951,_oid_(Kernel.emptySet),_oid_(Kernel.emptySet));
      princ_string(v16382);
      } 
    } 

ClaireBoolean * c_safe_any(OID v5136)
{ return (not_any(_oid_(((Optimize.OPT->allocation == CTRUE) ? ((BCONTAIN(c_status_any(v5136,Kernel.nil),1)) ? CTRUE: CFALSE): CFALSE))));} 

ClaireClass * check_sort_method(method *v13492)
{ GC_BIND;
  { ClaireClass *Result ;
    { ClaireType * v11654 = v13492->range;
      OID  v5114 = GC_OID(OBJECT(Generate_producer,Generate.PRODUCER->value)->body);
      ClaireType * v11655 = GC_OBJECT(ClaireType,ptype_type(OBJECT(ClaireType,(*Optimize.c_type)(v5114))));
      ClaireClass * v5134 = psort_any(_oid_(v11654));
      (OBJECT(Generate_producer,Generate.PRODUCER->value)->body = c_strict_code_any(v5114,v5134));
      if (_inf_equal_type(v11655,v11654) != CTRUE)
       { tformat_string(CSTRING("---- note: ~S's range was found to be ~S (vs. ~S) \n"),2,list::alloc(3,_oid_(v13492),
          _oid_(v11655),
          _oid_(v11654)));
        if (Generate.WrongMethod->value == 0)
         { (Generate.WrongMethod->value= v5114);
          close_exception(((general_error *) (*Core._general_error)(_string_(CSTRING("You can look at WrongMethod")),
            _oid_(Kernel.nil))));
          } 
        if ((Optimize.compiler->safety < 2) || 
            ((Optimize.compiler->safety < 4) && 
                (boolean_I_any(sort_equal_class(osort_any(_oid_(v11655)),v5134)) != CTRUE)))
         (OBJECT(Generate_producer,Generate.PRODUCER->value)->body = c_strict_code_any(GC_OID(c_check_any(GC_OID((*Optimize.c_code)(v5114,
          _oid_(Kernel._any))),GC_OID((*Optimize.c_code)(_oid_(v11654),
          _oid_(Kernel._type))))),v5134));
        if (boolean_I_any(sort_equal_class(osort_any(_oid_(v11655)),v5134)) != CTRUE)
         { if ((v5134 != Kernel._void) && 
              ((_oid_((INHERIT(v11655->isa,Kernel._class) ? (ClaireObject *) sort_I_class((ClaireClass *) OBJECT(ClaireClass,_oid_(v11655))) :  (ClaireObject *)  sort_I_type((ClaireType *) OBJECT(ClaireType,_oid_(v11655))))) == _oid_(Kernel._void)) || 
                  (inherit_ask_class(v5134,OBJECT(ClaireClass,_oid_((INHERIT(v11655->isa,Kernel._class) ? (ClaireObject *) sort_I_class((ClaireClass *) OBJECT(ClaireClass,_oid_(v11655))) :  (ClaireObject *)  sort_I_type((ClaireType *) OBJECT(ClaireType,_oid_(v11655))))))) != CTRUE)))
           (*Optimize.Cerror)(_string_(CSTRING("[218] Sort error: Cannot compile ~S.")),
            _oid_(v13492));
          } 
        } 
      { ClaireType * v11656 = GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Kernel._exp)(_oid_(v11654),
          _oid_(v11655))));
        if ((Optimize.compiler->safety > 1) && 
            (osort_any(_oid_(v11656)) == v5134))
         { (OBJECT(Generate_producer,Generate.PRODUCER->value)->body = (*Optimize.c_strict_check)(GC_OID(OBJECT(Generate_producer,Generate.PRODUCER->value)->body),
            _oid_(class_I_type(v11656))));
          ;} 
        } 
      if (INHERIT(v11654->isa,Kernel._tuple))
       { (Optimize.OPT->alloc_stack = CTRUE);
        } 
      if ((Optimize.OPT->allocation == CTRUE) && 
          (nth_integer(status_I_restriction(v13492),6) != CTRUE))
       { if (nth_integer(status_I_restriction(v13492),1) != CTRUE)
         ;} 
      else { (Optimize.OPT->loop_gc = CFALSE);
          (Optimize.OPT->protection = CFALSE);
          } 
        Result = psort_any(_oid_(v13492->range));
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  typed_args_list_list(list *v13492)
{ { OID Result = 0;
    { ClaireBoolean * v11041 = CTRUE;
      { ITERATE(v5136);
        Result= Kernel.cfalse;
        for (START(v13492); NEXT(v5136);)
        { if (v11041 == CTRUE)
           v11041= CFALSE;
          else princ_string(CSTRING(","));
            (*Generate.interface_I)(Generate.PRODUCER->value,
            _oid_(sort_Variable(OBJECT(Variable,v5136))));
          (*Language.ident)(Generate.PRODUCER->value,
            v5136);
          } 
        } 
      } 
    return (Result);} 
  } 

ClaireBoolean * need_debug_ask_any(OID v5125)
{ { ClaireBoolean *Result ;
    if (Kernel._method == OWNER(v5125))
     { property * v5128 = OBJECT(restriction,v5125)->selector;
      Result = ((Optimize.compiler->debug_ask->memq(_oid_(OBJECT(restriction,v5125)->module_I)) == CTRUE) ? 
      ((domain_I_restriction(OBJECT(restriction,v5125)) != Kernel._environment) ? 
      ((OBJECT(restriction,v5125)->module_I != claire.it) ? 
      ((v5128 != Core.self_eval) ? 
      ((v5128 != Core.execute) ? 
      ((v5128 != Core.eval_message) ? 
      ((v5128 != Core.push_debug) ? 
      ((v5128 != Core.pop_debug) ? 
      ((v5128 != Core.tr_indent) ? 
      ((v5128 != Core.find_which) ? 
      ((v5128 != Core.matching_ask) ? 
      ((v5128 != Core.vmatch_ask) ? 
      CTRUE: CFALSE): CFALSE): CFALSE): CFALSE): CFALSE): CFALSE): CFALSE): CFALSE): CFALSE): CFALSE): CFALSE): CFALSE);
      } 
    else Result = CFALSE;
      return (Result);} 
  } 

void  get_dependents_method(method *v5125)
{ GC_BIND;
  { OID gc_local;
    ITERATE(v5128);
    bag *v5128_support;
    v5128_support = GC_OBJECT(set,dependents_method(v5125));
    for (START(v5128_support); NEXT(v5128);)
    { property * v2501 = v5125->selector;
      add_table(Reader.PRdependent,_oid_(v2501),v5128);
      } 
    } 
  GC_UNBIND;} 

void  c_princ_function(ClaireFunction *v13492)
{ c_princ_string(string_I_function(v13492));
  } 

void  set_outfile_lambda(lambda *v13492)
{ GC_BIND;
  { module * v5125 = ClEnv->module_I;
    char * v11217 = GC_STRING(string_I_symbol(v5125->name));
    ClairePort * v5128 = (Optimize.OPT->outfile);
    OID  v15461;
    { if (v13492->vars->length != 0)
       v15461 = (*Kernel.range)((*(v13492->vars))[1]);
      else v15461 = CNULL;
        GC_OID(v15461);} 
    if (v15461 != CNULL)
     { { ClaireBoolean * g0007I;
        { OID  v16039;
          { OID gc_local;
            ITERATE(v5115);
            v16039= Kernel.cfalse;
            bag *v5115_support;
            v5115_support = GC_OBJECT(list,Optimize.OPT->objects);
            for (START(v5115_support); NEXT(v5115);)
            if ((INHERIT(OWNER(v5115),Kernel._class)) && 
                (equal(v5115,v15461) == CTRUE))
             { v16039 = Kernel.ctrue;
              break;} 
            } 
          g0007I = boolean_I_any(v16039);
          } 
        
        if (g0007I == CTRUE) v11217= GC_STRING(string_v((*Generate.c_string)(Generate.PRODUCER->value,
            _oid_(OBJECT(ClaireClass,v15461)->name))));
          } 
      if (equal_string(v11217,string_I_symbol(ClEnv->module_I->name)) != CTRUE)
       v5128= (fopen_string(append_string(GC_STRING(append_string(GC_STRING(append_string(GC_STRING(Optimize.compiler->source),GC_STRING(string_v(Reader._starfs_star->value)))),v11217)),GC_STRING(OBJECT(Generate_producer,Generate.PRODUCER->value)->extension)),CSTRING("a")));
      (Optimize.OPT->outfile = v5128);
      } 
    ;} 
  GC_UNBIND;} 

