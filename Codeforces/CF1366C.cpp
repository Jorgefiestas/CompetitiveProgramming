#include <bits/stdc++.h>
using namespace std;
const int N = 100;
int t, n, m;
int cnt[N][2];

int solve() {
	cin >> n >> m;

	int len = n + m - 2;

	int c;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> c;
			int idx = i + j;
			if (idx > len / 2) {
				idx = len - idx;
			}

			cnt[idx][c] += 1;
		}
	}

	int cost = 0;
	for (int i = 0; i < (len + 1) / 2; i++) {
		cost += min(cnt[i][0], cnt[i][1]);
	}

	return cost;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		memset(cnt, 0, sizeof cnt);
		cout << solve() << '\n';
	}

	return 0;
}
