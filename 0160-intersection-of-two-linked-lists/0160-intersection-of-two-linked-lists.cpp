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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
       if(!headB||!headA)
           return NULL;
        ListNode *p1=headA;
       ListNode *p2=headB;
		while(p1&&p2&&p1!=p2)
        {
			p1=p1->next;
            p2=p2->next;
            if(p1==p2)return p1;
           if(!p1)p1=headB;
           if(!p2)p2=headA;

		}
		return p1;
    }
};

// TC :O(m*n) SC :O(1) 
// class Solution {
// public:
//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//        ListNode *temp;
// 		while(headA != NULL)
//         {
// 			temp = headB;
// 			while(temp != NULL)
//             {
// 				if(headA == temp)return headA;
//                 temp = temp -> next;
//             }
			
// 			headA = headA -> next;
// 		}
// 		return NULL;
//     }
// };