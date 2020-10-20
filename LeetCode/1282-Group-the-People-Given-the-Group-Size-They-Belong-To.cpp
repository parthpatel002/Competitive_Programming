class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        
        // unordered_map<int, vector<int>> umap;
        // for(int i = 0; i < groupSizes.size(); i++){
        //     if (umap.find(groupSizes[i]) == umap.end()){
        //         umap[groupSizes[i]] = vector<int>(1, i);
        //     }
        //     else{
        //         umap[groupSizes[i]].push_back(i);
        //     }
        // }
        // vector<vector<int>> groups;
        // for(auto itr = umap.begin(); itr != umap.end(); itr++){
        //     int sz = itr->first;
        //     for(int i = 0; i < itr->second.size(); i += sz){
        //         vector<int> vec;
        //         for (int j = i; j < i+sz; j++){
        //             vec.push_back(itr->second[j]);
        //         }
        //         groups.push_back(vec);
        //     }
        // }
        // return groups;
        
        // vector<vector<int>> groups;
        // unordered_map<int, vector<int>> umap;
        // for(int i = 0; i < groupSizes.size(); i++){
        //     if (umap.find(groupSizes[i]) == umap.end()){
        //         umap[groupSizes[i]] = vector<int>(1, i);
        //     }
        //     else{
        //         umap[groupSizes[i]].emplace_back(i);
        //     }
        //     if (umap[groupSizes[i]].size() == groupSizes[i]){
        //         groups.emplace_back(umap[groupSizes[i]]);
        //         umap[groupSizes[i]] = vector<int>();
        //     }
        // }
        // for(auto itr = umap.begin(); itr != umap.end(); itr++){
        //     if (itr->second.size() != 0)
        //         groups.emplace_back(itr->second);
        // }
        // return groups;
        
        // vector<vector<int>> groups;
        // unordered_map<int, int> size_to_idx;
        // for(int i = 0, size = groupSizes.size(); i != size; ++i){
        //     auto it = size_to_idx.find(groupSizes[i]);
        //     if(it == size_to_idx.end() || groupSizes[i] == groups[it->second].size()){
        //         size_to_idx[groupSizes[i]] = groups.size();
        //         groups.emplace_back(1, i);
        //     } else 
        //         groups[it->second].push_back(i);
        // }
        // return groups;
        
    }
};
