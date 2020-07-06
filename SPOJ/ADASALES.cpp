#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 100;
int n, q;
long long val[N];
vector<int> adjList[N];
vector<long long> dp[N][2];
long long res[N];

void dfs1(int v, int p) {
	dp[v][0] = {0, 0};
	dp[v][1] = {val[v], 0};
	for (int u : adjList[v]) {
		if (u == p) continue;
		dfs1(u, v);
		dp[v][0].push_back(max(dp[u][1][0] - val[v], dp[u][0][0]));
		dp[v][1].push_back(max(dp[u][0][0] + val[v], dp[u][1][0]));
		sort(dp[v][0].begin(), dp[v][0].end(), greater<long long>());
		sort(dp[v][1].begin(), dp[v][1].end(), greater<long long>());
		dp[v][0].pop_back();
		dp[v][1].pop_back();
	}
}

void dfs2(int v, int p) {
	if (p != -1) {
		long long mx0 = -1, mx1 = -1;
		long long cont0 = max(dp[v][1][0] - val[p], dp[v][0][0]);
		long long cont1 = max(dp[v][0][0] + val[p], dp[v][1][0]);

		mx0 = (dp[p][0][0] == cont0) ? dp[p][0][1] : dp[p][0][0];
		mx1 = (dp[p][1][0] == cont1) ? dp[p][1][1] : dp[p][1][0];

		dp[v][0].push_back(max(mx1 - val[v], mx0));
		dp[v][1].push_back(max(mx0 + val[v], mx1));

		sort(dp[v][0].begin(), dp[v][0].end(), greater<long long>());
		sort(dp[v][1].begin(), dp[v][1].end(), greater<long long>());
		dp[v][0].pop_back();
		dp[v][1].pop_back();
	}

	res[v] = dp[v][0][0];
	for (int u : adjList[v]) {
		if (u == p) continue;
		dfs2(u, v);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> q;
	for (int i = 0; i < n; i++) {
		cin >> val[i];
	}

	int a, b;
	for (int i = 1; i < n; i++) {
		cin >> a >> b;
		adjList[a].emplace_back(b);
		adjList[b].emplace_back(a);
	}

	dfs1(0, -1);
	dfs2(0, -1);

	int s;
	for (int i = 0; i < q; i++) {
		cin >> s;
		cout << res[s] << '\n';
	}

	return 0;
}
