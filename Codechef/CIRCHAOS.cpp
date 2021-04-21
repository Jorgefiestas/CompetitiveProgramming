#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int N = 3e5 + 10;
int t, n, m, p[N];

int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a % b);
}

int solve() {
	cin >> n >> m;

	for (int i = 1; i <= m; i++) {
		cin >> p[i];
	}

	sort(p + 1, p + m + 1);

	int g = p[1];
	for (int i = 2; i <= m; i++) {
		g = gcd(g, p[i] - p[i - 1]);
	}

	int ans = 1;
	for (int x = 1; x * x <= g; x++) {
		if (g % x) continue;
		int y = g / x;

		if (x <= n)
			ans = max(ans, x);
		if (y <= n) 
			ans = max(ans, y);
	}

	return n - ans;
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
