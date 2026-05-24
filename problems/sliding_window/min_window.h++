

#ifndef LEETCODEC_MIN_WINDOW_H
#define LEETCODEC_MIN_WINDOW_H

#pragma once

#include <vector>
#include <string>

using namespace std;

class min_window
{
public:
  string minWindow(string s, string t)
  {
    /**
     * Algorithm:
     *  count frequencies in target string
     *  count frequencies in first window of length of target string
     *  if frequencies match, return that window; otherwise
     *  set left = 0, right = t.length()
     *  while right < s.length():
     *     increment right, increment frequency of char at right
     *     if the counts now match,
     *        while matches == 26:
     *          decrement frequency of char at left
     *          increment left
     *          adjust match count
     *        store min(window width, res)
     *
     *  This is a relatively ugly implementation...
     */
    if (t.length() > s.length())
    {
      return "";
    }

    if (t.length() == 1 && s.length() == 1)
    {
      if (t == s)
      {
        return t;
      }
      else
      {
        return "";
      }
    }

    const int char_offset = 65; // uppercase
    vector<int> freq(122);
    vector<int> window_freq(122);
    for (char c : t)
    {
      freq[c - char_offset]++;
    }

    for (int i = 0; i < t.length(); i++)
    {
      window_freq[s[i] - char_offset]++;
    }

    int matches = 0;

    pair<int, int> res = {0, s.length()};

    for (int i = 0; i < 122; i++)
    {
      if (window_freq[i] >= freq[i])
      {
        matches++;
      }
    }

    if (matches == 122)
    {
      return s.substr(0, t.length());
    }

    bool matched = false;
    int left = 0;
    int right = t.length();

    while (right < s.length())
    {
      char left_char = s[left];
      char right_char = s[right];
      window_freq[s[right] - char_offset]++;
      if (window_freq[s[right] - char_offset] == freq[s[right] - char_offset])
      {
        matches++;
      }
      if (matches == 122)
      {
        matched = true;
        while (window_freq[s[left] - char_offset] > freq[s[left] - char_offset])
        {
          window_freq[s[left] - char_offset]--;
          left++;
        }
        if ((right - left) < (res.second - res.first))
        {
          res = {left, right};
        }
        window_freq[s[left] - char_offset]--;
        left++;
        matches--;
      }
      right++;
    }

    if (matched)
    {
      return s.substr(res.first, ((res.second - res.first) + 1));
    }
    else
    {
      return "";
    }
  }
};


#endif //LEETCODEC_MIN_WINDOW_H
