#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int N = 55;
int n;
char mat[N][N], check[N][N], ans[2 * N][2 * N];
set<pii> poss;
vector<pii> piece;

bool checkMove(pii a, pii b) {
	int nx = a.first + b.first;
	int ny = a.second + b.second;

	if (nx <= 0 || nx > n) {
		return true;
	}
	if (ny <= 0 || ny > n) {
		return true;
	}
	return mat[nx][ny] != '.';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> mat[i][j];
			check[i][j] = '.';
			if (mat[i][j] == 'o') {
				piece.push_back({i, j});
			}
		}
	}

	for (int i = 1 - n; i < n; i++) {
		for (int j = 1 - n; j < n; j++) {
			poss.insert({i, j});
		}
	}

	for (pii p : piece) {
		for (auto it = poss.begin(); it != poss.end();) {
			if (checkMove(p, *it)) {
				it = next(it);
			}
			else {
				it = poss.erase(it);
			}
		}
	}

	for (pii p : piece) {
		check[p.first][p.second] = 'o';
		for (pii d : poss) {
			int nx = p.first + d.first;
			int ny = p.second + d.second;
			if (nx <= 0 || nx > n) continue;
			if (ny <= 0 || ny > n) continue;
			if (check[nx][ny] != '.') continue;
			check[nx][ny] = 'x';
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (mat[i][j] != check[i][j]) {
				cout << "NO\n";
				return 0;
			}
		}
	}

	for (pii p : poss) {
		ans[p.first + n][p.second + n] = 'x';
	}
	ans[n][n] = 'o';

	cout << "YES\n";

	for (int i = 1; i < 2 * n; i++) {
		for (int j = 1; j < 2 * n; j++) {
			ans[i][j] = ans[i][j] ? ans[i][j] : '.';
			cout << ans[i][j];
		}
		cout << '\n';
	}

	return 0;
}
