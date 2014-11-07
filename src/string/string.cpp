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

size_t string::string_length(const char *str) const {
  size_t length = 0;

  while (str[length] != '\0') {
    ++length;
    assert(length < 1000000, "Possible unterminated string"); // sanity check - if length is this long, string was not likely null terminated
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

  assert(m_buffer_length > size, "Buffer size insufficient for copying");

  for (size_t i = 0; i < size; ++i) {
    m_text[i] = str[i];
  }

  m_text[size] = '\0';
  m_text_length = size;


  assert(string_length(m_text) == size, "Invalid string length after copy_string");
}


void string::increase_size_no_copy(size_t new_length) {
  new_length += 1;
  assert(new_length > m_buffer_length, "New length is shorter or equal to current length!");
  delete [] m_text;
  m_text = new char[new_length];
  m_buffer_length = new_length;
}

void string::increase_size(size_t new_length) {
  new_length += 1;

  assert(new_length > m_buffer_length, "New length is shorter or equal to current length!");

  char *new_buffer = new char[new_length];

  for (size_t i = 0; i < m_text_length; ++i) {
    new_buffer[i] = m_text[i];
    assert(i < m_buffer_length, "Buffer overflow!");
  }
  new_buffer[m_text_length] = '\0';

  delete [] m_text;

  m_text = new_buffer;
  m_buffer_length = new_length;
  assert(string_length(m_text) == m_text_length, "Invalid string length after increase_size");
}



bool operator==(const cs::string &lhs, const cs::string &rhs)  {

  if (lhs.length() != rhs.length()) {
    return false;
  }

  for (size_t i = 0; i < lhs.length(); ++i) {
    assert(i < lhs.m_buffer_length, "Buffer overflow, lhs");
    assert(i < rhs.m_buffer_length, "Buffer overflow, rhs");

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
  if (lhs.m_buffer_length  <= lhs.length() + rhs.length()) {
    lhs.increase_size((size_t)((lhs.m_buffer_length + rhs.length())*GROWTH_FACTOR));
  }

  assert(lhs.m_buffer_length > lhs.length() + rhs.length(), "Buffer size insufficient for copying");

  for (size_t i = 0; i < rhs.length() && i < lhs.m_buffer_length; ++i) {
    assert(i < lhs.m_buffer_length, "Buffer overflow!");
    lhs.m_text[lhs.length() + i] = rhs.m_text[i];
  }

  auto length = lhs.length() + rhs.length();
  assert(lhs.m_buffer_length > lhs.length(), "Invalid buffer length");
  lhs.m_text[length] = '\0';

  assert(lhs.string_length(lhs.m_text) == lhs.length() + rhs.length(), "Invalid string length after operator+=");
  lhs.m_text_length = length;

  return lhs;
}

string operator+(const cs::string &lhs, const cs::string &rhs) {
  cs::string new_string;
  new_string += lhs;
  new_string += rhs;

  assert(lhs.string_length(new_string.m_text) == lhs.length() + rhs.length(), "Invalid string length after operator+");
  return new_string;
}

std::ostream &operator<<(std::ostream &output, const cs::string &string) {
  output << string.m_text;
  return output;
}

std::istream &operator>>(std::istream &input, cs::string &string) {

  // get length first
  input.seekg (0, input.end);
  size_t length = input.tellg();
  input.seekg (0, input.beg);

  if (string.m_buffer_length <= length) {
    string.increase_size_no_copy((size_t)((string.m_buffer_length + length)*GROWTH_FACTOR));
  }

  assert(string.m_buffer_length > length, "Buffer size insufficient for operator>>!");


  input.read(string.m_text, length);
  string.m_text_length = length;

  assert(string.string_length(string.m_text) == length, "Invalid string length after operator>>");

  return input;
}


}
