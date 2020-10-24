class Solution {
public:
    int numTimesAllBlue(vector<int>& light) {
        
        // Solution 1 - O(N) Time, O(N) Space
        // if (light.size() == 1)
        //     return 1;
        // int mini = 0;
        // vector<bool> vec(light.size()+2, false);
        // int cnt = 0;
        // for(int i = 0; i < light.size(); i++){
        //     vec[light[i]] = true;
        //     while(vec[mini+1])
        //         mini += 1;
        //     if(mini == i+1)
        //         cnt += 1;
        // }
        // return cnt;
        
        // Solution 2 - O(N) Time, O(1) Space
        // if (light.size() == 1)
        //     return 1;
        // int cnt = 0, maxi = 0;
        // for(int i = 0; i < light.size(); i++)
        // {
        //     maxi = max(maxi,light[i]);
        //     if(maxi == i+1) 
        //         cnt++;
        // }
        // return cnt;
        
    }
};
