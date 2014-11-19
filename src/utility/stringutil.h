#pragma once

// at least mingw 4.8 does not define std::to_string, so we need to define our own

#include <sstream>
#include <string>

namespace utility {
  template <typename T>
  std::string to_string(T value) {
    std::ostringstream stream;
    stream << value;
    return stream.str();
  }
}
