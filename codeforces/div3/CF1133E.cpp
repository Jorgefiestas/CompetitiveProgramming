#include <bits/stdc++.h>
using namespace std;
int n, k, a[5001], mem[5002][5002];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>k;
	for(int i = 1; i<=n; i++)
		cin>>a[i];
	sort(a, a + n + 1);
	for(int j = 0; j <= k; j++){
		int r = 1;
		for(int i = 0; i<=n; i++){
			if(i != 0) mem[i][j] = max(mem[i][j], mem[i-1][j]);
			if(i<n && j<k){
				while(r <= n && a[r] <= a[i+1] + 5){
					mem[r][j+1] = max(mem[r][j+1], mem[i][j]+r-i);
					r++;
				}
			}
		}
	}
	cout<<mem[n][k]<<endl;
	return 0;
}
