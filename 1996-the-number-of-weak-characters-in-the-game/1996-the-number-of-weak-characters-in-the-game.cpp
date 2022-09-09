class Solution {
   static bool compare(vector<int> &a, vector<int> &b){
       if(a[0]==b[0])return a[1]>b[1];
 else 
       return a[0]<b[0];
   }
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(),properties.end(),compare);
        int weak=0;
        // for(int i=0;i<properties.size();i++)
        // {
        //     for(int j=i+1;j<properties.size();j++)
        //     {
        //         if(properties[i][1]<properties[j][1]&&properties[i][0]<properties[j][0])
        //         {
        //             weak++;
        //             break;
        //         }
        //     }
        // }
          int maxTillnow=INT_MIN;
        for(int i=properties.size()-1;i>=0;i--)
             {
               
                 if(properties[i][1]<maxTillnow)weak++;
                 maxTillnow=max(maxTillnow,properties[i][1]);
             }
        return weak;
    }
};