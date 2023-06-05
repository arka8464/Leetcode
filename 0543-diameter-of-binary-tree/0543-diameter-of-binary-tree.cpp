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
    int height(TreeNode* root,int& ans)
    {
        if(!root)
            return 0;
       int leftHeight=height(root->left,ans);
        int rightHeight=height(root->right,ans);
        ans=max(ans,rightHeight+leftHeight);
        return 1+max(leftHeight,rightHeight);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root)
            return 0;
        int ans=0;
        height(root,ans);
             
        return ans;        
    }
};