#include "../../../include/lc_test.hpp"
#include "solution.hpp"

void test_placeholder() {
  Solution soln;
  vector<int> input = {1, 7, 2, 5, 12, 3, 500, 500, 7, 8, 4, 7, 3, 6};
  EXPECT_EQ(soln.maxArea(input), 500);
}

int main() {
  test_placeholder();
  return lc_test::summary();
}
