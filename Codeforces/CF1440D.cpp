#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
const int SN = 500;
using pii = pair<int, int>;
int t, n, m, k, deg[N];
vector<int> adjList[N];

bool clique(int v) {
	vector<int> vec;

	for (int u : adjList[v]) {
		if (deg[u] == 0) continue;
		vec.emplace_back(u);
	}

	for (int u : vec) {
		for (int w : vec) {
			if (u < w && !binary_search(adjList[u].begin(), adjList[u].end(), w))
				return false;
		}
	}

	vec.emplace_back(v);

	cout << 2 << '\n';
	for (int u : vec) {
		cout << u << ' ';
	}
	cout << '\n';

	return true;
}

void solve() {
	cin >> n >> m >> k;

	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		adjList[a].emplace_back(b);
		adjList[b].emplace_back(a);
		deg[a] += 1;
		deg[b] += 1;
	}

	if (k > SN) {
		cout << -1 << '\n';
		return;
	}

	queue<int> q;

	for (int v = 1; v <= n; v++) {
		sort(adjList[v].begin(), adjList[v].end());
		if (deg[v] < k)
			q.push(v);
	}

	while (!q.empty()) {
		int v = q.front();
		q.pop();

		if (deg[v] == 0) continue;
		if (deg[v] == k - 1) {
			if (clique(v))
				return;
		}

		deg[v] = 0;
		for (int u : adjList[v]) {
			if (deg[u] == 0) continue;

			deg[u] -= 1;
			if (deg[u] < k)
				q.push(u);
		}
	}

	vector<int> ans;
	for (int v = 1; v <= n; v++) {
		if(deg[v] == 0) continue;
		ans.emplace_back(v);
	}

	if (ans.empty()) {
		cout << -1 << '\n';;
		return;
	}

	cout << 1 << ' ' << ans.size() << '\n';
	for (int v : ans) {
		cout << v << ' ';
	}
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);


	cin >> t;
	while (t--) {
		for (int i = 1; i <= n; i++) {
			adjList[i].clear();
			deg[i] = 0;
		}

		solve();
	}

	return 0;
}
