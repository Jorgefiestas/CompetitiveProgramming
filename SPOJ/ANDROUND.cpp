#include <bits/stdc++.h>
using namespace std;
int st[240005];
int T, n, k, arr[60000];

void build(int v, int l, int r) {
	if (l == r) {
		st[v] = arr[l];
	}
	else {
		int m = (r + l) / 2;
		build(v * 2, l, m);
		build(v * 2 + 1, m + 1, r);
		st[v] = st[v * 2] & st[v * 2 + 1];
	}
}

int query(int v, int tl, int tr, int l, int r) {
	if (l > r) {
		return INT_MAX;
	}
	if (tl == l && tr == r) {
		return st[v];
	}
	int tm = (tr + tl) / 2;
	int ql = query(v * 2, tl, tm, l, min(r, tm));
	int qr = query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
	return ql & qr;
}

void solve() {
	cin >> n >> k;
	
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		arr[i + n] = arr[i];
		arr[i + 2 * n] = arr[i];
	}

	build(1, 0, 3 * n - 1);

	k = min(k, n);
	for(int i = n; i < 2 * n; i++) {
		cout << query(1, 0, n * 3 - 1, i - k, i + k) << ' ';
	}
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	while (T--) {
		solve();
	}

	return 0;
}
