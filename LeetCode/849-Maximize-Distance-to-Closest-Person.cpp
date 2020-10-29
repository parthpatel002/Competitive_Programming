class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        
        if (seats.size() == 2)
            return 1;
        int idx = 0;
        while(seats[idx] == 0)
            idx++;
        int cnt = max(0, idx);
        int prev = idx;
        idx++;
        while(1){
            while(idx < seats.size() && seats[idx]==0)
                idx++;
            int temp = idx - prev;
            if(idx == seats.size())
                cnt = max(cnt, temp-1);
            else
                cnt = max(cnt, (temp-(temp%2))/2);
            prev = idx;
            idx++;
            if(idx >= seats.size())
                break;
        }
        return cnt;
        
    }
};
