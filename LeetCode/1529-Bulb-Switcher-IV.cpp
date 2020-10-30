class Solution {
public:
    int minFlips(string target) {
        int idx = 0;
        int cnt = 0;
        while(idx < target.size() && target[idx] == '0')
            idx++;
        if (idx == target.size())
            return cnt; // return 0
        cnt++;
        char ch = '1';
        while(1){
            while(idx < target.size() && target[idx] == ch){
                idx++;
            }
            if (idx >= target.size())
                return cnt;
            cnt++;
            ch = (ch == '0')?'1':'0';
        }
        return cnt; // Make compiler happy
    }
};
