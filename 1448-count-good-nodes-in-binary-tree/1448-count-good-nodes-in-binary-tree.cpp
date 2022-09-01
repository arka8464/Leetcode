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
int count=0;
void goodNode(TreeNode*root,int maxi=INT_MIN)
{
    if(!root)return;
    if(root->val>=maxi)
       { maxi=root->val;
        count+=1;}
    goodNode(root->left,maxi);
    goodNode(root->right,maxi);

}
public:
    int goodNodes(TreeNode* root) {
        if(root==NULL)
           return 0; 
        goodNode(root);
        return count;
        
    }
};