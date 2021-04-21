#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 100;
int n, k[3], cnt[3][N], mn[N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 3; i++) {
		cin >> k[i];
		n += k[i];
	}
	for (int i = 0; i < 3; i++) {
		int x;
		for (int j = 0; j < k[i]; j++) {
			cin >> x;
			cnt[i][x] += 1;
		}

		for (int j = 1; j <= n; j++) {
			cnt[i][j] += cnt[i][j - 1];
		}
	}

	mn[n + 1] = INT_MAX;
	for (int i = n; i >= 0; i--) {
		int score = k[1] + cnt[2][i] - cnt[1][i];
		mn[i] = min(mn[i + 1], score);
	}

	int ans = INT_MAX;
	for (int x = 0; x <= n; x++) {
		int can = k[0] - cnt[0][x] + cnt[1][x] + mn[x];
		ans = min(ans, can);
	}

	cout << ans << '\n';

	return 0;
}
