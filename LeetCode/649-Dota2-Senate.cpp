class Solution {
public:
    string predictPartyVictory(string senate) {
        int N = senate.size();
        if(N == 1){
            if(senate[0] == 'R')
                return "Radiant";
            else 
                return "Dire";
        }
        int cntR = 0;
        int cntD = 0;
        for(int i = 0; i < N; i++){
            if(senate[i] == 'R')
                cntR++;
            else
                cntD++;
        }
        if(cntR == 0)
            return "Dire";
        else if(cntD == 0)
            return "Radiant";
        vector<bool> flag (N, false);
        while(cntR != 0 && cntD != 0){
            for(int i = 0; i < N; i++){
                if(flag[i])
                    continue;
                if(senate[i] == 'R'){
                    int j = (i+1)%N;
                    while(j != i){
                        if(senate[j] == 'D' && !flag[j]){
                            flag[j] = true;
                            cntD--;
                            if(cntD == 0)
                                return "Radiant";
                            break;
                        }
                        j = (j+1)%N;
                    }
                }
                else{
                    int j = (i+1)%N;
                    while(j != i){
                        if(senate[j] == 'R' && !flag[j]){
                            flag[j] = true;
                            cntR--;
                            if(cntR == 0)
                                return "Dire";
                            break;
                        }
                        j = (j+1)%N;
                    }
                }
            }
        }
        return ""; // Make compiler happy
    }
};
