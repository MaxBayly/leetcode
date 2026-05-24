

#ifndef LEETCODEC_TWO_SUM_II_H
#define LEETCODEC_TWO_SUM_II_H
#pragma once

#include <vector>

using namespace std;

class two_sum_ii {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;
        while (true) {
            int sum = numbers[left] + numbers[right];
            if (sum == target) {
                return vector({left + 1, right + 1});
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }
    }
};

#endif //LEETCODEC_TWO_SUM_II_H
