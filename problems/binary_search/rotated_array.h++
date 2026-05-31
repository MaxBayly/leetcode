#ifndef LEETCODE_ROTATED_ARRAY_H
#define LEETCODE_ROTATED_ARRAY_H
#include <vector>

using namespace std;
class RotatedArray {
public:
    int findMin(std::vector<int> &nums) {
        int left = 0;
        int right = nums.size() - 1;
        while (left < right - 1) {
            int mid = (left + right)/2;
            if (nums[mid] > nums[left] && nums[mid] > nums[right]) {
                left = mid;
            } else if (nums[mid] < nums[left] && nums[mid] < nums[right]) {
                right = mid;
            } else if (nums[mid] > nums[left] && nums[mid] < nums[right]) {
                right = mid;
            }
        }
        return min(nums[left], nums[right]);
    }
};

#endif //LEETCODE_ROTATED_ARRAY_H
