struct HASH {
  size_t operator() (const pair<vector<bool>, pair<int, int>>& x) const {
    int N = x.first.size();
    long long sum = 0;
    for(int i = 0; i < N; i++){
        sum += x.first[i];
        sum *= 2;
    }
    sum *= 1000;
    sum += x.second.first;
    sum *= 10;
    sum += x.second.second;
    return hash<long long>()(sum);
  }
};

class Solution {
public:
    
    void canWin(vector<bool>& used, int sum, int player, unordered_map<pair<vector<bool>, pair<int, int>>, bool, HASH>& umap){
        if(umap.find(make_pair(used, make_pair(sum, player))) != umap.end())
            return;
        int N = used.size();
        for(int i = 0; i < N; i++){
            if(used[i])
                continue;
            bool flag = true;
            used[i] = true;
            if(sum > i+1){
                canWin(used, sum-i-1, (player+1)%2, umap);
                if(umap[make_pair(used, make_pair(sum-i-1, (player+1)%2))])
                    flag = false;
            }
            used[i] = false;
            if(flag){
                umap[make_pair(used, make_pair(sum, player))] = true;
                return;
            }
        }
        umap[make_pair(used, make_pair(sum, player))] = false;
    }
    
    bool canIWin(int N, int S) {
        if(N*(N+1) < 2*S)
            return false;
		    if(N >= S)
			      return true;
        unordered_map<pair<vector<bool>, pair<int, int>>, bool, HASH> umap;
        vector<bool> used (N, false);
        canWin(used, S, 0, umap);
        vector<bool> temp (N, false);
        return umap[make_pair(temp, make_pair(S, 0))];
    }
};
