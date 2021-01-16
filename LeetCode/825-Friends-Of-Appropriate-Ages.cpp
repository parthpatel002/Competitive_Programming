#include <bits/stdc++.h>

class Solution {
public:
    int numFriendRequests(vector<int>& people) {
        
        int N = people.size();
        if(N == 1)
            return 0;
        vector<int> count (121, 0);
        for(int i = 0; i < N; i++){
            count[people[i]] += 1;
        }
        int ans = 0;
        for (int ageA = 0; ageA <= 120; ageA++) {
            int countA = count[ageA];
            for (int ageB = 0; ageB <= 120; ageB++) {
                int countB = count[ageB];
                if (ageA * 0.5 + 7 >= ageB) continue;
                if (ageA < ageB) continue;
                if (ageA < 100 && 100 < ageB) continue;
                ans += countA * countB;
                if (ageA == ageB) ans -= countA;
            }
        }
        return ans;
        
    }
};
