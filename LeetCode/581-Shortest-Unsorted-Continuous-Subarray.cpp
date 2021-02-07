class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int N = nums.size();
        if(N == 1)
            return 0;
        else if(N == 2){
            if(nums[0] <= nums[1])
                return 0;
            else
                return 2;
        }
        int i = 0;
        while(i < N-1 && nums[i] <= nums[i+1])
            i++;
        if(i == N-1)
            return 0;
        int j = N-1;
        while(j > 0 && nums[j] >= nums[j-1])
            j--;
        int mini = nums[i];
        int maxi = nums[i];
        for(int k = i+1; k <= j; k++){
            mini = min(mini, nums[k]);
            maxi = max(maxi, nums[k]);
        }
        int l = 0;
        while(l < i && nums[l] <= mini)
            l++;
        int r = N-1;
        while(r > j && nums[r] >= maxi)
            r--;
        return r-l+1;
    }
};
