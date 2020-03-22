#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 100;
const long long mod = 1e9 + 7;
int n, k, a[N];
long long dp[N], da[N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	dp[0] = 1;
	for (int i = 0; i < n; i++) {
		memset(da, 0, sizeof da);
		for (int c = k; c >= 0; c--) {
			int l = c + 1;
			int r = min(c + a[i], k);
			da[l] = (da[l] + dp[c]) % mod;
			da[r + 1] = (da[r + 1] + mod - dp[c]) % mod;
		}
		
		long long pref = 0;
		for (int i = 0; i <= k; i++) {
			pref = (pref + da[i]) % mod;
			dp[i] = (dp[i] + pref) % mod;
		}
	}

	cout << dp[k] << endl;

	return 0;
}
