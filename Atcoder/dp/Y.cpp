#include <bits/stdc++.h>
using namespace std;
const int N = 3005;
const int M = 3e5;
const int mod = 1e9 + 7;
using pii = pair<int, int>;
int h, w, n, fac[M], dp[N];
pii points[N];

int mul(int x, int y) {
	return (x * 1LL * y) % mod;
}

int exp(int x, int y) {
	long long ans = 1;
	while (y) {
		if (y & 1) {
			ans = mul(ans, x);
		}
		x = mul(x, x);
		y >>= 1;
	}

	return ans;
}

int sub(int x, int y) {
	if (x - y < 0) {
		return x - y + mod;
	}
	return x - y;
}

int inv(int x) {
	return exp(x, mod - 2);
}

int paths(int x, int y) {
	if (x < 0 || y < 0) {
		return 0;
	}
	return mul(fac[x + y], inv(mul(fac[x], fac[y])));
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	fac[0] = 1;
	for (int i = 1; i < M; i ++) {
		fac[i] = mul(fac[i - 1], i);
	}

	cin >> h >> w >> n;

	for (int i = 0; i < n; i++) {
		cin >> points[i].first >> points[i].second;
		points[i].first--;
		points[i].second--;
	}

	sort(points, points + n);

	points[n] = {h - 1, w - 1};
	n++;

	for (int i = 0; i < n; i++) {
		pii p = points[i];
		dp[i] = paths(p.first, p.second);

		for (int j = 0; j < i; j++) {
			dp[i] = sub(dp[i], mul(dp[j], paths(p.first - points[j].first, p.second - points[j].second)));

		}
	}

	cout << dp[n - 1] << endl;
}
