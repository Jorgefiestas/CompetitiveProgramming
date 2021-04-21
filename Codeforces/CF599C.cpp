#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, h[N], to[N];

struct SegTree {
	vector<int> st;

	SegTree(int n): st(4 * n, 0) {};

	void update(int v, int tl, int tr, int idx, int val) {
		if (tl == tr) {
			st[v] = val;
			return;
		}
		int tm = (tl + tr) / 2;
		if (idx <= tm) {
			update(v * 2, tl, tm, idx, val);
		}
		else {
			update(v * 2 + 1, tm + 1, tr, idx, val);
		}
		st[v] = max(st[v * 2], st[v * 2 + 1]);
	}

	int query(int v, int tl, int tr, int k) {
		if (tl == tr) {
			return tl;
		}

		int tm = (tl + tr) / 2;
		if (st[v * 2] > k) {
			return query(v * 2, tl, tm, k);
		}
		if (st[v * 2 + 1] > k) {
			return query(v * 2 + 1, tm + 1, tr, k);
		}

		return -1;
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	SegTree st(n + 1);

	for (int i = 1; i <= n; i++) {
		cin >> h[i];
	}

	for (int i = 1; i <= n; i++) {
		st.update(1, 1, n, i, h[i]);
		int j = st.query(1, 1, n, h[i]);
		j = j == -1 ? i : j;
		to[i] = j - 1;
	}

	int ans = 1;
	int nxt = n - 1;
	for (int i = n; i > 0; i--) {
		if (i == nxt) {
			ans++;
			nxt--;
		}
		nxt = min(nxt, to[i]);
	}

	cout << ans << '\n';

	return 0;
}
