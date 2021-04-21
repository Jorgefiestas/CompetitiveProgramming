#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int t, n, ans[N];

void solve() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cout << ans[i];
	}
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);


	ans[0] = 9;
	ans[1] = 8;
	for (int i = 2; i < N; i++) {
		ans[i] = (ans[i - 1] + 1) % 10;
	}

	cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}
