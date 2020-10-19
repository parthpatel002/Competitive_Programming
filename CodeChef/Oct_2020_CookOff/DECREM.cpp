#include <iostream>
#include <string>

using namespace std;

// [L, R] includes R-L+1 numbers. So, for each no. in [L, R] to have distinct modulo, module for L
// be R-L. But modulo for L can be at most L-1. So, answer will be -1 if R-L > L-1. Answer is possible 
// if R-L <= L-1 i.e. L >= (R+1)/2 ==> Reqd. N must be equal to R. 

int main(){
    int T;
    string temp;
    cin>>T;
    getline(cin, temp);
    while(T>0){
        int L, R;
        cin>>L>>R;
        getline(cin, temp);
        if (R+1 > 2*L)
            cout<<-1<<endl;
        else
            cout<<R<<endl;
        T--;
    }
}
