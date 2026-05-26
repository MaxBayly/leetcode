

#ifndef LEETCODE_RPN_H
#define LEETCODE_RPN_H
#include <stack>
#include <vector>

#include "gtest/gtest.h"

using namespace std;

class RPN {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> vals;
        vector<string> operators = {"+", "-", "*", "/"};
        for (string s:tokens) {
            int res;
            if (ranges::find(operators, s) != operators.end()) {
                int val1 = vals.top();
                vals.pop();
                int val2 = vals.top();
                vals.pop();
                if (s == "-") {
                    res = val2 - val1;
                } else if (s == "+") {
                    res = val2 + val1;
                } else if (s == "*") {
                    res = val2 * val1;
                } else if (s == "/") {
                    res = val2 / val1;
                }
                vals.push(res);
            } else {
                vals.push(stoi(s));
            }
        }

        return vals.top();
    }
};
#endif //LEETCODE_RPN_H

