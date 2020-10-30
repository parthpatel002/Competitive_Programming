#include <bits/stdc++.h> 

class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        bool oneBreaksTwo(true), twoBreaksOne(true);
        for(int i = 0; i < s1.length(); i++){
            if(s1[i] < s2[i]){
                oneBreaksTwo = false;
            }
            if(s2[i] < s1[i]){
                twoBreaksOne = false;
            }
            if(!(oneBreaksTwo || twoBreaksOne))
                return false;
        }
        return oneBreaksTwo || twoBreaksOne; 
    }
};
