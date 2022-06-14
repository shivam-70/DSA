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
    void helper(TreeNode* node)
    {
        if(!node)
            return;
        helper(node->left);
        helper(node->right);
        swap(node->left,node->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        if(!root)
            return root;
        helper(root);
        return root;
    }
};