class Solution {
public:
    int numOfWays(int n) {
        // Below:
        // a represents no. of arrangements for (n-1) rows s.t. last row has all three colors
        // a_ represents no. of arrangements for n rows s.t. last row has all three colors
        // b represents no. of arrangements for (n-1) rows s.t. last row has only two distinct colors
        // b_ represents no. of arrangements for n rows s.t. last row has only two distinct colors
        long long int a = 1, b = 1;
        int mod = 1e9 + 7;
        for(int i = 1; i < n; i++){
            long long int a_ = ((2*a) + (2*b)) % mod;
            long long int b_ = ((2*a) + (3*b)) % mod;
            a = a_;
            b = b_;
        }
        // We multiply both a and b by 6 since there are:
        // 6 ways to arrange tiles s.t. first row has all three colors.
        // 6 ways to arrange tiles s.t. first row has only two distinct colors, and 
        long long int ans = (6*a + 6*b) % mod;
        return ans;
    }
};
