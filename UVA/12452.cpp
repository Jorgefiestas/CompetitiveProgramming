#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 100;
int t, n, dp[N][2];
vector<int> adjList[N]; 

void dfs(int v, int p) {
	for (int u : adjList[v]) {
		if (u == p) continue;
		dfs(u, v);
	}

	int none = 0;
	int star = 0;
	int mx_dif1 = 0;
	int mx_dif2 = 0;

	for (int u : adjList[v]) {
		if (u == p) continue;
		none += dp[u][0];
		star += dp[u][1]; 

		int dif = dp[u][0] - dp[u][1];
		if (dif > mx_dif1) {
			mx_dif2 = mx_dif1;
			mx_dif1 = dif;
		}
		else if (dif > mx_dif2) {
			mx_dif2 = dif;
		}
	}

	dp[v][0] = min({none + 100, none - mx_dif1 + 175, 500 + star});
	dp[v][1] = min({none, none - mx_dif1 + 100, none - mx_dif1 - mx_dif2 + 175, 500 + star});
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> t;
	while (t--) {
		memset(dp, 0, sizeof dp);
		for (int i = 0; i < n; i++) {
			adjList[i].clear();
		}

		cin >> n;

		int a, b;
		for (int i = 1; i < n; i++) {
			cin >> a >> b;
			adjList[a].emplace_back(b);
			adjList[b].emplace_back(a);
		}

		dfs(0, -1);
		cout << '$' << dp[0][1] << '\n';
	}

	return 0;
}
