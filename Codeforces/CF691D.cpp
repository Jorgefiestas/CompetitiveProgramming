#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int n, m, p[N];
vector<int> adjList[N];
bool vis[N];

vector<int> vals, idx;

void dfs(int v) {
	vis[v] = true;
	for (int u : adjList[v]) {
		if (vis[u]) continue;
		dfs(u);
	}
	vals.emplace_back(p[v]);
	idx.emplace_back(v);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		cin >> p[i];
	}

	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		adjList[a].emplace_back(b);
		adjList[b].emplace_back(a);
	}

	for (int v = 1; v <= n; v++) {
		if (vis[v]) continue;
		dfs(v);

		sort(vals.begin(), vals.end(), greater<int>());
		sort(idx.begin(), idx.end());

		for (int i = 0; i < vals.size(); i++) {
			p[idx[i]] = vals[i];
		}

		vals.clear();
		idx.clear();
	}

	for (int i = 1; i <= n; i++) {
		cout << p[i] << ' ';
	}
	cout << '\n';

	return 0;
}
