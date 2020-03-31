#include <bits/stdc++.h>
using namespace std;
int T, n;
string str;

bool can(){
    cin>>n>>str;
    for(int i = n-11; i>=0; i--){
        if(str[i] == '8') return true;
    }
    return false;
}

int main(){
    cin>>T;
    while(T--){
        if(can()) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
