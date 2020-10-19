#include <iostream>
#include <string>

using namespace std;

int main(){
    int T;
    string temp;
    cin>>T;
    getline(cin, temp);
    while(T>0){
        int N;
        string str;
        cin>>N;
        getline(cin, temp);
        getline(cin, str);
        if (str.substr(0, N-1).find(str.substr(N-1, 1)) != string::npos)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
        T--;
    }
}
