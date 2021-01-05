class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int> umap;
        for(int i = 0; i < wall.size(); i++){
            int cnt = 0;
            for(int j = 0; j < wall[i].size() - 1; j++){
                cnt += wall[i][j];
                umap[cnt]++;
            }
        }
        int maxcnt = 0;
        for(auto it = umap.begin(); it != umap.end(); it++){
            if(it->second > maxcnt){
                maxcnt = it->second;
            }
        }
        return wall.size() - maxcnt;
    }
};
