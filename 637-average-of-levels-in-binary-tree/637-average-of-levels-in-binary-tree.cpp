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
    vector<double> averageOfLevels(TreeNode* root) {
       queue<TreeNode*>q;
       vector<double>ans;
       if(!root)return ans;
        q.push(root);
         q.push(NULL);

                         long long element=0,sum=0;

         while(!q.empty())
              {
                 TreeNode* front=q.front();
                  q.pop();
                  if(front==NULL)
                  {
                      double temp=sum*(1.00)/element;
                      ans.push_back(temp);
                      element=0;
                      sum=0;
                      if(q.empty())
                          return ans;
                      q.push(NULL);
                  }
                  else
                  {
                      sum+=front->val;
                      element++;
                      cout<<sum<<" "<<element<<endl;
                      if(front->right!=NULL)q.push(front->right);
                     if(front->left!=NULL)q.push(front->left);

                  }
              }
        return ans;
    }
};