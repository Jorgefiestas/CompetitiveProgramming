#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int N = 1e6 + 10;
int n, arr[N];
pii seg[N];
vector<int> adjList[N];

int idx = 2;
void dfs(int v, int p) {
	for (int i = 0; i < adjList[v].size(); i++) {
		int u = adjList[v][i];
		if (u == p) continue;
		arr[idx] = u;
		idx += 1;
	}

	arr[idx] = v;
	idx += 1;

	for (int i = adjList[v].size() - 1; i >= 0; i--) {
		int u = adjList[v][i];
		if (u == p) continue;
		dfs(u, v);
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

	arr[1] = 1;
	dfs(1, -1);

	for (int i = 1; i <= 2 * n; i++) {
		int x = arr[i];
		if (!seg[x].first) {
			seg[x].first = i;
		}
		else {
			seg[x].second = i;
		}
	}

	for (int i = 1; i <= n; i++) {
		cout << seg[i].first << ' ' << seg[i].second << '\n';
	}

	return 0;
}
