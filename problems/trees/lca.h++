#ifndef LEETCODE_LCA_H
#define LEETCODE_LCA_H
#include "btree.h++"

class LCA {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if ((p->val <= root->val && root->val <= q->val) || (q->val <= root->val && root->val <= p->val)) {
            return root;
        }

        if (root->val < p->val && root->val < q->val) {
            return lowestCommonAncestor(root->right, p, q);
        }
        return lowestCommonAncestor(root->left, p, q);
    }
};
#endif //LEETCODE_LCA_H
