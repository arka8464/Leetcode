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
    bool solve(TreeNode* L,TreeNode* R)
    {
        if(!L&&!R)
            return true;
        else if(!L||!R)
            return false;
        else if(L->val!=R->val)
            return false;
        return solve(L->left,R->right)&&solve(L->right,R->left);
            
    }
      bool isSymmetric(TreeNode* root) 
    {
        if(root==NULL)
            return true;
        else return solve(root->left,root->right);  
    }
    
    

};