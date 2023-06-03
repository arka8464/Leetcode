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
class cmp{
    public:
    bool operator()(ListNode*a,ListNode*b)
    {
        return a->val>b->val;
    }
};
class Solution {
   
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,cmp> pq;
        ListNode*dummy=new ListNode(-1e9,NULL);
        ListNode*tail=dummy;
        //ekta pq banchi jate min among all the current nodes gulo abante pari
        for(int i=0;i<lists.size();i++)
        {
            if(lists[i]!=NULL)
                pq.push(lists[i]);
        }
        
        while(!pq.empty())
        {
             ListNode*temp=pq.top();
            // temp->next=NULL;
            tail->next=temp;//amra ekhne prothom e i next ta ke null korchi na borom jokhon e kono minimum kuje pachi tar porer element ta keo push kore dichi pq te jate subidha hoi pore
            tail= tail->next;
            pq.pop();
            if(temp->next)
               pq.push(temp->next);
                
        }
        return dummy->next;
    }
};