/***** CLAIRE Compilation of file e:\claire\v3.5\src\compile\cgen.cl 
         [version 3.5.0 / safety 5] Sun May 28 08:26:01 2017 *****/

#include <claire.h>
#include <Kernel.h>
#include <Core.h>
#include <Language.h>
#include <Reader.h>
#include <Optimize.h>
#include <Generate.h>
char * c_string_c_producer1(Generate_c_producer *v5115,Variable *v13492)
{ GC_BIND;
  { char *Result ;
    if (Optimize.compiler->naming == 2)
     Result = append_string(CSTRING("v"),GC_STRING(string_I_integer (integer_I_symbol(v13492->pname))));
    else { print_in_string_void();
        ident_c_producer(v5115,v13492->pname);
        Result = end_of_print_void();
        } 
      GC_UNBIND; return (Result);} 
  } 

char * c_string_c_producer2(Generate_c_producer *v5115,symbol *v13492)
{ print_in_string_void();
  ident_c_producer(v5115,v13492);
  return (end_of_print_void());} 

char * string_I_c_producer1(Generate_c_producer *v5115,Variable *v13492)
{ GC_BIND;
  { char *Result ;
    if (Optimize.compiler->naming == 2)
     Result = append_string(CSTRING("v"),GC_STRING(string_I_integer (integer_I_symbol(v13492->pname))));
    else { print_in_string_void();
        ident_c_producer(v5115,v13492->pname);
        Result = end_of_print_void();
        } 
      GC_UNBIND; return (Result);} 
  } 

char * string_I_c_producer2(Generate_c_producer *v5115,symbol *v13492)
{ print_in_string_void();
  ident_c_producer(v5115,v13492);
  return (end_of_print_void());} 

void  ident_c_producer3(Generate_c_producer *v5115,Variable *v5138)
{ GC_BIND;
  if (Optimize.compiler->naming == 2)
   princ_string(append_string(CSTRING("v"),GC_STRING(string_I_integer (integer_I_symbol(v5138->pname)))));
  else { symbol * v5134 = v5138->pname;
      Cint  v5126 = index_list(v5115->bad_names,_oid_(v5134));
      if (v5126 == 0)
       c_princ_string(string_I_symbol(v5134));
      else c_princ_symbol(OBJECT(symbol,(*(v5115->good_names))[v5126]));
        } 
    GC_UNBIND;} 

void  ident_c_producer(Generate_c_producer *v5115,symbol *v5134)
{ { Cint  v5126 = index_list(v5115->bad_names,_oid_(v5134));
    if (v5126 == 0)
     c_princ_string(string_I_symbol(v5134));
    else c_princ_symbol(OBJECT(symbol,(*(v5115->good_names))[v5126]));
      } 
  } 

void  class_princ_c_producer(Generate_c_producer *v5115,ClaireClass *v13492)
{ if (v13492->name->module_I != claire.it)
   { ident_c_producer(v5115,v13492->name->module_I->name);
    princ_string(CSTRING("_"));
    } 
  ident_c_producer(v5115,v13492->name);
  } 

void  produce_c_producer2(Generate_c_producer *v5115,OID v5136)
{ GC_BIND;
  if (INHERIT(OWNER(v5136),Kernel._function))
   { princ_string(CSTRING("_function_("));
    c_princ_function(OBJECT(ClaireFunction,v5136));
    princ_string(CSTRING(","));
    print_any(GC_OID(_string_(string_I_function(OBJECT(ClaireFunction,v5136)))));
    princ_string(CSTRING(")"));
    } 
  else if (INHERIT(OWNER(v5136),Kernel._char))
   { princ_string(CSTRING("_char_('"));
    if ((v5136 == _oid_(_char_('\"'))) || 
        ((v5136 == _oid_(_char_('\''))) || 
          ((v5136 == _oid_(_char_('\?'))) || 
            (v5136 == _oid_(_char_('\\'))))))
     princ_string(CSTRING("\\"));
    princ_char(OBJECT(ClaireChar,v5136));
    princ_string(CSTRING("')"));
    } 
  else if (INHERIT(OWNER(v5136),Kernel._environment))
   princ_string(CSTRING("ClEnv"));
  else if (Kernel._string == OWNER(v5136))
   { if (Optimize.OPT->use_string_update == CTRUE)
     { princ_string(CSTRING("copy_string("));
      print_any(v5136);
      princ_string(CSTRING(")"));
      } 
    else { princ_string(CSTRING("CSTRING("));
        print_any(v5136);
        princ_string(CSTRING(")"));
        } 
      } 
  else if (INHERIT(OWNER(v5136),Core._global_variable))
   globalVar_c_producer(v5115,OBJECT(global_variable,v5136));
  else if (Kernel._boolean == OWNER(v5136))
   { if ((OBJECT(ClaireBoolean,v5136)) == CTRUE)
     princ_string(CSTRING("CTRUE"));
    else princ_string(CSTRING("CFALSE"));
      } 
  else if (INHERIT(OWNER(v5136),Kernel._symbol))
   { princ_string(CSTRING("symbol::make("));
    print_any(GC_OID(_string_(string_I_symbol(OBJECT(symbol,v5136)))));
    princ_string(CSTRING(","));
    ident_symbol(OBJECT(symbol,v5136)->module_I->name);
    princ_string(CSTRING(","));
    ident_symbol(defined_symbol(OBJECT(symbol,v5136))->name);
    princ_string(CSTRING(")"));
    } 
  else if (INHERIT(OWNER(v5136),Kernel._class))
   { if (v5136 == _oid_(Kernel._cl_import))
     princ_string(CSTRING("Kernel._cl_import"));
    else { ident_c_producer(v5115,defined_symbol(OBJECT(ClaireClass,v5136)->name)->name);
        princ_string(CSTRING("._"));
        c_princ_string(string_I_symbol(OBJECT(ClaireClass,v5136)->name));
        princ_string(CSTRING(""));
        } 
      } 
  else if (INHERIT(OWNER(v5136),Reader._reserved_keyword))
   { ident_c_producer(v5115,defined_symbol(OBJECT(thing,v5136)->name)->name);
    princ_string(CSTRING("._cl_"));
    c_princ_string(string_I_symbol(OBJECT(thing,v5136)->name));
    princ_string(CSTRING(""));
    } 
  else if (INHERIT(OWNER(v5136),Kernel._thing))
   { if (INHERIT(OBJECT(ClaireObject,v5136)->isa,Kernel._module))
     { ident_c_producer(v5115,OBJECT(thing,v5136)->name);
      princ_string(CSTRING(".it"));
      } 
    else { ident_c_producer(v5115,defined_symbol(OBJECT(thing,v5136)->name)->name);
        princ_string(CSTRING("."));
        ident_symbol(OBJECT(thing,v5136)->name);
        princ_string(CSTRING(""));
        } 
      } 
  else princ_string(CSTRING("CNULL"));
    GC_UNBIND;} 

void  globalVar_c_producer(Generate_c_producer *v5115,global_variable *v5136)
{ if ((equal(_oid_(v5136->range),_oid_(Kernel.emptySet)) == CTRUE) && 
      (INHERIT(OWNER(v5136->value),Kernel._integer))) 
  { (*Kernel.princ)(v5136->value);
     } 
  else{ GC_BIND;
    ident_c_producer(v5115,defined_symbol(v5136->name)->name);
    princ_string(CSTRING("."));
    ident_symbol(v5136->name);
    if (nativeVar_ask_global_variable(v5136) != CTRUE)
     princ_string(CSTRING("->value"));
    princ_string(CSTRING(""));
    GC_UNBIND;} 
  } 

void  stat_exp_c_producer(Generate_c_producer *v5115,OID v13492,OID v11276)
{ if (INHERIT(OWNER(v13492),Optimize._to_C)) 
  { stat_exp_c_producer(v5115,GC_OID(OBJECT(Compile_to_C,v13492)->arg),v11276);
     } 
  else{ if (INHERIT(OWNER(v13492),Optimize._to_CL)) 
    { stat_exp_c_producer(v5115,GC_OID(OBJECT(Compile_to_CL,v13492)->arg),v11276);
       } 
    else{ GC_BIND;
      if (designated_ask_any(v13492) == CTRUE)
       princ_string(CSTRING(";"));
      else { (*Generate.expression)(v13492,
            v11276);
          princ_string(CSTRING(";"));
          breakline_void();
          princ_string(CSTRING(""));
          } 
        GC_UNBIND;} 
    } 
  } 

void  namespace_I_c_producer(Generate_c_producer *v5115,module *v5125)
{ princ_string(CSTRING("\n\n// namespace class for "));
  print_any(_oid_(v5125));
  princ_string(CSTRING(" \n"));
  { princ_string(CSTRING("class "));
    ident_c_producer(v5115,v5125->name);
    princ_string(CSTRING("Class: public NameSpace {\npublic:\n"));
    } 
  } 

void  module_I_c_producer(Generate_c_producer *v5115,module *v5125)
{ princ_string(CSTRING("\n\n// module definition \n"));
  princ_string(CSTRING(" void metaLoad();};\n\n"));
  princ_string(CSTRING("extern "));
  ident_c_producer(v5115,v5125->name);
  princ_string(CSTRING("Class "));
  ident_c_producer(v5115,v5125->name);
  princ_string(CSTRING(";\n"));
  { module * v11469 = v5125->part_of;
    { while (((boolean_I_any(_oid_(v11469->made_of)) != CTRUE) && 
          (v11469 != claire.it)))
      { princ_string(CSTRING("extern NameSpace "));
        ident_c_producer(v5115,v11469->name);
        princ_string(CSTRING(";\n"));
        v11469= v11469->part_of;
        } 
      } 
    } 
  } 

void  declare_c_producer(Generate_c_producer *v5115,property *v5128)
{ GC_BIND;
  breakline_void();
  { expression_thing(v5128,Core.nil->value);
    princ_string(CSTRING(" = "));
    princ_string(((INHERIT(v5128->isa,Kernel._operation)) ?
      CSTRING("operation") :
      CSTRING("property") ));
    princ_string(CSTRING("::make("));
    print_any(GC_OID(_string_(string_I_symbol(v5128->name))));
    princ_string(CSTRING(","));
    if ((v5128->open != 1) || 
        (v5128->dispatcher > 0))
     { expression_integer(v5128->open,_oid_(Kernel.emptySet));
      princ_string(CSTRING(","));
      } 
    expression_thing(v5128->name->module_I,Core.nil->value);
    if (INHERIT(v5128->isa,Kernel._operation))
     { princ_string(CSTRING(","));
      princ_integer(CLREAD(operation,v5128,precedence));
      princ_string(CSTRING(""));
      } 
    else if (v5128->dispatcher > 0)
     { princ_string(CSTRING(","));
      (*Generate.expression)(_oid_(v5128->domain),
        Core.nil->value);
      princ_string(CSTRING(","));
      princ_integer(v5128->dispatcher);
      princ_string(CSTRING(""));
      } 
    princ_string(CSTRING(");"));
    } 
  GC_UNBIND;} 

void  start_module_interface_c_producer(Generate_c_producer *v5115,module *v13492)
{ GC_BIND;
  { char * v15900 = GC_STRING(append_string(GC_STRING(Optimize.compiler->headers_dir),GC_STRING(append_string(GC_STRING(append_string(GC_STRING(string_v(Reader._starfs_star->value)),GC_STRING(string_I_symbol(v13492->name)))),CSTRING(".h")))));
    (Optimize.OPT->cinterface = fopen_string(v15900,CSTRING("w")));
    use_as_output_port(Optimize.OPT->cinterface);
    princ_string(CSTRING("// interface defination for module "));
    print_any(_oid_(v13492));
    princ_string(CSTRING(", "));
    princ_string(date_I_integer(1));
    princ_string(CSTRING(""));
    princ_string(CSTRING("#ifndef CLAIREH_"));
    ident_thing(v13492);
    princ_string(CSTRING("\n#define CLAIREH_"));
    ident_thing(v13492);
    princ_string(CSTRING("\n"));
    { OID gc_local;
      ITERATE(v5136);
      bag *v5136_support;
      v5136_support = GC_OBJECT(list,Optimize.compiler->headers);
      for (START(v5136_support); NEXT(v5136);)
      { princ_string(CSTRING("#include \""));
        princ_string(string_v(v5136));
        princ_string(CSTRING(".h\"\n"));
        } 
      } 
    use_as_output_port(EXPORT((ClairePort *),Reader.STDOUT->value));
    } 
  GC_UNBIND;} 

void  end_module_interface_c_producer(Generate_c_producer *v5115,module *v13492)
{ princ_string(CSTRING("\n#endif\n"));
  } 

void  generate_end_file_c_producer(Generate_c_producer *v5122,module *v5125)
{ GC_RESERVE(1);  // HOHO v3.0.55 optim !
  close_block_void();
  fclose_port(Optimize.OPT->outfile);
  { OID gc_local;
    ITERATE(v5115);
    bag *v5115_support;
    v5115_support = GC_OBJECT(list,Optimize.OPT->objects);
    for (START(v5115_support); NEXT(v5115);)
    { GC_LOOP;
      if (INHERIT(OWNER(v5115),Kernel._class))
       { ClairePort * v5128 = (fopen_string(append_string(GC_STRING(append_string(GC_STRING(append_string(GC_STRING(Optimize.compiler->source),GC_STRING(string_v(Reader._starfs_star->value)))),GC_STRING(c_string_c_producer2(v5122,OBJECT(symbol,(*Kernel.name)(v5115)))))),GC_STRING(v5122->extension)),CSTRING("a")));
        use_as_output_port(v5128);
        close_block_void();
        fclose_port(v5128);
        } 
      GC_UNLOOP;} 
    } 
  GC_UNBIND;} 

void  generate_classes_c_producer(Generate_c_producer *v5122,char *v5134,module *v5125)
{ princ_string(CSTRING("\n\n"));
  princ_string(v5134);
  princ_string(CSTRING("Class "));
  princ_string(v5134);
  princ_string(CSTRING(";\n\n"));
  { module * v11468 = v5125;
    module * v11469 = v11468->part_of;
    { while (((boolean_I_any(_oid_(v11469->made_of)) != CTRUE) && 
          ((v11469 != claire.it) && 
            ((*(v11469->parts))[1] == _oid_(v11468)))))
      { princ_string(CSTRING("NameSpace "));
        (*Language.ident)(Generate.PRODUCER->value,
          _oid_(v11469->name));
        princ_string(CSTRING(";\n"));
        v11469= v11469->part_of;
        v11468= v11469;
        } 
      } 
    } 
  } 

void  generate_start_file_c_producer(Generate_c_producer *v5115,module *v5125)
{ GC_BIND;
  tformat_string(CSTRING("++++ Creating the file ~A.cpp \n"),2,list::alloc(1,GC_OID(_string_(c_string_c_producer2(v5115,v5125->name)))));
  start_file_string(GC_STRING(string_I_symbol(v5125->name)),v5125);
  (Optimize.OPT->level = 0);
  princ_string(CSTRING("/* class file for module "));
  print_any(_oid_(v5125));
  princ_string(CSTRING(" */"));
  breakline_void();
  breakline_void();
  princ_string(CSTRING("public class "));
  ident_c_producer(v5115,v5125->name);
  princ_string(CSTRING(" extends NameSpace"));
  new_block_void();
  GC_UNBIND;} 

void  generate_meta_load_c_producer(Generate_c_producer *v5115,module *v5125)
{ princ_string(CSTRING("void "));
  ident_c_producer(v5115,v5125->name);
  princ_string(CSTRING("Class::metaLoad() "));
  new_block_void();
  breakline_void();
  { princ_string(CSTRING("GC_BIND;"));
    breakline_void();
    princ_string(CSTRING("ClEnv->module_I = it;\n"));
    } 
  } 

OID  start_file_string(char *v5134,module *v5125)
{ GC_BIND;
  use_as_output_port(Optimize.OPT->outfile);
  princ_string(CSTRING("/***** CLAIRE Compilation of file "));
  princ_string(v5134);
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
    ITERATE(v5136);
    bag *v5136_support;
    v5136_support = GC_OBJECT(list,add_modules_list(list::alloc(1,_oid_(v5125))));
    for (START(v5136_support); NEXT(v5136);)
    { GC_LOOP;
      { { OID gc_local;
          ITERATE(v5140);
          bag *v5140_support;
          v5140_support = GC_OBJECT(list,OBJECT(module,v5136)->uses);
          for (START(v5140_support); NEXT(v5140);)
          if (Kernel._string == OWNER(v5140))
           { princ_string(CSTRING("#include <"));
            (*Kernel.princ)(v5140);
            princ_string(CSTRING(".h>\n"));
            } 
          } 
        if (OBJECT(module,v5136)->made_of->length != 0)
         { princ_string(CSTRING("#include <"));
          ident_symbol(OBJECT(symbol,(*Kernel.name)(v5136)));
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
    Result = ClAlloc->import(Kernel._port,(int *) use_as_output_port(EXPORT((ClairePort *),Reader.STDOUT->value)));
    GC_UNBIND; return (Result);} 
  } 

void  define_variable_c_producer2(Generate_c_producer *v5115,ClaireClass *v5133,char *v5138)
{ interface_I_class(v5133);
  princ_string(v5138);
  princ_string(CSTRING(" "));
  if ((v5133 == Kernel._integer) || 
      (v5133 == Kernel._any))
   princ_string(CSTRING("= 0"));
  else if (v5133 == Kernel._float)
   princ_string(CSTRING("=0.0"));
  princ_string(CSTRING(";"));
  } 

void  generate_profile_c_producer(Generate_c_producer *v5115,OID v5125)
{ if (Kernel._method == OWNER(v5125))
   get_dependents_method(OBJECT(method,v5125));
  { princ_string(CSTRING("   PRcount *PR_x = PRstart(PRget_property("));
    expression_thing(((Kernel._method == OWNER(v5125)) ?
      OBJECT(restriction,v5125)->selector :
      Kernel.fastcall ),Core.nil->value);
    princ_string(CSTRING("));"));
    breakline_void();
    princ_string(CSTRING(""));
    } 
  } 

void  generate_interface_c_producer(Generate_c_producer *v5115,module *v13492)
{ GC_RESERVE(8);  // v3.0.55 optim !
  { OID gc_local;
    ITERATE(v5136);
    bag *v5136_support;
    v5136_support = GC_OBJECT(list,Optimize.OPT->objects);
    for (START(v5136_support); NEXT(v5136);)
    if (INHERIT(OWNER(v5136),Kernel._class))
     { princ_string(CSTRING("\nclass "));
      class_princ_c_producer(v5115,OBJECT(ClaireClass,v5136));
      princ_string(CSTRING(";"));
      } 
    } 
  { OID gc_local;
    ITERATE(v5136);
    bag *v5136_support;
    v5136_support = GC_OBJECT(list,Optimize.OPT->objects);
    for (START(v5136_support); NEXT(v5136);)
    { GC_LOOP;
      if (INHERIT(OWNER(v5136),Kernel._class))
       { princ_string(CSTRING("\n\nclass "));
        class_princ_c_producer(v5115,OBJECT(ClaireClass,v5136));
        princ_string(CSTRING(": public "));
        class_princ_c_producer(v5115,OBJECT(ClaireClass,v5136)->superclass);
        new_block_void();
        breakline_void();
        princ_string(CSTRING("public:"));
        { OID gc_local;
          ITERATE(v5137);
          bag *v5137_support;
          v5137_support = GC_OBJECT(list,OBJECT(bag,(*Optimize.get_indexed)(v5136)));
          for (START(v5137_support); NEXT(v5137);)
          { ClaireBoolean * g0060I;
            { OID  v7834;
              { OID gc_local;
                ITERATE(v11655);
                v7834= Kernel.cfalse;
                for (START(OBJECT(ClaireClass,v5136)->superclass->slots); NEXT(v11655);)
                if (_I_equal_any(_oid_(OBJECT(restriction,v11655)->selector),_oid_(OBJECT(restriction,v5137)->selector)) != CTRUE)
                 { v7834 = Kernel.ctrue;
                  break;} 
                } 
              g0060I = not_any(v7834);
              } 
            
            if (g0060I == CTRUE) { breakline_void();
                princ_string(CSTRING("   "));
                (*Generate.interface_I)(Generate.PRODUCER->value,
                  _oid_(psort_any(_oid_(OBJECT(restriction,v5137)->range))));
                ident_symbol(OBJECT(restriction,v5137)->selector->name);
                princ_string(CSTRING(";"));
                } 
              } 
          } 
        (*Generate.methods_interface)(Generate.PRODUCER->value,
          v5136);
        close_block_void();
        princ_string(CSTRING(";"));
        } 
      GC_UNLOOP;} 
    } 
  { OID gc_local;
    ITERATE(v5124);
    bag *v5124_support;
    v5124_support = GC_OBJECT(list,Optimize.OPT->functions);
    for (START(v5124_support); NEXT(v5124);)
    { GC_LOOP;
      { OID  v9289 = GC_OID((*Kernel.nth)(v5124,
          1));
        OID  v2923 = GC_OID((*Kernel.nth)(v5124,
          2));
        OID  v5134 = GC_OID((*Kernel.nth)(v5124,
          3));
        princ_string(CSTRING("\nextern "));
        (*Generate.interface_I)(Generate.PRODUCER->value,
          v5134);
        princ_string(CSTRING(" "));
        (*Kernel.c_princ)(v9289);
        princ_string(CSTRING("("));
        typed_args_list_list(OBJECT(list,v2923));
        princ_string(CSTRING(");"));
        } 
      GC_UNLOOP;} 
    } 
  GC_UNBIND;} 

void  global_var_def_I_c_producer(Generate_c_producer *v5115,module *v13492,Let *v5136)
{ GC_BIND;
  { global_variable * v1693 = OBJECT(global_variable,get_symbol(OBJECT(symbol,(*(OBJECT(bag,(*Core.args)(GC_OID(v5136->value)))))[1])));
    ClaireClass * v5134 = getRange_global_variable(v1693);
    OID  v2758 = GC_OID((*(OBJECT(Do,v5136->arg)->args))[2]);
    OID  v10505;
    { if (INHERIT(OWNER(v2758),Language._Update))
       v10505 = OBJECT(Update,v2758)->value;
      else if ((INHERIT(OWNER(v2758),Language._Call)) || 
          (INHERIT(OWNER(v2758),Language._Call_method)))
       v10505 = (*(OBJECT(bag,(*Core.args)(v2758))))[5];
      else { OID  v12502;close_exception(((general_error *) (*Core._general_error)(_string_(CSTRING("Design bug: make ~S a public global var !")),
            _oid_(list::alloc(1,_oid_(v1693))))));
          
          v10505=_void_(v12502);} 
        GC_OID(v10505);} 
    ClaireBoolean * v5114 = c_func_any(v10505);
    Variable * v904 = GC_OBJECT(Variable,build_Variable_string(CSTRING("V_C"),_oid_(Kernel._any)));
    if (nativeVar_ask_global_variable(v1693) != CTRUE)
     statement_any(_oid_(v5136),Core.nil->value,Core.nil->value);
    else { if (v5114 != CTRUE)
         { new_block_void();
          princ_string(CSTRING("OID "));
          ident_c_producer3(v5115,v904);
          princ_string(CSTRING(";"));
          breakline_void();
          statement_any(v10505,GC_OID((*Generate.c_string)(Generate.PRODUCER->value,
            _oid_(v904))),Core.nil->value);
          princ_string(CSTRING(""));
          } 
        ident_c_producer(v5115,v13492->name);
        princ_string(CSTRING("."));
        ident_c_producer(v5115,v1693->name);
        princ_string(CSTRING(" = "));
        if (v5114 == CTRUE)
         to_c_c_producer1(v5115,v10505,v5134,Core.nil->value);
        else to_c_c_producer1(v5115,_oid_(v904),v5134,Core.nil->value);
          princ_string(CSTRING(";"));
        if (v5114 != CTRUE)
         close_block_void();
        breakline_void();
        princ_string(CSTRING(""));
        } 
      } 
  GC_UNBIND;} 

void  gc_introduction_c_producer(Generate_c_producer *v5115,OID v9285)
{ GC_BIND;
  if (Optimize.OPT->protection == CTRUE)
   { OID  v5139 = GC_OID(gc_usage_any(v9285,CFALSE));
    if ((Optimize.OPT->loop_gc == CTRUE) && 
        (INHERIT(OWNER(v5139),Kernel._integer)))
     { if ((OBJECT(ClaireBoolean,(*Kernel._inf)(v5139,
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

OID  gc_usage_any(OID v13492,ClaireBoolean *v11276)
{ { OID Result = 0;
    if (INHERIT(OWNER(v13492),Language._Instruction))
     { if (INHERIT(OBJECT(ClaireObject,v13492)->isa,Language._Construct))
       Result = gc_usage_star_list(OBJECT(Construct,v13492)->args,v11276);
      else if (INHERIT(OBJECT(ClaireObject,v13492)->isa,Language._Definition))
       Result = Kernel.ctrue;
      else if (INHERIT(OBJECT(ClaireObject,v13492)->isa,Language._Call_method))
       Result = gc_usage_star_list(OBJECT(Call_method,v13492)->args,v11276);
      else if (INHERIT(OBJECT(ClaireObject,v13492)->isa,Language._Call_slot))
       Result = gc_usage_any(OBJECT(Call_slot,v13492)->arg,v11276);
      else if (INHERIT(OBJECT(ClaireObject,v13492)->isa,Language._Call_table))
       Result = gc_usage_any(OBJECT(Call_table,v13492)->arg,v11276);
      else if (INHERIT(OBJECT(ClaireObject,v13492)->isa,Language._Call_array))
       Result = gc_usage_any(OBJECT(Call_array,v13492)->arg,v11276);
      else if (INHERIT(OBJECT(ClaireObject,v13492)->isa,Optimize._to_C))
       Result = gc_usage_any(OBJECT(Compile_to_C,v13492)->arg,v11276);
      else if (INHERIT(OBJECT(ClaireObject,v13492)->isa,Optimize._to_CL))
       Result = gc_usage_any(OBJECT(Compile_to_CL,v13492)->arg,v11276);
      else if (INHERIT(OBJECT(ClaireObject,v13492)->isa,Optimize._to_protect))
       Result = Kernel.ctrue;
      else if (INHERIT(OBJECT(ClaireObject,v13492)->isa,Language._Update))
       Result = gc_usage_any(OBJECT(Update,v13492)->value,v11276);
      else if (INHERIT(OBJECT(ClaireObject,v13492)->isa,Language._Call))
       Result = gc_usage_star_list(OBJECT(Call,v13492)->args,v11276);
      else if (INHERIT(OBJECT(ClaireObject,v13492)->isa,Language._If))
       Result = gc_or_any(gc_usage_any(OBJECT(If,v13492)->test,v11276),gc_or_any(gc_usage_any(OBJECT(If,v13492)->arg,v11276),gc_usage_any(OBJECT(If,v13492)->other,v11276)));
      else if (INHERIT(OBJECT(ClaireObject,v13492)->isa,Language._Do))
       Result = gc_usage_star_list(OBJECT(Do,v13492)->args,v11276);
      else if (INHERIT(OBJECT(ClaireObject,v13492)->isa,Language._Iteration))
       Result = gc_or_any(gc_usage_any(OBJECT(Iteration,v13492)->set_arg,v11276),gc_usage_any(OBJECT(Iteration,v13492)->arg,CTRUE));
      else if (INHERIT(OBJECT(ClaireObject,v13492)->isa,Language._Let))
       { OID  v5136 = OBJECT(Let,v13492)->value;
        { OID  v9756;
          if ((v11276 == CTRUE) && 
              (INHERIT(OWNER(v5136),Optimize._to_protect)))
           v9756 = OBJECT(Instruction_with_var,v13492)->var->index;
          else v9756 = Kernel.cfalse;
            Result = gc_or_any(v9756,gc_or_any(gc_usage_any(v5136,v11276),gc_usage_any(OBJECT(Let,v13492)->arg,v11276)));
          } 
        } 
      else if (INHERIT(OBJECT(ClaireObject,v13492)->isa,Language._Assign))
       { OID  v5136 = OBJECT(Assign,v13492)->arg;
        { OID  v10717;
          if ((v11276 == CTRUE) && 
              (inner2outer_ask_any(v5136) == CTRUE))
           v10717 = (*Kernel.index)(OBJECT(Assign,v13492)->var);
          else v10717 = Kernel.cfalse;
            Result = gc_or_any(v10717,gc_usage_any(v5136,v11276));
          } 
        } 
      else if (INHERIT(OBJECT(ClaireObject,v13492)->isa,Optimize._to_protect))
       Result = Kernel.ctrue;
      else if (INHERIT(OBJECT(ClaireObject,v13492)->isa,Language._Gassign))
       Result = gc_usage_any(OBJECT(Gassign,v13492)->arg,v11276);
      else if (INHERIT(OBJECT(ClaireObject,v13492)->isa,Language._And))
       Result = gc_usage_star_list(OBJECT(And,v13492)->args,v11276);
      else if (INHERIT(OBJECT(ClaireObject,v13492)->isa,Language._Or))
       Result = gc_usage_star_list(OBJECT(Or,v13492)->args,v11276);
      else if (INHERIT(OBJECT(ClaireObject,v13492)->isa,Language._Cast))
       Result = gc_usage_any(OBJECT(Cast,v13492)->arg,v11276);
      else if (INHERIT(OBJECT(ClaireObject,v13492)->isa,Language._Super))
       Result = gc_usage_star_list(OBJECT(Super,v13492)->args,v11276);
      else if (INHERIT(OBJECT(ClaireObject,v13492)->isa,Language._Case))
       Result = gc_usage_star_list(OBJECT(Case,v13492)->args,v11276);
      else if (INHERIT(OBJECT(ClaireObject,v13492)->isa,Language._While))
       Result = gc_or_any(gc_usage_any(OBJECT(While,v13492)->arg,CTRUE),gc_usage_any(OBJECT(While,v13492)->test,v11276));
      else if (INHERIT(OBJECT(ClaireObject,v13492)->isa,Language._Return))
       Result = gc_usage_any(OBJECT(Return,v13492)->arg,v11276);
      else if (INHERIT(OBJECT(ClaireObject,v13492)->isa,Language._Handle))
       Result = gc_or_any(gc_usage_any(OBJECT(ClaireHandle,v13492)->arg,v11276),gc_usage_any(OBJECT(ClaireHandle,v13492)->other,v11276));
      else Result = Kernel.cfalse;
        } 
    else Result = Kernel.cfalse;
      return (Result);} 
  } 

OID  gc_or_any(OID v5136,OID v5137)
{ { OID Result = 0;
    if (v5136 == Kernel.cfalse)
     Result = v5137;
    else if (v5136 == Kernel.ctrue)
     { if (v5137 == Kernel.cfalse)
       Result = v5136;
      else Result = v5137;
        } 
    else if (INHERIT(OWNER(v5137),Kernel._integer))
     { if (equal(v5136,v5137) == CTRUE)
       Result = v5137;
      else Result = 1000;
        } 
    else Result = v5136;
      return (Result);} 
  } 

OID  gc_usage_star_list(list *v5124,ClaireBoolean *v11276)
{ { OID Result = 0;
    { OID  v5136 = Kernel.cfalse;
      { ITERATE(v5137);
        for (START(v5124); NEXT(v5137);)
        v5136= gc_or_any(v5136,gc_usage_any(v5137,v11276));
        } 
      Result = v5136;
      } 
    return (Result);} 
  } 

void  debug_intro_c_producer(Generate_c_producer *v5115,lambda *v13492,method *v5136)
{ GC_BIND;
  { module * v5125;
    { ClaireObject *V_CC ;
      if (Kernel._method == v5136->isa)
       V_CC = v5136->module_I;
      else V_CC = CFALSE;
        v5125= (module *) V_CC;} 
    Cint  v5126 = 1;
    princ_string(CSTRING("DB_BIND("));
    ident_thing(v5125);
    princ_string(CSTRING(","));
    expression_thing(v5136->selector,_oid_(Kernel.emptySet));
    princ_string(CSTRING(","));
    princ_integer(v13492->vars->length);
    princ_string(CSTRING(",{"));
    if ((v13492->vars->length == 1) && 
        ((*Kernel.range)((*(v13492->vars))[1]) == _oid_(Kernel._void)))
     princ_string(CSTRING("PUSH(_oid_(ClEnv));"));
    else { OID gc_local;
        ITERATE(v5138);
        for (START(v13492->vars); NEXT(v5138);)
        { princ_string(CSTRING("PUSH("));
          { OID  v5134 = (*(v5136->srange))[v5126];
            if (((v5134 == _oid_(Kernel._any)) && 
                  ((*Kernel.range)(v5138) != _oid_(Kernel._float))) || 
                (v5134 == _oid_(Kernel._integer)))
             (*Generate.expression)(v5138,
              Kernel.cfalse);
            else to_cl_c_producer(v5115,v5138,(((*Kernel.range)(v5138) == _oid_(Kernel._float)) ?
                Kernel._float :
                OBJECT(ClaireClass,v5134) ),Kernel.cfalse);
              } 
          princ_string(CSTRING(");"));
          ++v5126;
          } 
        } 
      princ_string(CSTRING("});"));
    breakline_void();
    princ_string(CSTRING(""));
    } 
  GC_UNBIND;} 

char * protect_result_c_producer(Generate_c_producer *v5115,ClaireClass *v5134,ClaireBoolean *v5628,OID v5136)
{ GC_BIND;
  if (Optimize.compiler->safety > 5)
   { (Optimize.OPT->protection = CFALSE);
    v5628= CFALSE;
    (Optimize.OPT->loop_gc = CFALSE);
    } 
  { char *Result ;
    { char * v11654 = ((v5134 != Kernel._void) ?
        ((v5628 == CTRUE) ?
          CSTRING("GC_UNBIND; return ") :
          CSTRING("return ") ) :
        ((v5628 == CTRUE) ?
          CSTRING("GC_UNBIND;") :
          CSTRING("") ) );
      ClaireObject * v5125;
      if (need_debug_ask_any(v5136) == CTRUE)
       v5125 = OBJECT(method,v5136)->module_I;
      else v5125 = CFALSE;
        if (INHERIT(v5125->isa,Kernel._module))
       { print_in_string_void();
        princ_string(CSTRING("DB_UNBIND("));
        ident_thing(((thing *) v5125));
        princ_string(CSTRING(","));
        (*Generate.expression)(GC_OID((*Kernel.selector)(v5136)),
          _oid_(Kernel.emptySet));
        princ_string(CSTRING(","));
        if (v5134 == Kernel._void)
         princ_string(CSTRING("CNULL"));
        else if ((v5134 == Kernel._any) || 
            (v5134 == Kernel._integer))
         princ_string(CSTRING("Result"));
        else to_cl_c_producer(v5115,GC_OID(_oid_(build_Variable_string(CSTRING("Result"),_oid_(v5134)))),v5134,Core.nil->value);
          princ_string(CSTRING(");"));
        breakline_void();
        princ_string(CSTRING("  "));
        princ_string(v11654);
        princ_string(CSTRING(""));
        Result = end_of_print_void();
        } 
      else Result = (((Optimize.OPT->profile_ask == CTRUE) && 
          ((Kernel._method == OWNER(v5136)) || 
              (v5136 == CNULL))) ?
        append_string(CSTRING("PRend(PR_x);"),v11654) :
        v11654 );
      } 
    GC_UNBIND; return (Result);} 
  } 

void  generate_function_start_c_producer(Generate_c_producer *v5115,lambda *v13492,ClaireClass *v5134,OID v5125,char *v8687)
{ GC_BIND;
  { OID  v15461;
    { if (v13492->vars->length != 0)
       v15461 = (*Kernel.range)(GC_OID((*(v13492->vars))[1]));
      else v15461 = _oid_(Kernel._any);
        GC_OID(v15461);} 
    ClaireFunction * v9289 = make_function_string(v8687);
    list * v11506 = GC_OBJECT(list,(((v13492->vars->length == 1) && 
        ((v15461 == _oid_(Kernel._environment)) || 
            (v15461 == _oid_(Kernel._void)))) ?
      Kernel.nil :
      v13492->vars ));
    update_function_entry_c_producer(v5115,v9289,v11506,v5134);
    use_as_output_port(Optimize.OPT->outfile);
    if (Kernel._method == OWNER(v5125))
     { if ((OBJECT(restriction,v5125)->range == Kernel._float) || 
          (OBJECT(restriction,v5125)->domain->memq(_oid_(Kernel._float)) == CTRUE))
       generate_float_function_c_producer(v5115,OBJECT(method,v5125),GC_STRING(string_I_function(v9289)));
      else if (INHERIT(OBJECT(restriction,v5125)->range->isa,Kernel._tuple))
       generate_tuple_function_c_producer(v5115,OBJECT(method,v5125),GC_STRING(string_I_function(v9289)));
      } 
    generate_regular_function_c_producer(v5115,
      v13492,
      v9289,
      v5134,
      v5125,
      v11506);
    } 
  GC_UNBIND;} 

void  generate_regular_function_c_producer(Generate_c_producer *v5115,lambda *v13492,ClaireFunction *v9289,ClaireClass *v5134,OID v5125,list *v11506)
{ GC_BIND;
  if (Optimize.compiler->naming != 2)
   { princ_string(CSTRING("\n/* The c++ function for: "));
    if (Kernel._method == OWNER(v5125))
     { print_any(_oid_(OBJECT(restriction,v5125)->selector));
      princ_string(CSTRING("("));
      ppvariable_list(GC_OBJECT(list,v13492->vars));
      princ_string(CSTRING(") ["));
      if (Optimize.compiler->naming == 1)
       bitvectorSum_integer(status_I_restriction(OBJECT(restriction,v5125)));
      princ_string(CSTRING("]"));
      } 
    else princ_string(string_I_function(v9289));
      princ_string(CSTRING(" */\n"));
    } 
  { interface_I_c_producer(v5115,v5134);
    princ_string(CSTRING(" "));
    c_princ_function(v9289);
    princ_string(CSTRING("("));
    typed_args_list_list(v11506);
    princ_string(CSTRING(")\n"));
    } 
  GC_UNBIND;} 

void  generate_float_function_c_producer(Generate_c_producer *v5115,method *v5125,char *v8687)
{ GC_BIND;
  { list * v11488 = (((v5125->domain->length == 1) && 
        (domain_I_restriction(v5125) == Kernel._void)) ?
      Kernel.nil :
      v5125->domain );
    Cint  v5126 = v11488->length;
    list * v11506;
    { { bag *v_list; OID v_val;
        OID v5136,CLcount;
        v_list = v11488;
         v11506 = v_list->clone();
        for (CLcount= 1; CLcount <= v_list->length; CLcount++)
        { v5136 = (*(v_list))[CLcount];
          { Variable * v14361 = ((Variable *) GC_OBJECT(Variable,new_object_class(Language._Variable)));
            (v14361->pname = gensym_void());
            { Variable * v2688 = v14361; 
              ClaireType * v2689;
              if (v5136 == _oid_(Kernel._float))
               v2689 = Kernel._any;
              else v2689 = OBJECT(ClaireType,v5136);
                (v2688->range = v2689);} 
            add_I_property(Kernel.instances,Language._Variable,11,_oid_(v14361));
            v_val = _oid_(v14361);
            } 
          
          (*((list *) v11506))[CLcount] = v_val;} 
        } 
      GC_OBJECT(list,v11506);} 
    char * v7248 = GC_STRING(append_string(v8687,CSTRING("_")));
    ClaireFunction * v9289 = make_function_string(v7248);
    lambda * v9668 = GC_OBJECT(lambda,lambda_I_list(v11506,Core.nil->value));
    ClaireClass * v5134 = ((v5125->range == Kernel._float) ?
      Kernel._any :
      psort_any(_oid_(v5125->range)) );
    generate_regular_function_c_producer(v5115,
      v9668,
      v9289,
      v5134,
      _oid_(v5125),
      v11506);
    GC_OBJECT(list,Optimize.OPT->functions)->addFast(_oid_(list::alloc(3,_oid_(v9289),
      _oid_(v11506),
      _oid_(v5134))));
    new_block_void();
    if (v5134 != Kernel._void)
     princ_string(CSTRING("return "));
    if (v5125->range == Kernel._float)
     princ_string(CSTRING("_float_("));
    c_princ_function(OBJECT(ClaireFunction,(*Optimize.functional_I)(_oid_(v5125))));
    princ_string(CSTRING("("));
    { Cint  v5121 = 1;
      Cint  v2687 = v5126;
      { OID gc_local;
        while ((v5121 <= v2687))
        { if (v5121 != 1)
           princ_string(CSTRING(","));
          if ((*(v5125->domain))[v5121] == _oid_(Kernel._float))
           { princ_string(CSTRING("float_v("));
            expression_Variable(OBJECT(Variable,(*(v11506))[v5121]),Core.nil->value);
            princ_string(CSTRING(")"));
            } 
          else expression_Variable(OBJECT(Variable,(*(v11506))[v5121]),Core.nil->value);
            ++v5121;
          } 
        } 
      } 
    princ_string(CSTRING(")"));
    if (v5125->range == Kernel._float)
     princ_string(CSTRING(")"));
    princ_string(CSTRING(";"));
    close_block_void();
    princ_string(CSTRING("\n"));
    } 
  GC_UNBIND;} 

void  at_c_producer(Generate_c_producer *v5115)
{ princ_string(CSTRING("->"));
  } 

void  generate_tuple_function_c_producer(Generate_c_producer *v5115,method *v5125,char *v8687)
{ GC_BIND;
  { list * v11488 = (((v5125->domain->length == 1) && 
        (domain_I_restriction(v5125) == Kernel._void)) ?
      Kernel.nil :
      v5125->domain );
    Cint  v5126 = v11488->length;
    list * v11506;
    { { bag *v_list; OID v_val;
        OID v5136,CLcount;
        v_list = v11488;
         v11506 = v_list->clone();
        for (CLcount= 1; CLcount <= v_list->length; CLcount++)
        { v5136 = (*(v_list))[CLcount];
          { Variable * v14361 = ((Variable *) GC_OBJECT(Variable,new_object_class(Language._Variable)));
            (v14361->pname = gensym_void());
            (v14361->range = OBJECT(ClaireType,v5136));
            add_I_property(Kernel.instances,Language._Variable,11,_oid_(v14361));
            v_val = _oid_(v14361);
            } 
          
          (*((list *) v11506))[CLcount] = v_val;} 
        } 
      GC_OBJECT(list,v11506);} 
    char * v7248 = GC_STRING(append_string(v8687,CSTRING("_")));
    ClaireFunction * v9289 = make_function_string(v7248);
    lambda * v9668 = GC_OBJECT(lambda,lambda_I_list(v11506,Core.nil->value));
    ClaireClass * v5134 = Kernel._tuple;
    generate_regular_function_c_producer(v5115,
      v9668,
      v9289,
      v5134,
      _oid_(v5125),
      v11506);
    GC_OBJECT(list,Optimize.OPT->functions)->addFast(_oid_(list::alloc(3,_oid_(v9289),
      _oid_(v11506),
      _oid_(v5134))));
    new_block_void();
    if (v5134 != Kernel._void)
     princ_string(CSTRING("return "));
    c_princ_function(OBJECT(ClaireFunction,(*Optimize.functional_I)(_oid_(v5125))));
    princ_string(CSTRING("("));
    { Cint  v5121 = 1;
      Cint  v2712 = v5126;
      { OID gc_local;
        while ((v5121 <= v2712))
        { if (v5121 != 1)
           princ_string(CSTRING(","));
          expression_Variable(OBJECT(Variable,(*(v11506))[v5121]),Core.nil->value);
          ++v5121;
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

OID  create_function_entry_c_producer(Generate_c_producer *v5115,lambda *v11486,char *v9289,OID v5125)
{ return (Core.nil->value);} 

OID  update_function_entry_c_producer(Generate_c_producer *v5115,ClaireFunction *v9289,list *v11506,ClaireClass *v5134)
{ GC_BIND;
  GC_OBJECT(list,Optimize.OPT->functions)->addFast(_oid_(list::alloc(3,_oid_(v9289),
    _oid_(v11506),
    _oid_(v5134))));
  { OID Result = 0;
    Result = Kernel.cfalse;
    GC_UNBIND; return (Result);} 
  } 

char * c_interface_class1_Generate(ClaireClass *v13492)
{ { char *Result ;
    { Cint  v5126 = index_list(OBJECT(Generate_producer,Generate.PRODUCER->value)->interfaces,_oid_(v13492));
      Result = ((v5126 == 0) ?
        CSTRING("OID *") :
        string_v((*(OBJECT(Generate_producer,Generate.PRODUCER->value)->interfaces))[(v5126+1)]) );
      } 
    return (Result);} 
  } 

void  c_interface_class2_Generate(ClaireClass *v13492,char *v5134)
{ GC_BIND;
  { Cint  v5126 = index_list(OBJECT(Generate_producer,Generate.PRODUCER->value)->interfaces,_oid_(v13492));
    if (v5126 == 0)
     (OBJECT(Generate_producer,Generate.PRODUCER->value)->interfaces = GC_OBJECT(list,GC_OBJECT(list,OBJECT(Generate_producer,Generate.PRODUCER->value)->interfaces)->addFast(_oid_(v13492)))->addFast(_string_(v5134)));
    else ((*(OBJECT(Generate_producer,Generate.PRODUCER->value)->interfaces))[(v5126+1)]=_string_(v5134));
      } 
  GC_UNBIND;} 

void  c_interface_method_Generate(method *v13492)
{ c_princ_string(string_v((*Optimize.function_name)(_oid_(v13492->selector),
    _oid_(v13492->domain),
    _oid_(v13492->functional))));
  } 

void  interface_I_c_producer(Generate_c_producer *v5115,ClaireClass *v13492)
{ if (v13492 == Kernel._void)
   princ_string(CSTRING("void "));
  else if (v13492 == Kernel._integer)
   princ_string(CSTRING("Cint "));
  else if ((v13492 == Kernel._function) || 
      ((v13492 == Kernel._char) || 
        (v13492 == Kernel._boolean)))
   { ident_c_producer(v5115,v13492->name);
    princ_string(CSTRING(" *"));
    } 
  else if ((INHERIT(v13492,Kernel._cl_import)) || 
      ((v13492 == Kernel._string) || 
        (v13492 == Kernel._array)))
   princ_string(string_v((*Optimize.c_interface)(_oid_(v13492))));
  else if (INHERIT(v13492,Kernel._object))
   { class_princ_c_producer(v5115,v13492);
    princ_string(CSTRING(" *"));
    } 
  else if (INHERIT(v13492,Kernel._bag))
   { ident_c_producer(v5115,v13492->name);
    princ_string(CSTRING(" *"));
    } 
  else if (v13492 == Kernel._float)
   princ_string(CSTRING("double "));
  else princ_string(CSTRING("OID "));
    } 

void  to_cl_c_producer(Generate_c_producer *v5115,OID v5136,ClaireClass *v5134,OID v11276)
{ if (v5134 == Kernel._void)
   { princ_string(CSTRING("_void_("));
    (*Generate.expression)(v5136,
      v11276);
    princ_string(CSTRING(")"));
    } 
  else if (INHERIT(v5134,Kernel._object))
   { if (v5136 == Kernel.ctrue)
     princ_string(CSTRING("Kernel.ctrue"));
    else if (v5136 == Kernel.cfalse)
     princ_string(CSTRING("Kernel.cfalse"));
    else { princ_string(CSTRING("_oid_("));
        (*Generate.expression)(v5136,
          v11276);
        princ_string(CSTRING(")"));
        } 
      } 
  else if (v5134 == Kernel._integer)
   { if (Optimize.compiler->safety > 1)
     (*Generate.expression)(v5136,
      v11276);
    else { princ_string(CSTRING("_integer_("));
        (*Generate.expression)(v5136,
          v11276);
        princ_string(CSTRING(")"));
        } 
      } 
  else if (v5134 == Kernel._char)
   { princ_string(CSTRING("_oid_("));
    (*Generate.expression)(v5136,
      v11276);
    princ_string(CSTRING(")"));
    } 
  else if (v5134 == Kernel._string)
   { princ_string(CSTRING("_string_("));
    (*Generate.expression)(v5136,
      v11276);
    princ_string(CSTRING(")"));
    } 
  else if (v5134 == Kernel._array)
   { princ_string(CSTRING("_array_("));
    (*Generate.expression)(v5136,
      v11276);
    princ_string(CSTRING(")"));
    } 
  else if (v5134 == Kernel._float)
   { princ_string(CSTRING("_float_("));
    (*Generate.expression)(v5136,
      v11276);
    princ_string(CSTRING(")"));
    } 
  else if (INHERIT(v5134,Kernel._cl_import))
   { princ_string(CSTRING("ClAlloc->import("));
    expression_any(_oid_(v5134),_oid_(Kernel.emptySet));
    princ_string(CSTRING(",(Cint *) "));
    (*Generate.expression)(v5136,
      v11276);
    princ_string(CSTRING(")"));
    } 
  else if (v5134 == Kernel._any)
   (*Generate.expression)(v5136,
    v11276);
  else close_exception(((general_error *) (*Core._general_error)(_string_(CSTRING("[internal] to_cl for a ~S is not implemented")),
      _oid_(list::alloc(1,_oid_(v5134))))));
    } 

void  to_c_c_producer1(Generate_c_producer *v5115,OID v5136,ClaireClass *v5134,OID v11276)
{ if (v5134 == Kernel._integer)
   (*Generate.expression)(v5136,
    v11276);
  else if (v5136 == CNULL)
   princ_string(CSTRING("NULL"));
  else if ((INHERIT(OWNER(v5136),Core._global_variable)) && 
      ((equal((*Kernel.range)(v5136),_oid_(Kernel.emptySet)) == CTRUE) && 
        (equal((*Kernel.value)(v5136),Core.nil->value) == CTRUE)))
   princ_string(CSTRING("Kernel.nil"));
  else { to_c_c_producer2(v5115,v5134);
      (*Generate.expression)(v5136,
        v11276);
      princ_string(CSTRING(")"));
      } 
    } 

void  to_c_c_producer2(Generate_c_producer *v5115,ClaireClass *v5134)
{ if (INHERIT(v5134,Kernel._object))
   { princ_string(CSTRING("OBJECT("));
    class_princ_class(v5134);
    princ_string(CSTRING(","));
    } 
  else if (v5134 == Kernel._float)
   princ_string(CSTRING("float_v("));
  else if (v5134 == Kernel._char)
   princ_string(CSTRING("char_v("));
  else if (v5134 == Kernel._string)
   princ_string(CSTRING("string_v("));
  else if (v5134 == Kernel._array)
   princ_string(CSTRING("array_v("));
  else if (INHERIT(v5134,Kernel._cl_import))
   { princ_string(CSTRING("EXPORT(("));
    interface_I_class(v5134);
    princ_string(CSTRING("),"));
    } 
  else close_exception(((general_error *) (*Core._general_error)(_string_(CSTRING("[internal] to_c for a ~S is not implemented")),
      _oid_(list::alloc(1,_oid_(v5134))))));
    } 

void  public_static_c_producer(Generate_c_producer *v5115)
{ ;} 

void  bool_exp_I_c_producer(Generate_c_producer *v5115,OID v13492,OID v11276)
{ if (INHERIT(OWNER(v13492),Optimize._to_CL))
   { princ_string(CSTRING("("));
    (*Optimize.bool_exp)(v13492,
      Kernel.ctrue,
      v11276);
    princ_string(CSTRING(" ? Kernel.ctrue : Kernel.cfalse)"));
    } 
  else { princ_string(CSTRING("("));
      (*Optimize.bool_exp)(v13492,
        Kernel.ctrue,
        v11276);
      princ_string(CSTRING(" ? CTRUE : CFALSE)"));
      } 
    } 

void  inherit_exp_c_producer(Generate_c_producer *v5115,OID v11096,OID v11098,OID v11276)
{ princ_string(CSTRING("INHERIT("));
  (*Generate.expression)(v11096,
    v11276);
  princ_string(CSTRING(","));
  (*Generate.expression)(v11098,
    v11276);
  princ_string(CSTRING(")"));
  } 

void  bitvector_exp_c_producer(Generate_c_producer *v5115,OID v11096,OID v11098,OID v11276)
{ princ_string(CSTRING("BCONTAIN("));
  (*Generate.expression)(v11096,
    v11276);
  princ_string(CSTRING(","));
  (*Generate.expression)(v11098,
    v11276);
  princ_string(CSTRING(")"));
  } 

void  equal_exp_c_producer(Generate_c_producer *v5115,OID v11096,ClaireBoolean *v15827,OID v11098,OID v9244)
{ if ((INHERIT(OWNER(v11096),Optimize._to_CL)) && 
      ((INHERIT(OWNER(v11098),Optimize._to_CL)) && 
        ((osort_any((*Language.set_arg)(v11096)) == osort_any((*Language.set_arg)(v11098))) && 
          ((identifiable_ask_any(GC_OID((*Kernel.arg)(v11096))) == CTRUE) || 
              ((identifiable_ask_any(GC_OID((*Kernel.arg)(v11098))) == CTRUE) || 
                (((*Language.set_arg)(v11096) == _oid_(Kernel._string)) || 
                  ((*Language.set_arg)(v11096) == _oid_(Kernel._float)))))))) 
  { equal_exp_c_producer(v5115,
      GC_OID((*Kernel.arg)(v11096)),
      v15827,
      GC_OID((*Kernel.arg)(v11098)),
      Kernel.ctrue);
     } 
  else{ if ((INHERIT(OWNER(v11096),Optimize._to_protect)) && 
        ((INHERIT(owner_any((*Kernel.arg)(v11096)),Optimize._to_CL)) && 
          (((*Optimize.c_gc_ask)(GC_OID((*Kernel.arg)(GC_OID((*Kernel.arg)(v11096))))) != Kernel.ctrue) && 
            ((INHERIT(OWNER(v11098),Optimize._to_protect)) && 
              ((INHERIT(owner_any((*Kernel.arg)(v11098)),Optimize._to_CL)) && 
                ((*Optimize.c_gc_ask)(GC_OID((*Kernel.arg)(GC_OID((*Kernel.arg)(v11098))))) != Kernel.ctrue)))))) 
    { equal_exp_c_producer(v5115,
        GC_OID((*Kernel.arg)(v11096)),
        v15827,
        GC_OID((*Kernel.arg)(v11098)),
        v9244);
       } 
    else{ GC_BIND;
      { ClaireBoolean * g0072I;
        { ClaireBoolean *v_and;
          { v_and = (((*Optimize.c_sort)(v11096) == _oid_(Kernel._string)) ? CTRUE : CFALSE);
            if (v_and == CFALSE) g0072I =CFALSE; 
            else { v_and = (((*Optimize.c_sort)(v11098) == _oid_(Kernel._string)) ? CTRUE : CFALSE);
              if (v_and == CFALSE) g0072I =CFALSE; 
              else { { OID  v6779;
                  if (INHERIT(OWNER(v11098),Optimize._to_C))
                   v6779 = ((OBJECT(Compile_to_C,v11098)->arg == CNULL) ? Kernel.ctrue : Kernel.cfalse);
                  else v6779 = Kernel.cfalse;
                    v_and = not_any(v6779);
                  } 
                if (v_and == CFALSE) g0072I =CFALSE; 
                else g0072I = CTRUE;} 
              } 
            } 
          } 
        
        if (g0072I == CTRUE) { princ_string(CSTRING("(equal_string("));
            (*Generate.expression)(v11096,
              Core.nil->value);
            princ_string(CSTRING(","));
            (*Generate.expression)(v11098,
              Core.nil->value);
            princ_string(CSTRING(") "));
            sign_equal_boolean(v15827);
            princ_string(CSTRING(" CTRUE)"));
            } 
          else if ((INHERIT(OWNER(v11096),Optimize._to_CL)) && 
            (((*Language.set_arg)(v11096) != _oid_(Kernel._integer)) && 
              (v11098 == CNULL)))
         { princ_string(CSTRING("("));
          (*Generate.expression)(GC_OID((*Kernel.arg)(v11096)),
            Core.nil->value);
          princ_string(CSTRING(" "));
          sign_equal_boolean(v15827);
          princ_string(CSTRING(" NULL)"));
          } 
        else if ((char_exp_ask_c_producer2(v5115,v11096) == CTRUE) || 
            (char_exp_ask_c_producer2(v5115,v11098) == CTRUE))
         { princ_string(CSTRING("("));
          char_exp_c_producer2(v5115,v11096,Core.nil->value);
          princ_string(CSTRING(" "));
          sign_equal_boolean(v15827);
          princ_string(CSTRING(" "));
          char_exp_c_producer2(v5115,v11098,Core.nil->value);
          princ_string(CSTRING(")"));
          } 
        else if ((boolean_I_any(v9244) == CTRUE) || 
            ((identifiable_ask_any(v11096) == CTRUE) || 
              ((identifiable_ask_any(v11098) == CTRUE) || 
                ((*Optimize.c_sort)(v11096) == _oid_(Kernel._float)))))
         { if (equal(_oid_(glb_class(stupid_t_any1(v11096),stupid_t_any1(v11098))),_oid_(Kernel.emptySet)) == CTRUE)
           { warn_void();
            tformat_string(CSTRING("~S = ~S will fail ! [263]"),2,list::alloc(2,v11096,v11098));
            } 
          princ_string(CSTRING("("));
          bexpression_any(v11096,Core.nil->value);
          princ_string(CSTRING(" "));
          sign_equal_boolean(v15827);
          princ_string(CSTRING(" "));
          bexpression_any(v11098,Core.nil->value);
          princ_string(CSTRING(")"));
          } 
        else { princ_string(CSTRING("(equal("));
            (*Generate.expression)(v11096,
              Core.nil->value);
            princ_string(CSTRING(","));
            (*Generate.expression)(v11098,
              Core.nil->value);
            princ_string(CSTRING(") "));
            sign_equal_boolean(v15827);
            princ_string(CSTRING(" CTRUE)"));
            } 
          } 
      GC_UNBIND;} 
    } 
  } 

ClaireBoolean * char_exp_ask_c_producer2(Generate_c_producer *v5115,OID v5136)
{ { ClaireBoolean *Result ;
    if (INHERIT(OWNER(v5136),Kernel._char))
     Result = CTRUE;
    else if (INHERIT(OWNER(v5136),Language._Call_method))
     { method * v5125 = OBJECT(Call_method,v5136)->arg;
      Result = ((_oid_(v5125) == Generate._starnth_1_string_star->value) ? CTRUE : (((_oid_(v5125) == Generate._starnth_string_star->value) && 
          (2 <= Optimize.compiler->safety)) ? CTRUE : CFALSE));
      } 
    else Result = CFALSE;
      return (Result);} 
  } 

void  char_exp_c_producer2(Generate_c_producer *v5115,OID v5136,OID v11276)
{ GC_BIND;
  if (INHERIT(OWNER(v5136),Kernel._char))
   { princ_string(CSTRING("'"));
    if ((v5136 == _oid_(_char_('\"'))) || 
        ((v5136 == _oid_(_char_('\''))) || 
          ((v5136 == _oid_(_char_('\?'))) || 
            (v5136 == _oid_(_char_('\\'))))))
     princ_string(CSTRING("\\"));
    princ_char(OBJECT(ClaireChar,v5136));
    princ_string(CSTRING("'"));
    } 
  else if (INHERIT(OWNER(v5136),Language._Call_method))
   { method * v5125 = OBJECT(Call_method,v5136)->arg;
    if ((_oid_(v5125) == Generate._starnth_1_string_star->value) || 
        (_oid_(v5125) == Generate._starnth_string_star->value))
     { OID  v11096 = (*(OBJECT(Call_method,v5136)->args))[1];
      OID  v11098 = (*(OBJECT(Call_method,v5136)->args))[2];
      (*Generate.expression)(v11096,
        v11276);
      princ_string(CSTRING("["));
      (*Generate.expression)(v11098,
        v11276);
      princ_string(CSTRING(" - 1]"));
      } 
    else { princ_string(CSTRING("((char) "));
        (*Generate.expression)(v5136,
          v11276);
        princ_string(CSTRING("->ascii)"));
        } 
      } 
  else { princ_string(CSTRING("((char) "));
      (*Generate.expression)(v5136,
        v11276);
      princ_string(CSTRING("->ascii)"));
      } 
    GC_UNBIND;} 

void  c_member_c_producer(Generate_c_producer *v5115,OID v13492,ClaireClass *v5134,property *v5136,OID v11276)
{ if (INHERIT(stupid_t_any1(v13492),v5134))
   { (*Generate.expression)(v13492,
      v11276);
    princ_string(CSTRING("->"));
    ident_symbol(v5136->name);
    princ_string(CSTRING(""));
    } 
  else { princ_string(CSTRING("CLREAD("));
      class_princ_class(v5134);
      princ_string(CSTRING(","));
      (*Generate.expression)(v13492,
        v11276);
      princ_string(CSTRING(","));
      ident_symbol(v5136->name);
      princ_string(CSTRING(")"));
      } 
    } 

void  addFast_c_producer(Generate_c_producer *v5115)
{ princ_string(CSTRING("->addFast"));
  } 

void  cast_I_c_producer(Generate_c_producer *v5115,Compile_C_cast *v13492,OID v11276)
{ GC_BIND;
  princ_string(CSTRING("(("));
  class_princ_class(v13492->set_arg);
  princ_string(CSTRING(" *) "));
  (*Generate.expression)(v13492->arg,
    v11276);
  princ_string(CSTRING(")"));
  GC_UNBIND;} 

void  gc_protection_exp_c_producer(Generate_c_producer *v5115,Variable *v5138,ClaireBoolean *v7978,OID v5135,OID v11276)
{ (v5115->stat = (v5115->stat+1));
  if ((osort_any(_oid_(v5138->range)) == Kernel._float) || 
      (osort_any(_oid_(v5138->range)) == Kernel._integer))
   { princ_string(CSTRING("("));
    ident_c_producer3(v5115,v5138);
    princ_string(CSTRING("="));
    if (v7978 == CTRUE)
     (*Generate.expression)(v5135,
      v11276);
    else c_princ_string(string_v(v5135));
      princ_string(CSTRING(")"));
    } 
  else { princ_string(CSTRING("GC__"));
      princ_string(((osort_any(_oid_(v5138->range)) == Kernel._any) ?
        CSTRING("OID") :
        ((osort_any(_oid_(v5138->range)) == Kernel._string) ?
          CSTRING("STRING") :
          CSTRING("ANY") ) ));
      princ_string(CSTRING("("));
      ident_c_producer3(v5115,v5138);
      if (v5135 != _oid_(v5138))
       { princ_string(CSTRING(" = "));
        if (v7978 == CTRUE)
         (*Generate.expression)(v5135,
          v11276);
        else c_princ_string(string_v(v5135));
          } 
      princ_string(CSTRING(", "));
      princ_integer(((Optimize.OPT->loop_index == 0) ?
        1 :
        (v5138->index+1) ));
      princ_string(CSTRING(")"));
      } 
    } 

void  bag_expression_c_producer(Generate_c_producer *v11229,ClaireClass *v5115,bag *v5124,ClaireType *v5133,OID v11276)
{ GC_BIND;
  if (v5124->length == 0)
   { print_any(_oid_(v5115));
    princ_string(CSTRING("::empty("));
    if (v5133 != Kernel._void)
     { (*Generate.expression)(GC_OID((*Optimize.c_code)(_oid_(v5133),
          _oid_(Kernel._object))),
        v11276);
      } 
    princ_string(CSTRING(")"));
    } 
  else { print_any(_oid_(v5115));
      princ_string(CSTRING("::alloc"));
      if ((v5115 == Kernel._tuple) && 
          (Optimize.OPT->alloc_stack == CTRUE))
       princ_string(CSTRING("Stack"));
      princ_string(CSTRING("("));
      if (v5133 != Kernel._void)
       { (*Generate.expression)(GC_OID((*Optimize.c_code)(_oid_(v5133),
            _oid_(Kernel._object))),
          v11276);
        princ_string(CSTRING(","));
        } 
      princ_integer(v5124->length);
      princ_string(CSTRING(","));
      args_list_bag(v5124,v11276,_sup_integer(v5124->length,2));
      princ_string(CSTRING(")"));
      } 
    GC_UNBIND;} 

void  generate_s_file_string(char *v13492,list *v5124,OID v5125)
{ GC_BIND;
  { ClairePort * v5128 = (fopen_string(append_string(GC_STRING(append_string(GC_STRING(_7_string(GC_STRING(Optimize.compiler->source),v13492)),CSTRING("-s"))),GC_STRING(OBJECT(Generate_producer,Generate.PRODUCER->value)->extension)),CSTRING("w")));
    list * v13080 = GC_OBJECT(list,add_modules_list(v5124));
    list * v12500 = GC_OBJECT(list,parents_list(v5124));
    (Optimize.OPT->cinterface = v5128);
    (Optimize.OPT->properties = set::empty(Kernel._property));
    (Optimize.OPT->objects = list::empty(Kernel._any));
    (Optimize.OPT->functions = list::empty(Kernel._any));
    (Optimize.OPT->need_to_close = set::empty(Kernel._any));
    (Optimize.OPT->legal_modules = set_I_bag(v12500));
    use_as_output_port(v5128);
    princ_string(CSTRING("// --- System configuration file for "));
    print_any(_string_(v13492));
    princ_string(CSTRING(" , ["));
    print_any(GC_OID(_string_(date_I_integer(1))));
    princ_string(CSTRING("] ---\n\n"));
    princ_string(CSTRING("#include <claire.h>\n"));
    princ_string(CSTRING("#include <Kernel.h>\n"));
    { ITERATE(v5136);
      for (START(v13080); NEXT(v5136);)
      if (OBJECT(module,v5136)->made_of->length != 0)
       { princ_string(CSTRING("#include <"));
        ident_symbol(OBJECT(symbol,(*Kernel.name)(v5136)));
        princ_string(CSTRING(".h>\n"));
        } 
      } 
    create_load_modules_string(v13492,v5128,v12500,v5125);
    if ((boolean_I_any(_oid_(_at_property1(Core.main,Kernel._list))) == CTRUE) && 
        (domain_I_restriction(((restriction *) _at_property1(Core.main,Kernel._list))) == Kernel._list))
     { char * v5134 = CSTRING("main_list");
      princ_string(CSTRING("\nextern void "));
      princ_string(v5134);
      princ_string(CSTRING("(list *l);\n"));
      princ_string(CSTRING("void call_main() {"));
      princ_string(v5134);
      princ_string(CSTRING("(ClEnv->params);}\n"));
      } 
    else princ_string(CSTRING("\nvoid call_main() {default_main();}\n"));
      fclose_port(v5128);
    } 
  GC_UNBIND;} 

void  create_load_modules_string(char *v13492,ClairePort *v5128,list *v12500,OID v5125)
{ GC_BIND;
  breakline_void();
  { OID gc_local;
    ITERATE(v5136);
    for (START(v12500); NEXT(v5136);)
    if ((*Kernel.status)(v5136) == 5)
     { princ_string(CSTRING("void load_"));
      ident_symbol(OBJECT(symbol,(*Kernel.name)(v5136)));
      princ_string(CSTRING("() {"));
      ident_symbol(OBJECT(symbol,(*Kernel.name)(v5136)));
      princ_string(CSTRING(".metaLoad();}\n"));
      } 
    } 
  princ_string(CSTRING("\n\nvoid loadModules() \n"));
  new_block_void();
  princ_string(CSTRING("//module definitions "));
  breakline_void();
  princ_string(CSTRING(""));
  { OID gc_local;
    ITERATE(v5136);
    bag *v5136_support;
    v5136_support = GC_OBJECT(set,_backslash_type(v12500,GC_OBJECT(set,set::alloc(Kernel.emptySet,3,_oid_(claire.it),
      _oid_(mClaire.it),
      _oid_(Kernel.it)))));
    for (START(v5136_support); NEXT(v5136);)
    { GC_LOOP;
      { ident_symbol(OBJECT(symbol,(*Kernel.name)(v5136)));
        princ_string(CSTRING(".initModule("));
        print_any(GC_OID(_string_(string_I_symbol(OBJECT(symbol,(*Kernel.name)(v5136))))));
        princ_string(CSTRING(","));
        expression_thing(OBJECT(module,v5136)->part_of,Core.nil->value);
        princ_string(CSTRING(","));
        (*Generate.expression)(GC_OID((*Optimize.c_code)(GC_OID(_oid_(OBJECT(module,v5136)->uses)),
            _oid_(Kernel._list))),
          Core.nil->value);
        princ_string(CSTRING(","));
        breakline_void();
        print_any(GC_OID((*Kernel.source)(v5136)));
        princ_string(CSTRING(","));
        (*Generate.expression)(GC_OID((*Optimize.c_code)(GC_OID(_oid_(OBJECT(module,v5136)->made_of)),
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
    ITERATE(v5136);
    for (START(v12500); NEXT(v5136);)
    if ((OBJECT(module,v5136)->made_of->length != 0) && 
        ((*Kernel.status)(v5136) != 5))
     { ident_symbol(OBJECT(symbol,(*Kernel.name)(v5136)));
      princ_string(CSTRING(".metaLoad();"));
      breakline_void();
      princ_string(CSTRING(""));
      } 
    } 
  { OID gc_local;
    ITERATE(v5136);
    for (START(v12500); NEXT(v5136);)
    { GC_LOOP;
      if ((*Kernel.status)(v5136) == 5)
       { ident_symbol(OBJECT(symbol,(*Kernel.name)(v5136)));
        princ_string(CSTRING(".it->evaluate = "));
        expression_any(_oid_(make_function_string(append_string(CSTRING("load_"),GC_STRING(string_I_symbol(OBJECT(symbol,(*Kernel.name)(v5136))))))),Kernel.cfalse);
        breakline_void();
        princ_string(CSTRING(""));
        ident_symbol(OBJECT(symbol,(*Kernel.name)(v5136)));
        princ_string(CSTRING(".it->status = 2;"));
        breakline_void();
        princ_string(CSTRING(""));
        } 
      GC_UNLOOP;} 
    } 
  princ_string(CSTRING("ClEnv->module_I = "));
  { OID  v8701;
    if (INHERIT(OWNER(v5125),Kernel._module))
     v8701 = v5125;
    else v8701 = _oid_(claire.it);
      (*Generate.expression)(v8701,
      Core.nil->value);
    } 
  princ_string(CSTRING("; "));
  breakline_void();
  princ_string(CSTRING(""));
  if (Optimize.compiler->safety > 5)
   princ_string(CSTRING("ClAlloc->statusGC = 2;\n"));
  if (Optimize.OPT->profile_ask == CTRUE)
   { OID gc_local;
    ITERATE(v5128);
    for (START(Reader.PRdependent->graph); NEXT(v5128);)
    { GC_LOOP;
      if (INHERIT(OWNER(v5128),Kernel._property))
       { OID gc_local;
        ITERATE(v11562);
        bag *v11562_support;
        v11562_support = GC_OBJECT(set,OBJECT(bag,nth_table1(Reader.PRdependent,v5128)));
        for (START(v11562_support); NEXT(v11562);)
        if ((contain_ask_set(Optimize.OPT->to_remove,v11562) != CTRUE) && 
            (OBJECT(thing,v5128)->name->definition == OBJECT(thing,v11562)->name->definition))
         { princ_string(CSTRING("PRdepends_property("));
          expression_thing(OBJECT(thing,v5128),Core.nil->value);
          princ_string(CSTRING(","));
          expression_thing(OBJECT(thing,v11562),Core.nil->value);
          princ_string(CSTRING(");\n"));
          } 
        } 
      GC_UNLOOP;} 
    } 
  close_block_void();
  GC_UNBIND;} 

void  methods_interface_c_producer(Generate_c_producer *v5115,ClaireClass *v5136)
{ GC_RESERVE(6);  // v3.0.55 optim !
  { OID gc_local;
    ITERATE(v5128);
    bag *v5128_support;
    v5128_support = GC_OBJECT(list,OBJECT(bag,nth_table1(Language.InterfaceList,_oid_(v5136))));
    for (START(v5128_support); NEXT(v5128);)
    { GC_LOOP;
      { ClaireObject * v5125 = GC_OBJECT(ClaireObject,_at_property1(OBJECT(property,v5128),v5136));
        if ((Kernel._method == v5125->isa) && 
            (get_property(Kernel.formula,v5125) != CNULL))
         { ClaireClass * v5134 = class_I_type(OBJECT(ClaireType,(*Kernel.range)(_oid_(v5125))));
          list * v2923 = GC_OBJECT(list,cdr_list(OBJECT(lambda,(*Kernel.formula)(_oid_(v5125)))->vars));
          breakline_void();
          interface_I_c_producer(v5115,v5134);
          princ_string(CSTRING(" "));
          (*Kernel.c_princ)(GC_OID((*Kernel.name)(v5128)));
          princ_string(CSTRING("("));
          typed_args_list_list(v2923);
          princ_string(CSTRING(");  "));
          } 
        } 
      GC_UNLOOP;} 
    } 
  GC_UNBIND;} 

void  methods_bodies_c_producer(Generate_c_producer *v5115,ClaireClass *v5136)
{ GC_RESERVE(6);  // v3.0.55 optim !
  { OID gc_local;
    ITERATE(v5128);
    bag *v5128_support;
    v5128_support = GC_OBJECT(list,OBJECT(bag,nth_table1(Language.InterfaceList,_oid_(v5136))));
    for (START(v5128_support); NEXT(v5128);)
    { GC_LOOP;
      { ClaireObject * v5125 = GC_OBJECT(ClaireObject,_at_property1(OBJECT(property,v5128),v5136));
        if ((Kernel._method == v5125->isa) && 
            (get_property(Kernel.formula,v5125) != CNULL))
         { ClaireClass * v5134 = class_I_type(OBJECT(ClaireType,(*Kernel.range)(_oid_(v5125))));
          list * v2923 = GC_OBJECT(list,cdr_list(OBJECT(lambda,(*Kernel.formula)(_oid_(v5125)))->vars));
          breakline_void();
          princ_string(CSTRING("// interface method "));
          breakline_void();
          princ_string(CSTRING(""));
          breakline_void();
          interface_I_c_producer(v5115,v5134);
          princ_string(CSTRING(" "));
          class_princ_class(v5136);
          princ_string(CSTRING("::"));
          (*Kernel.c_princ)(GC_OID((*Kernel.name)(v5128)));
          princ_string(CSTRING("("));
          typed_args_list_list(v2923);
          princ_string(CSTRING(")"));
          breakline_void();
          princ_string(CSTRING("  "));
          princ_string(CSTRING("\t{ "));
          if (v5134 != Kernel._void)
           { princ_string(CSTRING("return ("));
            interface_I_c_producer(v5115,v5134);
            princ_string(CSTRING(") "));
            } 
          if ((OBJECT(ClaireBoolean,(*Kernel._sup)(GC_OID((*Kernel.dispatcher)(v5128)),
            0))) == CTRUE)
           { (*Generate.expression)(v5128,
              Core.nil->value);
            princ_string(CSTRING("->fcall((Cint) this"));
            { OID gc_local;
              ITERATE(v5138);
              for (START(v2923); NEXT(v5138);)
              { princ_string(CSTRING(",(Cint) "));
                (*Generate.expression)(v5138,
                  Core.nil->value);
                } 
              } 
            princ_string(CSTRING(")"));
            } 
          else { c_princ_function(OBJECT(ClaireFunction,(*Optimize.functional_I)(_oid_(v5125))));
              princ_string(CSTRING("(this"));
              { OID gc_local;
                ITERATE(v5138);
                for (START(v2923); NEXT(v5138);)
                { princ_string(CSTRING(","));
                  (*Generate.expression)(v5138,
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

