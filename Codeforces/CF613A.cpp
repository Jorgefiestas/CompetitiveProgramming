#include <bits/stdc++.h>
using namespace std;
using ld = long double;
const int N = 1e5 + 10;
const ld PI = 3.141592653589793;
int n;

struct pt {
	ld x, y;

	pt operator -(const pt &p) const {
		return {x - p.x, y - p.y};
	}

	pt operator *(const pt &p) const {
		return {x * p.x, y * p.y};
	}

	ld dot(const pt &p) const {
		return x * p.x + y * p.y;
	}

	ld cross(const pt &p) const {
		return x * p.y - y * p.x;
	}

	ld arg2() {
		return x * x + y * y;
	}
};

struct Seg {
	pt a, b;

	ld dist2(const pt &p) const {
		pt ab = b - a;
		pt bp = p - b;
		pt ap = p - a;

		if (ab.dot(bp) > 0) {
			return bp.arg2();
		}
		if (ab.dot(ap) < 0) {
			return ap.arg2();
		}

		ld c = ab.cross(ap);
		return c * c / ab.arg2();
	}
};

pt p, pol[N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> p.x >> p.y;

	for (int i = 0; i < n; i++) {
		cin >> pol[i].x >> pol[i].y;
	}

	ld mn = 1e18;
	for (int i = 0; i < n; i++) {
		Seg s = {pol[i], pol[(i + 1) % n]};
		mn = min(mn, PI * s.dist2(p));
	}

	ld mx = -1e18;
	for (int i = 0; i < n; i++) {
		ld r2 = (p - pol[i]).arg2();
		mx = max(mx, PI * r2);
	}

	cout << fixed << setprecision(12);
	cout << mx - mn << '\n';

	return 0;
}
