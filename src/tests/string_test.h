#pragma once


void new_string_length_is_zero();
void new_string_equals_to_empty_string();

void string_is_correctly_initialized_with_c_string();
void string_length_is_correct_when_initialized_with_c_string();
void string_is_correctly_initialized_with_string();
void string_length_is_correct_when_initialized_with_string();

void string_equality_operator_returns_true_when_comparing_to_same_c_string();
void string_equality_operator_returns_false_when_comparing_to_different_c_string();
void string_equality_operator_returns_false_when_comparing_to_different_c_string_with_same_length();

void string_equality_operator_returns_true_when_comparing_to_same_string();
void string_equality_operator_returns_false_when_comparing_to_different_string();
void string_equality_operator_returns_false_when_comparing_to_different_string_with_same_length();
void string_equality_operator_returns_true_when_comparing_to_self();

void string_non_equality_operator_returns_true_with_c_string();
void string_non_equality_operator_returns_false_with_c_string();

void string_non_equality_operator_returns_true_with_string();
void string_non_equality_operator_returns_false_with_string();


void string_concatenation_works_with_c_string();
void string_concatenation_works_with_string();
void string_length_is_correct_after_concatenation();

void string_sum_assignment_operator_works_with_c_string();
void string_sum_assignment_operator_works_with_string();
void string_sum_assignment_operator_returns_correct_string();
void string_length_is_correct_after_sum_assignment();




void string_output_stream_operator_works();
void string_input_stream_operator_works();
