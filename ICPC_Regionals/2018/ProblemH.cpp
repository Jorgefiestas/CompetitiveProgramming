#include <bits/stdc++.h>
using namespace std;
typedef vector<long long> pii;
long long n, m, cost;
vector<pii> adjList[10005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m;
    long long a, b, l, c;
    for(int i = 0; i < m; i++){
        cin>>a>>b>>l>>c;
        adjList[a].push_back({l, c, b});
        adjList[b].push_back({l, c, a});
    }

    auto comp = [](pii x, pii y){
        if(x[0] != y[0])
            return x[0] > y[0];
        return x[1] > y[1];
    };

    priority_queue<pii, vector<pii>, greater<pii>> Q;
    pii dist(100005, LLONG_MAX);
    pii par(100005, -1);
    vector<bool> vis(100005, false);

    Q.push({0, 0, 1});
    dist[1] = 0;
    while(!Q.empty()){
        pii p = Q.top();
        Q.pop();
        long long v = p[2];
        if(dist[v] != p[0] || vis[v]) continue;
        vis[v] = true;

        cost += p[1];

        for(pii edg : adjList[v]){
            if(dist[v] + edg[0] <= dist[edg[2]]){
                dist[edg[2]] = dist[v] + edg[0];
                par[edg[2]] = v;
                Q.push({dist[edg[2]], edg[1], edg[2]});
            }
        }
    }

    cout<<cost<<endl;

    return 0;
}
