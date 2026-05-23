#include "../../../include/lc_test.hpp"
#include "solution.hpp"
#include <vector>

void test_placeholder(vector<int> input, int target, vector<int> expected) {
  Solution soln;
  EXPECT_EQ(soln.twoSum(input, target), expected);
}

int main() {
  test_placeholder(vector({3, 4, 6, 8, 10}), 10, vector({2, 3}));
  test_placeholder(vector({2, 3, 4}), 6, vector({1, 3}));
  return lc_test::summary();
}
