class Solution {
public:
    
    bool recur(string &s1, string &s2, int i, int j, int k, int l, int N, int * dp){
        if(i==j && k==l){
            if(s1[i] == s2[k]){
                //dp[i][j][k][l] = 1;
                dp[l+N*(k+N*(j+N*(i)))] = 1;
                return true;
            }
            else{
                dp[l+N*(k+N*(j+N*(i)))] = 0;
                return false;
            }
        }    
        for(int x = 0; x < j-i; x++){
            if(dp[k+x+N*(k+N*(i+x+N*(i)))]/*dp[i][i+x][k][k+x]*/ == -1)
                recur(s1, s2, i, i+x, k, k+x, N, dp);
            if(dp[l+N*(k+x+1+N*(j+N*(i+x+1)))]/*dp[i+x+1][j][k+x+1][l]*/ == -1)
                recur(s1, s2, i+x+1, j, k+x+1, l, N, dp);
            if(dp[k+x+N*(k+N*(i+x+N*(i)))]==1 && dp[l+N*(k+x+1+N*(j+N*(i+x+1)))]==1){
                dp[l+N*(k+N*(j+N*(i)))] = 1;
                return true;
            }
            if(dp[l+N*(l-x+N*(i+x+N*(i)))]/*dp[i][i+x][l-x][l]*/ == -1)
                recur(s1, s2, i, i+x, l-x, l, N, dp);
            if(dp[l-x-1+N*(k+N*(j+N*(i+x+1)))]/*dp[i+x+1][j][k][l-x-1]*/ == -1)
                recur(s1, s2, i+x+1, j, k, l-x-1, N, dp);
            if(dp[l+N*(l-x+N*(i+x+N*(i)))]==1 && dp[l-x-1+N*(k+N*(j+N*(i+x+1)))]==1){
                dp[l+N*(k+N*(j+N*(i)))] = 1;
                return true;
            }    
        }
        dp[l+N*(k+N*(j+N*(i)))] = 0;
        return false;
    }
        
    bool isScramble(string s1, string s2) {
        int l1 = s1.length();
        int l2 = s2.length();
        if(l1 != l2)
            return false;
        int dp[l1*l1*l1*l1];
        for(int i = 0; i < l1*l1*l1*l1; i++)
            dp[i] = -1;
        return recur(s1, s2, 0, l1-1, 0, l2-1, l1, dp);                
    }
};
