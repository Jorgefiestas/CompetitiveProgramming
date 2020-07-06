#include <bits/stdc++.h>
using namespace std;
const int N = 2005;
const int mod = 1e9 + 7;
int n, m, d, lower[N], upper[N];
int dp[N][N][3];

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

int F(int a[N]) {
	memset(dp, 0, sizeof dp);

	if (n % 2 == 0) {
		dp[n][d % m][0]++;
		if (d <= a[n]) {
			dp[n][d % m][1]++;
		}
	}
	else {
		for (int i = 0; i <= 9; i++) {
			if (i == d) continue;
			dp[n][i % m][0]++;
		}

		for (int i = 0; i <= a[n]; i++) {
			if (i == d) continue;
			dp[n][i % m][1]++;
		}
	}

	int p10 = 10 % m;
	for (int i = n - 1; i >= 1; i--) {
		for (int md = 0; md < m; md++) {
			if (i % 2 == 0) {
				int nm = (m + (md - d * p10) % m) % m;
				dp[i][md][0] = dp[i + 1][nm][0];

				if (d <= a[i]) {
					dp[i][md][1] = (d == a[i]) ? dp[i + 1][nm][1] : dp[i + 1][nm][0];
				}
				continue;
			}

			for (int j = 0; j <= 9; j++) {
				if (j == d) continue;
				int nm = (m + (md - j * p10) % m) % m;
				dp[i][md][0] = add(dp[i][md][0], dp[i + 1][nm][0]);
			}

			for (int j = 0; j < a[i]; j++) {
				if (j == d) continue;
				int nm = (m + (md - j * p10) % m) % m;
				dp[i][md][1] = add(dp[i][md][1], dp[i + 1][nm][0]);
			}
			if (a[i] != d) {
				int nm = (m + (md - a[i] * p10) % m) % m;
				dp[i][md][1] = add(dp[i][md][1], dp[i + 1][nm][1]);
			}
		}

		p10 = (p10 * 10) % m;
	}

	return dp[1][0][1];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> m >> d;

	string a, b;
	cin >> a >> b;
	n = a.size();

	for (int i = 0; i < n; i++) {
		lower[i + 1] = a[i] - '0';
		upper[i + 1] = b[i] - '0';
	}

	int g = 1;
	int p10 = 1, r = 0;;
	for (int i = n; i > 0; i--) {
		if (i % 2 != (lower[i] != d)) {
			g = 0;
			break;
		}
		r = (r + p10 * lower[i]) % m;
		p10 = (p10 * 10) % m;
	}
	g = r ? 0 : g;

	cout << sub(F(upper) + g, F(lower)) << '\n';
	return 0;
}

