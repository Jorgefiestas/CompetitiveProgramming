#include <bits/stdc++.h>
using namespace std;
int t;
long long a, m;

long long gcd(long long a, long long b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a % b);
}

long long solve() {
	cin >> a >> m;

	long long g = gcd(a, m);

	m /= g;

	long long ans = m;

	for (long long d = 2; d * d <= m; d++) {
		if (m % d) continue;

		ans /= d;
		ans *= (d - 1);

		while (m % d == 0) {
			m /= d;
		}
	}

	if (m > 1) {
		ans /= m;
		ans *= m - 1;
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
