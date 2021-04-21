#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int t, n, q;
int f[N];

void sieve() {
	for (int i = 1; i < N; i ++) {
		f[i] = i;
	}

	for (int i = 1000; i > 1; i--) {
		int sq = i * i;
		for (int j = sq; j < N; j += sq) {
			if (f[j] % sq == 0) f[j] /= sq;
		}
	}
}

void solve() {
	cin >> n;

	map<int, int> cnt;

	int ai;
	for (int i = 0; i < n; i++) {
		cin >> ai;
		cnt[f[ai]] += 1;
	}

	int mx = 0;
	int sm = 0;

	for (auto [k, v] : cnt) {
		mx = max(mx, v);
		if (k == 1 || v % 2 == 0) sm += v;
	}

	cin >> q;

	long long w;
	for (int qi = 0; qi < q; qi++) {
		cin >> w;
		int ans = w ? max(mx, sm) : mx;
		cout << ans << '\n';
	}

}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	sieve();

	cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}
