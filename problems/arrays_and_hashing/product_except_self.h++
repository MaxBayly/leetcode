

#ifndef LEETCODEC_PRODUCT_EXCEPT_SELF_H
#define LEETCODEC_PRODUCT_EXCEPT_SELF_H

#pragma once
#include <vector>

using namespace std;

class product_except_self {
public:
    vector<int> productExceptSelf(vector<int> &nums) {
        size_t prefix = 1;
        vector<int> result;
        for (int pref = 0; pref < nums.size(); pref++) {
            result.push_back(prefix);
            prefix *= nums[pref];
        }

        size_t postfix = 1;
        for (int post = nums.size() - 1; post >= 0; post--) {
            result[post] *= postfix;
            postfix *= nums[post];
        }

        return result;
    }
};


#endif //LEETCODEC_PRODUCT_EXCEPT_SELF_H
