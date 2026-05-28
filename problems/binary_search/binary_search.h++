#ifndef LEETCODE_BINARY_SEARCH_H
#define LEETCODE_BINARY_SEARCH_H
#include <vector>
using namespace std;
class BinarySearch {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int idx = (right + left)/2;
            int current = nums[idx];
            if (current == target) {
                return idx;
            }
            if (current < target) {
                left = idx + 1;
            } else {
                right = idx - 1;
            }
        }

        return -1;
    }
};

#endif //LEETCODE_BINARY_SEARCH_H
