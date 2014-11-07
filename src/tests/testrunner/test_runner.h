#pragma once
#include <string>
#include <functional>
#include <vector>

class test_runner {
public:
  test_runner();

  void register_test(std::string name, std::function<void()> test);


  void run_tests();

private:


  struct test_case {
    std::string test_name;
    std::function<void()> test_function;
  };

  void handle_test_case(test_case test);

  std::vector<test_case> m_test_cases;
  int m_passed_tests;
  int m_failed_tests;
};
