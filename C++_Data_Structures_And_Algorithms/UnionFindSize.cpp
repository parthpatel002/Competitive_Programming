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

