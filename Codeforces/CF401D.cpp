#include <bits/stdc++.h>
using namespace std;
const int N = 19;
const int M = 105;
long long n, m, fact[N], cnt[10];
long long dp[1 << N][M];
string snum;
vector<int> num;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	fact[0] = 1;
	for (long long i = 1; i < N; i++) {
		fact[i] = fact[i - 1] * i;
	}

	cin >> snum >> m;
	n = snum.size();

	for (char c : snum) {
		num.push_back(c - '0');
		cnt[c - '0'] += 1;
	}

	dp[0][0] = 1;
	for (int bm = 0; bm < (1 << n); bm++) {
		if (__builtin_popcount(bm) == 1) {
			int b = 31 - __builtin_clz(bm);
			if (num[b] == 0) {
				continue;
			}
		}

		for (int j = 0; j < m; j++) {
			if (dp[bm][j] == 0) continue;

			for (int i = 0; i < n; i++) {
				if (bm & (1 << i)) continue;
				int nj = (j * 10 + num[i]) % m;
				dp[bm | (1 << i)][nj] += dp[bm][j];
			}
		}
	}

	long long ans = dp[(1 << n) - 1][0];
	for (int i = 0; i <= 9; i++) {
		ans /= fact[cnt[i]];
	}

	cout << ans << '\n';

	return 0;
}
