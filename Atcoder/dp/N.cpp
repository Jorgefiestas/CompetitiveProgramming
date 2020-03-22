#include <bits/stdc++.h>
using namespace std;
const int N = 405;
int n, a[N];
long long sum[N], mem[N][N];
bool vis[N][N];

long long dp(int i, int j) {
	if (i == j) {
		return 0;
	}
	if (vis[i][j]) {
		return mem[i][j];
	}
	vis[i][j] = true;

	long long ans = LLONG_MAX;
	for (int m = i; m < j; m++) {
		ans = min(ans, dp(i, m) + dp(m + 1, j));
	}

	long long cost = sum[j] - sum[i - 1];
	return mem[i][j] = cost + ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum[i] = sum[i - 1] + a[i];
	}

	cout << dp(1, n) << '\n';

	return 0;
}
