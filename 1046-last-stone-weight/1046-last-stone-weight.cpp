class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        
        for(int i=0;i<stones.size();i++)
        {
            pq.push(stones[i]);
        }
        
        while(!pq.empty()&&pq.size()>1)
        {
            int top=pq.top();
            pq.pop();
            int secondTop=pq.top();
            pq.pop();
            if(top!=secondTop)
                pq.push(abs(top-secondTop));
            
        }
        
        if(pq.empty())
            return 0;
        else
            return pq.top();
        
    }
};