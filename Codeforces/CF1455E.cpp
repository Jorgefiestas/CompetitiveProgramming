#include <bits/stdc++.h>
using namespace std;
int t;

struct pt {
	long long x, y;

	bool operator < (const pt &p) const {
		if (x == p.x) {
			return y < p.y;
		}
		return x < p.x;
	}
};

pt p[5];

long long calc() {
	long long ans = 0;

	pt sx1 = {min(p[0].x, p[3].x), max(p[0].x, p[3].x)};
	pt sx2 = {min(p[1].x, p[2].x), max(p[1].x, p[2].x)};

	ans += sx1.y - sx1.x + sx2.y - sx2.x;

	long long rx = max({sx1.y - sx2.x, sx2.y - sx1.x, 0LL});
	long long lx = max({sx1.x - sx2.y, sx2.x - sx1.y, 0LL});

	pt sy1 = {min(p[0].y, p[1].y), max(p[0].y, p[1].y)};
	pt sy2 = {min(p[2].y, p[3].y), max(p[2].y, p[3].y)};

	ans += sy1.y - sy1.x + sy2.y - sy2.x;

	long long ry = max({sy1.y - sy2.x, sy2.y - sy1.x, 0LL});
	long long ly = max({sy1.x - sy2.y, sy2.x - sy1.y, 0LL});

	long long is = min(rx, ry) - max(lx, ly);
	ans += 2LL * max(0LL, -is);

	return ans;
}

long long solve() {
	for (int i = 0; i < 4; i++) {
		cin >> p[i].x >> p[i].y;
	}
	
	long long ans = INT_MAX;

	sort(p, p + 4);
	do {
		ans = min(ans, calc());
	} while (next_permutation(p, p + 4));

	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		cout << solve() << '\n';
	}

	return 0;
}
