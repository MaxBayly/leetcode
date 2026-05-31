#include "binary_search.h++"

#include "koko_bananas.h++"
#include "rotated_array.h++"
#include "rotated_search.h++"
#include "two_d_matrix.h++"
#include "gtest/gtest.h"

TEST(BSearch, One) {
    BinarySearch soln;
    vector input = {-1,0,2,4,6,8};
    int target = 4;
    EXPECT_EQ(soln.search(input, target), 3);
}

TEST(BSearch, Two) {
    BinarySearch soln;
    vector input = {-1,0,2,4,6,8};
    int target = 3;
    EXPECT_EQ(soln.search(input, target), -1);
}

TEST(BSearch, Three) {
    BinarySearch soln;
    vector input = {-1,0,3,5,9,12};
    int target = 9;
    EXPECT_EQ(soln.search(input, target), 4);
}

TEST(BSearch, Four) {
    BinarySearch soln;
    vector input = {5};
    int target = 5;
    EXPECT_EQ(soln.search(input, target), 0);
}

TEST(MatrixTest, One) {
    SearchMatrix soln;
    vector<vector<int>> input = {{1,2,4,8},{10,11,12,13},{14,20,30,40}};
    int target = 10;
    EXPECT_TRUE(soln.searchMatrix(input, target));
}

TEST(MatrixTest, Two) {
    SearchMatrix soln;
    vector<vector<int>> input = {{1,2,4,8},{10,11,12,13},{14,20,30,40}};
    int target = 15;
    EXPECT_TRUE(!soln.searchMatrix(input, target));
}

TEST(Koko, One) {
    KokoBananas soln;
    vector piles = {1,4,3,2};
    int h = 9;
    EXPECT_EQ(soln.minEatingSpeed(piles, h), 2);
}

TEST(Koko, Two) {
    KokoBananas soln;
    vector piles = {25,10,23,4};
    int h = 4;
    EXPECT_EQ(soln.minEatingSpeed(piles, h), 25);
}

TEST(Rotated, One) {
    RotatedArray soln;
    vector nums = {3,4,5,6,1,2};
    EXPECT_EQ(soln.findMin(nums), 1);
}

TEST(Rotated, Two) {
    RotatedArray soln;
    vector nums = {4,5,0,1,2,3};
    EXPECT_EQ(soln.findMin(nums), 0);
}

TEST(Rotated, Three) {
    RotatedArray soln;
    vector nums = {4,5,6,7};
    EXPECT_EQ(soln.findMin(nums), 4);
}

TEST(RotSearch, One) {
    RotatedSearch soln;
    vector nums = {3,4,5,6,1,2};
    int target = 1;
    EXPECT_EQ(soln.search(nums, target), 4);
}

TEST(RotSearch, Two) {
    RotatedSearch soln;
    vector nums = {3,5,6,0,1,2};
    int target = 4;
    EXPECT_EQ(soln.search(nums, target), -1);
}

TEST(RotSearch, Three) {
    RotatedSearch soln;
    vector nums = {4,5,6,7,0,1,2};
    int target = 0;
    EXPECT_EQ(soln.search(nums, target), 4);
}

TEST(RotSearch, Four) {
    RotatedSearch soln;
    vector nums = {3,1};
    int target = 3;
    EXPECT_EQ(soln.search(nums, target), 0);
}

TEST(RotSearch, Five) {
    RotatedSearch soln;
    vector nums = {4,5,6,7,8,1,2,3};
    int target = 8;
    EXPECT_EQ(soln.search(nums, target), 4);
}

TEST(RotSearch, Six) {
    RotatedSearch soln;
    vector nums = {1};
    int target = 2;
    EXPECT_EQ(soln.search(nums, target), -1);
}

TEST(RotSearch, Seven) {
    RotatedSearch soln;
    vector nums = {1,3 };
    int target = 4;
    EXPECT_EQ(soln.search(nums, target), -1);
}