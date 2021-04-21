#include <bits/stdc++.h>
using namespace std;
const int N = 2005;
int t, n, a[N];

bool solve() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	bool even = false;
	bool odd = false;
	for (int i = 0; i < n; i++) {
		if (a[i] % 2) {
			odd = true;
		}
		else {
			even = true;
		}
	}

	if (even && odd) {
		return true;
	}

	return (n % 2) && odd;
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
