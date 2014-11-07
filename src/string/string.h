#pragma once
#include <cstddef>

namespace cs {
  class string {
  public:
    string();
    string(const char *rhs);
    string(const string &rhs);

    ~string();

    size_t length() const;

    friend bool operator==(const cs::string &lhs, const cs::string &rhs);

  private:
    void copy_string(const char *str, size_t length);
    size_t string_length(const char *str);


    // new size will be text_length + 1
    void increase_size_no_copy(size_t text_length);

    char *m_text;
    size_t m_length;
  };
}
