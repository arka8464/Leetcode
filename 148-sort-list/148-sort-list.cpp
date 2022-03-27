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
    ListNode* merge(ListNode* left,ListNode* right)
    {
        ListNode *f_head=new ListNode(0);
        ListNode *ptr=f_head;
        while(left&&right)
        {
            if(left->val<=right->val)
            {
                ptr->next=left;
                left=left->next;
            }
            else
            {
                ptr->next=right;
                right=right->next;
            }
            ptr=ptr->next;
        }
        if(left)
        {
            ptr->next=left;
            left=left->next;
        }
        if(right)
        {
            ptr->next=right;
            right=right->next;
        }
        return f_head->next;
    }
    ListNode* sortList(ListNode* head) {
       if(!head||!head->next)return head;
        ListNode* tail=NULL;
        ListNode* fast=head;
        ListNode* slow=head;
        
        while(fast&&fast->next)
        {
            tail=slow;
            fast=fast->next->next;
            slow=slow->next;
        }
        tail->next=NULL;
        ListNode *left=sortList(head);
        ListNode *right=sortList(slow);
        return merge(left,right);
    }
};