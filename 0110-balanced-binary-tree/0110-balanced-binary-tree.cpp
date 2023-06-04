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
    bool isBalanced(TreeNode* root) {
        if(!root)
            return 1;
       return height(root)!=-1;
    }
    int height(TreeNode* root) {
        if(!root)
            return 0;
        // if(root&&!root->left&&!root->right)
        //     return 1;
        int leftHeight=height(root->left);
        if(leftHeight==-1)
            return -1;
         int rightHeight=height(root->right);
        if(rightHeight==-1)
            return -1;
        if(abs(rightHeight-leftHeight)>1)
            return -1;
        return 1+max(leftHeight,rightHeight);
    }
};