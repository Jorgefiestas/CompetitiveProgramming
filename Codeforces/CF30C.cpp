#include <bits/stdc++.h>
using namespace std;
using ld = long double;
using pdd = pair<ld, ld>;
const int N = 1005;
int n;
ld dp[N];

struct pt {
	ld x, y, t, p;

	bool operator<(const pt &p) const {
		return t < p.t;
	}
};

pt tar[N];

ld dist(const pt &a, const pt &b) {
	ld dx = a.x - b.x;
	ld dy = a.y - b.y;
	return sqrtl(dx * dx + dy * dy);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> tar[i].x >> tar[i].y >> tar[i].t >> tar[i].p;
	}

	sort(tar, tar + n);

	dp[0] = tar[0].p;
	ld ans = dp[0];

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			ld dt = tar[i].t - tar[j].t;
			ld d = dist(tar[i], tar[j]);

			if (d <= dt) {
				dp[i] = max(dp[i], dp[j]);
			}
		}

		dp[i] += tar[i].p;
		ans = max(ans, dp[i]);
	}

	cout << fixed << setprecision(9);
	cout << ans << '\n';

	return 0;
}
