class Solution {
public:
    string orderlyQueue(string S, int K) {
        int N = S.size();
        if(K == 1){
            string ans = S;
            for(int i = 0; i < N-1; i++){
                string str = S.substr(i+1) + S.substr(0, i+1);
                if(str < ans)
                    ans = str;
            }
            return ans;
        }
        else{
            // Claim: K >= 2 allows us to swap any two indices of the string w/o changing the rest of the string. 
            // So, we can return the smallest permutation of the string as the answer (i.e. we can transform original
            // string to its smallest permutation by the idea of selection sort).
            sort(S.begin(), S.end());
            return S;
        }
    }
};
