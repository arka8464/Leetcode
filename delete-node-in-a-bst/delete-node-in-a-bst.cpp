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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)
            return NULL;
        
      else if (key<root->val)
         root->left = deleteNode(root->left,key);
        
      else if (key>root->val)
         root->right = deleteNode(root->right,key);
        
      else //we found the key node
       {
           //No child
          if(!root->left&&!root->right)
          {
              delete root;
              return NULL;
          }
          //if only right child is present 
          else if(!root->left||!root->right)
          {
          if(root->right)
          {
              TreeNode* temp=root->right;
              delete root;
              return temp;
          }
          //if only left child is present 
          else
          {
              TreeNode* temp=root->left;
              delete root;
              return temp;
          }
          }
          //2 childs are present 
         else if(root->right&&root->left)
         {
            TreeNode *tmp = root->right;
             
                while (tmp->left!=NULL) 
                {
                    tmp = tmp->left;
                }
             root->val=tmp->val;
             root->right=deleteNode(root->right,root->val);
         }
       }
           
        return root;
    }
};