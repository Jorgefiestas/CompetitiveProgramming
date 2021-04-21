#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int N = 1e3 + 10;
const int dx[] = {1, 0, 0, -1};
const int dy[] = {0, -1, 1, 0};
const char w[] = {'D', 'L', 'R', 'U'};
int n, m, k, dist[N][N];
char mat[N][N];

bool check(int x, int y) {
	if (x < 1 || x > n) return false;
	if (y < 1 || y > m) return false;
	return mat[x][y] != '*';
}

int impossible() {
	cout << "IMPOSSIBLE\n";
	return 0;
}

bool vis[N][N];
void bfs(int sx, int sy) {
	queue<pii> q;
	q.push({sx, sy});
	vis[sx][sy] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int di = 0; di < 4; di++) {
			int nx = x + dx[di];
			int ny = y + dy[di];
			if (!vis[nx][ny] && check(nx, ny)) {
				q.push({nx, ny});
				vis[nx][ny] = true;
				dist[nx][ny] = dist[x][y] + 1;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;

	int sx, sy;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> mat[i][j];
			if (mat[i][j] == 'X') {
				sx = i;
				sy = j;
			}
		}
	}

	bool trapped = true;
	for (int di = 0; di < 4; di++) {
		int nx = sx + dx[di];
		int ny = sy + dy[di];
		if (check(nx, ny)) {
			trapped = false;
		}
	}

	if (trapped || k % 2) {
		return impossible();
	}

	bfs(sx, sy);

	int x = sx;
	int y = sy;
	string path;
	for (int i = 1; i <= k; i++) {
		for (int di = 0; di < 4; di++) {
			int nx = x + dx[di];
			int ny = y + dy[di];

			if (check(nx, ny) && dist[nx][ny] <= k - i) {
				path += w[di];
				x = nx;
				y = ny;
				break;
			}
		}
	}

	cout << path << '\n';
	return 0;
}
