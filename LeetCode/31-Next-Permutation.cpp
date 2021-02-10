class Solution {
public:
    
    void swap(vector<int>& nums, int i, int j){
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    
    void reverse(vector<int>& nums, int i, int j){
        while(i < j){
            swap(nums, i, j);
            i++;
            j--;
        }
    }
        
    void nextPermutation(vector<int>& nums) {
        
        // Solution 1: Sorting
        // int N = nums.size();
        // if(N == 1)
        //     return;
        // int i;
        // for(i = N-1; i > 0; i--){
        //     if(nums[i] <= nums[i-1])
        //         continue;
        //     break;
        // }
        // if(i == 0)
        //     sort(nums.begin(), nums.end());
        // else{
        //     int min_idx = N-1;
        //     while(nums[min_idx] <= nums[i-1])
        //         min_idx--;
        //     swap(nums, min_idx, i-1);
        //     sort(nums.begin()+i, nums.end());
        // }
        
        // Solution 2: Reversing
        int N = nums.size();
        if(N == 1)
            return;
        int i;
        for(i = N-1; i > 0; i--){
            if(nums[i] <= nums[i-1])
                continue;
            break;
        }
        if(i == 0)
            reverse(nums, 0, N-1);
        else{
            int min_idx = N-1;
            while(nums[min_idx] <= nums[i-1])
                min_idx--;
            swap(nums, min_idx, i-1);
            reverse(nums, i, N-1);
        }

    }
};
