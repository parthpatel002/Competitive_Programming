class Solution {
public:
    
    pair<int, int> getRowAndCol(int i, int N){
        i--;
        int row = N - (i/N) - 1;
        int col = ((i/N) % 2 == 0)?(i % N):(N - (i%N) -1);
        return make_pair(row, col);
    }
    
    int snakesAndLadders(vector<vector<int>>& board) {
        int N = board.size();
        bool visited[N][N];
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                visited[i][j] = false;
        queue<pair<int, int>> q;
        q.push(make_pair(1, 0));
        pair<int, int> p = getRowAndCol(1, N);
        visited[p.first][p.second] = true;
        while(!q.empty()){
            int i = q.front().first;
            int cnt = q.front().second;
            q.pop();
            if(i == N*N)
                return cnt;
            for(int j = i+1; j <= i+6 && j <= N*N; j++){
                p = getRowAndCol(j, N);
                int val = board[p.first][p.second];
                int dest = (val==-1)?j:val;
                if(dest == N*N)
                    return cnt+1;
                p = getRowAndCol(dest, N);
                if(!visited[p.first][p.second]){
                    visited[p.first][p.second] = true;
                    q.push(make_pair(dest, cnt+1));
                }
            }
        }
        return -1;
    }
};
