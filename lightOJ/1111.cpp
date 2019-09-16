#include <bits/stdc++.h>
using namespace std;
int T, k, n, m, cnt[1001], vis[1001];

void dfs(vector<vector<int>> &adjList, int v){
    vis[v] = true;
    cnt[v]++;
    for(int u : adjList[v]){
        if(vis[u]) continue;
        dfs(adjList, u);
    }
}


int solve(){
    memset(cnt, 0, sizeof cnt);
    cin>>k>>n>>m;

    vector<vector<int>> adjList(n);
    vector<int> origin(k);

    for(int i = 0; i<k; i++){
        cin>>origin[i];
        origin[i]--;
    }
    
    int a, b;
    for(int i = 0; i<m; i++){
        cin>>a>>b;
        a--, b--;
        adjList[a].emplace_back(b);
    }

    for(int s : origin){
        memset(vis, 0, sizeof vis);
        dfs(adjList, s);
    }

    int ans = 0;
    for(int i = 0; i<n; i++){
        if(cnt[i] == k){
            ans++;
        }
    }

    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>T;
    for(int i = 1; i<=T; i++){
        cout<<"Case "<<i<<": "<<solve()<<endl;
    }

    return 0;
}
