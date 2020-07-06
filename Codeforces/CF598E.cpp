#include <bits/stdc++.h>
using namespace std;
const int N = 55;
int t, mem[N][N][N];
bool vis[N][N][N];

int dp(int n, int m, int k) {
	if (vis[n][m][k]) {
		return mem[n][m][k];
	}
	vis[n][m][k] = true;

	if (n * m == k || k == 0) {
		return mem[n][m][k] = 0;
	}
	if (n * m < k) {
		return mem[n][m][k] = 5e8;
	}

	int can1 = 5e8;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= k; j++) {
			int temp = dp(i, m, j) + dp(n - i, m, k - j);
			can1 = min(can1, temp);
		}
	}
	can1 += m * m;

	int can2 = 5e8;
	for (int i = 1; i < m; i++) {
		for (int j = 0; j <= k; j++) {
			int temp = dp(n, i, j) + dp(n, m - i, k - j);
			can2 = min(can2, temp);
		}
	}
	can2 += n * n;

	return mem[n][m][k] = min(can1, can2);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;

	int n, m, k;
	while (t--) {
		cin >> n >> m >> k;
		cout << dp(n, m, k) << '\n';
	}

	return 0;
}
