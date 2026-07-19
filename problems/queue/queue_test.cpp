#include "k_closest.h++"
#include "scheduler.h++"
#include "gtest/gtest.h"

TEST(KClosestTest, One) {
    KClosest soln = KClosest();
    vector<vector<int>> input = {{0,2},{2,2}};
    vector<vector<int>> closest = soln.kClosest(input, 1);
    vector<vector<int>> expected ={{0, 2}};
    EXPECT_EQ(closest, expected);
}

TEST(SchedulerTest, One) {
    vector tasks = {'A','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    int n = 29;
    Scheduler soln;
    EXPECT_EQ(soln.leastInterval(tasks, n), 31);
}