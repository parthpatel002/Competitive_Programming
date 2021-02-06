class Solution {
public:
    
    bool isCyclic(int u, vector<vector<int>>& graph, vector<bool>& visited, vector<bool>& recstack, stack<int>& st){
        visited[u] = true;
        recstack[u] = true;
        for(int v : graph[u]){
            if(recstack[v])
                return true;
            else if(!visited[v] && isCyclic(v, graph, visited, recstack, st))
                return true;
        }
        recstack[u] = false;
        st.push(u);
        return false;
    }
    
    vector<int> findOrder(int n, vector<vector<int>>& prereqs) {
        if(n == 1)
            return vector<int> (1, 0);
        vector<vector<int>> graph (n, vector<int>());
        for(int i = 0; i < prereqs.size(); i++){
            int u = prereqs[i][1];
            int v = prereqs[i][0];
            if(u == v)
                return vector<int>();
            graph[u].push_back(v);
        }
        vector<bool> visited (n, false);
        vector<bool> recstack(n, false);
        stack<int> st;
        for(int i = 0; i < n; i++){
            if(!visited[i] && isCyclic(i, graph, visited, recstack, st))
                return vector<int>();
        }
        vector<int> vec;
        while(!st.empty()){
            vec.push_back(st.top());
            st.pop();
        }
        return vec;
    }
};

