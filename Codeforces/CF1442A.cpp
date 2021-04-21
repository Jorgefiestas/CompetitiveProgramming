#include <bits/stdc++.h>
using namespace std;
const int N = 3e4 + 10;
int t, n, x[N];

bool solve() {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> x[i];
	}

	int sub = 0;
	for (int i = 2; i <= n; i++) {
		x[i] -= sub;

		if (x[i] < 0) 
			return false;

		if (x[i] > x[i - 1]) {
			sub += x[i] - x[i - 1];
			x[i] = x[i - 1];
		}
	}

	return true;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		memset(x, 0, sizeof x);

		if (solve()) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}

	return 0;
}
