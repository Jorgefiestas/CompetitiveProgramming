#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int t, n, a[N];

bool solve() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	reverse(a, a + n);

	bool last = false;
	for (int i = 0; i < n; i++) {
		if (!last) {
			last = true;
		}
		else {
			last = a[i] > 1;
		}
	}

	return last;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;

	while (t--) {
		if (solve()) {
			cout << "First\n";
		}
		else {
			cout << "Second\n";
		}
	}

	return 0;
}
