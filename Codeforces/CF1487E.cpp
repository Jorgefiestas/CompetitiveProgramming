#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int N = 1.5e5 + 10;
int n[4], a[4][N], dps[4][N];
vector<int> adjList[4][N];
set<pii> dp[4];

void read_edges(int id) {
	int m;
	cin >> m;

	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;

		adjList[id][b].push_back(a);
	}
}

void read_values(int id) {
	for (int i = 1; i <= n[id]; i++) {
		cin >> a[id][i];
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n[0] >> n[1] >> n[2] >> n[3];


	for (int i = 0; i < 4; i++)
		read_values(i);

	for (int i = 1; i < 4; i++)
		read_edges(i);


	dp[0].insert({INT_MAX, -1});
	for (int i = 1; i <= n[0]; i++) {
		dps[0][i] = a[0][i];
		dp[0].insert({a[0][i], i});
	}

	for (int id = 1; id < 4; id++) {
		for (int i = 1; i <= n[id]; i++) {
			for (int x : adjList[id][i]) {
				dp[id - 1].erase({dps[id - 1][x], x});
			}

			dps[id][i] = dp[id - 1].begin()->first;
			if (dps[id][i] < INT_MAX) {
				dps[id][i] += a[id][i];
			}
			
			for (int x : adjList[id][i]) {
				dp[id - 1].insert({dps[id - 1][x], x});
			}
		}

		dp[id].insert({INT_MAX, -1});
		for (int i = 1; i <= n[id]; i++) {
			dp[id].insert({dps[id][i], i});
		}
	}

	int ans = dp[3].begin()->first;
	ans = (ans == INT_MAX) ? -1 : ans;

	cout << ans << '\n';

	return 0;
}
