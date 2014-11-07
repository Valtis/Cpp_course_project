#include "string_test.h"
#include "testrunner/test.h"
#include "../string/string.h"

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
