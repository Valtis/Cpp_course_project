#include "string_test.h"
#include "testrunner/test.h"
#include "../string/string.h"
#include <string>
#include <sstream>

void new_string_length_is_zero() {
  cs::string str;
  ASSERT_EQUALS(0u, str.length());
}

void new_string_equals_to_empty_string() {
  cs::string str;
  ASSERT_TRUE(str == "");
}

void string_is_correctly_initialized_with_c_string() {
  cs::string str("hello_world");
  ASSERT_TRUE(str == "hello_world");
}

void string_length_is_correct_when_initialized_with_c_string() {
  cs::string str("hello_world");
  ASSERT_EQUALS(11u, str.length());
}

void string_is_correctly_initialized_with_string() {
  cs::string str("hello_world");
  cs::string new_str(str);

  ASSERT_TRUE(new_str == "hello_world");
}


void string_length_is_correct_when_initialized_with_string() {
  cs::string str("hello_world");
  cs::string new_str(str);

  ASSERT_EQUALS(11u, new_str.length());
}

void string_equality_operator_returns_true_when_comparing_to_same_c_string() {
  cs::string str("hello_world");

  ASSERT_TRUE(str == "hello_world");
  ASSERT_TRUE("hello_world" == str);

}

void string_equality_operator_returns_false_when_comparing_to_different_c_string() {
  cs::string str("hello_world");
  ASSERT_FALSE("text" == str);
  ASSERT_FALSE(str == "text");
}

void string_equality_operator_returns_false_when_comparing_to_different_c_string_with_same_length() {
  cs::string str("hello_world");
  ASSERT_FALSE("hello world" == str);
  ASSERT_FALSE(str == "text");
}

void string_equality_operator_returns_true_when_comparing_to_same_string() {
  cs::string str("hello_world");
  cs::string str2("hello_world");

  ASSERT_TRUE(str == str2);
}

void string_equality_operator_returns_false_when_comparing_to_different_string() {
  cs::string str("hello_world");
  cs::string str2("ads");

  ASSERT_FALSE(str == str2);
}

void string_equality_operator_returns_false_when_comparing_to_different_string_with_same_length() {
  cs::string str("hello_world");
  cs::string str2("hello world");

  ASSERT_FALSE(str == str2);
}

void string_equality_operator_returns_true_when_comparing_to_self() {
  cs::string str("hello_world");
  ASSERT_TRUE(str == str);
}

void string_non_equality_operator_returns_true_with_c_string() {
  cs::string str("foobar");
  ASSERT_TRUE(str != "hello");
  ASSERT_TRUE("hello" != str);
}

void string_non_equality_operator_returns_false_with_c_string() {
  cs::string str("foobar");
  ASSERT_FALSE(str != "foobar");
  ASSERT_FALSE("foobar" != str);
}

void string_non_equality_operator_returns_true_with_string() {
  cs::string str("foobar");
  cs::string str2("hello!");
  ASSERT_TRUE(str != str2);
}

void string_non_equality_operator_returns_false_with_string() {
  cs::string str("foobar");
  cs::string str2("foobar");
  ASSERT_FALSE(str != str2);
}

void string_concatenation_works_with_c_string() {
  cs::string str("hello ");
  cs::string str2("world");
  ASSERT_EQUALS(cs::string("hello world"), str + "world");
  ASSERT_EQUALS(cs::string("hello world"), "hello " + str2);
}

void string_concatenation_works_with_string() {
  cs::string str("hello ");
  cs::string str2("world");

  ASSERT_EQUALS(cs::string("hello world"), str + str2);
}

void string_length_is_correct_after_concatenation() {
  cs::string str("hello ");
  ASSERT_EQUALS(11u, (str + "world").length());
}

void string_sum_assignment_operator_works_with_c_string() {
  cs::string str("hello ");
  str += "world";
  ASSERT_EQUALS(cs::string("hello world"), str);
}

void string_sum_assignment_operator_works_with_string() {
  cs::string str("hello ");
  cs::string str2("world");
  str += str2;
  ASSERT_EQUALS(cs::string("hello world"), str);
}

void string_sum_assignment_operator_returns_correct_string() {
  cs::string str("hello ");
  ASSERT_EQUALS(cs::string("hello world"), (str += "world"));
}


void string_length_is_correct_after_sum_assignment() {
  cs::string str("hello ");
  str += "world";

  ASSERT_EQUALS(11u, str.length());
}


void string_output_stream_operator_works() {
  cs::string str("hello");
  std::ostringstream stream;
  stream << "This is "<< str << " world!";
  ASSERT_EQUALS(std::string("This is hello world!"), stream.str());
}

void string_input_stream_operator_works() {
  cs::string str;
  std::istringstream input("this is an input test!");
  input >> str;
  ASSERT_EQUALS(cs::string("this is an input test!"), str);
}

void string_has_correct_length_after_input_stream() {
  cs::string str;
  std::istringstream input("this is an input test!");
  input >> str;
  ASSERT_EQUALS(22u, str.length());
}


void string_array_operator_gives_correct_letter_from_beginning() {
  cs::string str("teststring");
  ASSERT_EQUALS('t', str[0]);
}

void string_array_operator_gives_correct_letter_from_middle() {
  cs::string str("teststring");
  ASSERT_EQUALS('r', str[6]);
}

void string_array_operator_gives_correct_letter_from_end() {
  cs::string str("teststring");
  ASSERT_EQUALS('g', str[9]);
}

void string_array_operator_throws_with_access_beyond_text_length() {
  cs::string str("teststring");
  ASSERT_THROWS(str[10], std::out_of_range);
}

void string_array_operator_throws_with_negative_index() {
  cs::string str("teststring");
  ASSERT_THROWS(str[-1], std::out_of_range);
}
