#include <bits/stdc++.h>
using namespace std;
int t, n, x;

int solve() {
	cin >> n >> x;

	int a, mx = 0;
	bool eq = false;
	for (int i = 0; i < n; i++) {
		cin >> a;
		mx = max(a, mx);

		if (a == x) eq = true;
	}

	int ans = (x + mx - 1) / mx;
	return eq ? 1 : max(ans, 2);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		cout << solve() << '\n';
	}

	return 0;
}
