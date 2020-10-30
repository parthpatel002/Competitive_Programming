class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        int N = intervals.size();
        if(N <= 1)
            return intervals;
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        int idx = 0;
        while(1){
            int mini = intervals[idx][0];
            int maxi = intervals[idx][1];
            while(idx < N-1 && maxi >= intervals[idx+1][0]){
                maxi = max(maxi, intervals[idx+1][1]);
                idx++;
            }
            res.push_back(vector<int>{mini, maxi});
            if(idx == N-1)
                break;
            idx++;
        }
        return res;
        
    }
};
