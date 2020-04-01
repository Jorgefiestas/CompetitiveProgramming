#include <bits/stdc++.h>
using namespace std;
int n;
string str;
string g = "ACTG";

int main(){
    cin>>n>>str;
    int mx = INT_MAX;
    for(int i = 0; i<n-3; i++){
        int temp = 0;
        for(int j = 0; j<4; j++)
            temp += min(26-abs(str[i+j]-g[j]), abs(str[i+j]-g[j]));
        mx = min(temp, mx);
    }
    cout<<mx<<endl;
    return 0;
}
