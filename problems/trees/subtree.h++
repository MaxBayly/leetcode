#ifndef LEETCODE_SUBTREE_H
#define LEETCODE_SUBTREE_H
#include "btree.h++"

class Subtree {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root) {
            return false;
        }
        if (isSameTree(root, subRoot)) {
            return true;
        }

        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
private:
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
#endif //LEETCODE_SUBTREE_H
