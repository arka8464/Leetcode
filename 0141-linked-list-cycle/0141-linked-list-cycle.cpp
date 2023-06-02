/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        
        if(!head||!head->next)
            return 0;
        
        ListNode *fast=head->next;
        ListNode *slow=head;

        while(slow&&fast&&fast->next)
        {
            if(slow==fast)
                return 1;
            slow=slow->next;
            fast=fast->next->next;
        }
        
        return 0;
    }
};