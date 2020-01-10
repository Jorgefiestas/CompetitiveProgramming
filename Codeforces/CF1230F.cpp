#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
int n, m, q;
unordered_set<int> ID[maxn], OD[maxn];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin>>n>>m;

	int a, b;
	for(int i = 0; i < m; i++){
		cin>>a>>b;
		if(a > b){
			swap(a, b);
		}
		ID[a].insert(b);
		OD[b].insert(a);
	}

	long long s = 0;
	for(int i = 1; i <= n; i++){
		s += (signed long long)ID[i].size() * (signed long long)OD[i].size();
	}
	cout<<s<<endl;

	cin>>q;

	int v;
	for(int i = 1; i <= q; i++){
		cin>>v;
		s -= (signed long long)ID[v].size() * (signed long long)OD[v].size();
		for(int u : ID[v]){
			s += (signed long long)OD[u].size() - (signed long long)ID[u].size() - 1;
			OD[u].erase(v);
			ID[u].insert(v);
			OD[v].insert(u);
		}
		ID[v].clear();
		cout<<s<<endl;
	}

	return 0;
}
