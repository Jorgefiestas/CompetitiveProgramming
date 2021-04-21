#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int mod = 1e9 + 7;
int n, dp[N];
vector<int> adjList[N];

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

void dfs(int v, int p) {
	dp[v] = 1;

	if (adjList[v].size() == 1 && p) {
		return;
	}

	for (int u : adjList[v]) {
		if (u == p) continue;
		dfs(u, v);
		dp[v] = mul(dp[v], dp[u]);
	}

	dp[v] = mul(dp[v], 2);
}

int ans = 0;

void dfs2(int v, int p) {
	if (p != 0) {
		int par;
		if (adjList[p].size() == 1) {
			par = 1;
		}
		else {
			par = mul(dp[p], inv(dp[v]));
		}

		dp[v] = mul(dp[v], par);
		if (adjList[v].size() == 1) {
			dp[v] = mul(dp[v], 2);
		}
	}

	ans = add(ans, dp[v]);

	for (int u : adjList[v]) {
		if (u == p) continue;
		dfs2(u, v);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	int a, b;
	for (int i = 1; i < n; i++) {
		cin >> a >> b;
		adjList[a].emplace_back(b);
		adjList[b].emplace_back(a);
	}

	dfs(1, 0);
	dfs2(1, 0);

	cout << ans << '\n';

	return 0;
}
