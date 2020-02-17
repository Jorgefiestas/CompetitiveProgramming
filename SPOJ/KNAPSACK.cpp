#include <bits/stdc++.h>
using namespace std;
int s, n;
int w[20000], v[20000], mem[20000][20000];
bool vis[20000][20000];

int dp(int i, int c){
    if(i == n) return 0;
    if(vis[i][c]) return mem[i][c];
    vis[i][c] = true;
    int ans = dp(i+1, c);
    if(w[i] <= c) ans = max(ans, dp(i+1, c-w[i]) + v[i]);
    return mem[i][c] = ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>s>>n;
    for(int i = 0; i<n; i++)
        cin>>w[i]>>v[i];
    cout<<dp(0, s)<<endl;
}
