#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 100;
int n, a[N], b[N];
bool vis[N];
long long dp[N];
vector<int> adjList[N];

vector<int> sorted;
void dfs(int v) {
	vis[v] = true;

	dp[v] = a[v];
	for (int u : adjList[v]) {
		if (!vis[u]) {
			dfs(u);
		}
		dp[v] += max(dp[u], 0LL);
	}

	sorted.emplace_back(v);
}

void print(int v) {
	vis[v] = true;

	for (int u : adjList[v]) {
		if (dp[u] < 0) continue;
		print(u);
	}

	cout << v << ' ';

	for (int u : adjList[v]) {
		if (dp[u] >= 0) continue;
		print(u);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	int u;
	for (int i = 1; i <= n; i++) {
		cin >> u;
		if (u != -1) {
			adjList[u].emplace_back(i);
		}
	}

	for (int v = 1; v <= n; v++) {
		if (vis[v]) continue;
		dfs(v);
	}

	long long sum = 0;
	for (int v = 1; v <= n; v++) {
		sum += dp[v];
	}

	cout << sum << '\n';

	reverse(sorted.begin(), sorted.end());
	memset(vis, 0, sizeof vis);
	for (int v : sorted) {
		if (vis[v]) continue;
		print(v);
	}
	cout << '\n';


	return 0;
}
