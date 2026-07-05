#ifndef LEETCODE_LEVEL_ORDER_TRAVERSAL_H
#define LEETCODE_LEVEL_ORDER_TRAVERSAL_H
#include <vector>

#include "btree.h++"
#include <stack>
#include <queue>

using namespace std;
class LevelOrder {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) {
            return {};
        }
        vector<vector<int>> levels = {};
        queue<TreeNode*> main;

        main.emplace(root);
        int depth = 0;
        while (!main.empty()) {
            queue<TreeNode*> sub;
            levels.emplace_back();
            while (!main.empty()) {
                TreeNode* node = main.front();
                main.pop();
                levels[depth].emplace_back(node->val);
                if (node->left) {
                    sub.emplace(node->left);
                }
                if (node->right) {
                    sub.emplace(node->right);
                }
            }
            main = sub;
            depth++;
        }

        return levels;

    }
};
#endif //LEETCODE_LEVEL_ORDER_TRAVERSAL_H
