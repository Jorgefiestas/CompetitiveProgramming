#include <bits/stdc++.h>
using namespace std;
long long n, q, d, m;
long long arr[200], mem[205][11][22];
bool vis[205][11][22];

long long dp(int i, int c, long long r){
    if(i > n) return 0;
    if(c == 0){
        if(r) return 0;
        else return 1;
    }
    if(i == n) return 0;
    if(vis[i][c][r]) return mem[i][c][r];
    vis[i][c][r] = true;
    return mem[i][c][r] = dp(i+1, c, r) + dp(i+1, c-1, (d+(r+arr[i])%d)%d);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>q;
    int idx = 1;
    while(n && q){
        cout<<"SET "<<idx++<<":"<<endl;
        for(int i = 0; i<n; i++)
            cin>>arr[i];
        for(int i = 0; i<q; i++){
            memset(mem, 0, sizeof mem);
            memset(vis, 0, sizeof vis);
            cin>>d>>m;
            cout<<"QUERY "<<i+1<<": "<<dp(0, m, 0)<<endl;
        }
        cin>>n>>q;
    }
    return 0;
}
