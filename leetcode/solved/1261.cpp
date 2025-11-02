#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class FindElements {
    TreeNode *root;

public:

    FindElements(TreeNode *root) : root(root) { root->val = 0; }

    bool find(int target) {
        if (target == 0) { return true; }
        vector<int> direction;
        while (target) {
            target--;
            direction.push_back(target & 1);
            target >>= 1;
        }

        TreeNode *cur = root;
        for (int i = direction.size() - 1; i >= 0; i--) {
            if (direction[i]) {
                if (!cur->right) { return false; }
                cur = cur->right;
            } else {
                if (!cur->left) { return false; }
                cur = cur->left;
            }
        }
        return true;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */

