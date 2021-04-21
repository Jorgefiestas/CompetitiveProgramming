#include <bits/stdc++.h>
using namespace std;
int t, n, m;

void solve() {
	cin >> n >> m;

	int a;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a;
			if (a % 2 != (i + j) % 2) {
				a += 1;
			}
			cout << a << ' ';
		}
		cout << '\n';
	}
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
