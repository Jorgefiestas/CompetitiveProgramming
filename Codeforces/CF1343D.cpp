#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 100;
int t, n, k, a[N];

int solve() {
	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	map<int, int> cnt;

	for (int i = 1; i <= n / 2; i++) {
		if (a[i] > a[n - i + 1]) {
			swap(a[i], a[n - i + 1]);
		}

		int sm = a[i] + a[n - i + 1];
		cnt[a[i] + 1] -= 1;
		cnt[sm] -= 1;
		cnt[sm + 1] += 1;
		cnt[k + a[n - i + 1] + 1] += 1;
	}

	int c = n;

	int ans = INT_MAX;
	for (int x = 2; x <= 2 * k; x++) {
		if (!cnt.count(x)) continue;
		c += cnt[x];
		ans = min(ans, c);
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
