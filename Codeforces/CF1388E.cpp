#include <bits/stdc++.h>
using namespace std;
using ld = long double;
const int N = 2005;
int n;

struct Segment {
	ld l = 0;
	ld r = 0;
	ld y = 0;
};

bool intersect(Segment &s1, Segment &s2) {
	return !(s1.l <= s2.r && s2.l <= s1.r);
}

Segment s[N];

ld lft, rgt;
ld ans = 1e15;
bool check(ld v) {
	vector<Segment> sgmnts;

	lft = 1e10;
	rgt = -1e10;
	for (int i = 0; i < n; i++) {
		Segment ns;
		ns.l = s[i].l + s[i].y * v;
		ns.r = s[i].r + s[i].y * v;

		for (auto sg : sgmnts) {
			if (intersect(sg, ns)) {
				return false;
			}
		}

		lft = min(lft, ns.l);
		rgt = max(rgt, ns.r);
		sgmnts.push_back(ns);
	}

	ans = min(ans, rgt - lft);
	return true;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s[i].l >> s[i].r >> s[i].y;
	}

	ld l = 0;
	ld r = 1e9;
	for (int i = 0; i < 200; i++) {
		ld m = (l + r) / 2.0;
		if (check(m)) {
			r = m;
		}
		else {
			l = m;
		}
	}

	l = -1e9;
	r = 0;
	for (int i = 0; i < 200; i++) {
		cout << l << ' ' << r << endl;
		ld m = (l + r) / 2.0;
		if (check(m)) {
			l = m;
		}
		else {
			r = m;
		}
	}

	cout << ans << '\n';

	return 0;
}
