#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
int t, n, m;
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};
string maze[1000];
queue<pii> Q;

int solve() {
	pii J;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (maze[i][j] == 'J') {
				J = {i, j};
			}
			else if (maze[i][j] == 'F') {
				Q.push({i, j});
			}
		}
	}

	Q.push(J);

	while (!Q.empty()) {
		pii v = Q.top();
		Q.pop();

		if (maze[v.first][v.second] == 'J' || maze[v.first][v.second] == 'D') {
			state = true;
		}
		else {
			state = false;
		}

		for (int i = 0; i < 4; i++) {
			int nx = v.first + dx[i];
			int ny = v.second + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
				if (state) {
					return r[nx][ny];
				}
				continue;
			}

			if (state) {
				if (maze[nx][ny] != '.') {
					continue;
				}
				maze[nx][ny] = 'J';
				r[nx][ny] = r[v.first][v.second] + 1;
				Q.push({nx, ny});
			}

			else {
				if (maze[nx][ny] != '.' && maze[nx][ny] != 'J' && maze != 'K') {
					continue;
				}
				maze[nx][ny] = (maze[nx][ny] == '.') ? 'F' : 'D';
				r[nx][ny] = r[v.first][v.second] + 1;
				Q.push({nx, ny});
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
		Q.clear();

		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			cin >> maze[i];
		}

		int ans = solve();
		if (ans != -1) {
			cout << ans << '\n';
		}
		else {
			cout << "IMPOSSIBLE\n";
		}
	}

	return 0;
}
