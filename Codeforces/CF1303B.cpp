#include <bits/stdc++.h>
using namespace std;
int t;
long long n, g, b;

void solve() {
	cin >> n >> g >> b;

	long long ng = (n + 1) / 2;
	long long ca = ng / g;
	long long cb = ca;

	if (ng % g == 0) {
		cb--;
	}

	long long ta = cb * b + ca * g + (ng % g);

	if (ta >= n) {
		cout << ta << '\n';
		return;
	}

	ta += (n - ta);
	cout << ta << '\n';
	return;
}

int main() {
	cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}
