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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
       ListNode*p1= list1;
       ListNode*p2= list2;
    ListNode*pf = new ListNode(-1e9) ;
      ListNode*pf_head=pf;   
        while(p1&&p2)
        {
            if(p1->val<=p2->val)
            {
               ListNode*temp= p1->next;
               p1->next=NULL;
                pf->next=p1;
                pf=pf->next;
                p1=temp;
            }
            else
            {
               ListNode*temp= p2->next;
               p2->next=NULL;
                pf->next=p2;
                pf=pf->next;
                p2=temp; 
            }
        }
        
        if(p1)
            pf->next=p1;
        if(p2)
            pf->next=p2;

        return pf_head->next;
    }
};