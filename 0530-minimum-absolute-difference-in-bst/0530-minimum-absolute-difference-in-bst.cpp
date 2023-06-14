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
    void f(TreeNode* root,set<int>&m)
    {
        if(!root)
            return ;
        f(root->left,m);
        m.insert(root->val);
        f(root->right,m);

    }
public:
    int getMinimumDifference(TreeNode* root) {
        set<int>s;
        f(root,s);
        int ans=INT_MAX;
        
        auto it=s.begin();
        
        advance(it,1);
        for(;it!=s.end();it++)
        {
            ans=min(ans,*it-*prev(it));
        }
       return ans; 
    }
};