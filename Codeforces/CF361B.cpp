#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
int n, k;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;

	if (k == n) {
		cout << -1 << '\n';
		return 0;
	}

	for (int i = 2; i <= n - k; i++) { 
		cout << i << ' ';
	}

	cout << 1 << ' ';

	for (int i = n - k; i < n; i++) {
		cout << i + 1 << ' ';
	}
	cout << '\n';

	return 0;
}
