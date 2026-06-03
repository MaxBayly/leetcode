#ifndef LEETCODE_DOUBLE_MEDIAN_H
#define LEETCODE_DOUBLE_MEDIAN_H
#include <limits.h>
#include <vector>

using namespace std;

class DoubleMedian {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>* smaller;
        vector<int>* larger;
        if (nums1.size() <= nums2.size()) {
            smaller = &nums1;
            larger = &nums2;
        } else {
            smaller = &nums2;
            larger = &nums1;
        }

        int total = smaller->size() + larger->size();
        int half = (total + 1)/2;
        int left = 0;
        int right = smaller->size();
        while (left <= right) {
            int partA = (left + right)/2;
            int partB = half - partA;

            int leftA = partA > 0 ? smaller->at(partA - 1) :  INT_MIN;
            int rightA = partA < smaller->size() ? smaller->at(partA) : INT_MAX;
            int leftB = partB > 0 ? larger->at(partB - 1) : INT_MIN;
            int rightB = partB < larger->size() ? larger->at(partB) : INT_MAX;

            if (leftA <= rightB && leftB <= rightA) {
                if ((smaller->size() + larger->size()) % 2) {
                    return max(leftA, leftB);
                }
                return (max(leftA, leftB) + min(rightA, rightB)) / 2.0;
            }
            if (leftA > rightB) {
                right = partA - 1;
            }
            if (leftB > rightA) {
                left = partA + 1;
            }
            
        }

        return -1;


    }
};
#endif //LEETCODE_DOUBLE_MEDIAN_H
