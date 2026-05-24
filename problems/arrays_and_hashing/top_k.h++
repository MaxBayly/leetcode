

#ifndef LEETCODEC_TOP_K_H
#define LEETCODEC_TOP_K_H

#pragma once
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <fmt/ranges.h>

using namespace std;
class top_k {
public:
    vector<int> topKFrequent(vector<int> &nums, int k) {
        map<int, int> hashed;
        for (auto num:nums) {
            hashed[num] += 1;
        }

        fmt::print("{}", hashed);

        vector<pair<int, int>> counts;
        for (auto entry:hashed) {
            pair<int, int> swapped_entry = entry;
            swap(swapped_entry.first, swapped_entry.second);

            counts.push_back(swapped_entry);
        }
        fmt::print("{}", counts);
        sort(counts.begin(), counts.end());

        fmt::print("{}", counts);


        vector<int> top;
        for (int i = 0; i < k; i++ ) {
            top.push_back(counts[counts.size() - i -1].second);
        }

        return top;
    }
};


#endif //LEETCODEC_TOP_K_H
