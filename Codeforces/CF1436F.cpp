#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
const int mod = 998244353;
int m, a[N], f[N], dp[N];
vector<int> multiples[N];

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

int exp(int x, long long y) {
	if (y < 0) {
		return 0;
	}

	y = y % (mod - 1);
	int ans = 1;
	while (y) {
		if (y & 1LL) {
			ans = mul(ans, x);
		}
		x = mul(x, x);
		y >>= 1LL;
	}
	return ans;
}

int inv(int x) {
	return exp(x, mod - 2);
}

int fun(const vector<int> &s) {
	int xx = 0;
	int xy = 0;

	long long n = 0;
	for (int x : s) {
		xx = add(xx, mul(f[x], mul(x, x)));
		xy = add(xy, mul(f[x], x));
		n += (long long) f[x];
	}

	xy = sub(mul(xy, xy), xx);

	int en3 = exp(2, n - 3);
	int en2 = exp(2, n - 2);
	n = n % mod;

	int cxx = mul(en2, sub(n, 1));
	int cxy = add(mul(en3, sub(n, 2)), en2);
	
	return add(mul(xx, cxx), mul(xy, cxy));
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> m;

	int ai, fr;
	for (int i = 1; i <= m; i++) {
		cin >> ai >> fr;
		f[ai] = fr;

		for (int d = 1; d * d <= ai; d++) {
			if (ai % d) continue;
			multiples[d].push_back(ai);
			if (ai / d != d) multiples[ai / d].push_back(ai);
		}
	}

	for (int d = N - 1; d > 0; d--) {
		if (multiples[d].empty()) continue;

		dp[d] = fun(multiples[d]);

		for (int x = d * 2; x < N; x += d) {
			dp[d] = sub(dp[d], dp[x]);
		}
	}

	cout << dp[1] << '\n';

	return 0;
}
