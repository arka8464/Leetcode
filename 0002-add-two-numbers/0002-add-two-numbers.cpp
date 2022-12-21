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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;
        ListNode* dummy = new ListNode(INT_MIN);
        ListNode* curr=dummy;
        
        while(l1&&l2)
        {
          int val=l1->val+l2->val+carry;
          if(val>=10)
              carry=1;
            else 
                carry=0;
           val=val%10;
          ListNode * sum=new ListNode(val);
          cout<<sum->val<<endl;
            curr->next=sum;
          curr=sum;
            l1=l1->next;
            l2=l2->next;
        }
        cout<<"hello"<<endl;
        cout<<carry<<endl;
        while(l1)
        {
           int val=l1->val+carry;
          if(val>=10)
              carry=1;
            else 
                carry=0;
           val=val%10;
            ListNode * sum=new ListNode(val);
          cout<<sum->val<<endl;
            curr->next=sum;
          curr=sum;
            l1=l1->next;
        }
        
         while(l2)
        {
           int val=l2->val+carry;
          if(val>=10)
              carry=1;
            else 
                carry=0;
           val=val%10;
            ListNode * sum=new ListNode(val);
          cout<<sum->val<<endl;
            curr->next=sum;
          curr=sum;
            l2=l2->next;
        }
       if(carry>0)
          {  ListNode * sum=new ListNode(1);
          cout<<sum->val<<endl;
            curr->next=sum;
          curr=sum;}
        return dummy->next;
    }
};