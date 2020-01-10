#include <bits/stdc++.h>
using namespace std;
int n, m, mxp, x;
vector<int> adjList[10005];

void dfs(int v, int p, int r) {
	if (r > mxp) {
		mxp = r;
		x = v;
	}
	
	for (int u : adjList[v]) {
		if (u == p) continue;
		dfs(u, v, r + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	int a, b;
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b;
		adjList[a].emplace_back(b);
		adjList[b].emplace_back(a);
	}

	dfs(1, -1, 0);

	mxp = 0;

	dfs(x, -1, 0);

	cout << mxp << endl;

	return 0;
}
