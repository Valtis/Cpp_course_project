#include "string.h"
#include "assert.h"
#include <stdexcept>

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

// returns the iterator to the beginning of the string
string::iterator string::begin() const {
    return m_text;
}

// returns the iterator to the position after end of the string
string::iterator string::end() const {
  return m_text + m_text_length;
}

// returns the length of string stored
size_t string::length() const {
  return m_text_length;
}

// swaps contents between two strings
void string::swap(string &str) {
  size_t text_length = m_text_length;
  size_t buffer_length = m_buffer_length;
  char *text = m_text;

  m_text_length = str.m_text_length;
  m_buffer_length = str.m_buffer_length;
  m_text = str.m_text;

  str.m_text_length = text_length;
  str.m_buffer_length = buffer_length;
  str.m_text = text;
}

// appends string to the end of string. Equal to += operator
void string::push_back(const string &string) {
  (*this) += string;
}


// appends char to the end of string
void string::push_back(char c) {
  if (m_buffer_length <= m_text_length + 1) {
    increase_size(m_text_length + 1);
  }

  assert(m_buffer_length > m_text_length + 1, "Buffer size insufficient for push_back(char)");

  m_text[m_text_length] = c;
  m_text[m_text_length + 1] = c;
  ++m_text_length;
}

// removes char from the end of string and returns it
char string::pop_back() {
  if (m_text_length == 0) {
    throw std::out_of_range("Attempting to pop empty string");
  }

  --m_text_length;
  char c = m_text[m_text_length];
  m_text[m_text_length] = '\0';

  return c;
}

// inserts text to position specified by start_position
string &string::insert(const string::iterator start_position, const string &text) {
  if (start_position < m_text || start_position > m_text + m_text_length) {
    throw std::out_of_range("Attempting to insert text outside text buffer");
  }

  const size_t total_length = text.length() + m_text_length;

  // we have to allocate new buffer, since growing old buffer (-> allocating larger one)
  // invalidates iterators (as iterator is merely pointer to old buffer that has been deallocated)
  char *new_buffer = new char[total_length + 1];

  new_buffer[total_length] = '\0';

  // copy start of the orignal string to buffer
  int pos = 0;
  for (auto iter = begin(); iter != start_position; ++iter) {
    new_buffer[pos++] = *iter;
  }

  // do insertion
  for (size_t i = 0; i < text.length(); ++i) {
    new_buffer[pos++] = text.m_text[i];
  }

  // and copy rest of the original string
  for (size_t i = 0; start_position + i != end(); ++i)  {
    new_buffer[pos++] = *(start_position + i);
  }

  delete [] m_text;
  m_text = new_buffer;

  m_text_length = total_length;
  m_buffer_length = total_length;

  assert(string_length(m_text) == total_length, "Invalid text buffer length after insertion");
  return *this;
}

// inserts text to position specified by start_position
string &string::insert(const size_t start_position, const string &text) {
  return insert(begin() + start_position, text);
}

// erases characters between [start, end[ (start included, end not). Throws on invalid iterators
string::iterator string::erase(const string::iterator start_position, const string::iterator end_position) {
  if (start_position < begin() || end_position > end() || start_position >= end() || start_position > end_position) {
    throw std::out_of_range("Invalid iterators given to erase()");
  }

  if (start_position != end_position) {

    // copy the end of string to positions starting from start_position
    for (size_t i = 0; end_position + i < end(); ++i) {

      assert(start_position + i < end(), "Buffer overflow with writing!");
      assert(end_position + i < end(), "Buffer overflow with reading!");
      *(start_position + i) = *(end_position + i);
    }


    m_text_length -= (end_position - start_position);

    m_text[m_text_length] = '\0';

    assert(string_length(m_text) == m_text_length,
      "Invalid string length after erasion: Expected " + utility::to_string(m_text_length) + " but was "
      + utility::to_string(string_length(m_text)));


  }

  return start_position;
}

// erases character from the position specified by the iterator. Throws on invalid iterator
string::iterator string::erase(const string::iterator character) {
  return erase(character, character + 1);
}

// erases n charaters from start position determined by length attribute. Length is truncated to max end of buffer
// returns string after erasion
string &string::erase(const size_t start_position, const size_t length) {
  erase(begin() + start_position, std::min(end(), begin() + start_position + length));
  return *this;
}

// operator overloads

// returns true if contents are equal, false otherwise
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

// returns true if contents are different, false otherwise
bool operator!=(const cs::string &lhs, const cs::string &rhs)  {
  return !(lhs == rhs);
}

// appends content of rhs to the end of lhs
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

// concatenation operator. Returns new string which is concatenation between the two parameters.
string operator+(const cs::string &lhs, const cs::string &rhs) {
  cs::string new_string;
  new_string += lhs;
  new_string += rhs;

  assert(lhs.string_length(new_string.m_text) == lhs.length() + rhs.length(), "Invalid string length after operator+");
  return new_string;
}


// << operator. Writes content of buffer to stream
std::ostream &operator<<(std::ostream &output, const cs::string &string) {
  output << string.m_text;
  return output;
}

// >> operator. copies content of stream to buffer
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
  string.m_text[length] = '\0';

  assert(string.string_length(string.m_text) == length, "Invalid string length after operator>>");

  return input;
}

// [] operator. return character pointed by index or throws std::out_of_range if index is invalid
char &cs::string::operator[](const size_t index) {
  if (index >= m_text_length) {
    throw std::out_of_range("Array index out of range: " + index);
  }

  return m_text[index];
}

// assignment operator. Copies content of rhs to this string
cs::string &cs::string::operator=(cs::string rhs) {
  swap(rhs);
  return *this;
}

// helper functions

// increases buffer size but does not copy old buffer to it; optimization in case buffer would be overwritten anyway
void string::increase_size_no_copy(size_t new_length) {
  new_length += 1;
  assert(new_length > m_buffer_length, "New length is shorter or equal to current length!");
  delete [] m_text;
  m_text = new char[new_length];
  m_buffer_length = new_length;
}

// increases buffer size and copies the old buffer to it
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


// basically strncpy
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

// basically strlen
size_t string::string_length(const char *str) const {
  size_t length = 0;

  while (str[length] != '\0') {
    ++length;
    assert(length < 1000000, "Possible unterminated string"); // sanity check - if length is this long, string was not likely null terminated
  }

  return length;
}


}
