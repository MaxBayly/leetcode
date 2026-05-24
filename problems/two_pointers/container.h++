

#ifndef LEETCODEC_CONTAINER_H
#define LEETCODEC_CONTAINER_H
#pragma once

#include <vector>
#include <fmt/ranges.h>

using namespace std;

class container {
public:
    int maxArea(vector<int> &heights) {
        int largest = 0;
        int left = 0;
        int right = heights.size() - 1;
        while (left < right) {
            int height = min(heights[left], heights[right]);
            int vol = height * (right - left);
            if (vol > largest) {
                largest = vol;
            }
            if (heights[left] <= heights[right]) {
                left++;
            } else {
                right--;
            }
        }
        return largest;
    }
};

#endif //LEETCODEC_CONTAINER_H
