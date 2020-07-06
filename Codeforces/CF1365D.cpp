#include <bits/stdc++.h>
using namespace std;
const int N = 55;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
int t, n, m;
char mat[N][N];
bool vis[N][N];

bool barricade(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (mat[nx][ny] == 'G') {
			return false;
		}
		if (mat[nx][ny] != 'B') {
			mat[nx][ny] = '#';
		}
	}

	return true;
}

bool check(int x, int y) {
	return !vis[x][y] && mat[x][y] != '#';
}

void dfs(int x, int y) {
	vis[x][y] = true;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (check(nx, ny)) {
			dfs(nx, ny);
		}
	}
}

bool solve() {
	cin >> n >> m;

	for (int j = 0; j <= m + 1; j++) {
		mat[0][j] = '#';
	}
	for (int i = 1; i <= n; i++) {
		mat[i][0] = '#';
		for (int j = 1; j <= m; j++) {
			cin >> mat[i][j];
		}
		mat[i][m + 1] = '#';
	}
	for (int j = 0; j <= m + 1; j++) {
		mat[n + 1][j] = '#';
	}

	if (mat[n][m] == 'B') {
		return false;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (mat[i][j] == 'B') {
				if (barricade(i, j)) continue;
				return false;
			}
		}
	}

	if (check(n, m)) {
		dfs(n, m);
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (mat[i][j] != 'G') continue;
			if (!vis[i][j]) {
				return false;
			}
		}
	}

	return true;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		memset(vis, 0, sizeof vis);
		if (solve()) {
			cout << "Yes\n";
		}
		else {
			cout << "No\n";
		}
	}

	return 0;
}
