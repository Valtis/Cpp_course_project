#pragma once

#ifdef assert
undef assert
#endif


#ifndef NDEBUG
#include <stdexcept>
#include <string>
#include "../utility/stringutil.h"
#define assert(cond, msg) \
{ \
  if (!(cond)) {\
    throw std::logic_error(std::string("Assert failure at file ") + __FILE__ + " at line " + utility::to_string(__LINE__) + ":\n" + msg); \
  }\
}
#else
#define assert(x, msg)
#endif
