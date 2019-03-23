#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
int n, m, vis[200005], dad[200005];
vector<vector<int>> adjList;
vector<PII> MST;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	memset(dad, -1, sizeof dad);
	cin>>n>>m;
	adjList.resize(n);
	for(int i = 0; i<m; i++){
		int u, v;
		cin>>u>>v;
		adjList[u-1].push_back(v-1);
		adjList[v-1].push_back(u-1);
	}
	int root = 0;
	for(int i = 1; i<n; i++)
		if(adjList[root].size() < adjList[i].size()) root = i;
	queue<int> q;
	q.push(root);
	dad[root] = root;
	while(!q.empty()){
		int v = q.front();
		q.pop();
		for(int u : adjList[v]){
			if(dad[u] != -1) continue;
			MST.push_back(make_pair(v, u));
			q.push(u);
			dad[u] = v;
		}
	}
	for(PII p : MST)
		cout<<p.first+1<<" "<<p.second+1<<endl;
	return 0;
}
