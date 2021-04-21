#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int N = 2005;
const int dx[] = {1, 1, -1, -1};
const int dy[] = {1, -1, 1, -1};
int n;
long long a[N][N], score[N][N];
long long diag[N][N][4];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}

	for (int i = n; i > 0; i--) {
		for (int j = 1; j <= n; j++) {
			for (int d = 0; d < 2; d++) {
				int ni = i + dx[d];
				int nj = j + dy[d];
				diag[i][j][d] = diag[ni][nj][d];
				diag[i][j][d] += a[i][j];
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int d = 2; d < 4; d++) {
				int ni = i + dx[d];
				int nj = j + dy[d];
				diag[i][j][d] = diag[ni][nj][d];
				diag[i][j][d] += a[i][j];
			}

			score[i][j] = a[i][j];
			for (int d = 0; d < 4; d++) {
				int ni = i + dx[d];
				int nj = j + dy[d];
				score[i][j] += diag[ni][nj][d];
			}
		}
	}

	pii pos[2];
	long long ans[2] = {-1, -1};
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int idx = (i + j) % 2;

			if (score[i][j] > ans[idx]) {
				ans[idx] = score[i][j];
				pos[idx].first = i;
				pos[idx].second = j;
			}
		}
	}

	cout << ans[0] + ans[1] << '\n';
	for (int i = 0; i < 2; i++) {
		cout << pos[i].first << ' ' << pos[i].second << ' ';
	}
	cout << '\n';
	
	return 0;
}
