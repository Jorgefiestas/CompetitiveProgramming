#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 100;
const long long mod = 1e9 + 7;
int t, n, m, sz[N];
long long p[N];
vector<int> adjList[N];
vector<long long> cont;

int add(int x, int y) {
	if (x + y >= mod) {
		return x + y - mod;
	}
	return x + y;
}

int mul(long long x, long long y) {
	x = x % mod;
	y = y % mod;
	return x * y % mod;
}

void dfs(int v, int p) {
	sz[v] = 1;
	for (int u : adjList[v]) {
		if (u == p) continue;
		dfs(u, v);
		sz[v] += sz[u];
	}

	long long c = (long long) (n - sz[v]) * sz[v];
	cont.push_back(c);
}

void getLabels() {
	if (m > n - 1) {
		sort(p, p + m);
		while (m > n - 1) {
			p[m - 2] = mul(p[m - 1], p[m - 2]);
			m -= 1;
		}
	}
	else {
		while (m < n - 1) {
			p[m] = 1;
			m += 1;
		}
		sort(p, p + m);
	}
}

int solve() {
	cin >> n;

	int a, b;
	for (int i = 1; i < n; i++) {
		cin >> a >> b;
		adjList[a].emplace_back(b);
		adjList[b].emplace_back(a);
	}

	cin >> m;

	for (int i = 0; i < m; i++) {
		cin >> p[i];
	}

	dfs(1, -1);
	cont.pop_back();
	sort(cont.begin(), cont.end());

	getLabels();

	int ans = 0;
	for (int i = 0; i < n - 1; i++) {
		ans = add(ans, mul(p[i], cont[i]));
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		cont.clear();
		for (int i = 0; i <= n; i++) {
			adjList[i].clear();
		}
		cout << solve() << '\n';
	}

	return 0;
}
