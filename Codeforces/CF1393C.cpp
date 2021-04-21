#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 100;
int t, n, a[N], pref[N];

long long solve() {
	cin >> n;

	char ci;
	for (int i = 1; i <= n; i++) {
		cin >> ci;
		a[i] = ci - '0';
		pref[i] = pref[i - 1] + a[i];
	}

	map<int, int> cnt;
	cnt[0] = 1;

	long long ans = 0;

	for (int i = 1; i <= n; i++) {
		ans += (long long) cnt[pref[i] - i];
		cnt[pref[i] - i] += 1;
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
