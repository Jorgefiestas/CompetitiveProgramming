#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
int n, m, r, c;
bool row[N], col[N], vis[N][N];
string mat[N];

bool check() {
	for (int i = 0; i < n; i++) {
		bool seen = mat[i][0] == '#';
		for (int j = 1; j < m; j++) {
			if (mat[i][j] == '.') continue;
			if (mat[i][j - 1] == '#' || !seen) {
				seen = true;
			}
			else {
				return false;
			}
		}
	}

	for (int i = 0; i < m; i++) {
		bool seen = mat[0][i] == '#';
		for (int j = 1; j < n; j++) {
			if (mat[j][i] == '.') continue;
			if (mat[j - 1][i] == '#' || !seen) {
				seen = true;
			}
			else {
				return false;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (mat[i][j] == '.') continue;
			if (!row[i]) {
				row[i] = true;
				r--;
			}
			if (!col[j]) {
				col[j] = true;
				c--;
			}
		}
	}

	return !!r == !!c;
}

bool check_pos(int x, int y) {
	if (x < 0 || x >= n) return false;
	if (y < 0 || y >= m) return false;
	if (vis[x][y] || mat[x][y] == '.') return false;
	return true;
}

void dfs(int x, int y) {
	vis[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (!check_pos(nx, ny)) continue;
		dfs(nx, ny);
	}
}

int main() {
	cin >> n >> m;
	r = n, c = m;

	for (int i = 0; i < n; i++) {
		cin >> mat[i];
	}

	if (!check()) {
		cout << -1 << '\n';
		return 0;
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <  m; j++) {
			if (vis[i][j] || mat[i][j] == '.') continue;
			ans++;
			dfs(i, j);
		}
	}

	cout << ans << '\n';

	return 0;
}
