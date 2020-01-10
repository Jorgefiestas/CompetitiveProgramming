#include <bits/stdc++.h>
using namespace std;
const int N = 30000;
int n, q, arr[N + 5];
vector<int> st[4 * N + 5];

void build(int v, int tl, int tr) {
	if (tl == tr) {
		st[v].resize(1);
		st[v][0] = arr[tl];
	}
	else {
		int tm = (tl + tr) / 2;
		build(v * 2, tl, tm);
		build(v * 2 + 1, tm + 1, tr);
		st[v].resize(tr - tl + 1);
		merge(st[v * 2].begin(), st[v * 2].end(), st[v * 2 + 1].begin(), st[v * 2 + 1].end(), st[v].begin());
	}
}

int query(int v, int tl, int tr, int l, int r, int k) {
	if (l > r) {
		return 0;
	}
	if (tl == l && tr == r) {
		return distance(upper_bound(st[v].begin(), st[v].end(), k), st[v].end());
	}
	int tm = (tl + tr) / 2;
	int lq = query(v * 2, tl, tm, l, min(tm, r), k);
	int rq = query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, k);
	return lq + rq;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	build(1, 0, n - 1);

	cin >> q;
	int a, b, c;
	int la = 0;
	for (int i = 0; i < q; i++) {
		cin >> a >> b >> c;
		a ^= la;
		b ^= la;
		c ^= la;

		if (a < 1) {
			a = 1;
		}
		if (b > n) {
			b = n;
		}
		
		la = query(1, 0, n - 1, a - 1, b - 1, c);
		cout << la << endl;
	}

	return 0;
}
