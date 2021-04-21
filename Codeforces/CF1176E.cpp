#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, bool>;
const int N  = 2e5 + 100;
int t, n, m;
vector<int> adjList[N];
bool vis[N], col[N];

void clean() {
	for (int i = 0; i <= n; i++) {
		adjList[i].clear();
		vis[i] = false;
	}
}

void bfs() {

	queue<pii> q;
	
	q.push({1, 1});
	col[1] = 1;
	vis[1] = true;

	while (!q.empty()) {
		int v = q.front().first;
		int c = q.front().second;
		q.pop();

		col[v] = c;
		for (int u : adjList[v]) {
			if (vis[u]) continue;
			vis[u] = true;
			q.push({u, !c});
		}
	}
}

void solve() {
	cin >> n >> m;

	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		adjList[a].emplace_back(b);
		adjList[b].emplace_back(a);
	}

	bfs();

	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (!col[i]) continue;
		cnt += 1;
	}

	if (cnt > n / 2) {
		for (int i = 1; i <= n; i++) {
			col[i] = !col[i];
		}
		cnt = n - cnt;
	}

	cout << cnt << '\n';
	for (int i = 1; i <= n; i++) {
		if (!col[i]) continue;
		cout << i << ' ';
	}
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		clean();
		solve();
	}

	return 0;
}
