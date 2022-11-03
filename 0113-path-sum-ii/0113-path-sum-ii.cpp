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
    
    void helper(TreeNode* root, int targetSum,vector<int>& tmpAns,vector<vector<int>>& ans)
    {
        if(!root) return;
        if(!root->left and !root->right and root->val==targetSum) {
            tmpAns.push_back(root->val);
            ans.push_back(tmpAns);
            tmpAns.pop_back();
            return;
        }    
        if(root->left)
        {
            tmpAns.push_back(root->val);
            helper(root->left,targetSum-root->val,tmpAns,ans);
            tmpAns.pop_back();
        }
        if(root->right)
        {
            tmpAns.push_back(root->val);
            helper(root->right,targetSum-root->val,tmpAns,ans);
            tmpAns.pop_back();
        }
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        if(!root) return ans;
        vector<int> tmpAns;
        helper(root,targetSum,tmpAns,ans);
        return ans;
    }
};