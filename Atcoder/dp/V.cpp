#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 100;
int n;
vector<int> adjList[N];
long long mod, dp[N], ans[N];

void dfs1(int v, int p) {
	dp[v] = 1;

	for (int u : adjList[v]) {
		if (u == p) continue;
		dfs1(u, v);
		dp[v] = (dp[u] * dp[v]) % mod;
	}
	dp[v] = (dp[v] + 1) % mod;
}

void dfs2(int v, int p) {
	ans[v] = dp[v];

	int s = adjList[v].size();

	long long pref[s + 1];
	pref[0] = 1;
	for (int i = 0; i < s; i++) {
		int u = adjList[v][i];
		pref[i + 1] = (dp[u] * pref[i]) % mod;
	}
	
	long long suff[s + 2];
	suff[s + 1] = 1;
	for (int i = s - 1; i >= 0; i--) {
		int u = adjList[v][i];
		suff[i + 1] = (dp[u] * suff[i + 2]) % mod;
	}

	for (int i = 0; i < s; i++) {
		int u = adjList[v][i];
		if (u == p) continue;

		long long dpv = dp[v];
		long long dpu = dp[u];

		dp[v] = (suff[i + 2] * pref[i]) % mod;

		dp[u] = (dp[u] + mod - 1LL) % mod;
		dp[v] = (dp[v] + 1LL) % mod;
		dp[u] = (dp[u] * dp[v]) % mod;
		dfs2(u, v);
		dp[v] = dpv;
		dp[u] = dpu;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> mod;

	int a, b;
	for (int i = 1; i < n; i++) {
		cin >> a >> b;
		adjList[a].emplace_back(b);
		adjList[b].emplace_back(a);
	}

	dfs1(1, -1);
	dp[1] = (dp[1] + mod - 1LL) % mod;
	dfs2(1, -1);

	for (int i = 1; i <= n; i++) {
		cout << ans[i] << '\n';
	}

	return 0;
}
