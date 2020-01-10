#include <bits/stdc++.h>
using namespace std;
long long n, k, tables[300001], formulas[100001];
long long mem[3000001][2];

long long minLast(long long a, long long b, long long i, long long j){
	long long res = LLONG_MAX;
	if(mem[i-1][1-j] != -1){
		long long mn = (a+k-1)/k - 1;
		if(b == mn) res = a - mn*k;
		else if(b > mn && (a-1)*k + k - mem[i-1][1-j] >= b) res = 1;
	}
	if(mem[i-1][j] != -1){
		long long mn = (mem[i-1][j]+a+k-1)/k - 1;
		if(b == mn) res = min(res, mem[i-1][j] + a - mn*k);
		else if(b > mn && a*k >= b) res = 1;
	}
	return res == LLONG_MAX ? -1 : res;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>k;
	for(long long i = 1; i<=n; i++) cin>>tables[i];
	for(long long i = 1; i<=n; i++) cin>>formulas[i];
	for(long long i = 1; i<=n; i++){
		mem[i][0] = minLast(tables[i], formulas[i], i, 0);
		mem[i][1] = minLast(formulas[i], tables[i], i, 1);
		if(mem[i][0] == -1 && mem[i][1] == -1){
			cout<<"NO"<<endl;
			return 0;
		}
	}
	cout<<"YES"<<endl;
	return 0;
}
