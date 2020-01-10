#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
int t, n, m;
string maze[1000];
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

int solve() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> maze[i];
	}

	int r[1000][1000];

	queue<pii> pq;
	queue<bool> tq;
	pii J;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (maze[i][j] == 'J') {
				J = {i, j};
				r[i][j] = 0;
			}
			else if (maze[i][j] == 'F') {
				pq.push({i, j});
				tq.push(false);
				r[i][j] = 0;
			}
		}
	}

	pq.push(J);
	tq.push(true);

	while (!pq.empty()) {
		pii v = pq.front();
		bool state = tq.front();
		pq.pop();
		tq.pop();

		for (int i = 0; i < 4; i++) {
			int nx = v.first + dx[i];
			int ny = v.second + dy[i];
			char tile = maze[nx][ny];

			if (nx >= n || nx < 0 || ny >= m || ny < 0) {
				if (state) {
					return r[v.first][v.second] + 1;
				}
				continue;
			}

			if (tile == '.') {
				pq.push({nx, ny});
				tq.push(state);
				maze[nx][ny] = 'F';
				r[nx][ny] = r[v.first][v.second] + 1;
			}
		}
	}

	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> t;
	while (t--) {
		int ans = solve();
		if (ans != -1) {
			cout << ans << endl;
		}
		else {
			cout << "IMPOSSIBLE" << endl;
		}
	}

	return 0;
}
