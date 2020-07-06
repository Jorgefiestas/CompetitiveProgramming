#include <bits/stdc++.h>
using namespace std;
using ld = long double;
using pdd = pair<ld, ld>;
const int N = 1e5 + 10;
int n;
ld w, pref[N];
 
struct Point {
	ld x = 0;
	ld y = 0;

	bool operator<(const Point &other) const {
		return x < other.x;
	}
};
 
Point coor[N];

ld trapArea(ld h, ld b1, ld b2) {
	return h * (b1 + b2);
}

int getIndex(ld x) {
	Point temp;
	temp.x = x;

	return upper_bound(coor, coor + n, temp) - coor - 1;
}

ld prefArea(ld x) {
	int i = getIndex(x);
	ld area = pref[i];

	ld dx = coor[i + 1].x - coor[i].x;
	ld dy = coor[i + 1].y - coor[i].y;
	ld m = dy / dx;

	ld delta = x - coor[i].x;

	area += trapArea(delta, coor[i].y, coor[i].y + delta * m);
	return area;
}

ld rangeArea(ld l, ld r) { 
	return prefArea(r) - prefArea(l);
}

ld ts(int idx) {
	if (coor[idx].x + w > coor[n - 1].x) {
		return 0;
	}

	ld l = coor[idx].x;
	ld r = min(coor[idx + 1].x, coor[n - 1].x - w);

	for (int rep = 0; rep < 100; rep++) {
		ld m1 = l + (r - l) / 3.0;
		ld m2 = r - (r - l) / 3.0;

		if (rangeArea(m1, m1 + w) < rangeArea(m2, m2 + w)) {
			l = m1;
		}
		else {
			r = m2;
		}
	}

	ld m = (l + r) / 2.0;
	return rangeArea(m, m + w);
}

ld findMax() {
	pref[0] = 0;
	for (int i = 1; i < n; i++) {
		ld base = coor[i].x - coor[i - 1].x;
		pref[i] = pref[i - 1] + trapArea(base, coor[i].y, coor[i - 1].y);
	}

	if (coor[n - 1].x - coor[0].x <= w) {
		return pref[n - 1];
	}

	ld ans = 0;
	for (int i = 0; i < n; i++) {
		ld mxArea = ts(i);
		if (coor[i].x + w <= coor[n - 1].x) {
			mxArea = max(mxArea, rangeArea(coor[i].x, coor[i].x + w));
		}
		ans = max(ans, mxArea);
	}
	
	return ans;
}
 
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	cin >> n >> w;
 
	for (int i = 0; i < n; i++) {
		cin >> coor[i].x >> coor[i].y;
	}

	ld ans = findMax();
 
	reverse(coor, coor + n);
	for (int i = 0; i < n; i++) {
		coor[i].x = 1e9 - coor[i].x;
	}
 
	ans = max(ans, findMax());
	ans = (ld) ans / (2 * w);

	cout << fixed << setprecision(9) << ans << '\n';

	return 0;
}
