#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
int n, m, sx, sy;
set<pii> vis;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> sx >> sy;

	cout << sx << ' ' << sy << '\n';
	cout << 1 << ' ' << sy << '\n';
	cout << 1 << ' ' << 1 << '\n';

	vis.insert({sx, sy});
	vis.insert({1, sy});
	vis.insert({1, 1});

	for (int i = 1; i <= n; i++) {
		int sj = (i % 2) ? 1 : m;
		int ej = (i % 2) ? m + 1 : 0;
		int dj = (i % 2) ? 1 : -1;

		for (int j = sj; j != ej; j += dj) {
			if (vis.count({i, j})) continue;
			cout << i << ' ' << j << '\n';
		}
	}

	return 0;
}
