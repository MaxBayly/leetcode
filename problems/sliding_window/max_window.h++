

#ifndef LEETCODEC_MAX_WINDOW_H
#define LEETCODEC_MAX_WINDOW_H

#pragma once

#include <vector>
#include <string>
#include <queue>


using namespace std;

class max_window
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        /**
         * build max heap from window - add max to res array
         * slide: pop leftmost, add rightmost
         */
        vector<int> res;

        priority_queue<pair<int, int>> heap;
        for (int i = 0; i < k; i++) {
            heap.push({nums[i], i});
        }
        res.push_back(heap.top().first);

        int right = k;
        int left = 1;

        while (right < nums.size()) {
            heap.push({nums[right], right});
            while (heap.top().second < left) {
                heap.pop();
            }
            res.push_back(heap.top().first);
            right++;
            left++;
        }

        return res;
    }
};

#endif // LEETCODEC_MAX_WINDOW_H
