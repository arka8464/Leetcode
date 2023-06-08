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
    void flatten(TreeNode* root) {
        if(!root)
            return;
        TreeNode* finalHead=new TreeNode(root->val);
        stack<TreeNode*>st;
        st.push(root);
        TreeNode* finalTail=finalHead;
        while(!st.empty())
        {
           TreeNode* tp=st.top();
            finalTail->right=tp;
            finalTail->left=NULL;
            finalTail=finalTail->right;
            
                st.pop();
             if(tp->right)
            {
                st.push(tp->right);
            }
            if(tp->left)
            {
                st.push(tp->left);
            }
            
        }
        
        root = finalHead;
        
    }
};