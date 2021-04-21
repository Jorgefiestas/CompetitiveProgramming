#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, long long>;
const int N = 5005;
int n, k, x, a[N];
long long dp[N][N];
deque<pii> st[N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k >> x;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	memset(dp, -1, sizeof dp);

	for (int i = 1; i <= x; i++) {
		st[i].push_back({i, -1});
	}

	for (int i = 1; i <= n; i++) {
		dp[i][1] = (i <= k) ? a[i] : -1;

		for (int j = 2; j <= x; j++) {
			dp[i][j] = st[j - 1].front().second;
			if (dp[i][j] >= 0) {
				dp[i][j] += (long long) a[i];
			}
		}

		for (int j = 1; j <= x; j++) {
			while (!st[j].empty() && st[j].back().second <= dp[i][j]) {
				st[j].pop_back();
			}
			st[j].push_back({i, dp[i][j]});

			while (st[j].front().first <= i - k) {
				st[j].pop_front();
			}
		}
	}

	cout << st[x].front().second << '\n';

	return 0;
}
