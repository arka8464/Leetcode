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
    void solve(TreeNode* root,vector<int>&ans)
    {
        stack<TreeNode*> s;
        TreeNode* curr=root;
        while(!s.empty()||curr)
        {
            while(curr)
            {
                s.push(curr);
                curr=curr->left;
            }
            curr=s.top();
            s.pop();
            ans.push_back(curr->val);
     
            curr=curr->right;
        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
       vector<int>v;
          solve(root,v);
        return v;
    }
};