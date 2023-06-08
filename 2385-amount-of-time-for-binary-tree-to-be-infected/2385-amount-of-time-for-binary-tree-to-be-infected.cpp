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
    
//     TreeNode* find(TreeNode* root, int start)//to find address of the initial node  
//     {
//         if(!root)
//             return root;
        
//          if(root->val==start)
//             return root;
//         if(find(root->left,start)!=NULL)
//             return find(root->left,start);
        
//        if(find(root->right,start)!=NULL)
//             return find(root->right,start);
      
//         return NULL;
//     }
    
    // map the parent addresses 
    TreeNode* f(unordered_map<TreeNode*,TreeNode*> &m,TreeNode* root,int target)
    {
        queue<TreeNode*>q;
        q.push(root);
        TreeNode* ans=NULL;
        while(!q.empty())
        {
          int sz=q.size();
            
            for(int i=0;i<sz;i++)
            {
                TreeNode* frnt=q.front();
                q.pop();
                if(frnt->val==target)
                    ans=frnt;
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
        return ans;
    }
    int findMaxDist(TreeNode*startNode,unordered_map<TreeNode*,TreeNode*>&trackParent)//bfs
    {
        if(!startNode)
            return -1e9;
        
        int level=0;
        
        queue<TreeNode*>q;
        unordered_map<TreeNode*,bool> vis;
        
        q.push(startNode);
        vis[startNode]=1;
        while(!q.empty())
        {
            int sz=q.size();
            level++;
            for(int i=0;i<sz;i++)
            {
                TreeNode* frnt=q.front();
                q.pop();
                if(frnt->left&&!vis[frnt->left])
                {
                    vis[frnt->left]=1;
                    q.push(frnt->left);
                }
                if(frnt->right&&!vis[frnt->right])
                {
                    vis[frnt->right]=1;
                    q.push(frnt->right);
                }
                if(trackParent[frnt]&&!vis[trackParent[frnt]])
                {
                    vis[trackParent[frnt]]=1;
                    q.push(trackParent[frnt]);
                }
            }
        }
        return level-1;
    }
    


int f(TreeNode* root ,   unordered_map<TreeNode*,TreeNode*>&par ,  unordered_map<TreeNode*, bool>&vis)//dfs
{
    if(!root)
    return 0;
    
    vis[root]=1;
    
    int lh= INT_MIN;
     int rh= INT_MIN;
      int ph= INT_MIN;
    
    if(!vis[root->left])
     lh= f(root->left, par, vis);
      if(!vis[root->right])
        rh= f(root->right, par, vis);
          if(!vis[par[root]])
        ph= f(par[root] , par, vis);
    
    return  max(ph, max(lh,rh)) +1;
}
public:
    int amountOfTime(TreeNode* root, int start) {
        
        // TreeNode *startNode=find(root, start);
        
        unordered_map<TreeNode*,TreeNode*> trackParent;
       TreeNode *startNode= f(trackParent,root,start);//parent address map created 
        
        // return findMaxDist(startNode,trackParent);//bfs
        
        unordered_map<TreeNode*,bool> vis;
        return f(startNode,trackParent,vis)-1;
        
    }
};