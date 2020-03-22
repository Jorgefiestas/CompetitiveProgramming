#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, h[N];
long long a[N], st[4 * N];

void update_st(int v, int tl, int tr, int idx, long long val) {
	if (tl == tr && tl == idx) {
		st[v] = max(st[v], val);
		return;
	}
	int m = (tl + tr) / 2;
	if (idx <= m) {
		update_st(v * 2, tl, m, idx, val);
	}
	else {
		update_st(v * 2 + 1, m + 1, tr, idx, val);
	}
	st[v] = max(st[v * 2], st[v * 2 + 1]);
}

long long query_st(int v, int tl, int tr, int l, int r) {
	if (l > r) {
		return 0;
	}
	if (tl == l && tr == r) {
		return st[v];
	}
	int m = (tl + tr) / 2;
	long long ql = query_st(v * 2, tl, m, l, min(r, m));
	long long qr = query_st(v * 2 + 1, m + 1, tr, max(l, m + 1), r);
	return max(ql, qr);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> h[i];
		h[i]--;
	}
	
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < n; i++) {
		long long tans = a[i] + query_st(1, 0, n, 0, h[i]);
		update_st(1, 0, n, h[i], tans);
	}

	cout << query_st(1, 0, n, 0, n) << '\n';

	return 0;
}
