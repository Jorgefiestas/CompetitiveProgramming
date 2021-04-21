#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int N = 1e5 + 100;
int n, q, a[N], prv[N], res[N];
map<int, int> lst;
vector<pii> queries[N];

struct SegmentTree {
	long long st[4 * N];
	long long best[4 * N];
	long long lazy[4 * N];
	long long bestlazy[4 * N];

	void push(int v) {
		for (int c = v * 2; c <= v * 2 + 1; c++) {
			bestlazy[c] = max(bestlazy[c], lazy[c] + bestlazy[v]);
			lazy[c] += lazy[v];
			best[c] = max(best[c], st[c] + bestlazy[v]);
			st[c] += lazy[v];
		}

		lazy[v] = 0;
		bestlazy[v] = 0;
	}

	void update(int v, int tl, int tr, int l, int r, long long val) {
		if (l > r) {
			return;
		}
		if (tl == l && tr == r) {
			st[v] += val;
			lazy[v] += val;
			best[v] = max(best[v], st[v]);
			bestlazy[v] = max(bestlazy[v], lazy[v]);
			return;
		}
		push(v);
		int m = (tl + tr) / 2;
		update(v * 2, tl, m, l, min(m, r), val);
		update(v * 2 + 1, m + 1, tr, max(m + 1, l), r, val);
		st[v] = max(st[v * 2], st[v * 2 + 1]);
		best[v] = max(best[v * 2], best[v * 2 + 1]);
	}

	long long query(int v, int tl, int tr, int l, int r) {
		if (l > r) {
			return 0;
		}
		if (tl == l && tr == r) {
			return best[v];
		}
		push(v);
		int m = (tl + tr) / 2;
		int ql = query(v * 2, tl, m, l, min(m, r));
		int qr = query(v * 2 + 1, m + 1, tr, max(m + 1, l), r);
		return max(ql, qr);
	}
};

SegmentTree st;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		prv[i] = lst[a[i]];
		lst[a[i]] = i;
	}

	cin >> q;

	int ql, qr;
	for (int i = 0; i < q; i++) {
		cin >> ql >> qr;
		queries[qr].push_back({ql, i});
	}

	for (int i = 1; i <= n; i++) {
		st.update(1, 1, n, prv[i] + 1, i, a[i]);

		sort(queries[i].begin(), queries[i].end());
		for (auto [l, idx] : queries[i]) {
			res[idx] = st.query(1, 1, n, l, i);
		}
	}

	for (int i = 0; i < q; i++) {
		cout << res[i] << '\n';
	}

	return 0;
}
