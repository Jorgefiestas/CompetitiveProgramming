#include <bits/stdc++.h>
using namespace std;
int t, n, m;

int solve() {
	cin >> n >> m;

	int ans = 0;
	char move;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> move;
			if (i == n && j == m) continue;
			if (i == n) {
				ans += (move == 'D');
			}
			if (j == m) {
				ans += (move == 'R');
			}
		}
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		cout << solve() << '\n';
	}

	return 0;
}
