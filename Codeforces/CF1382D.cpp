#include <bits/stdc++.h>
using namespace std;
const int N = 4005;
int t, n, p[N];

bool solve() {
	cin >> n;

	for (int i = 0; i < 2 * n; i++) {
		cin >> p[i];
	}

	vector<int> ssum;

	int rem = 2 * n;
	while (rem > 0) {
		int idx = max_element(p, p + rem) - p;
		int size = rem - idx;
		ssum.emplace_back(size);
		rem -= size;
	}

	vector<bool> dp(n + 1, false);
	dp[0] = true;

	for (int x : ssum) {
		for (int s = n; s >= 0; s--) {
			if (!dp[s] || s + x > n) continue;
			dp[s + x] = true;
		}
	}

	return dp[n];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		if (solve()) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}

	return 0;
}
