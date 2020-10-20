class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        
        // Solution 1 (Slower and memory intensive)
        // Computing size of set union directly
        // int N = A.size();
        // unordered_map<int, unordered_set<int>> umap1;
        // unordered_map<int, unordered_set<int>> umap2;
        // for(int i = 1; i <= 6; i++){
        //     umap1[i] = unordered_set<int>();
        //     umap2[i] = unordered_set<int>();
        // }
        // for(int i = 0; i < N; i++){
        //     umap1[A[i]].insert(i);
        //     umap2[B[i]].insert(i);
        // }
        // for(int i = 1; i <= 6; i++){
        //     unordered_set<int> union_set (umap1[i]);
        //     union_set.insert(umap2[i].begin(), umap2[i].end());
        //     if (union_set.size() == N){
        //         return min(N-umap1[i].size(), N-umap2[i].size());
        //     }
        // }
        // return -1;
        
        // Solution 2 (Faster and lesser memory)
        // Computing size of set union as n(A U B) = n(A) + n(B) - n(A . B)
        // int N = A.size();
        // vector<int> cntA(6, 0), cntB(6, 0), cntS(6, 0);
        // for(int i = 0; i < N; i++){
        //     cntA[A[i]-1] += 1;
        //     cntB[B[i]-1] += 1;
        //     if (A[i]==B[i])
        //         cntS[A[i]-1] += 1;
        // }
        // for(int i = 0; i < 6; i++){
        //     if(cntA[i]+cntB[i]-cntS[i]==N)
        //         return min(N-cntA[i], N-cntB[i]);
        // }
        // return -1;
        
    }
};
