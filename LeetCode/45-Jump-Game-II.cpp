class Solution {
public:
    int jump(vector<int>& nums) {
        
        // DP - O(N*N) Time - TLE
        // int N = nums.size();
        // if(N == 1)
        //     return 0;
        // else if(N == 2)
        //     return 1;
        // if(nums[0] >= N-1)
        //     return 1;
        // vector<int> dp (N-1, 0);
        // dp[0] = nums[0]; 
        // for(int i = 1; i < N-1; i++){
        //     if(nums[i] == 0)
        //         continue;
        //     for(int j = i-1; j >= 0; j--){
        //         if(dp[j] >= i){
        //             dp[j+1] = max(dp[j+1], i+nums[i]);
        //         }
        //     }
        // }
        // for(int i = 1; i < N-1; i++){
        //     if(dp[i] >= N-1)
        //         return i+1;
        // }
        // return 1; // Satisfy Compiler
        
        
        // Greedy - O(N) Time
        int N = nums.size();
        if(N == 1 || nums[0] == 0){
            return 0;
        }
        int jumps = 1;
        int farthest = nums[0];
        int curr = nums[0];
        for(int i = 1; i < N; i++){
            if(i == N-1){
                return jumps;
            }
            farthest = max(farthest, i + nums[i]);
            if(i==curr){
                jumps++;
                curr = farthest;
            }
        }
        return jumps;
    }
};
