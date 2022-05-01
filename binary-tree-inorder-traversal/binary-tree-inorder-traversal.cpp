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
 curr*/
class Solution {
public:
    
    vector<int> inorderTraversal(TreeNode* root) {
       vector<int>v;
         if(root==NULL)
             return v;
        stack<TreeNode*> s;
        TreeNode* temp=root;
         while(!s.empty()||temp!=NULL)
         {
             
             while(temp!=NULL)
             {
                 s.push(temp);
                 temp=temp->left;      
             }
             temp=s.top();
            s.pop();
            v.push_back(temp->val);
            temp=temp->right;
         }
         return v;
    }
};