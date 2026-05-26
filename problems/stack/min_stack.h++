

#ifndef LEETCODE_MIN_STACK_H
#define LEETCODE_MIN_STACK_H

#include <vector>

#include "gtest/gtest.h"

using namespace std;

class MinStack {
    vector<int> elements;
    vector<int> mins;
    int size = 0;
public:
    void push(int val) {
        elements.push_back(val);
        if (size == 0) {
            mins.push_back(val);
        } else {
            mins.push_back(min(val, mins[size - 1]));
        }
        size++;
    }

    void pop() {
        elements.pop_back();
        mins.pop_back();
        size--;
    }

    int top() {
        return elements[size - 1];
    }

    int getMin() {
        return mins[size - 1];
    }
};

#endif //LEETCODE_MIN_STACK_H

