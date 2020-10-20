class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int N = nums.size();
        if (N <= 2)
            return true;
        bool flag = false;
        for(int i = 0; i < N-1; i++){
            if (nums[i] > nums[i+1]){
                if (flag)
                    return false;
                int maxi = nums[i+1];
                int mini = (i==0)?-100000:nums[i-1];
                if (mini > maxi){
                    nums[i+1] = nums[i];   
                }
                flag = true;
            }
        }
        return true;
    }
};
