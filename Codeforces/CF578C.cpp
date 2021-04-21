#include <bits/stdc++.h>
using namespace std;
using ld = long double;
const int N = 2e5 + 100;
int n;
ld a[N];

ld f(ld x) {
	ld mx = -1e15;
	ld mn = 1e15;
	ld dp;

	dp = -1e15;
	for (int i = 1; i <= n; i++) {
		ld ai = a[i] - x;
		dp = max(ai, dp + ai);
		mx = max(dp, mx);
	}

	dp = 1e15;
	for (int i = 1; i <= n; i++) {
		ld ai = a[i] - x;
		dp = min(ai, dp + ai);
		mn = min(dp, mn);
	}

	return max(mx, -mn);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	ld l = -10000;
	ld r = 10000;

	for (int i = 0; i < 200; i++) {
		ld m1 = l + (r - l) / 3;
		ld m2 = r - (r - l) / 3;

		ld v1 = f(m1);
		ld v2 = f(m2);

		if (v1 > v2) {
			l = m1;
		}
		else {
			r = m2;
		}
	}

	cout << fixed << setprecision(9);
	cout << f((l + r) / 2.0) << '\n';

	return 0;
}
