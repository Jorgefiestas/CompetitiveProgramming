#include <bits/stdc++.h>
using namespace std;
typedef pair<long long, long long> PII;
vector<vector<PII>> edges;
vector<PII> E;
vector<vector<long long>> children;
map<long long, map<long long, long long>> idx;
long long n, m, k;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m>>k;
	edges.resize(n), E.resize(m), children.resize(n);
	for(int i = 0; i<m; i++){
		long long x, y, w;
		cin>>x>>y>>w;
		edges[x-1].push_back(make_pair(w, y-1));
		edges[y-1].push_back(make_pair(w, x-1));
		idx[x-1][y-1] = i + 1;
		idx[y-1][x-1] = i + 1;
		E[i] = make_pair(x-1, y-1);
	}
	priority_queue<PII, vector<PII>, greater<PII>> q;
	vector<long long> dist(n, LLONG_MAX),  dad(n, -1);
	q.push(make_pair(0, 0));
	dist[0] = 0;
	while(!q.empty()){
		PII p = q.top();
		q.pop();
		long long v = p.second;
		if(dist[v] != p.first) continue;
		for(PII e : edges[v]){	
			if(dist[v] + e.first < dist[e.second]){
				dist[e.second] = dist[v] + e.first;
				dad[e.second] = v;
				q.push(make_pair(dist[e.second], e.second));
			}
		}
	}
	for(int i = 1; i<n; i++)
		children[dad[i]].emplace_back(i);
	int count = 0;
	cout<<min(n-1, k)<<endl;
	queue<long long> pq;
	pq.push(0);
	while(!pq.empty()){
		int  i = pq.front();
		pq.pop();
		for(long long x : children[i]){
			if(count == k) break;
			cout<<idx[i][x]<<" ";
			pq.push(x);
			count++;
		}
		if(count == k) break;
	}
	cout<<endl;
	return 0;
}
