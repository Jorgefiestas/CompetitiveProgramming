#include <bits/stdc++.h>
using namespace std;
const int N = 1e6;

struct SegmentTree {
	int st[4 * N];
	int lazy[4 * N];

	void build(int v, int tl, int tr, int a[]) {
		if (tl == tr) {
			st[v] = a[tl];
			return;
		}
		int m = (tl + tr) / 2;
		build(v * 2, tl, m, a[]);
		build(v * 2 + 1, m + 1, tr, a[]);
		st[v] = st[v * 2] + st[v * 2 + 1];
	}

	void push(int v, int tl, int tr) {
		int m = (tl + tr) / 2;

		st[2 * v] += lazy[v] * (m - tl + 1);
		st[2 * v + 1] += lazy[v] * (tr - m);

		lazy[2 * v] += lazy[v];
		lazy[2 * v + 1] += lazy[v];

		lazy[v] = 0;
	}

	void update(int v, int tl, int tr, int i, int x) {
		if(tl == tr) {
			st[v] += x;
			return;
		}
		push(v, tl, tr);
		int m = (tl + tr) / 2;
		if (i <= m) {
			update(2 * v, tl, m, i, x);
		}
		else {
			update(2 * v + 1, m + 1, tr, i, x);
		}
		st[v] = st[v * 2] + st[v * 2 + 1];
	}

	int query(int v, int tl, int tr, int l, int r) {
		if (l > r) {
			return 0;
		}
		if (tl == l && tr == r) {
			return st[v];
		}
		push(v, tl, tr);
		int m = (l + r) / 2;
		int ql = query(v * 2, tl, m, l, min(m, r));
		int qr = query(v * 2 + 1, m + 1, tr, max(l, m + 1), r);
		return ql + qr;
	}

	int update(int v, int tl, int tr, int l, int r, int x) {
		if (l > r) {
			return;
		}
		if (tl == l && tr == r) {
			st[v] += x * (tr - tl + 1);
			lazy[v] += x;
			return;
		}
		push(v, tl, tr);
		int m = (l + r) / 2;
		update(v * 2, tl, m, l, min(m, r), x);
		update(v * 2 + 1, m + 1, tr, max(l, m + 1), r, x);
		st[v] = st[v * 2] + st[v * 2 + 1];
	}
};


