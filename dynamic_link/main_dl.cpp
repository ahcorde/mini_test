#include <dlfcn.h>

extern "C" typedef void (*hello_t)( const char* text );
extern "C" typedef void (*goobye_t)( const char* text );

int main() {
  void* lib2 = dlopen("./libdynamic_load_cmake.dylib", RTLD_LAZY);
  goobye_t goobye = (goobye_t)dlsym(lib2, "goodbye");
  goobye("goobye!");

  void* lib = dlopen("./libhello.dylib", RTLD_LAZY);
  hello_t hello = (hello_t)dlsym(lib, "hello");
  hello("World!");

  dlclose(lib);
  dlclose(lib2);
}
