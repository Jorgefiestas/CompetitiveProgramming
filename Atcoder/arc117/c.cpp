#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 10;
const int mod = 3;
const char toCh[] = {'W', 'B', 'R'};
int n, a[N], fact[3];

int add(int x, int y) {
	if (x + y >= mod) {
		return x + y - mod;
	}
	return x + y;
}

int mul(int x, int y) {
	return x * y % mod;
}

int choose(int x, int y) {
	int ans = 1;

	while (x > 0 || y > 0) {
		int xi = x % mod;
		int yi = y % mod;

		if (xi < yi)
			return  0;

		int den = mul(fact[xi - yi], fact[yi]);
		ans = mul(ans, mul(fact[xi], den));

		x /= mod;
		y /= mod;
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	fact[0] = fact[1] = 1;
	fact[2] = 2;

	cin >> n;

	char c;
	for (int i = 0; i < n; i++) {
		cin >> c;
		if (c == 'W') a[i] = 0;
		if (c == 'B') a[i] = 1;
		if (c == 'R') a[i] = 2;
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans = add(ans, mul(a[i], choose(n - 1, i)));
	}

	if (n % 2 == 0) {
		ans = (3 - ans) % 3;
	}

	cout << toCh[ans] << '\n';

	return 0;
}
