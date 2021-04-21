#include <bits/stdc++.h>
using namespace std;
int t, w, h, n;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		cin >> w >> h >> n;

		long long ans = 1;

		while (w % 2 == 0) {
			w >>= 1;
			ans <<= 1;
		}

		while (h % 2 == 0) {
			h >>= 1;
			ans <<= 1;
		}

		if (ans >= n) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}

	return 0;
}
