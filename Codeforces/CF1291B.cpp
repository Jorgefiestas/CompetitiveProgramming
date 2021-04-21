#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 100;
int t, n, a[N];

bool solve() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	bool inc = true;
	for (int i = 0; i < n; i++) {
		if (inc && a[i] < i) {
			if (a[i] == a[i - 1]) {
				a[i] -= 1;
			}
			inc = false;
		}
		if (!inc && a[i] < (n - 1 - i)) {
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
