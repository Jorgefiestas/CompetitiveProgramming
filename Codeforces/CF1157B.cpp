#include <bits/stdc++.h>
using namespace std;
string num;
int i, j, f[10];
int n;

int main(){
    ios_base::sync_with_stdio(false);
    cin>>n>>num;
    for(int i = 1; i<10; i++)
        cin>>f[i];
    for(i = 0; i<n && f[num[i]-'0'] <= (num[i]-'0'); i++);
    for(j = i; j<n && f[num[j]-'0'] >= (num[j]-'0'); j++)
        num[j] = f[num[j]-'0'] + '0';
    cout<<num;
    return 0;
}
