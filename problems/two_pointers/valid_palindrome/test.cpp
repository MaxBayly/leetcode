#include "solution.hpp"
#include "../../../include/lc_test.hpp"

void test_placeholder() {
    Solution soln;
    EXPECT_TRUE(soln.isPalindrome("Was it a car r a cat I saw?"));
}

void test_2() {
    Solution soln;
    EXPECT_TRUE(!soln.isPalindrome("tab a cat"));
}

int main() {
  test_placeholder();
  test_2();
  return lc_test::summary();
}
