

#ifndef LEETCODEC_REPLACEMENT_H
#define LEETCODEC_REPLACEMENT_H
#pragma once

#include <fmt/ranges.h>
#include <map>
#include <vector>
#include <iostream>

using namespace std;

class replacement
{
public:
    int characterReplacement(string s, int k)
    {
        vector<char> chars(s.begin(), s.end());
        int res = 0;
        int left = 0;
        int right = 0;
        int max_frequency = 0;
        map<char, int> window;
        while (right < chars.size())
        {
            window[chars[right]]++;
            max_frequency = max(max_frequency, window[chars[right]]);

            int window_size = (right - left) + 1;
            int replacement_count = window_size - max_frequency;
            while (replacement_count > k)
            {
                window[chars[left]]--;
                left++;
                window_size = (right - left) + 1;
                replacement_count = window_size - max_frequency;
            }
            res = max(res, window_size);
            right++;
        }
        return res;
    }
};

/**
 * Invariant description
 *
 * - Let M be the tracked max_frequency (never decreased), so M is monotonic non-decreasing.
 * - Window is maintained so window_len - M <= k after shrinking.
 * - Because M may be stale, this condition is optimistic: some maintained windows may be actually invalid (window_len - true_max > k).
 * - But stale M only delays shrinking; it never causes over-shrinking, so no valid candidate length is missed.
 * - Suppose res = L is recorded. Then at that moment L - M <= k, i.e. L <= M + k.
 * - M came from a real window where some char count reached M (not fabricated).
 * - Therefore L cannot exceed what is supportable by observed frequencies plus k replacements; if window grows too far, even optimistic check fails and left advances.
 * - Hence temporary invalid windows may appear, but final maximal res is still the true optimum.
 */

#endif //LEETCODEC_REPLACEMENT_H
