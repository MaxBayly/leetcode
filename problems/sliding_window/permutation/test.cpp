#include "solution.hpp"
#include "../../../include/lc_test.hpp"

void test_placeholder() {
  Solution soln;
  string s1 = "abc", s2 = "lecaabee";
  EXPECT_TRUE(!soln.checkInclusion(s1, s2));
}

void test_2() {
  Solution soln;
  string s1 = "ab", s2 = "lecabee";
  EXPECT_TRUE(soln.checkInclusion(s1, s2));
}

void test_3() {
  Solution soln;
  string s1="adc"; 
  string s2="dcda";
  EXPECT_TRUE(soln.checkInclusion(s1, s2));
}

int main() {
  // test_placeholder();
  test_3();
  return lc_test::summary();
}
