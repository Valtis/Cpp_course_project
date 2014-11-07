#include "testrunner/test.h"
#include "dummy_test.h"
#include "string_test.h"


int main() {
  test_runner runner;

/*
  REGISTER_TEST(runner, passing_test);
  REGISTER_TEST(runner, failing_test);
  REGISTER_TEST(runner, non_leaking_test);
  REGISTER_TEST(runner, leaking_test);*/

  REGISTER_TEST(runner, new_string_length_is_zero);
  REGISTER_TEST(runner, new_string_equals_to_empty_string);
  REGISTER_TEST(runner, string_is_correctly_initialized_with_c_string);
  REGISTER_TEST(runner, string_length_is_correct_when_initialized_with_c_string);
  REGISTER_TEST(runner, string_is_correctly_initialized_with_string);
  REGISTER_TEST(runner, string_length_is_correct_when_initialized_with_string);

  REGISTER_TEST(runner, assignment_operator_works_with_c_string);
  REGISTER_TEST(runner, assignment_operator_works_with_string);
  REGISTER_TEST(runner, assignment_operator_works_with_assignment_to_self);
  REGISTER_TEST(runner, assignment_operator_assigns_multiple_variables_correctly);

  REGISTER_TEST(runner, string_equality_operator_returns_true_when_comparing_to_same_c_string);
  REGISTER_TEST(runner, string_equality_operator_returns_false_when_comparing_to_different_c_string);
  REGISTER_TEST(runner, string_equality_operator_returns_false_when_comparing_to_different_c_string_with_same_length);
  REGISTER_TEST(runner, string_equality_operator_returns_true_when_comparing_to_same_string);
  REGISTER_TEST(runner, string_equality_operator_returns_false_when_comparing_to_different_string);
  REGISTER_TEST(runner, string_equality_operator_returns_false_when_comparing_to_different_string_with_same_length);
  REGISTER_TEST(runner, string_equality_operator_returns_true_when_comparing_to_self);

  REGISTER_TEST(runner, string_non_equality_operator_returns_true_with_c_string);
  REGISTER_TEST(runner, string_non_equality_operator_returns_false_with_c_string);
  REGISTER_TEST(runner, string_non_equality_operator_returns_true_with_string);
  REGISTER_TEST(runner, string_non_equality_operator_returns_false_with_string);

  REGISTER_TEST(runner, string_concatenation_works_with_c_string);
  REGISTER_TEST(runner, string_concatenation_works_with_string);
  REGISTER_TEST(runner, string_length_is_correct_after_concatenation);

  REGISTER_TEST(runner, string_sum_assignment_operator_works_with_c_string);
  REGISTER_TEST(runner, string_sum_assignment_operator_works_with_string);
  REGISTER_TEST(runner, string_sum_assignment_operator_returns_correct_string);
  REGISTER_TEST(runner, string_length_is_correct_after_sum_assignment);

  REGISTER_TEST(runner, string_output_stream_operator_works);
  REGISTER_TEST(runner, string_input_stream_operator_works);
  REGISTER_TEST(runner, string_has_correct_length_after_input_stream);

  REGISTER_TEST(runner, string_array_operator_gives_correct_letter_from_beginning);
  REGISTER_TEST(runner, string_array_operator_gives_correct_letter_from_middle);
  REGISTER_TEST(runner, string_array_operator_gives_correct_letter_from_end);
  REGISTER_TEST(runner, string_array_operator_throws_with_access_beyond_text_length);
  REGISTER_TEST(runner, string_array_operator_throws_with_negative_index);

  REGISTER_TEST(runner, swap_works);


  runner.run_tests();

}
