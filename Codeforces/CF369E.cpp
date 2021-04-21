#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int N = 3e5 + 10;
const int A = 1e6 + 10;
int n, m;
vector<int> p[N], q[A], seg[A];
map<pii, int> query;

struct FT {
	int ft[A];
	
	void update(int idx, int x) {
		while (idx < A) {
			ft[idx] += x;
			idx += idx & -idx;
		}
	}

	int query(int idx) {
		int ans = 0;
		while (idx > 0) {
			ans += ft[idx];
			idx -= idx & -idx;
		}
		return ans;
	}
};

FT ft;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	int l, r;
	for (int i = 1; i <= n; i++) {
		cin >> l >> r;
		seg[l].emplace_back(r);
	}

	int sz, x;
	for (int qi = 0; qi < m; qi++) {
		cin >> sz;

		p[qi].push_back(0);
		for (int i = 0; i < sz; i++) {
			cin >> x;
			p[qi].push_back(x);
		}
		p[qi].push_back(1e6  + 1);

		for (int i = 1; i < p[qi].size(); i++) {
			q[p[qi][i - 1] + 1].push_back(p[qi][i] - 1);
		}
	}

	for (int i = 1e6; i > 0; i--) {
		for (int r : seg[i]) {
			ft.update(r, 1);
		}

		for (int r : q[i]) {
			pii idx = {i, r};
			query[idx] = ft.query(r);
		}
	}

	for (int qi = 0; qi < m; qi++) {
		int rem = 0;
		for (int i = 1; i < p[qi].size(); i++) {
			pii qry = {p[qi][i - 1] + 1, p[qi][i] - 1};
			rem += query[qry];
		}

		cout << n - rem << '\n';
	}

	return 0;
}
