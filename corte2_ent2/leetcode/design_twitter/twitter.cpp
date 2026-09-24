#include <bits/stdc++.h>
using namespace std;

class Twitter {
private:
    struct Tweet {
        int tweetId;
        int time;
    };

    unordered_map<int, vector<Tweet>> tweets;
    unordered_map<int, unordered_set<int>> following;

    int currentTime;

public:
    Twitter() {
        currentTime = 0;
    }

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({tweetId, currentTime});
        currentTime++;
    }

    vector<int> getNewsFeed(int userId) {
        vector<Tweet> allTweets;

        for (const Tweet& tweet : tweets[userId]) {
            allTweets.push_back(tweet);
        }

        for (int followedUser : following[userId]) {
            for (const Tweet& tweet : tweets[followedUser]) {
                allTweets.push_back(tweet);
            }
        }

        sort(allTweets.begin(), allTweets.end(),
             [](const Tweet& a, const Tweet& b) {
                 return a.time > b.time;
             });

        vector<int> result;

        for (int i = 0; i < min(10, (int)allTweets.size()); i++) {
            result.push_back(allTweets[i].tweetId);
        }

        return result;
    }

    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};
