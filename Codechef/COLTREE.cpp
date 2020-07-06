#include <bits/stdc++.h>
using namespace std;
const int N = 55;
const int mod = 1e9 + 7;
int t, n, k, fact[N];
vector<int> adjList[N];
int mem[N][N];
bool vis[N][N];

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

int P(int x, int y) {
	if (y > x) {
		return 0;
	}
	return mul(fact[x], inv(fact[x - y]));
}

int dfs(int v, int p) {
	int ans = 1;

	vector<int> dp0(k + 1, 0);
	dp0[1] = 1;
	for (int u : adjList[v]) {
		if (u == p) continue;

		for (int i = 1; i <= k; i++) {
			for (int j = 1; i + j <= k; j++) {
				dp0[i + j] = add(dp0[i + j], mul(dp[v][i], dp[u][j]));
			}
		}

		for (int i = 1; i <= k; i++) {
			dp[v][i] = dp0[i];
		}
	}
}

int solve() {
	cin >> n >> k;
	
	int a, b;
	for (int i = 1; i < n; i++) {
		cin >> a >> b;
		adjList[a].emplace_back(b);
		adjList[b].emplace_back(a);
	}

	int ans = 0;
	for (int i = 1; i <= k; i++) {
		cout << dp(1, -1, i) << endl;
		ans = add(ans, mul(dp(1, -1, i), P(k, i)));
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	fact[0] = 1;
	for (int i = 1; i < N; i++) {
		fact[i] = mul(fact[i - 1], i);
	}

	cin >> t;
	while (t--) {
		memset(vis, 0, sizeof vis);
		for (int i = 1; i <= n; i++) {
			adjList[i].clear();
		}

		cout << solve() << '\n';
	}

	return 0;
}
