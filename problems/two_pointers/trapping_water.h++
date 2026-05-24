

#ifndef LEETCODEC_TRAPPING_WATER_H
#define LEETCODEC_TRAPPING_WATER_H
#pragma once

#include <algorithm>
#include <fmt/ranges.h>
#include <vector>
#include <stack>

using namespace std;

class trapping_water {
public:
    int trap(vector<int> &height) {
        // [0, 2, 0, 3, 1, 0, 1, 3, 2, 1]
        // [0, 0, 2, 2, 3, 3, 3, 3, 3, 3]
        // [3, 3, 3, 3, 3, 3, 3, 2, 1, 0]
        int res = 0;
        vector<int> prefix;
        vector<int> suffix(height.size());
        int prefix_max = 0;
        int suffix_max = 0;
        for (auto h : height) {
            prefix.push_back(prefix_max);
            if (h > prefix_max) {
                prefix_max = h;
            }
        }

        for (int h = height.size() - 1; h >= 0; h--) {
            suffix[h] = (suffix_max);
            if (height[h] > suffix_max) {
                suffix_max = height[h];
            }
        }

        fmt::println("Prefixes: {}", prefix);
        fmt::println("Suffixes: {}", suffix);

        for (int i = 0; i < height.size() - 1; i++) {
            int volume = min(prefix[i], suffix[i]) - height[i];
            fmt::println("At position {}, prefix is {}, suffix is {}, volume is {}",
                         i, prefix[i], suffix[i], volume);
            if (volume > 0) {
                res += volume;
            }
        }

        return res;
    }

    int trap_stack(vector<int>& height) {
        if (height.empty()) {
            return 0;
        }

        stack<int> stk;
        int res = 0;

        for (int i = 0; i < height.size(); i++) {
            fmt::println("i is {}, height is {}, stack is {}", i, height[i], stk);
            while (!stk.empty() && height[i] >= height[stk.top()]) {
                int mid = height[stk.top()];
                stk.pop();
                fmt::println("popped: {}", stk);
                if (!stk.empty()) {
                    int right = height[i];
                    int left = height[stk.top()];
                    int h = min(right, left) - mid;
                    int w = i - stk.top() - 1;
                    res += h * w;
                }
            }
            stk.push(i);
        }

        return res;
    }
};

#endif //LEETCODEC_TRAPPING_WATER_H
