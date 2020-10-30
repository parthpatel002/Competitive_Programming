class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        
        // Solution 1 [O(M*N) time, O(M+N) space]
        // int M = grid.size();
        // int N = grid[0].size();
        // unordered_map<int, int> rows;
        // unordered_map<int, int> cols;
        // for(int i = 0; i < M; i++){
        //     for(int j = 0; j < N; j++){
        //         if(grid[i][j] == 1){
        //             rows[i] += 1;
        //             cols[j] += 1;
        //         }
        //     }
        // }
        // int cnt = 0;
        // for(int i = 0; i < M; i++){
        //     for(int j = 0; j < N; j++){
        //         if(grid[i][j] == 1){
        //             if(rows[i] > 1 || cols[j] > 1)
        //                 cnt++;
        //         }
        //     }
        // }
        // return cnt;
        
        // Solution 2 [O(M*N) time, O(1) space - modifying grid in-place]
        int M = grid.size();
        int N = grid[0].size();
        int retVal = 0;
        for(int i = 0; i < M; i++){
            int cnt = 0;
            for(int j = 0; j < N; j++){
                if(grid[i][j] == 1)
                    cnt++;
            }
            if(cnt > 1){
                retVal += cnt;
                for(int j = 0; j < N; j++)
                    grid[i][j] *= -1;
            }
        }
        for(int j = 0; j < N; j++){
            int cnt = 0;
            int dnt = 0;
            for(int i = 0; i < M; i++){
                if(grid[i][j] != 0)
                    cnt++;
                if (grid[i][j] == -1)
                    dnt++;
            }
            if(cnt > 1)
                retVal += (cnt-dnt);
        }
        return retVal;
        
    }
};
