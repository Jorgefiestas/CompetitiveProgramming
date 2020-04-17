#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, k, a[N];
long long dp[13][N];
long long fts[13][N];

void update(long long ft[N], int idx, long long val) {
	while (idx < N) {
		ft[idx] += val;
		idx += idx & -idx;
	}
}

long long query(long long ft[N], int idx) {
	long long ans = 0;
	while (idx > 0) {
		ans += ft[idx];
		idx -= idx & -idx;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	long long ans = 0;
	for (int i = 0; i < n; i++) {
		for (int l = 0; l <= min(i, k); l++) {
			long long tans = (l == 0) ? 1 : query(fts[l], a[i] - 1);
			if (l == k) {
				ans += tans;
			}
			else {
				update(fts[l + 1], a[i], tans);
			}
		}
	}

	cout << ans << endl;
}
