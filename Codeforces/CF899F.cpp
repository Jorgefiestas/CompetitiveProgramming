#include <bits/stdc++.h>
using namespace std;
using pic = pair<int, char>;
const int N = 2e5 + 10;
int n, m;
string str;
set<int> st[256];

struct SegmentTree {
	int st[4 * N];

	void update(int v, int tl, int tr, int idx) {
		if (tl == tr) {
			st[v] += 1;
			return;
		}
		int tm = (tl + tr) / 2;
		if (idx <= tm) {
			update(v * 2, tl, tm, idx);
		}
		else {
			update(v * 2 + 1, tm + 1, tr, idx);
		}
		st[v] = st[v * 2] + st[v * 2 + 1];
	}

	int query(int v, int tl, int tr, int x) {
		if (tl == tr) {
			return tl;
		}
		int tm = (tl + tr) / 2;
		if (tm - st[v * 2] >= x) {
			return query(v * 2, tl, tm, x);
		}
		return query(v * 2 + 1, tm + 1, tr, x + st[v * 2]);
	}
};

SegmentTree seg;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	cin >> str;

	for (int i = 0; i < n; i++) {
		st[str[i]].insert(i + 1);
	}

	char c;
	int l, r;

	for (int i = 0; i < m; i++) {
		cin >> l >> r >> c;

		l = seg.query(1, 1, n, l);
		r = seg.query(1, 1, n, r);

		auto it = st[c].lower_bound(l);

		while (it != st[c].end() && *it <= r) {
			seg.update(1, 1, n, *it);
			it = next(it);
			st[c].erase(prev(it));
		}
	}

	set<pic> ans;

	for (int i = 0; i < 256; i++) {
		for (int x : st[i]) {
			ans.insert({x, i});
		}
	}

	for (auto [i, c] : ans) {
		cout << c;
	}
	cout << '\n';

	return 0;
}
