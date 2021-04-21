#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
const int mod = 1e9 + 7;
int fact[N];

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

int solve() {
	int n, k;
	cin >> n >> k;

	vector<int> cnt(n + 1, 0);

	int ai;
	for (int i = 1; i <= n; i++) {
		cin >> ai;
		cnt[ai] += 1;
	}

	int x = n;
	while (k > 0 && k - cnt[x] >= 0) {
		k -= cnt[x];
		x -= 1;
	}

	return choose(cnt[x], k);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	fact[0] = 1;
	for (int i = 1; i < N; i++) {
		fact[i] = mul(fact[i - 1], i);
	}

	int t;
	cin >> t;

	while (t--) {
		cout << solve() << '\n';
	}

	return 0;
}
