#include <bits/stdc++.h>
using namespace std;
using pil = pair<int, long long>;
const int N = 2e5 + 10;
const int L = 20;
int n, dp[N], par[N][L];
long long a[N], depth[N];
vector<pil> adjList[N];

long long dist(int u, int v) {
	return abs(depth[v] - depth[u]);
}

void dfs(int v, int p) {

	par[v][0] = p;
	for (int i = 1; i < L; i++) {
		if (par[v][i - 1] == -1) break;
		par[v][i] = par[par[v][i - 1]][i - 1];
	}

	for (auto [u, w] : adjList[v]) {
		if (u == p) continue;
		depth[u] = depth[v] + w;
		dfs(u, v);
	}

	int u = v;
	for (int i = L - 1; i >= 0; i--) {
		if (par[u][i] != -1 && dist(par[u][i], v) <= a[v]) {
			u = par[u][i];
		}
	}

	if (par[u][0] != -1) {
		dp[par[u][0]] -= 1;
	}
}

void dfs1(int v, int p) {
	for (auto [u, w] : adjList[v]) {
		if (u == p) continue;
		dfs1(u, v);
		dp[v] += 1 + dp[u];
	}
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	int pi;
	long long wi;
	for (int i = 2; i <= n; i++) {
		cin >> pi >> wi;
		adjList[i].push_back({pi, wi});
		adjList[pi].push_back({i, wi});
	}

	memset(par, -1, sizeof par);

	dfs(1, -1);
	dfs1(1, -1);

	for (int v = 1; v <= n; v++) {
		cout << dp[v] << ' ';
	}
	cout << '\n';

	return 0;
}
