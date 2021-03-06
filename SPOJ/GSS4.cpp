#include <bits/stdc++.h>
using namespace std;
const int N = 100000;
int n, q;
long long arr[N + 5];

struct node {
	long long max;
	long long min;
	long long sum;
};

node st[4 * N + 5];
bool lazy[4 * N + 5];

node merge(node &a, node &b) {
	node c;
	c.max = max(a.max, b.max);
	c.min = min(a.min, b.min);
	c.sum = a.sum + b.sum;

	return c;
}

void push(int v, int tl, int tm, int tr) {
	if (lazy[v]) {
		st[v * 2].min = st[v].min;
		st[v * 2].max = st[v].max;
		st[v * 2].sum = (tm - tl + 1) * st[v].max;
		lazy[v * 2] = true;

		st[v * 2 + 1].min = st[v].min;
		st[v * 2 + 1].max = st[v].max;
		st[v * 2 + 1].sum = (tr - tm) * st[v].max;
		lazy[v * 2 + 1] = true;

		lazy[v] = false;
	}
}

void build(int v, int tl, int tr) {
	if (tl == tr) {
		st[v].sum = arr[tl];
		st[v].max = arr[tl];
		st[v].min = arr[tl];
	}
	else {
		int tm = (tl + tr) / 2;
		build(v * 2, tl, tm);
		build(v * 2 + 1, tm + 1, tr);
		st[v] = merge(st[v * 2], st[v * 2 + 1]);
	}
}

void print(int v, int tl, int tr) {
	if (tl == tr) {
		cout << st[v].max << " ";
	}
	else {
		int tm = (tl + tr) / 2;
		push(v, tl, tm, tr);
		print(v * 2, tl, tm);
		print(v * 2 + 1, tm + 1, tr);
	}
}

void update(int v, int tl, int tr, int l, int r) {
	if (l > r) {
		return;
	}
	if (tl == l && tr == r) {
		if (st[v].max == st[v].min) {
			if (st[v].max == 1) {
				return;
			}
			st[v].max = sqrt(st[v].max);
			st[v].min = st[v].max;
			st[v].sum = (tr - tl + 1) * st[v].max;
			lazy[v] = true;
		}
		else {
			int tm = (tl + tr) / 2;
			push(v, tl, tm, tr);
			update(v * 2, tl, tm, tl, tm);
			update(v * 2 + 1, tm + 1, tr, tm + 1, tr);
			st[v] = merge(st[v * 2], st[v * 2 + 1]);
		}	
	}
	else {
		int tm = (tl + tr) / 2;
		push(v, tl, tm, tr);
		update(v * 2, tl, tm, l, min(r, tm));
		update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
		st[v] = merge(st[v * 2], st[v * 2 + 1]);
	}
}

long long query(int v, int tl, int tr, int l, int r) {
	if (l > r) {
		return 0;
	}
	if (tl == l && tr == r) {
		return st[v].sum;
	}
	else {
		int tm = (tl + tr) / 2;
		push(v, tl, tm, tr);
		long long ql = query(v * 2, tl, tm, l, min(r, tm));
		long long qr = query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
		return ql + qr;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int c = 1;
	while (cin >> n) {
		memset(st, 0, sizeof st);
		memset(lazy, 0, sizeof lazy);

		cout << "Case #" << c << ":\n";

		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}

		build(1, 0, n - 1);

		cin >> q;
		int qu, l, r;
		for (int i = 0; i < q; i++) {
			cin >> qu >> l >> r;
			if (l > r) {
				swap(l, r);
			}

			if (qu == 0) {
				update(1, 0, n - 1, l - 1, r - 1);
			}
			else {
				cout << query(1, 0, n - 1, l - 1, r - 1) << '\n';
			}
		}
		c++;
		cout << '\n';
	}
	
	return 0;
}
