#include <bits/stdc++.h>
using namespace std;
int t, n;

void solve() {
	cin >> n;

	int cnt[2] = {0, 0};

	int x;
	for (int i = 0; i < n; i++) {
		cin >> x;
		cnt[x] += 1;
	}

	if (cnt[0] >= n / 2) {
		cout << n / 2 << '\n';

		for (int i = 1; i <= n / 2; i++) {
			cout << 0 << ' ' ;
		}
		cout << '\n';
		return;
	}

	int e = n / 2 + (n / 2) % 2;

	cout << e << '\n';

	for (int i = 1; i <= e; i++) {
		cout << 1 << ' ';
	}
	cout << '\n';
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
