#include "solution.hpp"
#include "../../../include/lc_test.hpp"

void test_placeholder()
{
  Solution soln;
  string input = "XYYX";
  int k = 2;
  EXPECT_EQ(soln.characterReplacement(input, k), 4);
}

void test_2()
{
  Solution soln;
  string input = "AAABABB";
  int k = 1;
  EXPECT_EQ(soln.characterReplacement(input, k), 5);
}

void test_3()
{
  Solution soln;
  string input = "AAAA";
  int k = 2;
  EXPECT_EQ(soln.characterReplacement(input, k), 4);
}

void test_4() {
  Solution soln;
  string input = "AABABBA";
  int k = 1;
  EXPECT_EQ(soln.characterReplacement(input, k), 4);
}

int main()
{
  // test_placeholder();
  // test_2();
  // test_3();
  test_4();
  return lc_test::summary();
}
