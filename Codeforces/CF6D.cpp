#include <bits/stdc++.h>
using namespace std;
const int N = 20;
int n, a, b, h[N];
int dp[N][N][N];
vector<int> tr[N][N][N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> a >> b;

	for (int i = 1; i <= n; i++) {
		cin >> h[i];
		h[i] += 1;
	}

	int cnt = 0;
	vector<int> res;



	for (int i = 0; i <= 16; i++) {
		int mn = (max(h[n - 1] - b * i, 0) + a - 1) / a;
		mn = max(mn, (h[n] + b - 1) / b);

		for (int j = 0; j <= 16; j++) {
			dp[n - 1][i][j] = (j < mn) ? 1000000 : j;
		}
	}

	for (int i = n - 2; i > 1; i--) {
		for (int j = 0; j <= 16; j++) {
			for (int k = 0; k <= 16; k++) {
				int ch = max(h[i] - (j * b + k * a), 0);
				int s = (ch + b - 1) / b;

				int best = 1000000;
				for (int l = s; l <= 16; l++) {
					if (best > dp[i + 1][k][l]) {
						best = dp[i + 1][k][l];
						tr[i][j][k] = {i + 1, k, l};
					}
				}

				dp[i][j][k] = k + best;
			}
		}
	}

	int mn = (h[1] + b - 1) / b;

	int bi = 2, bj = 0, bk = 0;
	int ans = INT_MAX;
	for (int i = mn; i <= 16; i++) {
		if (dp[2][0][i] >= ans) continue;
		ans = dp[2][0][i];
		bk = i;
	}

	cout << ans << '\n';
	while (true) {
		for (int i = 0; i < bk; i++) {
			cout << bi << ' ';
		}
		if (bi == n - 1) {
			break;
		}
		auto tran = tr[bi][bj][bk];
		bi = tran[0];
		bj = tran[1];
		bk = tran[2];
	}
	cout << '\n';

	return 0;
}
