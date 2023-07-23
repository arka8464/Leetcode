class Solution {
public:
    vector<string> splitWordsBySeparator(vector<string>& words, char separator) {
        
        vector<string> ans;
        for(auto it:words)
        {
            string s=it;
            istringstream ss(s);
            string token;
            
            while(getline(ss,token,separator))
            {
                if(token.size()>0)
                    ans.push_back(token);
            }
        }
        return ans;
//         for(int i=0;i<words.size();i++)
//         {
//             string temp;
            
//             for(int j=0;j<words[i].size();j++)
//             {
//                 int ascii=(int)words[i][j];
//                 if(words[i][j]==separator)
//                 {
//                     if(temp.size()>0)
//                        ans.push_back(temp);
//                     temp.clear();
//                 }
//                 else
//                 {
//                     temp.push_back(words[i][j]);
//                 }
//             }
//             if(temp.size()>0)
//           ans.push_back(temp);

//         }
        
        
        // return ans;
    }
};