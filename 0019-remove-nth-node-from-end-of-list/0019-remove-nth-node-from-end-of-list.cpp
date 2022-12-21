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
        
        int cnt=0;
        ListNode* curr=head;
        while(curr)
        {
            curr=curr->next;
            cnt++;
        }
        if(n<=0)return NULL;

        n=cnt-n;
        cnt=0;
        if(n==0)
        {
            head=head->next;
            return head;
        }
        curr=head;
        while(cnt<n-1&&curr)
        {

            curr=curr->next;
            cnt++;
        }
                    ListNode* temp=NULL;

         if(curr->next)
             temp=curr->next->next;
         else
             temp=NULL;
        curr->next=temp;
        return head;
    }
};