#include <bits/stdc++.h>
using namespace std;
const int N = 1e6;
const int L = 1e5;
const int M = 105;
const int mod = 1e9 + 7;
int n, l, m, c[N];
int dp[M], cnt0[M], cnt[M];

int add(int x, int y) {
	if (x + y >= mod) {
		return x + y - mod;
	}
	return x + y;
}

int mul(int x, int y) {
	return (long long) x * y % mod;
}

void mat_mul(int a[M][M], int b[M][M], int to[M][M]) {
	int c[m][m];

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			c[i][j] = 0;
			for (int k = 0; k < m; k++) {
				c[i][j] = add(c[i][j], mul(a[i][k], b[k][j]));
			}
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			to[i][j] = c[i][j];
		}
	}
}

void mat_exp(int x[M][M], int y) {
	int ans[M][M];
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			ans[i][j] = (i == j) ? 1 : 0;
		}
	}

	while (y) {
		if (y & 1) {
			mat_mul(ans, x, ans);
		}

		mat_mul(x, x, x);
		y >>= 1;
	}


	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			x[i][j] = ans[i][j];
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> l >> m;

	int xi;
	for (int i = 0; i < n; i++) {
		cin >> xi;
		cnt0[xi % m]++;
	}
	for (int i = 0; i < n; i++) {
		cin >> c[i];
		c[i] %= m;
		cnt[c[i]]++;
	}

	int x[M][M];
	for (int i = 0; i <= m; i++) {
		for (int j = 0; j < m; j++) {
			x[i][j] = cnt[(m - j + i) % m];
		}
	}

	mat_exp(x, l - 2);

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m;j ++) {
			dp[i] = add(dp[i], mul(cnt0[j], x[i][j]));
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		cin >> xi;
		ans = add(ans, dp[(2 * m - xi - c[i]) % m]);
	}

	cout << ans << '\n';
}
