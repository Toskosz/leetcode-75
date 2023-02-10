/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    void f(TreeNode* root, vector<int>* sofar) {
        if (root == NULL) {
            return;
        } else {
            f(root->left, sofar);
            sofar->push_back(root->val);
            f(root->right, sofar);
        }
    }

    int kthSmallest(TreeNode* root, int k) {
        vector<int> sorted;
        f(root, &sorted);
        return sorted[k-1];
    }
};

