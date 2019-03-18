#include <bits/stdc++.h>
using namespace std;
unordered_map<int,vector<int>> indb;
map<int, int> curr;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int m;
	cin>>m;
	vector<int> a(m), b(m);
	for(int i = 0; i<m; i++) cin>>a[i];
	for(int i = 0; i<m; i++){
		cin>>b[i];
		indb[b[i]].emplace_back(i);
	}
	
	sort(a.begin(), a.end(), greater<int>());
	sort(b.begin(), b.end());
	vector<int> c(m);
	
	for(int i = 0; i<m; i++)
		c[indb[b[i]][curr[b[i]]++]] = a[i];
	for(int x : c)
		cout<<x<<" ";
	cout<<endl;
	return 0;
}
