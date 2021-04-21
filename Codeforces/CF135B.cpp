#include <bits/stdc++.h>
using namespace std;

struct pt {
	int x, y;
};
pt p[8];

int dist(pt a, pt b) {
	int dx = a.x - b.x;
	int dy = a.y - b.y;
	return dx * dx + dy * dy;
}

bool isSquare(vector<pt> v) {
	pt a = v[0], b = v[1], c = v[2], d = v[3];

	int d1[] = {dist(a, b), dist(a, c), dist(a, d)};
	sort(d1, d1 + 3);
	if (d1[0] != d1[1] || d1[2] != 2 * d1[0]) {
		return false;
	}

	int d2[] = {dist(b, a), dist(b, c), dist(b, d)};
	sort(d2, d2 + 3);
	if (d2[0] != d2[1] || d2[2] != 2 * d2[0]) {
		return false;
	}

	 return true;
}

bool isRectangle(vector<pt> v) {
	pt a = v[0], b = v[1], c = v[2], d = v[3];

	int d1[] = {dist(a, b), dist(a, c), dist(a, d)};
	sort(d1, d1 + 3);
	if (d1[2] != d1[0] + d1[1]) {
		return false;
	}

	int d2[] = {dist(b, a), dist(b, c), dist(b, d)};
	sort(d2, d2 + 3);
	if (d2[2] != d2[0] + d2[1]) {
		return false;
	}

	 return true;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 8; i++) {
		cin >> p[i].x >> p[i].y;
	}

	for (int bm = 0; bm < (1 << 8); bm++) {
		if (__builtin_popcount(bm) != 4) continue;

		vector<pt> a, b;
		for (int i = 0; i < 8; i++) {
			if (bm & (1 << i)) {
				a.emplace_back(p[i]);
			}
			else {
				b.emplace_back(p[i]);
			}
		}

		if (isSquare(a) && isRectangle(b)) {
			cout << "YES\n";

			for (int i = 0; i < 8; i++) {
				if (bm & (1 << i)) {
					cout << i + 1 << ' ';
				}
			}
			cout << '\n';

			for (int i = 0; i < 8; i++) {
				if (bm & (1 << i)) continue;
				cout << i + 1 << ' ';
			}
			cout << '\n';

			return 0;
		}
	}

	cout << "NO\n";
	return 0;
}
