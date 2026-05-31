#ifndef LEETCODE_ROTATED_SEARCH_H
#define LEETCODE_ROTATED_SEARCH_H
#include <vector>
using namespace std;
class RotatedSearch {
public:
    int search(vector<int>& nums, int target) {
        pair res = {nums[0], 0};
        int l = 0;
        int r = nums.size() - 1;

        while (l <= r) {
            if (nums[l] < nums[r]) {
                if (nums[l] < res.first) {
                    res = {nums[l], l};
                }
                break;
            }
            int m = l + (r - l) / 2;
            if (nums[m] < res.first) {
                res = {nums[m], m};
            }

            if (nums[m] >= nums[l]) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        int mindex = res.second;

        int left, right;
        if (target <= nums.back()) {
            left = mindex;
            right = nums.size() - 1;
        } else {
            left = 0;
            right = mindex - 1;
        }

        while (left <= right) {
            int mid = (left + right)/2;
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return -1;
    }
};
#endif //LEETCODE_ROTATED_SEARCH_H
