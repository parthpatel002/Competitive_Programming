class Solution {
public:
    bool buddyStrings(string A, string B) {
        if (A.size() != B.size())
            return false;
        int N = A.size();
        if (N <= 1)
            return false;
        int cnt = 0;
        vector<int> idx;
        for(int i = 0; i < N; i++){
            if (A[i] != B[i]){
                cnt++;
                idx.push_back(i);
            }
        }
        if (cnt == 1 || cnt >= 3)
            return false;
        if (cnt == 0){
            unordered_set<char> uset;
            for(int i = 0; i < N; i++){
                if (uset.find(A[i]) != uset.end())
                    return true;
                uset.insert(A[i]);
            }
            return false;
        }
        if (A[idx[0]] == B[idx[1]] && A[idx[1]] == B[idx[0]])
            return true;
        return false;
    }
};
