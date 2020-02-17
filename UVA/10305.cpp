#include <bits/stdc++.h>
using namespace std;
int n, m;
bool vis[105];
vector<vector<int>> adjList(105);
deque<int> order;

void dfs(int v){
    vis[v] = 1;

    for(int i = 0; i < adjList[v].size(); i++){
        int u = adjList[v][i];
        if(vis[u]) continue;
        dfs(u);
    }
    order.push_front(v);
}

void solve(){
    for(int i = 0; i < m; i++){
        int a, b;
        cin>>a>>b;
        adjList[a].emplace_back(b);
    }

    for(int i = 1; i <= n; i++){
        if(vis[i]) continue;
        dfs(i);
    }

    for(int i = 0; i < n; i++){
        cout<<order.front()<<" ";
        order.pop_front();
    }
    cout<<endl;
}

int main(){
    while(cin>>n>>m, n){
        memset(vis, 0, sizeof vis);
        adjList.clear();
        adjList.resize(105);
        order.clear();
        solve();
    }

    return 0;
}
