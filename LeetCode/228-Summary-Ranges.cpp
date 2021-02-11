class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int N = nums.size();
        vector<string> vec;
        if(N == 0)
            return vec;
        if(N == 1){
            vec.push_back(std::to_string(nums[0]));
            return vec;
        }
        int st = 0, end;
        while(1){
            end = st+1;
            while(end < N && nums[end-1] + 1 == nums[end])
                end++;
            string str = std::to_string(nums[st]);
            if(st < end-1){
                str += "->";
                str += std::to_string(nums[end-1]);
            }
            vec.push_back(str);
            if(end == N){
                return vec;
            }
            st = end;
        }
        return vec; // Satisfy Compiler
    }
};
