#include <bits/stdc++.h>
using namespace std;
int t, n;

int solve(){
    unordered_map<int, vector<int>> adjList;
    unordered_map<int, int> dis;
    unordered_map<int, int> vis;
    int a, b;

    cin>>n;
    
    for(int i = 0; i < n; i++){
        cin>>a>>b;

        adjList[a].emplace_back(b);
        adjList[b].emplace_back(a);
    }

    queue<int> q;

    int cnt = 0;

    for(auto it : adjList){
        if(vis[it.first]) continue;

        int temp = 0;
        int total = 0;

        q.push(it.first);
        vis[it.first] = true;
        while(!q.empty()){
            int curr = q.front();
            q.pop();

            if(dis[curr]%2 == 0) temp++;
            total++;

            for(int v : adjList[curr]){
                if(vis[v]) continue;
                vis[v] = true;
                dis[v] = dis[curr] + 1;
                q.push(v);
            }
        }

        cnt += max(temp, total - temp);
    }

    return cnt;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>t;

    for(int i = 1; i<= t; i++){
        cout<<"Case "<<i<<": "<<solve()<<endl;
    }

    return 0;
}
