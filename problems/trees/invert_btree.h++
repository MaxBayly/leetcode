#ifndef LEETCODE_INVERT_BTREE_H
#define LEETCODE_INVERT_BTREE_H
#include <bits/stl_list.h>

#include "btree.h++"


class Inverter {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) {
            return nullptr;
        }
        // aka
        // TreeNode* left = root->left;
        // TreeNode* right = root->right;
        // root->left = right;
        // root->right = left;
        std::swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);

        return root;
    }


};
#endif //LEETCODE_INVERT_BTREE_H

