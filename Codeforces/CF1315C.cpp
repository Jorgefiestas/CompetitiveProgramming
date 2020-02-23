#include <bits/stdc++.h>
using namespace std;
const int N = 250;
int t, n, b[N], a[N];
int ft[N];
bool vis[N];

void update(int idx) {
	while (idx <= N) {
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

int nxt(int idx) {
	int l = idx + 1;
	int r = 2 * n;
	
	int ans = -1;
	while (l <= r) {
		int m = (l + r) / 2;

		int num = (m - idx) - (query(m) - query(idx));

		if (num > 0) {
			ans = m;
			r = m - 1;
		}
		if (num == 0) {	
			l = m + 1;
		}
	}

	return ans;
}

void solve() {
	cin >> n;

	bool imp = false;
	for (int i = 0; i < n; i++) {
		cin >> b[i];
		a[2 * i] = b[i];

		update(b[i]);
		if (b[i] > 2 * n || vis[b[i]]) {
			imp = true;
		}
		vis[b[i]] = true;
	}

	if (imp) {
		cout << -1 << '\n';
		return;
	}

	for (int i = 0; i < n; i++) {
		int foll = nxt(b[i]);

		if (foll == -1) {
			cout << -1 << '\n';
			return;
		}

		a[2 * i + 1] = foll;
		update(foll);
	}	

	for (int i = 0; i < 2 * n; i++) {
		cout << a[i] << ' ' ;
	}
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;

	while (t--) {
		memset(vis, 0, sizeof vis);
		memset(ft, 0, sizeof ft);
		solve();
	}

	return 0;
}
