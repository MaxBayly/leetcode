#include "binary_search.h++"

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