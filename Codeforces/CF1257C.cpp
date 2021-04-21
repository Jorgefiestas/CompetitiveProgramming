#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 100;
int t, n, last[N];

int solve() {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		last[i] = -1;
	}

	int a, ans = INT_MAX;
	for (int i = 0; i < n; i++) {
		cin >> a;

		if (last[a] != -1) {
			ans = min(ans, i - last[a] + 1);
		}
		last[a] = i;
	}

	return (ans == INT_MAX) ? -1 : ans;
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
