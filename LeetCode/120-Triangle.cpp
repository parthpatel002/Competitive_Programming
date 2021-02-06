class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int N = triangle.size();
        if(N == 1)
            return triangle[0][0];
        vector<vector<int>> dp (2, vector<int>(N, 0));
        dp[0][0] = triangle[0][0];
        for(int curr = 1; curr < N; curr++){
            for(int j = 0; j <= curr; j++){
                if(j == 0){
                    dp[curr%2][j] = triangle[curr][j] + dp[(curr-1)%2][j];
                }
                else if(j == curr){
                    dp[curr%2][j] = triangle[curr][j] + dp[(curr-1)%2][j-1];
                }
                else{
                    dp[curr%2][j] = triangle[curr][j] + min(dp[(curr-1)%2][j-1], dp[(curr-1)%2][j]);
                }
            }
        }
        int mini = 1000000;
        for(int i = 0; i < N; i++)
            if(mini > dp[(N-1)%2][i])
                mini = dp[(N-1)%2][i];
        return mini;
    }
};
