#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int N = 2e5 + 10;
int t, n;
vector<int> adjList[N];

int ans = 0;
int dfs(int v, int p) {
	if (adjList[v].size() == 1 && v != 1) {
		return 1;
	}

	vector<int> can;
	for (int u : adjList[v]) {
		if (u == p) continue;
		int w = dfs(u, v);
		can.push_back(w);
	}

	sort(can.begin(), can.end());

	if (can.size() > 1) {
		if (v == 1) {
			ans = max({ans, can.back(), can[can.size() - 2] + 1});
		}
		else {
			ans = max(ans, can.back() + 1);
		}
	}
	ans = max(ans, can[0]);

	return can[0] + 1;
}

int solve() {
	cin >> n;

	int a, b;
	for (int i = 1; i < n; i++) {
		cin >> a >> b;
		adjList[a].emplace_back(b);
		adjList[b].emplace_back(a);
	}

	ans = 0;
	dfs(1, -1);

	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;

	while (t--) {
		for (int i = 1; i <= n; i++) {
			adjList[i].clear();
		}

		cout << solve() << '\n';
	}

	return 0;
}
