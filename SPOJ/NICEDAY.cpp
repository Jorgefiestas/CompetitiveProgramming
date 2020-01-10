#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int maxn = 100005;
int t, n, y[maxn], v[maxn], ft[maxn];
vector<pii> points;

void update(int idx, int val){
	while(idx < maxn){
		ft[idx] = min(ft[idx], val);
		idx += idx & -idx;
	}
}

int query(int idx){
	int ans = INT_MAX;
	while(idx > 0){
		ans = min(ft[idx], ans);
		idx -= idx & -idx;
	}
	return ans;
}

void solve(){
	cin>>n;
	points.resize(n);

	for (int i = 0; i < n; i ++) {
		cin>>points[i].first;
		points[i].second = i;
		cin>>y[i];
		cin>>v[i];
	}

	sort(points.begin(), points.end());
	
	int mny = INT_MAX;
	int cnt = 0;
	for(pii p : points){
		int idx = p.second;
		if(y[idx] < mny){
			mny = y[idx];
			cnt++;
		}
		else{
			if(v[idx] < query(y[idx])){
				cnt++;
			}
		}
		update(y[idx], v[idx]);
	}

	cout<<cnt<<endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin>>t;
	while(t--){
		points.clear();
		memset(ft, 1, sizeof ft);
		solve();
	}

	return 0;
}
