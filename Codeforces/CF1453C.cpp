#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int N = 2005;
int t, n, a[N][N];
int res[N], back[10], fron[10], top[10], bot[10];
vector<pii> pos[10];

void solve() {
	cin >> n;

	char mij;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> mij;
			int d = mij - '0';
			a[i][j] = d;

			back[d] = min(back[d], i);
			fron[d] = max(fron[d], i);
			top[d] = min(top[d], j);
			bot[d] = max(bot[d], j);
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int d = a[i][j];

			int w1 = max(fron[d] - i, i - back[d]);
			int h1 = max(n - j, j - 1);
			res[d] = max(res[d], w1 * h1);

			int w2 = max(n - i, i - 1);
			int h2 = max(bot[d] - j, j - top[d]);
			res[d] = max(res[d], w2 * h2);

		}
	}

	for (int i = 0; i < 10; i++) {
		cout << res[i] << ' ';
	}
	cout << '\n';

}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		memset(res, 0, sizeof res);
		memset(top, 1, sizeof top);
		memset(bot, 0, sizeof bot);
		memset(back, 1, sizeof back);
		memset(fron, 0, sizeof fron);
		for (int i = 0; i < 10; i++) {
			pos[i].clear();
		}

		solve();
	}

	return 0;
}
