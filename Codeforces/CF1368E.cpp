#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 100;
int t, n, m, col[N];
vector<int> adjList[N];

void solve() {
	cin >> n >> m;
	
	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		adjList[a].emplace_back(b);
	}

	for (int i = 1; i <= n; i++) {
		col[i] = -1;
	}

	int cnt = 0;
	for (int v = 1; v <= n; v++) {
		if (col[v] == -1) {
			col[v] = 0;
		}

		int nxt = (col[v] + 1) % 3;
		for (int u : adjList[v]) {
			col[u] = max(col[u], nxt);
		}

		if (col[v] == 2) {
			cnt++;
		}
	}

	cout << cnt << '\n';
	for (int v = 1; v <= n; v++) {
		if (col[v] != 2) continue;
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
		}
		solve();
	}

	return 0;
}
