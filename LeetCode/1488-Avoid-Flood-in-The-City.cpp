class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int N = rains.size();
        if(N == 1){
            if(rains[0] != 0)
                return vector<int> (1, -1);
            else
                return vector<int> (1, 1);
        }
        unordered_map<int, int> umap;
        vector<pair<int, bool>> v;
        int cntr = 0;
        vector<int> out (N, -1);
        for(int i = 0; i < N; i++){
            if(rains[i] == 0){
                out[i] = 1;
                v.push_back(make_pair(i, true));
            }
            else{
                if(umap.find(rains[i]) == umap.end()){
                    umap[rains[i]] = i;
                }
                else{
                    int prev = umap[rains[i]];
                    umap[rains[i]] = i;
                    bool flag = true;
                    for(int j = cntr; j < v.size(); j++){
                        if(v[j].second && prev < v[j].first){
                            v[j].second = false;
                            out[v[j].first] = rains[i];
                            flag = false;
                            if(j == cntr)
                                cntr++;
                            break;
                        }
                    }
                    if(flag)
                        return vector<int>();
                }
            }
        }
        return out;
    }
};
