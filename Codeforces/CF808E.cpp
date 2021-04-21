#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 100;
int n, m, c1[N], c2[N];
long long dp[N];
vector<int> costs[4];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;


	int ci, wi;
	for (int i = 0; i < n; i++) {
		cin >> wi >> ci;
		costs[wi].emplace_back(ci);
	}

	for (int i = 0; i < 2 * N; i++) {
		for (int j = 0; j < 4; j++) {
			costs[j].push_back(0);
		}
	}

	for (int i = 0; i < 4; i++) {
		sort(costs[i].begin(), costs[i].end(), greater<int>());
	}

	dp[1] = costs[1][0];
	c1[1] = 1;

	for (int w = 2; w <= m; w++) {
		long long can1 = dp[w - 1] + (long long) costs[1][c1[w - 1]];
		long long can2 = dp[w - 2] + (long long) costs[2][c2[w - 2]];
		if (can1 > can2) {
			dp[w] = can1;
			c1[w] = c1[w - 1] + 1;
			c2[w] = c2[w - 1];
		}
		else {
			dp[w] = can2;
			c1[w] = c1[w - 2];
			c2[w] = c2[w - 2] + 1;
		}
	}

	long long ans = dp[m];
	long long s3 = 0;
	for (int t = 0; t < m / 3; t++) {
		s3 += (long long) costs[3][t];
		int w = m - 3 * (t + 1);
		ans = max(ans, s3 + dp[w]);
	}

	cout << ans << endl;

	return 0;
}
