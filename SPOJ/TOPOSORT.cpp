#include <bits/stdc++.h>
using namespace std;
int n, m, vis[10005];
bool ag;
vector<vector<int>> adjList(10005);
deque<int> order;

void dfs(int v){
    vis[v] = 1;

    for(int u : adjList[v]){
        if(vis[u]){
            if(vis[u] == 1)
                ag = true;
            continue;
        }
        dfs(u);
    }

    vis[v] = 2;
    order.push_front(v);
}

int main(){
    cin>>n>>m;

    for(int i = 0; i < m; i++){
        int a, b;
        cin>>a>>b;
        adjList[a].emplace_back(b);
    }
    for(int i = 1; i <= n; i++)
        sort(adjList[i].begin(), adjList[i].end(), greater<int>());

    for(int i = n; i >= 1; i--){
        if(vis[i]) continue;
        dfs(i);
    }

    if(ag)
        cout<<"Sandro fails."<<endl;

    else{
        for(int i = 0; i < n; i++){
            cout<<order.front()<<" ";
            order.pop_front();
        }
    }

    return 0;
}
