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
    int countNodes(TreeNode* root) {
        if(!root)
            return 0;
        
        int leftHeight=lftheight(root);
        int rightHeight=rghtheight(root);

       if(leftHeight==rightHeight)
           return (1<<rightHeight)-1; //formula (2^levelHeight) -1
        //jodi match na kor height tobe niche kiye dekhbo je koto ta match korche ar nijer jonyo +1 kore debo
        return 1+countNodes(root->left)+countNodes(root->right);
    }
    
    
    int lftheight(TreeNode* root)
    {
        int height=0;
        while(root)
        {
            height++;
            root=root->left;
        }
        return height;
    }
    int rghtheight(TreeNode* root)
    {
        int height=0;
        while(root)
        {
            height++;
            root=root->right;
        }
        return height;
    }
};