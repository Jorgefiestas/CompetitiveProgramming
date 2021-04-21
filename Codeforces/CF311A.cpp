#include <bits/stdc++.h>
using namespace std;
int n, k;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;

	if (k >= n * (n - 1) / 2) {
		cout << "no solution" << '\n';
		return 0;
	}

	for (int x = 1; x <= n; x++) {
		cout << x << ' ' << (x - 1) * n + 1 << '\n';
	}

	return 0;
}
