class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int M = matrix.size();
        int N = matrix[0].size();
        vector<vector<short>> H (M, vector<short>(N, 0));
        vector<vector<short>> V (M, vector<short>(N, 0));
        for(int i = 0; i < M; i++){
            for(int j = 0; j < N; j++){
                H[i][j] = ((j == 0)?(matrix[i][j]==1?1:0):(matrix[i][j]==1?H[i][j-1]+1:0));
                V[i][j] = ((i == 0)?(matrix[i][j]==1?1:0):(matrix[i][j]==1?V[i-1][j]+1:0));
            }
        }
        int cnt = 0;
        for(int i = M-1; i >= 0; i--){
            for(int j = N-1; j >= 0; j--){
                if(matrix[i][j] == 0)
                    continue;
                cnt++;
                int min_sz = min(H[i][j], V[i][j]);
                while(min_sz > 1){
                    bool flag = true;
                    for(int i_tmp = i-1; i_tmp > i-min_sz; i_tmp--){
                        if(H[i_tmp][j] < min_sz){
                            flag = false;
                            break;
                        }
                    }
                    if(flag){
                        cnt += (min_sz-1);
                        break;
                    }
                    min_sz--;
                }
            }
        }
        return cnt;
    }
};
