#include "solution.hpp"
#include "../../../include/lc_test.hpp"
#include <vector>

void test_placeholder() {
    Solution soln;
    vector<int> height = {0,2,0,3,1,0,1,3,2,1};
  EXPECT_EQ(soln.trap_stack(height), 9);
}

int main() {
  test_placeholder();
  return lc_test::summary();
}
