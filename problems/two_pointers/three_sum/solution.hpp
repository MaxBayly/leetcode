#pragma once

#include <algorithm>
#include <fmt/ranges.h>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    for (size_t i = 0; i < nums.size() - 2; i++) {
      if (nums[i] > 0) {
        break;
      }
      if (i > 0 && nums[i] == nums[i - 1]) {
        continue;
      }
      int left = i + 1;
      int right = nums.size() - 1;

      while (left < right) {
        int sum = nums[left] + nums[right] + nums[i];
        if (sum > 0) {
          right--;
        } else if (sum < 0) {
          left++;
        } else {
          res.push_back({nums[left], nums[right], nums[i]});
          left++;
          right--;
          // deduplicate on left
          while (left < right && nums[left] == nums[left - 1]) {
            left++;
          }
        }
      }
    }
    return res;
  }
};
