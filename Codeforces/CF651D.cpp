#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 100;
int n, a, b, t, rot[N];
long long bef[N], aft[N];

int bs(int x) {
	int l = 1;
	int r = n;

	int ans = n + 1;
	while (l <= r) {
		int m = (l + r) / 2;

		if (bef[m] <= x) {
			ans = m;
			r = m - 1;
		}
		else {
			l = m + 1;
		}
	}

	return ans;
}

int solve() {
	aft[1] = rot[1] * b + 1;
	for (int i = 2; i <= n; i++) {
		aft[i] = aft[i - 1] + rot[i] * b + a + 1;
	}
	for (int i = n; i >= 1; i--) {
		bef[i] = bef[i + 1] + rot[i] * b + 2 * a + 1;
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (aft[i] > t) break;
		int idx = n - bs(t - aft[i]) + 1;
		idx = min(n - i, idx);
		ans = max(i + idx, ans);
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> a >> b >> t;

	char c;
	for (int i = 1; i <= n; i++) {
		cin >> c;
		rot[i] = (c == 'w');
	}

	int ans = solve();

	reverse(rot + 1, rot + n + 1);
	rotate(rot + 1, rot + n, rot + n + 1); 

	ans = max(solve(), ans);

	cout << ans << '\n';

	return 0;
}
