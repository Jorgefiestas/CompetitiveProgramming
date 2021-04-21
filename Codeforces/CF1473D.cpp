#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int N = 2e5 + 10;
const int K = 20;
int t, n, m, a[N], ans[N];
int mn[N][20], mx[N][K];

int rmnq(int l, int r) {
	if (l > r) 
		return 1e9;
	int j = 31 - __builtin_clz(r - l + 1);
	return min(mn[l][j], mn[r - (1 << j) + 1][j]);
}

int rmxq(int l, int r) {
	if (l > r)
		return -1e9;
	int j = 31 - __builtin_clz(r - l + 1);
	return max(mx[l][j], mx[r - (1 << j) + 1][j]);
}

void solve() {
	cin >> n >> m;

	char ch;
	for (int i = 1; i <= n; i++) {
		cin >> ch;
		a[i] = a[i - 1];
		a[i] += (ch == '+') ? 1 : -1;
	}

	for (int i = 0; i <= n; i++) {
		mn[i][0] = a[i];
		mx[i][0] = a[i];
	}

	for (int j = 1; j < K; j++) {
		for (int i = 0; i + (1 << j) <= n + 1; i++) {
			mn[i][j] = min(mn[i][j - 1], mn[i + (1 << (j -1))][j -1]);
			mx[i][j] = max(mx[i][j - 1], mx[i + (1 << (j -1))][j -1]);
		}
	}

	int l, r;
	for (int qi = 0; qi < m; qi++) {
		cin >> l >> r;

		int sm = a[r] - a[l - 1];
		int mn = min(rmnq(0, l - 1), rmnq(r + 1, n) - sm);
		int mx = max(rmxq(0, l - 1), rmxq(r + 1, n) - sm);
		cout << mx - mn + 1 << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}
