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
    
    int depth(TreeNode* root)
    {
        if(!root)
            return 0;
        int lh=depth(root->left);
        int rh=depth(root->right);
        return max(lh,rh)+1;
    }
    
    void helper(vector<vector<int>>& ans,TreeNode* root,int level)
    {
        if(!root)
            return;
        ans[level].push_back(root->val);
        helper(ans,root->left,level-1);
        helper(ans,root->right,level-1);
    }
    
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        int d=depth(root);
        vector<vector<int>> ans(d,vector<int>{});
        if(!root)
            return ans;
        helper(ans,root,d-1);
        return ans;
    }
};