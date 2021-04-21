#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int N = 1e6 + 10;
int n, m;
vector<int> add[N], rem[N];
vector<pii> query[N];

struct ST {
	int st[4 * N];

	ST() {
		memset(st, 0, sizeof st);
	}

	void update(int v, int tl, int tr, int idx, int val) {
		if (tl == idx && tl == tr) {
			st[v] += val;
			return;
		}
		int tm = (tl + tr) / 2;
		if (idx <= tm) {
			update(v * 2, tl, tm, idx, val);
		}
		else {
			update(v * 2 + 1, tm + 1, tr, idx, val);
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
		int tm = (tl + tr) / 2;
		int ql = query(v * 2, tl, tm, l, min(r, tm));
		int qr = query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
		return ql + qr;
	}
};
ST st;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	long long ans = 1;

	int lx, rx, y;
	for (int i = 0; i < n; i++) {
		cin >> y >> lx >> rx;
		add[lx].emplace_back(y);
		rem[rx].emplace_back(y);
		if (lx == 0 && rx == 1000000) {
			ans += 1;
		}
	}

	int x, ly, ry;
	for (int i = 0; i < m; i++) {
		cin >> x >> ly >> ry;
		query[x].push_back({ly, ry});
		if (ly == 0 && ry == 1000000) {
			ans += 1;
		}
	}
	
	for (int i = 0; i < N; i++) {
		for (int h : add[i]) {
			st.update(1, 0, N, h, 1);
		}

		for (pii q : query[i]) {
			ans += (long long) st.query(1, 0, N, q.first, q.second);
		}

		for (int h : rem[i]) {
			st.update(1, 0, N, h, -1);
		}
	}

	cout << ans << '\n';

	return 0;
}
