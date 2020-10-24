#include <list> 

// Solution 1 - 1 Unordered Map and 1 List
// class LRUCache {
// private:
//     int capacity;
//     unordered_map<int, list<pair<int, int>>::iterator> umap;
//     list<pair<int, int>> ls;
    
// public:
//     LRUCache(int cpcity) : capacity(cpcity), umap({}), ls ({}) { }
    
//     int get(int key) {
//         if(umap.find(key) == umap.end())
//             return -1;
//         int val = (*umap[key]).second;
//         ls.erase(umap[key]);
//         ls.push_front(make_pair(key, val));
//         umap[key] = ls.begin();
//         return val;
//     }
    
//     void put(int key, int val) {
//         if(umap.find(key) == umap.end()){
//             ls.push_front(make_pair(key, val));
//             umap[key] = ls.begin();
//             if(ls.size() == capacity+1){
//                 umap.erase(ls.back().first);
//                 ls.pop_back();
//             }
//         }
//         else{
//             ls.erase(umap[key]);
//             ls.push_front(make_pair(key, val));
//             umap[key] = ls.begin();
//         }
//     }
// };

// Solution 2 - 2 Unordered Maps and 1 List
class LRUCache {
private:
    int capacity;
    unordered_map<int, int> umap1;
    unordered_map<int, list<int>::iterator> umap2;
    list<int> ls;
    
public:
    LRUCache(int cpcity) : capacity(cpcity), umap1({}), umap2({}), ls ({}) { }
    
    int get(int key) {
        if(umap1.find(key) == umap1.end())
            return -1;
        ls.erase(umap2[key]);
        ls.push_front(key);
        umap2[key] = ls.begin();
        return umap1[key];
    }
    
    void put(int key, int val) {
        if(umap1.find(key) == umap1.end()){
            umap1[key] = val;
            ls.push_front(key);
            umap2[key] = ls.begin();
            if(ls.size() == capacity+1){
                int k = ls.back();
                umap1.erase(k);
                umap2.erase(k);
                ls.pop_back();
            }
        }
        else{
            umap1[key] = val;
            ls.erase(umap2[key]);
            ls.push_front(key);
            umap2[key] = ls.begin();
        }
    }
};


/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
