#include <bits/stdc++.h>
using namespace std;
int t, x, y, a, b;

long long solve() {
	cin >> x >> y >> a >> b;

	if (x > y) {
		swap(x, y);
	}

	if (2 * a < b) {
		return (long long) (x + y) * a;
	}

	long long ans = (long long) (y - x) * a;
	ans += (long long) b * x;
	return ans;
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
