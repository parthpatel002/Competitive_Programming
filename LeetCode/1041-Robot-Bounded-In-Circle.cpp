class Solution {
public:
    bool isRobotBounded(string instructions) {
        
        // Solution 1
        int x = 0, y = 0;
        int dir = 0; // 0-N, 1-E, 2-S, 3-W
        for(int j = 0; j < 4; j++){
            for(char ch: instructions){
                if(ch == 'G'){
                    if(dir == 0)
                        y++;
                    else if(dir == 1)
                        x++;
                    else if(dir == 2)
                        y--;
                    else if(dir == 3)
                        x--;
                }
                else if(ch == 'L'){
                    dir = (dir == 0) ? 3 : (dir-1);
                }
                else if(ch == 'R'){
                    dir = (dir == 3) ? 0 : (dir+1);
                }
            }
            if(x == 0 && y == 0)
                return true;
        }
        return false;
    
        // Solution 2
        int x = 0, y = 0;
        int dir = 0; // 0-N, 1-E, 2-S, 3-W
        for(char ch: instructions){
            if(ch == 'G'){
                if(dir == 0)
                    y++;
                else if(dir == 1)
                    x++;
                else if(dir == 2)
                    y--;
                else if(dir == 3)
                    x--;
            }
            else if(ch == 'L')
                dir = (dir == 0) ? 3 : (dir-1);
            else if(ch == 'R')
                dir = (dir == 3) ? 0 : (dir+1);
        }
        if (x == 0 && y == 0)
            return true;
        if (dir == 0)
            return false;
        return true;
        
    }
};
