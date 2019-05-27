#include <bits/stdc++.h>
using namespace std;
int n, x, y, cnt;
string num;

int check(int i, char c){
    return c != num[i];
}

int main(){
    cin>>n>>x>>y>>num;
    for(int i = n-x; i<n; i++){
        if(n-i-1 == y) cnt += check(i, '1');
        else cnt += check(i, '0');
    }
    cout<<cnt<<endl;
    return 0;
}

