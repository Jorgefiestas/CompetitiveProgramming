#include <bits/stdc++.h>
using namespace std;
typedef pair<long long, long long> PII;
long long n, m, suml[300001], ans[300001];
vector<vector<long long>> adjList;
vector<PII> q[3000001];

void dfs(long long v, long long p, long long h, long long total){
	long long s = -suml[h];
	for(PII p : q[v]){
		s += p.second;
		if( h + p.first + 1 <= 300000) suml[h + p.first + 1] += p.second;
	}
	total += s;
	ans[v] = total;
	for(long long v1 : adjList[v])
		if(v1 != p) dfs(v1, v, h+1, total);
	for(PII p : q[v]) if( h + p.first + 1 <= 300000) suml[h + p.first + 1] -= p.second;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	adjList.resize(n);
	for(long long i = 0; i < n-1; i++){
		int a, b;
		cin>>a>>b;
		adjList[a-1].emplace_back(b-1);
		adjList[b-1].emplace_back(a-1);
	}
	cin>>m;
	for(long long i = 0; i<m; i++){
		long long v, d, x;
		cin>>v>>d>>x;
		q[v-1].emplace_back(make_pair(d, x));
	}
	dfs(0, -1, 0, 0);
	for(long long i = 0; i<n; i++)
		cout<<ans[i]<<" ";
	cout<<endl;
	return 0;
}
