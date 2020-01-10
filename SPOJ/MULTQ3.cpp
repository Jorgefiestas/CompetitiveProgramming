#include <bits/stdc++.h>
using namespace std;
const int N = 100000;
int n, q;

struct node {
	int mul[3] = {0, 0 , 0};

	node operator +(node &b) {
		node ans;
		ans.mul[0] = mul[0] + b.mul[0];
		ans.mul[1] = mul[1] + b.mul[1];
		ans.mul[2] = mul[2] + b.mul[2];
		return ans;
	}
	
	void shift(int s){
		int tmul[3];
		
		for (int i = 0; i < 3; i++) {
			tmul[i] = mul[(i + s) % 3];
		}
		for (int i = 0; i < 3; i++) {
			mul[i] = tmul[i];
		}
	}
};

node st[4 * N + 5];
int lazy[4 * N + 5];

void push(int v) {
	st[v * 2].shift(lazy[v]);
	lazy[v * 2] += lazy[v];
	st[v * 2 + 1].shift(lazy[v]);
	lazy[v * 2 + 1] += lazy[v];
	lazy[v] = 0;
}

void build(int v, int tl, int tr) {
	if (tl == tr) {
		st[v].mul[0] = 1;
	}
	else {
		int tm = (tl + tr) / 2;
		build(v * 2, tl, tm);
		build(v * 2 + 1, tm + 1, tr);
		st[v] = st[v * 2] + st[v * 2 + 1];
	}
}

void update(int v, int tl, int tr, int l, int r) {
	if (l > r) {
		return;
	}
	if (tl == l && tr == r) {
		st[v].shift(1);
		lazy[v]++;
	}
	else {
		push(v);
		int tm = (tl + tr) / 2;
		update(v * 2, tl, tm, l, min(r, tm));
		update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
		st[v] = st[v * 2] + st[v * 2 + 1];
	}
}

int query(int v, int tl, int tr, int l, int r) {
	if (l > r) {
		return 0;
	}
	if (tl == l && tr == r) {
		return st[v].mul[0];
	}
	push(v);
	int tm = (tl + tr) / 2;
	int ql = query(v * 2, tl, tm, l, min(tm, r));
	int qr = query(v * 2 + 1, tm + 1, tr, max(tm + 1, l), r);
	return ql + qr;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> q;

	build(1, 0, n - 1);

	int qu, l, r;
	for (int i = 0; i < q; i++) {
		cin >> qu >> l >> r;
		if (qu) {
			cout << query(1, 0, n - 1, l, r) << '\n';
		}
		else {
			update(1, 0, n - 1, l, r);
		}
	}

	return 0;
}
