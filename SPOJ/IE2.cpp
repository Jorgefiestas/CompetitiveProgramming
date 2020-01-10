#include <bits/stdc++.h>
using namespace std;
long long n, m, k, d, adjMat[22][22], tempMat[22][22];
const long long mod = 1000000009;

void removeNode(int idx){
	for(int i = 0; i < n; i++){
		tempMat[idx][i] = 0;
	}

	for(int i = 0; i < n; i++){
		tempMat[i][idx] = 0;
	}
}

void multiply(long long A[22][22], long long B[22][22]){
	long long ans[22][22];

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			ans[i][j] = 0;
			for(int l = 0; l < n; l++){
				ans[i][j] = (ans[i][j] + A[i][l]*B[l][j]) % mod;
			}
		}
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			A[i][j] = ans[i][j];
		}
	}
}

long long count(){

	long long res[22][22];

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			res[i][j] = (i == j);
		}
	}

	for(long long p = d - 1; p; p >>= 1){
		if(p & 1){
			multiply(res, tempMat);
		}
		multiply(tempMat, tempMat);
	}

	long long ans = 0;

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			ans = (ans + res[i][j]) % mod;
		}
	}

	return ans;
}

int main(){
	cin>>n>>m>>k>>d;

	int a, b;
	for(int i = 0; i < m; i++){
		cin>>a>>b;
		adjMat[a - 1][b - 1] = 1;
		adjMat[b - 1][a - 1] = 1;
	}

	long long ans = 0;

	for(int mask = 0; mask < (1<<k); mask++){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				tempMat[i][j] = adjMat[i][j];
			}
		}

		for(int i = 0; i < k; i++){
			if(mask & (1 << i)){
				removeNode(i);
			}
		}

		long long temp = (d > 1) ? count() : n - __builtin_popcount(mask) ;
		ans += (__builtin_popcount(mask)&1) ? mod - temp : temp;
		ans %= mod;
	}

	cout<<ans<<endl;

	return 0;
}
