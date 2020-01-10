#include <bits/stdc++.h>
using namespace std;
int n, m, q[3], arr[200005];
long long lazy[800005], st[800005];

void push(int v) {
	st[v * 2] += lazy[v];
	lazy[v * 2] += lazy[v];
	st[v * 2 + 1] += lazy[v];
	lazy[v * 2 + 1] += lazy[v];
	lazy[v] = 0;
}

long long query(int v, int tl, int tr, int l, int r) {
	if (l > r) {
		return INT_MAX;
	}
	if (tl == l && tr == r) {
		return st[v];
	}
	push(v);
	int tm = (tl + tr) / 2;
	long long q1 = query(v * 2, tl, tm, l, min(tm, r));
	long long q2 = query(v * 2 + 1, tm + 1, tr, max(tm + 1, l), r);
	return min(q1, q2);
}

void update(int v, int tl, int tr, int l, int r, int val) {
	if (l > r) {
		return;
	}
	if (tl == l && tr == r) {
		st[v] += val;
		lazy[v] += val;
	}
	else {
		push(v);
		int tm = (tl + tr) / 2;
		update(v * 2, tl, tm, l, min(tm, r), val);
		update(v * 2 + 1, tm + 1, tr, max(tm + 1, l), r, val);
		st[v] = min(st[v * 2], st[v * 2 + 1]);
	}
}

void build(int v, int l, int r) {
	if (l == r) {
		st[v] = arr[l];
	}
	else {
		int m = (r + l) / 2;
		build(v * 2, l, m);
		build(v * 2 + 1, m + 1, r);
		st[v] = min(st[v * 2], st[v * 2 + 1]);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	
	build(1, 0, n - 1);
	
	string line;

	cin >> m;
	getline(cin, line);
	for (int i = 0; i < m; i++) {
		getline(cin, line);
		stringstream ss(line);
		int j = 0;
		while (ss >> q[j]) {
			j++;
		}

		if (j == 2) {
			if (q[0] <= q[1]) {
				cout << query(1, 0, n - 1, q[0], q[1]) << '\n';
			}
			else {
				cout << min(query(1, 0, n - 1, q[0], n - 1), query(1, 0, n - 1, 0, q[1])) << '\n';
			}
		}
		else {
			if (q[0] <= q[1]) {
				update(1, 0, n - 1, q[0], q[1], q[2]);
			}
			else {
				update(1, 0, n - 1, q[0], n - 1, q[2]);
				update(1, 0, n - 1, 0, q[1], q[2]);
			}
		}
	}

	return 0;
}
