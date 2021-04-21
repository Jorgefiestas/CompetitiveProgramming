#include <bits/stdc++.h>
using namespace std;
const int N = 505;
int n, a[N], dp[N][N];
bool vis[N][N], isPal[N][N];

int solve(int l, int r) {
	if (l > r) {
		return 0;
	}
	if (l == r) {
		return 1;
	}
	if (vis[l][r]) {
		return dp[l][r];
	}
	vis[l][r] = true;

	int ans = 1 + solve(l + 1, r);

	if (a[l] == a[l + 1]) {
		int can = 1 + solve(l + 2, r);
		ans = min(can, ans);
	}

	for (int k = l + 2; k <= r; k++) {
		if (a[l] == a[k]) {
			int can = solve(l + 1, k - 1) + solve(k + 1, r);
			ans = min(ans, can);
		}
	}

	return dp[l][r] = ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	cout << solve(1, n) << '\n';

	return 0;
}
