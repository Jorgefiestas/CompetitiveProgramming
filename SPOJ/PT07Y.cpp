#include <bits/stdc++.h>
using namespace std;
int n, m, cnt;
bool vis[10005];
vector<int> adjList[10005];

bool dfs(int v, int p) {
	cnt++;
	vis[v] = true;

	for (int u : adjList[v]) {
		if (u == p)
			continue;
		if(vis[u] || !dfs(u, v))
			return false;
	}
	return true;
}

int main() {
	cin >> n >> m;

	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		adjList[a].emplace_back(b);
		adjList[b].emplace_back(a);
	}

	if (dfs(1, -1) && cnt == n) {
		cout << "YES\n";
	}
	else {
		cout << "NO\n";
	}

	return 0;
}
