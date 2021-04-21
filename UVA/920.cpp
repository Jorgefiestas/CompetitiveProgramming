#include <bits/stdc++.h>
using namespace std;
using ld = long double;
const int N = 105;
int t, n;

struct pt {
	ld x, y;

	pt operator+(const pt &p) {
		return {x + p.x, y + p.y};
	}
	pt operator-(const pt &p) {
		return {x - p.x, y - p.y};
	}
	pt operator*(ld d) {
		return {x * d, y * d};
	}
	pt operator/(ld d) {
		return {x / d, y / d};
	}

	bool operator <(const pt &p) const {
		return x > p.x;
	}

	ld sq() {
		return x * x + y * y;
	}
	ld abs() {
		return sqrtl(sq()); 
	}
};

pt a[N];

ld dist(pt a, pt b) {
	return (a - b).abs();
}

ld solve() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i].x >> a[i].y;
	}

	sort(a, a + n);

	ld h = 0;
	ld ans = 0;
	for (int i = 1; i < n; i++) {
		if (a[i].y <= h) continue;

		pt dif = a[i] - a[i - 1];
		ld m = dif.x / dif.y;

		pt np = {a[i].x + (a[i].y - h) * m, h};
		ans += dist(a[i], np);

		h = a[i].y;
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;

	cout << fixed << setprecision(2);
	while (t--) {
		cout << solve() << endl;
	}

	return 0;
}
