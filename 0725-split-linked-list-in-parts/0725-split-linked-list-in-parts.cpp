/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
         vector<ListNode*>ans(k,NULL);
        int length=0;
        while(!head)
        {
            return ans;
        }
        ListNode* tmp=head;
        
        while(tmp)
        {
            tmp=tmp->next;
            length++;
        }
        // cout<<length<<endl;
        int sz=length/k;
        int rem=length%k;
        // int frst=sz+rem;
        
        tmp=head;
       ListNode* prev=nullptr;
        
        // ans.push_back(root);
//         while(frst)
//         {
             
//             prev=tmp;
//             tmp=tmp->next;
            
//             frst--;
//         }
        
        for(int i=0;tmp!=NULL;i++,rem--)
        {
            
            ans[i]=tmp;
            for(int j=0;j<sz+(rem>0);j++)
            {
               cout<<i<<" "<<j<<" "<<tmp->val<<endl;
               prev=tmp;
               tmp=tmp->next;
            }
            prev->next=NULL;
            cout<<endl;
        }
        
        return ans;
    }
};