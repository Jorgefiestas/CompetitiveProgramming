#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int mod = 1e9 + 7;
int n, hcnt;
vector<int> adjList[N];
map<vector<int>, int> hashed;
unordered_map<int, int> mem[N];
unordered_map<int, bool> vis[N];

void dfs(int v, int p) {
	if (vis[v][p]) {
		return;
	}
	vis[v][p] = true;

	vector<int> hashes;
	for (int u : adjList[v]) {
		if (u == p) continue;
		dfs(u, v);
		hashes.emplace_back(mem[u][v]);
	}

	sort(hashes.begin(), hashes.end());
	if (!hashed.count(hashes)) {
		hashed[hashes] = ++hcnt;
	}

	mem[v][p] = hashed[hashes];
	return;
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

	set<int> unHash;
	for (int i = 1; i <= n; i++) {
		if (adjList[i].size() >= 4) continue;

		dfs(i, 0);
		unHash.insert(mem[i][0]);
	}

	cout << unHash.size() << '\n';

	return 0;
}
