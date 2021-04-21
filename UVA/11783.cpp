#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int n;

struct pt {
	int x, y;
};

ostream& operator<<(ostream& out, pt p) {
	return out << '(' << p.x << ',' << p.y << ')';
}

struct seg {
	pt l, r;
};

seg s[N];

int orientation(const pt &p, const pt &q, const pt &r) {
	int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
	if (val == 0) {
		return 0;
	}
	return (val > 0) ? 1 : 2;
}

bool intersect(const seg a, const seg b) {
	int o1 = orientation(a.l, a.r, b.l);
	int o2 = orientation(a.l, a.r, b.r);
	int o3 = orientation(b.l, b.r, a.l);
	int o4 = orientation(b.l, b.r, a.r);

	return o1 != o2 && o3 != o4;
}

int solve() {
	pt p, q;
	for (int i = 0; i < n; i++) {
		cin >> p.x >> p.y >> q.x >> q.y;
		s[i] = {p, q};
	}

	int inter = 0;
	int noint = 0;
	for (int i = 0; i < n; i++) {
		bool alone = true;;
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			if (intersect(s[i], s[j])) {
				alone = false;
				inter += 1;
			}
		}
		if (alone) {
			noint += 1;
		}
	}

	return inter / 2 + 2 * noint;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (cin >> n, n) {
		cout << solve() << '\n';
	}

	return 0;
}
