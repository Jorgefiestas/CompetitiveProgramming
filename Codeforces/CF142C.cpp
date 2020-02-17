#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
int n, m, idx, curr, nans = -1;
bool t[200][9][9];
char mat[9][9], ans[9][9];
int vis[9][9][4];

const int dx[4][5] = {{0, 0, 0, 1, 2}, {0, 1, 1, 1, 2}, {0, 1, 2, 2, 2}, {0, 1, 1, 1, 2}};
const int dy[4][5] = {{0, 1, 2, 1, 1}, {0, 0, 1, 2, 0}, {1, 1, 0, 1, 2}, {2, 0, 1, 2, 2}};

bool free(int x, int y, int s) {
	for (int i = 0; i < 5; i++) {
		int tx = x + dx[s][i];
		int ty = y + dy[s][i];
		
		if (tx < 0 || tx >= n) {
			return false;
		}
		if (ty < 0 || ty >= m) {
			return false;
		}
		if (mat[tx][ty] != '.') {
			return false;
		}
	} 
	return true;
}

bool add(int x, int y, int s) {
	for (int i = 0; i < 5; i++) {
		int tx = x + dx[s][i];
		int ty = y + dy[s][i];
		mat[tx][ty] = 'A' + curr;
	} 
	return true;
}

bool remove(int x, int y, int s) {
	for (int i = 0; i < 5; i++) {
		int tx = x + dx[s][i];
		int ty = y + dy[s][i];
		mat[tx][ty] = '.';
	} 
	return true;
}

bool copy() {
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < m; y++) {
			ans[x][y] = mat[x][y];
		}
	}
	return true;
}

void solve(int idx, int si, int sj) {
	if (nans == 13) {
		return;
	}

	bool last = true;

	if ((n - si) * m / 5 <= nans - idx) {
		return;
	}

	if (idx == 0) {
		for (int j = 0; j < m - 2; j++) {
			for (int s = 0; s < 1; s++) {
				if (!free(0, j, s)) continue;
				last = false;

				add(0, j, s);
				++curr;
				solve(idx + 1, 0, j);
				--curr;
				remove(0, j, s);
			}
		}
	}

	else {
		int cnt = 0;
		for (int i = si; i < n - 2; i++) {
			for (int j = (i == si) ? sj : 0; j < m - 2; j++) {
				cnt ++;
				for (int s = 0; s < 4; s++) {
					if (!free(i, j, s)) continue;
					if (idx < vis[i][j][s] - 1) continue;


					add(i, j, s);
					++curr;
					solve(idx + 1, i, j);
					vis[i][j][s] = idx;
					--curr;
					remove(i, j, s);

					if(idx == 0) break;
				}
				if (cnt == 10) break;
			}
			if (cnt == 10) break;
		}
	}

	if (last) {
		if (idx > nans) {
			nans = idx;
			copy();
		}
	}
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			mat[i][j] = '.';
		}
	}

	solve(0, -1, -1);

	cout << nans << '\n';
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << ans[i][j];
		}
		cout << '\n';
	}

	return 0;
}
