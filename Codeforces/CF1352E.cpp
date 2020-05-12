#include <bits/stdc++.h>
using namespace std;
const int N = 8005;
int t, n, cnt[N], pref[N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		memset(cnt, 0, sizeof cnt);
		cin >> n;

		int ai;
		for (int i = 1; i <= n; i++) {
			cin >> ai;
			pref[i] = pref[i - 1] + ai;
			cnt[ai]++;
		}

		int ans = 0;
		for (int i = 2; i <= n; i++) {
			for (int j = 1; j < i; j++) {
				int sum = pref[i] - pref[j - 1];
				if (sum <= 8000) {
					ans += cnt[sum];
					cnt[sum] = 0;
				}
			}
		}

		cout << ans << '\n';
	}

	return 0;
}
