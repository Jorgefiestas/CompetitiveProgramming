#include <bits/stdc++.h>
using namespace std;
int t, n, m;

vector<int> solve() {
	cin >> n >> m;

	vector<vector<int>> adjList(n + 1);
	vector<int> col(n + 1, - 1);

	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		adjList[a].emplace_back(b);
		adjList[b].emplace_back(a);
	}

	queue<int> q;
	q.push(1);

	while (!q.empty()) {
		int v = q.front();
		q.pop();

		if (col[v] != -1) continue;

		col[v] = 0;
		for (int u : adjList[v]) {
			if (col[u] != -1) continue;

			col[u] = 1;
			for (int w : adjList[u]) {
				q.push(w);
			}
		}
	}

	vector<int> ans;
	for (int v = 1; v <= n; v++) {
		if (col[v] == -1)
			return {};

		if (col[v] == 0)
			ans.emplace_back(v);
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		vector<int> ans = solve();
		if (ans.size() == 0) {
			cout << "NO\n";
		}
		else {
			cout << "YES\n";
			cout << ans.size() << '\n';
			for (int x : ans) {
				cout << x << ' ';
			}
			cout << '\n';
		}
	}

	return 0;
}
