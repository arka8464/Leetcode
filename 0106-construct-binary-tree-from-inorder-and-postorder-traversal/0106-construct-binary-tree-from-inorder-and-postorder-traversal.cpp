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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> address;
        for(int i=0;i<inorder.size();i++)
            address[inorder[i]]=i;   //inorder element gulo r sathe index map korlm
        TreeNode* ansHead=buildTree(postorder,0,postorder.size()-1,inorder,0,inorder.size()-1,address);
        return ansHead;
    }
    TreeNode* buildTree(vector<int>& postorder,int postStart,int postEnd,vector<int>& inorder,int inStart,int inEnd,unordered_map<int,int>&address)
    {
        if(postStart>postEnd||inStart>inEnd)
            return NULL;
        TreeNode* root=new TreeNode(postorder[postEnd]);
        int inorderrootAddress=address[postorder[postEnd]];
        cout<<"inorderrootAddress"<<inorderrootAddress<<endl;
        int leftNums=inorderrootAddress-inStart;
        root->left=buildTree(postorder,postStart,postStart+leftNums-1,inorder,inStart,inorderrootAddress-1,address);
        root->right=buildTree(postorder,postStart+leftNums,postEnd-1,inorder,inorderrootAddress+1,inEnd,address);

        return root;
    }
    
};