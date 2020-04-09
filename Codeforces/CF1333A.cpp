#include <bits/stdc++.h>
using namespace std;
int t, n, m;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;

	while (t--) {
		cin >> n >> m;

		char ans[n][m];

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				ans[i][j] = 'B';
			}
		}

		int cnt = n * m / 2;
		if ((n * m) % 2 == 0) {
			cnt--;
		}

		for (int i = 0; i < n; i++) {
			for (int j = !(i % 2); j < m; j += 2) {
				if (!cnt) break;
				ans[i][j] = 'W';
				cnt--;
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << ans[i][j];
			}
			cout << endl;
		}
	}

	return 0;
}
