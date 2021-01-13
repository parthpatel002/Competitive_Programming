class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int N = nums.size();
        if(N <= 1)
            return N;
        if(N == 2){
            if(nums[0] == nums[1])
                return 1;
            return N;
        }
        vector<int> p (N, 1);
        vector<int> n (N, 1);
        int maxi = 1;
        for(int i = 1; i < N; i++){
            for(int j = i-1; j >= 0; j--){
                if(nums[j] < nums[i]){
                    p[i] = max(p[i], n[j]+1);
                    maxi = max(maxi, p[i]);
                }
                else if(nums[j] > nums[i]){
                    n[i] = max(n[i], p[j]+1);
                    maxi = max(maxi, n[i]);
                }
            }   
        }
        return maxi;
    }
};
