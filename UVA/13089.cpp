#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int t, n, c[N];
vector<int> adjList[N];

int dfs(int v, int d, int p) {
	int ans = (c[v] % 2) ? d : 0;

	for (int u : adjList[v]) {
		if (u == p) continue;
		ans ^= dfs(u, d + 1, v);
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	for (int ti = 1; ti <= t; ti++) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> c[i];
			adjList[i].clear();
		}

		int a, b;
		for (int i = 1; i < n; i++) {
			cin >> a >> b;
			adjList[a].emplace_back(b);
			adjList[b].emplace_back(a);
		}

		int ans = 0;
		for (int i = 1; i <= n; i++) {
			if (dfs(i, 0, 0) == 0) {
				ans++;
			}
			
		}

		cout << "Case " << ti << ": " << ans << '\n';
	}

	return 0;
}
