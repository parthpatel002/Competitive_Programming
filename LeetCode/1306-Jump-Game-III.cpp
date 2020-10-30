class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        
        if (arr.size() == 1){
            if (arr[0] == 0)
                return true;
            return false;
        }
        
        if (arr[start] == 0)
            return true;
        
        bool flag = true;
        for (int i = 0; i < arr.size(); i++)
            if (arr[i] == 0){
                flag = false;
                break;
            }
        if (flag)
            return false;
        
        // Solution 1 - BFS
        // vector<bool> visited (arr.size(), false);
        // queue<int> q;
        // q.push(start);
        // visited[start] = true;
        // while(!q.empty()){
        //     int idx = q.front();
        //     q.pop();
        //     if(idx+arr[idx]>=0 && idx+arr[idx]<arr.size() && !visited[idx+arr[idx]]){
        //         if(arr[idx+arr[idx]] == 0)
        //             return true;
        //         visited[idx+arr[idx]] = true;
        //         q.push(idx+arr[idx]);
        //     }
        //     if(idx-arr[idx]>=0 && idx-arr[idx]<arr.size() && !visited[idx-arr[idx]]){
        //         if(arr[idx-arr[idx]] == 0)
        //             return true;
        //         visited[idx-arr[idx]] = true;
        //         q.push(idx-arr[idx]);
        //     }
        // }
        // return false;
        
        // Solution 2 - DFS
        vector<bool> visited (arr.size(), false);
        stack<int> st;
        st.push(start);
        while(!st.empty()){
            int idx = st.top();
            st.pop();
            visited[idx] = true;
            if(idx+arr[idx]>=0 && idx+arr[idx]<arr.size() && !visited[idx+arr[idx]]){
                if(arr[idx+arr[idx]] == 0)
                    return true;
                st.push(idx+arr[idx]);
            }
            if(idx-arr[idx]>=0 && idx-arr[idx]<arr.size() && !visited[idx-arr[idx]]){
                if(arr[idx-arr[idx]] == 0)
                    return true;
                st.push(idx-arr[idx]);
            }
        }
        return false;
        
    }
};
