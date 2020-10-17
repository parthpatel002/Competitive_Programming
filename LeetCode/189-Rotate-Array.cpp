class Solution {
public:
    
    void reverse(vector<int>& nums, int st, int end){
        while(st < end){
            int temp = nums[st];
            nums[st] = nums[end];
            nums[end] = temp;
            st++;
            end--;
        }
    }
    
    void rotate(vector<int>& nums, int k) {
        
        // Solution 1:
        // int n = nums.size();
        // k = k % n;
        // reverse(nums, 0, n-1);
        // reverse(nums, 0, k-1);
        // reverse(nums, k, n-1);
        
        // Solution 2: Cyclic Reordering
        // int n = nums.size();
        // k = k % n;
        // if (k == 0)
        //     return;
        // int cnt = 0;
        // for(int i = 0; cnt < n; i++){
        //     int curr = i;
        //     int prev = nums[curr];
        //     while(1){
        //         int nxt = (curr + k) % n;
        //         int temp = nums[nxt];
        //         nums[nxt] = prev;
        //         curr = nxt;
        //         prev = temp;
        //         cnt++;
        //         if (curr == i)
        //             break;
        //     }
        // }
        
        // Solution 3: Cyclic Reordering (in Reverse)
        // int n = nums.size();
        // k = k % n;
        // k = (n - k) % n;
        // if (k == 0)
        //     return;
        // int cnt = 0;
        // for(int i = 0; cnt < n; i++){
        //     int curr = i;
        //     int temp = nums[curr];
        //     int nxt = (curr + k) % n;;
        //     while(1){
        //         nums[curr] = nums[nxt];
        //         cnt++;
        //         curr = nxt;
        //         nxt = (curr + k) % n;
        //         if (nxt == i)
        //             break;
        //     }
        //     nums[curr] = temp;
        //     cnt++;
        // }
        
    }
};
