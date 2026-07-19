
#include <map>
#include <queue>
#include <vector>

using namespace std;

class Tweet {
public:
    Tweet(int count, int id) {
        this->count = count;
        this->id = id;
    }
    int count;
    int id;
};

class FeedItem {
public:
    FeedItem(Tweet tweet, int userId, int next) : tweet(tweet) {
        this->tweet = tweet;
        this->userId = userId;
        this->next = next;
    }

    int getNext() const {
        return this->next;
    }

    void setNext() {
        this->next--;
    }

    Tweet getTweet() {
        return this->tweet;
    }

    int getUser() const {
        return this->userId;
    }

    bool operator>(const FeedItem& other) const {
        return this->tweet.count > other.tweet.count;
    }
private:
    Tweet tweet;
    int userId;
    int next;
};

class User {
public:
    User(int id) {
        this->id = id;
        this->addFollower(id);
    }
    void tweet(Tweet tweet) {
        tweets.push_back(tweet);
    }
    void addFollower(int followeeId) {
        following[followeeId] = true;
    }

    void removeFollower(int followeeId) {
        following[followeeId] = false;
    }

    map<int, bool> getFollowing() {
        return this->following;
    }

    vector<Tweet> getTweets() {
        return this->tweets;
    }

private:
    map<int, bool> following;
    vector<Tweet> tweets;
    int id;
};


class Twitter {
public:
    Twitter() {
        this->tweetCount = 0;
    }

    void postTweet(int userId, int tweetId) {
        tweetCount--;
        auto[it, inserted] = users.try_emplace(userId, userId);

        it->second.tweet(Tweet(tweetCount, tweetId));
    }

    vector<int> getNewsFeed(int userId) {
        vector<int> result;
        auto it = users.find(userId);
        User user =it->second;
        priority_queue<FeedItem, vector<FeedItem>, greater<>> feed;
        for (auto status : user.getFollowing()) {
            if (status.second) {
                auto it2 = users.find(status.first);
                vector<Tweet> tweets = it2->second.getTweets();
                if (!tweets.empty()) {
                    Tweet latestTweet = tweets.back();
                    FeedItem item = FeedItem(latestTweet, status.first, tweets.size() - 2);
                    feed.emplace(item);
                }
            }
        }

        while (!feed.empty() && result.size() < 10) {
            FeedItem item = feed.top();
            feed.pop();
            result.push_back(item.getTweet().id);
            if (item.getNext() >= 0) {
                auto it = users.find(item.getUser());
                Tweet nextTweet = it->second.getTweets()[item.getNext()];
                FeedItem nextItem = FeedItem(nextTweet, item.getUser(), item.getNext() - 1);
                feed.emplace(nextItem);
            }
        }

        return result;
    }

    void follow(int followerId, int followeeId) {
        auto it = users.find(followerId);
        if (it == users.end()) {
            auto result = users.emplace(followerId, User(followerId));
            it = result.first;
        }
        it->second.addFollower(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        if (followerId == followeeId) {
            return;
        }
        auto it = users.find(followerId);

        it->second.removeFollower(followeeId);
    }
private:
    int tweetCount;
    map<int, User> users;
};

