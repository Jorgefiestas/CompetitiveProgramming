#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int N = 1e6 + 100;
const int mod = 1e9 + 7;
int t, n, p, k[N];
int lazy[4 * (N + 1)];
pii st[4 * (N + 1)];

void push(int v, int m, int tl) {
	if (lazy[v] == -1) return;

	st[v * 2] = {tl, lazy[v]};
	st[v * 2 + 1] = {m + 1, lazy[v]};
	lazy[v * 2] = lazy[v];
	lazy[v * 2 + 1] = lazy[v];

	lazy[v] = -1;
}

pii query(int v, int tl, int tr, int l, int r) {
	if (l > r) {
		return {-1, 0};
	}
	if (tl == l && tr == r) {
		return st[v];
	}
	int m = (tl + tr) / 2;
	push(v, m, tl);
	pii ql = query(2 * v, tl, m, l, min(m, r));
	pii qr = query(2 * v + 1, m + 1, tr, max(m + 1, l), r);

	if (ql.second) {
		return ql;
	}
	return qr;
}

void update(int v, int tl, int tr, int l, int r, int val) {
	if (l > r) {
		return;
	}
	if (tl == l && tr == r) {
		lazy[v] = val;
		st[v] = {tl, val};
		return;
	}
	int m = (tl + tr) / 2;
	push(v, m, tl);
	update(2 * v, tl, m, l, min(m, r), val);
	update(2 * v + 1, m + 1, tr, max(m + 1, l), r, val);
	if (st[v * 2].second) {
		st[v] = st[v * 2];
	}
	else {
		st[v] = st[v * 2 + 1];
	}
}

int add(int x, int y) {
	if (x + y >= mod) {
		return x + y - mod;
	}
	return x + y;
}

int sub(int x, int y) {
	if (x - y < 0) {
		return x - y + mod;
	}
	return x - y;
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

int solve() {
	update(1, 0, N, 0, N, 0);
	cin >> n >> p;

	for (int i = 0; i < n; i++) {
		cin >> k[i];
	}

	if (p == 1) {
		return n % 2;
	}

	sort(k, k + n, greater<int>());

	int ans = 0;
	for (int i = 0; i < n; i++) {
		int e = k[i];
		pii curr = query(1, 0, N, e, e);
		if (!curr.second) {
			pii lft = query(1, 0, N, e + 1, N);
			if (!lft.second) {
				update(1, 0, N, e, e, 1);
				ans = add(ans, exp(p, e));
			}
			else {
				update(1, 0, N, lft.first, lft.first, lft.second - 1);
				update(1, 0, N, e, lft.first - 1, p - 1);
				ans = sub(ans, exp(p, e));
			}
			continue;
		}
		ans = sub(ans, exp(p, e));
		update(1, 0, N, e, e, curr.second - 1);
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		cout << solve() << '\n';
	}

	return 0;
}
