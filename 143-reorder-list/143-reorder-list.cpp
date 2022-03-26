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
    void reorderList(ListNode* head) {
        if(!head||!head->next)return ;
      stack<ListNode*>s;
        ListNode*curr=head;
        int size=0;
        while(curr)
        {
            s.push(curr);
            curr=curr->next;
            size++;
        }
        ListNode*curr_new=head;
        for(int i=0;i<size/2;i++)
        {
            ListNode* top_temp=s.top();
            s.pop();
            top_temp->next=curr_new->next;
            curr_new->next=top_temp;
            curr_new=curr_new->next->next;
        }
        curr_new->next=NULL;
    }
};