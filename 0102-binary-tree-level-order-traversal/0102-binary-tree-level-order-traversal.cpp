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
    vector<vector<int>> levelOrder(TreeNode* root) {
         vector<vector<int>> ans;
        if(root==NULL)
            return ans;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty())
        {
            int sz=q.size();
            vector<int>temp;
            for(int i=0;i<sz;i++)
            {
                TreeNode*frnt=q.front();
                q.pop();
               temp.push_back(frnt->val);
                if(frnt->left)q.push(frnt->left);
                if(frnt->right)q.push(frnt->right);

            }
            ans.push_back(temp);
        }
        return ans;
    }
};

/*
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        vector<vector<int>> ans;
        if(root==NULL)
            return ans;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        vector<int> curr;
        while(!q.empty())
        {
            TreeNode* temp=q.front();
            q.pop();
            if(temp==NULL)
            {
                ans.push_back(curr);
                curr.clear();
                if(q.empty())
                    return ans;
                q.push(NULL);
            }
            else
            {
                curr.push_back(temp->val);
                 if(temp->left!=NULL)
                    q.push(temp->left);
                if(temp->right!=NULL)
                    q.push(temp->right);
            }
            
        }
        return ans;
        
    }
};
*/