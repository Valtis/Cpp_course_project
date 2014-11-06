#include "testrunner/test.h"
#include "dummy_test.h"

int main() {
  test_runner runner;

  runner.register_test("passing_test", passing_test);
  runner.register_test("failing_test", failing_test);
  runner.register_test("non_leaking_test", non_leaking_test);
  runner.register_test("leaking_test", leaking_test);


  runner.run_tests();

}
