#include <bits/stdc++.h>
using namespace std;
const int N = 505;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
int r, c;
char mat[N][N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> r >> c;

	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			cin >> mat[i][j];
		}
	}

	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			if (mat[i][j] != 'S') continue;
			for (int d = 0; d < 4; d++) {
				int ni = i + dx[d];
				int nj = j + dy[d];

				if (mat[ni][nj] == '.') {
					mat[ni][nj] = 'D';
				}
				else if (mat[ni][nj] == 'W') {
					cout << "No\n";
					return 0;
				}
			}
		}
	}

	cout << "Yes\n";
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			cout << mat[i][j];
		}
		cout << '\n';
	}

	return 0;
}
