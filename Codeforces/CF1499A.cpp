#include <bits/stdc++.h>
using namespace std;
int t, n, k1, k2, w, b;

bool solve() {
	cin >> n >> k1 >> k2;
	cin >> w >> b;

	int aw = (k1 + k2) / 2;
	int ab = (2 * n - k1 - k2) / 2;

	return aw >= w && ab >= b;
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;

	while (t--) {
		if (solve()) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}

	return 0;
}
