#include <bits/stdc++.h>
using namespace std;
const int B = 22;
const int N = (1 << B);
int n, a[N], dp[N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	memset(dp, -1, sizeof dp);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		int msk = a[i] ^ ((1 << B) - 1);
		dp[msk] = a[i];
	}

	for (int i = B - 1; i >= 0; i--) {
		for (int mask = (1 << B) - 1; mask >= 0; mask--) {
			if (!(mask & (1 << i))) {
				dp[mask] = max(dp[mask], dp[mask ^ (1 << i)]);
			}
		}
	}

	for (int i = 0; i < n; i++) {
		cout << dp[a[i]] << ' ';
	}
	cout << '\n';

	return 0;
}
