#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int t, n, d, a[N];

bool solve() {
	cin >> n >> d;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (a[i] + a[j] <= d) 
				return true;
		}
	}

	for (int i = 1; i <= n; i++) {
		if (a[i] > d)
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
