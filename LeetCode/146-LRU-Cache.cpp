#include <list> 

class LRUCache {
private:
    int capacity;
    unordered_map<int, list<pair<int, int>>::iterator> umap;
    list<pair<int, int>> ls;
    
public:
    LRUCache(int cpcity) : capacity(cpcity), umap({}), ls ({}) { }
    
    int get(int key) {
        if(umap.find(key) == umap.end())
            return -1;
        int val = (*umap[key]).second;
        ls.erase(umap[key]);
        ls.push_front(make_pair(key, val));
        umap[key] = ls.begin();
        return val;
    }
    
    void put(int key, int val) {
        if(umap.find(key) == umap.end()){
            ls.push_front(make_pair(key, val));
            umap[key] = ls.begin();
            if(ls.size() == capacity+1){
                umap.erase(ls.back().first);
                ls.pop_back();
            }
        }
        else{
            ls.erase(umap[key]);
            ls.push_front(make_pair(key, val));
            umap[key] = ls.begin();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
