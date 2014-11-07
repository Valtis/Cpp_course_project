#pragma once
#include <cstddef>
#include <iostream>

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
    throw std::logic_error(std::string("Assertion failure at file ") + __FILE__ + " at line " + utility::to_string(__LINE__) + ":\n" + msg); \
  }\
}
#else
#define assert(x, msg)
#endif

namespace cs {
  class string {
  public:
    string();
    string(const char *rhs);
    string(const string &rhs);

    ~string();

    size_t length() const;

    friend bool operator==(const cs::string &lhs, const cs::string &rhs);
    friend bool operator!=(const cs::string &lhs, const cs::string &rhs);
    friend cs::string operator+=(cs::string &lhs, const cs::string &rhs);
    friend cs::string operator+(const cs::string &lhs, const cs::string &rhs);

    char &operator[](const size_t index);

    friend std::ostream &operator<<(std::ostream &output, const cs::string &string);
    friend std::istream &operator>>(std::istream &input, cs::string &string);

  private:
    void copy_string(const char *str, size_t length);
    size_t string_length(const char *str) const;


    // new size will be new_length + 1 to account for possible edge case where growth might be just enough to hold new
    // string but no null termintor
    void increase_size_no_copy(size_t new_length);
    void increase_size(size_t new_length);
    char *m_text;

    size_t m_text_length;
    size_t m_buffer_length;
  };
}
