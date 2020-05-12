#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int N = 1e5 + 10;
int q, ft[N], res[N], gpf[N];
vector<pii> queries[N];

void sieve(){
	for (int i = 2; i < N; i++) {
		gpf[i] = i;
	}

	for (int i = 2; i < N; i++) {
		if (gpf[i] != i) continue;
		for (int j = i; j < N; j += i) {
			gpf[j] = i;
		}
	}
}

void update(int idx) {
	while (idx < N) {
		ft[idx]++;
		idx += idx & -idx;
	}
}

int query(int idx) {
	int ans = 0;
	while (idx > 0) {
		ans += ft[idx];
		idx -= idx & -idx;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	sieve();

	cin >> q;
	
	int ni, ki;
	for (int i = 0; i < q; i++) {
		cin >> ni >> ki;
		queries[ni].push_back({ki, i});
	}

	for (int i = 2; i < N; i++) {
		update(gpf[i]);
		for (pii qu : queries[i]) {
			res[qu.second] = query(qu.first);
		}
	}

	for (int i = 0; i < q; i++) {
		cout << res[i] << '\n';
	}

	return 0;
}
