class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
       int n = heights.size();
      stack < int > st;
      int leftsmall[n], rightsmall[n];
      for (int i = 0; i < n; i++) {
        while (!st.empty() && heights[st.top()] >= heights[i]) {
          st.pop();
        }
        if (st.empty())
          leftsmall[i] = 0;
        else
          leftsmall[i] = st.top() + 1;
        st.push(i);
      }
      // clear the stack to be re-used
      while (!st.empty())
        st.pop();

      for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && heights[st.top()] >= heights[i])
          st.pop();

        if (st.empty())
          rightsmall[i] = n - 1;
        else
          rightsmall[i] = st.top() - 1;

        st.push(i);
      }
      int maxA = 0;
      for (int i = 0; i < n; i++) {
        maxA = max(maxA, heights[i] * (rightsmall[i] - leftsmall[i] + 1));
      }
      return maxA;
      
    }
};



// class Solution {
//     vector<int> nsefind(vector<int>& heights)
//     {
//        stack<pair<int,int>>s;
//         vector<int> nse;
//         for(int i=heights.size()-1;i>=0;i--)
//         {
//             while(!s.empty()&&s.top().second>heights[i])s.pop();

//             if(s.empty())
//                 nse.push_back(heights.size()-1);
//             else
//                nse.push_back(s.top().first-1); 
//             s.push(make_pair(i,heights[i]));
            
//         // cout<<s.size()<<"<-size  "<<s.top().first<<" "<<s.top().second<<endl;
       
//         }
//         reverse(nse.begin(), nse.end());
//         return nse; 
        
//     }
//     vector<int> psefind(vector<int>& heights)
//     {
//         stack<pair<int,int>>s;
//         vector<int> pse;
//         for(int i=0;i<heights.size();i++)
//         {
//             while(!s.empty()&&s.top().second>heights[i])s.pop();
            
//             if(s.empty())
//                 pse.push_back(0);
//             else
//                pse.push_back(s.top().first+1); 
//             s.push(make_pair(i,heights[i]));
//         }
//         return pse;
//     }
// public:
//     int largestRectangleArea(vector<int>& heights) {
       
//         vector<int> nse=nsefind( heights);
//        vector<int> pse=psefind( heights);
        
//         int area=INT_MIN;
//           for(int i=0;i<nse.size();i++)cout<<nse[i]<<" ";
//           cout<<"nse"<<endl;
//         for(int i=0;i<pse.size();i++)cout<<pse[i]<<" ";
//         cout<<"pse"<<endl; 

//         for(int i=0;i<heights.size();i++)
//         {
//             area=max(area,heights[i]*(nse[i]-pse[i]+1));
//         }
//         return area;
//     }
// };