#include <bits/stdc++.h>
using namespace std;
const int N = 205;
int n, t, ans[N][N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> t;

	ans[N / 2][N / 2] = n;

	bool change = true;
	while (change) {
		change = false;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (ans[i][j] < 4) continue;
				change = true;

				ans[i][j - 1] += ans[i][j] / 4;
				ans[i][j + 1] += ans[i][j] / 4;
				ans[i + 1][j] += ans[i][j] / 4;
				ans[i - 1][j] += ans[i][j] / 4;

				ans[i][j] = ans[i][j] % 4;
			}
		}
	}

	int x, y;
	for (int i = 0; i < t; i++) {
		cin >> x >> y;
		x += N / 2;
		y += N / 2;

		if (x < 0 || x >= N || y < 0 || y >= N) {
			cout << 0 << '\n';
		}
		else {
			cout << ans[x][y] << '\n';
		}
		
	}

	return 0;
}
