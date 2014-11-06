#pragma once
#include <string>
#include <functional>
#include <vector>

class test_runner {
public:
  void register_test(std::string name, std::function<void()> test);


  void run_tests();

private:


  struct test_case {
    std::string test_name;
    std::function<void()> test_function;
  };

  std::vector<test_case> m_test_cases;
};
