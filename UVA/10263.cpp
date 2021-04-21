#include <bits/stdc++.h>
using namespace std;
using ld = long double;
const int N = 1e6 + 100;
int n, t;

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

pt b, a[N];

ld dist(pt a, pt b) {
	return (a - b).abs();
}

pt closest(pt p, ld m, ld c) {
	pt ans;
	ans.x = (p.x + m * p.y - m * c) / (m * m + 1);
	ans.y = (m * (p.x + m * p.y) + c) / (m * m + 1);
	return ans;
}

void solve() {
	cin >> n;

	for (int i = 0; i <= n; i++) {
		cin >> a[i].x >> a[i].y;
	}

	pt np;
	ld ans = 1e15;
	for (int i = 1; i <= n; i++) {
		pt dif = a[i] - a[i - 1];
		ld m = dif.y / dif.x;
		ld c = a[i].y - m * a[i].x;

		pt can = closest(b, m, c);
		ld d = dist(b, can);

		ld lft = min(a[i].x, a[i - 1].x);
		ld rgt = max(a[i].x, a[i - 1].x);
		if (can.x < lft || can.x > rgt) {
			ld d1 = dist(a[i], b);
			ld d2 = dist(a[i - 1], b);

			d = min(d1, d2);
			can = (d1 < d2) ? a[i] : a[i - 1];
		}

		if (d < ans) {
			np = can;
			ans = d;
		}
	}

	cout << np.x << '\n';
	cout << np.y << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cout << fixed << setprecision(4);
	while (cin >> b.x >> b.y) {
		solve();
	}

	return 0;
}
