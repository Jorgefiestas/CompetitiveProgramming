#include <bits/stdc++.h>
using namespace std;

int n, zs, tz;
string str;

int main(){
    cin>>n>>str;

    for(char x : str)
        if(x == '0') zs++;

    if(n - zs != zs){
        cout<<1<<endl;
        cout<<str<<endl;
        return 0;
    }

    cout<<2<<endl;
    cout<<str[0]<<" "<<str.substr(1);

    return 0;
}
