#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 100;
int n, q, s[N];

int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a % b);
}

struct Node {
	int g = 0;
	int cnt = 0;
};

Node operator+(Node &a, Node &b) {
	Node c;
	c.g = gcd(a.g, b.g);

	if (a.g == c.g) {
		c.cnt += a.cnt;
	}
	if (b.g == c.g) {
		c.cnt += b.cnt;
	}
	return c;
}

Node st[4 * N];

Node query(int v, int tl, int tr, int l, int r) {
	if (l > r) {
		Node empty;
		return empty;
	}
	if (tl == l && tr == r) {
		return st[v];
	}
	int tm = (tl + tr) / 2;
	Node ql = query(v * 2, tl, tm, l, min(r, tm));
	Node qr = query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
	return ql + qr;
}

void build(int v, int tl, int tr) {
	if (tl == tr) {
		st[v].cnt = 1;
		st[v].g = s[tl];
		return;
	}
	int tm = (tl + tr) / 2;
	build(v * 2, tl, tm);
	build(v * 2 + 1, tm + 1, tr);
	st[v] = st[v * 2] + st[v * 2 + 1];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> s[i];
	}
	build(1, 1, n);

	cin >> q;
	
	int li, ri;
	for (int i = 0; i < q; i++) {
		cin >> li >> ri;
		Node ans = query(1, 1, n, li, ri);
		cout << (ri - li + 1) - ans.cnt << '\n';
	}

	return 0;
}
