#include <bits/stdc++.h>
using namespace std;
const int N = 300000;
int n, m;
bool vis[N + 5];
vector<int> adjList[N + 5], tree[N + 5];
unordered_map<int, unordered_map<int, int>> isBridge;

int tin[N + 5], low[N + 5];
int timer;

void bridges(int v, int p) {
	vis[v] = true;
	tin[v] = low[v] = ++timer;

	for (int u : adjList[v]) {
		if (u == p) continue;
		if (vis[u]) {
			low[v] = min(low[v], tin[u]);
			continue;
		}

		bridges(u, v);
		low[v] = min(low[v], low[u]);
		if (low[u] > tin[v]) {
			isBridge[u][v] = true;
			isBridge[v][u] = true;
		}
	}
}

int compnum = 1;
void build_tree(int v) {
	int currcomp = compnum++;

	queue<int> Q;
	Q.push(v);
	vis[v] = true;

	while (!Q.empty()) {
		int u = Q.front();
		Q.pop();

		for (int w : adjList[u]) {
			if (vis[w]) continue;

			if (isBridge[u][w]) {
				tree[currcomp].push_back(compnum);
				tree[compnum].push_back(currcomp);
				build_tree(w);
			}
			else {
				Q.push(w);
				vis[w] = true;
			}
		}
	}
}

int mxpath[N + 5];
int dfs(int v, int p, int d) {
	
	int f = 0;
	int s = 0;
	for (int u : tree[v]) {
		if (u == p) continue;
		int l = 1 + dfs(u, v, d + 1);
		if (l > f) {
			s = f;
			f = l;
		}
		else if (l > s) {
			s = l;
		}
	}

	mxpath[v] = f + s;
	return f;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	
	int x, y;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		adjList[x].emplace_back(y);
		adjList[y].emplace_back(x);
	}

	bridges(1, -1);
	memset(vis, 0, sizeof vis);

	build_tree(1);

	dfs(1, -1, 0);

	cout << *max_element(mxpath + 1, mxpath + compnum) << endl;

	return 0;
}
