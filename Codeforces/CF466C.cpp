#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int n, a[N];
long long pref[N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		pref[i] = pref[i - 1] + (long long) a[i];
	}

	map<int, int> cnt;

	long long ls = pref[n];
	long long ans = 0;
	for (int i = 1; i < n; i++) {
		ls -= (long long) a[i];
		if (pref[i] == 2 * ls) {
			ans += (long long) cnt[ls];
		}
		cnt[pref[i]] += 1;
	}

	cout << ans << '\n';

	return 0;
}
