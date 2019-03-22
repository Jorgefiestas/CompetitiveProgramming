#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<vector<int>> al(100000);
bool cat[100000];

int dfs(int v, int tm, int d){
	if(cat[v]) tm++;
	else tm = 0;
	if(tm > m) return 0;
	int res = 0;
	if(al[v].size() == 1 && v != 0)
		return 1;
	for(int x : al[v]){
		if(x == d) continue;
		res += dfs(x, tm, v);
	}
	return res;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	for(int i = 0; i<n; i++)
		cin>>cat[i];
	for(int i = 1; i<n; i++){
		int a, b;
		cin>>a>>b;
		a--; b--;
		al[a].emplace_back(b);
		al[b].emplace_back(a);
	}
	cout<<dfs(0,0,0)<<endl;
}
