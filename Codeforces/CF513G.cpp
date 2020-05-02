#include <bits/stdc++.h>
using namespace std;
using ld = long double;
const int N = 105;
int n, k, a[N];
ld dp[N][N], dp2[N][N], pref[N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	if (k > 1000) {
		k = 1000;
	}

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			dp[i][j] = 1;
		}
	}

	ld p = (ld) n * (n + 1) / 2.0;

	for (int m = 1; m <= k; m++) {
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				dp2[i][j] = (j - i - 1) * (j - i);
				dp2[i][j] += (i + 1) * i;
				dp2[i][j] += (n - j) * (n - j - 1);
				dp2[i][j] *= dp[i][j] / 2.0;

				for (int sum = j; sum <= n + i - 1; sum++) {
					int start = max(sum - n + 1, 0);
					int end = min(i, sum - j);
					dp2[i][j] += (ld) (1.0 - dp[sum - j][sum - i]) * (end - start + 1);
				}

				for (int sum = i; sum <= i + j - 1; sum++) {
					int start = max(sum - j + 1, 0);
					int end = min(i, sum - i);
					dp2[i][j] += (ld) (dp[sum - i][j]) * (end - start + 1);
				}

				for (int sum = i + j + 1; sum <= n + j - 1; sum++) {
					int start = max(i + 1, sum - n + 1);
					int end = min(j, sum - j);
					dp2[i][j] += (ld) (dp[i][sum - j]) * (end - start + 1);
				}

				dp2[i][j] /= p;
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				dp[i][j] = dp2[i][j];
			}
		}
	}

	ld ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i] < a[j]) {
				ans += 1.0 - dp[i][j];
			}
			else {
				ans += dp[i][j];
			}
		}
	}
	
	cout << setprecision(15) << ans << '\n';

	return 0;
}
