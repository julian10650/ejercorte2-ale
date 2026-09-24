#include <iostream>
#include <vector>
#include "../corte2_ent2/leetcode/design_twitter/twitter.cpp"

using namespace std;

int main() {
    Twitter twitter;

    twitter.postTweet(1, 5);

    vector<int> feed = twitter.getNewsFeed(1);

    if (feed.size() != 1 || feed[0] != 5) {
        cerr << "Twitter: ERROR" << endl;
        return 1;
    }

    twitter.follow(1, 2);
    twitter.postTweet(2, 6);

    feed = twitter.getNewsFeed(1);

    if (feed.size() != 2 || feed[0] != 6 || feed[1] != 5) {
        cerr << "Twitter: ERROR en follow/feed" << endl;
        return 1;
    }

    twitter.unfollow(1, 2);

    feed = twitter.getNewsFeed(1);

    if (feed.size() != 1 || feed[0] != 5) {
        cerr << "Twitter: ERROR en unfollow" << endl;
        return 1;
    }

    cout << "Twitter: OK" << endl;

    return 0;
}
