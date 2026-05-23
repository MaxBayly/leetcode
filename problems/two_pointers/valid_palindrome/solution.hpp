#pragma once
#include <algorithm>
#include <cctype>
#include <fmt/ranges.h>
#include <string>

using namespace std;

class Solution {
public:
  bool isPalindrome(string s) {
    int left = 0;
    int right = s.length() - 1;
    while (left < right) {
      while (left < right && !isAlphaNumAscii(s[left])) {
        left++;
      }
      while (right > left && !isAlphaNumAscii(s[right])) {
        right--;
      }
      if (tolower(s[left]) != tolower(s[right])) {
        return false;
      }
      left++;
      right--;
    }

    return true;
  }

  bool isAlphaNumAscii(char c) {
    return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') ||
            (c >= '0' && c <= '9'));
  }
};
