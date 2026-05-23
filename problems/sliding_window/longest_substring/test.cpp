#include "solution.hpp"
#include "../../../include/lc_test.hpp"

void test_placeholder() {
    Solution soln;
    string input = "zxyzxyz";
  EXPECT_EQ(soln.lengthOfLongestSubstring(input), 3);
}

void test_2() {
    Solution soln;
    string input = "xxxx";
    EXPECT_EQ(soln.lengthOfLongestSubstring(input), 1);
}

void test_3() {
    Solution soln;
    string input = "pwwkew";
    EXPECT_EQ(soln.lengthOfLongestSubstring(input), 3);
}

void test_4() {
    Solution soln;
    string input = "dvdf";
    EXPECT_EQ(soln.lengthOfLongestSubstring(input), 3);
}

int main() {
  test_placeholder();
  test_2();
  test_3();
  test_4();
  return lc_test::summary();
}
