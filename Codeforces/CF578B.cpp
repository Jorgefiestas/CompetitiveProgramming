#include <bits/stdc++.h>
using namespace std;
int n, k, x, stcnt[65];
long long a[200005];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k >> x;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 64; j++) {
			if (a[i] & (1LL << j)) {
				stcnt[j]++;
			}
		}
	}

	long long xtk = 1;
	for (int i = 0; i < k; i++) {
		xtk *= x;
	}

	long long ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 64; j++) {
			if (a[i] & (1LL << j)) {
				stcnt[j]--;
			}
		}

		long long nai = a[i] * xtk;

		long long tans = 0;
		for (int j = 0; j < 64; j++) {
			if (nai & (1LL << j) || stcnt[j]) {
				tans |= (1LL << j);
			}
		}

		ans = max(ans, tans);

		for (int j = 0; j < 64; j++) {
			if (a[i] & (1LL << j)) {
				stcnt[j]++;
			}
		}
	}

	cout << ans << endl;
	return 0;
}
