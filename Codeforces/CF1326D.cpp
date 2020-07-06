#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 100;
int n, m, p[N], col[N];
vector<int> adjList[N];
vector<int> colors[N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		adjList[a].emplace_back(b);
		adjList[b].emplace_back(a);
	}

	for (int i = 1; i <= n; i++) {
		cin >> a;
		colors[a].emplace_back(i);
	}

	int time = 0;
	for (int c = 1; c <= n; c++) {
		for (int v : colors[c]) {
			vector<int> sc;
			sc.push_back(0);
			for (int u : adjList[v]) {
				if (!col[u]) continue;
				sc.emplace_back(col[u]);
			}
			sort(sc.begin(), sc.end());
			
			for (int i = 1; i < sc.size(); i++) {
				if (sc[i] - sc[i - 1] > 1) {
					cout << - 1 << '\n';
					return 0;
				}
			}
			if (sc.back() != c - 1) {
				cout << - 1 << '\n';
				return 0;
			}

			col[v] = c;
			p[time++] = v;
		}
	}

	for (int i = 0; i < n; i++) {
		cout << p[i] << ' ';
	}
	cout << '\n';

	return 0;
}
