class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        int cntX = 0;
        int cntO = 0;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(board[i][j] == 'X')
                    cntX++;
                if(board[i][j] == 'O')
                    cntO++;
            }
        }
        if(cntO > cntX || cntX > cntO+1)
            return false;
        int winX = 0;
        int winO = 0;
        for(int i = 0; i < 3; i++){
            if(board[i][0] == 'X' && board[i][1] == 'X' && board[i][2] == 'X')
                winX++;
            if(board[i][0] == 'O' && board[i][1] == 'O' && board[i][2] == 'O')
                winO++;
        }
        for(int i = 0; i < 3; i++){
            if(board[0][i] == 'X' && board[1][i] == 'X' && board[2][i] == 'X')
                winX++;
            if(board[0][i] == 'O' && board[1][i] == 'O' && board[2][i] == 'O')
                winO++;
        }
        if(board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X'){
            winX++;
        }
        if(board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O'){
            winO++;
        }
        if(board[2][0] == 'X' && board[1][1] == 'X' && board[0][2] == 'X'){
            winX++;
        }
        if(board[2][0] == 'O' && board[1][1] == 'O' && board[0][2] == 'O'){
            winO++;
        }
        if(winO > 1)
            return false;
        if(winX == 1 && winO == 1)
            return false;
        if(winX > 0 && cntO >= cntX)
            return false;
        if(winO == 1 && cntX > cntO)
            return false;
        return true;
    }
};
