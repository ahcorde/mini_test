#include "hello.hpp"

#include <cstdio>
#include <iostream>

namespace ignition
{
  namespace plugin
  {
    namespace
    {
      struct ExecuteWhenLoadingLibrary
      {
        ExecuteWhenLoadingLibrary()
        {
          std::cerr << "ExecuteWhenLoadingLibrary:" << std::endl;
        }
      };
    } /* namespace */
    static ignition::plugin::ExecuteWhenLoadingLibrary execute;
  }
}

#ifdef __cplusplus
extern "C"
{
#endif
void hello( const char* text ) {
  printf("Hello, %s\n", text);
}
#ifdef __cplusplus
} // extern "C"
#endif
