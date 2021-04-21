#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 100;
int n, k, sz[N], dp[N][6];
vector<int> adjList[N];


long long s = 0;
void dfs(int v, int p) {
	sz[v] = 1;
	for (int u : adjList[v]) {
		if (u == p) continue;
		dfs(u, v);
		sz[v] += sz[u];
	}

	s += (long long) sz[v] * (n - sz[v]);
}

void dfs2(int v, int p) {
	dp[v][0] += 1;
	for (int u : adjList[v]) {
		if (u == p) continue;
		dfs2(u, v);

		for (int i = 0; i < k; i++) {
			for (int j = 0; j < k; j++) {
				int rem = (i + j + 1) % k;
				if (!rem) continue;
				s += (long long) dp[v][i] * dp[u][j] * (k - rem);
			}
		}

		for (int i = 0; i < k; i++) {
			dp[v][(i + 1) % k] += dp[u][i];
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;

	int a, b;
	for (int i = 1; i < n; i++) {
		cin >> a >> b;
		adjList[a].emplace_back(b);
		adjList[b].emplace_back(a);
	}

	dfs(1, -1);
	dfs2(1, -1);

	cout << (long long) s / k << '\n';

	return 0;
}
