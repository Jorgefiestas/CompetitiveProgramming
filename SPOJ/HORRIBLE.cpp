#include <bits/stdc++.h>
using namespace std;
int const maxn = 100005;
long long t, n, c, ft1[maxn], ft2[maxn];

void update(long long *ft, int idx, long long v){
	while(idx < maxn){
		ft[idx] += v;
		idx += idx & -idx;
	}
}

long long query(long long *ft, int idx){
	long long ans = 0;
	while(idx > 0){
		ans += ft[idx];
		idx -= idx & -idx;
	}
	return ans;
}

void solve(){
	cin>>n>>c;
	
	bool t;
	int p, q;
	long long v;
	for(int i = 0; i < c; i++){
		cin>>t>>p>>q;
		if(t){
			long long R = query(ft1, q)*q - query(ft2, q);
			long long L = query(ft1, p - 1)*(p - 1) - query(ft2, p - 1);
			cout<<R - L<<endl;
		}
		else{
			cin>>v;
			update(ft1, p, v);
			update(ft2, p, (p - 1)*v);
			
			update(ft1, q + 1, -v);
			update(ft2, q + 1, -q * v);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin>>t;
	while(t--){
		memset(ft1, 0, sizeof ft1);
		memset(ft2, 0, sizeof ft2);
		solve();
	}

	return 0;
}
