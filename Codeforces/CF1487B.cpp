#include <bits/stdc++.h>
using namespace std;
int t, n, k; 

int solve() {
	cin >> n >> k;
	k -= 1;

	if (n % 2 == 0) {
		return k % n + 1;
	}

	int pos = k % (n - 1) + 1;

	int m = n / 2;
	int jmps = k / m;

	return (k + jmps) % n + 1;
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
