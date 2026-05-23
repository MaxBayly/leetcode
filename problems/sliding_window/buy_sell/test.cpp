#include "../../../include/lc_test.hpp"
#include "solution.hpp"
#include <vector>

using namespace std;

void test_placeholder() {
    Solution soln;
  vector<int> input = {10, 1, 5, 6, 7, 1};
  EXPECT_EQ(soln.maxProfitDynamic(input), 6);
}

int main() {
  test_placeholder();
  return lc_test::summary();
}
