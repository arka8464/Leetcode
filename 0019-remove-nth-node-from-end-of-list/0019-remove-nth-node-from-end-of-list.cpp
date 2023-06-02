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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
          if(!head)
            return head;
        if(!head->next)
        {
            if(n==0)
                return head;
            return NULL;
        }
        
        
        ListNode* dummy =new ListNode (-1e9,head);
        ListNode* slow=dummy;
        ListNode* fast=dummy;

        for(int i=1;i<=n;i++)
        {
            fast=fast->next;
            cout<<"fast->val"<<fast->val<<endl;
        }
         
        // if(!fast)
        // {
        //     delete(fa)
        // }
        while(fast&&fast->next)
        {
            
            slow=slow->next;
            fast=fast->next;
        }
                    cout<<"slow->val"<<slow->val<<endl;

        // if(slow==dummy)
        //     return NULL;
        if(slow&&slow->next)
           {
            
            ListNode*temp=slow->next->next;
            delete(slow->next);
            slow->next=temp;
          }
      return dummy->next;  
        
    }
};