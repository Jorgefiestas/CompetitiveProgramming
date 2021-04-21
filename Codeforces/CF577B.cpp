#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
int n, m, dp[N], dp0[N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	if (n >= m) {
		cout << "YES\n";
		return 0;
	}

	int a;
	for (int i = 0; i < n; i++) {
		cin >> a;
		a %= m;

		for (int x = 0; x < m; x++) {
			if (!dp0[x]) continue;
			dp[(x + a) % m] = true;
		}
		dp[a] = true;

		for (int x = 0; x < m; x++) {
			dp0[x] = dp[x];
		}
	}

	if (dp[0]) {
		cout << "YES\n";
	}
	else {
		cout << "NO\n";
	}

	return 0;
}
