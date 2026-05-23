#include "solution.hpp"
#include "../../../include/lc_test.hpp"

void test_placeholder()
{
  Solution soln;
  string s = "OUZODYXAZV";
  string t = "XYZ";

  string expected = "YXAZ";
  EXPECT_EQ(soln.minWindow(s, t), expected);
}

void test_2()
{
  Solution soln;
  string s = "OUZODYXAZV";
  string t = "XYZ";

  string expected = "YXAZ";
  EXPECT_EQ(soln.minWindow(s, t), expected);
}

void test_3()
{
  Solution soln;
  string s = "ab";
  string t = "A";

  string expected = "";
  EXPECT_EQ(soln.minWindow(s, t), expected);
}

int main()
{
  test_3();
  return lc_test::summary();
}
