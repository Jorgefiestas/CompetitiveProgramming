#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int t, n, a[N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}

		int ans = 0;
		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) {
				if ((a[i] & a[j]) == a[i]) {
					ans += 1;
				}
			}
		}

		cout << ans << '\n';
	}

	return 0;
}
