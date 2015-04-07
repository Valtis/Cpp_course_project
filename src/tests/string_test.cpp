#include "string_test.h"
#include "testrunner/test.h"
#include "../string/string.h"
#include <string>
#include <sstream>
#include <algorithm>


TEST(new_string_length_is_zero) {
  cs::string str;
  ASSERT_EQUALS((size_t)0, str.length());
}

TEST(new_string_equals_to_empty_string) {
  cs::string str;
  ASSERT_TRUE(str == "");
}

TEST(string_is_correctly_initialized_with_c_string) {
  cs::string str("hello_world");
  ASSERT_TRUE(str == "hello_world");
}

TEST(string_length_is_correct_when_initialized_with_c_string) {
  cs::string str("hello_world");
  ASSERT_EQUALS((size_t)11, str.length());
}

TEST(string_is_correctly_initialized_with_string) {
  cs::string str("hello_world");
  cs::string new_str(str);

  ASSERT_TRUE(new_str == "hello_world");
}


TEST(string_length_is_correct_when_initialized_with_string) {
  cs::string str("hello_world");
  cs::string new_str(str);

  ASSERT_EQUALS((size_t)11, new_str.length());
}


TEST(assignment_operator_works_with_c_string) {
  cs::string str;
  str = "hello_world";

  ASSERT_EQUALS(cs::string("hello_world"), str);
}

TEST(assignment_operator_works_with_string) {
  cs::string str;
  cs::string str2("hello_world");
  str = str2;

  ASSERT_EQUALS(cs::string("hello_world"), str);
}

TEST(assignment_operator_works_with_assignment_to_self) {
  cs::string str("hello_world");
  str = str;

  ASSERT_EQUALS(cs::string("hello_world"), str);
}

TEST(assignment_operator_assigns_multiple_variables_correctly) {
  cs::string str, str2, str3, str4("hello_world");
  str = str2 = str3 = str4;
  ASSERT_EQUALS(cs::string("hello_world"), str);
  ASSERT_EQUALS(cs::string("hello_world"), str2);
  ASSERT_EQUALS(cs::string("hello_world"), str3);
}

TEST(string_equality_operator_returns_true_when_comparing_to_same_c_string) {
  cs::string str("hello_world");

  ASSERT_TRUE(str == "hello_world");
  ASSERT_TRUE("hello_world" == str);

}

TEST(string_equality_operator_returns_false_when_comparing_to_different_c_string) {
  cs::string str("hello_world");
  ASSERT_FALSE("text" == str);
  ASSERT_FALSE(str == "text");
}

TEST(string_equality_operator_returns_false_when_comparing_to_different_c_string_with_same_length) {
  cs::string str("hello_world");
  ASSERT_FALSE("hello world" == str);
  ASSERT_FALSE(str == "text");
}

TEST(string_equality_operator_returns_true_when_comparing_to_same_string) {
  cs::string str("hello_world");
  cs::string str2("hello_world");

  ASSERT_TRUE(str == str2);
}

TEST(string_equality_operator_returns_false_when_comparing_to_different_string) {
  cs::string str("hello_world");
  cs::string str2("ads");

  ASSERT_FALSE(str == str2);
}

TEST(string_equality_operator_returns_false_when_comparing_to_different_string_with_same_length) {
  cs::string str("hello_world");
  cs::string str2("hello world");

  ASSERT_FALSE(str == str2);
}

TEST(string_equality_operator_returns_true_when_comparing_to_self) {
  cs::string str("hello_world");
  ASSERT_TRUE(str == str);
}

TEST(string_non_equality_operator_returns_true_with_c_string) {
  cs::string str("foobar");
  ASSERT_TRUE(str != "hello");
  ASSERT_TRUE("hello" != str);
}

TEST(string_non_equality_operator_returns_false_with_c_string) {
  cs::string str("foobar");
  ASSERT_FALSE(str != "foobar");
  ASSERT_FALSE("foobar" != str);
}

TEST(string_non_equality_operator_returns_true_with_string) {
  cs::string str("foobar");
  cs::string str2("hello!");
  ASSERT_TRUE(str != str2);
}

TEST(string_non_equality_operator_returns_false_with_string) {
  cs::string str("foobar");
  cs::string str2("foobar");
  ASSERT_FALSE(str != str2);
}

TEST(string_concatenation_works_with_c_string) {
  cs::string str("hello ");
  cs::string str2("world");
  ASSERT_EQUALS(cs::string("hello world"), str + "world");
  ASSERT_EQUALS(cs::string("hello world"), "hello " + str2);
}

TEST(string_concatenation_works_with_string) {
  cs::string str("hello ");
  cs::string str2("world");

  ASSERT_EQUALS(cs::string("hello world"), str + str2);
}

TEST(string_length_is_correct_after_concatenation) {
  cs::string str("hello ");
  ASSERT_EQUALS((size_t)11, (str + "world").length());
}

TEST(string_sum_assignment_operator_works_with_c_string) {
  cs::string str("hello ");
  str += "world";
  ASSERT_EQUALS(cs::string("hello world"), str);
}

TEST(string_sum_assignment_operator_works_with_string) {
  cs::string str("hello ");
  cs::string str2("world");
  str += str2;
  ASSERT_EQUALS(cs::string("hello world"), str);
}

TEST(string_sum_assignment_operator_returns_correct_string) {
  cs::string str("hello ");
  ASSERT_EQUALS(cs::string("hello world"), (str += "world"));
}


TEST(string_length_is_correct_after_sum_assignment) {
  cs::string str("hello ");
  str += "world";

  ASSERT_EQUALS((size_t)11, str.length());
}


TEST(string_output_stream_operator_works) {
  cs::string str("hello");
  std::ostringstream stream;
  stream << "This is " << str << " world!";
  ASSERT_EQUALS(std::string("This is hello world!"), stream.str());
}

TEST(string_input_stream_operator_works) {
  cs::string str;
  std::istringstream input("this is an input test!");
  input >> str;
  ASSERT_EQUALS(cs::string("this is an input test!"), str);
}

TEST(string_has_correct_length_after_input_stream) {
  cs::string str;
  std::istringstream input("this is an input test!");
  input >> str;
  ASSERT_EQUALS((size_t)22, str.length());
}


TEST(string_array_operator_gives_correct_letter_from_beginning) {
  cs::string str("teststring");
  ASSERT_EQUALS('t', str[0]);
}

TEST(string_array_operator_gives_correct_letter_from_middle) {
  cs::string str("teststring");
  ASSERT_EQUALS('r', str[6]);
}

TEST(string_array_operator_gives_correct_letter_from_end) {
  cs::string str("teststring");
  ASSERT_EQUALS('g', str[9]);
}

TEST(string_array_operator_throws_with_access_beyond_text_length) {
  cs::string str("teststring");
  ASSERT_THROWS(str[10], std::out_of_range);
}

TEST(string_array_operator_throws_with_negative_index) {
  cs::string str("teststring");
  ASSERT_THROWS(str[-1], std::out_of_range);
}

TEST(swap_works) {
  cs::string str("text here");
  cs::string str2("foobarbaz");

  str.swap(str2);

  ASSERT_EQUALS(cs::string("foobarbaz"), str);
  ASSERT_EQUALS(cs::string("text here"), str2);
}

TEST(push_back_char_works_to_empty_string) {
  cs::string str;
  str.push_back('a');

  ASSERT_EQUALS(cs::string("a"), str);
}

TEST(push_back_char_works_to_nonempty_string) {
  cs::string str("abcdef");
  str.push_back('a');

  ASSERT_EQUALS(cs::string("abcdefa"), str);
}

TEST(push_back_string_works_to_empty_string) {
  cs::string str;
  str.push_back("hello");
  ASSERT_EQUALS(cs::string("hello"), str);
}

TEST(push_back_string_works_to_nonempty_string) {
  cs::string str("hello");
  str.push_back(" world");
  ASSERT_EQUALS(cs::string("hello world"), str);
}

TEST(string_is_correct_after_pop_back) {
  cs::string str("hello!");
  str.pop_back();
  ASSERT_EQUALS(cs::string("hello"), str);
}

TEST(pop_back_returns_last_character_from_nonempty_string) {
  cs::string str("hello!");
  ASSERT_EQUALS('!', str.pop_back());
}

TEST(pop_back_throws_exception) {
  cs::string str;
  ASSERT_THROWS(str.pop_back(), std::out_of_range);
}


TEST(iterating_over_string_passes_all_characters) {
  cs::string str = "hello world!";
  cs::string new_str;

  for (cs::string::iterator iter = str.begin(); iter < str.end(); ++iter) {
    new_str.push_back(*iter);
  }

  ASSERT_EQUALS(str, new_str);
}

TEST(iterating_using_range_based_loop_works) {
  cs::string str = "hello world!";
  cs::string new_str;

  for (char c : str) {
    new_str.push_back(c);
  }

  ASSERT_EQUALS(str, new_str);
}

TEST(can_mutate_string_through_iterator) {
  cs::string str = "hxllo!";

  auto iter = str.begin();
  ++iter;
  *iter = 'e';

  ASSERT_EQUALS(cs::string("hello!"), str);
}


TEST(sorting_by_ascii_value_works_with_iterators) {
  cs::string str = "ihgfedcba";
  std::sort(str.begin(), str.end());

  ASSERT_EQUALS(cs::string("abcdefghi"), str);
}


TEST(insert_with_iterator_position_works_when_inserting_to_beginning) {
  cs::string str = "Hello world!";
  str.insert(str.begin(), "Wonderful ");
  ASSERT_EQUALS(cs::string("Wonderful Hello world!"), str);
}

TEST(insert_with_iterator_position_works_when_inserting_to_middle) {
  cs::string str = "Hello world!";
  str.insert(str.begin() + 6, "Wonderful ");
  ASSERT_EQUALS(cs::string("Hello Wonderful world!"), str);
}

TEST(insert_with_iterator_position_works_when_inserting_to_end) {
  cs::string str = "Hello world!";
  str.insert(str.end(), " Wonderful");
  ASSERT_EQUALS(cs::string("Hello world! Wonderful"), str);
}

TEST(insert_with_iterator_throws_if_position_is_before_start) {
  cs::string str = "Hello world!";
  // strictly speaking, pointer arithmetics where results ends outside assigned memory area (from beginning to one
  // after the end)  is undefined. However, on x86, this should work fine
  ASSERT_THROWS(str.insert(str.begin() - 1, "Wonderful"), std::out_of_range);
}

TEST(insert_with_iterator_throws_if_position_is_after_end) {
  cs::string str = "Hello world!";
  ASSERT_THROWS(str.insert(str.end()+1, "Wonderful"), std::out_of_range);
}

TEST(insert_with_iterator_returns_the_string_with_insertion) {
  cs::string str = "Hello world!";
  ASSERT_EQUALS(cs::string("Hello world! Wonderful"), str.insert(str.end(), " Wonderful"));
}

TEST(text_length_is_correct_after_insertion_with_iterator) {
  cs::string str = "Hello world!";
  str.insert(str.begin(), "Wonderful ");
  ASSERT_EQUALS((size_t)22, str.length());
}

TEST(insert_with_integer_position_works_when_inserting_to_beginning) {
  cs::string str = "Hello world!";

  // both char * and size_t are equally good implicit conversions for (int)0 so we have to specify that we actually want
  // to use the size_t version
  str.insert((size_t)0, "Wonderful ");
  ASSERT_EQUALS(cs::string("Wonderful Hello world!"), str);
}

TEST(insert_with_integer_position_works_when_inserting_to_middle) {
  cs::string str = "Hello world!";
  str.insert(6, "Wonderful ");
  ASSERT_EQUALS(cs::string("Hello Wonderful world!"), str);
}

TEST(insert_with_integer_position_works_when_inserting_to_end) {
  cs::string str = "Hello world!";
  str.insert(12, " Wonderful");
  ASSERT_EQUALS(cs::string("Hello world! Wonderful"), str);
}

TEST(insert_with_integer_throws_if_integer_is_negative) {
  cs::string str = "Hello world!";
  ASSERT_THROWS(str.insert(-1, "Wonderful"), std::out_of_range);
}

TEST(insert_with_integer_throws_if_integer_is_larger_than_string) {
  cs::string str = "Hello world!";
  ASSERT_THROWS(str.insert(13, "Wonderful"), std::out_of_range);
}
TEST(insert_with_integer_returns_the_string_with_insertion) {
  cs::string str = "Hello world!";
  ASSERT_EQUALS(cs::string("Hello world! Wonderful"), str.insert(12, " Wonderful"));
}

TEST(text_length_is_correct_after_insertion_with_integer_position) {
  cs::string str = "Hello world!";
  str.insert((size_t)0, "Wonderful ");
  ASSERT_EQUALS((size_t)22, str.length());
}

TEST(erase_with_iterator_range_erases_correctly_from_beginning) {

  cs::string str = "Hello world!";
  str.erase(str.begin(), str.begin() + 2);

  ASSERT_EQUALS(cs::string("llo world!"), str);
}
TEST(erase_with_iterator_range_erases_correctly_from_the_middle) {
  cs::string str = "Hello world!";
  str.erase(str.begin() + 2, str.begin() + 5);

  ASSERT_EQUALS(cs::string("He world!"), str);
}

TEST(erase_with_iterator_range_erases_correctly_from_end) {
  cs::string str = "Hello world!";
  str.erase(str.begin() + 5, str.end());

  ASSERT_EQUALS(cs::string("Hello"), str);
}

TEST(erase_with_iterator_range_erases_whole_string_with_begin_and_end_iterators) {
  cs::string str = "Hello world!";
  str.erase(str.begin(), str.end());

  ASSERT_EQUALS(cs::string(""), str);
}

TEST(erase_with_iterator_range_does_not_change_string_if_iterators_are_same) {
  cs::string str = "Hello world!";
  str.erase(str.begin()+4, str.begin()+4);

  ASSERT_EQUALS(cs::string("Hello world!"), str);
}

TEST(erase_with_iterator_range_returns_iterator_to_first_character_not_erased) {
  cs::string str = "Hello world!";
  ASSERT_EQUALS('w', *str.erase(str.begin(), str.begin() + 6));
}

TEST(erase_with_iterator_range_returns_end_if_rest_of_string_erased) {
  cs::string str = "Hello world!";
  auto iter = str.erase(str.begin() + 5, str.end());
  ASSERT_EQUALS(str.end(), iter);
}

TEST(erase_with_iterator_range_returns_correct_string_length) {
  cs::string str = "Hello world!";
  str.erase(str.begin() + 2, str.begin() + 9);

  ASSERT_EQUALS((size_t)5, str.length());
}

TEST(erase_with_iterator_range_throws_if_start_iterator_is_smaller_than_begin) {
  cs::string str = "Hello world!";
  ASSERT_THROWS(str.erase(str.begin()-1, str.begin() + 6), std::out_of_range);
}

TEST(erase_with_iterator_range_throws_if_end_iterator_is_beyond_end_of_string) {
  cs::string str = "Hello world!";
  ASSERT_THROWS(str.erase(str.begin(), str.end() + 1), std::out_of_range);
}

TEST(erase_with_iterator_range_throws_if_start_iterator_is_greater_than_end_iterator) {
  cs::string str = "Hello world!";
  ASSERT_THROWS(str.erase(str.begin() + 4, str.begin() + 2), std::out_of_range);
}

TEST(erase_with_integers_erases_correctly_from_beginning) {
  cs::string str = "Hello world!";
  str.erase(0, 6);

  ASSERT_EQUALS(cs::string("world!"), str);
}

TEST(erase_with_integers_erases_correctly_from_the_middle) {
  cs::string str = "Hello world!";
  str.erase(2, 7);

  ASSERT_EQUALS(cs::string("Held!"), str);
}

TEST(erase_with_integers_erases_correctly_from_end) {
  cs::string str = "Hello world!";
  str.erase(5, 7);

  ASSERT_EQUALS(cs::string("Hello"), str);
}

TEST(erase_with_integers_erases_whole_string_with_0_and_length_as_parameters) {
  cs::string str = "Hello world!";
  str.erase(0, str.length());

  ASSERT_EQUALS(cs::string(""), str);
}


TEST(erase_with_integers_erases_string_from_start_position_if_length_is_larger_than_remaining_string) {
  cs::string str = "Hello world!";
  str.erase(2, str.length()*5);

  ASSERT_EQUALS(cs::string("He"), str);
}

TEST(erase_with_integers_does_not_change_string_if_length_is_0) {
  cs::string str = "Hello world!";
  str.erase(4, 0);

  ASSERT_EQUALS(cs::string("Hello world!"), str);
}

TEST(erase_with_integers_returns_string_after_erasion) {
  cs::string str = "Hello world!";
  ASSERT_EQUALS(cs::string("world!"), str.erase(0, 6));
}

TEST(erase_with_integers_returns_correct_string_length) {
  cs::string str = "Hello world!";
  str.erase(5, str.length());
  ASSERT_EQUALS((size_t)5, str.length());
}

TEST(erase_with_integers_throws_if_start_is_negative) {
  cs::string str = "Hello world!";
  ASSERT_THROWS(str.erase(-1, 5), std::out_of_range);
}

TEST(erase_with_integers_throws_if_start_is_beyond_string_length) {
  cs::string str = "Hello world!";
  ASSERT_THROWS(str.erase(str.length(), 4), std::out_of_range);
}

TEST(erase_with_single_iterator_erases_character_correctly_from_beginning) {
  cs::string str = "Hello world!";
  str.erase(str.begin());
  ASSERT_EQUALS(cs::string("ello world!"), str);
}

TEST(erase_with_single_iterator_erases_character_correctly_from_middle) {
  cs::string str = "Hello world!";
  str.erase(str.begin()+6);
  ASSERT_EQUALS(cs::string("Hello orld!"), str);
}

TEST(erase_with_single_iterator_erases_character_correctly_from_end) {
  cs::string str = "Hello world!";
  str.erase(str.end() - 1);
  ASSERT_EQUALS(cs::string("Hello world"), str);
}

TEST(erase_with_single_iterator_returns_iterator_to_first_character_not_erased) {
  cs::string str = "Hello world!";
  ASSERT_EQUALS('o', *str.erase(str.begin()+6));
}

TEST(erase_with_single_iterator_returns_iterator_to_end_when_erasing_last_character) {
  cs::string str = "Hello world!";
  auto iter =  str.erase(str.end() - 1);
  ASSERT_EQUALS(str.end(), iter);
}

TEST(erase_with_single_iterator_throws_if_iterator_is_before_begin) {
  cs::string str = "Hello world!";
  ASSERT_THROWS(str.erase(str.begin() - 1), std::out_of_range);
}

TEST(erase_with_single_iterator_throws_if_iterator_is_end) {
  cs::string str = "Hello world!";
  ASSERT_THROWS(str.erase(str.end()), std::out_of_range);
}

TEST(erase_with_single_iterator_throws_if_iterator_is_after_end) {
  cs::string str = "Hello world!";
  ASSERT_THROWS(str.erase(str.end()+1), std::out_of_range);
}
