/***** CLAIRE Compilation of file /Users/ycaseau/claire/v3.5/src/compile/gsystem.cl 
         [version 3.5.01 / safety 5] Sun Jul 24 08:43:47 2016 *****/

#include <claire.h>
#include <Kernel.h>
#include <Core.h>
#include <Language.h>
#include <Reader.h>
#include <Optimize.h>
#include <Generate.h>
void  ident_symbol(symbol *v107876)
{ (*Language.ident)(Generate.PRODUCER->value,
    _oid_(v107876));
  } 

void  ident_thing(thing *v107876)
{ (*Language.ident)(Generate.PRODUCER->value,
    _oid_(v107876->name));
  } 

void  ident_class(ClaireClass *v107876)
{ (*Language.ident)(Generate.PRODUCER->value,
    _oid_(v107876->name));
  } 

void  interface_I_class(ClaireClass *v106827)
{ (*Generate.interface_I)(Generate.PRODUCER->value,
    _oid_(v106827));
  } 

void  class_princ_class(ClaireClass *v106827)
{ (*Generate.class_princ)(Generate.PRODUCER->value,
    _oid_(v106827));
  } 

OID  indent_c_void()
{ { OID Result = 0;
    { Cint  v106848 = Optimize.OPT->level;
      { Result= _oid_(CFALSE);
        while ((v106848 > 0))
        { princ_string(CSTRING("  "));
          v106848= (v106848-1);
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

void  c_test_any(OID v106848)
{ GC_BIND;
  { OID  v106844 = GC_OID((*Optimize.c_type)(v106848));
    ClaireClass * v106843 = osort_any(v106844);
    OID  v106845 = GC_OID((*Optimize.c_code)(v106848,
      _oid_(v106843)));
    ClaireBoolean * v106830 = c_func_any(v106845);
    princ_string(CSTRING("type -> "));
    print_any(v106844);
    princ_string(CSTRING(" [sort "));
    print_any(_oid_(v106843));
    princ_string(CSTRING("]\n"));
    princ_string(CSTRING("opt["));
    print_any(_oid_(OWNER(v106845)));
    princ_string(CSTRING("] -> "));
    print_any(v106845);
    princ_string(CSTRING(" \n"));
    if (v106830 == CTRUE)
     { princ_string(CSTRING("exp  -> "));
      (*Generate.expression)(v106845,
        Core.nil->value);
      princ_string(CSTRING("\n"));
      } 
    else { princ_string(CSTRING("stat -> "));
        statement_any(v106845,_string_(CSTRING("result")),Core.nil->value);
        princ_string(CSTRING("\n"));
        } 
      } 
  GC_UNBIND;} 

void  c_test_method(method *v106837)
{ GC_BIND;
  { lambda * v106836 = GC_OBJECT(lambda,v106837->formula);
    if (v106836 == (NULL))
     ;else { tformat_string(CSTRING("---- Compiling ~S ---- \n"),0,list::alloc(1,_oid_(v106837)));
        (Optimize.OPT->in_method = _oid_(v106837));
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
        (OBJECT(Generate_producer,Generate.PRODUCER->value)->body = v106836->body);
        { ClaireClass * v106843 = Kernel._void;
          OID  v35887;
          { { v106843= check_sort_method(v106837);
              v35887 = OBJECT(Generate_producer,Generate.PRODUCER->value)->body;
              } 
            GC_OID(v35887);} 
          char * v12463 = GC_STRING(string_v((*Generate.protect_result)(Generate.PRODUCER->value,
            _oid_(v106843),
            _oid_(Optimize.OPT->protection),
            _oid_(v106837))));
          princ_string(CSTRING("Opt => "));
          print_any(v35887);
          princ_string(CSTRING(" \n\n"));
          new_block_void();
          (*Generate.print_body)(v35887,
            _string_(v12463),
            _oid_(v106843),
            GC_OID(v106836->body),
            Kernel.ctrue);
          } 
        (Optimize.OPT->in_method = CNULL);
        } 
      } 
  GC_UNBIND;} 

void  compile_module(module *v107876)
{ GC_BIND;
  (Optimize.OPT->need_modules = Kernel.emptySet);
  { bag * v35165 = GC_OBJECT(list,parents_list(GC_OBJECT(list,add_modules_list(list::alloc(1,_oid_(v107876))))));
    update_property(Optimize.legal_modules,
      Optimize.OPT,
      9,
      Kernel._object,
      GC_OID((*Kernel.set_I)(_oid_(v35165))));
    if (Optimize.compiler->class2file_ask == CTRUE)
     { tformat_string(CSTRING("**** Compiling the module ~A [v. 3.~A - verbose:~A opt:~S] \n"),2,list::alloc(4,GC_OID(_string_(string_I_symbol(v107876->name))),
        GC_OID(Optimize.compiler->version),
        ClEnv->verbose,
        _oid_(Optimize.compiler->optimize_ask)));
      write_property(Generate.outmodule,Optimize.OPT,GC_OID(ClAlloc->import(Kernel._port,(Cint *) fopen_string(append_string(GC_STRING(append_string(GC_STRING(append_string(GC_STRING(Optimize.compiler->source),GC_STRING(string_v(Reader._starfs_star->value)))),GC_STRING(string_v((*Generate.c_string)(Generate.PRODUCER->value,
        _oid_(v107876->name)))))),GC_STRING(OBJECT(Generate_producer,Generate.PRODUCER->value)->extension)),CSTRING("w")))));
      generate_files_module(v107876);
      begin_module(v107876);
      generate_classes_module(v107876);
      generate_c2f_module(v107876);
      end_module(v107876);
      } 
    else { generate_files_module(v107876);
        generate_f2f_module(v107876);
        generate_interface_module(v107876,GC_OBJECT(set,Optimize.OPT->legal_modules));
        } 
      v35165= GC_OBJECT(set,difference_set(GC_OBJECT(set,set_I_set(Optimize.OPT->need_modules)),GC_OBJECT(set,Optimize.OPT->legal_modules)));
    if (v35165->length != 0)
     tformat_string(CSTRING("---- WARNING: ~S should be declared for ~S\n"),2,list::alloc(2,_oid_(v35165),_oid_(v107876)));
    } 
  GC_UNBIND;} 

void  generate_files_module(module *v107876)
{ GC_BIND;
  tformat_string(CSTRING("==== Generate ~A files for module ~S [verbose = ~A, Opt? = ~S] \n"),0,list::alloc(4,GC_OID(_string_(OBJECT(Generate_producer,Generate.PRODUCER->value)->comment)),
    _oid_(v107876),
    ClEnv->verbose,
    _oid_(Optimize.compiler->optimize_ask)));
  (Optimize.OPT->instructions = list::empty(Kernel._any));
  (Optimize.OPT->properties = set::empty(Kernel._property));
  (Optimize.OPT->objects = list::empty(Kernel._object));
  (Optimize.OPT->functions = list::empty(Kernel._any));
  (Optimize.OPT->need_to_close = set::empty(Kernel._any));
  (*Generate.start_module_interface)(Generate.PRODUCER->value,
    _oid_(v107876));
  begin_module(v107876);
  { OID gc_local;
    ITERATE(v106848);
    bag *v106848_support;
    v106848_support = GC_OBJECT(list,v107876->made_of);
    for (START(v106848_support); NEXT(v106848);)
    { GC_LOOP;
      { tformat_string(CSTRING("++++ Compiling the file ~A.cl [v. 3.~A - safety:~A] \n"),2,list::alloc(3,v106848,
          GC_OID(Optimize.compiler->version),
          Optimize.compiler->safety));
        if (equal(v106848,_string_(string_I_symbol(v107876->name))) == CTRUE)
         (*Optimize.Cerror)(_string_(CSTRING("[211]  ~S cannot be used both as a file and module name")),
          v106848);
        generate_file_string2(GC_STRING(append_string(GC_STRING(append_string(GC_STRING(v107876->source),GC_STRING(string_v(Reader._starfs_star->value)))),string_v(v106848))),GC_STRING(append_string(GC_STRING(append_string(GC_STRING(Optimize.compiler->source),GC_STRING(string_v(Reader._starfs_star->value)))),string_v(v106848))));
        if (CFALSE == CTRUE)
         claire_gc();
        } 
      GC_UNLOOP;} 
    } 
  end_module(v107876);
  GC_UNBIND;} 

void  generate_f2f_module(module *v106837)
{ GC_BIND;
  { ClairePort * v106840 = (fopen_string(append_string(GC_STRING(append_string(GC_STRING(append_string(GC_STRING(Optimize.compiler->source),GC_STRING(string_v(Reader._starfs_star->value)))),GC_STRING(string_I_symbol(v106837->name)))),GC_STRING(OBJECT(Generate_producer,Generate.PRODUCER->value)->extension)),CSTRING("w")));
    tformat_string(CSTRING("==== generate file for module ~S [~A GC protections inserted] ==== \n"),0,list::alloc(2,_oid_(v106837),OBJECT(Generate_producer,Generate.PRODUCER->value)->stat));
    (Optimize.OPT->outfile = v106840);
    generate_file_string1(GC_STRING(string_I_symbol(v106837->name)),v106837);
    } 
  GC_UNBIND;} 

void  generate_file_string1(char *v106843,module *v106837)
{ GC_BIND;
  start_file_string(v106843,v106837);
  use_as_output_port(Optimize.OPT->outfile);
  (*Generate.generate_classes)(Generate.PRODUCER->value,
    _string_(v106843),
    _oid_(v106837));
  { OID gc_local;
    ITERATE(v106827);
    bag *v106827_support;
    v106827_support = GC_OBJECT(list,Optimize.OPT->objects);
    for (START(v106827_support); NEXT(v106827);)
    if (INHERIT(OWNER(v106827),Kernel._class))
     (*Generate.methods_bodies)(Generate.PRODUCER->value,
      v106827);
    } 
  generate_meta_load_module(v106837);
  breakline_void();
  princ_string(CSTRING("GC_UNBIND;"));
  close_block_void();
  breakline_void();
  fclose_port(Optimize.OPT->outfile);
  GC_UNBIND;} 

void  generate_classes_module(module *v107876)
{ GC_BIND;
  erase_table(Generate.classFile);
  { OID gc_local;
    ITERATE(v106827);
    bag *v106827_support;
    v106827_support = GC_OBJECT(list,Optimize.OPT->objects);
    for (START(v106827_support); NEXT(v106827);)
    { GC_LOOP;
      if (INHERIT(OWNER(v106827),Kernel._class))
       { put_table(Generate.classFile,v106827,ClAlloc->import(Kernel._port,(Cint *) fopen_string(append_string(GC_STRING(append_string(GC_STRING(append_string(GC_STRING(Optimize.compiler->source),GC_STRING(string_v(Reader._starfs_star->value)))),GC_STRING(string_v((*Generate.c_string)(Generate.PRODUCER->value,
          GC_OID((*Kernel.name)(v106827))))))),GC_STRING(OBJECT(Generate_producer,Generate.PRODUCER->value)->extension)),CSTRING("w"))));
        use_as_output_port(EXPORT((ClairePort *),nth_table1(Generate.classFile,v106827)));
        tformat_string(CSTRING("++++ Creating the file ~A.java\n"),2,GC_OBJECT(list,list::alloc(1,GC_OID((*Generate.c_string)(Generate.PRODUCER->value,
          GC_OID((*Kernel.name)(v106827)))))));
        (Optimize.OPT->level = 0);
        princ_string(CSTRING("// class file for "));
        print_any(v106827);
        princ_string(CSTRING(" in module "));
        print_any(_oid_(v107876));
        princ_string(CSTRING(" "));
        breakline_void();
        breakline_void();
        breakline_void();
        princ_string(CSTRING("public class "));
        ident_symbol(OBJECT(symbol,(*Kernel.name)(v106827)));
        princ_string(CSTRING(" extends "));
        ident_symbol(OBJECT(ClaireClass,v106827)->superclass->name);
        new_block_void();
        breakline_void();
        breakline_void();
        princ_string(CSTRING("/* empty constructor by default */"));
        breakline_void();
        princ_string(CSTRING("public "));
        ident_symbol(OBJECT(symbol,(*Kernel.name)(v106827)));
        princ_string(CSTRING("() {}"));
        breakline_void();
        breakline_void();
        breakline_void();
        princ_string(CSTRING("/* declaration of fields */"));
        { OID gc_local;
          ITERATE(v106849);
          bag *v106849_support;
          v106849_support = GC_OBJECT(list,OBJECT(bag,(*Optimize.get_indexed)(v106827)));
          for (START(v106849_support); NEXT(v106849);)
          if (_oid_(domain_I_restriction(OBJECT(restriction,v106849))) == v106827)
           { breakline_void();
            princ_string(CSTRING("public  "));
            interface_I_class(psort_any(_oid_(OBJECT(restriction,v106849)->range)));
            princ_string(CSTRING(" "));
            ident_symbol(OBJECT(restriction,v106849)->selector->name);
            princ_string(CSTRING(";"));
            } 
          } 
        breakline_void();
        princ_string(CSTRING(""));
        fclose_port(EXPORT((ClairePort *),nth_table1(Generate.classFile,v106827)));
        } 
      GC_UNLOOP;} 
    } 
  GC_UNBIND;} 

void  generate_c2f_module(module *v107876)
{ GC_BIND;
  { ClairePort * v98597 = (fopen_string(append_string(GC_STRING(append_string(GC_STRING(append_string(GC_STRING(Optimize.compiler->source),GC_STRING(string_v(Reader._starfs_star->value)))),GC_STRING(string_v((*Generate.c_string)(Generate.PRODUCER->value,
      _oid_(v107876->name)))))),GC_STRING(OBJECT(Generate_producer,Generate.PRODUCER->value)->extension)),CSTRING("w")));
    (Optimize.OPT->outfile = v98597);
    use_as_output_port(v98597);
    (*Generate.generate_start_file)(Generate.PRODUCER->value,
      _oid_(v107876));
    fclose_port(v98597);
    claire_gc();
    generate_functions_module(v107876);
    claire_gc();
    v98597= (fopen_string(append_string(GC_STRING(append_string(GC_STRING(append_string(GC_STRING(Optimize.compiler->source),GC_STRING(string_v(Reader._starfs_star->value)))),GC_STRING(string_v((*Generate.c_string)(Generate.PRODUCER->value,
      _oid_(v107876->name)))))),GC_STRING(OBJECT(Generate_producer,Generate.PRODUCER->value)->extension)),CSTRING("a")));
    use_as_output_port(v98597);
    (Optimize.OPT->outfile = v98597);
    (Optimize.OPT->level = 2);
    generate_objects_module(v107876);
    use_as_output_port(EXPORT((ClairePort *),Reader.STDOUT->value));
    claire_gc();
    use_as_output_port(v98597);
    generate_meta_load_module(v107876);
    (*Generate.generate_end_file)(Generate.PRODUCER->value,
      _oid_(v107876));
    } 
  GC_UNBIND;} 

void  generate_interface_module(module *v107876,bag *v106836)
{ tformat_string(CSTRING("==== Generate inteface (.h) files for module ~S \n"),0,list::alloc(1,_oid_(v107876)));
  use_as_output_port(Optimize.OPT->cinterface);
  breakline_void();
  (*Generate.generate_interface)(Generate.PRODUCER->value,
    _oid_(v107876));
  (*Generate.namespace_I)(Generate.PRODUCER->value,
    _oid_(v107876));
  generate_objects_module(v107876);
  (*Kernel.module_I)(Generate.PRODUCER->value,
    _oid_(v107876));
  (*Generate.end_module_interface)(Generate.PRODUCER->value,
    _oid_(v107876));
  fclose_port(Optimize.OPT->cinterface);
  use_as_output_port(EXPORT((ClairePort *),Reader.STDOUT->value));
  } 

void  generate_objects_module(module *v107876)
{ GC_RESERVE(1);  // HOHO v3.0.55 optim !
  { OID gc_local;
    ITERATE(v106848);
    bag *v106848_support;
    v106848_support = GC_OBJECT(list,Optimize.OPT->objects);
    for (START(v106848_support); NEXT(v106848);)
    { breakline_void();
      (*Generate.public_static)(Generate.PRODUCER->value);
      if (INHERIT(OWNER(v106848),Core._global_variable))
       { { OID  v41395;
          if (nativeVar_ask_global_variable(OBJECT(global_variable,v106848)) == CTRUE)
           v41395 = _oid_(getRange_global_variable(OBJECT(global_variable,v106848)));
          else v41395 = _oid_(Core._global_variable);
            (*Generate.interface_I)(Generate.PRODUCER->value,
            v41395);
          } 
        princ_string(CSTRING(" "));
        ident_symbol(OBJECT(thing,v106848)->name);
        princ_string(CSTRING(";"));
        } 
      else { (*Generate.interface_I)(Generate.PRODUCER->value,
            _oid_(psort_any(_oid_(OWNER(v106848)))));
          princ_string(CSTRING(" "));
          if (INHERIT(OWNER(v106848),Kernel._class))
           { princ_string(CSTRING("_"));
            c_princ_string(string_I_symbol(OBJECT(symbol,(*Kernel.name)(v106848))));
            } 
          else if (INHERIT(OWNER(v106848),Reader._reserved_keyword))
           { princ_string(CSTRING("_cl_"));
            c_princ_string(string_I_symbol(OBJECT(symbol,(*Kernel.name)(v106848))));
            } 
          else ident_symbol(OBJECT(symbol,(*Kernel.name)(v106848)));
            princ_string(CSTRING(";"));
          } 
        } 
    } 
  { OID gc_local;
    ITERATE(v106848);
    bag *v106848_support;
    v106848_support = GC_OBJECT(set,Optimize.OPT->properties);
    for (START(v106848_support); NEXT(v106848);)
    { GC_LOOP;
      if (Optimize.OPT->objects->memq(v106848) != CTRUE)
       { { OID  v20844;
          { { OID  v15417 = CNULL;
              { OID gc_local;
                ITERATE(v35290);
                bag *v35290_support;
                v35290_support = GC_OBJECT(set,Optimize.OPT->properties);
                for (START(v35290_support); NEXT(v35290);)
                { GC_LOOP;
                  if (v35290 != v106848)
                   { if (equal_string(string_I_symbol(OBJECT(thing,v35290)->name),string_I_symbol(OBJECT(thing,v106848)->name)) == CTRUE)
                     { v15417= v35290;
                      break;} 
                    } 
                  GC_UNLOOP;} 
                } 
              v20844 = v15417;
              } 
            GC_OID(v20844);} 
          if (v20844 != CNULL)
           { property * v35290 = OBJECT(property,v20844);
            close_exception(((general_error *) (*Core._general_error)(_string_(CSTRING("[217] ~S and ~S cannot be defined in the same module")),
              _oid_(list::alloc(2,_oid_(v35290),v106848)))));
            } 
          else ;} 
        princ_string(CSTRING("\n"));
        (*Generate.public_static)(Generate.PRODUCER->value);
        (*Generate.interface_I)(Generate.PRODUCER->value,
          _oid_(psort_any(_oid_(OWNER(v106848)))));
        princ_string(CSTRING(" "));
        ident_symbol(OBJECT(thing,v106848)->name);
        princ_string(CSTRING(";// "));
        print_any(_oid_(OBJECT(thing,v106848)->name));
        princ_string(CSTRING(""));
        } 
      GC_UNLOOP;} 
    } 
  GC_UNBIND;} 

void  generate_meta_load_module(module *v107876)
{ GC_RESERVE(1);  // HOHO v3.0.55 optim !
  princ_string(CSTRING("// definition of the meta-model for "));
  print_any(_oid_(v107876));
  princ_string(CSTRING(" \n"));
  breakline_void();
  princ_string(CSTRING(""));
  (*Generate.generate_meta_load)(Generate.PRODUCER->value,
    _oid_(v107876));
  princ_string(CSTRING("// definition of the properties "));
  { OID gc_local;
    ITERATE(v106848);
    bag *v106848_support;
    v106848_support = GC_OBJECT(set,Optimize.OPT->properties);
    for (START(v106848_support); NEXT(v106848);)
    if (Optimize.OPT->objects->memq(v106848) != CTRUE)
     (*Generate.declare)(Generate.PRODUCER->value,
      v106848);
    } 
  breakline_void();
  breakline_void();
  princ_string(CSTRING("// instructions from module sources"));
  { OID  v106834 = CNULL;
    { OID gc_local;
      ITERATE(v106833);
      bag *v106833_support;
      v106833_support = GC_OBJECT(list,Optimize.OPT->instructions);
      for (START(v106833_support); NEXT(v106833);)
      { GC_LOOP;
        { breakline_void();
          if (Kernel._string == OWNER(v106833))
           { if (equal(_oid_(Kernel._string),_oid_(OWNER(v106834))) != CTRUE)
             breakline_void();
            princ_string(CSTRING("// "));
            (*Kernel.princ)(v106833);
            princ_string(CSTRING(""));
            } 
          else if (global_var_def_ask_any(v106833) == CTRUE)
           (*Generate.global_var_def_I)(Generate.PRODUCER->value,
            _oid_(v107876),
            v106833);
          else statement_any(v106833,_oid_(Kernel.emptySet),_oid_(Kernel.emptySet));
            GC__OID(v106834 = v106833, 1);
          } 
        GC_UNLOOP;} 
      } 
    } 
  GC_UNBIND;} 

ClaireBoolean * global_var_def_ask_any(OID v106848)
{ GC_BIND;
  { ClaireBoolean *Result ;
    Result = ((INHERIT(OWNER(v106848),Language._Let)) ?
      ((INHERIT(OWNER(OBJECT(Let,v106848)->value),Language._Call)) ? (((*Kernel.selector)(OBJECT(Let,v106848)->value) == _oid_(Optimize.object_I)) ? (((*(OBJECT(bag,(*Core.args)(OBJECT(Let,v106848)->value))))[2] == _oid_(Core._global_variable)) ? CTRUE: CFALSE): CFALSE): CFALSE) :
      CFALSE );
    GC_UNBIND; return (Result);} 
  } 

ClaireClass * getRange_global_variable(global_variable *v106848)
{ { ClaireClass *Result ;
    Result = ((equal(_oid_(v106848->range),_oid_(Kernel.emptySet)) == CTRUE) ?
      OWNER(v106848->value) :
      class_I_type(v106848->range) );
    return (Result);} 
  } 

void  generate_functions_module(module *v107876)
{ GC_BIND;
  princ_string(CSTRING("// definition of class methods "));
  { ClairePort * v106840 = (Optimize.OPT->outfile);
    { OID gc_local;
      ITERATE(v106830);
      bag *v106830_support;
      v106830_support = GC_OBJECT(list,Optimize.OPT->functions);
      for (START(v106830_support); NEXT(v106830);)
      { GC_LOOP;
        { (Optimize.OPT->level = 2);
          (Optimize.OPT->outfile = v106840);
          print_c_function_lambda2(GC_OBJECT(lambda,OBJECT(lambda,(*Kernel.nth)(v106830,
            1))),GC_STRING(string_v((*Kernel.nth)(v106830,
            2))),GC_OID((*Kernel.nth)(v106830,
            3)));
          } 
        GC_UNLOOP;} 
      } 
    } 
  GC_UNBIND;} 

list * parents_module(module *v107876,list *v106836)
{ if (v106836->memq(_oid_(v107876)) == CTRUE) 
  { { list *Result ;
      Result = v106836;
      return (Result);} 
     } 
  else{ GC_BIND;
    if (((v107876->part_of == (NULL)) ? CTRUE : CFALSE) != CTRUE)
     v106836= GC_OBJECT(list,parents_module(v107876->part_of,v106836));
    v106836= GC_OBJECT(list,v106836->addFast(_oid_(v107876)));
    { list *Result ;
      Result = v106836;
      GC_UNBIND; return (Result);} 
    } 
  } 

list * parents_list(list *v107876)
{ GC_RESERVE(1);  // HOHO v3.0.55 optim !
  { list *Result ;
    { list * v106836 = list::empty(Kernel._module);
      { OID gc_local;
        ITERATE(v106848);
        for (START(v107876); NEXT(v106848);)
        { GC_LOOP;
          GC__ANY(v106836 = parents_module(OBJECT(module,v106848),v106836), 1);
          GC_UNLOOP;} 
        } 
      Result = v106836;
      } 
    GC_UNBIND; return (Result);} 
  } 

void  get_module2(module *v106837)
{ load_module(v106837);
  begin_module(v106837);
  } 

void  generate_file_string2(char *v107876,char *v34980)
{ GC_RESERVE(7);  // v3.0.55 optim !
  { ClairePort * v35289 = (fopen_string(append_string(v107876,CSTRING(".cl")),CSTRING("r")));
    ClaireBoolean * v106826 = Reader.reader->toplevel;
    ClairePort * v35288 = (Reader.reader->fromp);
    if (Optimize.compiler->class2file_ask != CTRUE)
     (Optimize.OPT->outfile = fopen_string(append_string(v34980,GC_STRING(OBJECT(Generate_producer,Generate.PRODUCER->value)->extension)),CSTRING("w")));
    (Reader.reader->toplevel = CFALSE);
    (Optimize.compiler->loading_ask = CTRUE);
    (Reader.reader->nb_line = 1);
    (Reader.reader->external = v107876);
    (Reader.reader->fromp = v35289);
    if (Optimize.compiler->class2file_ask != CTRUE)
     start_file_string(v107876,ClEnv->module_I);
    { OID  v4449 = GC_OID(readblock_port(v35289));
      { OID gc_local;
        while ((equal(v4449,_oid_(Reader.eof)) != CTRUE))
        { GC_LOOP;
          if (ClEnv->verbose > 5)
           { princ_string(CSTRING("["));
            princ_integer(Reader.reader->nb_line);
            princ_string(CSTRING("] "));
            print_any(_oid_(OWNER(v4449)));
            princ_string(CSTRING(" ("));
            print_any(GC_OID(_oid_(Optimize.OPT->need_modules)));
            princ_string(CSTRING("%)\n"));
            } 
          if ((Kernel._string == OWNER(v4449)) && 
              (Optimize.compiler->class2file_ask != CTRUE))
           { if (Optimize.compiler->naming < 2)
             { ClairePort * v35352 = (use_as_output_port(Optimize.OPT->outfile));
              princ_string(CSTRING("\n//"));
              (*Kernel.princ)(v4449);
              princ_string(CSTRING(""));
              use_as_output_port(v35352);
              } 
            } 
          else GC_OBJECT(list,Optimize.OPT->instructions)->addFast(GC_OID((*Optimize.c_code)(v4449,
              _oid_(Kernel._void))));
            GC__OID(v4449 = readblock_port(v35289), 6);
          GC_UNLOOP;} 
        } 
      } 
    fclose_port(v35289);
    (Optimize.compiler->loading_ask = CFALSE);
    (Reader.reader->toplevel = v106826);
    (Reader.reader->external = CSTRING("toplevel"));
    (Reader.reader->fromp = v35288);
    if (Optimize.compiler->class2file_ask != CTRUE)
     fclose_port(Optimize.OPT->outfile);
    } 
  GC_UNBIND;} 

OID  make_c_function_lambda_Generate(lambda *v107876,char *v21151,OID v106837)
{ { OID Result = 0;
    if (Optimize.compiler->class2file_ask == CTRUE)
     Result = (*Generate.create_function_entry)(Generate.PRODUCER->value,
      _oid_(v107876),
      _string_(v21151),
      v106837);
    else Result = print_c_function_lambda2(v107876,v21151,v106837);
      return (Result);} 
  } 

OID  print_c_function_lambda2(lambda *v107876,char *v21151,OID v106837)
{ GC_BIND;
  (OBJECT(Generate_producer,Generate.PRODUCER->value)->body = v107876->body);
  { OID Result = 0;
    { ClaireClass * v106843 = Kernel._void;
      OID  v35887;
      { if (boolean_I_any(v106837) != CTRUE)
         v35887 = (*Optimize.c_code)(GC_OID(v107876->body),
          _oid_(Kernel._void));
        else if (Kernel._method == OWNER(v106837))
         { v106843= check_sort_method(OBJECT(method,v106837));
          v35887 = OBJECT(Generate_producer,Generate.PRODUCER->value)->body;
          } 
        else if (INHERIT(OWNER(v106837),Kernel._class))
         { v106843= OBJECT(ClaireClass,v106837);
          v35887 = (*Optimize.c_code)(GC_OID(v107876->body),
            v106837);
          } 
        else { v106843= Kernel._any;
            v35887 = (*Optimize.c_code)(GC_OID(v107876->body),
              _oid_(Kernel._any));
            } 
          GC_OID(v35887);} 
      OID  v12463 = GC_OID((*Generate.protect_result)(Generate.PRODUCER->value,
        _oid_(v106843),
        _oid_(Optimize.OPT->protection),
        v106837));
      ClaireBoolean * v38246 = need_debug_ask_any(v106837);
      ClaireBoolean * v69628 = ((Optimize.OPT->profile_ask == CTRUE) ? (((Kernel._method == OWNER(v106837)) || 
          (v106837 == CNULL)) ? CTRUE: CFALSE): CFALSE);
      (*Generate.generate_function_start)(Generate.PRODUCER->value,
        _oid_(v107876),
        _oid_(v106843),
        v106837,
        _string_(v21151));
      if (Optimize.OPT->max_vars > 0)
       { (Language._starvariable_index_star->value= 0);
        lexical_num_any2(v35887,(v107876->vars->length+1));
        (Optimize.OPT->loop_index = Language._starvariable_index_star->value);
        } 
      new_block_void();
      if (v69628 == CTRUE)
       (*Generate.generate_profile)(Generate.PRODUCER->value,
        v106837);
      if (v38246 == CTRUE)
       (*Generate.debug_intro)(Generate.PRODUCER->value,
        _oid_(v107876),
        v106837);
      (*Generate.print_body)(v35887,
        v12463,
        _oid_(v106843),
        GC_OID(v107876->body),
        _oid_(not_any(_oid_(((Optimize.OPT->protection == CTRUE) ? CTRUE : ((v69628 == CTRUE) ? CTRUE : ((v38246 == CTRUE) ? CTRUE : ((Optimize.OPT->alloc_stack == CTRUE) ? CTRUE : CFALSE))))))));
      close_block_void();
      breakline_void();
      (Optimize.OPT->alloc_stack = CFALSE);
      Result = ClAlloc->import(Kernel._port,(Cint *) use_as_output_port(EXPORT((ClairePort *),Reader.STDOUT->value)));
      } 
    GC_UNBIND; return (Result);} 
  } 

void  print_body_If(If *v35887,char *v12463,ClaireClass *v106843,If *v52702,ClaireBoolean *v112271)
{ GC_BIND;
  if ((c_func_any(GC_OID(v35887->test)) == CTRUE) && 
      ((Optimize.OPT->protection == CTRUE) && 
        ((c_safe_any(GC_OID(v52702->arg)) == CTRUE) && 
          (Optimize.compiler->debug_ask->memq(_oid_(ClEnv->module_I)) != CTRUE))))
   { char * v124228 = ((v106843 != Kernel._void) ?
      CSTRING("return ") :
      CSTRING("") );
    princ_string(CSTRING("if "));
    (*Optimize.bool_exp)(GC_OID(v35887->test),
      Kernel.ctrue,
      Core.nil->value);
    princ_string(CSTRING(" "));
    breakline_void();
    new_block_void();
    outer_statement_any(GC_OID(v35887->arg),v124228,v106843,v112271);
    princ_string(CSTRING(" "));
    close_block_void();
    princ_string(CSTRING("else"));
    new_block_void();
    (*Generate.print_body)(GC_OID(v35887->other),
      _string_(v12463),
      _oid_(v106843),
      GC_OID(v52702->other),
      _oid_(v112271));
    close_block_void();
    } 
  else print_body_any(_oid_(v35887),
      v12463,
      v106843,
      _oid_(v52702),
      v112271);
    GC_UNBIND;} 

void  print_body_any(OID v35887,char *v12463,ClaireClass *v106843,OID v52702,ClaireBoolean *v112271)
{ (*Generate.gc_introduction)(Generate.PRODUCER->value,
    v35887);
  outer_statement_any(v35887,v12463,v106843,v112271);
  } 

OID  print_body_Do(Do *v35887,char *v12463,ClaireClass *v106843,OID v52702,ClaireBoolean *v112271)
{ GC_BIND;
  { OID Result = 0;
    { list * v106836 = GC_OBJECT(list,v35887->args);
      Cint  v7731 = v106836->length;
      Cint  v106837 = 0;
      (*Generate.gc_introduction)(Generate.PRODUCER->value,
        _oid_(v35887));
      { ITERATE(v106848);
        Result= Kernel.cfalse;
        for (START(v106836); NEXT(v106848);)
        { ++v106837;
          if (v106837 == v7731)
           outer_statement_any(v106848,v12463,v106843,v112271);
          else inner_statement_any(v106848,_oid_(Kernel.emptySet),_oid_(Kernel.emptySet));
            } 
        } 
      } 
    GC_UNBIND; return (Result);} 
  } 

void  outer_statement_any(OID v35887,char *v12463,ClaireClass *v106843,ClaireBoolean *v112271)
{ if ((c_func_any(v35887) == CTRUE) && 
      ((v112271 == CTRUE) && 
        ((v106843 != Kernel._void) && 
          (inherit_ask_class(OWNER(v35887),Language._If) != CTRUE))))
   { if (equal_string(v12463,CSTRING("")) != CTRUE)
     { princ_string(v12463);
      princ_string(CSTRING("("));
      (*Generate.expression)(v35887,
        Core.nil->value);
      princ_string(CSTRING(");"));
      } 
    else { (*Generate.expression)(v35887,
          Core.nil->value);
        princ_string(CSTRING(";"));
        } 
      } 
  else if (v106843 != Kernel._void)
   { new_block_void();
    (*Generate.define_variable)(Generate.PRODUCER->value,
      _oid_(v106843),
      _string_(CSTRING("Result")));
    breakline_void();
    statement_any(v35887,_string_(CSTRING("Result")),_oid_(Kernel.emptySet));
    if (equal_string(v12463,CSTRING("")) != CTRUE)
     { princ_string(v12463);
      princ_string(CSTRING("(Result);"));
      close_block_void();
      princ_string(CSTRING(""));
      } 
    } 
  else { statement_any(v35887,_oid_(Kernel.emptySet),_oid_(Kernel.emptySet));
      princ_string(v12463);
      } 
    } 

ClaireBoolean * c_safe_any(OID v106848)
{ return (not_any(_oid_(((Optimize.OPT->allocation == CTRUE) ? ((BCONTAIN(c_status_any(v106848,Kernel.nil),1)) ? CTRUE: CFALSE): CFALSE))));} 

ClaireClass * check_sort_method(method *v107876)
{ GC_BIND;
  { ClaireClass *Result ;
    { ClaireType * v35382 = v107876->range;
      OID  v106826 = GC_OID(OBJECT(Generate_producer,Generate.PRODUCER->value)->body);
      ClaireType * v35383 = GC_OBJECT(ClaireType,ptype_type(OBJECT(ClaireType,(*Optimize.c_type)(v106826))));
      ClaireClass * v106843 = psort_any(_oid_(v35382));
      (OBJECT(Generate_producer,Generate.PRODUCER->value)->body = c_strict_code_any(v106826,v106843));
      if (_inf_equal_type(v35383,v35382) != CTRUE)
       { tformat_string(CSTRING("---- note: ~S's range was found to be ~S (vs. ~S) \n"),2,list::alloc(3,_oid_(v107876),
          _oid_(v35383),
          _oid_(v35382)));
        if (Generate.WrongMethod->value == 0)
         { (Generate.WrongMethod->value= v106826);
          close_exception(((general_error *) (*Core._general_error)(_string_(CSTRING("You can look at WrongMethod")),
            _oid_(Kernel.nil))));
          } 
        if ((Optimize.compiler->safety < 2) || 
            ((Optimize.compiler->safety < 4) && 
                (boolean_I_any(sort_equal_class(osort_any(_oid_(v35383)),v106843)) != CTRUE)))
         (OBJECT(Generate_producer,Generate.PRODUCER->value)->body = c_strict_code_any(GC_OID(c_check_any(GC_OID((*Optimize.c_code)(v106826,
          _oid_(Kernel._any))),GC_OID((*Optimize.c_code)(_oid_(v35382),
          _oid_(Kernel._type))))),v106843));
        if (boolean_I_any(sort_equal_class(osort_any(_oid_(v35383)),v106843)) != CTRUE)
         { if ((v106843 != Kernel._void) && 
              ((_oid_((INHERIT(v35383->isa,Kernel._class) ? (ClaireObject *) sort_I_class((ClaireClass *) OBJECT(ClaireClass,_oid_(v35383))) :  (ClaireObject *)  sort_I_type((ClaireType *) OBJECT(ClaireType,_oid_(v35383))))) == _oid_(Kernel._void)) || 
                  (inherit_ask_class(v106843,OBJECT(ClaireClass,_oid_((INHERIT(v35383->isa,Kernel._class) ? (ClaireObject *) sort_I_class((ClaireClass *) OBJECT(ClaireClass,_oid_(v35383))) :  (ClaireObject *)  sort_I_type((ClaireType *) OBJECT(ClaireType,_oid_(v35383))))))) != CTRUE)))
           (*Optimize.Cerror)(_string_(CSTRING("[218] Sort error: Cannot compile ~S.")),
            _oid_(v107876));
          } 
        } 
      { ClaireType * v35384 = GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Kernel._exp)(_oid_(v35382),
          _oid_(v35383))));
        if ((Optimize.compiler->safety > 1) && 
            (osort_any(_oid_(v35384)) == v106843))
         { (OBJECT(Generate_producer,Generate.PRODUCER->value)->body = (*Optimize.c_strict_check)(GC_OID(OBJECT(Generate_producer,Generate.PRODUCER->value)->body),
            _oid_(class_I_type(v35384))));
          ;} 
        } 
      if (INHERIT(v35382->isa,Kernel._tuple))
       { (Optimize.OPT->alloc_stack = CTRUE);
        } 
      if ((Optimize.OPT->allocation == CTRUE) && 
          (nth_integer(status_I_restriction(v107876),6) != CTRUE))
       { if (nth_integer(status_I_restriction(v107876),1) != CTRUE)
         ;} 
      else { (Optimize.OPT->loop_gc = CFALSE);
          (Optimize.OPT->protection = CFALSE);
          } 
        Result = psort_any(_oid_(v107876->range));
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  typed_args_list_list(list *v107876)
{ { OID Result = 0;
    { ClaireBoolean * v36977 = CTRUE;
      { ITERATE(v106848);
        Result= Kernel.cfalse;
        for (START(v107876); NEXT(v106848);)
        { if (v36977 == CTRUE)
           v36977= CFALSE;
          else princ_string(CSTRING(","));
            (*Generate.interface_I)(Generate.PRODUCER->value,
            _oid_(sort_Variable(OBJECT(Variable,v106848))));
          (*Language.ident)(Generate.PRODUCER->value,
            v106848);
          } 
        } 
      } 
    return (Result);} 
  } 

ClaireBoolean * need_debug_ask_any(OID v106837)
{ { ClaireBoolean *Result ;
    if (Kernel._method == OWNER(v106837))
     { property * v106840 = OBJECT(restriction,v106837)->selector;
      Result = ((Optimize.compiler->debug_ask->memq(_oid_(OBJECT(restriction,v106837)->module_I)) == CTRUE) ? 
      ((domain_I_restriction(OBJECT(restriction,v106837)) != Kernel._environment) ? 
      ((OBJECT(restriction,v106837)->module_I != claire.it) ? 
      ((v106840 != Core.self_eval) ? 
      ((v106840 != Core.execute) ? 
      ((v106840 != Core.eval_message) ? 
      ((v106840 != Core.push_debug) ? 
      ((v106840 != Core.pop_debug) ? 
      ((v106840 != Core.tr_indent) ? 
      ((v106840 != Core.find_which) ? 
      ((v106840 != Core.matching_ask) ? 
      ((v106840 != Core.vmatch_ask) ? 
      CTRUE: CFALSE): CFALSE): CFALSE): CFALSE): CFALSE): CFALSE): CFALSE): CFALSE): CFALSE): CFALSE): CFALSE): CFALSE);
      } 
    else Result = CFALSE;
      return (Result);} 
  } 

void  get_dependents_method(method *v106837)
{ GC_BIND;
  { OID gc_local;
    ITERATE(v106840);
    bag *v106840_support;
    v106840_support = GC_OBJECT(set,dependents_method(v106837));
    for (START(v106840_support); NEXT(v106840);)
    { property * v81877 = v106837->selector;
      add_table(Reader.PRdependent,_oid_(v81877),v106840);
      } 
    } 
  GC_UNBIND;} 

void  c_princ_function(ClaireFunction *v107876)
{ c_princ_string(string_I_function(v107876));
  } 

void  set_outfile_lambda(lambda *v107876)
{ GC_BIND;
  { module * v106837 = ClEnv->module_I;
    char * v34945 = GC_STRING(string_I_symbol(v106837->name));
    ClairePort * v106840 = (Optimize.OPT->outfile);
    OID  v11541;
    { if (v107876->vars->length != 0)
       v11541 = (*Kernel.range)((*(v107876->vars))[1]);
      else v11541 = CNULL;
        GC_OID(v11541);} 
    if (v11541 != CNULL)
     { { ClaireBoolean * g0007I;
        { OID  v45239;
          { OID gc_local;
            ITERATE(v106827);
            v45239= Kernel.cfalse;
            bag *v106827_support;
            v106827_support = GC_OBJECT(list,Optimize.OPT->objects);
            for (START(v106827_support); NEXT(v106827);)
            if ((INHERIT(OWNER(v106827),Kernel._class)) && 
                (equal(v106827,v11541) == CTRUE))
             { v45239 = Kernel.ctrue;
              break;} 
            } 
          g0007I = boolean_I_any(v45239);
          } 
        
        if (g0007I == CTRUE) v34945= GC_STRING(string_v((*Generate.c_string)(Generate.PRODUCER->value,
            _oid_(OBJECT(ClaireClass,v11541)->name))));
          } 
      if (equal_string(v34945,string_I_symbol(ClEnv->module_I->name)) != CTRUE)
       v106840= (fopen_string(append_string(GC_STRING(append_string(GC_STRING(append_string(GC_STRING(Optimize.compiler->source),GC_STRING(string_v(Reader._starfs_star->value)))),v34945)),GC_STRING(OBJECT(Generate_producer,Generate.PRODUCER->value)->extension)),CSTRING("a")));
      (Optimize.OPT->outfile = v106840);
      } 
    ;} 
  GC_UNBIND;} 

