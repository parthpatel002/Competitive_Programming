using namespace std;

class D {
public:
    
    double maxi, mini;
    string maxs, mins;
    
    D() : maxi(-1.0), mini(-1.0), maxs(""), mins("") {}
    
    D(double mx, double mn, string mxs, string mns) : maxi(mx), mini(mn), maxs(mxs), mins(mns) {}
    
};

class Solution {
public:
    
    D recurse1(vector<int>& nums, int st, int end, string str){
        if(st == end){
            double maxi = (double) nums[st], mini = (double) nums[st];
            string maxs = to_string(nums[st]), mins = to_string(nums[st]);
            return D (maxi, mini, maxs, mins);
        }
        if(str == "max"){
            D d1, d2;
            double maxVal = -1.0;
            string maxString = "";
            for(int i = st; i < end; i++){
                d1 = recurse1(nums, st, i, "max");
                d2 = recurse1(nums, i+1, end, "min");
                if(d1.maxi/d2.mini > maxVal){
                    maxVal = d1.maxi/d2.mini;
                    if(d2.mins.find("/") == string::npos)
                        maxString = d1.maxs + "/" + d2.mins;
                    else
                        maxString = d1.maxs + "/(" + d2.mins + ")";
                }
            }
            return D (maxVal, 0.0, maxString, "");
        }
        else{
            D d1, d2;
            bool flag = true;
            double minVal;
            string minString;
            for(int i = st; i < end; i++){
                d1 = recurse1(nums, st, i, "min");
                d2 = recurse1(nums, i+1, end, "max");
                if(flag){
                    minVal = d1.mini/d2.maxi;
                    if(d2.maxs.find("/") == string::npos)
                        minString = d1.mins + "/" + d2.maxs;
                    else
                        minString = d1.mins + "/(" + d2.maxs +")";
                    flag = false;
                }
                else if(d1.mini/d2.maxi < minVal){
                    minVal = d1.mini/d2.maxi;
                    if(d2.maxs.find("/") == string::npos)
                        minString = d1.mins + "/" + d2.maxs;
                    else
                        minString = d1.mins + "/(" + d2.maxs +")";
                }
            }
            return D (0.0, minVal, "", minString);
        }
    }
    
    void recurse2(vector<int>& nums, int st, int end, string str, vector<vector<D>>& dp){
        if(str=="max" && dp[st][end].maxi != -1.0)
            return;
        else if(str=="min" && dp[st][end].mini != -1.0)
            return;
        if(st==end){
            dp[st][st].maxi = (double) nums[st];
            dp[st][st].mini = (double) nums[st];
            dp[st][st].maxs = to_string(nums[st]);
            dp[st][st].mins = to_string(nums[st]);
            return;
        }
        if(str=="max"){
            double maxVal = -1.0;
            string maxString = "";
            for(int i = st; i < end; i++){
                recurse2(nums, st, i, "max", dp);
                recurse2(nums, i+1, end, "min", dp);
                if(dp[st][i].maxi/dp[i+1][end].mini > maxVal){
                    maxVal = dp[st][i].maxi/dp[i+1][end].mini;
                    if(dp[i+1][end].mins.find('/') == string::npos)
                        maxString = dp[st][i].maxs + "/" + dp[i+1][end].mins;
                    else
                        maxString = dp[st][i].maxs + "/(" + dp[i+1][end].mins + ")";
                }
            }
            dp[st][end].maxi = maxVal;
            dp[st][end].maxs = maxString;
        }
        else{
            bool flag = true;
            double minVal;
            string minString;
            for(int i = st; i < end; i++){
                recurse2(nums, st, i, "min", dp);
                recurse2(nums, i+1, end, "max", dp);
                if(flag){
                    minVal = dp[st][i].mini/dp[i+1][end].maxi;
                    if(dp[i+1][end].maxs.find('/') == string::npos)
                        minString = dp[st][i].mins + "/" + dp[i+1][end].maxs;
                    else
                        minString = dp[st][i].mins + "/(" + dp[i+1][end].maxs + ")";
                    flag = false;
                }
                else if(dp[st][i].mini/dp[i+1][end].maxi < minVal){
                    minVal = dp[st][i].mini/dp[i+1][end].maxi;
                    if(dp[i+1][end].maxs.find('/') == string::npos)
                        minString = dp[st][i].mins + "/" + dp[i+1][end].maxs;
                    else
                        minString = dp[st][i].mins + "/(" + dp[i+1][end].maxs + ")";
                }
            }
            dp[st][end].mini = minVal;
            dp[st][end].mins = minString;
        }
    }
    
    string optimalDivision(vector<int>& nums) {
        
        if(nums.size() == 1)
            return to_string(nums[0]);
        
        // Solution 1 - Brute Force
        // D d = recurse1(nums, 0, nums.size()-1, "max");
        // return d.maxs;        
        
        // Solution 2 - DP (Memoization)
        int N = nums.size();
        vector<vector<D>> dp (N, vector<D>(N, D()));
        recurse2(nums, 0, N-1, "max", dp);
        return dp[0][N-1].maxs;
        
    }
    
};
