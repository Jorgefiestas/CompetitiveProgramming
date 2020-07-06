#include <bits/stdc++.h>
using namespace std;
int t, n, k;

int sd(int x) {
	for (int i = 2; i * i <= x; i++) {
		if (x % i) continue;
		return i;
	}

	return x;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		cin >> n >> k;

		if (n % 2 == 0) {
			cout << (long long) n + 2LL * k << '\n';
		}
		else {
			cout << (long long) n + sd(n) + 2 * (k - 1) << '\n';
		}
	}

	return 0;
}
