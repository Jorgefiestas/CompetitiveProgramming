#include <bits/stdc++.h>
using namespace std;
const int N = 55;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
int n, m, cnt;
char mat[N][N];
bool vis[N][N];

bool check(int x, int y) {
	return !vis[x][y] && mat[x][y] == '#';
}

int dfs(int x, int y) {
	vis[x][y] = true;
	int ans = 1;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (check(nx, ny)) {
			ans += dfs(nx, ny);
		}
	}
	return ans;
}

bool connected() {
	memset(vis, 0, sizeof vis);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (mat[i][j] != '#') continue;
			return dfs(i, j) == cnt;
		}
	}

	return true;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> mat[i][j];
			cnt += mat[i][j] == '#';
		}
	}

	if (!connected()) {
		cout << 0 << '\n';
		return 0;
	}

	if (cnt <= 2) {
		cout << -1 << '\n';
		return 0;
	}

	cnt -= 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (mat[i][j] != '#') continue;
			mat[i][j] = '.';
			if (!connected()) {
				cout << 1 << '\n';
				return 0;
			}
			mat[i][j] = '#';
		}
	}

	cout << 2 << '\n';
	return 0;
}
