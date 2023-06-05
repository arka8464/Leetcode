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
    int height(TreeNode* root)
    {
        if(!root)
            return 0;
        if(root&&!root->left&&!root->right)
            return 1;
        
        return 1+max(height(root->left),height(root->right));
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root)
            return 0;
        int ans=INT_MIN;
           
        int leftHeight=height(root->left);
        int rightHeight=height(root->right);

        ans=max(ans,leftHeight+rightHeight);//ekhane largest diameter thorugh root pelm
        
        ans=max(ans,diameterOfBinaryTree(root->left));
        ans=max(ans,diameterOfBinaryTree(root->right));
        
        return ans;

        
        
        
    }
};