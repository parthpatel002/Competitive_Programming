/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class UnionFind{
private:
    vector<int> arr;
    int cnt;
    
public:
    UnionFind(int N) : arr(vector(N, 0)), cnt(N) {
        for(int i = 0; i < N; i++)
            arr[i] = i;
    }
    
    int count(){
        return cnt;
    }

    int find(int i){
        while(i != arr[i]){
            arr[i] = arr[arr[i]];
            i = arr[i];
        }
        return i;
    }
    
    void union_(int p, int q){
        int rp = find(p);
        int rq = find(q);
        if (rp == rq)
            return;
        arr[rp] = rq;
        cnt--;
    }
    
    bool connected(int p, int q){
        return find(p) == find(q);
    }
};

class Solution {
public:
    int numComponents(ListNode* head, vector<int>& G) {
        
        // Solution 1 (UnionFind + UnorderedMap)
        // unordered_map<int, int> umap;
        // for(int idx = 0; idx < G.size(); idx++)
        //     umap[G[idx]] = idx;
        // UnionFind uf = UnionFind(G.size());
        // while(head->next != NULL){
        //     if(umap.find(head->val) != umap.end() && umap.find(head->next->val) != umap.end())
        //         uf.union_(umap[head->val], umap[head->next->val]);
        //     head = head->next;
        // }
        // return uf.count();
        
        // Solution 2 (UnorderedSet - Because LL elements are unique and G is subset of LL)
        unordered_set<int> uset;
        for(int idx = 0; idx < G.size(); idx++)
            uset.insert(G[idx]);
        int cnt = 0;
        while(1){
            if(head==NULL)
                break;
            if(uset.find(head->val)==uset.end()){
                head = head->next;
                continue;
            }
            while((head->next!=NULL) && (uset.find(head->val)!=uset.end()&&uset.find(head->next->val)!=uset.end())){
                head = head->next;
            }
            cnt++;
            if(head->next==NULL)
                break;
            head = head->next;
        }
        return cnt;
        
    }
};







