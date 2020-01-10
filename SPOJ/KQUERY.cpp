#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int maxn = 30004;
int n, q, ft[maxn], L[200005], R[200005], res[200005];
vector<pii> P, Q;

int query(int idx){
	int ans = 0;
	while(idx > 0){
		ans += ft[idx];
		idx -= idx & -idx;
	}
	return ans;
}

void update(int idx, int v){
	while(idx < maxn){
		ft[idx] += v;
		idx += idx & -idx;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n;
	for(int i = 1; i <= n; i++){
		int t;
		cin>>t;
		P.push_back({t, i});
	}
	sort(P.begin(), P.end());

	cin>>q;
	for(int i = 0; i < q; i++){
		int l, r, k;
		cin>>l>>r>>k;
		L[i] = l;
		R[i] = r;
		Q.push_back({k, i});
	}

	sort(Q.begin(), Q.end());

	for(int i = 1; i <= n; i++){
		update(i, 1);
	}

	int j = 0;
	for(pii qu : Q){
		while(j < n && P[j].first <= qu.first){
			update(P[j].second, -1);
			j++;
		}
		int l = L[qu.second];
		int r = R[qu.second];
		res[qu.second] = query(r) - query(l - 1);
	}

	for(int i = 0; i < q; i++){
		cout<<res[i]<<'\n';
	}

	return 0;
}
