#ifndef LEETCODE_SAME_TREE_H
#define LEETCODE_SAME_TREE_H
#include "problems/trees/btree.h++"

class SameTree {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p != !q) {
            return false;
        }
        if (!p && !q) {
            return true;
        }

        bool leftSame = isSameTree(p->left, q->left);
        bool rightSame = isSameTree(p->right, q->right);
        return leftSame && rightSame && (p->val == q->val);
    }
};
#endif //LEETCODE_SAME_TREE_H
