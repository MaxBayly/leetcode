#ifndef LEETCODE_RIGHT_SIDE_H
#define LEETCODE_RIGHT_SIDE_H
#include <vector>
#include <stack>

#include "btree.h++"

using namespace std;
class RightSide {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (!root) {return {};}

        vector<int> visible = {};
        deque<TreeNode*> level;
        level.emplace_back(root);

        while (!level.empty()) {
            deque<TreeNode*> sub;
            visible.emplace_back(level.back()->val);
            while (!level.empty()) {
                if (level.front()->left) {sub.emplace_back(level.front()->left); }
                if (level.front()->right) {sub.emplace_back(level.front()->right); }
                level.pop_front();
            }

            level = sub;
        }

        return visible;
    }
};
#endif //LEETCODE_RIGHT_SIDE_H
