#include "string.h"
namespace cs {

const float GROWTH_FACTOR = 1.5;

string::string() : m_text(nullptr), m_text_length(0), m_buffer_length(0) {
  m_text = new char[1];
  m_text[0] = '\0';
}

string::string(const char *rhs) : m_text(nullptr), m_text_length(0), m_buffer_length(0) {
  copy_string(rhs, string_length(rhs));
}

string::string(const string &rhs) : m_text(nullptr), m_text_length(0), m_buffer_length(0) {
  copy_string(rhs.m_text, rhs.m_text_length);
}

string::~string() {
  delete [] m_text;
}

size_t string::string_length(const char *str) {
  size_t length = 0;

  while (str[length] != '\0') {
    ++length;
  }

  return length;
}


size_t string::length() const {
  return m_text_length;
}

void string::copy_string(const char *str, size_t size) {

  if (m_buffer_length <= size) {
    increase_size_no_copy((size_t)(size*GROWTH_FACTOR));
  }

  for (size_t i = 0; i < size; ++i) {
    m_text[i] = str[i];
  }

  m_text[size] = '\0';
  m_text_length = size;
}


void string::increase_size_no_copy(size_t new_length) {
  delete [] m_text;
  m_text = new char[new_length + 1];
  m_buffer_length = new_length;
}

void string::increase_size(size_t new_length) {
  char *new_buffer = new char[new_length + 1];

  for (size_t i = 0; i < m_text_length; ++i) {
    new_buffer[i] = m_text[i];
  }
  new_buffer[m_text_length] = '\0';

  delete [] m_text;

  m_text = new_buffer;
  m_buffer_length = new_length;
}



bool operator==(const cs::string &lhs, const cs::string &rhs)  {

  if (lhs.length() != rhs.length()) {
    return false;
  }

  for (size_t i = 0; i < lhs.length(); ++i) {
    if (lhs.m_text[i] != rhs.m_text[i]) {
      return false;
    }
  }

  return true;
}

bool operator!=(const cs::string &lhs, const cs::string &rhs)  {
  return !(lhs == rhs);
}

string operator+=(cs::string &lhs, const cs::string &rhs) {
  if (lhs.m_buffer_length <= rhs.length()) {
    lhs.increase_size((size_t)((lhs.m_buffer_length + rhs.length())*GROWTH_FACTOR));
  }

  for (size_t i = 0; i < rhs.length(); ++i) {
    lhs.m_text[lhs.length() + i] = rhs.m_text[i];
  }

  lhs.m_text_length = lhs.length() + rhs.length();
  lhs.m_text[lhs.length()] = '\0';
  return lhs;
}

string operator+(const cs::string &lhs, const cs::string &rhs) {
  cs::string new_string;
  new_string += lhs;
  new_string +=rhs;
  return new_string;
}

std::ostream &operator<<(std::ostream &output, const cs::string &string) {
  output << string.m_text;

  return output;
}

}
