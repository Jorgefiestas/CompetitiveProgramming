#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int t, n, a[N], b[N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;

	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> b[i];
		}

		bool pos = false;
		bool neg = false;
		bool ans = true;
		for (int i = 0; i < n; i++) {
			if (b[i] > a[i] && !pos) {
				ans = false;
			}
			else if (b[i] < a[i] && !neg) {
				ans = false;
			}

			if (a[i] > 0) {
				pos = true;
			}
			if (a[i] < 0) {
				neg = true;
			}
		}

		if (ans) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}

	return 0;
}
