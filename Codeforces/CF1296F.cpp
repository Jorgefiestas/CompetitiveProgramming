#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int N = 5005;
int n, m, par[N], beauty[N];
vector<int> adjList[N];
map<int, int> score[N];
vector<pii> edg, query;

void maximize(int s, int e, int b) {
	memset(par, 0, sizeof par);

	queue<int> q;
	q.push(s);

	while (!q.empty()) {
		int v = q.front();
		q.pop();

		if (v == e) break;

		for (int u : adjList[v]) {
			if (u == par[v]) continue;
			par[u] = v;
			q.push(u);
		}
	}

	int v = e;

	while (par[v]) {
		int p = par[v];
		score[v][p] = max(score[v][p], b);
		score[p][v] = max(score[p][v], b);
		v = p;
	}
}

int minimize(int s, int e) {
	memset(par, 0, sizeof par);

	queue<int> q;
	q.push(s);

	while (!q.empty()) {
		int v = q.front();
		q.pop();

		if (v == e) break;

		for (int u : adjList[v]) {
			if (u == par[v]) continue;
			par[u] = v;
			q.push(u);
		}
	}

	int v = e;

	int mn = INT_MAX;
	while (par[v]) {
		int p = par[v];
		mn = min(score[v][p], mn);
		v = p;
	}

	return mn;
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
		edg.push_back({a, b});
	}

	cin >> m;

	int u, v, bi;
	for (int i = 0; i < m; i++) {
		cin >> u >> v >> bi;
		maximize(u, v, bi);
		query.push_back({u, v});
		beauty[i] = bi;
	}

	for (int i = 0; i < m; i++) {
		int u = query[i].first;
		int v = query[i].second;
		if (minimize(u, v) != beauty[i]) {
			cout << -1 << '\n';
			return 0;
		}
	}

	for (pii e : edg) {
		cout << max(score[e.first][e.second], 1) << ' ';
	}
	cout << '\n';

	return 0;
}
