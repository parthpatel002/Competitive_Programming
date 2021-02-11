class Solution {
public:
    bool canPlaceFlowers(vector<int>& bed, int n) {
        int N = bed.size();
        if(N == 1){
            if(bed[0] == 0)
                return 1 >= n;
            return 0 >= n;
        }
        int cnt = 0;
        int i = 0;
        while(i < N && bed[i] == 0)
            i++;
        if(i == N)
            return ((N/2)+(N%2)) >= n;
        if(i != 0){
            cnt += ((i-1)/2) + ((i-1)%2);
            if(cnt >= n)
                return true;
        }
        int prev;
        while(1){
            prev = i;
            i++;
            while(i < N && bed[i] == 0)
                i++;
            if(i == N){
                if(N - prev - 2 > 0)
                    cnt += ((N-prev-2)/2) + ((N-prev-2)%2);
                return cnt >= n;
            }
            else{
                if(i - prev - 3 > 0)
                    cnt += ((i-prev-3)/2) + ((i-prev-3)%2);
                if(cnt >= n)
                    return true;
            }
        }
        return cnt >= n; // Satisfy Compiler
    }
};
