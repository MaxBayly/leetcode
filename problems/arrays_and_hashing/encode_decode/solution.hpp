#pragma once
#include <cstdio>
#include <string>
#include <vector>
#include <format>
#include <fmt/ranges.h>

using namespace std;
class Solution {
public:
  string encode(vector<string> &strs) {
      string encoded = "";
      for (auto str : strs) {
          int len = str.length();
          encoded += format("{:03}", len);
          encoded += str;
      }

      return encoded;
  }

  vector<string> decode(string s) {
      vector<string> decoded;
      if (s.size() == 0) {
          return decoded;
      }

      int read = 0;
      while (read < s.size()) {
          int str_size = stoi(s.substr(read, 3));
          string decoded_string = s.substr(read + 3, str_size);
          decoded.push_back(decoded_string);
          read += 3 + str_size;
      }
      return decoded;
  }
};
