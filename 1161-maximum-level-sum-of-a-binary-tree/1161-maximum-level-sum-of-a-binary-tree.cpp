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
    int maxLevelSum(TreeNode* root) {
        int ans=INT_MIN;
        int level= 0;
        
        
        queue<TreeNode*>q;
        q.push(root);
        int levelCnt=1;
        while(!q.empty())
        {
            int sz=q.size();
             int tempSum=0;
            for(int i=0;i<sz;i++)
            {
                TreeNode*frnt=q.front();
                q.pop();
                tempSum+=frnt->val;
                if(frnt->left)
                    q.push(frnt->left);
                 if(frnt->right)
                    q.push(frnt->right);
            }
            cout<<"levelCnt"<<levelCnt<<"tempSum"<<tempSum<<endl;
            if(tempSum>ans)
            {
                level=levelCnt;
                ans=tempSum;
            }
            levelCnt++;
        }
        return level;
    }
};