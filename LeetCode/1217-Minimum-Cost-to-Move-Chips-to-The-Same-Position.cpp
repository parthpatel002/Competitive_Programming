class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int N = position.size();
        if(N == 1)
            return 0;
        int even = 0;
        int odd = 0;
        for(int i = 0; i < N; i++)
            if(position[i] % 2 == 0)
                even++;
            else
                odd++;
        return min(odd, even);
    }
};
