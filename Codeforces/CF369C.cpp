#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> al(100000);
unordered_map<int, unordered_map<int,bool>> br;
unordered_set<int> ms;
int n, a, b, c;

int dfs(int v, int p){
	int s1 = 0;
	if(br[v][p]) s1 = 1;
	int s2 = 0;
	for(int x : al[v]){
		if(x == p) continue;
		s2 += dfs(x,v);
	}
	if(s1>s2) ms.insert(v);
	return max(s1, s2);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for(int i = 1; i<n; i++){
		cin>>a>>b>>c;
		a--; b--; c--;
		al[a].emplace_back(b);
		al[b].emplace_back(a);
		br[a][b] = c;
		br[b][a] = c;
	}
	cout<<dfs(0, 0)<<endl;
	for(int x : ms)
		cout<<x+1<<" ";
	cout<<endl;
}
