class UnionFindSize{
private:
    vector<int> arr;
    vector<int> size;
    int cnt;
    
public:
    UnionFindSize(int N) : arr(vector(N, 0)), cnt(N), size(vector(N, 1)) {
        for(int i = 0; i < N; i++)
            arr[i] = i;
    }
    
    int count(){
        return cnt;
    }

    int find(int i){
        while(i != arr[i])
            i = arr[i];
        return i;
    }
    
    int get_size(int i){
        return size[i];
    }
    
    void union_(int p, int q){
        int rp = find(p);
        int rq = find(q);
        if (rp == rq)
            return;
        if(size[rp] >= size[rq]){
            arr[rq] = rp;
            size[rp] += size[rq];
        }
        else{
            arr[rp] = rq;
            size[rq] += size[rp];
        }
        cnt--;
    }
    
    bool connected(int p, int q){
        return find(p) == find(q);
    }
};

class Solution {
public:
    int findLatestStep(vector<int>& arr, int M) {
        
        // Solution 1: TLE:
        // int N = arr.size();
        // if(N == M)
        //     return N;
        // for(int i = 0; i < N; i++)
        //     arr[i] -= 1;
        // vector<int> s (N, 1);
        // vector<int> sz (N, N);
        // vector<int> idx (N, 0);
        // for(int i = 0; i < N; i++)
        //     idx[i] = i;
        // for(int i = N-1; i > 0; i--){
        //     s[arr[i]] = 0;
        //     int size = sz[arr[i]];
        //     int index = idx[arr[i]];
        //     int lsize = index;
        //     if(lsize == M)
        //         return i;
        //     int rsize = size-index-1;
        //     if(rsize == M)
        //         return i;
        //     for(int cnt = 0, j = arr[i] - lsize; j < arr[i]; j++, cnt++){
        //         sz[j] = lsize;
        //         idx[j] = cnt;
        //     }
        //     for(int cnt = 0, j = arr[i]+1; j <= arr[i] + rsize; j++, cnt++){
        //         sz[j] = rsize;
        //         idx[j] = cnt;
        //     }
        //     sz[arr[i]] = -1;
        //     idx[arr[i]] = -1;
        // }
        // return -1;
        
        // Solution 2: Maintain/update length of group only at its ends.
        // int N = arr.size();
        // if(N == M)
        //     return N;
        // vector<int> len(N+2);
        // int res = -1;
        // for(int i = 0;i < N; i++)
        // {
        //     int a = arr[i];
        //     int left = len[a-1];
        //     int right = len[a+1];
        //     if(left == M or right == M)
        //         res = i;
        //     len[a-left] = len[a+right] = left+right+1;
        // }
        // return res;
        
        // Solution 3: Union Find Size
        int N = arr.size();
        if(N == M)
            return N;
        for(int i = 0; i < N; i++)
            arr[i] -= 1;
        vector<int> s (N, 0);
        UnionFindSize uf (N);
        int res = -1;
        for(int i = 0; i < N; i++){
            s[arr[i]] = 1;
            if(arr[i] > 0 && s[arr[i]-1] == 1){
                if(uf.get_size(uf.find(arr[i]-1)) == M)
                    res = i;
                uf.union_(arr[i], arr[i]-1);
            }
            if(arr[i] < N-1 && s[arr[i]+1] == 1){
                if(uf.get_size(uf.find(arr[i]+1)) == M)
                    res = i;
                uf.union_(arr[i], arr[i]+1);
            }
            if(uf.get_size(uf.find(arr[i])) == M)
               res = i+1;
        }
        return res;
        
    }
};
