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
              if(!p&&!q)return true; 
        if(!p||!q)return false;
        
//         if(p&&q)
//         {
//             if(p->val!=q->val)return false;//checking val 
//              if(p->left&&!q->left||p->right&&!q->right)//either child missing
//                 return false;
//             if(p->left&&p->right&&q->left&&q->right)//all child present
//                 if(p->left->val==q->left->val&&p->right->val==q->right->val)
//                     return true;
//                 else
//                     return false;
           
//         }
        if(p->val!=q->val)return false;
        
        return isSameTree( p->left,  q->left)&&isSameTree( p->right,  q->right);
    }
};