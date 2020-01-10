#include <bits/stdc++.h>
using namespace std;
const int N = 100000;
int n, q, arr[N + 5];
int st[4 * N + 5], lazy[4 * N + 5];
unordered_set<int> primes;
vector<bool> notPrime(10000000);

void sieve() { 
	for (int i = 2; i * i <= 10000000; i++) {
		if (notPrime[i]) {
			continue;
		}
		for (int j = i * i; j <= 10000000; j += i) {
			notPrime[j] = true;
		}
	}
}

bool isPrime(int x) {
	return x <= 10000000 && !notPrime[x];
}

void push(int v, int tl, int tm, int tr) {
	if (lazy[v] != -1) {
		st[v * 2] = isPrime(lazy[v]) ? tm - tl + 1 : 0;
		lazy[v * 2] = lazy[v];
		st[v * 2 + 1] = isPrime(lazy[v]) ? tr - tm : 0;
		lazy[v * 2 + 1] = lazy[v];
	}
	lazy[v] = -1;
}

void build(int v, int tl, int tr) {
	if (tl == tr) {
		lazy[v] = arr[tl];
		if (isPrime(arr[tl])) {
			st[v] = 1;
		}
	}
	else {
		int tm = (tl + tr) / 2;
		build(v * 2, tl, tm);
		build(v * 2 + 1, tm + 1, tr);
		st[v] = st[v * 2] + st[v * 2 + 1];
		lazy[v] = -1;
	}
}

void updateR(int v, int tl, int tr, int l, int r, int val) {
	if (l > r) {
		return;
	}
	if (tl == l && tr == r) {
		st[v] = isPrime(val) ? r - l + 1 : 0;
		lazy[v] = val;
	}
	else {
		int tm = (tl + tr) / 2;
		push(v, tl, tm, tr);
		updateR(v * 2, tl, tm, l, min(r, tm), val);
		updateR(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, val);
		st[v] = st[v * 2] + st[v * 2 + 1];
	}
}

void updateS(int v, int tl, int tr, int idx, int val) {
	if (tl == tr) {
		if (isPrime(lazy[v] + val)) {
			st[v] = 1;
		}
		else {
			st[v] = 0;
		}
		lazy[v] += val;
	}
	else {
		int tm = (tl + tr) / 2;
		push(v, tl, tm, tr);
		if (idx <= tm) {
			updateS(v * 2, tl, tm, idx, val);
		}
		else {
			updateS(v * 2 + 1, tm + 1, tr, idx, val);
		}
		st[v] = st[v * 2] + st[v * 2 + 1];
	}
}

int query(int v, int tl, int tr, int l, int r) {
	if (l > r) {
		return 0;
	}
	if (tl == l && tr == r) {
		return st[v];
	}
	int tm = (tl + tr) / 2;
	push(v, tl, tm, tr);
	int ql = query(v * 2, tl, tm, l, min(tm, r));
	int qr = query(v * 2 + 1, tm + 1, tr, max(tm + 1, l), r);
	return ql + qr;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> q;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sieve();
	build(1, 0, n - 1);

	char qu;
	int l, r, val;
	for (int i = 0; i < q; i++) {
		cin >> qu;
		if (qu == 'Q') {
			cin >> l >> r;
			cout << query(1, 0, n - 1, l - 1, r - 1) << '\n';
		}
		else if (qu == 'A') {
			cin >> val >> l;
			updateS(1, 0, n - 1, l - 1, val);
		}
		else {
			cin >> val >> l >> r;
			updateR(1, 0, n - 1, l - 1, r - 1, val);
		}
	}

	return 0;
}
