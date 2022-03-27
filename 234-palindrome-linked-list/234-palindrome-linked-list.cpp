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
    ListNode* reverseLL(ListNode* head)
    {
        if(!head||!head->next)return head;
        ListNode*prev=NULL;
        ListNode* curr=head;
        while(curr)
        {
            ListNode*temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(!head||!head->next)
            return 1;
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode*prevS=head;
        while(fast&&fast->next)
        {
            prevS=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        if (fast != NULL) slow = slow->next;
        prevS->next=reverseLL(slow);
        ListNode* ptr=head;
        ListNode* ptr_next=prevS->next;
        while(ptr_next)
        {
            if(ptr->val!=ptr_next->val)
                return 0;
            ptr=ptr->next;
            ptr_next=ptr_next->next;
        }
        return 1;
    }
};