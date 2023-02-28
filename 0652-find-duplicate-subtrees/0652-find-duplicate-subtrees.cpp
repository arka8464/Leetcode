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
            unordered_map<string,int>m;

    string f(vector<TreeNode*>&ans,TreeNode* root)
    {
        if(!root)return "";
        string left=f(ans,root->left);
        string right=f(ans,root->right);
        
        string s="("+left+to_string(root->val)+right+")";
       
        if(m[s]==1)
            ans.push_back(root);
        m[s]++;
        
        return s;
    }
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*>ans;
        f(ans,root);
        return ans;
    }
};