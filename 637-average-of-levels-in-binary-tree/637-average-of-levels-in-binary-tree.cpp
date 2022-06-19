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
    vector<double> averageOfLevels(TreeNode* root) {
        double ans=0;
        queue<TreeNode*> q;
        q.push(root);
        vector<double> res;
        while(!q.empty())
        {
            int size=q.size();
            ans=0;
            for(int i=0;i<size;i++)
            {
                TreeNode *curr=q.front();
                q.pop();
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
                ans+=curr->val;
            }
            res.push_back(ans/size);
        }
        return res;
    }
};