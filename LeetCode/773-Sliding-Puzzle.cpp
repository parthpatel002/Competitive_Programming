class Solution {
public:
    
    int hash(vector<vector<int>>& board){
        int mul = 1;
        int val = 0;
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 3; j++){
                val += (board[i][j] * mul);
                mul *= 6;
            }
        }
        return val;
    }
    
    vector<pair<int, int>> getNeighbors(int x, int y){
        vector<pair<int, int>> vec;
        int i, j;
        i = -1, j = 0;
        if(x+i >= 0 && x+i < 2 && y+j >= 0 && y+j < 3)
            vec.push_back(make_pair(i, j));
        i = 1, j = 0;
        if(x+i >= 0 && x+i < 2 && y+j >= 0 && y+j < 3)
            vec.push_back(make_pair(i, j));
        i = 0, j = -1;
        if(x+i >= 0 && x+i < 2 && y+j >= 0 && y+j < 3)
            vec.push_back(make_pair(i, j));
        i = 0, j = 1;
        if(x+i >= 0 && x+i < 2 && y+j >= 0 && y+j < 3)
            vec.push_back(make_pair(i, j));
        return vec;
    }
    
    vector<vector<int>> getNextState(vector<vector<int>>& board, int x1, int y1, int x2, int y2){
        vector<vector<int>> next (board);
        int temp = next[x1][y1];
        next[x1][y1] = next[x2][y2];
        next[x2][y2] = temp;
        return next;
    }
    
    bool isFinalState(vector<vector<int>>& board){
        bool flag = true;
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 3; j++){
                if(board[i][j] != (i*3+j+1)%6){
                    flag = false;
                    break;
                }
            }
            if(!flag)
                break;
        }
        return flag;
    }
    
    int slidingPuzzle(vector<vector<int>>& board) {
        if(isFinalState(board))
            return 0;
        int i, j;
        bool flag = false;
        for(i = 0; i < 2; i++){
            for(j = 0; j < 3; j++){
                if(board[i][j] == 0){
                    flag = true;
                    break;
                }
            }
            if(flag)
                break;
        }
        queue<pair<vector<vector<int>>, vector<int>>> q;
        unordered_set<int> uset;
        vector<int> vec;
        vec.push_back(i);
        vec.push_back(j);
        vec.push_back(0);
        q.push(make_pair(board, vec));
        uset.insert(hash(board));
        while(!q.empty()){
            pair<vector<vector<int>>, vector<int>> p = q.front();
            int x = p.second[0];
            int y = p.second[1];
            int cnt = p.second[2];
            q.pop();
            vector<pair<int, int>> neighbors = getNeighbors(x, y);
            for(pair<int, int> coords : neighbors){
                int x_ = coords.first + x;
                int y_ = coords.second + y;
                vector<vector<int>> nextState = getNextState(p.first, x, y, x_, y_);
                if(isFinalState(nextState))
                    return cnt+1;
                int nextHash = hash(nextState);
                if(uset.find(nextHash) == uset.end()){
                    vector<int> vec;
                    vec.push_back(x_);
                    vec.push_back(y_);
                    vec.push_back(cnt+1);
                    q.push(make_pair(nextState, vec));
                    uset.insert(nextHash);
                }
            }
        }
        return -1;
    }
};







