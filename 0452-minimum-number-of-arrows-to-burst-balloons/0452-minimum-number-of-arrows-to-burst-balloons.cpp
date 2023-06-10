class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
    int noOfArrows=1;
    sort(points.begin(), points.end()); // strictly increasing order
    
        for(auto it:points)
            for(auto it1:it)
                cout<<it1<<" ";
        cout<<endl;
    for(int i=1; i<points.size(); i++){
        int currStart=points[i][0]; // Current Interval's start point
        int currEnd=points[i][1]; // Current Interval's end point
        int preEnd=points[i-1][1]; // Previous Interval's end point

        if(currStart>preEnd){
            noOfArrows++;
            // cout<<"points[i][0]"<<points[i][0]<<endl;
            // cout<<"points[i][1]"<<points[i][1]<<endl;
            // cout<<"points[i-1][1]"<<points[i-1][1]<<endl;

            // no need to update minEnd here bcoz we sorted the array in strictly increasing order
        }
        else{
            points[i][1] = min(currEnd, preEnd); // Same as minEnd (as explained in the template)
        }
    }

    return noOfArrows;
}
};