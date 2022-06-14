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
    int ans=0;
    int postOrder(TreeNode* root)
    {
        if(!root)
            return 0;
        int leftSum=postOrder(root->left);
        int rightSum=postOrder(root->right);
        ans+=abs(leftSum-rightSum);
        return root->val+leftSum+rightSum;
    }
    
    int findTilt(TreeNode* root) {
        if(!root)
            return 0;
        postOrder(root);
        return ans;
    }
};