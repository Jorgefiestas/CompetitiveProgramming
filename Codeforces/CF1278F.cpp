#include <bits/stdc++.h>
using namespace std;
const int mod = 98244353;
int n, m, k;

int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a % b);
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

	cin >> n >> m >> k;

	int g = gcd(n, m);
	n /= g;
	m /= g;

	cout << mul(exp(n, k), inv(exp(m, k))) << '\n';

	return 0;
}
