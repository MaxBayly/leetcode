#include "solution.hpp"
#include "../../../include/lc_test.hpp"

void test_1() {
    Solution solution;
    vector<int> input = {1,2,2,3,3,3};
    vector<int> expected = {2, 3};
    EXPECT_EQ(solution.topKFrequent(input,  2), expected);
}

void test_2() {
    Solution solution;
    vector<int> input = {7,7};
    vector<int> expected = {7};
    EXPECT_EQ(solution.topKFrequent(input,  1), expected);
}

int main() {
  test_1();
  test_2();
  return lc_test::summary();
}
