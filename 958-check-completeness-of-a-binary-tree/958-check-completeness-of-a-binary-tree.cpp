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
    
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        bool noMore=false;
        while(!q.empty())
        {
            int size=q.size();
            while(size--)
            {
                TreeNode* curr=q.front();
                q.pop();
                if(curr->left){
                    if(noMore)
                        return false;
                    q.push(curr->left);
                }
                else
                    noMore=true;
                    
                if(curr->right){
                    if(noMore)
                        return false;
                    q.push(curr->right);
                }
                else
                    noMore=true;
            }
        }
        return true;
    }
};