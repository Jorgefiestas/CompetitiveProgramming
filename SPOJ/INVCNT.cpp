#include <bits/stdc++.h>
using namespace std;
const int maxn = 10000007;
int t, n;
long long ft[maxn];

long long query(int idx){
	long long ans = 0;
	while(idx > 0){
		ans += ft[idx];
		idx -= idx & -idx;
	}
	return ans;
}

void update(int idx, long long v){
	while(idx < maxn){
		ft[idx] += v;
		idx += idx & -idx;
	}
}

void solve(){
	cin>>n;

	int m;
	long long cnt = 0;
	for(long long i = 1; i <= n; i++){
		cin>>m;
		update(m, 1);
		cnt += i - query(m);
	}

	cout<<cnt<<endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>t;
	while(t--){
		memset(ft, 0, sizeof ft);
		solve();
	}

	return 0;
}
