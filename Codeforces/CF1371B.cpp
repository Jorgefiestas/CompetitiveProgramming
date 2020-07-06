#include <bits/stdc++.h>
using namespace std;
int t, n, r;

long long solve() {
	cin >> n >> r;

	long long ans = 0;
	
	int r1 = min(r, n - 1);
	ans = (long long) r1 * (r1 + 1) / 2;
	if (r >= n) {
		ans += 1;
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
