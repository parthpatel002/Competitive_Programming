class UnionFind{
private:
    vector<int> arr;
    int cnt;
    
public:
    UnionFind(int N) : arr(vector(N, 0)), cnt(N) {
        for(int i = 0; i < N; i++)
            arr[i] = i;
    }
    
    int count(){
        return cnt;
    }

    int find(int i){
        while(i != arr[i]){
            arr[i] = arr[arr[i]];
            i = arr[i];
        }
        return i;
    }
    
    void union_(int p, int q){
        int rp = find(p);
        int rq = find(q);
        if (rp == rq)
            return;
        arr[rp] = rq;
        cnt--;
    }
    
    bool connected(int p, int q){
        return find(p) == find(q);
    }
};

