#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int t, n, c[N];

long long solve() {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}

	int mn[2] = {INT_MAX, INT_MAX};
	long long sm[2] = {0, 0};

	long long ans = LLONG_MAX;

	for (int i = 1; i <= n; i++) {
		mn[i % 2] = min(mn[i % 2], c[i]);
		sm[i % 2] += (long long) c[i];

		int xcnt = (i + 1) / 2;
		int ycnt = i / 2;

		long long xans = sm[1] + 1LL * (n - xcnt) * mn[1];
		long long yans = sm[0] + 1LL * (n - ycnt) * mn[0];
		ans = min(ans, xans + yans);
	}

	return ans;
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
