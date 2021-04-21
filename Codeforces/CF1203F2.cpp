#include <bits/stdc++.h>
using namespace std;
const int N = 105;
const int R = 80000;
int n, r, dp[N][R];

struct Task {
	int a, b;

	bool operator<(const Task &t) const {
		if (b >= 0 && t.b >= 0) {
			if (a == t.a) {
				return b > t.b;
			}
			return a < t.a;
		}
		if (b >= 0) {
			return true;
		}
		if (t.b >= 0) {
			return false;
		}

		return max(a, -b) + b > max(t.a, -t.b) + t.b;
	}
};

Task t[N];

int main() {
	ios_base::sync_with_stdio();
	cin.tie(0);

	cin >> n >> r;

	for (int i = 0; i < n; i++) {
		cin >> t[i].a >> t[i].b;
	}

	sort(t, t + n);

	int pos = 0;

	int i = 0;
	for (i = i; t[i].b >= 0 && i < n; i++) {
		if (r < t[i].a) continue;
		r += t[i].b;
		pos += 1;
	}

	memset(dp, -1, sizeof dp);

	dp[i][r] = pos;
	for (i = i; i < n; i++) {
		for (int k = 0; k < R; k++) {
			if (dp[i][k] == -1) continue;
			dp[i + 1][k] = max(dp[i + 1][k], dp[i][k]);
			if (k >= t[i].a && k >= -t[i].b) {	
				dp[i + 1][k + t[i].b] = max(dp[i + 1][k + t[i].b], dp[i][k] + 1);
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < R; i++) {
		ans = max(ans, dp[n][i]);
	}

	cout << ans << '\n';

	return 0;
}
