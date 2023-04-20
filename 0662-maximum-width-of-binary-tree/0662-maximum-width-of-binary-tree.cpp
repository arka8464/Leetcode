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
// class Solution {
// public:
//     int widthOfBinaryTree(TreeNode* root) {
//         int ans=INT_MIN;
//         queue<TreeNode*>q;
//          vector<vector<int>>bfs;
        
//         q.push(root);
        
//        while(!q.empty())
//         {
//             int sz=q.size();
//             vector<int>temp;
//            // int cnt=0;
//             for(int i=0;i<sz;i++)
//             {
//                 TreeNode*frnt=q.front();
//                 q.pop();
//                 temp.push_back(frnt->val);
//                 if(frnt->left)q.push(frnt->left);
//                 if(frnt->right)q.push(frnt->right);
//                 // cnt++;
//             }
//            ans=max(ans,sz);
//             bfs.push_back(temp);
//         }
//         for(auto it:bfs)
//         {
//             for(auto it1:it)
//                 cout<<it1<<" ";
//             cout<<endl;
//         }
//         return ans;
//     }
// };
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,int>>q;
    q.push({root,0});   
    int ans=0;
    while(!q.empty())
    {
      int count=q.size();
      int mx=INT_MIN,mn=INT_MAX;    
      for(int i=0;i<count;i++)
      {
        TreeNode *p=q.front().first;
        int x=q.front().second;
        q.pop();
        mx=max(mx,x);
        mn=min(mn,x);
        if(p->left)
        {
          q.push({p->left,(long long)2*x+1});
        }
        if(p->right)
        {
          q.push({p->right,(long long)2*x+2});
        }
      }
      ans=max(ans,abs((mx-mn)+1));          
    }
  return ans; 
    }
};