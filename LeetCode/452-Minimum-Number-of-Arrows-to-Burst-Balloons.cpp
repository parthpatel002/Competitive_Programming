struct compare
{
    bool operator()( vector<int>& a, vector<int>&b)
    {
        if( a[0] == b[0])
            return a[1] < b[1];
        else
            return a[0] < b[0];
    }
};

class Solution {
public:
    
    static bool cmp(vector <int>& a, vector <int>& b){
        return a[1] < b[1];
    }
    
    int findMinArrowShots(vector<vector<int>>& points) {
        
        // Solution 1:
        // sort(points.begin() , points.end() , compare());
        // int n = points.size();
        // if(n == 0 || n == 1)
        //     return n;
        // int end = points[0][1];
        // int count = 1;
        // for(int i = 1; i < n; i++){
        //     if(end < points[i][0]){
        //         count++;
        //         end = points[i][1];
        //     }
        //     else{
        //         end = min(end, points[i][1]);
        //     }
        // }
        // return count;
        
        // Solution 2:
        // sort(points.begin(), points.end(), cmp);
        // int n = points.size();
        // if(!n) return 0;
        // int currEnd = points[0][1];
        // int cnt = 1;
        // for(int i = 1; i < n; i++){
        //     if(currEnd < points[i][0]){
        //         cnt++;
        //         currEnd = points[i][1];
        //     }
        // }
        // return cnt;
        
    }
    
};
