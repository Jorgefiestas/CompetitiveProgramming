#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> adjList[100005];

bool dfs(int v, int p){
	if(adjList[v].size() - 1 == 1)
		return false;

	for(int u : adjList[v]){
		if(u == p)
			continue;
		if(!dfs(u, v))
			return false;
	}

	return true;
}

int main(){
	cin>>n;

	int a, b;
	for(int i = 0; i < n - 1; i++){
		cin>>a>>b;
		adjList[a].emplace_back(b);
		adjList[b].emplace_back(a);
	}

	if(dfs(1, 0)){
		cout<<"YES"<<endl;
	}
	else{
		cout<<"NO"<<endl;
	}

	return 0;
}
