#include <bits/stdc++.h>
using namespace std;
int t, n;

void solve() {
	cin >> n;

	string ans;
	while (n >= 2) {
		ans += '1';
		n -= 2;
	}
	if (n) {
		ans[0] = '7';
	}

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}
