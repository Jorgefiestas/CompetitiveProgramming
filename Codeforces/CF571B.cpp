#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10;
const int K = 5005;
int n, k, a[N];
long long dp[K][K];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	sort(a + 1, a + n + 1);

	int sg = k - n % k;
	int lg = n % k;

	int fl = n / k;
	int cl = fl + 1;

	dp[0][0] = 0;

	for (int i = 0; i <= lg; i++) {
		for (int j = 0; j <= sg; j++) {
			if (i == 0 && j == 0) continue;
			int idx = i * cl + j * fl;

			long long c1 = LLONG_MAX;
			if (i > 0) {
				c1 = dp[i - 1][j] + (long long) abs(a[idx] - a[idx - cl + 1]);
			}

			long long c2 = LLONG_MAX;
			if (j > 0) {
				c2 = dp[i][j - 1] + (long long) abs(a[idx] - a[idx - fl + 1]);
			}

			dp[i][j] = min(c1, c2);
		}
	}

	cout << dp[lg][sg] << '\n';

	return 0;
}
