#include "../../../include/lc_test.hpp"
#include "solution.hpp"

void test_placeholder() {
    Solution soln;
    vector<int> input = {-1,0,1,2,-1,-4};
    vector<vector<int>> expected = {{-1,-1,2},{-1,0,1}};
    EXPECT_EQ(soln.threeSum(input), expected);
}

void test_2() {
    Solution soln;
    vector<int> input = {-1,0,1,2,-1,-4};
    vector<vector<int>> expected = {{-1,-1,2},{-1,0,1}};
    EXPECT_EQ(soln.threeSum(input), expected);
}

int main() {
  test_placeholder();
  return lc_test::summary();
}
