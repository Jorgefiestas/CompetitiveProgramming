#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, bool>;
const int N = 505;
int t, n, a[N], as[N];

bool solve() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		as[i] = a[i];
	}


	bool zcnt = false;
	bool ocnt = false;
	bool b;
	for (int i = 0; i < n; i++) {
		cin >> b;
		if (b) {
			ocnt = true;
		}
		else {
			zcnt = true;
		}
	}

	if (ocnt && zcnt) {
		return true;
	}
	
	sort(as, as + n);
	for (int i = 0; i < n; i++) {
		if (as[i] != a[i]) {
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
