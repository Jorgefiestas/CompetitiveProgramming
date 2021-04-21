#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 100;
const int mod = 998244353;
int n, m, fact[N];

int add(int x, int y) {
	if (x + y >= mod) {
		return x + y - mod;
	}
	return x + y;
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

int choose(int x, int y) {
	if (y > x) {
		return 0;
	}
	return mul(fact[x], inv(mul(fact[x - y], fact[y])));
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	fact[0] = 1;
	for (int i = 1; i < N; i++) {
		fact[i] = mul(fact[i - 1], i);
	}

	cin >> n >> m;

	int ans = choose(m, n - 1);
	ans = mul(ans, exp(2, n - 2));
	ans = mul(ans, n - 2);
	ans = mul(ans, inv(2));

	cout << ans << '\n';

	return 0;
}
