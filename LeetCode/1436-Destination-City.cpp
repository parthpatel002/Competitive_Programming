class Solution {
public:
    string destCity(vector<vector<string>>& paths) {

        unordered_map<string, int> umap;
        for(int i = 0; i < paths.size(); i++){
            if (umap.find(paths[i][0]) == umap.end())
                umap[paths[i][0]] = 2;
            else
                umap[paths[i][0]] += 2;
            if (umap.find(paths[i][1]) == umap.end())
                umap[paths[i][1]] = 1;
            else
                umap[paths[i][1]] += 1;
        }
        for(auto it = umap.begin(); it != umap.end(); it++)
            if (it->second == 1)
                return it->first;
        return ""; // Make compiler happy.

    }
};
