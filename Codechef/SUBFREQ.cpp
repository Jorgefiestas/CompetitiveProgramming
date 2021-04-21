#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 100;
const int mod = 1e9 + 7;
int t, n, fact[N], cnt[N], ways[N];
vector<int> have[N];

int add(int x, int y) {
	if (x + y >= mod) {
		return x + y - mod;
	}
	return x + y;
}

int mul(int x, int y) {
	return (long long) x * y % mod;
}

int exp(int x, int y) {
	int ans = 1;
	while (y) {
		if (y & 1) {
			ans = mul(ans, x);
		}
		x = mul(x, x);
		y >>= 1;
	}
	return ans;
}

int inv(int x) {
	return exp(x, mod - 2);
}

struct ST {
	int st[4 * N];

	void clear(int n) {
		build(1, 1, n);
	}

	void build(int v, int tl, int tr) {
		if (tl == tr) {
			st[v] = 1;
			return;
		}
		int tm = (tl + tr) / 2;
		build(v * 2, tl, tm);
		build(v * 2 + 1, tm + 1, tr);
		st[v] = 1;
	}

	int query(int l, int r) {
		return query(1, 1, n, l, r);
	}
	
	int query(int v, int tl, int tr, int l, int r) {
		if (l > r) {
			return 1;
		}
		if (tl == l && tr == r) {
			return st[v];
		}
		int tm = (tl + tr) / 2;
		int ql = query(v * 2, tl, tm, l, min(r, tm));
		int qr = query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
		return mul(ql, qr);
	}

	void update(int idx, int val) {
		update(1, 1, n, idx, val);
	}

	void update(int v, int tl, int tr, int idx, int val) {
		if (tl == tr && tl == idx) {
			st[v] = add(st[v], val);
			return;
		}
		int tm = (tl + tr) / 2;
		if (idx <= tm) {
			update(v * 2, tl, tm, idx, val);
		}
		else {
			update(v * 2 + 1, tm + 1, tr, idx, val);
		}
		st[v] = mul(st[v * 2], st[v * 2 + 1]);
	}
};

ST st;

int choose(int x, int y) {
	if (y > x) {
		return 0;
	}
	return mul(fact[x], inv(mul(fact[y], fact[x - y])));
}

void solve() {
	cin >> n;
	st.clear(n);

	int a, cntmx = 0;
	for (int i = 0; i < n; i++) {
		cin >> a;
		cnt[a] += 1;
		cntmx = max(cnt[a], cntmx);
	}


	for (int a = n; a >= 1; a--) {
		for (int c = 1; c <= cnt[a]; c++) {
			have[c].emplace_back(a);
		}
	}

	for (int c = 1; c <= cntmx; c++) {
		for (int a : have[c]) {
			int rgt = st.query(a + 1, n);
			int lft = st.query(1, a - 1);

			int comb = choose(cnt[a], c);

			int tways = mul(comb, mul(lft, rgt));
			ways[a] = add(ways[a],  tways);

			st.update(a, comb);
		}
	}

	for (int i = 1; i <= n; i++) {
		cout << ways[i] << ' ';
	}
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	fact[0] = 1;
	for (int i = 1; i < N; i++) {
		fact[i] = mul(fact[i - 1], i);
	}

	cin >> t;
	while (t--) {
		for (int i = 0; i <= n; i++) {
			have[i].clear();
			ways[i] = 0;
			cnt[i] = 0;
		}
		solve();
	}

	return 0;
}
