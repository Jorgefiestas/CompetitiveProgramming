#include <bits/stdc++.h>
using namespace std;
const int N = 19;
int n;
long long a[N];
unordered_map<int, unordered_map<int, long long>> mem[N][N];
unordered_map<int, unordered_map<int, bool>> vis[N][N];

long long dp(int i, long long xi, int j, long long xj) {
	if (j - i + 1 <= 2) {
		return 0;
	}
	if (vis[i][j][xi][xj]) {
		return mem[i][j][xi][xj];
	}
	vis[i][j][xi][xj] = true;

	long long ans = LLONG_MAX;
	for (int m = i + 1; m < j; m++) {
		ans = min(ans, dp(i, xi, m, xi + xj) + dp(m, xi + xj, j, xj) + a[m] * (xi + xj));
	}

	return mem[i][j][xi][xj] = ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	cout << dp(0, 1, n - 1, 1) + a[0] + a[n - 1] << '\n';

	return 0;
}
