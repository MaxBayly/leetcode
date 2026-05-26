

#ifndef LEETCODE_VALID_PARENTHESES_H
#define LEETCODE_VALID_PARENTHESES_H

#include <stack>
#include <vector>
#include <map>
#include <algorithm>

#include "gtest/gtest.h"

using namespace std;

class valid_parentheses {
public:
    bool isValid(string s) {
        vector opening = {'[', '{', '('};
        map<char, char> pairs = {{']', '['}, {'}', '{'}, {')', '('}};
        stack<char> parens;
        for (char c:s) {
            if (ranges::find(opening, c) != opening.end()) {
                parens.push(c);
            } else {
                if (parens.empty()) {
                    return false;
                }
                if (parens.top() == pairs[c]) {
                    parens.pop();
                } else {
                    return false;
                }
            }
        }
        return parens.empty();
    }
};

#endif //LEETCODE_VALID_PARENTHESES_H


