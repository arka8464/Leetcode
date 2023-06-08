/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
     void markParent(unordered_map<TreeNode*,TreeNode*> &m,TreeNode* root)
    {
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
          int sz=q.size();
            
            for(int i=0;i<sz;i++)
            {
                TreeNode* frnt=q.front();
                q.pop();
                if(frnt->left)
                {
                    m[frnt->left]=frnt;
                    q.push(frnt->left);
                }
                 if(frnt->right)
                {
                    m[frnt->right]=frnt;
                    q.push(frnt->right);
                }
            }
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> parentTrack;//ekhane node r or parent er address gulo store korchi 
        markParent(parentTrack,root);//function to initialize the parentTrack
        
        unordered_map<TreeNode*,bool> vis;//ebar target node theke bfs korbo jate distacnce bar korte pari
        queue<TreeNode*>q;
        q.push(target);
        vis[target]=1;
        int currLevel=0;
        while(!q.empty())
        {
            int sz=q.size();
            if(currLevel==k)
                break;
            currLevel++;
            for(int i=0;i<sz;i++)
            {
            TreeNode*frnt=q.front();
            q.pop();
                
                if(frnt->left&&!vis[frnt->left])
                {
                    q.push(frnt->left);
                    vis[frnt->left]=1;
                }
                if(frnt->right&&!vis[frnt->right])
                {
                    q.push(frnt->right);
                    vis[frnt->right]=1;
                }
                if(parentTrack[frnt]&&!vis[parentTrack[frnt]])
                {
                     q.push(parentTrack[frnt]);
                    vis[parentTrack[frnt]]=1;
                }
            }
            
        }
        vector<int>ans;
            while(!q.empty())
            {
                ans.push_back(q.front()->val);
                q.pop();
            }  
            return ans;
    }
};