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
    int cnt(TreeNode* root,int& ans)
    {
        if(root==NULL)
            return 1;
        
        int l=cnt(root->left,ans);
        int r=cnt(root->right,ans);
        
        if(l==0||r==0)
        {
            ans++;
            return 2;
        }
        
         if(l==2||r==2)
        {
            // ans++;
            return 1;
        }
        
        return 0;
    }

public:
    
    int minCameraCover(TreeNode* root) {
        int ans=0;
        if(cnt(root,ans)==0)
            ans++;
        return ans;
        
    }
};