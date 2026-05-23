#include "solution.hpp"
#include "../../../include/lc_test.hpp"
#include <vector>

void test_1() {
    Solution soln;
    vector<string> input = {"Hello","World"};
    string encoded = soln.encode(input);
    vector<string> decoded = soln.decode(encoded);
  EXPECT_EQ(decoded, input);
}

int main() {
  test_1();
  return lc_test::summary();
}
