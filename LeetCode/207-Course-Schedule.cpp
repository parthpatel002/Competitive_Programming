class Solution {
public:
    
    bool isCyclic(int u, vector<vector<int>>& graph, vector<bool>& visited, vector<bool>& recstack){
        visited[u] = true;
        recstack[u] = true;
        for(int v : graph[u]){
            if(recstack[v])
                return true;
            else if(!visited[v] && isCyclic(v, graph, visited, recstack))
                return true;
        }
        recstack[u] = false;
        return false;
    }
    
    bool canFinish(int n, vector<vector<int>>& prereqs) {
        vector<vector<int>> graph (n, vector<int>());
        for(int i = 0; i < prereqs.size(); i++){
            int u = prereqs[i][1];
            int v = prereqs[i][0];
            if(u == v)
                return false;
            graph[u].push_back(v);
        }
        vector<bool> visited (n, false);
        vector<bool> recstack (n, false);
        for(int i = 0; i < n; i++){
            if(!visited[i] && isCyclic(i, graph, visited, recstack))
                return false;
        }
        return true;
    }
};
