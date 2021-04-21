#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 100;
int t, n;

struct pt {
	int x, y;

	pt operator+(const pt &p) const {
		return {x + p.x, y + p.y};
	}
	pt operator-(const pt &p) const {
		return {x - p.x, y - p.y};
	}
	pt operator*(int s) const {
		return {x * s, y * s};
	}
	pt rotate90() const {
		return {-y, x};
	}

	bool operator==(const pt &p) const {
		return x == p.x && y == p.y;
	}
	bool operator!=(const pt &p) const {
		return x != p.x || y != p.y;
	}
	bool operator<(const pt &p) const {
		if (x == p.x) {
			return y < p.y;
		}
		return x < p.x;
	}
};

ostream& operator<<(ostream &out, const pt &p) {
	return out << '(' << p.x << ',' << p.y << ')';
}

pt h[N], p[N];

bool solve() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> p[i].x >> p[i].y;
	}
	for (int i = 0; i < n; i++) {
		cin >> h[i].x >> h[i].y;
	}

	sort(p, p + n);

	bool poss = false;
	for (int rot = 0; !poss && rot < 4; rot++) {
		sort(h, h + n);

		pt dif = p[0] - h[0];

		poss = true;
		for (int i = 1; i < n; i++) {
			pt tmp = p[i] - h[i];
			if (tmp != dif) {
				poss = false;
				break;
			}
		}
		
		for (int i = 0; i < n; i++) {
			h[i] = h[i].rotate90();
		}
	}
	
	return poss;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		if (solve()) {
			cout << "MATCHED\n";
		}
		else {
			cout << "NOT MATCHED\n";
		}
	}

	return 0;
}
