class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int M = matrix.size();
        int N = matrix[0].size();
        int H[M][N];
        int V[M][N];
        for(int i = 0; i < M; i++){
            for(int j = 0; j < N; j++){
                if(j == 0)
                    H[i][j] = (matrix[i][j] == '1')?1:0;
                else
                    H[i][j] = (matrix[i][j] == '1')?H[i][j-1]+1:0;
                if(i == 0)
                    V[i][j] = (matrix[i][j] == '1')?1:0;
                else
                    V[i][j] = (matrix[i][j] == '1')?V[i-1][j]+1:0;
            }
        }
        int maxi = 0;
        for(int i = M-1; i >= 0; i--){
            for(int j = N-1; j >= 0; j--){
                int sz = min(H[i][j], V[i][j]);
                if(sz == 0)
                    continue;
                while(sz > maxi){
                    bool flag = true;
                    for(int k = i - 1; k >= i - sz + 1; k--){
                        if(H[k][j] < sz){
                            flag = false;
                            break;
                        }
                    }
                    if(flag)
                        break;
                    sz--;
                }
                maxi = max(maxi, sz);
            }
        }
        return maxi*maxi;
    }
};
