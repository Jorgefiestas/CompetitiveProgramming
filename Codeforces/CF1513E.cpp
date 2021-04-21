#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int N = 1e5 + 10;
long long n, a[N], fact[N];

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
	int den = mul(fact[y], fact[x - y]);
	return mul(fact[x], inv(den));
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	fact[0] = 1;
	for (int i = 1; i < N; i++) {
		fact[i] = mul(fact[i - 1], i);
	}
	
	cin >> n;

	long long sum = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum += a[i];
	}

	if (sum % n) {
		cout << 0 << '\n';
		return 0;
	}

	long long y = sum / n;

	map<int, int> freq;
	int cnt[3] = {0, 0, 0};

	for (int i = 1; i <= n; i++) {
		freq[a[i]] += 1;
		if (a[i] == y) cnt[0] += 1;
		if (a[i] < y) cnt[1] += 1;
		if (a[i] > y) cnt[2] += 1;
	}

	if (cnt[1] <= 1 || cnt[2] <= 1) {
		int ans = fact[n];
		for (auto [x, c] : freq) {
			ans = mul(ans, inv(fact[c]));
		}
		cout << ans << '\n';
		return 0;
	}

	int pL = fact[cnt[1]];
	int pR = fact[cnt[2]];

	for (auto [x, c] : freq) {
		if (x < y) pL = mul(pL, inv(fact[c]));
		if (x > y) pR = mul(pR, inv(fact[c]));
	}

	int ans = mul(2, mul(pL, pR));
	ans = mul(ans, choose(n, cnt[1] + cnt[2]));

	cout << ans << '\n';

	return 0;
}
