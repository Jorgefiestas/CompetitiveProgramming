#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, par[N];
long long a[N];
vector<int> adjList[N], level[N];

void dfs(int v, int p, int d) {
	par[v] = p;
	level[d].push_back(v);
	for (int u : adjList[v]) {
		if (u == p) continue;
		dfs(u, v, d + 1);
	}
}

long long solve() {
	cin >> n;

	int p;
	for (int i = 2; i <= n; i++) {
		cin >> p;
		adjList[i].push_back(p);
		adjList[p].push_back(i);
	}

	for (int i = 2; i <= n; i++) {
		cin >> a[i];
	}

	dfs(1, -1, 0);

	vector<long long> dp(n + 1, 0);

	long long ans = 0;
	for (int l = 1; l <= n; l++) {
		if (level[l].empty()) break;

		long long mn = LLONG_MAX;
		long long mx = LLONG_MIN;
		long long mx1 = LLONG_MIN;
		long long mx2 = LLONG_MIN;

		for (int v : level[l]) {
			mn = min(mn, a[v]);
			mx = max(mx, a[v]);
			mx1 = max(mx1, dp[par[v]] + a[v]);
			mx2 = max(mx2, dp[par[v]] - a[v]);
		}

		for (int v : level[l]) {
			long long can1, can2;
			can1 = dp[par[v]] + max(a[v] - mn, mx - a[v]);
			can2 = max(mx1 - a[v], mx2 + a[v]);
			dp[v] = max(can1, can2);
			ans = max(ans, dp[v]);
		}
	}

	for (int v = 1; v <= n; v++) {
		adjList[v].clear();
		level[v].clear();
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	while (t--) {
		cout << solve() << '\n';
	}

	return 0;
}
