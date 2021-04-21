#include <bits/stdc++.h>
using namespace std;
const int N = 5005;
int n, a[N];

int rmq(int l, int r) {
	int mn = INT_MAX;
	int idx = 0;

	for (int i = l; i <= r; i++) {
		if (a[i] < mn) {
			idx = i;
			mn = a[i];
		}
	}

	return idx;
}

int solve(int l, int r, int h) {
	if (l > r) {
		return 0;
	}

	int idx = rmq(l, r);

	int ans = 0;
	ans += solve(l, idx - 1, a[idx]);
	ans += solve(idx + 1, r, a[idx]);
	ans += a[idx] - h;

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
