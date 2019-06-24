#include <bits/stdc++.h>
using namespace std;
int T, mx, n;
vector<vector<int>> adjList;
unordered_map<int, unordered_map<int,int>> dist;

int dfs(int v, int p){
    int tmp1 = 0, tmp2 = 0;

    for(int u : adjList[v]){
        if(u == p) continue;
        int temp = dfs(u, v);
        if(temp > tmp1){
            tmp2 = tmp1;
            tmp1 = temp;
        }
        else if(temp > tmp2){
            tmp2 = temp;
        }
    }

    if(tmp1 + tmp2 > mx){
        mx = tmp1 + tmp2;
    }

    return dist[p][v] + tmp1;
}

int solve(){
    adjList.clear();
    dist.clear();
    mx = 0;

    cin>>n;

    adjList.resize(n);

    int a, b, w;
    for(int i = 0; i < n - 1; i++){
        cin>>a>>b>>w;
        adjList[a].emplace_back(b);
        adjList[b].emplace_back(a);
        dist[a][b] = w;
        dist[b][a] = w;
    }

    dfs(0, -1);

    return mx;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>T;
    for(int i = 1; i <= T; i++){
        cout<<"Case "<<i<<": "<<solve()<<endl;
    }

    return 0;
}
