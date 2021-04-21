#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 100;
int t, n, a[N];

void solve() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	if (a[0] + a[1] <= a[n - 1]) { 
		cout << 1 << ' ' << 2 << ' ' << n << '\n';
		return;
	}

	cout << -1 << '\n';
	return;
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
