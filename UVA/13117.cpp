#include <bits/stdc++.h>
using namespace std;
using ld = long double;
const int N = 18;
int n, t;

struct pt {
	ld x, y;

	pt operator+(const pt &p) const {
		return {x + p.x, y + p.y};
	}
	pt operator-(const pt &p) const {
		return {x - p.x, y - p.y};
	}
	pt operator*(ld d) const {
		return {x * d, y * d};
	}
	pt operator/(ld d) const {
		return {x / d, y / d};
	}
	ld sq() const {
		return x * x + y * y;
	}
	ld abs() const {
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

ld solve() {
	cin >> b.x >> b.y;

	for (int i = 0; i < n; i++) {
		cin >> a[i].x >> a[i].y;
	}
	a[n] = a[0];

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
		}

		ans = min(ans, d);
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cout << fixed << setprecision(3);
	string sn;
	while (cin >> sn, sn != "*") {
		n = stoi(sn);
		cout << solve() << '\n';
	}

	return 0;
}
