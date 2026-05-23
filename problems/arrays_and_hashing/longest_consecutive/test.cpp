#include "../../../include/lc_test.hpp"
#include "solution.hpp"
#include <vector>

void test_placeholder() {
  Solution soln;
  vector<int> input = {2,20,4,10,3,4,5};

  EXPECT_EQ(soln.longestConsecutive(input), 4);
}

void test_2() {
    Solution soln;
    vector<int> input = {0,3,2,5,4,6,1,1};
    EXPECT_EQ(soln.longestConsecutive(input), 7);
}

int main() {
  // test_placeholder();
  test_2();
  return lc_test::summary();
}
