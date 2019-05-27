#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<int>> adjList(200001);
int parity[200001], edges[200001];

bool dfs(int v){
	for(int u : adjList[v]){
		if(parity[u]){
			if(parity[u] == parity[v]) return false;
			else continue;
		}
		parity[u] = 3 - parity[v];
		if(!dfs(u)) return false;
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	for(int i = 0; i<m; i++){
		int u, v;
		cin>>u>>v;
		u--, v--;
		edges[i] = u;
		adjList[u].emplace_back(v);
		adjList[v].emplace_back(u);
	}
	parity[0] = 1;
	if(dfs(0)){
		cout<<"YES"<<endl;
		for(int i = 0; i<m; i++) cout<<parity[edges[i]]-1;	
		cout<<endl;
	}
	else 
		cout<<"NO"<<endl;
	return 0;
}
