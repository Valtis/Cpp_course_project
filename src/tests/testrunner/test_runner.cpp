#include "test_runner.h"
#include <iostream>
#include "exceptions.h"
#include "leakdetection/memory_instrumentation.h"

test_runner::test_runner() : m_passed_tests(0), m_failed_tests(0) {

}

void test_runner::register_test(std::string name, std::function<void()> test) {
  m_test_cases.push_back({ name, test });
}


void test_runner::run_tests() {
  std::cout << "\nRunning tests...\n\n";





  for (test_case test : m_test_cases) {
    handle_test_case(test);

  }

  std::cout << "\n" << m_passed_tests << " tests passed, " << m_failed_tests << " failed.\n";
}


void test_runner::handle_test_case(test_case test) {
  bool passing = false;

  auto allocations = get_allocations_list();
  allocations->clear();

  try {
    test.test_function();
    passing = true;
  } catch (const AssertionException &ex) {
    std::cout << "Assertion failure at test " << test.test_name << ": " << ex.what() << "\n";
    std::cout << "Failed at line " << ex.line() << " at file " << ex.file() << "\n";
  } catch (const std::exception &ex) {
    std::cout << "Unexpected exception caught: " << ex.what() << "\n";
  } catch (...) {
    std::cout << "Unexpected exception with unknown type caught\n";
  }


  if (allocations->has_errors()) {
    std::cout << "Memory leak(s) detected in test case " << test.test_name << "\n";
    allocations->print_errors();
    passing = false;
  }

  if (passing) {
    std::cout << "Test " << test.test_name << " passed!\n";
    ++m_passed_tests;
  } else {
    std::cout << "Test " << test.test_name << " failed!\n";
    ++m_failed_tests;
  }

  std::cout << "\n";
}
