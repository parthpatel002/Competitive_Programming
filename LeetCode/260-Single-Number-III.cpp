class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        
        if(nums.size() <= 2)
            return nums;
        int res {0};
        for (const auto &num : nums) 
            res ^= num;
        
        int temp {res};
        int p {0};
        while (!(temp & 1)) {
            ++p;
            temp >>= 1;
        }
               
        int mask {1 << p}; 
        int x {0};
        int y {0};
        
        for (const auto &num : nums)
            if (num & mask)
                y ^= num;
               
        x = res ^ y;
        return vector<int> {x, y};
        
    }
};
