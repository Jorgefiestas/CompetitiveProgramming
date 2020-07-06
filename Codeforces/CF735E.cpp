#include <bits/stdc++.h>
using namespace std;
const int N = 105;
const int mod = 1e9 + 7;
int n, k;
vector<int> adjList[N];

int add(int x, int y) {
	if (x + y >= mod) {
		return x + y - mod;
	}
	return x + y;
}

int dp(int v, int k, int p) {
	if (vis[v][k]) {
		return mem[v][k];
	}
	vis[v][k] = true;

	int ans = 0;
	for (int u : adjList[v]) {
		if (u == p) continue;

		if (k) {
			ans = add(ans, dp(u, k - 1, v));
		}
		ans = add(ans, dp(u, k));
	}

	return mem[v][k] = ans;
}

int main() {
	ios_base::sync_with_stido(0);
	cin.tie(0);

	cin >> n >> k;

	int a, b;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		adjList[a].emplace_back(b);
		adjList[b].emplace_back(a);
	}
}
