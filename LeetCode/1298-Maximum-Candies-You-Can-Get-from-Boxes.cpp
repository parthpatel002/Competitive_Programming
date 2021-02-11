class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int N = status.size();
        vector<bool> visited(N, false); // Whether we can reach a box or not
        vector<bool> hasKey(N, false); // Whether we have a key for a box or not
        vector<bool> used(N, false); // whether we have counted candies from a box or not
        int cnt = 0;
        queue<int> q;
        for(int i = 0; i < initialBoxes.size(); i++){
            int box = initialBoxes[i];
            visited[box] = true;
            if(status[box] == 1){
                cnt += candies[box];
                used[box] = true;
                q.push(box);
            }
        }
        while(!q.empty()){
            int box = q.front();
            q.pop();
            for(int b : containedBoxes[box]){
                visited[b] = true;
                if((status[b] == 1 && !used[b]) || (hasKey[b] && !used[b])){
                    cnt += candies[b];
                    used[b] = true;
                    q.push(b);
                }
            }
            for(int k : keys[box]){
                hasKey[k] = true;
                if(visited[k] && !used[k]){
                    cnt += candies[k];
                    used[k] = true;
                    q.push(k);
                }
            }
        }
        return cnt;
    }
};
