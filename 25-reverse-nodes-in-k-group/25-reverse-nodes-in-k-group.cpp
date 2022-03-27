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
     ListNode *reverseBefore(ListNode *head, ListNode *node) {
        ListNode *pre = node, *cur = head;
        while (cur != node) {
            ListNode *next = cur->next;
            cur->next = pre;
            pre = cur; cur = next;
        }
        return pre;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
       
        auto node=head;
        for (int i=0; i < k; ++i)
        {
            if ( ! node  )
                return head; // nothing to do list too sort
            node = node->next;
        }

        auto new_head = reverseBefore( head,node);
        head->next = reverseKGroup( node, k);
        return new_head;
        
    }
};