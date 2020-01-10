#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
int t, n, k, c, dist[16][16];
pii points[16];

int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[8] = {1, 2, 2 , 1, -1, -2, -2, -1};

int absDist[1000][1000];
bool absVis[1000][1000];

void BFS() {
	queue<pii> Q;

	Q.push({0, 0});
	while (!Q.empty()) {
		pii v = Q.front();
		Q.pop();

		for (int i = 0; i < 8; i ++) {
			int nx = v.first + dx[i];
			int ny = v.second + dy[i];

			if (nx < 1000 && nx >= 0 && ny >= 0 && ny < 1000 && !absVis[nx][ny]) {
				absVis[nx][ny] = true;
				absDist[nx][ny] = absDist[v.first][v.second] + 1;
				Q.push({nx, ny});
			}
		}
	}
}

int tempDist[1000][1000];
bool vis[1000][1000];

int BFS2(pii s, pii e) {
	memset(vis, 0 , sizeof vis);

	queue<pii> Q;

	Q.push(s);
	vis[s.first][s.second] = true;
	tempDist[s.first][s.second] = 0;
	
	while (!Q.empty()) {
		pii v = Q.front();
		Q.pop();
		if (v == e) {
			break;
		}

		for (int i = 0; i < 8; i ++) {
			int nx = v.first + dx[i];
			int ny = v.second + dy[i];

			if (nx < n && nx >= 0 && ny >= 0 && ny < n && !vis[nx][ny]) {
				vis[nx][ny] = true;
				tempDist[nx][ny] = tempDist[v.first][v.second] + 1;
				Q.push({nx, ny});
			}
		}
	}

	return tempDist[e.first][e.second];
}

int mem[(1 << 16)][16];
int dpv[(1 << 16)][16];

int dp(int m, int i) {
	if (dpv[m][i] == c) {
		return mem[m][i];
	}
	if (__builtin_popcount(m) == 2) {
		return dist[0][i];
	}

	dpv[m][i] = c;
	int ans = INT_MAX;
	for (int j = 1; j < k; j++) {
		if (m & (1 << j) && j != i) {
			ans = min(ans, dp(m & ~(1 << i), j) + dist[i][j]);
		}
	}
	return mem[m][i] = ans;
}

int solve() {
	cin >> n >> k;

	int x, y;
	for (int i = 0; i < k; i++) {
		cin >> x >> y;
		points[i] = {x - 1, y - 1};
	}

	for (int i = 0; i < k; i++) {
		pii v = points[i];
		for (int j = i + 1; j < k; j++) {
			pii u = points[j];

			if (u == v) {
				continue;
			}

			if (abs(u.first - v.first) + abs(u.second - v.second) > 30) {
				dist[i][j] = absDist[abs(u.first - v.first)][abs(u.second - v.second)];
			}
			else {
				dist[i][j] = BFS2(v, u);
			}
			dist[j][i] = dist[i][j];
		}
	}

	int ans = (k > 1) ? INT_MAX : 0;

	for (int i = 1; i < k; i++) {
		int tans = dp((1 << k) - 1, i) + dist[0][i];
		ans = min(tans, ans);
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	BFS();

	cin >> t;

	for (c = 1; c <= t; c++) {
		memset(dist, 0 , sizeof dist);
		cout << "Case " << c <<": " << solve() << '\n';
	}

	return 0;
}
