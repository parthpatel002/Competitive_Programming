class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
        int n1 = 0, s1 = 1;
        for (int i = 1; i < A.size(); ++i) {
            int n2 = 2001, s2 = 2001; // Since A[i], B[i] are integer values in the range [0, 2000].
            if (A[i-1] < A[i] && B[i-1] < B[i]) {
                n2 = min(n2, n1);
                s2 = min(s2, s1 + 1);
            }
            if (A[i-1] < B[i] && B[i-1] < A[i]) {
                n2 = min(n2, s1);
                s2 = min(s2, n1 + 1);
            }
            n1 = n2;
            s1 = s2;
        }
        return min(n1, s1);
    }
};
