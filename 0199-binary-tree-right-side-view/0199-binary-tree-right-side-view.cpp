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
    vector<int> rightSideView(TreeNode* root) {
               vector<int>ans;

        if(!root)
            return ans;
        queue<pair<TreeNode*,int>>q;//{node,y-axis}
        
        map<int,int>mp;
        
        q.push({root,0});
        
        while(!q.empty())
        {
            TreeNode* frntNode=q.front().first;
            int frntYaxis=q.front().second;
            q.pop();
            mp[frntYaxis]=frntNode->val;
            
            if(frntNode->left)
                q.push({frntNode->left,frntYaxis+1});
            if(frntNode->right)
                q.push({frntNode->right,frntYaxis+1});
                
        }
        
        for(auto it:mp)
            ans.push_back(it.second);
        
        return ans;
    }
};