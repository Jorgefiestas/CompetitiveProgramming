#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int N = 2e5 + 10;
int t, n, m;

void solve() {
	cin >> n >> m;

	vector<vector<int>> adjList(n + 1);

	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		adjList[a].push_back(b);
	}

	queue<int> q;
	vector<int> d(n + 1, -1);

	q.push(1);
	d[1] = 0;

	while (!q.empty()) {
		int v = q.front();
		q.pop();

		for (int u : adjList[v]) {
			if (d[u] != -1) continue;
			d[u] = d[v] + 1;
			q.push(u);
		}
	}

	vector<vector<pii>> revList(n + 1);

	for (int v = 1; v <= n; v++) {
		for (int u : adjList[v]) {
			bool w = (d[v] >= d[u]);
			revList[u].push_back({v, w});
		}
	}

	priority_queue<pii, vector<pii>, greater<pii>> pq;
	vector<int> ans(n + 1);

	for (int v = 1; v <= n; v++) {
		pq.push({d[v], v});
		ans[v] = d[v];
	}

	while (!pq.empty()) {
		auto [dp, v] = pq.top();
		pq.pop();

		if (dp != ans[v]) continue;

		for (auto [u, w] : revList[v]) {
			int can = w ? d[v] : ans[v];
			if (can < ans[u]) {
				ans[u] = can;
				pq.push({ans[u], u});
			}
		}
	}

	for (int i = 1; i <= n; i ++) {
		cout << ans[i] << ' ';
	}
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}
