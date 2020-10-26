class Solution {
public:
    
    // Instead of keeping track of how much champagne should end up in a glass, keep track of the total 
    // amount of champagne that flows through a glass. For example, if poured = 10 cups are poured at 
    // the top, then the total flow-through of the top glass is 10; the total flow-through of each 
    // glass in the second row is 4.5, and so on.

    void recurse(int i, int j, double& poured, vector<vector<double>>& dp){
        if(i==0 && j==0){
            dp[i][j] = poured;
            return;
        }
        if(j==0){
            double x = dp[i-1][j];
            if(x == -1.0)
                recurse(i-1, j, poured, dp);
            x = dp[i-1][j];
            if(x <= 1.0)
                dp[i][j] = 0.0;
            else
                dp[i][j] = (x-1.0) / 2.0;
            return;
        }
        if(j==i){
            double y = dp[i-1][j-1];
            if(y == -1.0)
                recurse(i-1, j-1, poured, dp);
            y = dp[i-1][j-1];
            if(y <= 1.0)
                dp[i][j] = 0.0;
            else
                dp[i][j] = (y-1.0) / 2.0;
            return;
        }
        double x = dp[i-1][j];
        if(x == -1.0)
            recurse(i-1, j, poured, dp);
        x = dp[i-1][j];
        if(x <= 1.0)
            dp[i][j] = 0.0;
        else
            dp[i][j] = (x-1.0) / 2.0;
        double y = dp[i-1][j-1];
        if(y == -1.0)
            recurse(i-1, j-1, poured, dp);
        y = dp[i-1][j-1];
        if(y > 1.0)
            dp[i][j] += (y-1.0) / 2.0;
    }
    
    double champagneTower(int pour, int query_row, int query_glass) {
        
        double poured = (double) pour;
        vector<vector<double>> dp (query_row+1, vector<double>(query_row+1, -1.0));
        recurse(query_row, query_glass, poured, dp);
        double amt = dp[query_row][query_glass];
        return (amt>=1.0) ? 1.0 : amt;
        
    }
    
};
