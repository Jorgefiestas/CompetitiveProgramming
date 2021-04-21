#include <bits/stdc++.h>
using namespace std;

int solve() {
	int n, c;
	cin >> n >> c;

	vector<int> a(n + 1), b(n);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i < n; i++) {
		cin >> b[i];
	}

	int ans = 1e9;
	int rem = 0;
	int days = 0;

	for (int i = 1; i <= n; i++) {
		if (days >= ans) break;
		ans = min(ans, days + (c - rem + a[i] - 1) / a[i]);

		int d = max(0, (b[i] - rem + a[i] - 1) / a[i]);
		rem = rem - b[i] + d * a[i];
		days += d + 1;
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	while (t--) {
		cout << solve() << '\n';
	}

	return 0;
}
