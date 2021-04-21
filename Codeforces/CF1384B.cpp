#include <bits/stdc++.h>
using namespace std;
const int N = 3e5;
int t, n, k, l;
int rng[N], d[N];

bool solve() {
	cin >> n >> k >> l;

	for (int i = 0; i < n; i++) {
		cin >> d[i];
		int dif = l - d[i];
		rng[i] = max(0, k - dif);
	}

	int l = 0;
	int r = 2 * k - 1;
	for (int i = 0; i < n; i++) {
		if (rng[i] == 0) {
			l = 0;
			r = 2 * k - 1;
			continue;
		}

		l = max(rng[i], l + 1);
		r = min(2 * k - rng[i], r + 1);

		if (l > r) {
			return false;
		}
	}

	return true;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;

	while (t--) {
		if (solve()) {
			cout << "Yes\n";
		}
		else {
			cout << "No\n";
		}
	}

	return 0;
}
