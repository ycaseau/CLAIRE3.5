// --- System configuration file for "cclaire" , ["Thu Jul 07 06:47:12 2016\n"] ---

#include <claire.h>
#include <Kernel.h>
#include <Core.h>
#include <Language.h>
#include <Reader.h>
#include <Optimize.h>
#include <Generate.h>



void loadModules() 
{ //module definitions 
  Core.initModule("Core",mClaire.it,list::alloc(Kernel.emptySet,1,_oid_(Kernel.it)),
  "e:\\claire\\v3.5\\src\\meta",list::alloc(Kernel.emptySet,4,_string_(CSTRING("method")),
    _string_(CSTRING("object")),
    _string_(CSTRING("function")),
    _string_(CSTRING("types"))));
  iClaire.initModule("iClaire",claire.it,list::alloc(Kernel.emptySet,1,_oid_(mClaire.it)),
  "",Kernel.nil);
  Language.initModule("Language",iClaire.it,list::alloc(Kernel.emptySet,2,_oid_(Kernel.it),_oid_(Core.it)),
  "e:\\claire\\v3.5\\src\\meta",list::alloc(Kernel.emptySet,4,_string_(CSTRING("pretty")),
    _string_(CSTRING("call")),
    _string_(CSTRING("control")),
    _string_(CSTRING("define"))));
  Reader.initModule("Reader",iClaire.it,list::alloc(Kernel.emptySet,3,_oid_(Kernel.it),
    _oid_(Core.it),
    _oid_(Language.it)),
  "e:\\claire\\v3.5\\src\\meta",list::alloc(Kernel.emptySet,4,_string_(CSTRING("read")),
    _string_(CSTRING("syntax")),
    _string_(CSTRING("file")),
    _string_(CSTRING("inspect"))));
  Compile.initModule("Compile",iClaire.it,list::alloc(Kernel._module,1,_oid_(mClaire.it)),
  "",list::empty(Kernel._string));
  Optimize.initModule("Optimize",Compile.it,list::alloc(Kernel._module,2,_oid_(Reader.it),_oid_(mClaire.it)),
  "e:\\claire\\v3.5\\src\\compile",list::alloc(Kernel._string,5,_string_(CSTRING("osystem")),
    _string_(CSTRING("otool")),
    _string_(CSTRING("ocall")),
    _string_(CSTRING("ocontrol")),
    _string_(CSTRING("odefine"))));
  Generate.initModule("Generate",Compile.it,list::alloc(Kernel._module,2,_oid_(Optimize.it),_oid_(mClaire.it)),
  "e:\\claire\\v3.5\\src\\compile",list::alloc(Kernel._string,5,_string_(CSTRING("gsystem")),
    _string_(CSTRING("gexp")),
    _string_(CSTRING("gstat")),
    _string_(CSTRING("cgen")),
    _string_(CSTRING("copt"))));
  //module load 
  Core.metaLoad();
  Language.metaLoad();
  Reader.metaLoad();
  Optimize.metaLoad();
  Generate.metaLoad();
  ClEnv->module_I = claire.it; 
  } 

extern void main_list(list *l);
void call_main() {main_list(ClEnv->params);}
