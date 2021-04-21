#include <bits/stdc++.h>
using namespace std;
const long long INF = 5.1e18;
long long t, a, b;

long long gcd(long long x, long long y) {
	if (y == 0) {
		return x;
	}
	return gcd(y, x % y);
}

long long lcm(long long x, long long y) {
	long long g = gcd(x, y);

	if (x / g > INF / y) {
		return INF;
	}
	return (x / g) * y;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t >> a >> b;

	if (a > b) {
		swap(a, b);
	}

	long long cm = lcm(a, b);
	long long ways = ((t / cm) + 1) * a;

	if (t % cm < a) {
		ways = ways - (a - 1 - t % cm);
	}
	ways -= 1;

	long long g = gcd(ways, t);
	ways = ways / g;
	t = t / g;

	cout << ways << '/' << t << '\n';

	return 0;
}
