#include "k_closest.h++"
#include "scheduler.h++"
#include "twitter.h++"
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

TEST(TwitterTest, One) {
    Twitter twitter = Twitter();
    twitter.postTweet(1, 10); // User 1 posts a new tweet with id = 10.
    twitter.postTweet(2, 20); // User 2 posts a new tweet with id = 20.
    twitter.getNewsFeed(1);   // User 1's news feed should only contain their own tweets -> [10].
    twitter.getNewsFeed(2);   // User 2's news feed should only contain their own tweets -> [20].
    twitter.follow(1, 2);     // User 1 follows user 2.
    vector<int> feed = twitter.getNewsFeed(1);   // User 1's news feed should contain both tweets from user 1 and user 2 -> [20, 10].
    twitter.getNewsFeed(2);   // User 2's news feed should still only contain their own tweets -> [20].
    twitter.unfollow(1, 2);   // User 1 unfollows user 2.
    twitter.getNewsFeed(1);   // User 1's news feed should only contain their own tweets -> [10].
}

TEST(TwitterTest, Two) {
    Twitter twitter = Twitter();
    twitter.postTweet(1, 100);
    twitter.follow(1, 1);
    twitter.getNewsFeed(1);
    twitter.unfollow(1, 1);
    twitter.getNewsFeed(1);
}

TEST(TwitterTest, Three) {
    Twitter twitter = Twitter();
    twitter.postTweet(1, 101);
    twitter.postTweet(1, 102);
    twitter.follow(2, 1);
    twitter.getNewsFeed(2);
    twitter.unfollow(2, 1);
    twitter.getNewsFeed(2);
}