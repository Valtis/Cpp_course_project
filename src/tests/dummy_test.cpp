#include "dummy_test.h"
#include "testrunner/test.h"
#include <cstdlib>

#include "testrunner/memory_instrumentation.h"





// should pass regular tests
void passing_test() {
  ASSERT_EQUALS(5, 5);
  ASSERT_EQUALS("horse", "horse");
}


// should fail tests
void failing_test() {
  ASSERT_EQUALS("horse", "car");

}


// should pass leak detection
void non_leaking_test() {

  double *a = new double;
  delete a;

  int *b = new int[100];
  delete [] b;
}

// should fail leak detection
void leaking_test() {
  new int;
  new int[100];
  auto c = new int[100];
  delete c;

}
