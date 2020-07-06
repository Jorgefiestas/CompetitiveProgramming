#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 100;
int t, n, k, a[N];

bool solve() {
	cin >> n >> k;

	int x;
	int last = -2;
	bool poss = false;
	bool seen = false;
	for (int i = 1; i <= n; i++) {
		cin >> x;
		a[i] = (x < k) ? -1 : 1;
		a[i] = (x == k) ? 0 : a[i];

		seen = seen || !a[i];
		if (a[i] >= 0) {
			if (i - last <= 2) {
				poss = true;
			}
			last = i;
		}
	}

	if (n == 1) {
		return !a[1];
	}

	return seen && poss;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		if (solve()) {
			cout << "yes\n";
		}
		else {
			cout << "no\n";
		}
	}

	return 0;
}
