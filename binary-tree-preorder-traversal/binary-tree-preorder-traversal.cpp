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
    //recursive code
//      void preorderTraversal(TreeNode* root,vector<int>&v)
//     {
//         if(root==NULL)return;
         
//          v.push_back(root->val);
//         preorderTraversal(root->left,v);
//         preorderTraversal(root->right,v);
//     }
    vector<int> preorderTraversal(TreeNode* root) {
         vector<int>v;
          if(root==NULL)
              return v;
         stack<TreeNode*> s;
        s.push(root);
        while(!s.empty())
        {
            TreeNode* temp=s.top();
            s.pop();
            v.push_back(temp->val);
            if(temp->right)
                s.push(temp->right);
            if(temp->left)
                s.push(temp->left);
        }
        return v;
    }
};