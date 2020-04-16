#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, ans, a[N], spf[N];
vector<int> adjList[N];
map<int , int> paths[N];

void sieve() {
	for (int i = 1; i <= N; i++) {
		spf[i] = i;
	}

	for (int i = 2; i * i < N; i++) {
		if (spf[i] != i) continue;
		for (int j = i * i; j < N; j += i) {
			spf[j] = min(i, spf[j]);
		}
	}
}

void dfs(int v, int p) {
	int y = a[v];
	while (y > 1) {
		ans = max(ans, 1);
		paths[v][spf[y]] = 1;
		y /= spf[y];
	}

	for (int u : adjList[v]) {
		if (u == p) continue;
		dfs(u, v);

		int x = a[v];
		while (x > 1) {
			int d = spf[x];
			if (paths[u].count(d)) {
				ans = max(ans, paths[v][d] + paths[u][d]);
				paths[v][d] = max(paths[v][d], 1 + paths[u][d]);
			}

			while (x % d == 0) {
				x /= d;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	sieve();

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	
	int x, y;
	for (int i = 1; i < n; i++) {
		cin >> x >> y;
		adjList[x].emplace_back(y);
		adjList[y].emplace_back(x);
	}

	dfs(1, -1);
	cout << ans << '\n';

	return 0;
}
