#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int mod = 1e9 + 7;
int n, c[N];
int dp[N][2];
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

void dfs(int v) { 
	dp[v][0] = 1;

	int ans = 0;
	for (int u : adjList[v]) {
		dfs(u);
		ans = mul(ans, dp[u][0]);
		ans = add(ans, mul(dp[v][0], dp[u][1]));
		dp[v][0] = mul(dp[v][0], dp[u][0]);
	}

	if (c[v] == 1) {
		dp[v][1] = dp[v][0];
	}
	else {
		dp[v][0] = add(dp[v][0], ans);
		dp[v][1] = ans;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	int pi;
	for (int i = 1; i < n; i++) {
		cin >> pi;
		adjList[pi].emplace_back(i);
	}

	for (int i = 0; i < n; i++) {
		cin >> c[i];
	}

	dfs(0);
	cout << dp[0][1] << '\n';

	return 0;
}
