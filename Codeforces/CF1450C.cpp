#include <bits/stdc++.h>
using namespace std;
const int N = 305;
int t, n, k;
char mat[N][N], res[N][N];

bool fill(int x, int o) {
	int cnt = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int id = (i + j) % 3;

			if (mat[i][j] == '.') {
				res[i][j] = '.';
			}
			else if (id == x) {
				cnt += (mat[i][j] == 'O');
				res[i][j] = 'X';
			}
			else if (id == o) {
				cnt += (mat[i][j] == 'X');
				res[i][j] = 'O';
			}
			else {
				res[i][j] = mat[i][j];
			}
		}
	}

	if (cnt > k / 3) {
		return false;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << res[i][j];
		}
		cout << '\n';
	}

	return true;
}

void solve() {
	cin >> n;
	k = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mat[i][j];
			k += (mat[i][j] != '.');
		}
	}

	for (int x = 0; x < 3; x++) {
		for (int o = 0; o < 3; o++) {
			if (x == o) continue;
			if (fill(x, o))
				return;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}
