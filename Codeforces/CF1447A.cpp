#include <bits/stdc++.h>
using namespace std;
int t, n;

void solve() {
	cin >> n;

	cout << n - 1 << '\n';
	for (int i = 2; i <= n; i++) {
		cout << i << ' ';
	}
	cout << '\n';
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
