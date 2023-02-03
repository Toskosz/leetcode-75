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

    bool validSubBST(TreeNode* node, long left, long right){
        if (node == NULL){
            return true;
        } else if (!(node->val<right && node->val>left)){
            return false;
        }
        return validSubBST(node->left, left, node->val) && validSubBST(node->right, node->val, right);
    }

    bool isValidBST(TreeNode* root) {
        return validSubBST(root, LONG_MIN, LONG_MAX); 
    }
};


