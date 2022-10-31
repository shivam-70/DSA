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
    
    void helper(vector<string>& ans,string s,TreeNode* root)
    {
        if(!root) return;
        if(!root->left and !root->right) {
            // s.pop_back();
            ans.push_back(s);
            return;
        }
        // s+=;
        if(root->left) helper(ans,s+"->"+to_string(root->left->val),root->left);
        if(root->right) helper(ans,s+"->"+to_string(root->right->val),root->right);
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        // string s/;
        vector<string> ans;
        if(!root) return ans;
        helper(ans,to_string(root->val),root);
        return ans;
    }
};