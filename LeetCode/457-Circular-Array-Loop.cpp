class Solution {
public:
    
    int getNext(int ptr, int N, bool forward, vector<int>& nums){
        bool direction = nums[ptr] > 0;
        if(direction != forward)
            return -1;
        if(nums[ptr] % N == 0)
            return -1;
        return ((ptr + nums[ptr]) % N + N) % N;
    }
    
    bool circularArrayLoop(vector<int>& nums) {
        int N = nums.size();
        for(int i = 0; i < N; i++){
            if(nums[i] % N == 0)
                continue;
            bool forward = nums[i] > 0;
            int slow = i;
            int fast = i;
            while(1){
                slow = getNext(slow, N, forward, nums);
                if(slow == -1)
                    break;
                fast = getNext(fast, N, forward, nums);
                if(fast == -1)
                    break;
                fast = getNext(fast, N, forward, nums);
                if(fast == -1)
                    break;
                if(slow == fast)
                    return true;
            }
        }
        return false;
    }
};
