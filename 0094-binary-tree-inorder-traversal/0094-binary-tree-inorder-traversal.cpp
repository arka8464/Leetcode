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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(!root)
            return ans;
        stack<TreeNode*>st;
        TreeNode*tmp=root;
        while(!st.empty()||tmp!=NULL)
        {
           while(tmp!=NULL)
           {
               st.push(tmp);
               tmp=tmp->left;
           }
            tmp=st.top();
            st.pop();
            ans.push_back(tmp->val);
            // if(tmp->right)
                tmp=tmp->right;
        }
        return ans;
    }
};