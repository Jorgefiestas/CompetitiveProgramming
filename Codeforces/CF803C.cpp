#include <bits/stdc++.h>
using namespace std;
long long n, k;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;

	if (k > 1e9) {
		cout << -1 << '\n';
		return 0;
	}

	long long s = k * (k + 1) / 2LL;

	long long d = -1;
	for (long long x = 1; x * x <= n; x++) {
		if (n % x) continue;
		long long y = n / x;
		if (s <= y) {
			d = max(d, x);
		}
		if (s <= x) {
			d = max(d, y);
		}
	}

	if (d == -1) {
		cout << d << '\n';
		return 0;
	}

	long long cs = 0;
	for (long long i = 1; i < k; i++) {
		cout << d * i << ' ';
		cs += d * i;
	}
	cout << n - cs << '\n';

	return 0;
}
