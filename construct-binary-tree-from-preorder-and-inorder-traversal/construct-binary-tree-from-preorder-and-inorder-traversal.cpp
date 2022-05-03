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
    TreeNode* buildTreehelper(vector<int>& preorder, vector<int>& inorder,map<int,int>&m,int ps,int pe,int is,int ie)
    {
        if(is>ie||ps>pe)
            return NULL;
        
        int rootofInorder=m[preorder[ps]];
       
        int numLeft=rootofInorder-is;
        
        int lps=ps+1;
        int lpe=ps+numLeft;
        int rps=lpe+1;
        int rpe=pe;
        int lis=is;
        int lie=rootofInorder-1;
        int ris=rootofInorder+1;
        int rie=ie;
         TreeNode* root= new TreeNode(preorder[ps]); 
        root->left=buildTreehelper(preorder, inorder,m,lps,lpe,lis,lie);
        root->right=buildTreehelper(preorder, inorder,m,rps,rpe,ris,rie); 
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size()!=inorder.size())
            return NULL;
        map<int,int>m;
        for(int i=0;i<inorder.size();i++)
            m[inorder[i]]=i;
        return buildTreehelper(preorder, inorder,m,0,preorder.size()-1,0,inorder.size()-1);
    }
    
};