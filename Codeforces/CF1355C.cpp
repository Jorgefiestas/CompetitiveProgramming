#include <bits/stdc++.h>
using namespace std;
long long a, b, c, d;

long long sum(long long l, long long r) {
	if (l > r) return 0;
	long long n = (r - l + 1);
	return n * b - (l + r) * n / 2;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> a >> b >> c >> d;

	long long ans = 0;
	for (long long z = c; z <= d; z++) {
		long long mx = z - b;
		long long mn = z - c;

		if (mn < a) {
			ans += min(a - mn, mx - mn + 1LL) * (b - a + 1);
		}

		ans += sum(max(mn, a), min(mx, b));
	}

	cout << ans << '\n';

	return 0;
}
