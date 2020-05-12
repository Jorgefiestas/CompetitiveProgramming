#include <bits/stdc++.h>
using namespace std;
using ld = long double;
using pii = pair<ld, ld>;
const ld PI = 3.14159265;
const int N = 500;
int t, k, n;
pii op[N], p[N];

int quadrant(pii coor) {
	if (coor.first >= 0) {
		return (coor.second >= 0) ? 1 : 4;
	}
	return (coor.second >= 0) ? 2 : 3;
}

ld ang(pii a) {
	ld theta = atan2((ld) a.second, (ld) a.first);
	if (a.second < 0) {
		return 2 * PI + theta;
	}
	return theta;
}

bool comp(pii &a, pii &b) {
	if (quadrant(a) == quadrant(b)) {
		return (ld) a.second * b.first < (ld) b.second * a.first;
	}
	return quadrant(a) < quadrant(b);
}

ld ang(pii a, pii b) {
	return ang(b) - ang(a);
}

ld cot(ld a) {
	return (ld) 1.0 / abs(tan(a));
}

void solve() {
	cin >> k;
	n = 4 * k + 5;

	for (int i = 0; i < n; i++) {
		cin >> op[i].first >> op[i].second;
		p[i] = op[i];
	}

	ld ans = 1e15;
	bool pos = false;
	for (int pi = 0; pi < n; pi++) {
		pii o = op[pi];	
		
		for (int i = 0; i < n; i++) {
			if (i == pi) continue;
			p[i] = op[i];
			p[i].first -= o.first;
			p[i].second -= o.second;
		}
		p[pi] = p[n - 1];

		sort(p, p + n - 1, comp);

		pii arm[4];
		for (int i = 0; i <= k; i++) {
			for (int j = 0; j < 4; j++) {
				arm[j] = p[j * (k + 1) + i];
			}

			ld ab = ang(arm[0], arm[1]);
			ld bc = ang(arm[1], arm[2]);
			ld cd = ang(arm[2], arm[3]);
			ld da = 2.0 * PI + ang(arm[3], arm[0]);

			if (ab >= PI || bc >= PI || cd >= PI || da >= PI) continue;
			ans = min(ans, cot(ab) + cot(bc) + cot(cd) + cot(da));
			pos = true;
		}
	}

	if (pos) {
		cout << fixed << setprecision(6) << ans << '\n';
	}
	else {
		cout << "Impossible\n";
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}
