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
    
    void helper(TreeNode* root,int maxi,int &ans)
    {
        if(!root)
            return;
        if(root->val>=maxi)
        {
            ans++;
        }
        helper(root->left,max(maxi,root->val),ans);
        helper(root->right,max(maxi,root->val),ans);
    }
    
    int goodNodes(TreeNode* root) {
        int ans=0;
        int maxi=root->val;
        helper(root,maxi,ans);
        return ans;
    }
};