#include <bits/stdc++.h>
using namespace std;
int x, y;

long long solve() {
	cin >> x >> y;

	long long ans = 0;
	for (int r = 1; r * r <= x; r++) {
		int mx = min(y, (x - r) / r);
		ans += (long long) max(0, mx - r);
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	while (t--) {
		cout << solve() << '\n';
	}

	return 0;
}
