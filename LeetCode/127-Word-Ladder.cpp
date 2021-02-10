class Solution {
public:
    
    int diff(string& a, string& b){
        int cnt = 0;
        for(int i = 0; i < a.size(); i++){
            if(a[i] != b[i])
                cnt++;
        }
        return cnt;
    }
    
    vector<string> getNeighbors(string str, vector<string>& list){
        vector<string> output;
        for(string v : list){
            if(diff(str, v) == 1)
                output.push_back(v);
        }
        return output;
    }
    
    int ladderLength(string begin, string end, vector<string>& list) {
        bool flag = true;
        for(string str : list){
            if(str.find(end, 0) != string::npos){
                flag = false;
                break;
            }
        }
        if(flag)
            return 0;
        queue<pair<string, int>> q;
        unordered_set<string> uset;
        q.push(make_pair(begin, 1));
        uset.insert(begin);
        while(!q.empty()){
            string str = q.front().first;
            int cnt = q.front().second;
            q.pop();
            vector<string> nlist = getNeighbors(str, list);
            for(string n : nlist){
                if(n.find(end, 0) != string::npos)
                    return cnt+1;
                if(uset.find(n) != uset.end())
                    continue;
                q.push(make_pair(n, cnt+1));
                uset.insert(n);
            }
        }
        return 0;
    }
    
};
