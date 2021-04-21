#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 200;
int t, n, dp[N];
string str;

int cost(int i, string s) {
	int c = 0;
	for (int j = 0; j < s.size(); j++) {
		if (s[j] == str[i + j]) continue;
		c += 1;
	}

	return c;
}

int calc() {
	for (int i = 0; i < n + 100; i++) {
		dp[i] = N;
	}

	dp[0] = 0;
	for (int i = 0; i < n; i++) {
		if (i >= N) continue;
		dp[i + 2] = min(dp[i + 2], dp[i] + cost(i, "RL"));
		dp[i + 3] = min(dp[i + 3], dp[i] + cost(i, "RLL"));
		dp[i + 3] = min(dp[i + 3], dp[i] + cost(i, "RRL"));
		dp[i + 4] = min(dp[i + 4], dp[i] + cost(i, "RRLL"));
	}

	return dp[n];
}

int solve() {
	cin >> n >> str;
	str += "0000";

	int ans = calc();
	rotate(str.begin(), str.begin() + 1, str.begin() + n);
	ans = min(ans, calc());
	rotate(str.begin(), str.begin() + 1, str.begin() + n);
	ans = min(ans, calc());
	rotate(str.begin(), str.begin() + 1, str.begin() + n);
	ans = min(ans, calc());

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
