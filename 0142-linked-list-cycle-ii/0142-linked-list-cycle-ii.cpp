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
    ListNode *detectCycle(ListNode *head) {
      
        // unordered_map<ListNode *,bool>m;
        ListNode *slow=head;
        ListNode *fast=head;
        // bool flag=true;
       while(fast != NULL && fast->next != NULL)
       {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)
            {
                slow = head;
                while(slow != fast)
                {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
           }
        
        // if(flag)return NULL;
            
//         ListNode *curr=head;
        
        
//         while(curr)
//         {
//             if(m[curr]==true)return curr;
                
//             m[curr]=true;
            
//             curr=curr->next;
//         }
        return NULL;
    }
};
//this takes O(n) TC but has a O(n) SC hence required to optimise further
// class Solution {
// public:
//     ListNode *detectCycle(ListNode *head) {
      
//         unordered_map<ListNode *,bool>m;
//         ListNode *slow=head;
//                 ListNode *fast=head;
//         bool flag=true;
//         while(fast&&fast->next)
//         {
//             slow=slow->next;
//             fast=fast->next->next;
//             if(slow==fast)
//             {
//                 flag=false;
//                 break;
//             }
//         }
//         if(flag)return NULL;
            
//         ListNode *curr=head;
        
        
//         while(curr)
//         {
//             if(m[curr]==true)return curr;
                
//             m[curr]=true;
            
//             curr=curr->next;
//         }
//         return NULL;
//     }
// };