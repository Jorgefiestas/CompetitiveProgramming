#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
const int mod = 1e9 + 7;
int n, x, pos, cnt[2], fact[N];
bool a[N];

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

int perm(int x, int y) {
	if (y > x) return 0;
	return mul(fact[x], inv(fact[x - y]));
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	fact[0] = 1;
	for (int i = 1; i < N; i++) {
		fact[i] = mul(fact[i - 1], i);
	}

	cin >> n >> x >> pos;

	int l = 0;
	int r = n;
	while (l < r) {
		int m = (l + r) / 2;

		if (m <= pos) {
			cnt[0]++;
			l = m + 1;
		}
		else {
			cnt[1]++;
			r = m;
		}
	}

	cnt[0] -=1;

	int small = perm(x - 1, cnt[0]);
	int big = perm(n - x, cnt[1]);
	int rest = fact[n - cnt[1] - cnt[0] - 1];

	cout << mul(rest, mul(small, big)) << '\n';

	return 0;
}
