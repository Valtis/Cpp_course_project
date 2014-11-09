#include "testrunner/test.h"
#include "dummy_test.h"
#include "string_test.h"


int main() {
  test_runner runner;

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

  REGISTER_TEST(runner, push_back_char_works_to_empty_string);
  REGISTER_TEST(runner, push_back_char_works_to_nonempty_string);

  REGISTER_TEST(runner, swap_works);

  REGISTER_TEST(runner, push_back_string_works_to_empty_string);
  REGISTER_TEST(runner, push_back_string_works_to_nonempty_string);

  REGISTER_TEST(runner, string_is_correct_after_pop_back);
  REGISTER_TEST(runner, pop_back_returns_last_character_from_nonempty_string);
  REGISTER_TEST(runner, pop_back_throws_exception);

  REGISTER_TEST(runner, iterating_over_string_passes_all_characters);
  REGISTER_TEST(runner, iterating_using_range_based_loop_works);
  REGISTER_TEST(runner, can_mutate_string_through_iterator);
  REGISTER_TEST(runner, sorting_by_ascii_value_works_with_iterators);

  REGISTER_TEST(runner, insert_with_iterator_position_works_when_inserting_to_beginning);
  REGISTER_TEST(runner, insert_with_iterator_position_works_when_inserting_to_middle);
  REGISTER_TEST(runner, insert_with_iterator_position_works_when_inserting_to_end);
  REGISTER_TEST(runner, insert_with_iterator_throws_if_position_is_before_start);
  REGISTER_TEST(runner, insert_with_iterator_throws_if_position_is_after_end);
  REGISTER_TEST(runner, insert_with_iterator_returns_the_string_with_insertion);
  REGISTER_TEST(runner, text_length_is_correct_after_insertion_with_iterator);

  REGISTER_TEST(runner, insert_with_integer_position_works_when_inserting_to_beginning);
  REGISTER_TEST(runner, insert_with_integer_position_works_when_inserting_to_middle);
  REGISTER_TEST(runner, insert_with_integer_position_works_when_inserting_to_end);
  REGISTER_TEST(runner, insert_with_integer_throws_if_integer_is_negative);
  REGISTER_TEST(runner, insert_with_integer_throws_if_integer_is_larger_than_string);
  REGISTER_TEST(runner, insert_with_integer_returns_the_string_with_insertion);
  REGISTER_TEST(runner, text_length_is_correct_after_insertion_with_integer_position);

  REGISTER_TEST(runner, erase_with_iterator_range_erases_correctly_from_beginning);
  REGISTER_TEST(runner, erase_with_iterator_range_erases_correctly_from_the_middle);
  REGISTER_TEST(runner, erase_with_iterator_range_erases_correctly_from_end);
  REGISTER_TEST(runner, erase_with_iterator_range_erases_whole_string_with_begin_and_end_iterators);
  REGISTER_TEST(runner, erase_with_iterator_range_does_not_change_string_if_iterators_are_same);
  REGISTER_TEST(runner, erase_with_iterator_range_returns_iterator_to_first_character_not_erased);
  REGISTER_TEST(runner, erase_with_iterator_range_returns_end_if_rest_of_string_erased);
  REGISTER_TEST(runner, erase_with_iterator_range_returns_correct_string_length);
  REGISTER_TEST(runner, erase_with_iterator_range_throws_if_start_iterator_is_smaller_than_begin);
  REGISTER_TEST(runner, erase_with_iterator_range_throws_if_end_iterator_is_beyond_end_of_string);
  REGISTER_TEST(runner, erase_with_iterator_range_throws_if_start_iterator_is_greater_than_end_iterator);

  REGISTER_TEST(runner, erase_with_integers_erases_correctly_from_beginning);
  REGISTER_TEST(runner, erase_with_integers_erases_correctly_from_the_middle);
  REGISTER_TEST(runner, erase_with_integers_erases_correctly_from_end);
  REGISTER_TEST(runner, erase_with_integers_erases_string_from_start_position_if_length_is_larger_than_remaining_string);
  REGISTER_TEST(runner, erase_with_integers_erases_whole_string_with_0_and_length_as_parameters);
  REGISTER_TEST(runner, erase_with_integers_does_not_change_string_if_length_is_0);
  REGISTER_TEST(runner, erase_with_integers_returns_iterator_to_first_character_not_erased);
  REGISTER_TEST(runner, erase_with_integers_returns_end_if_rest_of_string_erased);
  REGISTER_TEST(runner, erase_with_integers_returns_correct_string_length);
  REGISTER_TEST(runner, erase_with_integers_throws_if_start_is_negative);
  REGISTER_TEST(runner, erase_with_integers_throws_if_start_is_beyond_string_length);


  runner.run_tests();

}
