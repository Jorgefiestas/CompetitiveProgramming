#include <bits/stdc++.h>
using namespace std;
const int N = 15;
int t, n, m, a[N][N];

int solve() {
	cin >> n >> m;

	int sum = 0;
	int mn = INT_MAX;

	int z = 0, cnt = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];

			sum += abs(a[i][j]);
			mn = min(mn, abs(a[i][j]));

			if (a[i][j] < 0) {
				cnt += 1;
			}
			if (a[i][j] == 0) {
				z += 1;
			}
		}
	}

	if (z || cnt % 2 == 0) {
		return sum;
	}
	return sum - 2 * mn;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		cout << solve() << '\n';
	}

	return 0;
}
