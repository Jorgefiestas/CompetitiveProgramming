#include <bits/stdc++.h>
using namespace std;
int st[400050];
int T, n, q, arr[100005];

void build(int v, int l, int r) {
	if (l == r) {
		st[v] = arr[l];
	}
	else {
		int m = (r + l) / 2;
		build(v * 2, l, m);
		build(v * 2 + 1, m + 1, r);
		st[v] = min(st[v * 2], st[v * 2 + 1]);
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
	return min(ql, qr);
}
	
void solve () {
	cin >> n >> q;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	build(1, 0, n - 1);

	int l, r;
	for (int i = 0; i < q; i++) {
		cin >> l >> r;
		l--, r--;
		cout << query(1, 0, n - 1, l, r) << "\n";
	}
}
	
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;

	for (int i = 1; i <= T; i++) {
		cout << "Scenario #" << i << ":\n";
		solve();
	}

	return 0;
}
