#include <bits/stdc++.h>
using namespace std;
int n, mem[100005][4];
vector<int> children[100005];
bool vis[100005][4];

int dp(int v, int l){
    if(vis[v][l])
        return mem[v][l];

    int ans = 0;

    if(l == 1){
        for(int u : children[v])
            ans += max(dp(u, 2), dp(u, 1));
    }

    else if(l == 2){
        if(children[v].size() < 3)
            return 0;

        int sm = 0;
        for(int u : children[v])
            sm += max(dp(u, 1), dp(u, 2));

        for(int u : children[v])
            if(dp(u, 3))
                ans = max(ans, sm - max(dp(u, 1), dp(u,2)) + dp(u, 3));
    }

    else{
        if(children[v].size() < 2)
            return 0;
        ans = 1;

        int sm = 0;
        for(int u : children[v])
            sm += max(dp(u, 1), dp(u, 2));

        for(int u : children[v])
            ans = max(ans, sm - max(dp(u, 2), dp(u, 1)) + dp(u, 1));
    }

    vis[v][l] = true;
    return mem[v][l] = ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    int par;
    for(int i = 2; i <= n; i++){
        cin>>par;
        children[par].emplace_back(i);
    }

    cout<<dp(1, 1)<<endl;

    return 0;
}
