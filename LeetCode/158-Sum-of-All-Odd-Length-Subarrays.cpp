class Solution {
public:
    
    int sumOddLengthSubarrays(vector<int>& arr) {
        
        int n = arr.size();
        if (n == 0)
            return 0;
        int cnt = 0;
        int dp[n][n];
        for(int i = 0; i < n; i++){
            dp[i][i] = arr[i];
            cnt += dp[i][i];            
        }
        for(int sz = 1; sz < n; sz++){
            for(int i = 0; i+sz < n; i++){
                int j = i+sz;
                dp[i][j] = dp[i][j-1] + arr[j];
                if (sz % 2 == 0)
                    cnt += dp[i][j];
            }
        }
        return cnt;
        
    }
};
