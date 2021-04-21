#include <bits/stdc++.h>
using namespace std;
const int N = 500;
long long x[N], y[N], ax, ay, bx, by;
long long xs, ys, t;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> x[0] >> y[0];
	cin >> ax >> ay;
	cin >> bx >> by;


	int lx = 0;
	while (!lx || x[lx] <= 5e16) {
		lx += 1;
		x[lx] = ax * x[lx - 1] + bx;
	}
	
	int ly = 0;
	while (!ly || y[ly] <= 5e16) {
		ly += 1;
		y[ly] = ay * y[ly - 1] + by;
	}

	cin >> xs >> ys >> t;

	int ans = 0;
	for (int i = 0; i <= min(lx, ly); i++) {
		for (int j = i; j < min(lx, ly); j++) {
			long long dx = x[j] - x[i];
			long long dy = y[j] - y[i];

			long long e1 = abs(x[i] - xs) + abs(y[i] - ys);
			long long e2 = abs(x[j] - xs) + abs(y[j] - ys);
			long long extra = min(e1, e2);

			if (dx + dy + extra > t) continue;
			ans = max(ans, j - i + 1);
		}
	}

	cout << ans << '\n';

	return 0;
}
