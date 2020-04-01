#include <bits/stdc++.h>
using namespace std;
int n, m;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 1; i * 2 <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cout << i << ' ' << j << '\n';
			cout << n - i + 1 << ' ' << m - j + 1 << '\n';
		}
	}

	if (n % 2) {
		int mid = n / 2 + 1;
		for (int i = 1; i * 2 <= m; i++) {
			cout << mid << ' ' <<  i << '\n';
			cout << mid << ' ' <<  m - i + 1 << '\n';
		}

		if (m % 2) {
			cout << mid << ' ' << m / 2 + 1 << '\n';
		}
	}

	return 0;
}
