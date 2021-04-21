#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int N = 2e5 + 10;
int n, m, cnt[2][N], pref[N];
pii dp[N];
string str;

int count(int l, int r) {
	int ans = pref[r];
	if (l != 0) {
		ans -= pref[l - 1];
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> str >> m;

	for (int i = 0; i < n; i++) {
		pref[i] = (str[i] == '?');
		if (i > 0) {
			pref[i] += pref[i - 1];
		}
	}

	for (int i = n - 1; i >= 0; i--) {
		if (str[i] != 'b') {
			cnt[0][i] = cnt[0][i + 2] + 1;
		}
		if (str[i] != 'a') {
			cnt[1][i] = cnt[1][i + 2] + 1;
		}
	}

	for (int i = n - 1; i >= 0; i--) {
		if (cnt[0][i] >= (m + 1) / 2 && cnt[1][i + 1] >= m / 2) {
			dp[i] = {1 + dp[i + m].first, dp[i + m].second - count(i, i + m - 1)};
		}
		dp[i] = max(dp[i], dp[i + 1]);
	}

	cout << -dp[0].second << '\n';

	return 0;
}
