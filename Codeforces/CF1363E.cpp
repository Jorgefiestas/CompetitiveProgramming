#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int N = 2e5 + 100;
int n, a[N], b[N], c[N];
vector<int> adjList[N];

int cnt[2][N];

long long cost = 0;
pii dfs(int v, int mn, int p) {
	if (b[v] != c[v]) {
		cnt[b[v]][v] += 1;
	}

	for (int u : adjList[v]) {
		if (u == p) continue;
		pii extra = dfs(u, min(mn, a[u]), v);
		cnt[0][v] += extra.first;
		cnt[1][v] += extra.second;
	}

	if (a[v] == mn) {
		int mcnt = min(cnt[0][v], cnt[1][v]);
		cost += (long long) a[v] * 2LL * mcnt;
		cnt[0][v] -= mcnt;
		cnt[1][v] -= mcnt;
	}

	return {cnt[0][v], cnt[1][v]};
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> b[i] >> c[i];
	}

	int u, v;
	for (int i = 1; i < n; i++) {
		cin >> u >> v;
		adjList[u].emplace_back(v);
		adjList[v].emplace_back(u);
	}

	pii last = dfs(1, a[1], -1);
	
	if (last.first || last.second) {
		cout << -1 << '\n';
	}
	else {
		cout << cost << '\n';
	}

	return 0;
}
