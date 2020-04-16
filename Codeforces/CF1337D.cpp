#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
int t, n[3], w[3][N];

long long compute(int xi, int yi, int zi) {
	long long x = w[0][xi];
	long long y = w[1][yi];
	long long z = w[2][zi];

	long long xy = x - y;
	long long xz = x - z;
	long long yz = y - z;

	return xy * xy + xz * xz + yz * yz;
}

long long solve() {
	cin >> n[0] >> n[1] >> n[2];

	for (int i = 0; i < 3; i ++) {
		for (int j = 0; j < n[i]; j++) {
			cin >> w[i][j];
		}
	}

	for (int i = 0; i < 3; i++) {
		sort(w[i], w[i] + n[i]);
	}

	int r = 0, g = 0, b = 0;
	long long ans = compute(0, 0, 0);
	while (r != n[0] - 1 || g != n[1] - 1 || b != n[2] - 1) {
		int choice = 0;
		long long tans = LLONG_MAX;
		long long dr, dg, db;

		if (r != n[0] - 1) {
			dr = compute(r + 1, g, b);
			if (dr < tans) {
				choice = 0;
				tans = dr;
			}
		}
		if (g != n[1] - 1) {
			dg = compute(r, g + 1, b);
			if (dg < tans) {
				choice = 1;
				tans = dg;
			}
		}
		if (b != n[2] - 1) {
			db = compute(r, g, b + 1);
			if (db < tans) {
				choice = 2;
				tans = db;
			}
		}

		if (choice == 0) {
			ans = min(ans, dr);
			r++;
		}
		else if (choice == 1) {
			ans = min(ans, dg);
			g++;
		}
		else {
			ans = min(ans, db);
			b++;
		}
	}
	ans = min(ans, compute(r, g, b));

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
