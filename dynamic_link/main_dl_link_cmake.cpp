#include <dlfcn.h>

#include "hello.hpp"

extern "C" typedef void (*hello_t)( const char* text );

int main() {

  void* lib = dlopen("./libhello.dylib", RTLD_LAZY);
  hello_t hello_func = (hello_t)dlsym( lib, "hello" );
  hello_func("World!");
  dlclose(lib);

  hello("World2!");
}
