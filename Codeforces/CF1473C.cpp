#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int t, n, k;

void solve() {
	cin >> n >> k;

	for (int i = 1; i < 2 * k - n; i++) {
		cout << i << ' ';
	}
	for (int i = k; i >= 2 * k - n; i--) {
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
