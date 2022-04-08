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
    int height(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        else return 1+ max(height(root->left),height(root->right));
    }
    int diameterOfBinaryTree(TreeNode* root) 
    {
         if(root==NULL)
            return 0;
   int left_diameter=diameterOfBinaryTree(root->left);
   int right_diameter=diameterOfBinaryTree(root->right); 
    int max_d = max(left_diameter,right_diameter);
     int ht=height(root->left)+height(root->right);
        return max(ht,max_d);
    }
};