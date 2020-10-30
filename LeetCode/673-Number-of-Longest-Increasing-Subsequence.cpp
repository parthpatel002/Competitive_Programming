class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        
        int N = nums.size();
        if (N <= 1)
            return N;
        
        vector<int> dp (N, 1);
        vector<int> cnt (N, 1);
        for(int i = 1; i < N; i++)
            for(int j = i-1; j >= 0; j--)
                if(nums[i] > nums[j]){
                    if(dp[j] >= dp[i]){
                        dp[i] = 1+dp[j];
                        cnt[i] = cnt[j];
                    }
                    else if(dp[i]==dp[j]+1){
                        cnt[i] += cnt[j];
                    }
                }
        
        int lis = dp[0];
        for(int idx = 1; idx < N; idx++)
            lis = max(lis, dp[idx]);
        
        int count = 0;
        for(int idx = 0; idx < N; idx++)
            if(dp[idx] == lis)
                count += cnt[idx];
        return count;
        
    }
};
