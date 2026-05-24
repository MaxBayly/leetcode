

#ifndef LEETCODEC_LONGEST_SUBSTRING_H
#define LEETCODEC_LONGEST_SUBSTRING_H

#pragma once

#include <fmt/ranges.h>
#include <set>
#include <string>
#include <vector>

using namespace std;

class longest_substring {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0) {
            return 0;
        }

        vector<char> chars(s.begin(), s.end());
        int window_size = 1;
        int left = 0;
        int right = 0;
        set<char> window;
        while (right < chars.size()) {
            fmt::println("Window: {}\nInspecting: {}", window, chars[right]);
            if (window.insert(chars[right]).second) {
                right++;
                window_size = max(window_size, static_cast<int>(window.size()));
            } else {
                while (window.contains(chars[right])) {
                    fmt::println("Removing {}", chars[left]);
                    window.erase(chars[left]);
                    left++;
                }
                window.insert(chars[right]);
                right++;
            }
        }

        return window_size;
    }
};


#endif //LEETCODEC_LONGEST_SUBSTRING_H
