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
    //Using recursion 
//     void postorderTraversal(TreeNode* root,vector<int>&v)
//     {
//         if(root==NULL)return;
//         postorderTraversal(root->left,v);
        
//         postorderTraversal(root->right,v);
//         v.push_back(root->val);
//     }
    
//     //***Using  2 stack
//     vector<int> postorderTraversal(TreeNode* root)
//     {
//       vector<int> v;
//         if(root==NULL)return v;
        
//         stack <TreeNode*> s1,  s2;
//         s1.push(root);
//         while(!s1.empty())
//         {
//             TreeNode* temp=s1.top();
//             s1.pop();
//             s2.push(temp);
//             if(temp->left!=NULL) 
//                 s1.push(temp->left);
//              if(temp->right!=NULL) 
//                 s1.push(temp->right);
//         }
//         while(!s2.empty())
//         {
//            TreeNode* temp2=s2.top();
//            s2.pop();
//             v.push_back(temp2->val);
//         }
        
//         return v;
//     }
    
    
    //***Using  1 stack
    vector<int> postorderTraversal(TreeNode* root)
    {
     stack<TreeNode*> s;
        vector<int> ans;
        if(root==NULL)
            return ans;
        TreeNode* curr=root;
        TreeNode* pre=NULL;
        while(!s.empty() || curr){
            if(curr){
                s.push(curr);
                curr=curr->left;
            }
            else{
                curr=s.top();
                if(curr->right==NULL || curr->right==pre){
                    ans.push_back(curr->val);
                    s.pop();
                    pre=curr;
                    curr=NULL;
                }
                else
                    curr=curr->right;
            }
        }
        return ans;
    }
};