#pragma once

#include <vector>
#include <fmt/ranges.h>
using namespace std;

class Solution {
public:
  int maxProfit(vector<int> &prices) {
      vector<int> prefix(prices.size()), suffix(prices.size());
      int min_prefix = prices[0]; prefix[0] = min_prefix;
      int max_suffix = prices[prices.size() - 1]; suffix[prices.size() - 1] = max_suffix;
      for (size_t i = 1; i < prices.size(); i++) {
          min_prefix = min(prices[i], min_prefix);
          max_suffix = max(prices[prices.size() - 1 - i], max_suffix);
          prefix[i] = min_prefix;
          suffix[prices.size() - 1 - i] = max_suffix;
      }
      int max_spread = 0;
      for (size_t i = 0; i < prices.size(); i++) {
          int spread = suffix[i] - prefix[i];
          max_spread = max(spread, max_spread);
      }
      return max_spread;
  }

  int maxProfitDynamic(vector<int> &prices) {
      int lowest = prices[0];
      int max_spread = 0;
      for (auto price:prices) {
          lowest = min(lowest, price);
          max_spread = max(max_spread, price - lowest);
      }

      return max_spread;
  }
};
