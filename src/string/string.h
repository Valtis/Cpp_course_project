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

    // returns the iterator to the beginning of the string
    iterator begin() const;

    // returns the iterator to the position after end of the string
    iterator end() const;

    // returns the length of string stored
    size_t length() const;

    // modification operators

    // swaps contents between two strings
    void swap(string &str);

    // appends string to the end of string. Equal to += operator
    void push_back(const string &string);

    // appends char to the end of string
    void push_back(char c);

    // removes char from the end of string and returns it
    char pop_back();

    // inserts text to position specified by start_position
    string &insert(const iterator start_position, const string &text);
    string &insert(const size_t start_position, const string &text);

    // erases characters between [start, end[ (start included, end not). Throws on invalid iterators
    // returns iterator to first character that wasn't erased (or iterator to end())
    iterator erase(const iterator start_position, const iterator end_position);

    // erases character from the position specified by the iterator. Throws on invalid iterator
    // returns iterator to first character that wasn't erased (or iterator to end())
    iterator erase(const iterator character);

    // erases n charaters from start position determined by length attribute. Length is truncated to  end of buffer if
    // it would go beyond it
    // returns string after erasion
    string &erase(const size_t start_position, const size_t length);

    // these are defined as free functions to allow implicit conversion for first parameter
    // so for example both "hello" == cs::string("hello") and cs::string("hello") == "hello" are possible

    // equality comparison
    friend bool operator==(const cs::string &lhs, const cs::string &rhs);

    // non-equality comparison
    friend bool operator!=(const cs::string &lhs, const cs::string &rhs);

    // appends rhs to the end of lhs
    friend cs::string operator+=(cs::string &lhs, const cs::string &rhs);

    // returns new string that contains lhs and rhs concatenated
    friend cs::string operator+(const cs::string &lhs, const cs::string &rhs);

    // these cannot be defined as free functions as that makes little sense

    // returns character at index. Throws on invalid index
    char &operator[](const size_t index);

    // replaces content of string with contents of rhs
    cs::string &operator=(cs::string rhs);

    // stream operators

    // copies content of the string to stream
    friend std::ostream &operator<<(std::ostream &output, const cs::string &string);

    // copies content of stream to string
    friend std::istream &operator>>(std::istream &input, cs::string &string);

  private:

    // new size will be new_length + 1 to account for possible edge case where growth might be just enough to hold new
    // string but no null termintor
    void increase_size_no_copy(size_t new_length);
    void increase_size(size_t new_length);

    // not entirely sure if strncpy and strlen can be used, so I implemented my own just to err on the side of caution
    void copy_string(const char *str, size_t length);
    size_t string_length(const char *str) const;

    // character buffer
    char *m_text;

    // length of text stored in buffer
    size_t m_text_length;

    // length of buffer
    size_t m_buffer_length;
  };
}
