#include <bits/stdc++.h>
using namespace std;
int t, n, k;

int solve() {
	cin >> n >> k;

	if (n <= k) {
		return k - n;
	}
	if ((n - k) & 1) {
		return 1;
	}
	return 0;
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
