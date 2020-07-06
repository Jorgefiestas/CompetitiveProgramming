#include <bits/stdc++.h>
using namespace std;
const int N = 206;
int n, dp[N][2];
vector<int> adjList[N];
map<string, int> id;
bool rep[N][2];

void dfs(int v) {
	dp[v][0] = 0;
	dp[v][1] = 1;
	rep[v][0] = false;
	rep[v][1] = false;

	for (int u : adjList[v]) {
		dfs(u);
		if (dp[u][0] == dp[u][1]) {
			dp[v][0] += dp[u][1];
			rep[v][0] = true;
		}
		else if (dp[u][0] > dp[u][1]) {
			dp[v][0] += dp[u][0];
			rep[v][0] = rep[v][0] || rep[u][0];
		}
		else {
			dp[v][0] += dp[u][1];
			rep[v][0] = rep[v][0] || rep[u][1];
		}

		dp[v][1] += dp[u][0];
		rep[v][1] = rep[v][1] || rep[u][0];
	}
}

void solve() {
	int ecnt = 1;
	string emp, boss;

	cin >> boss;

	id[boss] = ecnt++;
	for (int i = 1; i < n; i++) {
		cin >> emp >> boss;
		if (!id.count(emp)) {
			id[emp] = ecnt++;
		}
		if (!id.count(boss)) {
			id[boss] = ecnt++;
		}

		adjList[id[boss]].emplace_back(id[emp]);
	}

	dfs(1);
	bool rpt = (dp[1][0] > dp[1][1]) ? rep[1][0] : rep[1][1];

	cout << max(dp[1][0], dp[1][1]) << ' ';
	if (dp[1][0] == dp[1][1] || rpt) {
		cout << "No";
	}
	else {
		cout << "Yes";
	}
	cout << '\n';
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (cin >> n, n) {
		for (int i = 1; i <= n; i++) {
			adjList[i].clear();
		}
		id.clear();
		solve();
	}

	return 0;
}
