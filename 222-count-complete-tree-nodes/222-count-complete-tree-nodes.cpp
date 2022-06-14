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
    
    /*
        The idea is that a perfect binary tree is a tree with all the nodes fully filled. We use the 
        property of a complete binary tree and a perfect binary tree. We will traverse 
        int both the directions and check if the left_subtree_size == right_subtree_size and where
        the above condition is not satisfied we look further in the right and left subtrees.
        Let's us suppose if we found that it is a perfect binary tree i.e 
        left_subtree_size == right_subtree_size then we return the number of nodes in that
        subtree i.e.pow(2,right_subtree_size)-1, and no need to further call left or right subtree.
        
        
    */
    int countNodes(TreeNode* root) {
        if(!root)
            return 0;
        int left_subtree_size=1;
        TreeNode *currLeft=root->left; // so that the root's value remains unchanged
        while(currLeft)        {
            currLeft=currLeft->left;
            left_subtree_size++;
        }
        
        int right_subtree_size=1;
        TreeNode *currRight=root->right; // so that the root's value remains unchanged
        while(currRight)
        {
            currRight=currRight->right;
            right_subtree_size++;
        }
        if(right_subtree_size==left_subtree_size)
            return pow(2,right_subtree_size)-1;
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};