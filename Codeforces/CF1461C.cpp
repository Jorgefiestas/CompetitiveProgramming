#include <bits/stdc++.h>
using namespace std;
using ld = long double;
const int N = 1e5 + 10;
int t, n, m, a[N];

ld solve() {
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	int mx = 0;
	int lst = -1;

	bool sorted = true;
	for (int i = 1; i <= n; i++) {
		if (mx > a[i]) lst = i;
		mx = max(mx, a[i]);
		sorted = sorted && (a[i] > a[i - 1]);
	}

	ld ans = 0;
	ld prob = 1;

	int ri;
	ld pi;
	for (int qi = 0; qi < m; qi++) {
		cin >> ri >> pi;
		if (ri < lst) continue;;

		ans += prob * pi;
		prob *= (1.0 - pi);
	}

	return sorted ? 1 : ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cout << setprecision(9) << fixed;

	cin >> t;
	while (t--) {
		cout << solve() << '\n';
	}

	return 0;
}
