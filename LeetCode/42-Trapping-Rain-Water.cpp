class Solution {
public:
    int trap(vector<int>& height) {
        int N = height.size();
        if(N < 3)
            return 0;
        int maxi_l = height[0];
        vector<int> dp_l (N, 0);
        for(int i = 1; i < N-1; i++){
            dp_l[i] = maxi_l;
            maxi_l = max(maxi_l, height[i]);
        }
        int maxi_r = height[N-1];
        vector<int> dp_r (N, 0);
        for(int i = N-2; i > 0; i--){
            dp_r[i] = maxi_r;
            maxi_r = max(maxi_r, height[i]);
        }
        int cnt = 0;
        for(int i = 1; i < N-1; i++){
            int val = min(dp_l[i], dp_r[i]);
            if(val > height[i])
                cnt += val - height[i];
        }
        return cnt;
    }
};

