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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> address;
        for(int i=0;i<inorder.size();i++)
            address[inorder[i]]=i;   //inorder element gulo r sathe index map korlm
        TreeNode* ansHead=buildTree(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,address);
        return ansHead;        
    }
    TreeNode* buildTree(vector<int>& preorder,int preStart,int preEnd,vector<int>& inorder,int inStart,int inEnd,unordered_map<int,int>&address)
    {
        if(preStart>preEnd||inStart>inEnd)
            return NULL;
        TreeNode* root=new TreeNode(preorder[preStart]);
        int inorderrootAddress=address[preorder[preStart]];
        
        int leftNums=inorderrootAddress-inStart;
        root->left=buildTree(preorder,preStart+1,preStart+leftNums,inorder,inStart,inorderrootAddress-1,address);
        root->right=buildTree(preorder,preStart+leftNums+1,preEnd,inorder,inorderrootAddress+1,inEnd,address);

        return root;
    }
    
};