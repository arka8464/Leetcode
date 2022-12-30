class Solution {
   
                            
public:
    int maxArea(vector<int>& height) {
        
        int left=0,right=height.size()-1;
        int ans=0;
        
        while(left<right)
        {
            int area=min(height[left],height[right])*abs(right-left);
            
            ans=max(area,ans);
            if(height[left]==height[right])left++,right--;
            else if(height[left]<height[right])left++;
            else if(height[left]>height[right])right--;
            
        }
        
        return ans;
    }
};