#include "k_closest.h++"
#include "gtest/gtest.h"

TEST(KClosestTest, One) {
    KClosest soln = KClosest();
    vector<vector<int>> input = {{0,2},{2,2}};
    vector<vector<int>> closest = soln.kClosest(input, 1);
    vector<vector<int>> expected ={{0, 2}};
    EXPECT_EQ(closest, expected);
}
