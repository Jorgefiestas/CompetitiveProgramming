#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int tc, n, t[N], x[N];

int solve() {
	cin >> n;

	int cx = 0;
	int to = 0;

	for (int i = 1; i <= n; i++) {
		cin >> t[i] >> x[i];
	}

	int cnt = 0;

	for (int i = 1; i <= n; i++) {
		int dir = (cx < to) ? 1 : -1;
		if (abs(to - cx) < t[i] - t[i - 1]) {
			cx = to;
		}
		else {
			cx = cx + dir * (t[i] - t[i - 1]);
		}

		if (cx == to) {
			to = x[i];
		}

		if (cx < to) {
			int nxt = min(to, cx + t[i + 1] - t[i]);
			if (i + 1 > n) nxt = to;

			if (cx <= x[i] && x[i] <= nxt) {
				cnt += 1;
			}
		}
		else {
			int nxt = max(to, cx - t[i + 1] + t[i]);
			if (i + 1 > n) nxt = to;

			if (nxt <= x[i] && x[i] <= cx) {
				cnt += 1;
			}
		}
	}

	return cnt;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> tc;
	while (tc--) {
		cout << solve() << '\n';
	}

	return 0;
}
