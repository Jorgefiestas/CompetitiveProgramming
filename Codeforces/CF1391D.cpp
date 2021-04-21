#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 100;
int n, m, dp[N][9];
int mat[N];

bool check(int a, int b) {
	for (int i = 0; i < m - 1; i++) {
		int s1 = __builtin_popcount(a % 4);
		int s2 = __builtin_popcount(b % 4);

		if ((s1 + s2) % 2 == 0) {
			return false;
		}

		a >>= 1;
		b >>= 1;
	}

	return true;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	if (n >= 4 && m >= 4) {
		cout << -1 << '\n';
		return 0;
	}
	if (n == 1 || m == 1) {
		cout << 0 << '\n';
		return 0;
	}

	char b;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> b;
			int op = (b == '1') ? 1 : 0;

			if (n >= m) {
				mat[i] |= (op << j);
			}
			else {
				mat[j] |= (op << i);
			}
		}
	}

	if (n < m) {
		swap(n, m);
	}

	for (int i = 0; i < n; i++) {
		for (int bm = 0; bm < (1 << m); bm++) {
			dp[i][bm] = (i == 0) ? 0 : INT_MAX;
			for (int sm = 0; sm < (1 << m); sm++) {
				if (i == 0 || !check(bm, sm)) continue;
				dp[i][bm] = min(dp[i][bm], dp[i - 1][sm]);
			}
			dp[i][bm] += __builtin_popcount(mat[i] ^ bm);
		}
	}

	int ans = INT_MAX;
	for (int i = 0; i < (1 << m); i++) {
		ans = min(ans, dp[n - 1][i]);
	}

	cout << ans << '\n';

	return 0;
}
