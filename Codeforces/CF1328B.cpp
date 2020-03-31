#include <bits/stdc++.h>
using namespace std;
int t, n, k;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;

	while (t--) {
		cin >> n >> k;
		k--;

		int l = 1;
		int r = n - 1;
		int i;
		while (l <= r) {
			int m = (l + r) / 2;

			if (m * 1LL * (m - 1) / 2 >  k) {
				r  = m - 1;
			}
			else {
				i = m;
				l = m + 1;
			}
		}

		int j = k - i * 1LL * (i - 1) / 2;

		for (int x = 0; x < n; x++) {
			if (x == n - i - 1 || x == n - j - 1) {
				cout << 'b';
			}
			else {
				cout << 'a';
			}
		}
		cout << '\n';
	}

	return 0;
}
