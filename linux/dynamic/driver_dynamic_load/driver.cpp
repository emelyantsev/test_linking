
//#include "../lib_mylib/lib_mylib.h" 

#include <dlfcn.h>
#include <iostream>

int main()  
{ 

  typedef void (*p_func)();
  p_func func;

  void *dl_handle;
  

  char *error;

  dl_handle = dlopen( "/home/aleksey/Coding/test_linking/dynamic/lib_mylib/lib_mylib.so", RTLD_LAZY );

  if (!dl_handle) {
    
    std::cout << "!!! " << dlerror() << std::endl; 
    return -1;
  }


  func = reinterpret_cast<p_func>( dlsym( dl_handle, "_Z3funv" ) );
  
  error = dlerror();

  if (error != nullptr) {

    std::cout << "!!! "  << error << std::endl;

    return -1;
  }

  func(); 

  dlclose(dl_handle);

  return 0;
} 