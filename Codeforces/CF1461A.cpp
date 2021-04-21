#include <bits/stdc++.h>
using namespace std;
const string base = "abc";
int t, n, k;

void solve() {
	cin >> n >> k;

	string ans;
	for (int i = 0; i < n; i++) {
		ans += base[i % 3];
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
