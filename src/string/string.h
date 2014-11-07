#pragma once
#include <cstddef>
#include <ostream>

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

    friend std::ostream &operator<<(std::ostream &output, const cs::string &string);


  private:
    void copy_string(const char *str, size_t length);
    size_t string_length(const char *str);


    // new size will be new_length + 1 to account for possible edge case where growth might be just enough to hold new
    // string but no null termintor
    void increase_size_no_copy(size_t new_length);
    void increase_size(size_t new_length);
    char *m_text;

    size_t m_text_length;
    size_t m_buffer_length;
  };
}
