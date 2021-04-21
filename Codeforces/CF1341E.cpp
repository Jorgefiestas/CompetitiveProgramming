#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int N = 1e4 + 10;
const int T = 1e3 + 10;
int n, m, g, r, d[N];
int dp[N][T];
bool vis[N][T];

int bfs() {
	for (int i = 0; i < m; i++) {
		for (int t = 0; t < g; t++) {
			dp[i][t] = INT_MAX;
		}
	}

	deque<pii> dq;

	dq.push_front({0, 0});
	dp[0][0] = 0;
	while (!dq.empty()) {
		int idx = dq.front().first;
		int t = dq.front().second;
		dq.pop_front();
		vis[idx][t] = true;

		int nt = t ? t : g;

		if (idx > 0) {
			int dist = d[idx] - d[idx - 1];

			if (dist <= nt && !vis[idx - 1][nt - dist]) {
				if (t > 0) {
					dq.push_front({idx - 1, nt - dist});
					dp[idx - 1][nt - dist] = min(dp[idx - 1][nt - dist], dp[idx][t]);
				}
				else {
					dq.push_back({idx - 1, nt - dist});
					dp[idx - 1][nt - dist] = min(dp[idx - 1][nt - dist], dp[idx][t] + 1);
				}
			}
		}
		if (idx < m - 1) {
			int dist = d[idx + 1] - d[idx];

			if (dist <= nt && !vis[idx + 1][nt - dist]) {
				if (t > 0) {
					dq.push_front({idx + 1, nt - dist});
					dp[idx + 1][nt - dist] = min(dp[idx + 1][nt - dist], dp[idx][t]);
				}
				else {
					dq.push_back({idx + 1, nt - dist});
					dp[idx + 1][nt - dist] = min(dp[idx + 1][nt - dist], dp[idx][t] + 1);
				}
			}
		}
	}

	int mn = INT_MAX;
	for (int i = 0; i < g; i++) {
		if (dp[m - 1][i] == INT_MAX) continue;
		mn = min(mn, dp[m - 1][i] * (r + g) - i - r);
	}

	return (mn == INT_MAX) ? -1 : mn;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		cin >> d[i];
	}
	sort(d, d + m);

	cin >> g >> r;

	int ans = bfs();

	if (ans == -1) {
		cout << -1 << '\n';
	}
	else {
		cout << ans << '\n';
	}

	return 0;
}
