/***** CLAIRE Compilation of file /Users/ycaseau/claire/v3.5/src/compile/cgen.cl 
         [version 3.5.01 / safety 5] Sun Jul 24 08:43:47 2016 *****/

#include <claire.h>
#include <Kernel.h>
#include <Core.h>
#include <Language.h>
#include <Reader.h>
#include <Optimize.h>
#include <Generate.h>
char * c_string_c_producer1(Generate_c_producer *v106827,Variable *v107876)
{ GC_BIND;
  { char *Result ;
    if (Optimize.compiler->naming == 2)
     Result = append_string(CSTRING("v"),GC_STRING(string_I_integer (integer_I_symbol(v107876->pname))));
    else { print_in_string_void();
        ident_c_producer(v106827,v107876->pname);
        Result = end_of_print_void();
        } 
      GC_UNBIND; return (Result);} 
  } 

char * c_string_c_producer2(Generate_c_producer *v106827,symbol *v107876)
{ print_in_string_void();
  ident_c_producer(v106827,v107876);
  return (end_of_print_void());} 

char * string_I_c_producer1(Generate_c_producer *v106827,Variable *v107876)
{ GC_BIND;
  { char *Result ;
    if (Optimize.compiler->naming == 2)
     Result = append_string(CSTRING("v"),GC_STRING(string_I_integer (integer_I_symbol(v107876->pname))));
    else { print_in_string_void();
        ident_c_producer(v106827,v107876->pname);
        Result = end_of_print_void();
        } 
      GC_UNBIND; return (Result);} 
  } 

char * string_I_c_producer2(Generate_c_producer *v106827,symbol *v107876)
{ print_in_string_void();
  ident_c_producer(v106827,v107876);
  return (end_of_print_void());} 

void  ident_c_producer3(Generate_c_producer *v106827,Variable *v106846)
{ GC_BIND;
  if (Optimize.compiler->naming == 2)
   princ_string(append_string(CSTRING("v"),GC_STRING(string_I_integer (integer_I_symbol(v106846->pname)))));
  else { symbol * v106843 = v106846->pname;
      Cint  v106838 = index_list(v106827->bad_names,_oid_(v106843));
      if (v106838 == 0)
       c_princ_string(string_I_symbol(v106843));
      else c_princ_symbol(OBJECT(symbol,(*(v106827->good_names))[v106838]));
        } 
    GC_UNBIND;} 

void  ident_c_producer(Generate_c_producer *v106827,symbol *v106843)
{ { Cint  v106838 = index_list(v106827->bad_names,_oid_(v106843));
    if (v106838 == 0)
     c_princ_string(string_I_symbol(v106843));
    else c_princ_symbol(OBJECT(symbol,(*(v106827->good_names))[v106838]));
      } 
  } 

void  class_princ_c_producer(Generate_c_producer *v106827,ClaireClass *v107876)
{ if (v107876->name->module_I != claire.it)
   { ident_c_producer(v106827,v107876->name->module_I->name);
    princ_string(CSTRING("_"));
    } 
  ident_c_producer(v106827,v107876->name);
  } 

void  produce_c_producer2(Generate_c_producer *v106827,OID v106848)
{ GC_BIND;
  if (INHERIT(OWNER(v106848),Kernel._function))
   { princ_string(CSTRING("_function_("));
    c_princ_function(OBJECT(ClaireFunction,v106848));
    princ_string(CSTRING(","));
    print_any(GC_OID(_string_(string_I_function(OBJECT(ClaireFunction,v106848)))));
    princ_string(CSTRING(")"));
    } 
  else if (INHERIT(OWNER(v106848),Kernel._char))
   { princ_string(CSTRING("_char_('"));
    if ((v106848 == _oid_(_char_('\"'))) || 
        ((v106848 == _oid_(_char_('\''))) || 
          ((v106848 == _oid_(_char_('\?'))) || 
            (v106848 == _oid_(_char_('\\'))))))
     princ_string(CSTRING("\\"));
    princ_char(OBJECT(ClaireChar,v106848));
    princ_string(CSTRING("')"));
    } 
  else if (INHERIT(OWNER(v106848),Kernel._environment))
   princ_string(CSTRING("ClEnv"));
  else if (Kernel._string == OWNER(v106848))
   { if (Optimize.OPT->use_string_update == CTRUE)
     { princ_string(CSTRING("copy_string("));
      print_any(v106848);
      princ_string(CSTRING(")"));
      } 
    else { princ_string(CSTRING("CSTRING("));
        print_any(v106848);
        princ_string(CSTRING(")"));
        } 
      } 
  else if (INHERIT(OWNER(v106848),Core._global_variable))
   globalVar_c_producer(v106827,OBJECT(global_variable,v106848));
  else if (Kernel._boolean == OWNER(v106848))
   { if ((OBJECT(ClaireBoolean,v106848)) == CTRUE)
     princ_string(CSTRING("CTRUE"));
    else princ_string(CSTRING("CFALSE"));
      } 
  else if (INHERIT(OWNER(v106848),Kernel._symbol))
   { princ_string(CSTRING("symbol::make("));
    print_any(GC_OID(_string_(string_I_symbol(OBJECT(symbol,v106848)))));
    princ_string(CSTRING(","));
    ident_symbol(OBJECT(symbol,v106848)->module_I->name);
    princ_string(CSTRING(","));
    ident_symbol(defined_symbol(OBJECT(symbol,v106848))->name);
    princ_string(CSTRING(")"));
    } 
  else if (INHERIT(OWNER(v106848),Kernel._class))
   { if (v106848 == _oid_(Kernel._cl_import))
     princ_string(CSTRING("Kernel._cl_import"));
    else { ident_c_producer(v106827,defined_symbol(OBJECT(ClaireClass,v106848)->name)->name);
        princ_string(CSTRING("._"));
        c_princ_string(string_I_symbol(OBJECT(ClaireClass,v106848)->name));
        princ_string(CSTRING(""));
        } 
      } 
  else if (INHERIT(OWNER(v106848),Reader._reserved_keyword))
   { ident_c_producer(v106827,defined_symbol(OBJECT(thing,v106848)->name)->name);
    princ_string(CSTRING("._cl_"));
    c_princ_string(string_I_symbol(OBJECT(thing,v106848)->name));
    princ_string(CSTRING(""));
    } 
  else if (INHERIT(OWNER(v106848),Kernel._thing))
   { if (INHERIT(OBJECT(ClaireObject,v106848)->isa,Kernel._module))
     { ident_c_producer(v106827,OBJECT(thing,v106848)->name);
      princ_string(CSTRING(".it"));
      } 
    else { ident_c_producer(v106827,defined_symbol(OBJECT(thing,v106848)->name)->name);
        princ_string(CSTRING("."));
        ident_symbol(OBJECT(thing,v106848)->name);
        princ_string(CSTRING(""));
        } 
      } 
  else princ_string(CSTRING("CNULL"));
    GC_UNBIND;} 

void  globalVar_c_producer(Generate_c_producer *v106827,global_variable *v106848)
{ if ((equal(_oid_(v106848->range),_oid_(Kernel.emptySet)) == CTRUE) && 
      (INHERIT(OWNER(v106848->value),Kernel._integer))) 
  { (*Kernel.princ)(v106848->value);
     } 
  else{ GC_BIND;
    ident_c_producer(v106827,defined_symbol(v106848->name)->name);
    princ_string(CSTRING("."));
    ident_symbol(v106848->name);
    if (nativeVar_ask_global_variable(v106848) != CTRUE)
     princ_string(CSTRING("->value"));
    princ_string(CSTRING(""));
    GC_UNBIND;} 
  } 

void  stat_exp_c_producer(Generate_c_producer *v106827,OID v107876,OID v40124)
{ if (INHERIT(OWNER(v107876),Optimize._to_C)) 
  { stat_exp_c_producer(v106827,GC_OID(OBJECT(Compile_to_C,v107876)->arg),v40124);
     } 
  else{ if (INHERIT(OWNER(v107876),Optimize._to_CL)) 
    { stat_exp_c_producer(v106827,GC_OID(OBJECT(Compile_to_CL,v107876)->arg),v40124);
       } 
    else{ GC_BIND;
      if (designated_ask_any(v107876) == CTRUE)
       princ_string(CSTRING(";"));
      else { (*Generate.expression)(v107876,
            v40124);
          princ_string(CSTRING(";"));
          breakline_void();
          princ_string(CSTRING(""));
          } 
        GC_UNBIND;} 
    } 
  } 

void  namespace_I_c_producer(Generate_c_producer *v106827,module *v106837)
{ princ_string(CSTRING("\n\n// namespace class for "));
  print_any(_oid_(v106837));
  princ_string(CSTRING(" \n"));
  { princ_string(CSTRING("class "));
    ident_c_producer(v106827,v106837->name);
    princ_string(CSTRING("Class: public NameSpace {\npublic:\n"));
    } 
  } 

void  module_I_c_producer(Generate_c_producer *v106827,module *v106837)
{ princ_string(CSTRING("\n\n// module definition \n"));
  princ_string(CSTRING(" void metaLoad();};\n\n"));
  princ_string(CSTRING("extern "));
  ident_c_producer(v106827,v106837->name);
  princ_string(CSTRING("Class "));
  ident_c_producer(v106827,v106837->name);
  princ_string(CSTRING(";\n"));
  { module * v35197 = v106837->part_of;
    { while (((boolean_I_any(_oid_(v35197->made_of)) != CTRUE) && 
          (v35197 != claire.it)))
      { princ_string(CSTRING("extern NameSpace "));
        ident_c_producer(v106827,v35197->name);
        princ_string(CSTRING(";\n"));
        v35197= v35197->part_of;
        } 
      } 
    } 
  } 

void  declare_c_producer(Generate_c_producer *v106827,property *v106840)
{ GC_BIND;
  breakline_void();
  { expression_thing(v106840,Core.nil->value);
    princ_string(CSTRING(" = "));
    princ_string(((INHERIT(v106840->isa,Kernel._operation)) ?
      CSTRING("operation") :
      CSTRING("property") ));
    princ_string(CSTRING("::make("));
    print_any(GC_OID(_string_(string_I_symbol(v106840->name))));
    princ_string(CSTRING(","));
    if ((v106840->open != 1) || 
        (v106840->dispatcher > 0))
     { expression_integer(v106840->open,_oid_(Kernel.emptySet));
      princ_string(CSTRING(","));
      } 
    expression_thing(v106840->name->module_I,Core.nil->value);
    if (INHERIT(v106840->isa,Kernel._operation))
     { princ_string(CSTRING(","));
      princ_integer(CLREAD(operation,v106840,precedence));
      princ_string(CSTRING(""));
      } 
    else if (v106840->dispatcher > 0)
     { princ_string(CSTRING(","));
      (*Generate.expression)(_oid_(v106840->domain),
        Core.nil->value);
      princ_string(CSTRING(","));
      princ_integer(v106840->dispatcher);
      princ_string(CSTRING(""));
      } 
    princ_string(CSTRING(");"));
    } 
  GC_UNBIND;} 

void  start_module_interface_c_producer(Generate_c_producer *v106827,module *v107876)
{ GC_BIND;
  { char * v109260 = GC_STRING(append_string(GC_STRING(Optimize.compiler->headers_dir),GC_STRING(append_string(GC_STRING(append_string(GC_STRING(string_v(Reader._starfs_star->value)),GC_STRING(string_I_symbol(v107876->name)))),CSTRING(".h")))));
    (Optimize.OPT->cinterface = fopen_string(v109260,CSTRING("w")));
    use_as_output_port(Optimize.OPT->cinterface);
    princ_string(CSTRING("// interface defination for module "));
    print_any(_oid_(v107876));
    princ_string(CSTRING(", "));
    princ_string(date_I_integer(1));
    princ_string(CSTRING(""));
    princ_string(CSTRING("#ifndef CLAIREH_"));
    ident_thing(v107876);
    princ_string(CSTRING("\n#define CLAIREH_"));
    ident_thing(v107876);
    princ_string(CSTRING("\n"));
    { OID gc_local;
      ITERATE(v106848);
      bag *v106848_support;
      v106848_support = GC_OBJECT(list,Optimize.compiler->headers);
      for (START(v106848_support); NEXT(v106848);)
      { princ_string(CSTRING("#include \""));
        princ_string(string_v(v106848));
        princ_string(CSTRING(".h\"\n"));
        } 
      } 
    use_as_output_port(EXPORT((ClairePort *),Reader.STDOUT->value));
    } 
  GC_UNBIND;} 

void  end_module_interface_c_producer(Generate_c_producer *v106827,module *v107876)
{ princ_string(CSTRING("\n#endif\n"));
  } 

void  generate_end_file_c_producer(Generate_c_producer *v106834,module *v106837)
{ GC_RESERVE(1);  // HOHO v3.0.55 optim !
  close_block_void();
  fclose_port(Optimize.OPT->outfile);
  { OID gc_local;
    ITERATE(v106827);
    bag *v106827_support;
    v106827_support = GC_OBJECT(list,Optimize.OPT->objects);
    for (START(v106827_support); NEXT(v106827);)
    { GC_LOOP;
      if (INHERIT(OWNER(v106827),Kernel._class))
       { ClairePort * v106840 = (fopen_string(append_string(GC_STRING(append_string(GC_STRING(append_string(GC_STRING(Optimize.compiler->source),GC_STRING(string_v(Reader._starfs_star->value)))),GC_STRING(c_string_c_producer2(v106834,OBJECT(symbol,(*Kernel.name)(v106827)))))),GC_STRING(v106834->extension)),CSTRING("a")));
        use_as_output_port(v106840);
        close_block_void();
        fclose_port(v106840);
        } 
      GC_UNLOOP;} 
    } 
  GC_UNBIND;} 

void  generate_classes_c_producer(Generate_c_producer *v106834,char *v106843,module *v106837)
{ princ_string(CSTRING("\n\n"));
  princ_string(v106843);
  princ_string(CSTRING("Class "));
  princ_string(v106843);
  princ_string(CSTRING(";\n\n"));
  { module * v35196 = v106837;
    module * v35197 = v35196->part_of;
    { while (((boolean_I_any(_oid_(v35197->made_of)) != CTRUE) && 
          ((v35197 != claire.it) && 
            ((*(v35197->parts))[1] == _oid_(v35196)))))
      { princ_string(CSTRING("NameSpace "));
        (*Language.ident)(Generate.PRODUCER->value,
          _oid_(v35197->name));
        princ_string(CSTRING(";\n"));
        v35197= v35197->part_of;
        v35196= v35197;
        } 
      } 
    } 
  } 

void  generate_start_file_c_producer(Generate_c_producer *v106827,module *v106837)
{ GC_BIND;
  tformat_string(CSTRING("++++ Creating the file ~A.cpp \n"),2,list::alloc(1,GC_OID(_string_(c_string_c_producer2(v106827,v106837->name)))));
  start_file_string(GC_STRING(string_I_symbol(v106837->name)),v106837);
  (Optimize.OPT->level = 0);
  princ_string(CSTRING("/* class file for module "));
  print_any(_oid_(v106837));
  princ_string(CSTRING(" */"));
  breakline_void();
  breakline_void();
  princ_string(CSTRING("public class "));
  ident_c_producer(v106827,v106837->name);
  princ_string(CSTRING(" extends NameSpace"));
  new_block_void();
  GC_UNBIND;} 

void  generate_meta_load_c_producer(Generate_c_producer *v106827,module *v106837)
{ princ_string(CSTRING("void "));
  ident_c_producer(v106827,v106837->name);
  princ_string(CSTRING("Class::metaLoad() "));
  new_block_void();
  breakline_void();
  { princ_string(CSTRING("GC_BIND;"));
    breakline_void();
    princ_string(CSTRING("ClEnv->module_I = it;\n"));
    } 
  } 

OID  start_file_string(char *v106843,module *v106837)
{ GC_BIND;
  use_as_output_port(Optimize.OPT->outfile);
  princ_string(CSTRING("/***** CLAIRE Compilation of file "));
  princ_string(v106843);
  princ_string(CSTRING(".cl \n         [version "));
  (*Kernel.princ)(GC_OID(release_void()));
  princ_string(CSTRING(" / safety "));
  print_any(Optimize.compiler->safety);
  princ_string(CSTRING("] "));
  princ_string(substring_string(GC_STRING(date_I_integer(1)),1,24));
  princ_string(CSTRING(" *****/\n\n"));
  princ_string(CSTRING("#include <claire.h>\n"));
  princ_string(CSTRING("#include <Kernel.h>\n"));
  { OID gc_local;
    ITERATE(v106848);
    bag *v106848_support;
    v106848_support = GC_OBJECT(list,add_modules_list(list::alloc(1,_oid_(v106837))));
    for (START(v106848_support); NEXT(v106848);)
    { GC_LOOP;
      { { OID gc_local;
          ITERATE(v106847);
          bag *v106847_support;
          v106847_support = GC_OBJECT(list,OBJECT(module,v106848)->uses);
          for (START(v106847_support); NEXT(v106847);)
          if (Kernel._string == OWNER(v106847))
           { princ_string(CSTRING("#include <"));
            (*Kernel.princ)(v106847);
            princ_string(CSTRING(".h>\n"));
            } 
          } 
        if (OBJECT(module,v106848)->made_of->length != 0)
         { princ_string(CSTRING("#include <"));
          ident_symbol(OBJECT(symbol,(*Kernel.name)(v106848)));
          princ_string(CSTRING(".h>\n"));
          } 
        } 
      GC_UNLOOP;} 
    } 
  if (boolean_I_any(Optimize.OPT->cfile) == CTRUE)
   { princ_string(CSTRING("#include <"));
    (*Kernel.princ)(GC_OID(Optimize.OPT->cfile));
    princ_string(CSTRING(".h>\n"));
    } 
  { OID Result = 0;
    Result = ClAlloc->import(Kernel._port,(Cint *) use_as_output_port(EXPORT((ClairePort *),Reader.STDOUT->value)));
    GC_UNBIND; return (Result);} 
  } 

void  define_variable_c_producer2(Generate_c_producer *v106827,ClaireClass *v106844,char *v106846)
{ interface_I_class(v106844);
  princ_string(v106846);
  princ_string(CSTRING(" "));
  if ((v106844 == Kernel._integer) || 
      (v106844 == Kernel._any))
   princ_string(CSTRING("= 0"));
  else if (v106844 == Kernel._float)
   princ_string(CSTRING("=0.0"));
  princ_string(CSTRING(";"));
  } 

void  generate_profile_c_producer(Generate_c_producer *v106827,OID v106837)
{ if (Kernel._method == OWNER(v106837))
   get_dependents_method(OBJECT(method,v106837));
  { princ_string(CSTRING("   PRcount *PR_x = PRstart(PRget_property("));
    expression_thing(((Kernel._method == OWNER(v106837)) ?
      OBJECT(restriction,v106837)->selector :
      Kernel.fastcall ),Core.nil->value);
    princ_string(CSTRING("));"));
    breakline_void();
    princ_string(CSTRING(""));
    } 
  } 

void  generate_interface_c_producer(Generate_c_producer *v106827,module *v107876)
{ GC_RESERVE(8);  // v3.0.55 optim !
  { OID gc_local;
    ITERATE(v106848);
    bag *v106848_support;
    v106848_support = GC_OBJECT(list,Optimize.OPT->objects);
    for (START(v106848_support); NEXT(v106848);)
    if (INHERIT(OWNER(v106848),Kernel._class))
     { princ_string(CSTRING("\nclass "));
      class_princ_c_producer(v106827,OBJECT(ClaireClass,v106848));
      princ_string(CSTRING(";"));
      } 
    } 
  { OID gc_local;
    ITERATE(v106848);
    bag *v106848_support;
    v106848_support = GC_OBJECT(list,Optimize.OPT->objects);
    for (START(v106848_support); NEXT(v106848);)
    { GC_LOOP;
      if (INHERIT(OWNER(v106848),Kernel._class))
       { princ_string(CSTRING("\n\nclass "));
        class_princ_c_producer(v106827,OBJECT(ClaireClass,v106848));
        princ_string(CSTRING(": public "));
        class_princ_c_producer(v106827,OBJECT(ClaireClass,v106848)->superclass);
        new_block_void();
        breakline_void();
        princ_string(CSTRING("public:"));
        { OID gc_local;
          ITERATE(v106849);
          bag *v106849_support;
          v106849_support = GC_OBJECT(list,OBJECT(bag,(*Optimize.get_indexed)(v106848)));
          for (START(v106849_support); NEXT(v106849);)
          { ClaireBoolean * g0060I;
            { OID  v86186;
              { OID gc_local;
                ITERATE(v35383);
                v86186= Kernel.cfalse;
                for (START(OBJECT(ClaireClass,v106848)->superclass->slots); NEXT(v35383);)
                if (_I_equal_any(_oid_(OBJECT(restriction,v35383)->selector),_oid_(OBJECT(restriction,v106849)->selector)) != CTRUE)
                 { v86186 = Kernel.ctrue;
                  break;} 
                } 
              g0060I = not_any(v86186);
              } 
            
            if (g0060I == CTRUE) { breakline_void();
                princ_string(CSTRING("   "));
                (*Generate.interface_I)(Generate.PRODUCER->value,
                  _oid_(psort_any(_oid_(OBJECT(restriction,v106849)->range))));
                ident_symbol(OBJECT(restriction,v106849)->selector->name);
                princ_string(CSTRING(";"));
                } 
              } 
          } 
        (*Generate.methods_interface)(Generate.PRODUCER->value,
          v106848);
        close_block_void();
        princ_string(CSTRING(";"));
        } 
      GC_UNLOOP;} 
    } 
  { OID gc_local;
    ITERATE(v106836);
    bag *v106836_support;
    v106836_support = GC_OBJECT(list,Optimize.OPT->functions);
    for (START(v106836_support); NEXT(v106836);)
    { GC_LOOP;
      { OID  v33017 = GC_OID((*Kernel.nth)(v106836,
          1));
        OID  v94393 = GC_OID((*Kernel.nth)(v106836,
          2));
        OID  v106843 = GC_OID((*Kernel.nth)(v106836,
          3));
        princ_string(CSTRING("\nextern "));
        (*Generate.interface_I)(Generate.PRODUCER->value,
          v106843);
        princ_string(CSTRING(" "));
        (*Kernel.c_princ)(v33017);
        princ_string(CSTRING("("));
        typed_args_list_list(OBJECT(list,v94393));
        princ_string(CSTRING(");"));
        } 
      GC_UNLOOP;} 
    } 
  GC_UNBIND;} 

void  global_var_def_I_c_producer(Generate_c_producer *v106827,module *v107876,Let *v106848)
{ GC_BIND;
  { global_variable * v60397 = OBJECT(global_variable,get_symbol(OBJECT(symbol,(*(OBJECT(bag,(*Core.args)(GC_OID(v106848->value)))))[1])));
    ClaireClass * v106843 = getRange_global_variable(v60397);
    OID  v7190 = GC_OID((*(OBJECT(Do,v106848->arg)->args))[2]);
    OID  v93625;
    { if (INHERIT(OWNER(v7190),Language._Update))
       v93625 = OBJECT(Update,v7190)->value;
      else if ((INHERIT(OWNER(v7190),Language._Call)) || 
          (INHERIT(OWNER(v7190),Language._Call_method)))
       v93625 = (*(OBJECT(bag,(*Core.args)(v7190))))[5];
      else { OID  v49350;close_exception(((general_error *) (*Core._general_error)(_string_(CSTRING("Design bug: make ~S a public global var !")),
            _oid_(list::alloc(1,_oid_(v60397))))));
          
          v93625=_void_(v49350);} 
        GC_OID(v93625);} 
    ClaireBoolean * v106826 = c_func_any(v93625);
    Variable * v62520 = GC_OBJECT(Variable,build_Variable_string(CSTRING("V_C"),_oid_(Kernel._any)));
    if (nativeVar_ask_global_variable(v60397) != CTRUE)
     statement_any(_oid_(v106848),Core.nil->value,Core.nil->value);
    else { if (v106826 != CTRUE)
         { new_block_void();
          princ_string(CSTRING("OID "));
          ident_c_producer3(v106827,v62520);
          princ_string(CSTRING(";"));
          breakline_void();
          statement_any(v93625,GC_OID((*Generate.c_string)(Generate.PRODUCER->value,
            _oid_(v62520))),Core.nil->value);
          princ_string(CSTRING(""));
          } 
        ident_c_producer(v106827,v107876->name);
        princ_string(CSTRING("."));
        ident_c_producer(v106827,v60397->name);
        princ_string(CSTRING(" = "));
        if (v106826 == CTRUE)
         to_c_c_producer1(v106827,v93625,v106843,Core.nil->value);
        else to_c_c_producer1(v106827,_oid_(v62520),v106843,Core.nil->value);
          princ_string(CSTRING(";"));
        if (v106826 != CTRUE)
         close_block_void();
        breakline_void();
        princ_string(CSTRING(""));
        } 
      } 
  GC_UNBIND;} 

void  gc_introduction_c_producer(Generate_c_producer *v106827,OID v33013)
{ GC_BIND;
  if (Optimize.OPT->protection == CTRUE)
   { OID  v106850 = GC_OID(gc_usage_any(v33013,CFALSE));
    if ((Optimize.OPT->loop_gc == CTRUE) && 
        (INHERIT(OWNER(v106850),Kernel._integer)))
     { if ((OBJECT(ClaireBoolean,(*Kernel._inf)(v106850,
        100))) == CTRUE)
       { (Optimize.OPT->loop_index = 0);
        princ_string(CSTRING("GC_RESERVE(1);  // HOHO v3.0.55 optim !"));
        } 
      else { princ_string(CSTRING("GC_RESERVE("));
          princ_integer((Optimize.OPT->loop_index+1));
          princ_string(CSTRING(");  // v3.0.55 optim !"));
          } 
        } 
    else princ_string(CSTRING("GC_BIND;"));
      breakline_void();
    } 
  GC_UNBIND;} 

OID  gc_usage_any(OID v107876,ClaireBoolean *v40124)
{ { OID Result = 0;
    if (INHERIT(OWNER(v107876),Language._Instruction))
     { if (INHERIT(OBJECT(ClaireObject,v107876)->isa,Language._Construct))
       Result = gc_usage_star_list(OBJECT(Construct,v107876)->args,v40124);
      else if (INHERIT(OBJECT(ClaireObject,v107876)->isa,Language._Definition))
       Result = Kernel.ctrue;
      else if (INHERIT(OBJECT(ClaireObject,v107876)->isa,Language._Call_method))
       Result = gc_usage_star_list(OBJECT(Call_method,v107876)->args,v40124);
      else if (INHERIT(OBJECT(ClaireObject,v107876)->isa,Language._Call_slot))
       Result = gc_usage_any(OBJECT(Call_slot,v107876)->arg,v40124);
      else if (INHERIT(OBJECT(ClaireObject,v107876)->isa,Language._Call_table))
       Result = gc_usage_any(OBJECT(Call_table,v107876)->arg,v40124);
      else if (INHERIT(OBJECT(ClaireObject,v107876)->isa,Language._Call_array))
       Result = gc_usage_any(OBJECT(Call_array,v107876)->arg,v40124);
      else if (INHERIT(OBJECT(ClaireObject,v107876)->isa,Optimize._to_C))
       Result = gc_usage_any(OBJECT(Compile_to_C,v107876)->arg,v40124);
      else if (INHERIT(OBJECT(ClaireObject,v107876)->isa,Optimize._to_CL))
       Result = gc_usage_any(OBJECT(Compile_to_CL,v107876)->arg,v40124);
      else if (INHERIT(OBJECT(ClaireObject,v107876)->isa,Optimize._to_protect))
       Result = Kernel.ctrue;
      else if (INHERIT(OBJECT(ClaireObject,v107876)->isa,Language._Update))
       Result = gc_usage_any(OBJECT(Update,v107876)->value,v40124);
      else if (INHERIT(OBJECT(ClaireObject,v107876)->isa,Language._Call))
       Result = gc_usage_star_list(OBJECT(Call,v107876)->args,v40124);
      else if (INHERIT(OBJECT(ClaireObject,v107876)->isa,Language._If))
       Result = gc_or_any(gc_usage_any(OBJECT(If,v107876)->test,v40124),gc_or_any(gc_usage_any(OBJECT(If,v107876)->arg,v40124),gc_usage_any(OBJECT(If,v107876)->other,v40124)));
      else if (INHERIT(OBJECT(ClaireObject,v107876)->isa,Language._Do))
       Result = gc_usage_star_list(OBJECT(Do,v107876)->args,v40124);
      else if (INHERIT(OBJECT(ClaireObject,v107876)->isa,Language._Iteration))
       Result = gc_or_any(gc_usage_any(OBJECT(Iteration,v107876)->set_arg,v40124),gc_usage_any(OBJECT(Iteration,v107876)->arg,CTRUE));
      else if (INHERIT(OBJECT(ClaireObject,v107876)->isa,Language._Let))
       { OID  v106848 = OBJECT(Let,v107876)->value;
        { OID  v88108;
          if ((v40124 == CTRUE) && 
              (INHERIT(OWNER(v106848),Optimize._to_protect)))
           v88108 = OBJECT(Instruction_with_var,v107876)->var->index;
          else v88108 = Kernel.cfalse;
            Result = gc_or_any(v88108,gc_or_any(gc_usage_any(v106848,v40124),gc_usage_any(OBJECT(Let,v107876)->arg,v40124)));
          } 
        } 
      else if (INHERIT(OBJECT(ClaireObject,v107876)->isa,Language._Assign))
       { OID  v106848 = OBJECT(Assign,v107876)->arg;
        { OID  v89069;
          if ((v40124 == CTRUE) && 
              (inner2outer_ask_any(v106848) == CTRUE))
           v89069 = (*Kernel.index)(OBJECT(Assign,v107876)->var);
          else v89069 = Kernel.cfalse;
            Result = gc_or_any(v89069,gc_usage_any(v106848,v40124));
          } 
        } 
      else if (INHERIT(OBJECT(ClaireObject,v107876)->isa,Optimize._to_protect))
       Result = Kernel.ctrue;
      else if (INHERIT(OBJECT(ClaireObject,v107876)->isa,Language._Gassign))
       Result = gc_usage_any(OBJECT(Gassign,v107876)->arg,v40124);
      else if (INHERIT(OBJECT(ClaireObject,v107876)->isa,Language._And))
       Result = gc_usage_star_list(OBJECT(And,v107876)->args,v40124);
      else if (INHERIT(OBJECT(ClaireObject,v107876)->isa,Language._Or))
       Result = gc_usage_star_list(OBJECT(Or,v107876)->args,v40124);
      else if (INHERIT(OBJECT(ClaireObject,v107876)->isa,Language._Cast))
       Result = gc_usage_any(OBJECT(Cast,v107876)->arg,v40124);
      else if (INHERIT(OBJECT(ClaireObject,v107876)->isa,Language._Super))
       Result = gc_usage_star_list(OBJECT(Super,v107876)->args,v40124);
      else if (INHERIT(OBJECT(ClaireObject,v107876)->isa,Language._Case))
       Result = gc_usage_star_list(OBJECT(Case,v107876)->args,v40124);
      else if (INHERIT(OBJECT(ClaireObject,v107876)->isa,Language._While))
       Result = gc_or_any(gc_usage_any(OBJECT(While,v107876)->arg,CTRUE),gc_usage_any(OBJECT(While,v107876)->test,v40124));
      else if (INHERIT(OBJECT(ClaireObject,v107876)->isa,Language._Return))
       Result = gc_usage_any(OBJECT(Return,v107876)->arg,v40124);
      else if (INHERIT(OBJECT(ClaireObject,v107876)->isa,Language._Handle))
       Result = gc_or_any(gc_usage_any(OBJECT(ClaireHandle,v107876)->arg,v40124),gc_usage_any(OBJECT(ClaireHandle,v107876)->other,v40124));
      else Result = Kernel.cfalse;
        } 
    else Result = Kernel.cfalse;
      return (Result);} 
  } 

OID  gc_or_any(OID v106848,OID v106849)
{ { OID Result = 0;
    if (v106848 == Kernel.cfalse)
     Result = v106849;
    else if (v106848 == Kernel.ctrue)
     { if (v106849 == Kernel.cfalse)
       Result = v106848;
      else Result = v106849;
        } 
    else if (INHERIT(OWNER(v106849),Kernel._integer))
     { if (equal(v106848,v106849) == CTRUE)
       Result = v106849;
      else Result = 1000;
        } 
    else Result = v106848;
      return (Result);} 
  } 

OID  gc_usage_star_list(list *v106836,ClaireBoolean *v40124)
{ { OID Result = 0;
    { OID  v106848 = Kernel.cfalse;
      { ITERATE(v106849);
        for (START(v106836); NEXT(v106849);)
        v106848= gc_or_any(v106848,gc_usage_any(v106849,v40124));
        } 
      Result = v106848;
      } 
    return (Result);} 
  } 

void  debug_intro_c_producer(Generate_c_producer *v106827,lambda *v107876,method *v106848)
{ GC_BIND;
  { module * v106837;
    { ClaireObject *V_CC ;
      if (Kernel._method == v106848->isa)
       V_CC = v106848->module_I;
      else V_CC = CFALSE;
        v106837= (module *) V_CC;} 
    Cint  v106838 = 1;
    princ_string(CSTRING("DB_BIND("));
    ident_thing(v106837);
    princ_string(CSTRING(","));
    expression_thing(v106848->selector,_oid_(Kernel.emptySet));
    princ_string(CSTRING(","));
    princ_integer(v107876->vars->length);
    princ_string(CSTRING(",{"));
    if ((v107876->vars->length == 1) && 
        ((*Kernel.range)((*(v107876->vars))[1]) == _oid_(Kernel._void)))
     princ_string(CSTRING("PUSH(_oid_(ClEnv));"));
    else { OID gc_local;
        ITERATE(v106846);
        for (START(v107876->vars); NEXT(v106846);)
        { princ_string(CSTRING("PUSH("));
          { OID  v106843 = (*(v106848->srange))[v106838];
            if (((v106843 == _oid_(Kernel._any)) && 
                  ((*Kernel.range)(v106846) != _oid_(Kernel._float))) || 
                (v106843 == _oid_(Kernel._integer)))
             (*Generate.expression)(v106846,
              Kernel.cfalse);
            else to_cl_c_producer(v106827,v106846,(((*Kernel.range)(v106846) == _oid_(Kernel._float)) ?
                Kernel._float :
                OBJECT(ClaireClass,v106843) ),Kernel.cfalse);
              } 
          princ_string(CSTRING(");"));
          ++v106838;
          } 
        } 
      princ_string(CSTRING("});"));
    breakline_void();
    princ_string(CSTRING(""));
    } 
  GC_UNBIND;} 

char * protect_result_c_producer(Generate_c_producer *v106827,ClaireClass *v106843,ClaireBoolean *v105132,OID v106848)
{ GC_BIND;
  if (Optimize.compiler->safety > 5)
   { (Optimize.OPT->protection = CFALSE);
    v105132= CFALSE;
    (Optimize.OPT->loop_gc = CFALSE);
    } 
  { char *Result ;
    { char * v35382 = ((v106843 != Kernel._void) ?
        ((v105132 == CTRUE) ?
          CSTRING("GC_UNBIND; return ") :
          CSTRING("return ") ) :
        ((v105132 == CTRUE) ?
          CSTRING("GC_UNBIND;") :
          CSTRING("") ) );
      ClaireObject * v106837;
      if (need_debug_ask_any(v106848) == CTRUE)
       v106837 = OBJECT(method,v106848)->module_I;
      else v106837 = CFALSE;
        if (INHERIT(v106837->isa,Kernel._module))
       { print_in_string_void();
        princ_string(CSTRING("DB_UNBIND("));
        ident_thing(((thing *) v106837));
        princ_string(CSTRING(","));
        (*Generate.expression)(GC_OID((*Kernel.selector)(v106848)),
          _oid_(Kernel.emptySet));
        princ_string(CSTRING(","));
        if (v106843 == Kernel._void)
         princ_string(CSTRING("CNULL"));
        else if ((v106843 == Kernel._any) || 
            (v106843 == Kernel._integer))
         princ_string(CSTRING("Result"));
        else to_cl_c_producer(v106827,GC_OID(_oid_(build_Variable_string(CSTRING("Result"),_oid_(v106843)))),v106843,Core.nil->value);
          princ_string(CSTRING(");"));
        breakline_void();
        princ_string(CSTRING("  "));
        princ_string(v35382);
        princ_string(CSTRING(""));
        Result = end_of_print_void();
        } 
      else Result = (((Optimize.OPT->profile_ask == CTRUE) && 
          ((Kernel._method == OWNER(v106848)) || 
              (v106848 == CNULL))) ?
        append_string(CSTRING("PRend(PR_x);"),v35382) :
        v35382 );
      } 
    GC_UNBIND; return (Result);} 
  } 

void  generate_function_start_c_producer(Generate_c_producer *v106827,lambda *v107876,ClaireClass *v106843,OID v106837,char *v21151)
{ GC_BIND;
  { OID  v11541;
    { if (v107876->vars->length != 0)
       v11541 = (*Kernel.range)(GC_OID((*(v107876->vars))[1]));
      else v11541 = _oid_(Kernel._any);
        GC_OID(v11541);} 
    ClaireFunction * v33017 = make_function_string(v21151);
    list * v35234 = GC_OBJECT(list,(((v107876->vars->length == 1) && 
        ((v11541 == _oid_(Kernel._environment)) || 
            (v11541 == _oid_(Kernel._void)))) ?
      Kernel.nil :
      v107876->vars ));
    update_function_entry_c_producer(v106827,v33017,v35234,v106843);
    use_as_output_port(Optimize.OPT->outfile);
    if (Kernel._method == OWNER(v106837))
     { if ((OBJECT(restriction,v106837)->range == Kernel._float) || 
          (OBJECT(restriction,v106837)->domain->memq(_oid_(Kernel._float)) == CTRUE))
       generate_float_function_c_producer(v106827,OBJECT(method,v106837),GC_STRING(string_I_function(v33017)));
      else if (INHERIT(OBJECT(restriction,v106837)->range->isa,Kernel._tuple))
       generate_tuple_function_c_producer(v106827,OBJECT(method,v106837),GC_STRING(string_I_function(v33017)));
      } 
    generate_regular_function_c_producer(v106827,
      v107876,
      v33017,
      v106843,
      v106837,
      v35234);
    } 
  GC_UNBIND;} 

void  generate_regular_function_c_producer(Generate_c_producer *v106827,lambda *v107876,ClaireFunction *v33017,ClaireClass *v106843,OID v106837,list *v35234)
{ GC_BIND;
  if (Optimize.compiler->naming != 2)
   { princ_string(CSTRING("\n/* The c++ function for: "));
    if (Kernel._method == OWNER(v106837))
     { print_any(_oid_(OBJECT(restriction,v106837)->selector));
      princ_string(CSTRING("("));
      ppvariable_list(GC_OBJECT(list,v107876->vars));
      princ_string(CSTRING(") ["));
      if (Optimize.compiler->naming == 1)
       bitvectorSum_integer(status_I_restriction(OBJECT(restriction,v106837)));
      princ_string(CSTRING("]"));
      } 
    else princ_string(string_I_function(v33017));
      princ_string(CSTRING(" */\n"));
    } 
  { interface_I_c_producer(v106827,v106843);
    princ_string(CSTRING(" "));
    c_princ_function(v33017);
    princ_string(CSTRING("("));
    typed_args_list_list(v35234);
    princ_string(CSTRING(")\n"));
    } 
  GC_UNBIND;} 

void  generate_float_function_c_producer(Generate_c_producer *v106827,method *v106837,char *v21151)
{ GC_BIND;
  { list * v35216 = (((v106837->domain->length == 1) && 
        (domain_I_restriction(v106837) == Kernel._void)) ?
      Kernel.nil :
      v106837->domain );
    Cint  v106838 = v35216->length;
    list * v35234;
    { { bag *v_list; OID v_val;
        OID v106848,CLcount;
        v_list = v35216;
         v35234 = v_list->clone();
        for (CLcount= 1; CLcount <= v_list->length; CLcount++)
        { v106848 = (*(v_list))[CLcount];
          { Variable * v109096 = ((Variable *) GC_OBJECT(Variable,new_object_class(Language._Variable)));
            (v109096->pname = gensym_void());
            { Variable * v82064 = v109096; 
              ClaireType * v82065;
              if (v106848 == _oid_(Kernel._float))
               v82065 = Kernel._any;
              else v82065 = OBJECT(ClaireType,v106848);
                (v82064->range = v82065);} 
            add_I_property(Kernel.instances,Language._Variable,11,_oid_(v109096));
            v_val = _oid_(v109096);
            } 
          
          (*((list *) v35234))[CLcount] = v_val;} 
        } 
      GC_OBJECT(list,v35234);} 
    char * v416 = GC_STRING(append_string(v21151,CSTRING("_")));
    ClaireFunction * v33017 = make_function_string(v416);
    lambda * v79636 = GC_OBJECT(lambda,lambda_I_list(v35234,Core.nil->value));
    ClaireClass * v106843 = ((v106837->range == Kernel._float) ?
      Kernel._any :
      psort_any(_oid_(v106837->range)) );
    generate_regular_function_c_producer(v106827,
      v79636,
      v33017,
      v106843,
      _oid_(v106837),
      v35234);
    GC_OBJECT(list,Optimize.OPT->functions)->addFast(_oid_(list::alloc(3,_oid_(v33017),
      _oid_(v35234),
      _oid_(v106843))));
    new_block_void();
    if (v106843 != Kernel._void)
     princ_string(CSTRING("return "));
    if (v106837->range == Kernel._float)
     princ_string(CSTRING("_float_("));
    c_princ_function(OBJECT(ClaireFunction,(*Optimize.functional_I)(_oid_(v106837))));
    princ_string(CSTRING("("));
    { Cint  v106833 = 1;
      Cint  v82063 = v106838;
      { OID gc_local;
        while ((v106833 <= v82063))
        { if (v106833 != 1)
           princ_string(CSTRING(","));
          if ((*(v106837->domain))[v106833] == _oid_(Kernel._float))
           { princ_string(CSTRING("float_v("));
            expression_Variable(OBJECT(Variable,(*(v35234))[v106833]),Core.nil->value);
            princ_string(CSTRING(")"));
            } 
          else expression_Variable(OBJECT(Variable,(*(v35234))[v106833]),Core.nil->value);
            ++v106833;
          } 
        } 
      } 
    princ_string(CSTRING(")"));
    if (v106837->range == Kernel._float)
     princ_string(CSTRING(")"));
    princ_string(CSTRING(";"));
    close_block_void();
    princ_string(CSTRING("\n"));
    } 
  GC_UNBIND;} 

void  at_c_producer(Generate_c_producer *v106827)
{ princ_string(CSTRING("->"));
  } 

void  generate_tuple_function_c_producer(Generate_c_producer *v106827,method *v106837,char *v21151)
{ GC_BIND;
  { list * v35216 = (((v106837->domain->length == 1) && 
        (domain_I_restriction(v106837) == Kernel._void)) ?
      Kernel.nil :
      v106837->domain );
    Cint  v106838 = v35216->length;
    list * v35234;
    { { bag *v_list; OID v_val;
        OID v106848,CLcount;
        v_list = v35216;
         v35234 = v_list->clone();
        for (CLcount= 1; CLcount <= v_list->length; CLcount++)
        { v106848 = (*(v_list))[CLcount];
          { Variable * v109096 = ((Variable *) GC_OBJECT(Variable,new_object_class(Language._Variable)));
            (v109096->pname = gensym_void());
            (v109096->range = OBJECT(ClaireType,v106848));
            add_I_property(Kernel.instances,Language._Variable,11,_oid_(v109096));
            v_val = _oid_(v109096);
            } 
          
          (*((list *) v35234))[CLcount] = v_val;} 
        } 
      GC_OBJECT(list,v35234);} 
    char * v416 = GC_STRING(append_string(v21151,CSTRING("_")));
    ClaireFunction * v33017 = make_function_string(v416);
    lambda * v79636 = GC_OBJECT(lambda,lambda_I_list(v35234,Core.nil->value));
    ClaireClass * v106843 = Kernel._tuple;
    generate_regular_function_c_producer(v106827,
      v79636,
      v33017,
      v106843,
      _oid_(v106837),
      v35234);
    GC_OBJECT(list,Optimize.OPT->functions)->addFast(_oid_(list::alloc(3,_oid_(v33017),
      _oid_(v35234),
      _oid_(v106843))));
    new_block_void();
    if (v106843 != Kernel._void)
     princ_string(CSTRING("return "));
    c_princ_function(OBJECT(ClaireFunction,(*Optimize.functional_I)(_oid_(v106837))));
    princ_string(CSTRING("("));
    { Cint  v106833 = 1;
      Cint  v82088 = v106838;
      { OID gc_local;
        while ((v106833 <= v82088))
        { if (v106833 != 1)
           princ_string(CSTRING(","));
          expression_Variable(OBJECT(Variable,(*(v35234))[v106833]),Core.nil->value);
          ++v106833;
          } 
        } 
      } 
    princ_string(CSTRING(")"));
    princ_string(CSTRING("->copyIfNeeded()"));
    princ_string(CSTRING(";"));
    close_block_void();
    princ_string(CSTRING("\n"));
    } 
  GC_UNBIND;} 

OID  create_function_entry_c_producer(Generate_c_producer *v106827,lambda *v35214,char *v33017,OID v106837)
{ return (Core.nil->value);} 

OID  update_function_entry_c_producer(Generate_c_producer *v106827,ClaireFunction *v33017,list *v35234,ClaireClass *v106843)
{ GC_BIND;
  GC_OBJECT(list,Optimize.OPT->functions)->addFast(_oid_(list::alloc(3,_oid_(v33017),
    _oid_(v35234),
    _oid_(v106843))));
  { OID Result = 0;
    Result = Kernel.cfalse;
    GC_UNBIND; return (Result);} 
  } 

char * c_interface_class1_Generate(ClaireClass *v107876)
{ { char *Result ;
    { Cint  v106838 = index_list(OBJECT(Generate_producer,Generate.PRODUCER->value)->interfaces,_oid_(v107876));
      Result = ((v106838 == 0) ?
        CSTRING("OID *") :
        string_v((*(OBJECT(Generate_producer,Generate.PRODUCER->value)->interfaces))[(v106838+1)]) );
      } 
    return (Result);} 
  } 

void  c_interface_class2_Generate(ClaireClass *v107876,char *v106843)
{ GC_BIND;
  { Cint  v106838 = index_list(OBJECT(Generate_producer,Generate.PRODUCER->value)->interfaces,_oid_(v107876));
    if (v106838 == 0)
     (OBJECT(Generate_producer,Generate.PRODUCER->value)->interfaces = GC_OBJECT(list,GC_OBJECT(list,OBJECT(Generate_producer,Generate.PRODUCER->value)->interfaces)->addFast(_oid_(v107876)))->addFast(_string_(v106843)));
    else ((*(OBJECT(Generate_producer,Generate.PRODUCER->value)->interfaces))[(v106838+1)]=_string_(v106843));
      } 
  GC_UNBIND;} 

void  c_interface_method_Generate(method *v107876)
{ c_princ_string(string_v((*Optimize.function_name)(_oid_(v107876->selector),
    _oid_(v107876->domain),
    _oid_(v107876->functional))));
  } 

void  interface_I_c_producer(Generate_c_producer *v106827,ClaireClass *v107876)
{ if (v107876 == Kernel._void)
   princ_string(CSTRING("void "));
  else if (v107876 == Kernel._integer)
   princ_string(CSTRING("Cint "));
  else if ((v107876 == Kernel._function) || 
      ((v107876 == Kernel._char) || 
        (v107876 == Kernel._boolean)))
   { ident_c_producer(v106827,v107876->name);
    princ_string(CSTRING(" *"));
    } 
  else if ((INHERIT(v107876,Kernel._cl_import)) || 
      ((v107876 == Kernel._string) || 
        (v107876 == Kernel._array)))
   princ_string(string_v((*Optimize.c_interface)(_oid_(v107876))));
  else if (INHERIT(v107876,Kernel._object))
   { class_princ_c_producer(v106827,v107876);
    princ_string(CSTRING(" *"));
    } 
  else if (INHERIT(v107876,Kernel._bag))
   { ident_c_producer(v106827,v107876->name);
    princ_string(CSTRING(" *"));
    } 
  else if (v107876 == Kernel._float)
   princ_string(CSTRING("double "));
  else princ_string(CSTRING("OID "));
    } 

void  to_cl_c_producer(Generate_c_producer *v106827,OID v106848,ClaireClass *v106843,OID v40124)
{ if (v106843 == Kernel._void)
   { princ_string(CSTRING("_void_("));
    (*Generate.expression)(v106848,
      v40124);
    princ_string(CSTRING(")"));
    } 
  else if (INHERIT(v106843,Kernel._object))
   { if (v106848 == Kernel.ctrue)
     princ_string(CSTRING("Kernel.ctrue"));
    else if (v106848 == Kernel.cfalse)
     princ_string(CSTRING("Kernel.cfalse"));
    else { princ_string(CSTRING("_oid_("));
        (*Generate.expression)(v106848,
          v40124);
        princ_string(CSTRING(")"));
        } 
      } 
  else if (v106843 == Kernel._integer)
   { if (Optimize.compiler->safety > 1)
     (*Generate.expression)(v106848,
      v40124);
    else { princ_string(CSTRING("_integer_("));
        (*Generate.expression)(v106848,
          v40124);
        princ_string(CSTRING(")"));
        } 
      } 
  else if (v106843 == Kernel._char)
   { princ_string(CSTRING("_oid_("));
    (*Generate.expression)(v106848,
      v40124);
    princ_string(CSTRING(")"));
    } 
  else if (v106843 == Kernel._string)
   { princ_string(CSTRING("_string_("));
    (*Generate.expression)(v106848,
      v40124);
    princ_string(CSTRING(")"));
    } 
  else if (v106843 == Kernel._array)
   { princ_string(CSTRING("_array_("));
    (*Generate.expression)(v106848,
      v40124);
    princ_string(CSTRING(")"));
    } 
  else if (v106843 == Kernel._float)
   { princ_string(CSTRING("_float_("));
    (*Generate.expression)(v106848,
      v40124);
    princ_string(CSTRING(")"));
    } 
  else if (INHERIT(v106843,Kernel._cl_import))
   { princ_string(CSTRING("ClAlloc->import("));
    expression_any(_oid_(v106843),_oid_(Kernel.emptySet));
    princ_string(CSTRING(",(Cint *) "));
    (*Generate.expression)(v106848,
      v40124);
    princ_string(CSTRING(")"));
    } 
  else if (v106843 == Kernel._any)
   (*Generate.expression)(v106848,
    v40124);
  else close_exception(((general_error *) (*Core._general_error)(_string_(CSTRING("[internal] to_cl for a ~S is not implemented")),
      _oid_(list::alloc(1,_oid_(v106843))))));
    } 

void  to_c_c_producer1(Generate_c_producer *v106827,OID v106848,ClaireClass *v106843,OID v40124)
{ if (v106843 == Kernel._integer)
   (*Generate.expression)(v106848,
    v40124);
  else if (v106848 == CNULL)
   princ_string(CSTRING("NULL"));
  else if ((INHERIT(OWNER(v106848),Core._global_variable)) && 
      ((equal((*Kernel.range)(v106848),_oid_(Kernel.emptySet)) == CTRUE) && 
        (equal((*Kernel.value)(v106848),Core.nil->value) == CTRUE)))
   princ_string(CSTRING("Kernel.nil"));
  else { to_c_c_producer2(v106827,v106843);
      (*Generate.expression)(v106848,
        v40124);
      princ_string(CSTRING(")"));
      } 
    } 

void  to_c_c_producer2(Generate_c_producer *v106827,ClaireClass *v106843)
{ if (INHERIT(v106843,Kernel._object))
   { princ_string(CSTRING("OBJECT("));
    class_princ_class(v106843);
    princ_string(CSTRING(","));
    } 
  else if (v106843 == Kernel._float)
   princ_string(CSTRING("float_v("));
  else if (v106843 == Kernel._char)
   princ_string(CSTRING("char_v("));
  else if (v106843 == Kernel._string)
   princ_string(CSTRING("string_v("));
  else if (v106843 == Kernel._array)
   princ_string(CSTRING("array_v("));
  else if (INHERIT(v106843,Kernel._cl_import))
   { princ_string(CSTRING("EXPORT(("));
    interface_I_class(v106843);
    princ_string(CSTRING("),"));
    } 
  else close_exception(((general_error *) (*Core._general_error)(_string_(CSTRING("[internal] to_c for a ~S is not implemented")),
      _oid_(list::alloc(1,_oid_(v106843))))));
    } 

void  public_static_c_producer(Generate_c_producer *v106827)
{ ;} 

void  bool_exp_I_c_producer(Generate_c_producer *v106827,OID v107876,OID v40124)
{ if (INHERIT(OWNER(v107876),Optimize._to_CL))
   { princ_string(CSTRING("("));
    (*Optimize.bool_exp)(v107876,
      Kernel.ctrue,
      v40124);
    princ_string(CSTRING(" ? Kernel.ctrue : Kernel.cfalse)"));
    } 
  else { princ_string(CSTRING("("));
      (*Optimize.bool_exp)(v107876,
        Kernel.ctrue,
        v40124);
      princ_string(CSTRING(" ? CTRUE : CFALSE)"));
      } 
    } 

void  inherit_exp_c_producer(Generate_c_producer *v106827,OID v34825,OID v34826,OID v40124)
{ princ_string(CSTRING("INHERIT("));
  (*Generate.expression)(v34825,
    v40124);
  princ_string(CSTRING(","));
  (*Generate.expression)(v34826,
    v40124);
  princ_string(CSTRING(")"));
  } 

void  bitvector_exp_c_producer(Generate_c_producer *v106827,OID v34825,OID v34826,OID v40124)
{ princ_string(CSTRING("BCONTAIN("));
  (*Generate.expression)(v34825,
    v40124);
  princ_string(CSTRING(","));
  (*Generate.expression)(v34826,
    v40124);
  princ_string(CSTRING(")"));
  } 

void  equal_exp_c_producer(Generate_c_producer *v106827,OID v34825,ClaireBoolean *v28291,OID v34826,OID v40300)
{ if ((INHERIT(OWNER(v34825),Optimize._to_CL)) && 
      ((INHERIT(OWNER(v34826),Optimize._to_CL)) && 
        ((osort_any((*Language.set_arg)(v34825)) == osort_any((*Language.set_arg)(v34826))) && 
          ((identifiable_ask_any(GC_OID((*Kernel.arg)(v34825))) == CTRUE) || 
              ((identifiable_ask_any(GC_OID((*Kernel.arg)(v34826))) == CTRUE) || 
                (((*Language.set_arg)(v34825) == _oid_(Kernel._string)) || 
                  ((*Language.set_arg)(v34825) == _oid_(Kernel._float)))))))) 
  { equal_exp_c_producer(v106827,
      GC_OID((*Kernel.arg)(v34825)),
      v28291,
      GC_OID((*Kernel.arg)(v34826)),
      Kernel.ctrue);
     } 
  else{ if ((INHERIT(OWNER(v34825),Optimize._to_protect)) && 
        ((INHERIT(owner_any((*Kernel.arg)(v34825)),Optimize._to_CL)) && 
          (((*Optimize.c_gc_ask)(GC_OID((*Kernel.arg)(GC_OID((*Kernel.arg)(v34825))))) != Kernel.ctrue) && 
            ((INHERIT(OWNER(v34826),Optimize._to_protect)) && 
              ((INHERIT(owner_any((*Kernel.arg)(v34826)),Optimize._to_CL)) && 
                ((*Optimize.c_gc_ask)(GC_OID((*Kernel.arg)(GC_OID((*Kernel.arg)(v34826))))) != Kernel.ctrue)))))) 
    { equal_exp_c_producer(v106827,
        GC_OID((*Kernel.arg)(v34825)),
        v28291,
        GC_OID((*Kernel.arg)(v34826)),
        v40300);
       } 
    else{ GC_BIND;
      { ClaireBoolean * g0072I;
        { ClaireBoolean *v_and;
          { v_and = (((*Optimize.c_sort)(v34825) == _oid_(Kernel._string)) ? CTRUE : CFALSE);
            if (v_and == CFALSE) g0072I =CFALSE; 
            else { v_and = (((*Optimize.c_sort)(v34826) == _oid_(Kernel._string)) ? CTRUE : CFALSE);
              if (v_and == CFALSE) g0072I =CFALSE; 
              else { { OID  v117899;
                  if (INHERIT(OWNER(v34826),Optimize._to_C))
                   v117899 = ((OBJECT(Compile_to_C,v34826)->arg == CNULL) ? Kernel.ctrue : Kernel.cfalse);
                  else v117899 = Kernel.cfalse;
                    v_and = not_any(v117899);
                  } 
                if (v_and == CFALSE) g0072I =CFALSE; 
                else g0072I = CTRUE;} 
              } 
            } 
          } 
        
        if (g0072I == CTRUE) { princ_string(CSTRING("(equal_string("));
            (*Generate.expression)(v34825,
              Core.nil->value);
            princ_string(CSTRING(","));
            (*Generate.expression)(v34826,
              Core.nil->value);
            princ_string(CSTRING(") "));
            sign_equal_boolean(v28291);
            princ_string(CSTRING(" CTRUE)"));
            } 
          else if ((INHERIT(OWNER(v34825),Optimize._to_CL)) && 
            (((*Language.set_arg)(v34825) != _oid_(Kernel._integer)) && 
              (v34826 == CNULL)))
         { princ_string(CSTRING("("));
          (*Generate.expression)(GC_OID((*Kernel.arg)(v34825)),
            Core.nil->value);
          princ_string(CSTRING(" "));
          sign_equal_boolean(v28291);
          princ_string(CSTRING(" NULL)"));
          } 
        else if ((char_exp_ask_c_producer2(v106827,v34825) == CTRUE) || 
            (char_exp_ask_c_producer2(v106827,v34826) == CTRUE))
         { princ_string(CSTRING("("));
          char_exp_c_producer2(v106827,v34825,Core.nil->value);
          princ_string(CSTRING(" "));
          sign_equal_boolean(v28291);
          princ_string(CSTRING(" "));
          char_exp_c_producer2(v106827,v34826,Core.nil->value);
          princ_string(CSTRING(")"));
          } 
        else if ((boolean_I_any(v40300) == CTRUE) || 
            ((identifiable_ask_any(v34825) == CTRUE) || 
              ((identifiable_ask_any(v34826) == CTRUE) || 
                ((*Optimize.c_sort)(v34825) == _oid_(Kernel._float)))))
         { if (equal(_oid_(glb_class(stupid_t_any1(v34825),stupid_t_any1(v34826))),_oid_(Kernel.emptySet)) == CTRUE)
           { warn_void();
            tformat_string(CSTRING("~S = ~S will fail ! [263]"),2,list::alloc(2,v34825,v34826));
            } 
          princ_string(CSTRING("("));
          bexpression_any(v34825,Core.nil->value);
          princ_string(CSTRING(" "));
          sign_equal_boolean(v28291);
          princ_string(CSTRING(" "));
          bexpression_any(v34826,Core.nil->value);
          princ_string(CSTRING(")"));
          } 
        else { princ_string(CSTRING("(equal("));
            (*Generate.expression)(v34825,
              Core.nil->value);
            princ_string(CSTRING(","));
            (*Generate.expression)(v34826,
              Core.nil->value);
            princ_string(CSTRING(") "));
            sign_equal_boolean(v28291);
            princ_string(CSTRING(" CTRUE)"));
            } 
          } 
      GC_UNBIND;} 
    } 
  } 

ClaireBoolean * char_exp_ask_c_producer2(Generate_c_producer *v106827,OID v106848)
{ { ClaireBoolean *Result ;
    if (INHERIT(OWNER(v106848),Kernel._char))
     Result = CTRUE;
    else if (INHERIT(OWNER(v106848),Language._Call_method))
     { method * v106837 = OBJECT(Call_method,v106848)->arg;
      Result = ((_oid_(v106837) == Generate._starnth_1_string_star->value) ? CTRUE : (((_oid_(v106837) == Generate._starnth_string_star->value) && 
          (2 <= Optimize.compiler->safety)) ? CTRUE : CFALSE));
      } 
    else Result = CFALSE;
      return (Result);} 
  } 

void  char_exp_c_producer2(Generate_c_producer *v106827,OID v106848,OID v40124)
{ GC_BIND;
  if (INHERIT(OWNER(v106848),Kernel._char))
   { princ_string(CSTRING("'"));
    if ((v106848 == _oid_(_char_('\"'))) || 
        ((v106848 == _oid_(_char_('\''))) || 
          ((v106848 == _oid_(_char_('\?'))) || 
            (v106848 == _oid_(_char_('\\'))))))
     princ_string(CSTRING("\\"));
    princ_char(OBJECT(ClaireChar,v106848));
    princ_string(CSTRING("'"));
    } 
  else if (INHERIT(OWNER(v106848),Language._Call_method))
   { method * v106837 = OBJECT(Call_method,v106848)->arg;
    if ((_oid_(v106837) == Generate._starnth_1_string_star->value) || 
        (_oid_(v106837) == Generate._starnth_string_star->value))
     { OID  v34825 = (*(OBJECT(Call_method,v106848)->args))[1];
      OID  v34826 = (*(OBJECT(Call_method,v106848)->args))[2];
      (*Generate.expression)(v34825,
        v40124);
      princ_string(CSTRING("["));
      (*Generate.expression)(v34826,
        v40124);
      princ_string(CSTRING(" - 1]"));
      } 
    else { princ_string(CSTRING("((char) "));
        (*Generate.expression)(v106848,
          v40124);
        princ_string(CSTRING("->ascii)"));
        } 
      } 
  else { princ_string(CSTRING("((char) "));
      (*Generate.expression)(v106848,
        v40124);
      princ_string(CSTRING("->ascii)"));
      } 
    GC_UNBIND;} 

void  c_member_c_producer(Generate_c_producer *v106827,OID v107876,ClaireClass *v106843,property *v106848,OID v40124)
{ if (INHERIT(stupid_t_any1(v107876),v106843))
   { (*Generate.expression)(v107876,
      v40124);
    princ_string(CSTRING("->"));
    ident_symbol(v106848->name);
    princ_string(CSTRING(""));
    } 
  else { princ_string(CSTRING("CLREAD("));
      class_princ_class(v106843);
      princ_string(CSTRING(","));
      (*Generate.expression)(v107876,
        v40124);
      princ_string(CSTRING(","));
      ident_symbol(v106848->name);
      princ_string(CSTRING(")"));
      } 
    } 

void  addFast_c_producer(Generate_c_producer *v106827)
{ princ_string(CSTRING("->addFast"));
  } 

void  cast_I_c_producer(Generate_c_producer *v106827,Compile_C_cast *v107876,OID v40124)
{ GC_BIND;
  princ_string(CSTRING("(("));
  class_princ_class(v107876->set_arg);
  princ_string(CSTRING(" *) "));
  (*Generate.expression)(v107876->arg,
    v40124);
  princ_string(CSTRING(")"));
  GC_UNBIND;} 

void  gc_protection_exp_c_producer(Generate_c_producer *v106827,Variable *v106846,ClaireBoolean *v102362,OID v106845,OID v40124)
{ (v106827->stat = (v106827->stat+1));
  if ((osort_any(_oid_(v106846->range)) == Kernel._float) || 
      (osort_any(_oid_(v106846->range)) == Kernel._integer))
   { princ_string(CSTRING("("));
    ident_c_producer3(v106827,v106846);
    princ_string(CSTRING("="));
    if (v102362 == CTRUE)
     (*Generate.expression)(v106845,
      v40124);
    else c_princ_string(string_v(v106845));
      princ_string(CSTRING(")"));
    } 
  else { princ_string(CSTRING("GC__"));
      princ_string(((osort_any(_oid_(v106846->range)) == Kernel._any) ?
        CSTRING("OID") :
        ((osort_any(_oid_(v106846->range)) == Kernel._string) ?
          CSTRING("STRING") :
          CSTRING("ANY") ) ));
      princ_string(CSTRING("("));
      ident_c_producer3(v106827,v106846);
      if (v106845 != _oid_(v106846))
       { princ_string(CSTRING(" = "));
        if (v102362 == CTRUE)
         (*Generate.expression)(v106845,
          v40124);
        else c_princ_string(string_v(v106845));
          } 
      princ_string(CSTRING(", "));
      princ_integer(((Optimize.OPT->loop_index == 0) ?
        1 :
        (v106846->index+1) ));
      princ_string(CSTRING(")"));
      } 
    } 

void  bag_expression_c_producer(Generate_c_producer *v34957,ClaireClass *v106827,bag *v106836,ClaireType *v106844,OID v40124)
{ GC_BIND;
  if (v106836->length == 0)
   { print_any(_oid_(v106827));
    princ_string(CSTRING("::empty("));
    if (v106844 != Kernel._void)
     { (*Generate.expression)(GC_OID((*Optimize.c_code)(_oid_(v106844),
          _oid_(Kernel._object))),
        v40124);
      } 
    princ_string(CSTRING(")"));
    } 
  else { print_any(_oid_(v106827));
      princ_string(CSTRING("::alloc"));
      if ((v106827 == Kernel._tuple) && 
          (Optimize.OPT->alloc_stack == CTRUE))
       princ_string(CSTRING("Stack"));
      princ_string(CSTRING("("));
      if (v106844 != Kernel._void)
       { (*Generate.expression)(GC_OID((*Optimize.c_code)(_oid_(v106844),
            _oid_(Kernel._object))),
          v40124);
        princ_string(CSTRING(","));
        } 
      princ_integer(v106836->length);
      princ_string(CSTRING(","));
      args_list_bag(v106836,v40124,_sup_integer(v106836->length,2));
      princ_string(CSTRING(")"));
      } 
    GC_UNBIND;} 

void  generate_s_file_string(char *v107876,list *v106836,OID v106837)
{ GC_BIND;
  { ClairePort * v106840 = (fopen_string(append_string(GC_STRING(append_string(GC_STRING(_7_string(GC_STRING(Optimize.compiler->source),v107876)),CSTRING("-s"))),GC_STRING(OBJECT(Generate_producer,Generate.PRODUCER->value)->extension)),CSTRING("w")));
    list * v112584 = GC_OBJECT(list,add_modules_list(v106836));
    list * v72228 = GC_OBJECT(list,parents_list(v106836));
    (Optimize.OPT->cinterface = v106840);
    (Optimize.OPT->properties = set::empty(Kernel._property));
    (Optimize.OPT->objects = list::empty(Kernel._any));
    (Optimize.OPT->functions = list::empty(Kernel._any));
    (Optimize.OPT->need_to_close = set::empty(Kernel._any));
    (Optimize.OPT->legal_modules = set_I_bag(v72228));
    use_as_output_port(v106840);
    princ_string(CSTRING("// --- System configuration file for "));
    print_any(_string_(v107876));
    princ_string(CSTRING(" , ["));
    print_any(GC_OID(_string_(date_I_integer(1))));
    princ_string(CSTRING("] ---\n\n"));
    princ_string(CSTRING("#include <claire.h>\n"));
    princ_string(CSTRING("#include <Kernel.h>\n"));
    { ITERATE(v106848);
      for (START(v112584); NEXT(v106848);)
      if (OBJECT(module,v106848)->made_of->length != 0)
       { princ_string(CSTRING("#include <"));
        ident_symbol(OBJECT(symbol,(*Kernel.name)(v106848)));
        princ_string(CSTRING(".h>\n"));
        } 
      } 
    create_load_modules_string(v107876,v106840,v72228,v106837);
    if ((boolean_I_any(_oid_(_at_property1(Core.main,Kernel._list))) == CTRUE) && 
        (domain_I_restriction(((restriction *) _at_property1(Core.main,Kernel._list))) == Kernel._list))
     { char * v106843 = CSTRING("main_list");
      princ_string(CSTRING("\nextern void "));
      princ_string(v106843);
      princ_string(CSTRING("(list *l);\n"));
      princ_string(CSTRING("void call_main() {"));
      princ_string(v106843);
      princ_string(CSTRING("(ClEnv->params);}\n"));
      } 
    else princ_string(CSTRING("\nvoid call_main() {default_main();}\n"));
      fclose_port(v106840);
    } 
  GC_UNBIND;} 

void  create_load_modules_string(char *v107876,ClairePort *v106840,list *v72228,OID v106837)
{ GC_BIND;
  breakline_void();
  { OID gc_local;
    ITERATE(v106848);
    for (START(v72228); NEXT(v106848);)
    if ((*Kernel.status)(v106848) == 5)
     { princ_string(CSTRING("void load_"));
      ident_symbol(OBJECT(symbol,(*Kernel.name)(v106848)));
      princ_string(CSTRING("() {"));
      ident_symbol(OBJECT(symbol,(*Kernel.name)(v106848)));
      princ_string(CSTRING(".metaLoad();}\n"));
      } 
    } 
  princ_string(CSTRING("\n\nvoid loadModules() \n"));
  new_block_void();
  princ_string(CSTRING("//module definitions "));
  breakline_void();
  princ_string(CSTRING(""));
  { OID gc_local;
    ITERATE(v106848);
    bag *v106848_support;
    v106848_support = GC_OBJECT(set,_backslash_type(v72228,GC_OBJECT(set,set::alloc(Kernel.emptySet,3,_oid_(claire.it),
      _oid_(mClaire.it),
      _oid_(Kernel.it)))));
    for (START(v106848_support); NEXT(v106848);)
    { GC_LOOP;
      { ident_symbol(OBJECT(symbol,(*Kernel.name)(v106848)));
        princ_string(CSTRING(".initModule("));
        print_any(GC_OID(_string_(string_I_symbol(OBJECT(symbol,(*Kernel.name)(v106848))))));
        princ_string(CSTRING(","));
        expression_thing(OBJECT(module,v106848)->part_of,Core.nil->value);
        princ_string(CSTRING(","));
        (*Generate.expression)(GC_OID((*Optimize.c_code)(GC_OID(_oid_(OBJECT(module,v106848)->uses)),
            _oid_(Kernel._list))),
          Core.nil->value);
        princ_string(CSTRING(","));
        breakline_void();
        print_any(GC_OID((*Kernel.source)(v106848)));
        princ_string(CSTRING(","));
        (*Generate.expression)(GC_OID((*Optimize.c_code)(GC_OID(_oid_(OBJECT(module,v106848)->made_of)),
            _oid_(Kernel._list))),
          Core.nil->value);
        princ_string(CSTRING(");"));
        breakline_void();
        princ_string(CSTRING(""));
        } 
      GC_UNLOOP;} 
    } 
  princ_string(CSTRING("//module load "));
  breakline_void();
  princ_string(CSTRING(""));
  { OID gc_local;
    ITERATE(v106848);
    for (START(v72228); NEXT(v106848);)
    if ((OBJECT(module,v106848)->made_of->length != 0) && 
        ((*Kernel.status)(v106848) != 5))
     { ident_symbol(OBJECT(symbol,(*Kernel.name)(v106848)));
      princ_string(CSTRING(".metaLoad();"));
      breakline_void();
      princ_string(CSTRING(""));
      } 
    } 
  { OID gc_local;
    ITERATE(v106848);
    for (START(v72228); NEXT(v106848);)
    { GC_LOOP;
      if ((*Kernel.status)(v106848) == 5)
       { ident_symbol(OBJECT(symbol,(*Kernel.name)(v106848)));
        princ_string(CSTRING(".it->evaluate = "));
        expression_any(_oid_(make_function_string(append_string(CSTRING("load_"),GC_STRING(string_I_symbol(OBJECT(symbol,(*Kernel.name)(v106848))))))),Kernel.cfalse);
        breakline_void();
        princ_string(CSTRING(""));
        ident_symbol(OBJECT(symbol,(*Kernel.name)(v106848)));
        princ_string(CSTRING(".it->status = 2;"));
        breakline_void();
        princ_string(CSTRING(""));
        } 
      GC_UNLOOP;} 
    } 
  princ_string(CSTRING("ClEnv->module_I = "));
  { OID  v119821;
    if (INHERIT(OWNER(v106837),Kernel._module))
     v119821 = v106837;
    else v119821 = _oid_(claire.it);
      (*Generate.expression)(v119821,
      Core.nil->value);
    } 
  princ_string(CSTRING("; "));
  breakline_void();
  princ_string(CSTRING(""));
  if (Optimize.compiler->safety > 5)
   princ_string(CSTRING("ClAlloc->statusGC = 2;\n"));
  if (Optimize.OPT->profile_ask == CTRUE)
   { OID gc_local;
    ITERATE(v106840);
    for (START(Reader.PRdependent->graph); NEXT(v106840);)
    { GC_LOOP;
      if (INHERIT(OWNER(v106840),Kernel._property))
       { OID gc_local;
        ITERATE(v35290);
        bag *v35290_support;
        v35290_support = GC_OBJECT(set,OBJECT(bag,nth_table1(Reader.PRdependent,v106840)));
        for (START(v35290_support); NEXT(v35290);)
        if ((contain_ask_set(Optimize.OPT->to_remove,v35290) != CTRUE) && 
            (OBJECT(thing,v106840)->name->definition == OBJECT(thing,v35290)->name->definition))
         { princ_string(CSTRING("PRdepends_property("));
          expression_thing(OBJECT(thing,v106840),Core.nil->value);
          princ_string(CSTRING(","));
          expression_thing(OBJECT(thing,v35290),Core.nil->value);
          princ_string(CSTRING(");\n"));
          } 
        } 
      GC_UNLOOP;} 
    } 
  close_block_void();
  GC_UNBIND;} 

void  methods_interface_c_producer(Generate_c_producer *v106827,ClaireClass *v106848)
{ GC_RESERVE(6);  // v3.0.55 optim !
  { OID gc_local;
    ITERATE(v106840);
    bag *v106840_support;
    v106840_support = GC_OBJECT(list,OBJECT(bag,nth_table1(Language.InterfaceList,_oid_(v106848))));
    for (START(v106840_support); NEXT(v106840);)
    { GC_LOOP;
      { ClaireObject * v106837 = GC_OBJECT(ClaireObject,_at_property1(OBJECT(property,v106840),v106848));
        if ((Kernel._method == v106837->isa) && 
            (get_property(Kernel.formula,v106837) != CNULL))
         { ClaireClass * v106843 = class_I_type(OBJECT(ClaireType,(*Kernel.range)(_oid_(v106837))));
          list * v94393 = GC_OBJECT(list,cdr_list(OBJECT(lambda,(*Kernel.formula)(_oid_(v106837)))->vars));
          breakline_void();
          interface_I_c_producer(v106827,v106843);
          princ_string(CSTRING(" "));
          (*Kernel.c_princ)(GC_OID((*Kernel.name)(v106840)));
          princ_string(CSTRING("("));
          typed_args_list_list(v94393);
          princ_string(CSTRING(");  "));
          } 
        } 
      GC_UNLOOP;} 
    } 
  GC_UNBIND;} 

void  methods_bodies_c_producer(Generate_c_producer *v106827,ClaireClass *v106848)
{ GC_RESERVE(6);  // v3.0.55 optim !
  { OID gc_local;
    ITERATE(v106840);
    bag *v106840_support;
    v106840_support = GC_OBJECT(list,OBJECT(bag,nth_table1(Language.InterfaceList,_oid_(v106848))));
    for (START(v106840_support); NEXT(v106840);)
    { GC_LOOP;
      { ClaireObject * v106837 = GC_OBJECT(ClaireObject,_at_property1(OBJECT(property,v106840),v106848));
        if ((Kernel._method == v106837->isa) && 
            (get_property(Kernel.formula,v106837) != CNULL))
         { ClaireClass * v106843 = class_I_type(OBJECT(ClaireType,(*Kernel.range)(_oid_(v106837))));
          list * v94393 = GC_OBJECT(list,cdr_list(OBJECT(lambda,(*Kernel.formula)(_oid_(v106837)))->vars));
          breakline_void();
          princ_string(CSTRING("// interface method "));
          breakline_void();
          princ_string(CSTRING(""));
          breakline_void();
          interface_I_c_producer(v106827,v106843);
          princ_string(CSTRING(" "));
          class_princ_class(v106848);
          princ_string(CSTRING("::"));
          (*Kernel.c_princ)(GC_OID((*Kernel.name)(v106840)));
          princ_string(CSTRING("("));
          typed_args_list_list(v94393);
          princ_string(CSTRING(")"));
          breakline_void();
          princ_string(CSTRING("  "));
          princ_string(CSTRING("\t{ "));
          if (v106843 != Kernel._void)
           { princ_string(CSTRING("return ("));
            interface_I_c_producer(v106827,v106843);
            princ_string(CSTRING(") "));
            } 
          if ((OBJECT(ClaireBoolean,(*Kernel._sup)(GC_OID((*Kernel.dispatcher)(v106840)),
            0))) == CTRUE)
           { (*Generate.expression)(v106840,
              Core.nil->value);
            princ_string(CSTRING("->fcall((Cint) this"));
            { OID gc_local;
              ITERATE(v106846);
              for (START(v94393); NEXT(v106846);)
              { princ_string(CSTRING(",(Cint) "));
                (*Generate.expression)(v106846,
                  Core.nil->value);
                } 
              } 
            princ_string(CSTRING(")"));
            } 
          else { c_princ_function(OBJECT(ClaireFunction,(*Optimize.functional_I)(_oid_(v106837))));
              princ_string(CSTRING("(this"));
              { OID gc_local;
                ITERATE(v106846);
                for (START(v94393); NEXT(v106846);)
                { princ_string(CSTRING(","));
                  (*Generate.expression)(v106846,
                    Core.nil->value);
                  } 
                } 
              princ_string(CSTRING(")"));
              } 
            princ_string(CSTRING(";}\n"));
          breakline_void();
          princ_string(CSTRING(""));
          } 
        } 
      GC_UNLOOP;} 
    } 
  GC_UNBIND;} 

