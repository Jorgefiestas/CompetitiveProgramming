#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 100;
int n, m, mem[N];
bool vis[N];
vector<int> adjList[N];

int dp(int v) {
	if (vis[v]) {
		return mem[v];
	}
	vis[v] = true;

	int ans = 0;
	for(int u : adjList[v]) {
		ans = max(ans, dp(u) + 1);
	}

	return mem[v] = ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		adjList[a].emplace_back(b);
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans = max(ans, dp(i));
	}

	cout << ans << '\n';

	return 0;
}
