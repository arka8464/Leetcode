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
    ListNode* reverseLL(ListNode* head)
    {
        ListNode* curr=head,*prev=NULL;
        
        while(curr)
        {
            ListNode* temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        return prev;
    }
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        if(!head)
            return NULL;
        
        ListNode* start=NULL, *last=NULL;
        
        ListNode*prev=NULL;
        ListNode*curr=head,*lefthead=NULL;
        
        int leftctr=1,rightctr=1;
        while(curr)
        {
            if(leftctr==left)
            {
                lefthead=curr;
                break;
            }
            prev=curr;
            curr=curr->next;
            leftctr++;
        }
        // prev->next=NULL;
        curr=head;
        while(curr)
        {
            if(rightctr==right)
            {
                last=curr->next;
                curr->next=NULL;
                break;
            }
            curr=curr->next;
            rightctr++;
        }
        if(prev!=NULL)
        {
            prev->next=reverseLL(lefthead);
        }
        else
        {
            head=reverseLL(lefthead);
        }
        
        curr=head;
        while(curr&&curr->next)
        {
            curr=curr->next;
        }
        curr->next=last;
        return head;
    }
};