#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int N = 405;
const int mod = 998244353;
int n, m, d[N][N];
vector<pii> edges;
vector<int> adjList[N];

int mul(int x, int y) {
	return (long long) x * y % mod;
}

int count(int s, int t) {
	vector<int> cnt(n + 1, 0);

	for (auto [u, v] : edges) {
		if (d[s][u] == d[s][v]) continue;
		if (abs(d[t][u] - d[t][v]) != 1) continue;

		if (d[s][u] > d[s][v])
			swap(u, v);

		if (d[t][u] < d[t][v])
			cnt[v] += 1;
	}

	while (t != s) {
		for (int u : adjList[t]) {
			if (d[s][u] < d[s][t]) {
				cnt[t] += 1;
				t = u;
				break;
			}
		}
	}

	int ans = 1;
	for (int v = 1; v <= n; v++) {
		if (v == s) continue;
		ans = mul(ans, cnt[v]);
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			d[i][j] = i == j ? 0 : INT_MAX;
		}
	}

	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		d[a][b] = 1;
		d[b][a] = 1;
		adjList[a].emplace_back(b);
		adjList[b].emplace_back(a);
		edges.push_back({a, b});
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			if (d[i][k] == INT_MAX) continue;
			for (int j = 1; j <= n; j++) {
				if (d[k][j] == INT_MAX) continue;
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}

	for (int v = 1; v <= n; v++) {
		for (int u = 1; u <= n; u++) {
			cout << count(u, v) << ' ';
		}
		cout << '\n';
	}

	return 0;
}
