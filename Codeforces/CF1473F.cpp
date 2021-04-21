#include <bits/stdc++.h>
using namespace std;
const int N = 3005;
int n, a[N], b[N];
long long cont[N];
bool used[N];

template <class T>
struct Dinic {
	struct Edge {
		int u, rev;
		T cap;
	};

	static const T MX = numeric_limits<T>::max();

	int n, s, t;
	vector<int> level, idx;
	vector<vector<Edge>> adjList;

	Dinic(int n, int s, int t):
		n(n), s(s), t(t), level(n), idx(n), adjList(n) {};

	void addEdge(int v, int u, T c) {
		adjList[v].push_back({u, (int) adjList[u].size(), c});
		adjList[u].push_back({v, (int) adjList[v].size() - 1, 0});
	}

	bool bfs() {
		queue<int> q;
		fill(level.begin(), level.end(), -1);

		q.push(s);
		level[s] = 0;
		while (!q.empty()) {
			int v = q.front();
			q.pop();

			if (v == t)
				return true;

			for (Edge e : adjList[v]) {
				if (e.cap <= 0 || level[e.u] != -1) continue;
				level[e.u] = level[v] + 1;
				q.push(e.u);
			}
		}

		return false;
	}

	T dfs(int v, T flow) {
		if (v == t)
			return flow;
		if (flow == 0)
			return 0;

		T cont = 0;
		for (; idx[v] < adjList[v].size(); idx[v]++) {
			Edge &e = adjList[v][idx[v]];

			if (e.cap <= 0 || level[e.u] <= level[v]) continue;
			T mnFlow = dfs(e.u, min(flow, e.cap));

			if (mnFlow > 0) {
				cont += mnFlow;
				flow -= mnFlow;
				e.cap -= mnFlow;
				adjList[e.u][e.rev].cap += mnFlow;
			}

			if (flow == 0) break;
		}
		return cont;
	}

	T maxFlow() {
		T flow, ans = 0;
		while (bfs()) {
			fill(idx.begin(), idx.end(), 0);
			while ((flow = dfs(s, MX)) > 0) {
				ans += flow;
			}
		}
		return ans;
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	Dinic<long long> mf(n + 2, 0, n + 1);

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	for (int i = 1; i <= n; i++) {
		cin >> b[i];
	}

	long long sum = 0;
	for (int i = 1; i <= n; i++) {
		if (b[i] >= 0) mf.addEdge(0, i, b[i]);
		else mf.addEdge(i, n + 1, -b[i]);

		set<int> seen;
		for (int j = i - 1; j > 0; j--) {
			if (a[i] % a[j] || seen.count(a[j])) continue;
			mf.addEdge(i, j, Dinic<long long>::MX);
			seen.insert(a[j]);
		}

		if (b[i] > 0)
			sum += b[i];
	}

	cout << sum - mf.maxFlow() << '\n';

	return 0;
}
