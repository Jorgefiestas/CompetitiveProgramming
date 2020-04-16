#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, k, size[N], depth[N];
int nodes[N];
vector<int> adjList[N];

void dfs(int v, int p) {
	size[v] = 1;
	for (int u : adjList[v]) {
		if (u == p) continue;
		depth[u] = depth[v] + 1;
		dfs(u, v);
		size[v] += size[u];
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;

	int a, b;
	for (int i = 1; i < n; i++) {
		cin >> a >> b;
		adjList[a].emplace_back(b);
		adjList[b].emplace_back(a);
	}

	depth[1] = 1;
	dfs(1, 0);

	for (int i = 0; i < n; i++) {
		nodes[i] = size[i + 1] - depth[i + 1];
	}

	sort(nodes, nodes + n, greater<int>());

	long long ans = 0;
	for (int i = 0; i < n - k; i++) {
		ans += (long long) nodes[i];
	}

	cout << ans << '\n';

	return 0;
}
