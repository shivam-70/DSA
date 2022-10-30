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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> ans;
        TreeNode* curr_node=root;
        // st.push(root);
        while(true)
        {
            if(curr_node!=NULL)
            {
                st.push(curr_node);
                curr_node=curr_node->left;
            }
            else
            {
                if(st.empty())
                    break;
                curr_node=st.top();
                st.pop();
                ans.push_back(curr_node->val);
                curr_node=curr_node->right;
            }
        }
        return ans;
    }
};