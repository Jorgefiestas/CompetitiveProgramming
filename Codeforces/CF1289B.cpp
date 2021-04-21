#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int t, n, k, z, a[N];
int mem[N][2][6];
bool vis[N][2][6];

int calc(int cnt, bool rep, int left) {
	int idx = cnt - 2 * left;
	if (cnt == k) {
		return a[idx];
	}
	if (vis[cnt][rep][left]) {
		return mem[cnt][rep][left];
	}
	vis[cnt][rep][left] = true;

	int score = calc(cnt + 1, false, left);

	if (!rep && left < z && idx > 0) {
		score = max(score, calc(cnt + 1, true, left + 1));
	}

	score += a[idx];

	return mem[cnt][rep][left] = score;
}

int solve() {
	cin >> n >> k >> z;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	return calc(0, false, 0);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;

	while (t--) {
		cout << solve() << '\n';

		for (int i = 0; i <= n; i++) {
			for (int j = 0; j < 2; j++) {
				for (int k = 0; k < 6; k++) {
					mem[i][j][k] = 0;
					vis[i][j][k] = false;
				}
			}
		}
	}

	return 0;
}
