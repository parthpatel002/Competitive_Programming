class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        if(grid[0][0] == 1)
            return 0;
        int M = grid.size();
        int N = grid[0].size();
        vector<vector<int>> dp (M, vector<int>(N, 0));
        dp[0][0] = 1;
        for(int i = 1; i < M; i++){
            if(grid[i][0] == 0){
                dp[i][0] = dp[i-1][0];
            }
        }
        for(int j = 1; j < N; j++){
            if(grid[0][j] == 0){
                dp[0][j] = dp[0][j-1];
            }
        }
        for(int i = 1; i < M; i++){
            for(int j = 1; j < N; j++){
                if(grid[i][j] == 0){
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }
        return dp[M-1][N-1];
    }
};
