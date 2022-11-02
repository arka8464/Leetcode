class Solution {
    private:
    void dfs(int sr,int sc,vector<vector<int>> &image,int val,int newcolor)
    {      
        if(sr<0 || sr>=image.size() || sc<0 || sc>=image[0].size() || image[sr][sc]==newcolor||image[sr][sc]!=val)return;

         image[sr][sc] = newcolor;
        dfs(sr-1,sc,image,val,newcolor);
        dfs(sr+1,sc,image,val,newcolor);
        dfs(sr,sc-1,image,val,newcolor);
        dfs(sr,sc+1,image,val,newcolor);
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newcolor) {
        // if(image[sr][sc]==newcolor)return image;
       
        int val=image[sr][sc];
        dfs(sr,sc,image,val,newcolor);
        return image;
    }
};