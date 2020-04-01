#include <bits/stdc++.h>
using namespace std;
int n, res, colors[300005], ccnt[3], vc[300005][2];
vector<vector<int>> adjList;

void dfs(int v, int p){
	if(colors[v] == 1) vc[v][0]++;
	else if(colors[v] == 2) vc[v][1]++;
	for(int u : adjList[v]){
		if(u == p) continue;
		dfs(u, v);
		vc[v][0] += vc[u][0];
		vc[v][1] += vc[u][1];
	}
	if(vc[v][0] == ccnt[1] && vc[v][1] == 0)
		res++;
	if(vc[v][1] == ccnt[2] && vc[v][0] == 0)
		res++;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	adjList.resize(n);
	for(int i = 0; i<n; i++)
		cin>>colors[i], ccnt[colors[i]]++;
	for(int i = 0; i<n-1; i++){
		int u, v;
		cin>>u>>v, u--; v--;
		adjList[u].emplace_back(v);
		adjList[v].emplace_back(u);
	}
	dfs(0, -1);
	cout<<res<<endl;
	return 0;
}
