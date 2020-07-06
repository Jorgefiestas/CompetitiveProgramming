#include <bits/stdc++.h>
using namespace std;

int getMin(int ox) {
	int mn = INT_MAX;

	int x = ox;
	for (int i = 2; i * i <= ox; i++) {
		if (x % i) continue;

		int k = ox / i;
		mn = min(mn, (k - 1) * i + 1);

		while (x % i == 0) {
			x /= i;
		}
	}
	if (x > 1 && x != ox) {
		int k = ox / x;
		mn = min(mn, (k - 1) * x + 1);
	}

	return max(mn, 3);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int x;
	cin >> x;

	int mn = getMin(x);
	int ans = INT_MAX;

	for (int i = max(mn, 4); i <= x; i++) {
		ans = min(ans, getMin(i));
	}

	cout << ans << '\n';

	return 0;
}
