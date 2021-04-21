#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int t, n, q, a[N];
long long pref[N];
set<long long> seen;

long long sum(int l, int r) {
	return pref[r] - pref[l - 1];
}

void dac(int l, int r) {
	if (l > r) return;

	seen.insert(sum(l, r));
	if (a[l] == a[r]) return;

	int mid = (a[r] + a[l]) / 2;

	int m = upper_bound(a + 1, a + n + 1, mid) - a;
	dac(l, m - 1);
	dac(m, r);
}

void solve() {
	cin >> n >> q;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);

	for (int i = 1; i <= n; i++) {
		pref[i] = pref[i - 1] + (long long) a[i];
	}

	dac(1, n);

	long long si;
	for (int qi = 0; qi < q; qi++) {
		cin >> si;

		if (seen.count(si)) {
			cout << "Yes\n";
		}
		else {
			cout << "No\n";
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		seen.clear();
		solve();
	}

	return 0;
}
