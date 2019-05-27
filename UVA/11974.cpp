#include <bits/stdc++.h>
using namespace std;
int T;
int mem[101][32769];
int val[100];

int solve(int n, int m){
	int sum = (1<<n) - 1;
	memset(val, 0, sizeof val);

	for(int i = 0; i<m; i++){
		int aux;
		for(int j = 0; j<n; j++){
			cin>>aux;
			val[i] = (val[i]<<1) + aux;
		}
	}
	sort(val, val + m);
	
	for(int i = 1; i<= sum; i++)
		mem[0][i] = 1000;

	for(int i = 1; i<=m; i++){
		int v = val[i-1];
		for(int j = 0; j<=sum; j++)
			mem[i][j] = min(mem[i-1][j^v] + 1, mem[i-1][j]);
	}
	
	return mem[m][sum];
}

	

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>T;
	for(int i = 1; i<= T; i++){
		int n, k;
		cin>>n>>k;
		int mn = solve(n, k);
		cout<<"Case "<<i<<": ";
		if(mn > 100) cout<<"IMPOSSIBLE"<<endl;
		else cout<<mn<<endl;
	}
	return 0;
}
