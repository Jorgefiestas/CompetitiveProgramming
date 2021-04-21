#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int t, n, k, a[N];

void solve() {
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int peaks = 0;

	for (int i = 1; i < k - 1; i++) {
		if (a[i] > a[i - 1] && a[i] > a[i + 1]) {
			peaks += 1;
		}
	}

	int ans = peaks;
	int idx = 0;

	for (int l = 1; l <= n - k; l++) {
		if (a[l] > a[l - 1] && a[l] > a[l + 1]) {
			peaks -= 1;
		}

		int r = l + k - 1;

		if (a[r - 1] > a[r] && a[r - 1] > a[r - 2]) {
			peaks += 1;
		}

		if (peaks > ans) {
			ans = peaks;
			idx = l;
		}
	}

	cout << ans + 1 << ' ' << idx + 1 << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}
