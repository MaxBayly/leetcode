#include "container.h++"
#include "three_sum.h++"
#include "trapping_water.h++"
#include "two_sum_ii.h++"
#include "valid_palindrome.h++"
#include "gtest/gtest.h"

TEST(Container, One) {
    container soln;
    vector<int> input = {1, 7, 2, 5, 12, 3, 500, 500, 7, 8, 4, 7, 3, 6};
    EXPECT_EQ(soln.maxArea(input), 500);
}

TEST(ThreeSum, One) {
    three_sum soln;
    vector<int> input = {-1,0,1,2,-1,-4};
    vector<vector<int>> expected = { { -1, 2, -1 }, { 0, 1, -1 } };
    EXPECT_EQ(soln.threeSum(input), expected);
}

TEST(ThreeSum, Two) {
    three_sum soln;
    vector<int> input = {-1,0,1,2,-1,-4};
    vector<vector<int>> expected = { { -1, 2, -1 }, { 0, 1, -1 } };
    EXPECT_EQ(soln.threeSum(input), expected);
}

TEST(TrappingWater, One) {
    trapping_water soln;
    vector<int> height = {0,2,0,3,1,0,1,3,2,1};
    EXPECT_EQ(soln.trap_stack(height), 9);
}

TEST(Palindrome, One) {
    valid_palindrome soln;
    EXPECT_TRUE(soln.isPalindrome("Was it a car r a cat I saw?"));
}

TEST(Palindrome, Two) {
    valid_palindrome soln;
    EXPECT_TRUE(!soln.isPalindrome("tab a cat"));
}