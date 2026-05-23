#pragma once
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> productExceptSelf(vector<int> &nums) {
      size_t prefix = 1;
      vector<int> result;
      for (int pref = 0; pref < nums.size(); pref++) {
          result.push_back(prefix);
          prefix *= nums[pref];
      }

      size_t postfix = 1;
      for (int post = nums.size() - 1; post >= 0; post--) {
          result[post] *= postfix;
          postfix *= nums[post];
      }

      return result;
  }
};
