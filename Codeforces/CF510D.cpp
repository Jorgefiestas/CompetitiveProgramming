#include <bits/stdc++.h>
using namespace std;
const int N = 305;
const int D = 300 * 1005;
int n, l[N], c[N];
map<int, int> dp;

int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a % b);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> l[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> c[i];
	}

	for (int i = 0; i < n; i++) {
		for (auto p : dp) {
			int g = p.first;
			int ng = gcd(g, l[i]);
			if (!dp[ng]) {
				dp[ng] = p.second + c[i];
			}
			else {
				dp[ng] = min(dp[ng], p.second + c[i]);
			}
		}

		if (!dp.count(l[i])) {
			dp[l[i]] = c[i];
		}
		dp[l[i]] = min(dp[l[i]], c[i]);
	}

	if (!dp.count(1)) {
		cout << -1 << '\n';
	}
	else {
		cout << dp[1] << '\n';
	}

	return 0;
}
