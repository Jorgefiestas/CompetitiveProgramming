#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
long long pref[N], n, a[N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = n - 1; i >= 0; i--) {
		pref[i] = a[i] + pref[i + 1];
	}

	long long ans = 0;
	int mr = -1;
	map<long long, int> cnt;
	for (int i = 0; i < n; i++) {
		cnt[pref[i]] = i;

		if (cnt.count(pref[i] - a[i])) {
			mr = max(mr, cnt[pref[i] - a[i]]);
		}

		ans += (long long) i - mr;
	}

	cout << ans << '\n';

	return 0;
}
