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
    
    TreeNode* lcs(TreeNode* root,TreeNode* p,TreeNode* q)
    {
        if(!root or root==p or root==q)
            return root;
        TreeNode* left=lcs(root->left,p,q);
        TreeNode* right=lcs(root->right,p,q);
        if(!right)
            return left;
        else if(!left)
            return right;
        else
            return root;
    }
    
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if(!root->left and !root->right)
            return root;
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* left=NULL,*right=NULL;
        while(!q.empty())
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                TreeNode* curr=q.front();
                q.pop();
                if(i==0)
                {
                    left=curr;
                }
                if(i==size-1)
                {
                    right=curr;
                }
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }
        }
        return lcs(root,left,right);
    }
};