#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int N = 305;
int n, k, arr[N], idx[N];
int cnt[N], lft[N];
vector<int> adjList[N], path;
vector<pii> leafs[N];

void dfs(int v, int p) {
	if (v != 1 && adjList[v].size() == 1) {
		lft[v] = idx[v];
		cnt[v] = 1;
		return;
	}

	for (int u : adjList[v]) {
		if (u == p) continue;
		dfs(u, v);
		leafs[v].push_back({lft[u], u});
		cnt[v] += cnt[u];
	}

	sort(leafs[v].begin(), leafs[v].end());

	lft[v] = leafs[v][0].first;
}

int nxt = 0;
bool poss = true;
void route(int v, int p) {
	path.emplace_back(v);

	if (leafs[v].size() == 0) {
		poss = poss && arr[nxt] == v;
		nxt += 1;
	}

	for (pii pr : leafs[v]) {
		int u = pr.second;
		route(u, v);
		path.emplace_back(v);
	}
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

	for (int i = 2; i <= n; i++) {
		if (adjList[i].size() == 1) {
			k++;
		}
	}

	for (int i = 0; i < k; i++) {
		cin >> arr[i];
		idx[arr[i]] = i;
	}

	dfs(1, - 1);
	route(1, -1);
	
	if (!poss) {
		cout << -1 << '\n';
		return 0;
	}

	for (int v : path) {
		cout << v << ' ';
	}
	cout << '\n';

	return 0;
}
