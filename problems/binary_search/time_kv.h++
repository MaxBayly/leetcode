#ifndef LEETCODE_TIME_KV_H
#define LEETCODE_TIME_KV_H
#include <map>
#include <string>
#include <vector>

using namespace std;

class TimeMap {
    map<string, vector<pair<int,string>>> entries;
public:
    void set(string key, string value, int timestamp) {
        // problem stipulates that timestamp is strictly increasing over input space, so
        // no extra work is needed to maintain the sort
        vector<pair<int, string>> entr = {{timestamp, value}};
        entries[key].emplace_back(timestamp, value);
    }

    string get(string key, int timestamp) {
        vector<pair<int, string>> entry = entries[key];
        int left = 0;
        int right = entry.size() - 1;
        int largestTimestampIdx = -1;
        while (left <= right) {
            int mid = (left + right) / 2;
            int currentTimestamp = entry[mid].first;
            if (currentTimestamp == timestamp) {
                return entry[mid].second;
            }
            if (currentTimestamp < timestamp) {
                largestTimestampIdx = max(mid, largestTimestampIdx);
                left = mid + 1;
            }
            else {
                right = mid -1;
            }
        }
        if (largestTimestampIdx == -1) {
            return "";
        }
        return entry[largestTimestampIdx].second;
    }
};
#endif //LEETCODE_TIME_KV_H
