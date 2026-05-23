#pragma once
#include <cstddef>
#include <vector>
#include <algorithm>
#include <fmt/ranges.h>
#include <iostream>

using namespace std;

class Solution {
public:
  int longestConsecutive(vector<int> &nums) {
      if (nums.size() == 0) {
          return 0;
      }
      sort(nums.begin(), nums.end());
      int longest = 1;
      int current = 1;
      for (size_t i = 1; i < nums.size(); i++) {
          if (nums[i] == nums[i-1]) {
              continue;
          } else if (nums[i] == nums[i-1] + 1) {
              current += 1;
          } else if (current > longest) {
              longest = current;
              current = 1;
          } else {
              current = 1;
          }
      }
      return max(longest, current);
  }
};
