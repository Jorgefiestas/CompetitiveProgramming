#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int maxn = 30005;
int n, q, nextt[maxn], ft[maxn], res[200005];
vector<pii> queries[200005];
unordered_map<int, int>  last;

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
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin>>n;

	int t;
	for(int i = 1; i <= n; i++){
		cin>>t;
		if(last.find(t) == last.end()){
			update(i, 1);
		}
		else{
			nextt[last[t]] = i;
		}
		last[t] = i;
	}

	cin>>q;

	int l, r;
	for(int i = 0; i < q; i++){
		cin>>l>>r;
		queries[l].push_back(make_pair(r, i));
	}

	for(int i = 1; i <= n; i++){
		for(pii q : queries[i]){
			res[q.second] = query(q.first);
		}
		update(i, -1);
		if(nextt[i]){
			update(nextt[i], 1); 
		}
	}

	for(int i = 0; i < q; i++){
		cout<<res[i]<<endl;
	}

	return 0;
}
