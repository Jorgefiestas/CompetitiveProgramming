#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int n, m, col[N], dist[N];
vector<int> revList[2][N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	memset(dist, -1, sizeof dist);
	memset(col, -1, sizeof col);

	cin >> n >> m;

	int a, b, t;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> t;
		revList[t][b].push_back(a);
	}

	queue<int> q;
	q.push(n);
	dist[n] = 0;

	while (!q.empty()) {
		int v = q.front();
		q.pop();

		for (int c = 0; c < 2; c++) {
			for (int u : revList[c][v]) {
				if (dist[u] != -1) continue;

				if (col[u] == -1) {
					col[u] = 1 - c;
				}
				if (col[u] == c) {
					dist[u] = dist[v] + 1;
					q.push(u);
				}
			}
		}
	}

	cout << dist[1] << '\n';

	for (int v = 1; v <= n; v++) {
		if (col[v] == -1) col[v] = 0;
		cout << col[v];
	}
	cout << '\n';

	return 0;
}
