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
        //adding if both lists are present
        ListNode* temp1=l1;
        ListNode* temp2=l2;
        ListNode* dummy=new ListNode(-1e9,NULL);
        ListNode* final= dummy;
        int carry=0;
        
        while(temp1&&temp2)
        {
            int sum=temp1->val+temp2->val+carry;
            cout<<"temp1->Val"<<temp1->val<<"temp2->Val"<<temp2->val<<endl;
            int val=sum%10;
            carry=0;
            ListNode* temp=new ListNode(val,NULL);
            final->next=temp;
            final=final->next;
            if(sum+carry>9)
                carry=1;
            cout<<"carry"<<carry<<"sum"<<sum<<endl;

            temp1=temp1->next;
            temp2=temp2->next;
        }
            while(temp1)
            {
            int sum=temp1->val+carry;
            carry=0;
            temp1->val=sum%10;
                
            if(sum>9)
              carry=1;
            
              final->next=temp1;
                final=final->next;
                temp1=temp1->next;
            }
        while(temp2)
            {
            int sum=temp2->val+carry;
            carry=0;
            temp2->val=sum%10;
                
            if(sum>9)
              carry=1;
            
              final->next=temp2;
                final=final->next;
                temp2=temp2->next;
            }
        
        if(final)
            cout<<"final-val"<<final->val<<"carry"<<carry<<endl;
        if(carry==1)
        {
            
          ListNode* temp=new ListNode(1,NULL);
          final->next=temp;
          // final=final->next;
        }
        
        
        return dummy->next;
    }
};