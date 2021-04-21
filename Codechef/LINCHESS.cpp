#include <bits/stdc++.h>
using namespace std;
const int nN = 1005;
int t, n, k;

int solve() {
	cin >> n >> k;

	int ans = -1;

	int p;
	for (int i = 1; i <= n; i++) {
		cin >> p;
		if (k % p == 0 && p > ans) {
			ans = p;
		}
	}

	return ans;
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
