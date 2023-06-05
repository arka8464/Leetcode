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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root)
            return ans;
       
        queue<TreeNode*>q;
        
        q.push(root);
        bool frontCheck=true;
        while(!q.empty())
        {
            int sz=q.size();
            cout<<"q.size()"<<q.size()<<endl;
            vector<int>tmp(sz);
            for(int i=0;i<sz;i++)
             {
                cout<<"i"<<i<<" ";

                TreeNode*frnt=q.front();
                q.pop();
                                cout<<"frnt->val"<<frnt->val<<endl;

                if(frontCheck)
                    tmp[i]=frnt->val;
                else
                    tmp[sz-1-i]=frnt->val;
            if(frnt->left)
                q.push(frnt->left);
            if(frnt->right)
                q.push(frnt->right);                
             }
                        
        frontCheck=!frontCheck;

            ans.push_back(tmp);
        }
        return ans;
    }
};