#include <iostream>
#include <vector> 
#include <string>

#define M 5 // M can be any no. in [1, 10^5-1] (from constraints mentioned in the problem).

// Given problem can be reduced to assigning a number from {M, M+1} to each node s.t. no two adjacent
// nodes are assigned the same number (this is always possible because it is a tree and has no cycles).

using namespace std;

void recurse(int root, vector<vector<int>>& mat, vector<int>& assign, int val){
    assign[root] = val;
    for(int i = 0; i < mat[root].size(); i++){
        int u = mat[root][i];
        if (assign[u] == -1){
            if(val == M)
                recurse(u, mat, assign, M+1);
            else
                recurse(u, mat, assign, M);
        }
    }
}

int main(){
    int T;
    string temp;
    cin>>T;
    getline(cin, temp);
    while(T>0){
        int N;
        cin>>N;
        getline(cin, temp);
        vector<vector<int>> mat(N, vector<int>());
        for(int i = 0; i < N-1; i++){
            int u, v;
            cin>>u>>v;
            getline(cin, temp);
            mat[u-1].push_back(v-1);
            mat[v-1].push_back(u-1);
        }
        vector<int> assign(N, -1);
        recurse(0, mat, assign, M);        
        for(int i = 0; i < N; i++)
            cout<<assign[i]<<" ";
        cout<<endl;
        T--;
    }
}
