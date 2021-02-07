class NumMatrix {
public:
    
    vector<vector<int>> dp;
    int M;
    int N;
    
    NumMatrix(vector<vector<int>>& matrix) {
        M = matrix.size();
        if(M == 0)
            return;
        N = matrix[0].size();
        if(N == 0)
            return;
        dp = vector<vector<int>> (M, vector<int>(N, 0));
        dp[0][0] = matrix[0][0];
        for(int i = 1; i < M; i++)
            dp[i][0] = dp[i-1][0] + matrix[i][0];
        for(int j = 1; j < N; j++)
            dp[0][j] = dp[0][j-1] + matrix[0][j];
        for(int i = 1; i < M; i++){
            int run_sum = matrix[i][0];
            for(int j = 1; j < N; j++){
                run_sum += matrix[i][j];
                dp[i][j] = run_sum + dp[i-1][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if(M == 0 || N == 0)
            return 0;
        int sum1 = dp[row2][col2];
        int sum2 = (row1 == 0)?0:dp[row1-1][col2];
        int sum3 = (col1 == 0)?0:dp[row2][col1-1];
        int sum4 = (row1 == 0 || col1 == 0)?0:dp[row1-1][col1-1];
        return sum1 - sum2 - sum3 + sum4;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
