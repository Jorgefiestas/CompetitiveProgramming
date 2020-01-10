#include <bits/stdc++.h>
using namespace std;
int n;
string str, str2;

int main(){
    cin>>n>>str;

    if(str == ""){
        cout<<endl;
        return 0;
    }

    str2 += str[0];
    
    for(int i = 1; i<n; i++){
        if(str2.size()%2 == 1 && str[i] == str2[str2.size()-1]) continue;
        str2 += str[i];
    }
    if(str2.size()%2) str2.pop_back();
    cout<<str.size() - str2.size()<<endl<<str2<<endl;
    return 0;
}
