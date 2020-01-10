#include <bits/stdc++.h> 
using namespace std;
const int N = 10000000;
int t, n, st[4 * N + 5];
bool lazy[4 * N + 1];
unordered_set<int> cnt;

void push(int v) {
	if(lazy[v]) {
		st[v * 2] = st[v];
		lazy[v * 2] = true;

		st[v * 2 + 1] = st[v];
		lazy[v * 2 + 1] = true;

		lazy[v] = false;
	}
}

void update(int v, int tl, int tr, int l, int r, int val) {
	if (l > r) {
		return;
	}
	if (tl == l && tr == r) {
		st[v] = val;
		lazy[v] = true;
	}
	else {
		push(v);
		int tm = (tl + tr) /  2;
		update(v * 2, tl, tm, l, min(tm, r), val);
		update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, val);
	}
}

void count(int v, int tl, int tr) {
	if (lazy[v]) {
		cnt.insert(st[v]);
		return;
	}
	int tm = (tl + tr) /  2;
	count(v * 2, tl, tm);
	count(v * 2 + 1, tm + 1, tr);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> t;

	while (t--) {
		cnt.clear();
		memset(st, 0, sizeof st);
		memset(lazy, 0, sizeof lazy);

		lazy[1] = true;

		cin >> n;
		int l, r;
		for (int i = 1; i <= n; i++) {
			cin >> l >> r;
			update(1, 0, N - 1, l - 1, r - 1, i);
		}
		count(1, 0, N - 1);
		int ans = cnt.count(0) ? cnt.size() - 1 : cnt.size();
		cout << ans << endl;
	}

	return 0;
}
