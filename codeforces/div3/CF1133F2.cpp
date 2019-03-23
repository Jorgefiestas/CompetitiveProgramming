#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
int n, m, k, sidx, vis[200005], ecs[200005];
vector<vector<int>> adjList;
vector<PII> MST;
vector<unordered_set<int>> ds;

void dfs(int v){
	ds[sidx].insert(v);
	for(int u : adjList[v]){
		if(u == 0) ecs[sidx] = v;
		if(vis[u] || u == 0) continue;
		vis[u] = true;
		dfs(u);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m>>k;
	adjList.resize(n);
	for(int i = 0; i<m; i++){
		int u, v;
		cin>>u>>v, u--, v--;
		adjList[u].emplace_back(v);
		adjList[v].emplace_back(u);
	}
	for(int i = 1; i<n; i++){
		if(vis[i]) continue;
		ds.push_back(unordered_set<int>());
		dfs(i);
		sidx++;
	}
	if(sidx > k || adjList[0].size() < k){
		cout<<"NO"<<endl;
		return 0;
	}
	memset(vis, false, sizeof vis);
	vis[0] = true;
	queue<int> q;
	for(int i = 0; i<sidx; i++){
		MST.push_back(make_pair(0, ecs[i]));
		vis[ecs[i]] = true;
		q.push(ecs[i]);
	}
	int visited = sidx;
	for(int u : adjList[0]){
		if(visited == k) break;
		if(vis[u]) continue;
		vis[u] = true;
		MST.push_back(make_pair(0, u));
		q.push(u);
		visited++;
	}
	while(!q.empty()){
		int v = q.front();
		q.pop();
		for(int u : adjList[v]){
			if(vis[u]) continue;
			vis[u] = true;
			q.push(u);
			MST.push_back(make_pair(u, v));
		}
	}
	cout<<"YES"<<endl;
	for(PII p : MST)
		cout<<p.first+1<<" "<<p.second+1<<endl;
	return 0;
}
