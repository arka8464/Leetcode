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
    bool f(TreeNode* root,long long min,long long max)
    {
        if(!root)
            return true;
        
       if(root->val >= max||root->val<=min)
            return false;
        
        return f(root->left,min,root->val)&& f(root->right,root->val,max);
    }
public:
    bool isValidBST(TreeNode* root) {
        
        
        return f(root,LLONG_MIN,LLONG_MAX);
    }
};