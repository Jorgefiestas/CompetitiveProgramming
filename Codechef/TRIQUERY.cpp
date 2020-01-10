#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int maxn = 1000005;
int n, q, S[maxn], X[maxn], Y[maxn], res[maxn];
int ft1[maxn], ft2[maxn], ft3[maxn];
vector<pii> P, QB[maxn];
vector<int> QT[maxn];

int query(int *ft, int idx){
	int ans = 0;
	while(idx > 0){
		ans += ft[idx];
		idx -= idx & -idx;
	}
	return ans;
}

void update(int *ft, int idx, int v){
	while(idx < maxn){
		ft[idx] += v;
		idx += idx & -idx;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n>>q;

	int x, y, d;
	for(int i = 0; i < n; i++){
		cin>>x>>y;
		P.push_back({x, y});
	}
	for(int i = 0; i < q; i++){
		cin>>x>>y>>d;
		QB[x - 1].push_back({y, i});
		QT[y + x + d].push_back(i);
		X[i] = x;
		Y[i] = y;
	}

	sort(P.begin(), P.end());
	int j = 0;
	for(int i = 1; i < maxn; i++){
		while(j < n && P[j].first <= i){
			update(ft1, P[j].second, 1);
			j++;
		}

		for(pii qu : QB[i]){
			S[qu.second] = query(ft1, qu.first - 1);
		}
	}

	auto comp = [](pii a, pii b){
		return a.first + a.second < b.first + b.second;
	};

	sort(P.begin(), P.end(), comp);

	int cnt = 0;
	j = 0;
	for(int i = 1; i < maxn; i++){
		while(j < n && P[j].first + P[j].second <= i){
			update(ft2, P[j].first, 1);
			update(ft3, P[j].second, 1);
			cnt++;
			j++;
		}

		for(int qu : QT[i]){
			int TT = query(ft2, X[qu] - 1);
			int HT = query(ft3, Y[qu] - 1);
			res[qu] = S[qu] - TT - HT + cnt;
		}
	}

	for(int i = 0; i < q; i++){
		cout<<res[i]<<endl;
	}

	return 0;
}
