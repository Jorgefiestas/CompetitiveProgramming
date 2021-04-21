#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;

	if (k >= (n + 1) / 2) {
		cout << -1 << '\n';
		return;
	}

	int x = n;

	vector<int> ans(n + 1, 0);
	for (int i = 1; i <= k; i++) {
		ans[2 * i] = x--;
	}
	for (int i = 1; i <= n; i++) {
		if (ans[i]) continue;
		ans[i] = x--;
	}

	for (int i = 1; i <= n; i++) {
		cout << ans[i] << ' ';
	}
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}
