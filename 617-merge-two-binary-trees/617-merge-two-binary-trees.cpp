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
    TreeNode* ans; // so that it doesn't contain any garbage value 
    void helper(TreeNode* &ans,TreeNode* root1,TreeNode* root2)
    {
        if(!root1 and !root2)
        {
            return;
        }
        ans= new TreeNode();
        if(root1 and root2)
        {
            ans->val=root1->val+root2->val;
            helper(ans->left,root1->left,root2->left);
            helper(ans->right,root1->right,root2->right);
        }
        else if(root1)
        {
            ans=root1;
        }
        else if(root2)
        {
            ans=root2;
        }
    }
    
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        // if(!root1 and !root2)
        //     return ans;
        helper(ans,root1,root2);
        return ans;
    }
};