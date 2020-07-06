#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 100;
int t, n, s[N];
int dp[N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		memset(dp, 0, sizeof dp);

		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> s[i];
		}

		for (int i = n; i > 0; i--) {
			for (int j = 2 * i; j <= n; j += i) {
				if (s[i] >= s[j]) continue;
				dp[i] = max(dp[i], dp[j]);
			}
			dp[i]++;
		}

		cout << *max_element(dp, dp + n + 1) << '\n';
	}

	return 0;
}
