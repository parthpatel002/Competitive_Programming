class Solution {
public:
    int maxPower(string s) {
        int N = s.size();
        if(N == 1)
            return N;
        int idx = 0;
        int cnt = 1;
        while(idx < N){
            int temp = 1;
            char ch = s[idx];
            idx++;
            while(idx < N && s[idx] == ch){
                idx++;
                temp++;
            }
            cnt = max(cnt, temp);
        }
        return cnt;
    }
};
