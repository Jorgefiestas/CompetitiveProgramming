#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll a, b, c, d, l, r;

ll _floor(ll, ll);
ll _ceil(ll, ll);

ll _floor(ll a, ll b) {
	if (b < 0) {
		return _floor(-a, -b);
	}
	if (a < 0) {
		return -_ceil(-a, b);
	}
	return a / b;
}

ll _ceil(ll a, ll b) {
	if (b < 0) {
		return _ceil(-a, -b);
	}
	if (a < 0) {
		return - _floor(-a, b);
	}
	return (a + b - 1) / b;
}

ll gcd(ll a, ll b, ll &x, ll &y) {
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}

	ll x1, y1;
	ll g = gcd(b, a % b, x1, y1);
	x = y1;
	y = x1 - y1 * (a / b);
	return g;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> a >> b;
	cin >> c >> d;
	cin >> l >> r;

	ll xg, yg;
	ll g = gcd(a, -c, xg, yg);

	if ((d - b) % g) {
		cout << 0 << '\n';
		return 0;
	}

	if (g < 0) {
		g = -g;
		xg = -xg;
		yg = -yg;
	}

	l = max(0LL, _ceil(l - b, a));
	r = _floor(r - b, a);

	ll lft = _ceil(r * g - xg * (d - b), -c);
	ll rgt = _floor(l * g - xg * (d - b), -c);
	rgt = min(rgt, _floor((d - b) * yg, a));

	cout << max(0LL, rgt - lft + 1) << '\n';

	return 0;
}
