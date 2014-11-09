#pragma once
#include <cstddef>
#include <iostream>

namespace cs {
  class string {
  public:
    string();
    string(const char *rhs);
    string(const string &rhs);

    ~string();

    // pointers are valid iterators
    typedef char * iterator;

    iterator begin() const;
    iterator end() const;

    size_t length() const;

    // modification operators
    void swap(string &str);

    void push_back(const string &string);
    void push_back(char c);

    char pop_back();

    string &insert(const iterator start_position, const string &text);
    string &insert(const size_t start_position, const string &text);

    iterator erase(const iterator start_position, const iterator end_position);
    iterator erase(const size_t start_position, const size_t length);

    // these are defined as free functions to allow implicit conversion for first parameter
    // so both "hello" == cs::string("hello") and cs::string("hello") == "hello" are possible
    friend bool operator==(const cs::string &lhs, const cs::string &rhs);
    friend bool operator!=(const cs::string &lhs, const cs::string &rhs);
    friend cs::string operator+=(cs::string &lhs, const cs::string &rhs);
    friend cs::string operator+(const cs::string &lhs, const cs::string &rhs);

    // these cannot be defined as free functions as that makes little sense
    char &operator[](const size_t index);
    cs::string &operator=(const cs::string &rhs);

    // stream operators
    friend std::ostream &operator<<(std::ostream &output, const cs::string &string);
    friend std::istream &operator>>(std::istream &input, cs::string &string);

  private:
    // not entirely sure if strcpy and strlen can be used, so I implemented my own just to err on the side of caution
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
