#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 100;
int n, m, L[N], R[N];
vector<int> open[N], close[N];
long long val[N];

long long st[4 * N], lazy[4 * N];

void push(int v) {
	st[v * 2] += lazy[v];
	lazy[v * 2] += lazy[v];
	st[v * 2 + 1] += lazy[v];
	lazy[v * 2 + 1] += lazy[v];
	lazy[v] = 0;
}

long long query(int v, int tl, int tr, int l, int r) {
	if (l > r) {
		return LLONG_MIN;
	}
	if (tl == l && tr == r) {
		return st[v];
	}
	push(v);
	int m = (tl + tr) / 2;
	long long ql = query(v * 2, tl, m, l, min(m, r));
	long long qr = query(v * 2 + 1, m + 1, tr, max(l, m + 1), r);
	return max(ql, qr);
}

void update(int v, int tl, int tr, int l, int r, long long val) {
	if (l > r) {
		return;
	}
	if (tl == l && tr == r) {
		st[v] += val;
		lazy[v] += val;
		return;
	}
	push(v);
	int m = (tl + tr) / 2;
	update(v * 2, tl, m, l, min(m, r), val);
	update(v * 2 + 1, m + 1, tr, max(l, m + 1), r, val);
	st[v] = max(st[v * 2], st[v * 2 + 1]);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	int l, r;
	for (int i = 1; i <= m; i++) {
		cin >> l >> r >> val[i];
		l--, r--;
		L[i] = l;
		R[i] = r;
		open[l].emplace_back(i);
		close[r + 1].emplace_back(i);
	}

	long long active = 0;
	for (int i = 0; i < n; i++) {
		for (int p : close[i]) {
			int l = L[p];
			int r = R[p];
			active -= val[p];
			update(1, 0, n, l, r, +val[p]);
		}

		long long opt = active + max(0LL, query(1, 0, n, 0, i - 1));

		for (int p : open[i]) {
			int l = L[p];
			int r = R[p];
			opt += val[p];
			active += val[p];
			update(1, 0, n, l, r, -val[p]);
		}

		update(1, 0, n, i, i, opt);
	}

	for (int p : close[n]) {
		int l = L[p];
		int r = R[p];
		active -= val[p];
		update(1, 0, n, l, r, val[p]);
	}

	cout << max(query(1, 0, n, 0, n - 1), 0LL) << '\n';

	return 0;
}
