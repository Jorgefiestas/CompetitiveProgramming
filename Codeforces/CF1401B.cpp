#include <bits/stdc++.h>
using namespace std;
int t, a[3], b[3];

long long solve() {
	for (int i = 0; i < 3; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < 3; i++) {
		cin >> b[i];
	}

	long long ans = 0;
	ans += (long long) min(a[2], b[1]) * 2;
	a[2] -= min(a[2], b[1]);
	b[1] -= min(a[2], b[1]);

	b[2] -= min(b[2], a[0]);
	b[2] -= min(b[2], a[2]);

	ans -= (long long) b[2] * 2;

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
