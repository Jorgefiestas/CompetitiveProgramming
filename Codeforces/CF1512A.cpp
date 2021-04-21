#include <bits/stdc++.h>
using namespace std;

int solve() {
	int n;
	cin >> n;

	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	for (int i = 2; i < n; i++) {
		if (a[i] != a[i - 1] && a[i] != a[i + 1]) {
			return i;
		}
	}

	return a[1] != a[2] ? 1 : n;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	while (t--) {
		cout << solve() << '\n';
	}

	return 0;
}
