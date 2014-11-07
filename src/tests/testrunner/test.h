#pragma once

#include "test_runner.h"
#include "exceptions.h"
#include "../../utility/stringutil.h"

// helper macro
#define REGISTER_TEST(runner, x) runner.register_test(#x, (x));

// Test macros
// assignments to prevent evaluation multiple times (in case there are side effects)
#define ASSERT_EQUALS(expected, actual) assert_equality((expected), (actual), __LINE__, __FILE__)
#define ASSERT_TRUE(value) assert_true((value), __LINE__, __FILE__)
#define ASSERT_FALSE(value) assert_false((value), __LINE__, __FILE__)



// due to templates, these must be defined in the header

template <typename T>
void assert_equality(T expected, T actual, int line, std::string file) {
  if (expected != actual) {
    throw AssertionException("Equality failure: Expected '" + utility::to_string(expected)
        + "' but was '" + utility::to_string(actual) + "'",
        line, file);
  }
}


void assert_true(bool value, int line, std::string file);
void assert_false(bool value, int line, std::string file);
