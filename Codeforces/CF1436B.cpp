#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;

	vector<int> ans(n, 0);
	ans[0] = 4;
	ans[1] = 1;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << ans[(i + j) % n] << ' ';
		}
		cout << '\n';
	}
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
