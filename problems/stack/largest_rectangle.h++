#ifndef LEETCODE_LARGEST_RECTANGLE_H
#define LEETCODE_LARGEST_RECTANGLE_H

#include <vector>
#include <stack>

using namespace std;

class LargestRectangle {
public:
    int largestRectangleArea(vector<int> &heights) {
        if (heights.size() == 1) {
            return heights[0];
        }
        if (heights.size() == 0) {
            return 0;
        }
        stack<int> stackLTOR;
        vector<int> nextSmallestOnRight(heights.size());
        for (int i = 0; i < heights.size(); i++) {
            while (!stackLTOR.empty() && heights[i] < heights[stackLTOR.top()]) {
                nextSmallestOnRight[stackLTOR.top()] = i;
                stackLTOR.pop();
            }
            stackLTOR.push(i);
        }

        stack<int> stackRTOL;
        vector<int> nextSmallestOnLeft(heights.size(), heights.size());
        for (int i = heights.size() - 1; i >= 0; i--) {
            while (!stackRTOL.empty() && heights[i] < heights[stackRTOL.top()]) {
                nextSmallestOnLeft[stackRTOL.top()] = i;
                stackRTOL.pop();
            }
            stackRTOL.push(i);
        }
        int maxRectangle = 0;
        for (int i = 0; i < heights.size(); i++) {
            int right = (nextSmallestOnRight[i]? nextSmallestOnRight[i] : heights.size()) - 1 ;
            int left = (nextSmallestOnLeft[i] == heights.size())? 0 : nextSmallestOnLeft[i] + 1;
            int height = heights[i];
            int width = (right - left + 1);
            int area = height * width;
            maxRectangle = max(maxRectangle, area);
        }

        return maxRectangle;
    }
};


#endif //LEETCODE_LARGEST_RECTANGLE_H
