#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 100;
const int mod = 1e9 + 7;
int n, to[N], dp[N][2];
vector<int> adjList[N];
bool vis[N];

int add(int x, int y) {
	if (x + y >= mod) {
		return x + y - mod;
	}
	return x + y;
}

int mul(int x, int y) {
	return (long long) x * y % mod;
}

int exp(int x, int y) {
	int ans = 1;
	while (y) {
		if (y & 1) {
			ans = mul(ans, x);
		}
		x = mul(x, x);
		y >>= 1;
	}
	return ans;
}

int inv(int x) {
	return exp(x, mod - 2);
}

void dfs(int v) {
	dp[v][0] = 1;
	dp[v][1] = 0;

	for (int u : adjList[v]) {
		dfs(u);
		dp[v][0] = mul(dp[v][0], dp[u][0]);
	}

	dp[v][1] = dp[v][0];
	for (int u : adjList[v]) {
		int cont = mul(mul(dp[v][0], inv(dp[u][0])), dp[u][1]);
		dp[v][1] = add(dp[v][1], cont);
	}
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	int a, b;
	for (int i = 1; i <= n; i++) {
		cin >> a >> b;
		to[a] = b;
		adjList[b].emplace_back(a);
	}

	int ans = 1;

	for (int i = 1; i <= 2 * n; i++) {
		if (!to[i] || vis[i]) continue;

		set<int> seen;

		int v = i;
		while (v && !vis[v]) {
			vis[v] = true;
			seen.insert(v);
			v = to[v];
		}

		if (!seen.count(v)) continue;

		if (to[v] != v) {
			ans = mul(ans, 2);
		}
	}

	for (int i = 1; i <= 2 * n; i++) {
		if (adjList[i].empty() || to[i]) continue;
		dfs(i);
		ans = mul(ans, dp[i][1]);
	}

	cout << ans << '\n';

	return 0;
}
