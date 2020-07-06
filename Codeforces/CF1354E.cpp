#include <bits/stdc++.h>
using namespace std;
const int N = 5e3 + 100;
int n, m, dp[2 * N][N];
int n1, n2, n3;
vector<int> adjList[N];
int col[N], ans[N];

bool poss = true, vis[N];
int cnt[2 * N];
void dfs(int v) {
	vis[v] = true;
	cnt[col[v]]++;

	for (int u : adjList[v]) {
		if (vis[u]) {
			poss = poss && (col[u] != col[v]);
			continue;
		}
		
		col[u] = col[v];
		col[u] += (col[v] & 1) ? -1 : 1;
		dfs(u);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	cin >> n1 >> n2 >> n3;

	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		adjList[a].emplace_back(b);
		adjList[b].emplace_back(a);
	}

	int c = 0;
	for (int i = 1; i <= n; i++) {
		if (vis[i]) continue;
		col[i] = c;
		dfs(i);
		c += 2;
	}

	memset(dp, -1, sizeof dp);
	dp[0][0] = -2;
	dp[1][0] = -2;
	for (int i = 0; i < c; i += 2) {
		for (int j = 0; j + cnt[i] <= n2; j++) {
			if (dp[i][j] == -1) continue;
			dp[i + 2][j + cnt[i]] = i;
			dp[i + 3][j + cnt[i]] = i;
		}
		for (int j = 0; j + cnt[i + 1] <= n2; j++) {
			if (dp[i + 1][j] == -1) continue;
			dp[i + 2][j + cnt[i + 1]] = i + 1;
			dp[i + 3][j + cnt[i + 1]] = i + 1;
		}
	}

	if (!poss || dp[c][n2] == -1) {
		cout << "NO\n";
		return 0;
	}

	int cc = c;
	int rn = n2;
	while (cc != -2) {
		cc = dp[cc][rn];
		for (int i = 1; i <= n; i++) {
			if (col[i] != cc) continue;
			ans[i] = 2;
			rn--;
		}
	}

	for (int i = 1; i <= n; i++) {
		if (ans[i]) continue;
		ans[i] = n1 ? 1 : 3;
		n1 = max(0, n1 - 1);
	}

	cout << "YES\n";
	for (int i = 1; i <= n; i++) {
		cout << ans[i];
	}
	cout << '\n';

	return 0;
}
