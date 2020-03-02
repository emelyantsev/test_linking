

#include <iostream>
#include "windows.h"


int main()  
{ 

  typedef void (*p_func_type)();
  p_func_type func;

  HINSTANCE hDLL;   


  hDLL = LoadLibrary("../lib_mylib/myLib.dll");

  if (hDLL == nullptr) {
    std::cerr << "Failed to load dll" << std::endl;
    return -1;
  }

  func = (p_func_type) GetProcAddress(hDLL, "?fun@@YAXXZ");


  if (!func) {

      FreeLibrary(hDLL);
      return -1;
  }
  else {
    
      func();
  }

  FreeLibrary(hDLL);

  return 0;
} 