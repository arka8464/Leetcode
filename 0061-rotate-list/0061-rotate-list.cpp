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
    ListNode* rotateRight(ListNode* head, int k) {
        int cnt=0,len=0;
        if(!head)return NULL;
        ListNode*curr= head;
        while(curr)
        {
            curr=curr->next;//couning length
            len++;
        }
        if(len<=1)return head;
        curr= head;
        if(k>=len)k=k%len;
        while(cnt<len-k-1&&curr)
        {
            curr=curr->next;//traversing till the node which will be the last node after the traversal
            cnt++;
        }
        
        if(!curr->next)return head;//if the node reaches the lst node that means that k=0 so we return the head
        ListNode*new_head=curr->next ;
        curr->next=NULL;//setting the last node next of the list as NULL
         ListNode*ptr=new_head;
        while(ptr&&ptr->next)//reaching the last node of the previous list to attach the previous head
        ptr=ptr->next;
        
        ptr->next=head;
        return new_head;
        // return NULL;
        
    }
};