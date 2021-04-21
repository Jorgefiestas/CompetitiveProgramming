#include <bits/stdc++.h>
using namespace std;
const int N = 5005;
int n, a[N];

int solve(int l, int r, int h) {
	if (l > r) {
		return 0;
	}

	int mn = INT_MAX;
	int idx = 0;
	for (int i = l; i <= r; i++) {
		if (a[i] < h) continue;
		if (a[i] < mn) {
			mn = a[i];
			idx = i;
		}
	}

	int ans = solve(l, idx - 1, mn) + solve(idx + 1, r, mn);
	ans += mn - h;

	return min(ans, r - l + 1);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	cout << solve(1, n, 0) << '\n';

	return 0;
}
