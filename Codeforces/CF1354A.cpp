#include <bits/stdc++.h>
using namespace std;
long long t, a, b, c, d;

long long solve() {
	cin >> a >> b >> c >> d;

	long long es = (c - d);

	if (b >= a) {
		return b;
	}
	if (b < a && es <= 0) {
		return -1;
	}

	return b + ((a - b + es - 1LL) / es) * c;
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
