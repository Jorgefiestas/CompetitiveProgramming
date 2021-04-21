#include <bits/stdc++.h>
using namespace std;
int t, l, r;

void solve() {
	cin >> l >> r;

	if (2 * l <= r) {
		cout << l << ' ' << 2 * l << '\n';
		return;
	}

	cout << -1 << ' ' << -1 << '\n';
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
