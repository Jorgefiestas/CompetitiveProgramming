#include <bits/stdc++.h>
using namespace std;
int n;
vector<vector<int>> adjList;
vector<int> roots, degree;
stack<int> mx;

void dfs(int v, stack<int> &temp){
	if(degree[v] > 1) return;
	temp.push(v);
	if(adjList[v].size() == 0) return;
	dfs(adjList[v][0], temp);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	adjList.resize(n), degree.resize(n);
	for(int i = 0; i<n; i++){
		int hotel;
		cin>>hotel;
		if(hotel) roots.emplace_back(i);
	}
	for(int i = 0; i<n; i++){
		int v;
		cin>>v; v--;
		if(v == -1) continue;
		adjList[i].emplace_back(v);
		degree[v]++;
	}
	for(int r : roots){
		stack<int> temp;
		dfs(r, temp);
		if(temp.size() > mx.size()) mx = temp;
	}
	cout<<mx.size()<<endl;
	while(!mx.empty())
		cout<<mx.top()+1<<" ", mx.pop();
	cout<<endl;
	return 0;
}
