class Solution {
public:
    ListNode* mergeTwoLists(ListNode* ptr1, ListNode* ptr2) {
        if(!ptr1||!ptr2)
        {
            return !ptr1?ptr2:ptr1;
        }
      
        ListNode*head= ptr1;

        if(ptr1&&ptr2)
        {
            if(ptr1->val<=ptr2->val)
            {
                ptr1=ptr1->next;
            }
            else
                
             {  
                head=ptr2;
                ptr2=ptr2->next;
            }

        }
                    

  ListNode*rear=head;
        while(ptr1&&ptr2)
        {
            // cout<<ptr1->val<<" "<<ptr2->val<<endl;
            //                 cout<<rear->val<<endl;
            if(ptr1->val<=ptr2->val)
               {
                
                rear->next=ptr1;
                ptr1=ptr1->next;
               }
            else
            {
                rear->next=ptr2;
                ptr2=ptr2->next; 
            }
            rear=rear->next;
        }
        while(ptr1)
        {
          rear->next=ptr1;
                ptr1=ptr1->next; 
            rear=rear->next;
        }
         while(ptr2)
        {
          rear->next=ptr2;
                ptr2=ptr2->next; 
            rear=rear->next;
        }
        rear->next=NULL;
        return head;
    }
};