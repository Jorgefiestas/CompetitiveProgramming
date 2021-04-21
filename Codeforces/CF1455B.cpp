#include <bits/stdc++.h>
using namespace std;
int t, x;

int solve() {
	cin >> x;

	int n = 0;
	while (n * (n + 1) / 2 < x) {
		n += 1;
	}

	if (n * (n + 1) / 2 - x == 1) {
		return n + 1;
	}
	return n;
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
