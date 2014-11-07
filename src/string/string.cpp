#include "string.h"
namespace cs {

string::string() : m_text(nullptr), m_length(0) {
  m_text = new char[1];
  m_text[0] = '\0';
}

string::string(const char *rhs) : m_text(nullptr), m_length(0) {
  copy_string(rhs, string_length(rhs));
}

string::string(const string &rhs) : m_text(nullptr), m_length(0) {
  copy_string(rhs.m_text, rhs.m_length);
}

string::~string() {
  delete [] m_text;
}


size_t string::length() const {
  return m_length;
}

void string::copy_string(const char *str, size_t size) {

  if (m_length <= size) {
    increase_size_no_copy(size);
  }

  for (size_t i = 0; i < size; ++i) {
    m_text[i] = str[i];
  }

  m_text[size] = '\0';
}

size_t string::string_length(const char *str) {
  size_t length = 0;

  while (str[length] != '\0') {
    ++length;
  }

  return length;
}


void string::increase_size_no_copy(size_t text_length) {
  delete [] m_text;
  m_text = new char[text_length + 1];
  m_length = text_length;
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

}
