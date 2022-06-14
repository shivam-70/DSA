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
    int minDepth(TreeNode* root) {
        if(root==nullptr)
            return 0;
        if(!root->left and !root->right)
        {
            return 1; // for leaf nodes
        }
        if(!root->left)
        {
            return 1+minDepth(root->right); // if left subtree ends gp tpwards right subtree
        }
        if(!root->right)
        {
            return 1+minDepth(root->left); // if right subtree ends go to left subtree
        }
        return 1+min(minDepth(root->left),minDepth(root->right)); // else go to both the subtrees and return the minimum
    }
};