#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int n, m, l, r;

int sub(int x, int y) {
	if (x - y < 0) {
		return x - y + mod;
	}
	return x - y;
}

int add(int x, int y) {
	if (x + y >= mod) {
		return x + y - mod;
	}
	return x + y;
}

int mul(int x, int y) {
	return (long long) (x * 1LL * y) % mod;
}

int exp(int x, long long y) {
	int ans = 1;
	
	while (y) {
		if (y & 1) {
			ans = mul(ans, x);
		}
		y >>= 1;
		x = mul(x, x);
	}

	return ans;
}

int main() {
	cin >> n >> m >> l >> r;
	long long nm = n * 1LL * m;

	int df = ((r - l + 1) / 2);
	int dc = ((r - l + 2) / 2);

	if (nm % 2) {
		cout << exp(add(df, dc), nm) << '\n';
		return 0;
	}
	
	int c1 = exp(add(dc, df), nm);
	int c2 = exp(sub(dc, df), nm);

	cout << mul(add(c1, c2), exp(2, mod - 2)) << '\n';

	return 0;
}
