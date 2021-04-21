#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int N = 2e5 + 10;
int n, e[N], dpth[N], mxd[N];
vector<int> adjList[N];

pii dfs1(int v, int p, int d) {
	mxd[v] = 1;
	pii mx = {d, v};
	for (int u : adjList[v]) {
		if (u == p) continue;
		mx = max(mx, dfs1(u, v, d + 1));
		mxd[v] = max(mxd[v], mxd[u] + 1);
	}
	return mx;
}


int num = 1;
void dfs2(int v, int p) {
	e[v] = num++;

	pii best = {0, -1};
	for (int u : adjList[v]) {
		if (u == p) continue;
		best = max(best, {mxd[u], u});
	}

	for (int u : adjList[v]) {
		if (u == p || u == best.second) continue;
		dfs2(u, v);
	}

	if (best.second != -1) {
		dfs2(best.second, v);
	}

	num++;
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

	auto [dt, r] = dfs1(1, -1, 0);
	dfs1(r, -1, 0);
	dfs2(r, -1);

	for (int v = 1; v <= n; v++) {
		cout << e[v] << ' ';
	}
	cout << '\n';

	return 0;
}
