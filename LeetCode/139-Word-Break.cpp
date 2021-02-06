class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int N = s.size();
        vector<bool> dp (N, false);
        for(int i = 0; i < N; i++){
            if(!dp[i]){
                string subs = s.substr(0, i+1);
                for(int j = 0; j < wordDict.size(); j++){
                    if(wordDict[j].size() == i+1 && subs.find(wordDict[j], 0) != string::npos){
                        dp[i] = true;
                        break;
                    }
                }
            }
            if(dp[N-1])
                return true;
            if(!dp[i])
                continue;
            for(int j = i+1; j < N; j++){
                string subs = s.substr(i+1, j-i);
                for(int k = 0; k < wordDict.size(); k++){
                    if(wordDict[k].size() == j-i && subs.find(wordDict[k], 0) != string::npos){
                        dp[j] = true;
                        break;
                    }
                }
            }
            if(dp[N-1])
                return true;
        }
        return dp[N-1];
    }
};
