#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
const int K = 55;
int n, p, k;
bool lft[N], rgt[N];
int dp[N][K][K], dp0[N][K][K];

int count(int arr[], int l, int r) {
	return arr[r] - arr[l - 1];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> p >> k;

	int sz, x;
	cin >> sz;
	for (int i = 0; i < sz; i++) {
		cin >> x;
		lft[x] = 1;
	}
	cin >> sz;
	for (int i = 0; i < sz; i++) {
		cin >> x;
		rgt[x] = 1;
	}

	if (p >= 2 * (n + k - 1) / k) {
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (lft[i] || rgt[i]) {
				cnt++;
			}
		}
		cout << cnt << '\n';
		return 0;
	}

	int ans = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= p; j++) {
			for (int a = 0; a <= k; a++) {
				for (int b = 0; b <= n; b++) {
					if (a == k && b == k && j < 2) continue;
					if (a == k && b == k) {
						dp0[j][k][k] = dp0[j - 2][0][0];
					}
					else if (a == k) {
						dp0[j][k][b] = dp0[j - 1][0][b];
						if (b && rgt[i]) {
							dp0[j][k][b] -= 1;
						}
					}
					else if (b == k) {
						dp0[j][a][k] = dp0[j - 1][a][0];
						if (a && lft[i]) {
							dp0[j][k][a] -= 1;
						}
					}
					else {
						int mx = dp[j][a + 1][b + 1];

						if (a == 0) {
							mx = max(mx, dp[j][0][b + 1]);
						}
						if (b == 0) {
							mx = max(mx, dp[j][a + 1][0]);
						}
						if (a == 0 && b == 0) {
							mx = max(mx, dp[j][0][0]);
						}
						dp0[j][a][b] = mx;
					}

					if ((a && (lft[i])) || (b && rgt[b])) {
						dp0[j][a][b] += 1;
					}
					cout << i << ' ' << j << ' ' << a << ' ' << b << ' ' << dp0[j][a][b] << endl;
					ans = max(ans, dp[j][a][b]);
				}
			}
		}

		for (int j = 1; j <= p; j++) {
			for (int a = 0; a <= k; a++) {
				for (int b = 0; b <= k; b++) {
					dp[j][a][b] = dp0[j][a][b];
				}
			}
		}
	}

	cout << ans << '\n';

	return 0;
}
