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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p&&!q)
            
        {
            cout<<"1"<<endl;
            return true;
        }
        if(!p||!q)
            
        {
            cout<<"1"<<endl;
            return false;
        }
        
        if(p->val!=q->val)
            
        {
            cout<<"2"<<endl;
            return false;
        }
        
        if(p->left&&!q->left||!p->left&&q->left)
            
        {
            cout<<"3"<<endl;
            return false;
        }
         if(p->right&&!q->right||!p->right&&q->right)
            {
                         cout<<"4"<<endl;

             return false;
         }
        
         if(isSameTree( p->left,  q->left)==false)
             {
                         cout<<"4"<<endl;

             return false;
         }
        return isSameTree( p->right,  q->right);
    }
    
};