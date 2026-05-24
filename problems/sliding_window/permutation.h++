

#ifndef LEETCODEC_PERMUTATION_H
#define LEETCODEC_PERMUTATION_H
#pragma once

#include <vector>

using namespace std;

class permutation
{
public:
    bool checkInclusion(string s1, string s2)
    {
        //string s1 = "ab", s2 = "lecabee";
        int char_offset = 97;
        if (s1.length() > s2.length()) {
            return false;
        }
        vector<int> s1_freq(26);
        vector<int> window_freq(26);

        for (char c:s1) {
            s1_freq[c-char_offset]++;
        }

        for (int i = 0; i < s1.size(); i++) {
            window_freq[s2[i] - char_offset]++;
        }

        if (s1_freq == window_freq) {
            return true;
        }

        for (int left = 1; left + s1.length() - 1 < s2.length(); left++) {
            int right = left + s1.length() - 1;
            window_freq[s2[left-1] - char_offset]--;
            window_freq[s2[right] - char_offset]++;
            if (window_freq == s1_freq) {
                return true;
            }
        }
        return false;
    }
};

#endif //LEETCODEC_PERMUTATION_H
