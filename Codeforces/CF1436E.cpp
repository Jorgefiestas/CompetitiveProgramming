#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, a[N], lst[N];

struct SegTree {
	vector<int> st;

	SegTree(int n): st(4 * n, 0) {}

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
		st[v] = min(st[v * 2], st[v * 2 + 1]);
	}

	int query(int v, int tl, int tr, int k) {
		if (tl == tr) {
			return tl;
		}
		int tm = (tl + tr) / 2;
		if (st[v * 2] < k) {
			return query(v * 2, tl, tm, k);
		}
		return query(v * 2 + 1, tm + 1, tr, k);
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	SegTree st(n + 2);

	set<int> mex;

	for (int i = 1; i <= n; i++) {
		if (lst[a[i]] + 1 < i) {
			int mx = st.query(1, 1, n + 1, lst[a[i]] + 1);
			mex.insert(mx);
		}

		st.update(1, 1, n + 1, a[i], i);
		lst[a[i]] = i;
	}

	for (int x = 0; x <= n + 1; x++) {
		if (lst[x] == n) continue;
		int mx = st.query(1, 1, n + 1, lst[x] + 1);
		mex.insert(mx);
	}

	int ans = 1;
	for (auto mx : mex) {
		if (mx == ans) ans++;
	}

	cout << ans << '\n';

	return 0;
}
