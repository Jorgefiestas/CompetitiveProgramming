#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 100;
const long long mod = 1e9 + 7;
int n, par[N];
vector<int> adjList[N];
long long mem[N][2];
bool vis[N][2];

long long dp(int v, int c) {
	if (vis[v][c]) {
		return mem[v][c];
	}
	vis[v][c] = true;

	long long wans = 1;
	long long bans = c;
	for (int u : adjList[v]) {
		if (u == par[v]) continue;
		par[u] = v;
		wans = (wans * dp(u, 1)) % mod;
		bans = (bans * dp(u, 0)) % mod;
	}

	return mem[v][c] = (wans + bans) % mod;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	int a, b;
	for (int i = 1; i < n; i++) {
		cin >> a >> b;
		adjList[a].emplace_back(b);
		adjList[b].emplace_back(a);
	}

	cout << dp(1, 1) << '\n';

	return 0;
}
