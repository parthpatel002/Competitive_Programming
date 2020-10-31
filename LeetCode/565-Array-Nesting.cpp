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
    int arrayNesting(vector<int>& nums) {
        int N = nums.size();
        if(N == 1)
            return 1;
        
        // Solution 1 (using union find data structure)
        // UnionFindSize ufs (N);
        // for(int i = 0; i < N; i++)
        //     ufs.union_(i, nums[i]);
        // int maxs = 0;
        // for(int i = 0; i < N; i++)
        //     maxs = max(maxs, ufs.get_size(i));
        // return maxs;
        
        // Solution 2 (modify input array in-place for storing visited information)
        int idx  = 0;
        int maxs = 0;
        bool flag = false;
        while(idx < N){
            if((nums[idx] < 0) || (nums[idx] == 0 && flag)){
                idx++;
                continue;
            }
            int temp = idx;
            int currs = 0;
            while((nums[temp] > 0) || (nums[temp] == 0 && !flag)){
                currs++;
                if(nums[temp] > 0)
                    nums[temp] *= -1;
                else
                    flag = true;
                temp = -1 * nums[temp];
            }
            maxs = max(maxs, currs);
            idx++;
        }
        return maxs;
        
    }
};
