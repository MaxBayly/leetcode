#ifndef LEETCODE_BALANCED_H
#define LEETCODE_BALANCED_H
#include <algorithm>

#include "btree.h++"
using namespace std;
class Balanced {
public:
    bool isBalanced(TreeNode* root) {
        bool balanced = true;
        dfs(root, balanced);
        return balanced;
    }
private:
    int dfs(TreeNode* node, bool& balanced) {
        if (!node) {
            return 0;
        }

        int leftDepth = dfs(node->left, balanced);
        int rightDepth = dfs(node->right, balanced);
        int diff = leftDepth - rightDepth;

        balanced = balanced && diff * diff <= 1;

        return 1 + ranges::max(leftDepth, rightDepth);

    }
};

class BalancedNoPointer {
    public:
    bool isBalanced(TreeNode* root) {
        return dfs(root).second;
    }
    private:
    pair<int, bool> dfs(TreeNode* node) {
        if (!node) {
            return {0, true};
        }

        auto [ leftDepth, leftBalanced ]  = dfs(node->left);
        auto [ rightDepth, rightBalanced ] = dfs(node->right);
        int diff = leftDepth - rightDepth;

        bool balanced = diff * diff <= 1 && leftBalanced && rightBalanced;

        int depth = 1 + max(leftDepth, rightDepth);

        return {depth, balanced};

    }
};
#endif //LEETCODE_BALANCED_H
