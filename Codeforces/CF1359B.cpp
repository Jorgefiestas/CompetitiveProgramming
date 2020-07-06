#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 100;
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

		sort(a, a + n, greater<int>());

		int ans = n;
		for (int i = 0; i < n; i++) {
			if (a[i] <= ans) break;
			ans--;
		}

		cout << ans + 1 << '\n';
	}

	return 0;
}
