#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 100;
const int mod = 1e9 + 7;
int fact[N];
string str;

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

int choose(int x, int y) {
	if (y > x) return 0;
	return mul(fact[x], inv(mul(fact[y], fact[x - y])));
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	fact[0] = 1;
	for (int i = 1; i < N; i++) {
		fact[i] = mul(fact[i - 1], i);
	}

	cin >> str;

	int ans = 0;
	int c1 = 0;
	int c2 = 0;

	for (char c : str) {
		if (c != ')') continue;
		c2 += 1;
	}

	for (char c : str) {
		if (c == ')') {
			c2 -= 1;
			continue;
		}
		c1 += 1;
		ans = add(ans, choose(c1 + c2, min(c1, c2)));
		ans = sub(ans, choose(c1 + c2 - 1, min(c1 - 1, c2)));
	}

	cout << ans << '\n';

	return 0;
}
