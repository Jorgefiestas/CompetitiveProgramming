#include <bits/stdc++.h>
using namespace std;
int t, n, a, b, x, y;

long long solve() {
	cin >> a >> b >> x >> y >> n;

	int da = a - x;
	int db = b - y;

	long long ans = LLONG_MAX;

	if (da >= n) {
		ans = min(ans, (long long) (a - n) * b);
	}
	else {
		ans = min(ans, (long long) x * max(b - n + da, y));
	}

	if (db >= n) {
		ans = min(ans, (long long) (b - n) * a);
	}
	else {
		ans = min(ans, (long long) y * max(a - n + db, x));
	}

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
