#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, k, a[N];
int st[4 * N];

int mul(int a, int b) {
	return (long long) a * b % k;
}

void st_build(int v, int tl, int tr) {
	if (tl == tr) {
		cin >> st[v];
		st[v] = st[v] % k;
		return;
	}
	int m = (tl + tr) / 2;
	st_build(v * 2, tl, m);
	st_build(v * 2 + 1, m + 1, tr);
	st[v] = mul(st[v * 2], st[v * 2 + 1]);
}

int st_query(int v, int tl, int tr, int l, int r) {
	if (l > r) {
		return 1;
	}
	if (tl == l && tr == r) {
		return st[v];
	}
	int m = (tl + tr) / 2;
	int ql = st_query(v * 2, tl, m, l, min(m, r));
	int qr = st_query(v * 2 + 1, m + 1, tr, max(m + 1, l), r);
	return mul(ql, qr);
}

int search(int idx) {
	int l = 0;
	int r = idx;

	int ans = -1;
	while (l <= r) {
		int m = (l + r) / 2;
		if (st_query(1, 0, n - 1, m, idx)) {
			r = m - 1;

		}
		else {
			ans = m;
			l = m + 1;
		}
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	st_build(1, 0, n - 1);

	long long ans = 0;
	for (int i = 0; i < n; i++) {
		int fpv = search(i);
		if (fpv == -1) continue;
		
		ans += (long long) fpv + 1;
	}

	cout << ans << '\n';

	return 0;
}
