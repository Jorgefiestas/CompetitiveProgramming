#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 100;
using mii = map<int, int>;
int n, q, st[4 * N];
 
int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a % b);
}
 
void build_st(int v, int tl, int tr) {
	if (tl == tr) {
		cin >> st[v];
		return;
	}
	int m = (tl + tr) / 2;
	build_st(v * 2, tl, m);
	build_st(v * 2 + 1, m + 1, tr);
	st[v] = gcd(st[v * 2], st[v * 2 + 1]);
}

bool explore_node(int v, int tl, int tr, int x) {
	if (tl == tr) { 
		return true;
	}

	int m = (tl + tr) / 2;

	bool lc = st[v * 2] % x == 0;
	bool rc = st[v * 2 + 1] % x == 0;

	if (!lc && !rc) {
		return false;
	}

	if (!lc) {
		lc = explore_node(v * 2, tl, m, x);
	}
	if (!rc) {
		rc = explore_node(v * 2 + 1, m + 1, tr, x);
	}
	
	return lc && rc;
}
 
bool query_st(int v, int tl, int tr, int l, int r, int x, bool &cnt) {
	if (l > r) {
		return 1;
	}
	if (tl == l && tr == r) {
		if (st[v] % x == 0) {
			return true;
		}

		if (!cnt) {
			cnt = true;
			return explore_node(v, tl, tr, x);
		}

		return false;
	}
	int m = (tl + tr) / 2;
	int ql = query_st(v * 2, tl, m, l, min(r, m), x, cnt);
	int qr = query_st(v * 2 + 1, m + 1, tr, max(l, m + 1), r, x, cnt);
	return ql && qr;
}

void update(int v, int tl, int tr, int idx, int x) {
	if (tl == tr && tl == idx) {
		st[v] = x;
		return;
	}
	int m = (tl + tr) / 2;
	if (idx <= m) {
		update(v * 2, tl, m, idx, x);
	}
	else {
		 update(v * 2 + 1, m + 1, tr, idx, x);
	}
	st[v] = gcd(st[v * 2], st[v * 2 + 1]);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	cin >> n;
 
	build_st(1, 1, n);
 
	cin >> q;
 
	int op, li, ri, xi;
	for (int i = 0; i <	q; i++) {
		cin >> op;
 
		if (op == 1) {
			cin >> li >> ri >> xi;
			bool cnt = false;
			if (query_st(1, 1, n, li, ri, xi, cnt)) {
				cout << "YES\n";
			}
			else {
				cout << "NO\n";
			}
		}
		else {
			cin >> li >> xi;
			update(1, 1, n, li, xi);
		}
	}
 
	return 0;
}
