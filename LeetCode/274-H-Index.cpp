class Solution {
public:
    int hIndex(vector<int>& citations) {
        int N = citations.size();
        if(N == 0)
            return 0;
        sort(citations.begin(), citations.end());
        int h = 0;
        for(int i = N-1; i >= 0; i--){
            if(citations[i] >= h+1)
                h++;
            else
                return h;
        }
        return h;
    }
};
