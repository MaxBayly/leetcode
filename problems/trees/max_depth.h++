#ifndef LEETCODE_MAX_DEPTH_H
#define LEETCODE_MAX_DEPTH_H
#include <algorithm>

#include "btree.h++"

class Depth {
public:
    int maxDepth(TreeNode* root) {
        return dfs(root, 0);
    }

    int dfs(TreeNode* node, int current) {
        if (!node) {
            return current;
        }

        current++;
        return std::ranges::max(dfs(node->left, current), dfs(node->right, current));
    }
};
#endif //LEETCODE_MAX_DEPTH_H
