#include <bits/stdc++.h>
using namespace std;
int t, n, k;

bool solve() {
	cin >> n >> k;

	if (n % 2 != k % 2) {
		return false;
	}

	if ((long long) n < (long long) k * k) {
		return false;
	}

	return true;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		if (solve()) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}

	return 0;
}
