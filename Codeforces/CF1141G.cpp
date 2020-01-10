#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
vector<PII> E;
vector<int> vertices;
vector<vector<int>> adjList;
map<int, map<int, int>> colors;
int n, k, c;

void dfs(int v, int p, int ic){
	int t_c = 1;
	for(int u : adjList[v]){
		if(u == p) continue;
		if(t_c ==  ic) t_c++;
		if(t_c > c) t_c = 1;
		colors[u][v] = t_c;
		colors[v][u] = t_c;
		dfs(u, v, t_c);
		t_c++;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>k;
	vertices.resize(n), adjList.resize(n), E.resize(n-1);
	for(int i = 0; i<n-1; i++){
		int u, v;
		cin>>u>>v;
		adjList[u-1].emplace_back(v-1);
		adjList[v-1].emplace_back(u-1);
		E[i] = make_pair(u-1, v-1);
	}
	for(int i = 0; i<n; i++) vertices[i] = i;
	sort(vertices.begin(), vertices.end(), [](int a, int b){ return adjList[a].size() > adjList[b].size();});
	c = adjList[vertices[k]].size();
	dfs(0, -1, -1);
	cout<<c<<endl;
	for(PII p : E)
		cout<<colors[p.first][p.second]<<" ";
	cout<<endl;
	return 0;
}
