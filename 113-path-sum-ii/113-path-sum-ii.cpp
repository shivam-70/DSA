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
    
    void helper(TreeNode* root,int targetSum,vector<vector<int>>& ans,vector<int>& path)
    {
        if(!root)
            return;
        path.push_back(root->val);
        if(!root->right and !root->left)
        {
            if(targetSum==root->val)
                ans.push_back(path);
            // return;
        }
        else
        {
            helper(root->right,targetSum-root->val,ans,path);
            helper(root->left,targetSum-root->val,ans,path);
        }
        path.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> path;
        helper(root,targetSum,ans,path);
        return ans;
    }
};