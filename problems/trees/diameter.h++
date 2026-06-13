#ifndef LEETCODE_DIAMETER_H
#define LEETCODE_DIAMETER_H
#include <algorithm>

#include "btree.h++"
using namespace std;
class Diameter {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int maxDepth = 0;
        // have to separate the call and return, because the
        // last invocation of DFS will increment the depth
        // one too many times - so we want to make sure we
        // return the pointer value here and not the return
        // value of dfs
        dfs(root, maxDepth);
        return maxDepth;
    }
private:
    int dfs(TreeNode* node, int& result) {
        if (!node) {
            return 0;
        }

        int leftDepth = dfs(node->left, result);
        int rightDepth = dfs(node->right, result);
        result = max(result, leftDepth + rightDepth);
        return 1 + max(leftDepth, rightDepth);
    }
};
#endif //LEETCODE_DIAMETER_H
