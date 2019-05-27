#include <bits/stdc++.h>
using namespace std;
int n, c, d, dia, dist[100000];
unordered_map<int, bool> tree;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	tree[0] = true;
	dist[0] = 0;
	for(int i =1; i<=n; i++){
		cin>>d;
		c += d;
		dist[i] = c;
		tree[c] = true;
	}
	for(int i = 0; dist[i]<c/2; i++)
		if(tree[dist[i] + c/2]) dia++;
	if(dia>1) cout<<'Y'<<endl;
	else cout<<'N'<<endl;
	return 0;
}
