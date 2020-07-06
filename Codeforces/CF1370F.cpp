#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int N = 1005;
int t, n, depth[N], par[N];
vector<int> adjList[N];
vector<int> level[N];

void dfs(int v, int p) {
	par[v] = p;
	level[depth[v]].emplace_back(v);

	for (int u : adjList[v]) {
		if (u == p) continue;
		depth[u] = depth[v] + 1;
		dfs(u, v);
	}
}

pii query(const vector<int> &qs) {
	if (qs.empty()) {
		return {-1, 10000};
	}

	cout << "? " << qs.size();
	for (int x : qs) {
		cout << ' ' << x;
	}
	cout << endl;
	
	int v, d;
	cin >> v >> d;
	
	return {v, d};
}

void solve() {
	cin >> n;

	int a, b;
	for (int i = 1; i < n; i++) {
		cin >> a >> b;
		adjList[a].emplace_back(b);
		adjList[b].emplace_back(a);
	}

	vector<int> nq;
	for (int i = 1; i <= n; i++) {
		nq.emplace_back(i);
	}

	pii fq = query(nq);
	int root = fq.first;
	int d = fq.second;

	depth[root] = 0;
	dfs(root, -1);

	int l = d / 2;
	int r = d;

	int b1, b2;
	while (l <= r) {
		int m = (l + r) / 2;
		pii q = query(level[m]);
		if (q.second == d) {
			l = m + 1;
			b1 = q.first;
		}
		else {
			r = m - 1;
		}
	}

	set<int> ancestors;
	int v = b1;
	while (v != root) {
		ancestors.insert(v);
		v = par[v];
	}

	nq.clear();
	for (int x : level[d - depth[b1]]) {
		if (ancestors.count(x)) continue;
		nq.emplace_back(x);
	}

	pii lq = query(nq);
	b2 = lq.first;

	cout << "! " << b1 << ' ' << b2 << endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	string good;
	while (t--) {
		for (int i = 0; i <= n; i++) {
			adjList[i].clear();
			level[i].clear();
		}
		solve();
		cin >> good;
		if (good != "Correct") {
			return 0;
		}
	}

	return 0;
}
