class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> umap;
    
public:
    /** Initialize your data structure here. */
    TimeMap() : umap({}) { }
    
    void set(string key, string value, int timestamp) {
        if(umap.find(key) == umap.end())
            umap[key] = vector<pair<int, string>>();
        umap[key].push_back(make_pair(timestamp, value));
    }
    
    string get(string key, int timestamp) {
        if(umap.find(key) == umap.end())
            return "";
        int lo = 0;
        int hi = umap[key].size()-1;
        int mid;
        while(lo <= hi){
            mid = lo + (hi - lo) / 2;
            if(umap[key][mid].first == timestamp)
                return umap[key][mid].second;
            else if(umap[key][mid].first < timestamp){
                if(mid+1 < umap[key].size() && umap[key][mid+1].first > timestamp)
                    return umap[key][mid].second;
                if(mid == umap[key].size()-1)
                    return umap[key][mid].second;
                lo = mid + 1;
            }
            else
                hi = mid - 1;
        }
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
