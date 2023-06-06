/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //brute force : path bar korbo tree to the nodes diye mathc korate thakbo jeta match korebe na abar p->val o na ar q->val o na oita ke return korbo
        //tail recursion lagachi mane nicher dik theke check kore uporer dike utchi jodi amraq root->val ==  p || root->val ==  q peye jai tobe return korbo root erom kore jetai first node hobe jar duto i side theke not null asbe ota ke return kore debo 
        
        if(!root||root==p||root==q)
            return root;
       TreeNode* left=lowestCommonAncestor( root->left, p,  q);
       TreeNode* right=lowestCommonAncestor( root->right, p,  q);

        if(!left)
            return right;
        else if(!right)
            return left;
        else 
            return root;//kono tai null noi tai etai LCA
            
    }
};