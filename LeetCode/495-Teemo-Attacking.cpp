class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        
        int N = timeSeries.size();
        if(N <= 1)
            return N * duration;
        int maxi = timeSeries[0] + duration - 1;
        int cnt = duration;
        for(int i = 1; i < timeSeries.size(); i++){
            if(maxi < timeSeries[i])
                cnt += duration;
            else
                cnt += (timeSeries[i] + duration - 1 - maxi);
            maxi = timeSeries[i] + duration - 1;
        }
        return cnt;
    
    }
};
