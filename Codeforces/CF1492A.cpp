#include <bits/stdc++.h>
using namespace std;
long long t, p, a, b, c;

long long f(long long x) {
	return ((p + x - 1) / x) * x - p;
}

long long solve() {
	cin >> p >> a >> b >> c;
	return min({f(a), f(b), f(c)});
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
