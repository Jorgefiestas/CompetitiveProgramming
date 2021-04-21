#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, m, cl, ce, v, q;
int l[N], e[N];

int dist(int sx, int sy, int up, int ex, int ey, bool el) {
	if (up == -1) {
		return INT_MAX;
	}

	int dx = abs(sx - up) + abs(up - ex);
	int dy = abs(ey - sy);

	if (el)
		dy = (dy + v - 1) / v;

	return dx + dy;
}

int lft(int a[], int x, int an) {
	if (an == 0) 
		return -1;

	int idx = upper_bound(a, a + an, x) - a;
	return (idx == 0) ? -1 : a[idx - 1];
}

int rgt(int a[], int x, int an) {
	if (an == 0)
		return -1;

	int idx = upper_bound(a, a + an, x) - a;
	return (idx == an) ? -1 : a[idx];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> cl >> ce >> v;

	for (int i = 0; i < cl; i++) {
		cin >> l[i];
	}
	sort(l, l + cl);


	for (int i = 0; i < ce; i++) {
		cin >> e[i];
	}
	sort(e, e + ce);

	cin >> q;

	int sx, sy, ex, ey;
	for (int qi = 0; qi < q; qi++) {
		cin >> sy >> sx >> ey >> ex;

		if (sy == ey) {
			cout << abs(ex - sx) << '\n';
			continue;
		}

		int lft_st = lft(l, sx, cl);
		int lft_el = lft(e, sx, ce);
		int rgt_st = rgt(l, sx, cl);
		int rgt_el = rgt(e, sx, ce);

		int can1 = dist(sx, sy, lft_st, ex, ey, 0);
		int can2 = dist(sx, sy, rgt_st, ex, ey, 0);
		int can3 = dist(sx, sy, lft_el, ex, ey, 1);
		int can4 = dist(sx, sy, rgt_el, ex, ey, 1);

		cout << min({can1, can2, can3, can4}) << '\n';
	}

	return 0;
}
