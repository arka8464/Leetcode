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
    ListNode* middleNode(ListNode* head) {
       ListNode *fast_pointer=head;
       ListNode *slow_pointer=head;
      while(fast_pointer!=NULL&&fast_pointer->next!=NULL)
      {
          fast_pointer=fast_pointer->next->next;
          slow_pointer=slow_pointer->next;
      }
        return slow_pointer;
    }
};

/*
 //Naive approach
        int count=0;
        ListNode *temp=head;
        while(temp!=NULL)
        {
            temp=temp->next;
            count++;
        }
        temp=head;
        int curr_count=0;
        while(curr_count<count/2)
        {
            temp=temp->next;
            curr_count++;
        }
        ListNode *ans=temp;
        return ans;
*/