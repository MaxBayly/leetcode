#include "buy_sell.h++"
#include "longest_substring.h++"
#include "min_window.h++"
#include "permutation.h++"
#include "replacement.h++"
#include "gtest/gtest.h"
#include "max_window.h++"

TEST(SlidingWindowTest, TestOne) {
    buy_sell soln;
    vector<int> input = {10, 1, 5, 6, 7, 1};
    EXPECT_EQ(soln.maxProfitDynamic(input), 6);
}

TEST(LongestSubstringTest, TestOne) {
    longest_substring soln;
    string input = "zxyzxyz";
    EXPECT_EQ(soln.lengthOfLongestSubstring(input), 3);
}

TEST(LongestSubstringTest, TestTwo) {
    longest_substring soln;
    string input = "xxxx";
    EXPECT_EQ(soln.lengthOfLongestSubstring(input), 1);
}

TEST(LongestSubstringTest, TestThree) {
    longest_substring soln;
    string input = "pwwkew";
    EXPECT_EQ(soln.lengthOfLongestSubstring(input), 3);
}

TEST(LongestSubstringTest, TestFour) {
    longest_substring soln;
    string input = "dvdf";
    EXPECT_EQ(soln.lengthOfLongestSubstring(input), 3);
}

TEST(MinWindowTest, TestOne)
{
    min_window soln;
    string s = "OUZODYXAZV";
    string t = "XYZ";

    string expected = "YXAZ";
    EXPECT_EQ(soln.minWindow(s, t), expected);
}

TEST(MinWindowTest, TestTwo){
    min_window soln;
    string s = "OUZODYXAZV";
    string t = "XYZ";

    string expected = "YXAZ";
    EXPECT_EQ(soln.minWindow(s, t), expected);
}

TEST(MinWindowTest, TestThree)
{
    min_window soln;
    string s = "ab";
    string t = "A";

    string expected;
    EXPECT_EQ(soln.minWindow(s, t), expected);
}

TEST(Permutation, One) {
    permutation soln;
    string s1 = "abc", s2 = "lecaabee";
    EXPECT_TRUE(!soln.checkInclusion(s1, s2));
}

TEST(Permutation, Two){
    permutation soln;
    string s1 = "ab", s2 = "lecabee";
    EXPECT_TRUE(soln.checkInclusion(s1, s2));
}

TEST(Permutation, Three) {
    permutation soln;
    string s1="adc";
    string s2="dcda";
    EXPECT_TRUE(soln.checkInclusion(s1, s2));
}

TEST(Replacement, One)
{
    replacement soln;
    string input = "XYYX";
    int k = 2;
    EXPECT_EQ(soln.characterReplacement(input, k), 4);
}

TEST(Replacement, Two)
{
    replacement soln;
    string input = "AAABABB";
    int k = 1;
    EXPECT_EQ(soln.characterReplacement(input, k), 5);
}

TEST(Replacement, Three)
{
    replacement soln;
    string input = "AAAA";
    int k = 2;
    EXPECT_EQ(soln.characterReplacement(input, k), 4);
}

TEST(Replacement, Four) {
    replacement soln;
    string input = "AABABBA";
    int k = 1;
    EXPECT_EQ(soln.characterReplacement(input, k), 4);
}

TEST(MaxWindow, One) {
    max_window soln;
    vector input = {1,2,1,0,4,2,6};
    int k = 3;
    vector expected = {2, 2, 4, 4, 6};
    EXPECT_EQ(soln.maxSlidingWindow(input, k), expected);
}

TEST(MaxWindow, Two) {
    max_window soln;
    vector input = {1,3,1,2,0,5};
    int k = 3;
    vector expected = {3,3,2,5};
    EXPECT_EQ(soln.maxSlidingWindow(input, k), expected);
}