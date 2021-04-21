#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, q;
string str;

struct SegmentTree {
	int st[4 * N];

	void update(int v, int tl, int tr, int idx, int x) {
		if (tl == tr) {
			st[v] = (1 << x);
			return;
		}
		int tm = (tl + tr) / 2;
		if (idx <= tm) {
			update(v * 2, tl, tm, idx, x);
		}
		else {
			update(v * 2 + 1, tm + 1, tr, idx, x);
		}
		st[v] = st[v * 2] | st[v * 2 + 1];
	}

	int query(int v, int tl, int tr, int l, int r) {
		if (l > r) {
			return 0;
		}
		if (tl == l && tr == r) {
			return st[v];
		}
		int tm = (tl + tr) / 2;
		int ql = query(v * 2, tl, tm, l, min(r, tm));
		int qr = query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
		return ql | qr;
	}
};

SegmentTree st;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> str;
	n = str.size();

	for (int i = 0; i < n; i++) {
		st.update(1, 1, n, i + 1, str[i] - 'a');
	}

	cin >> q;

	char c;
	int op, pos, l, r;
	for (int qi = 0; qi < q; qi++) {
		cin >> op;

		if (op == 1) {
			cin >> pos >> c;
			st.update(1, 1, n, pos, c - 'a');
		}

		else {
			cin >> l >> r;
			int ans = st.query(1, 1, n, l, r);
			cout << __builtin_popcount(ans) << '\n';
		}
	}

	return 0;
}
