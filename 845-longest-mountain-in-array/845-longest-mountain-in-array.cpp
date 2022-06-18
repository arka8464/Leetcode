class Solution {
public:
    int longestMountain(vector<int>& arr) {
       int max_length=0;
        if(arr.size()<3)
            return 0;
        for(int i=1;i<arr.size()-1;i++)
        {
            if(arr[i-1]<arr[i]&&arr[i+1]<arr[i])
            {
                int si=i,ei=i;
                while(si>0&&arr[si]>arr[si-1])
                    si--;
                while(ei<arr.size()-1&&arr[ei]>arr[ei+1])
                    ei++;
                cout<<"si"<<si<<"ei"<<ei<<endl;
                max_length=max(max_length,ei-si+1);
                i=ei;
            }
        }
        return max_length;
    }
};