#include <bits/stdc++.h>
using namespace std;
using  pii = pair<int, int>;
const int N = 105;
int t, n, a[N], depth[N];

void dac(int d, int l, int r) {
	if (l > r)
		return;

	pii mx = {0, -1};

	for (int i = l; i <= r; i++) {
		mx = max(mx, {a[i], i});
	}

	auto [m, idx] = mx;

	depth[idx] = d;
	dac(d + 1, l, idx - 1);
	dac(d + 1, idx + 1, r);
}

void solve() {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	dac(0, 1, n);

	for (int i = 1; i <= n; i++) {
		cout << depth[i] << ' ';
	}
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin  >> t;
	while (t--) {
		solve();
	}

	return 0;
}
