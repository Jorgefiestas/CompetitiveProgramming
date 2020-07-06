#include <bits/stdc++.h>
using namespace std;
using ld = long double;
const int N = 2e6 + 10;
const ld EPS = 1e-8;
ld w, d, a;
int k;
ld p[2][12], q[2][12];
 
ld depth;
ld f(ld x) {
	ld qu = 0;
	ld pu = 0;
	ld xp = 1;
	for (int i = 0; i <= k; i++) {
		pu += xp * p[0][i];
		qu += xp * q[0][i];
		xp *= x;
	}
	ld y0 = -pu / qu;

	qu = 0;
	pu = 0;
	xp = 1;
	for (int i = 0; i <= k; i++) {
		pu += xp * p[1][i];
		qu += xp * q[1][i];
		xp *= x;
	}
	ld y1 = -pu / qu;
 
	return min(depth, y1) - min(depth, y0);
}

ld simpson(ld a, ld b) {
	return (b - a) * (f(a) + 4.0 * f((a + b) / 2.0) + f(b)) / 6.0;
}

ld integrate(ld a, ld b, ld ans) {
	ld m = (a + b) / 2.0;
	ld sl = simpson(a, m);
	ld sr = simpson(m, b);

	if (abs(sl + sr - ans) < EPS) {
		return sl + sr;
	}
	return integrate(a, m, sl) + integrate(m, b, sr);
}
 
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	while (cin >> w) {
		cin >> d >> a >> k;
 
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j <= k; j++) {
				cin >> p[i][j];
			}
			for (int j = 0; j <= k; j++) {
				cin >> q[i][j];
			}
		}
 
		ld l = 0, r = d;
		for (int i = 0; i < 30; i ++) {
			depth = (l + r) / 2.0;
			ld area = integrate(0, w, simpson(0, w));
			if (area <= a) {
				l = depth;
			}
			else {
				r = depth;
			}
		}
 
		cout << fixed << setprecision(5) << depth << '\n';
	}
 
	return 0;
}
 
