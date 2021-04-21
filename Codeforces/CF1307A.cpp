#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int t, n, d, a[N];

int solve() {
	cin >> n >> d;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 1; d >= i && i < n; i++) {
		while (d >= i && a[i]) {
			a[0] += 1;
			a[i] -= 1;
			d -= i;
		}
	}

	return a[0];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		cout << solve() << '\n';
	}

	return 0;
}
