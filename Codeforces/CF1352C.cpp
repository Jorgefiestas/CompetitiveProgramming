#include <bits/stdc++.h>
using namespace std;
int t, n, k;

int solve() {
	cin >> n >> k;

	int acc = k / (n - 1);
	long long m = (long long) acc * n;

	if (k % (n - 1) == 0) {
		return m - 1;
	}

	return m + (k % (n - 1));
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
