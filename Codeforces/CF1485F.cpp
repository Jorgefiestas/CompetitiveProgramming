#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
const int mod = 1e9 + 7;
int n, b[N], cnt0[N], dp[N];
long long pref[N];

int add(int x, int y) {
	if (x + y >= mod) {
		return x + y - mod;
	}
	return x + y;
}

int sub(int x, int y) {
	if (x - y < 0) {
		return x - y + mod;
	}
	return x - y;
}

int solve() {
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> b[i];
	}

	dp[0] = 1;
	cnt0[0] = 1;

	map<long long, int> seen;
	seen[0] = 0;

	long long sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += (long long) b[i];

		cnt0[i] = 0;
		if (seen.count(sum)) {
			cnt0[i] = dp[seen[sum]];
		}

		seen[sum] = i;

		dp[i] = add(dp[i - 1], dp[i - 1]);
		dp[i] = sub(dp[i], cnt0[i - 1]);
	}

	return dp[n];
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
