class Solution {
public:
    
    int getMin(int x, int y) { 
        return (x < y) ? x : y; 
    }

    int largest1BorderedSquare(vector<vector<int>>& mat) {
    
        int max = 0;
        int M = mat.size();
        int N = mat[0].size();

        int hor[M][N], ver[M][N];
        
        for (int i = 0; i < M; i++){
            for (int j = 0; j < N; j++){
                if (mat[i][j] == 0)
                    ver[i][j] = hor[i][j] = 0;
                else{
                    hor[i][j] = (j == 0) ? 1 : hor[i][j - 1] + 1;
                    ver[i][j] = (i == 0) ? 1 : ver[i - 1][j] + 1;
                    max = 1;
                }
            }
        }
    
        for (int i = M - 1; i >= 1; i--){
            for (int j = N - 1; j >= 1; j--){
                int small = getMin(hor[i][j], ver[i][j]);
                while (small > max){
                    if (ver[i][j - small + 1] >= small && hor[i - small + 1][j] >= small){
                        max = small;
                    }
                    small--;
                }
            }
        }
        return max*max;
    }
};
