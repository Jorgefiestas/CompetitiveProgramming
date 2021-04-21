#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int N = 2005;
int a, n, m, dp[N];
vector<pii> umb;
bool rain[N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> a >> n >> m;

	int mnl = INT_MAX;
	int li, ri;
	for (int i = 0; i < n; i++) {
		cin >> li >> ri;
		for (int j = li + 1; j <= ri; j++) {
			rain[j] = true;
		}
		mnl = min(mnl, li);
	}

	int xi, pi;
	for (int i = 0; i < m; i++) {
		cin >> xi >> pi;
		umb.push_back({xi, pi});
	}
	sort(umb.begin(), umb.end());

	if (mnl < umb[0].first) {
		cout << -1 << '\n';
		return 0;
	}

	for (int i = 1; i <= a; i++) {
		if (!rain[i]) {
			dp[i] = dp[i - 1];
			continue;
		}

		dp[i] = INT_MAX;
		for (auto [x, w] : umb) {
			if (i < x) continue;
			int can = (i - x) * w + dp[x];
			dp[i] = min(dp[i], can);
		}
	}

	cout << dp[a] << '\n';

	return 0;
}
