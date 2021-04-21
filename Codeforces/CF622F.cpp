#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 100;
const int mod = 1e9 + 7;
int n, k, y[N];

int add(int x, int y) {
	if (x + y >= mod) {
		return x + y - mod;
	}
	return x + y;
}

int sub(int x, int y) {
	if (x - y < 0) {
		return x - y + mod;
	}
	return x - y;
}

int mul(int x, int y) {
	return (long long) x * y % mod;
}

int exp(int x, int y) {
	int ans = 1;
	while (y) {
		if (y & 1) {
			ans = mul(ans, x);
		}
		x = mul(x, x);
		y >>= 1;
	}
	return ans;
}

int inv(int x) {
	return exp(x, mod - 2);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;

	for (int i = 1; i <= k + 1; i++) {
		y[i] = add(y[i - 1], exp(i, k));
	}

	int num = 1;
	for (int i = 0; i <= k + 1; i++) {
		if (i == n) continue;
		num = mul(num, sub(n, i));
	}

	int den = 1;
	for (int i = 1; i <= k + 1; i++) {
		den = mul(den, sub(0, i));
	}


	int ans = 0;
	for (int i = 0; i <= k + 1; i++) {
		int tnum = 0;

		if (k + 1 < n) {
			tnum = mul(num, inv(sub(n, i)));
		}
		else if (i == n) {
			tnum = num;
		}

		ans = add(ans, mul(y[i], mul(tnum, inv(den))));

		den = mul(den, inv(sub(i, k + 1)));
		den = mul(den, i + 1);
	}

	cout << ans << '\n';

	return 0;
}
