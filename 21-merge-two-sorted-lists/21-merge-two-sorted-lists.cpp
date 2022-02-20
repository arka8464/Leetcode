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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        ListNode dummy(INT_MIN);
        ListNode *dummy_duplicate = &dummy;
        
        while (l1 && l2) 
        {
            if (l1->val < l2->val)
            {
                dummy_duplicate->next = l1;
                l1 = l1->next;
            } 
            else 
            {
                dummy_duplicate->next = l2;
                l2 = l2->next;
            }
            dummy_duplicate = dummy_duplicate->next;
        }
        
        dummy_duplicate->next = l1 ? l1 : l2;
        return dummy.next;
    }
};