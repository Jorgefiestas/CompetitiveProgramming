#include <bits/stdc++.h>
using namespace std;
int t, n;

int solve() {
	cin >> n;

	if (n <= 3) {
		return n - 1;
	}
	if (n % 2 == 0) {
		return 2;
	}
	return 3;
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
