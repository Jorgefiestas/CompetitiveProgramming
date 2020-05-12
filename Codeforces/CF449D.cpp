#include <bits/stdc++.h>
using namespace std;
const int N = (1 << 20) + 100;
const int L = 20;
const int mod = 1e9 + 7;
int n, dp[L + 1][N], cnt[N];

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

int mul(int x, int y) {
	return (long long) x * y % mod;
}

int exp(int x, int y) {
	int ans = 1;
	while (y) {
		if (y & 1) {
			ans = mul(ans, x);
		}
		x = mul(x, x);
		y >>= 1;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	int ai;
	for (int i = 0; i < n; i++) {
		cin >> ai;
		dp[0][ai]++;
	}

	for (int b = 0; b < 20; b++) {
		for (int x = 0; x < N; x++) {
			dp[b + 1][x] = dp[b][x];
			if (!(x & (1 << b)) && x + (1 << b) < N) {
				dp[b + 1][x] += dp[b][x + (1 << b)];
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < N; i++) {
		if (__builtin_popcount(i) % 2) {
			ans = sub(ans, exp(2, dp[20][i]));
		}
		else {
			ans = add(ans, exp(2, dp[20][i]));
		}
	}

	cout << ans << '\n';
	return 0;
}
