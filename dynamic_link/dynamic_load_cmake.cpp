#include <cstdio>
#include <dlfcn.h>

extern "C" void goodbye( const char* text ) {
  void* lib = dlopen("./libhello.dylib", RTLD_LAZY);
  dlclose(lib);
  printf("Goodbye, %s\n", text);
}
