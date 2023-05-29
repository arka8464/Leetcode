class Solution {
public:
    int hIndex(vector<int>& citations) {
        int low=0,high=citations.size()-1;
        if(citations.size()<=0)
            return 0;
        int hidx=0;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            
            // bool a =citations[mid]<=citations.size();
             // bool b =citations[mid]>=(citations.size()-mid+1);
             // bool b =citations[mid]<=citations[high];
       // bool a=citations[mid]<= (citations.size()-1)-mid+1;
      // cout<<"citations.size()-mid+1   "<<citations.size()-1-mid<<endl;
            // cout<<citations[mid]<<" "<<a<<" "<<b<<endl;
            if(citations[mid]>=citations.size()-mid)
            {
                hidx=citations.size()-mid;
                high=mid-1;
                
            }
            else
                low=mid+1;
        }
        
        return hidx;
    }
};