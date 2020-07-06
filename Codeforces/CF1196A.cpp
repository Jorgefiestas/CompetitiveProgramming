#include <bits/stdc++.h>
using namespace std;
long long T, t, s;

int main(){
    cin>>T;
    while(T--){
        s = 0;
        for(int i = 0; i < 3; i++){
            cin>>t;
            s += t;
        }
        cout<<s/2<<endl;
    }
    return 0;
}
