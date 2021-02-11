struct comparator{
	bool operator() (const pair<int, vector<int>>& p1, const pair<int, vector<int>>& p2){
		return p1.first > p2.first;
	}
};

string hash_(vector<int>& vec){
        string res = std::to_string(vec[0]);
        for(int i = 1; i < vec.size(); i++) 
            res += ',' + std::to_string(vec[i]);
        return res;
}

class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        
        // Solution 1: Using unordered set for strings: Slower (probably because hash function is expensive)
        // int M = mat.size();
        // int N = mat[0].size();
        // int s = 0;
        // for(int i = 0; i < M; i++)
        //     s += mat[i][0];
        // vector<int> v(M, 0);
        // priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, comparator> pq;
        // pq.push(make_pair(s, v));
        // unordered_set<string> uset;
        // uset.insert(hash_(v));
        // int cnt = 0;
        // while(!pq.empty()){
        //     pair<int, vector<int>> p = pq.top();
        //     pq.pop();
        //     cnt++;
        //     int sum = p.first;
        //     vector<int> vec (p.second);
        //     if(cnt == k)
        //         return sum;
        //     for(int i = 0; i < M; i++){
        //         int idx = vec[i];
        //         if(idx == N-1)
        //             continue;
        //         int sum_ = sum - mat[i][idx] + mat[i][idx+1];
        //         vector<int> vec_ (vec);
        //         vec_[i]++;
        //         string hash_str = hash_(vec_);
        //         if(uset.find(hash_str) == uset.end()){
        //             pq.push(make_pair(sum_, vec_));
        //             uset.insert(hash_str);
        //         }
        //     }
        // }
        // return 0; // Satisfy Compiler
        
        // Solution 2: Using ordered set for strings: Slowest (probably because hash function is expensive) 
        // int M = mat.size();
        // int N = mat[0].size();
        // int s = 0;
        // for(int i = 0; i < M; i++)
        //     s += mat[i][0];
        // vector<int> v(M, 0);
        // priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, comparator> pq;
        // pq.push(make_pair(s, v));
        // set<string> set;
        // set.insert(hash_(v));
        // int cnt = 0;
        // while(!pq.empty()){
        //     pair<int, vector<int>> p = pq.top();
        //     pq.pop();
        //     cnt++;
        //     int sum = p.first;
        //     vector<int> vec (p.second);
        //     if(cnt == k)
        //         return sum;
        //     for(int i = 0; i < M; i++){
        //         int idx = vec[i];
        //         if(idx == N-1)
        //             continue;
        //         int sum_ = sum - mat[i][idx] + mat[i][idx+1];
        //         vector<int> vec_ (vec);
        //         vec_[i]++;
        //         string hash_str = hash_(vec_);
        //         if(set.find(hash_str) == set.end()){
        //             pq.push(make_pair(sum_, vec_));
        //             set.insert(hash_str);
        //         }
        //     }
        // }
        // return 0; // Satisfy Compiler
        
        // Solution 3: Using ordered set for vectors: Faster 
        int M = mat.size();
        int N = mat[0].size();
        int s = 0;
        for(int i = 0; i < M; i++)
            s += mat[i][0];
        vector<int> v(M, 0);
        priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, comparator> pq;
        pq.push(make_pair(s, v));
        set<vector<int>> set;
        set.insert(v);
        int cnt = 0;
        while(!pq.empty()){
            pair<int, vector<int>> p = pq.top();
            pq.pop();
            cnt++;
            int sum = p.first;
            vector<int> vec (p.second);
            if(cnt == k)
                return sum;
            for(int i = 0; i < M; i++){
                int idx = vec[i];
                if(idx == N-1)
                    continue;
                int sum_ = sum - mat[i][idx] + mat[i][idx+1];
                vector<int> vec_ (vec);
                vec_[i]++;
                if(set.find(vec_) == set.end()){
                    pq.push(make_pair(sum_, vec_));
                    set.insert(vec_);
                }
            }
        }
        return 0; // Satisfy Compiler
        
    }
};
